import cv2
import sys
from spellchecker import SpellChecker
import string
from textblob import TextBlob
import translators as ts
import codecs
import numpy as np
import glob
import moviepy.editor as mpe
import os
import enchant
#FUNCTIE DE FORMARE A VIDEOCLIPULUI DIN FRAME-URI
def formVideo (img_path,video_path,frameRate):
    img_array = []
    for filename in glob.glob(img_path):
        img = cv2.imread(filename)
        height, width, layers = img.shape
        size = (width, height)
        img_array.append(img)

    out = cv2.VideoWriter(video_path, cv2.VideoWriter_fourcc(*'DIVX'), int(frameRate), size)

    for i in range(len(img_array)):
        out.write(img_array[i])
    out.release()
#FUNCTIE DE COMBINARE A VIDEOCLIPULUI CU SUBTITRARI CU SUNETUL
def combine_audio(vidname, audname, outname, fps):

    my_clip = mpe.VideoFileClip(vidname)
    audio_background = mpe.AudioFileClip(audname)
    final_clip = my_clip.set_audio(audio_background)
    final_clip.write_videofile(outname,fps=fps)

def translate(subtitle,dest_lang):

    translated_string = "";
    chestie = ts.google(subtitle, 'auto', dest_lang)
    return chestie

#FUNCTIE PENTRU REALIZARE OCR
def do_ocr(originalImage,input_lang):
    import pytesseract as pt
    pt.pytesseract.tesseract_cmd = r"C:\Program Files\Tesseract-OCR\tesseract.exe"
    height, width = originalImage.shape[0:2]

    startRow = int(height * .50)

    startCol = int(width * .10)

    endRow = int(height)

    endCol = int(width * .90)

    croppedImage = originalImage[startRow:endRow, startCol:endCol]

    # PENTRU OBTINEREA PERFORMANTELOR OCR SE FACE O PARTE DE PRE-PROCESARE
    # TRANSFORMARE IN GRAYSCALE , THRESHHOLDING SI ABIA APOI SE APLICA OCR
    grayImage = cv2.cvtColor(croppedImage, cv2.COLOR_BGR2GRAY)

    (thresh, blackAndWhiteImage) = cv2.threshold(grayImage, 128, 255, cv2.THRESH_BINARY)

    # APLICAREA OCR - se presupune ca stim limba in care este subtitrat videoclipul initial
    text = pt.image_to_string(blackAndWhiteImage, lang=input_lang)
    # IN MAJORITATEA FILMELOR SUBTITRARILE SUNT PUSE PE 2 RANDURI (MAXIMUL PERMIS DE STANDARD)
    # SI PRIN URMARE REZULTATUL OCR NECESITA O PARTE DE POST-PROCESARE
    traducere = text.replace('\n', ' ')
    traducere = traducere.replace('|', 'I')
    print(traducere)

    return traducere

#Functie de eliminare a punctuatiei
def remove_punctuation(string_new):
    if string_new.find(')') > -1:
        string_new = string_new.replace(')', '')
    elif string_new.find('(') > -1:
        string_new = string_new.replace('(', '')
    elif string_new.find('?') > -1:
        string_new = string_new.replace('?', '')
    elif string_new.find('...') > -1:
        string_new = string_new.replace('...', '')
    elif string_new.find('!') > -1:
        string_new = string_new.replace('!', '')
    elif string_new.find(':') > -1:
        string_new = string_new.replace(':', '')
    elif string_new.find('.') > -1:
        string_new = string_new.replace('.', '')
    elif string_new.find(',') > -1:
        string_new = string_new.replace(',', '')
    elif string_new.find(';') > -1:
        string_new = string_new.replace(';', '')
    return string_new

def check(cuvant):
    #Se compara cuvantul dat ca argument cu dictionarul limbii engleze
    import enchant
    d = enchant.Dict("en_US")
    if(cuvant):
        return d.check(cuvant)

#Verifica daca un cuvant contine cifre
def containsDigit(cuvant):
    for character in cuvant:
        if(str.isdigit(character)):
            return True

    return False

