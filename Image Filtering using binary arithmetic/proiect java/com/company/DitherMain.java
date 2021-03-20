package com.company;


import java.awt.*;
import java.awt.color.ColorSpace;
import java.awt.image.*;
import java.io.File;
import javax.imageio.ImageIO;
import java.io.IOException;
import java.util.Scanner;

public class DitherMain {
    static String out1 = "C:\\Users\\andrei.gheorghe1901\\Desktop\\Anul_3\\AWJ\\out1.bmp";
    static String out2 = "C:\\Users\\andrei.gheorghe1901\\Desktop\\Anul_3\\AWJ\\out2.bmp";
    BufferedImage startImage,startImage1,startImage2, endImage;
    int[] startPixels, endPixels, imR, imG, imB;
    int width, height;
    static  String imag1;
    static String imag2;
    static String out_path;
    public static void main(String[] args){
        //pornim un timer care masoara cat timp este necesar rularii programului
        long startTime = System.nanoTime();
        //preiau caile catre fisierele sursa imag1 si imag2 , respectiv calea catre fisierul destinatie
        //ce va fi utilizata pentru scrierea fisierului destinatie
        imag1 = args[0];
        imag2 = args[1];
        out_path = args[2];
        //voi incarca imaginea in img1 si img2 pentru prelucrari ulterioare folosind functia loadImage
        //Aceasta functie ia ca parametru calea catre imaginea sursa si o transforma intr-o variabila de tip
        //BufferedImage cu ajutorul careia se pot extrage si prelucra componentele RGB
        BufferedImage img1 = loadImage(imag1);
        BufferedImage img2 = loadImage(imag2);
        //voi printa in continuare posibilele optiuni ale utilizatorului de operatii binare cu imagini
        Scanner keyboard = new Scanner(System.in);
        System.out.println("1 - operatie tip OR \n");
        System.out.println("2 - operatie tip AND \n");
        System.out.println("3 - operatie tip NAND \n");
        System.out.println("4 - operatie tip NOR \n");
        System.out.println("5 - operatie tip XOR \n");
        System.out.println("6 - operatie tip NOT \n");
        System.out.println("Introdu optiunea de operatie: \n");
        //si voi prelua optiunea introdusa de utilizator
        int optiune = keyboard.nextInt();

        //preiau metoda prin care utilizatorul doreste sa realizeze operatia
        System.out.println("Alegeti metoda prin care doriti sa realizati operatia: ");
        System.out.println("1 -- Cu get/setRGB\n");
        System.out.print("2 -- BinaryFast images\n");

        int metoda = keyboard.nextInt();
        //Folosesc constructorul DitherMain pentru a initia o instanta
        //a clasei principale ce ia ca argumente cele 2 imagini , calea catre fisierul de iesire
        //si operatia selectata
        if(metoda == 1){
            if(optiune != 6)
                new DitherMain(img1,img2,out_path,optiune,metoda);
            else
                new DitherMain(img1,out_path);
        }
        else{
            new DitherMain(img1,img2,out_path,optiune,metoda);
        }

        long endTime = System.nanoTime();
        //calculez timpul trecut de la inceperea programului pana la finalizarea sa masurat in secunde
        double time_elapsed = ((double)endTime-(double)startTime)/1000000000.00;
        System.out.println("Processing the images took "+time_elapsed+" s");
    }
    int width1,height1,width2,height2;
    int[]start1;
    int[]start2;
    DitherMain(BufferedImage img1,BufferedImage img2,String path, int operatie,int metoda) {
        if(metoda == 1){
            switch (operatie) {
                case 1: {
                    width1 = img1.getWidth();
                    height1 = img1.getHeight();
                    width2 = img2.getWidth();
                    height2 = img2.getHeight();
                    start1 = new int[width1 * height1];
                    start2 = new int[width2 * height2];
                    //Facem o constrangere ca imaginile sa fie de aceeasi dimensiune
                    //iar in cazul in care dimensiunea lor difera utilizatorul sa fie anuntat intr-un mod specific
                    if ((width1 != width2) || (height1 != height2)) {
                        System.err.println("Error: Images dimensions mismatch");
                        System.exit(1);//si programul sa se termine
                    }
                    //altfel daca programul continua
                    //se realizeaza o Instanta a clasei ImageOr derivata din Interfata Image
                    ImageOr or = new ImageOr(width1, height1); // constructorul ia ca argumente marimea pozei
                    or.doOr(img1, img2, width1, height1, path);// si folosind obiectul nou creat relizam operatia de OR
                    //intre cele doua imagini salvand rezultatul la path-ul dat ca argument constructorului principal
                    break;
                }
                case 2: {
                    //verificare match imagini din punct de vedere al dimensiunilor
                    width1 = img1.getWidth();
                    height1 = img1.getHeight();
                    width2 = img2.getWidth();
                    height2 = img2.getHeight();
                    start1 = new int[width1 * height1];
                    start2 = new int[width2 * height2];
                    if ((width1 != width2) || (height1 != height2)) {
                        System.err.println("Error: Images dimensions mismatch");
                        System.exit(1);
                    }
                    ///ImageAnd este si ea clasa derivata din interfata Image
                    ImageAnd and = new ImageAnd(width1, height1);
                    and.doAnd(img1, img2, width1, height1, path);
                    break;
                }
                case 3: {
                    //verificare image size mismatch
                    width1 = img1.getWidth();
                    height1 = img1.getHeight();
                    width2 = img2.getWidth();
                    height2 = img2.getHeight();
                    if ((width1 != width2) || (height1 != height2)) {
                        System.err.println("Error: Images dimensions mismatch");
                        System.exit(1);
                    }
                    ImageNAND nand = new ImageNAND(width1, height1);
                    //foloseste pentru realizarea lui ImageNAND clasele ImageAND si imageNOT care sunt la randul lor derivate din interfata Image
                    nand.doNAND(img1, img2, width1, width2, path);
                    break;
                }
                case 4: {
                    width1 = img1.getWidth();
                    height1 = img1.getHeight();
                    width2 = img2.getWidth();
                    height2 = img2.getHeight();
                    if ((width1 != width2) || (height1 != height2)) {
                        System.err.println("Error: Images dimensions mismatch");
                        System.exit(1);
                    }
                    ImageNOR nor = new ImageNOR(width1, height1);
                    //foloseste pentru realizarea operatiei de NOR clasele imageOR si imageNOT care sunt la randul lor derivate din interfata Image
                    nor.doNOR(img1, img2, height1, height2, path);

                    break;
                }
                case 5: {
                    width1 = img1.getWidth();
                    height1 = img1.getHeight();
                    width2 = img2.getWidth();
                    height2 = img2.getHeight();
                    start1 = new int[width1 * height1];
                    start2 = new int[width2 * height2];
                    if ((width1 != width2) || (height1 != height2)) {
                        System.err.println("Error: Images dimensions mismatch");
                        System.exit(1);
                    }
                    //realizam un polimorfism static deoarece exemplificam supraincarcarea metodei DitherMain
                    //care avand 2 argumente joaca rol de operatie NOT
                    //in timp ce cu 4 argumente poate insemna realizarea unor operatii mult mai complexe precum
                    //NOR,NAND,XOR
                    new DitherMain(img1, out1);
                    new DitherMain(img2, out2);
                    //ImageXOR este la randul ei clasa derivata din ImageNAND deoarece asa cum am invatat la PDN
                    //operatia de XOR poate fi realizata doar din operatii de tip NAND sau doar din operatii de tip NOR
                    //pentru simplitate am ales sa implementez folosind operatii de tip NAND
                    ImageXOR xor = new ImageXOR(width1, height1);
                    xor.doXOR(img1, img2, width1, height1, path);
                    break;
                }
                case 6:{
                    width1 = img1.getWidth();
                    height1 = img1.getHeight();
                    width2 = img2.getWidth();
                    height2 = img2.getHeight();
                    start1 = new int[width1 * height1];
                    start2 = new int[width2 * height2];
                    if ((width1 != width2) || (height1 != height2)) {
                        System.err.println("Error: Images dimensions mismatch");
                        System.exit(1);
                    }
                    ImageNot neg = new ImageNot(width1,height1);
                    neg.applyNot(img1,height1,width1,path);
                }
            }
        }
        else if(metoda == 2){
            ///de aici este metoda a doua in care operez direct cu valorile pixelilor
            switch (operatie) {
                case 1: {
                    width1 = img1.getWidth();
                    height1 = img1.getHeight();
                    width2 = img2.getWidth();
                    height2 = img2.getHeight();
                    if ((width1 != width2) || (height1 != height2)) {
                        System.err.println("Error: Images dimensions mismatch");
                        System.exit(1);
                    }
                    //operatia de XOR folosind BinaryImages
                    int [][] pixels1,pixels2;
                    int[] gs_pixels1,gs_pixels2;
                    byte[] gs = new byte[width1*height1];
                    //matricele ce vor fi folosite pe parcursul programului
                    //convertesc din RGB la imagine GrayScale
                    pixels1 = getMatrixOfImage(img1);
                    pixels2 = getMatrixOfImage(img2);
                    BinaryFast b1 = new BinaryFast(pixels1,width1,height1);
                    BinaryFast b2 = new BinaryFast(pixels2,width2,height2);
                    gs_pixels1 = ImageConversions.binary2gs(b1);
                    gs_pixels2 = ImageConversions.binary2gs(b2);
                    //voi forma vectorul grayscale al imaginii
                    for (int i = 0 ;i < gs_pixels1.length;i++){
                        gs[i] = (byte) (gs_pixels1[i] | gs_pixels2[i]);
                    }
                    //creez modelul color folosind imaginea grayscale formata
                    ColorModel cm = new ComponentColorModel(ColorSpace.getInstance(ColorSpace.CS_GRAY), false, false, Transparency.OPAQUE, DataBuffer.TYPE_BYTE);
                    WritableRaster raster = Raster.createInterleavedRaster(new DataBufferByte(gs, gs.length), width1, height1, width1, 1, new int[]{0}, null);
                    //si scriu in fisierul OUT1 pentru a putea compara cu RESULT
                    BufferedImage image2 = new BufferedImage(cm, raster, cm.isAlphaPremultiplied(), null);
                    try {
                        ImageIO.write(image2, "bmp", new File(out1));
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    break;
                }
                case 2: {
                    //verificare match imagini din punct de vedere al dimensiunilor
                    width1 = img1.getWidth();
                    height1 = img1.getHeight();
                    width2 = img2.getWidth();
                    height2 = img2.getHeight();
                    if ((width1 != width2) || (height1 != height2)) {
                        System.err.println("Error: Images dimensions mismatch");
                        System.exit(1);
                    }
                    //operatia de XOR folosind BinaryImages
                    int [][] pixels1,pixels2;
                    int[] gs_pixels1,gs_pixels2;
                    byte[] gs = new byte[width1*height1];
                    //matricele ce vor fi folosite pe parcursul programului
                    //convertesc din RGB la imagine GrayScale
                    pixels1 = getMatrixOfImage(img1);
                    pixels2 = getMatrixOfImage(img2);
                    BinaryFast b1 = new BinaryFast(pixels1,width1,height1);
                    BinaryFast b2 = new BinaryFast(pixels2,width2,height2);
                    gs_pixels1 = ImageConversions.binary2gs(b1);
                    gs_pixels2 = ImageConversions.binary2gs(b2);
                    //voi forma vectorul grayscale al imaginii
                    for (int i = 0 ;i < gs_pixels1.length;i++){
                        gs[i] = (byte) (gs_pixels1[i] & gs_pixels2[i]);
                    }
                    //creez modelul color folosind imaginea grayscale formata
                    ColorModel cm = new ComponentColorModel(ColorSpace.getInstance(ColorSpace.CS_GRAY), false, false, Transparency.OPAQUE, DataBuffer.TYPE_BYTE);
                    WritableRaster raster = Raster.createInterleavedRaster(new DataBufferByte(gs, gs.length), width1, height1, width1, 1, new int[]{0}, null);
                    //si scriu in fisierul OUT1 pentru a putea compara cu RESULT
                    BufferedImage image2 = new BufferedImage(cm, raster, cm.isAlphaPremultiplied(), null);
                    try {
                        ImageIO.write(image2, "bmp", new File(out1));
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    break;
                }
                case 3: {
                    width1 = img1.getWidth();
                    height1 = img1.getHeight();
                    width2 = img2.getWidth();
                    height2 = img2.getHeight();
                    if ((width1 != width2) || (height1 != height2)) {
                        System.err.println("Error: Images dimensions mismatch");
                        System.exit(1);
                    }
                    //operatia de XOR folosind BinaryImages
                    int [][] pixels1,pixels2;
                    int[] gs_pixels1,gs_pixels2;
                    byte[] gs = new byte[width1*height1];
                    //matricele ce vor fi folosite pe parcursul programului
                    //convertesc din RGB la imagine GrayScale
                    pixels1 = getMatrixOfImage(img1);
                    pixels2 = getMatrixOfImage(img2);
                    BinaryFast b1 = new BinaryFast(pixels1,width1,height1);
                    BinaryFast b2 = new BinaryFast(pixels2,width2,height2);
                    gs_pixels1 = ImageConversions.binary2gs(b1);
                    gs_pixels2 = ImageConversions.binary2gs(b2);
                    //voi forma vectorul grayscale al imaginii
                    for (int i = 0 ;i < gs_pixels1.length;i++){
                        gs[i] = (byte) (255 - (gs_pixels1[i] & gs_pixels2[i]));
                    }
                    //creez modelul color folosind imaginea grayscale formata
                    ColorModel cm = new ComponentColorModel(ColorSpace.getInstance(ColorSpace.CS_GRAY), false, false, Transparency.OPAQUE, DataBuffer.TYPE_BYTE);
                    WritableRaster raster = Raster.createInterleavedRaster(new DataBufferByte(gs, gs.length), width1, height1, width1, 1, new int[]{0}, null);
                    //si scriu in fisierul OUT1 pentru a putea compara cu RESULT
                    BufferedImage image2 = new BufferedImage(cm, raster, cm.isAlphaPremultiplied(), null);
                    try {
                        ImageIO.write(image2, "bmp", new File(out1));
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    break;
                }
                case 4: {
                    width1 = img1.getWidth();
                    height1 = img1.getHeight();
                    width2 = img2.getWidth();
                    height2 = img2.getHeight();
                    if ((width1 != width2) || (height1 != height2)) {
                        System.err.println("Error: Images dimensions mismatch");
                        System.exit(1);
                    }
                    //operatia de XOR folosind BinaryImages
                    int [][] pixels1,pixels2;
                    int[] gs_pixels1,gs_pixels2;
                    byte[] gs = new byte[width1*height1];
                    //matricele ce vor fi folosite pe parcursul programului
                    //convertesc din RGB la imagine GrayScale
                    pixels1 = getMatrixOfImage(img1);
                    pixels2 = getMatrixOfImage(img2);
                    BinaryFast b1 = new BinaryFast(pixels1,width1,height1);
                    BinaryFast b2 = new BinaryFast(pixels2,width2,height2);
                    gs_pixels1 = ImageConversions.binary2gs(b1);
                    gs_pixels2 = ImageConversions.binary2gs(b2);
                    //voi forma vectorul grayscale al imaginii
                    for (int i = 0 ;i < gs_pixels1.length;i++){
                        //NOR
                        gs[i] = (byte) ( 255 - (gs_pixels1[i] | gs_pixels2[i] ));
                    }
                    //creez modelul color folosind imaginea grayscale formata
                    ColorModel cm = new ComponentColorModel(ColorSpace.getInstance(ColorSpace.CS_GRAY), false, false, Transparency.OPAQUE, DataBuffer.TYPE_BYTE);
                    WritableRaster raster = Raster.createInterleavedRaster(new DataBufferByte(gs, gs.length), width1, height1, width1, 1, new int[]{0}, null);
                    //si scriu in fisierul OUT1 pentru a putea compara cu RESULT
                    BufferedImage image2 = new BufferedImage(cm, raster, cm.isAlphaPremultiplied(), null);
                    try {
                        ImageIO.write(image2, "bmp", new File(out1));
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    break;
                }
                case 5: {
                    width1 = img1.getWidth();
                    height1 = img1.getHeight();
                    width2 = img2.getWidth();
                    height2 = img2.getHeight();
                    if ((width1 != width2) || (height1 != height2)) {
                        System.err.println("Error: Images dimensions mismatch");
                        System.exit(1);
                    }
                    //operatia de XOR folosind BinaryImages
                    int [][] pixels1,pixels2;
                    int[] gs_pixels1,gs_pixels2;
                    byte[] gs = new byte[width1*height1];
                    //matricele ce vor fi folosite pe parcursul programului
                    //convertesc din RGB la imagine GrayScale
                    pixels1 = getMatrixOfImage(img1);
                    pixels2 = getMatrixOfImage(img2);
                    BinaryFast b1 = new BinaryFast(pixels1,width1,height1);
                    BinaryFast b2 = new BinaryFast(pixels2,width2,height2);
                    gs_pixels1 = ImageConversions.binary2gs(b1);
                    gs_pixels2 = ImageConversions.binary2gs(b2);
                    //voi forma vectorul grayscale al imaginii
                    for (int i = 0 ;i < gs_pixels1.length;i++){
                        gs[i] = (byte) (gs_pixels1[i] ^ gs_pixels2[i]);
                    }
                    //creez modelul color folosind imaginea grayscale formata
                    ColorModel cm = new ComponentColorModel(ColorSpace.getInstance(ColorSpace.CS_GRAY), false, false, Transparency.OPAQUE, DataBuffer.TYPE_BYTE);
                    WritableRaster raster = Raster.createInterleavedRaster(new DataBufferByte(gs, gs.length), width1, height1, width1, 1, new int[]{0}, null);
                    //si scriu in fisierul OUT1 pentru a putea compara cu RESULT
                    BufferedImage image2 = new BufferedImage(cm, raster, cm.isAlphaPremultiplied(), null);
                    try {
                        ImageIO.write(image2, "bmp", new File(out1));
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    break;
                }
                case 6: {
                    //apelam DitherMain cu 2 argumente pentru realizarea operatiei de NOT pe imagine
                    width1 = img1.getWidth();
                    height1 = img1.getHeight();
                    //iau dimensiunile imaginii pe care o dau ca argument
                    int [][] pixels;
                    int[] gs_pixels;
                    byte[] gs = new byte[width1*height1];
                    //initializez vectorii si matricele de pixeli pe care le voi folosi de-a lungul programului
                    pixels = getMatrixOfImage(img1); // preiau matricea de pixeli folosind o functie definita de mine
                    BinaryFast b1 = new BinaryFast(pixels,width1,height1); // creez o imagine tip binaryFast
                    gs_pixels = ImageConversions.binary2gs(b1); // pe care o convertesc la grayscale
                    //fac operatia de NOT direct pe binaryImage
                    for (int i = 0 ;i < gs_pixels.length;i++){
                        gs[i] = (byte)(255- gs_pixels[i]);
                    }
                    //creez modelul color folosind imaginea grayscale formata
                    ColorModel cm = new ComponentColorModel(ColorSpace.getInstance(ColorSpace.CS_GRAY), false, false, Transparency.OPAQUE, DataBuffer.TYPE_BYTE);
                    WritableRaster raster = Raster.createInterleavedRaster(new DataBufferByte(gs, gs.length), width1, height1, width1, 1, new int[]{0}, null);
                    //si scriu in fisierul OUT1 pentru a putea compara cu RESULT
                    BufferedImage image2 = new BufferedImage(cm, raster, cm.isAlphaPremultiplied(), null);
                    try {
                        ImageIO.write(image2, "bmp", new File(out1));
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    break;
                }

            }
        }
    }
    //this object transforms the old image and writes the new image
    DitherMain(BufferedImage img, String path) {
        //pentru operatia de NOT
        startImage = img;
        width = img.getWidth();
        height = img.getHeight();
        ImageNot not = new ImageNot(width,height);
        not.applyNot(img,height,width,path);
    }
    //this method just loads a specific buffered image
    public static BufferedImage loadImage(String fileName){
        BufferedImage img;
        //aici am tratat exceptiile pentru citirea dintr-un fisier
        try{
            img = ImageIO.read(new File(fileName));
        } catch (Exception e) {
            e.printStackTrace();
            throw new RuntimeException(e);
        }
        return img;
    }
    //metoda folosita pentru Varianta folosind BinaryFast Images - varianta 2 de realizare a proiectului
    public int[][] getMatrixOfImage(BufferedImage bufferedImage) {

        int width = bufferedImage.getWidth(null);
        int height = bufferedImage.getHeight(null);
        int[][] pixels = new int[width][height];
        //preiau fiecare pixel si il memorez in matricea de pixeli pixels
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                pixels[i][j] = bufferedImage.getRGB(i, j);
            }
        }

        return pixels;
    }
}