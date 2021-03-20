package com.company;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class ImageNot implements Image {
    private int im_height;
    private int im_width;
    private int[] image_dest;
    //implementeaza toate metodele interfetei din care este derivata - interfata Image
    public int getHeight(){
        return im_height;
    }
    public int getWidth(){
        return im_width;
    }
    public void setWidth(int width){
        im_width = width;
    }
    public void setHeight(int height){
        im_height = height;
    }
    //are un constructor ce ia ca parametri dimensiunea imaginii sursa
    ImageNot(int im_in_width,int im_in_height){
        setHeight(im_in_height);
        setWidth(im_in_width);
        image_dest = new int[im_width*im_height];
    }

    public void applyNot(BufferedImage src_image, int height, int width,String path){
        BufferedImage outImg = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
        int result; // pixelul rezultat
        //pentru fiecare pixel voi scadea valoarea sa din 255 pentru a obtine imaginea negata
        //apoi reconstruiesc matricea de pixeli, adica imaginea
        for(int i=0;i< height;i++){
            for(int j = 0; j<width;j++){
                result = 255 - src_image.getRGB(j,i);
                result = 0xff000000 | result<<16 | result<<8 | result;
                outImg.setRGB(j, i, result); // Set result
            }
        }
        //scriu in fisierul destinatie rezultatul
        try {
            ImageIO.write(outImg, "bmp", new File(path));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