#Metoda pentru validarea cuvintelor individuale din cadrul subtitrarii recunoscute de OCR
def validare_subtitrare(string):
    cuvinte = string.split()
    index = 0
    maximum = len(cuvinte) - 1
    new_string = ""
    for cuv in cuvinte:
        #La executie dam la o parte semnele de punctuatie
        cuv = remove_punctuation(cuv)
        #Eliminam cifrele intrucat nu sunt relevante
        if (not containsDigit(cuv)):
            #Daca incepe cu litera mare si apoi avem litera mica , atunci inseamna ca poate fi nume de persoana
            #Si nu se mai face validarea sa intrucat poate fi un nume care sa nu fie din limba engleza
            if (not cuv.istitle()):
                #Altfel , se va valida cuvantul folosind biblioteca Enchant
                if (check(cuv)):
                    #Iar cuvantul validat se adauaga la subtitrarea recunsocuta
                    new_string = new_string + " " + cuv
            else:
                new_string = new_string + " " + cuv
        index += 1
    return new_string

#Metoda pentru validarea propozitiei prin constrangerea cu un set de reguli gramaticale
#Sursa : https://www.geeksforgeeks.org/check-given-sentence-given-set-simple-grammer-rules/
def checkSentence(string):
    length = len(string)

    #Propozitia incepe cu litera mare
    if string[0] < 'A' or string[0] > 'Z':
        return False

    #Verificarea ca avem semn de punctuatie '.' la final.
    #Problematica: Totusi punctuatia poate fi alta. O inlocuim cu . doar la executie pentru validare
    if string[length - 1] != '.':
        return False

    #MASINA DE STARI PENTRU VALIDAREA PROPOZITIEI
    prev_state = 0
    curr_state = 0

    #INDEXUL URMATORULUI CARACTER DIN STRING
    index = 1

    #CAT TIMP MAI INTALNIM CARACTERE IN STRING
    while (string[index]):

        if string[index] >= 'A' and string[index] <= 'Z':
            curr_state = 0

        #Spatiul este delimitator
        elif string[index] == ' ':
            curr_state = 1

        #si urmeaza automat un caracter [a-z]
        elif string[index] >= 'a' and string[index] <= 'z':
            curr_state = 2

        #La final avem punct
        elif string[index] == '.':
            curr_state = 3

        #Criterii invalidare
        if prev_state == curr_state and curr_state != 2:
            return False

        if prev_state == 2 and curr_state == 0:
            return False

        if curr_state == 3 and prev_state != 1:
            return True

        index += 1

        prev_state = curr_state

    return False

''''#POSIBILA VARIANTA DE CORECTIE -- RESTRANGERE DOMENIU DE OUTPUT

def spellcheck_output(out_subtitle,output_lang):
    words = out_subtitle.split();
    spell = SpellChecker(language=output_lang)
    checked_subtitle = ""
    for word in words:
        word = remove_punctuation(word)
        if word !="Iam":
            if word in spell:
                checked_subtitle = checked_subtitle + word
            else:
                checked_subtitle = checked_subtitle + ""
        else:
            checked_subtitle = checked_subtitle + word
    return checked_subtitle'''

#ULTIMA IDEE - SA RELIZEZ UN VECTOR CUMVA PRIN INTERMEDIUL CARUIA SA VALIDEZ FAPTUL CA SUBTITRARILE SUNT OKAY SI CA TEMPORIZARE

if __name__ == '__main__':
    #Generarea frame-urilor din videoclip
    path_video = sys.argv[1];
    nume_video = sys.argv[2];
    full_video = path_video + "\\" + nume_video;

    #SEPARAREA COMPONENTEI VIDEO DE CEA AUDIO SE FACE IN MATLAB
    audio_file = path_video + "\\test_out_audio.mp4"

    #PARAMETRU DAT DIN MATLAB CAND FAC CU VIDEOREADER -> a.FrameRate
    FR = sys.argv[3];

    #SETATE TOT DIN MATLAB
    input_lang = sys.argv[4];
    destination_lang = sys.argv[5]

    #SETATE TOT DIN MATLAB
    output_location = sys.argv[6]
    final_filename = sys.argv[7]
    full_output = output_location + "\\" + final_filename

    #PARCURGERE FRAME-URI
    cap = cv2.VideoCapture(full_video)

    numberOfFrames = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))

    subtitle_text = [];
    i = 0
    while (cap.isOpened()):
        #CITIM CATE UN FRAME
        ret, frame = cap.read()
        if ret == False:
            break
        cv2.imwrite('C:\\Users\\andrei.gheorghe1901\\Desktop\\incercare_proiect_AM\\images\\frame' + str(i) + '.png', frame)

        #OCR PE FIECARE FRAME
        subtitrare = do_ocr(frame,input_lang)

        #VALIDAREA SUBTITRARII OBTINUTE IN URMA OCR CUVANT CU CUVANT
        if(input_lang == "eng"):
            subtitrare_validata = validare_subtitrare(subtitrare)
            subtitrare_validata = subtitrare_validata.strip()

            if (subtitrare_validata):
                new_str = subtitrare_validata + "."
                if (checkSentence(new_str) == False):
                    subtitrare_validata = ""
            else:
                subtitrare_validata = ""

        else:
            subtitrare = translate(subtitrare,"en")
            subtitrare_validata = validare_subtitrare(subtitrare)
            subtitrare_validata = subtitrare_validata.strip()

            if (subtitrare_validata):
                new_str = subtitrare_validata + "."
                if (checkSentence(new_str) == False):
                    subtitrare_validata = ""
            else:
                subtitrare_validata = ""

        #TRADUCERE SUBTITRARE OBTINUTA
        traducere = ""
        if(subtitrare_validata!="" and not subtitrare_validata.isspace()):
            traducere = translate(subtitrare_validata,destination_lang)
            if(traducere == subtitrare_validata):
                traducere = ""
            print(traducere)
        #SCRIERE IN FISIERUL DE SUBTITRARI
        with open( path_video + "\\traduceri.txt", "a+") as file_object:
            #Se scriu traducerile
            file_object.write(traducere+"\n")

        #DECUPARE IMAGINE CURENTA SI INTRODUCERE TRADUCERE IN FRAME
        from PIL import Image, ImageFont, ImageDraw
        translatedFrames = path_video + '\\imagesTranslated'
        #SE SCRIE DIRECT IN FOLDER [DEJA EXISTA] cu extensia .bmp
        originalImage = cv2.imread('C:\\Users\\andrei.gheorghe1901\\Desktop\\incercare_proiect_AM\\images\\frame' + str(i) + '.png')
        #CROPARE IMAGINE
        height, width = originalImage.shape[0:2]

        startRow = 0

        startCol = 0

        endRow = int(height* .80)

        endCol = int(width)

        croppedImage = originalImage[startRow:endRow, startCol:endCol]
        cv2.imwrite("C:\\Users\\andrei.gheorghe1901\\Desktop\\incercare_proiect_AM\\images\\frame" + str(i) + ".png",croppedImage)

        #INTRODUCERE TEXT IN IMAGINEA CROPATA
        img = Image.open('C:\\Users\\andrei.gheorghe1901\\Desktop\\incercare_proiect_AM\\images\\frame' + str(i) + '.png')
        d = ImageDraw.Draw(img)
        location = (0.30*width, 0.70*height)
        text_color = (255, 255, 255)
        font = ImageFont.truetype(font = 'arial.ttf',size = 24)
        d.text(location, traducere, fill=text_color,font = font)


        #ALGORITM DE NUMEROTARE A FRAME-URILOR CU SUBTITRARILE TRADUSE
        #frame-ul 25/1512 => frame0025.bmp

        zeros = ""
        number_of_max_zeros = len(str(numberOfFrames))
        z = len(str(zeros)+str(i))
        while (z < number_of_max_zeros):
            zeros = zeros + "0"
            z = len(str(zeros) + str(i));
        img.save(path_video + "\\imagesTranslated" + "\\frame" + zeros + str(i) + ".bmp")
        i += 1

    cap.release()
    cv2.destroyAllWindows()

    #FORMAREA VIDEOCLIPULUI NOU IN CARE SUNT ADAUGATE SUBTITRARILE
    imgPath = path_video + '\\imagesTranslated\\*.bmp'
    #SE FORMEAZA PARTEA VIDEO
    video_part_path = path_video+'\\myVideo.mp4'
    formVideo(imgPath,video_part_path,FR)

    full_video_out = path_video + '\\myVideo.mp4';
    #SE FORMEAZA VIDEOCLIPUL FINAL
    combine_audio(full_video_out, audio_file, full_output, int(FR))
    #SE RETURNEAZA CONTROLUL MATLABULUI
    sys.stdout.write(str(subtitle_text))

