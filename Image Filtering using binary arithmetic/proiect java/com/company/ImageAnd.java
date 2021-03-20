package com.company;

import javax.imageio.ImageIO;
import java.applet.*;
import java.awt.*;
import java.awt.image.*;
import java.net.*;
import java.util.*;
import java.io.*;


/**
 */

public class ImageAnd implements Image {

    //the width of the input images in pixels
    private int i1_w;
    private int i2_w;
    public int getHeight(){
        return i1_w;
    }


    public int getWidth(){

        return i2_w;
    }
    public void setWidth(int width){
        i1_w = width;
    }
    public void setHeight(int height){
        i2_w = height;
    }

    //the width and height of the output image
    public ImageAnd(int firstwidth, int secondwidth) {
        i1_w = firstwidth;
        i2_w = secondwidth;
    }
    public void doAnd(BufferedImage img1,BufferedImage img2,int width1,int height1,String path) {
        BufferedImage outImg = new BufferedImage(width1, height1, BufferedImage.TYPE_INT_RGB);
        int asem = 0;
        int result; // Stores output pixel
        for (int i = 0; i < height1; i++) {
            for (int j = 0; j < width1; j++) {
                int rgb1 = img1.getRGB(j, i);
                int rgb2 = img2.getRGB(j, i);
                //scoatem componentele RGB din fiecare pixel al imaginii
                int r1 = (rgb1 >> 16) & 0xff;
                int g1 = (rgb1 >> 8) & 0xff;
                int b1 = (rgb1) & 0xff;
                int r2 = (rgb2 >> 16) & 0xff;
                int g2 = (rgb2 >> 8) & 0xff;
                int b2 = (rgb2) & 0xff;
                //identificam pixelii indentici si diferiti si aplicam operatii de AND
                if (r1 == r2) {
                    asem += r1;
                } else {
                    asem += r1 & r2;
                }
                if (g1 == g2) {
                    asem += g1;

                } else {
                    asem += g1 & g2;
                }
                if (b1 == b2) {
                    asem += b1;

                } else {
                    asem += b1 & b2;
                }
                asem = asem / 3; // Pentru a ne asigura ca rezultatul este in intervalul 0 - 255
                result = (asem << 16) | (asem << 8) | asem; // refacem pixelul initial
                outImg.setRGB(j, i, result); // Set result
            }
        }
        //desigur, ne asiguram ca tratarea exceptiilor pentru scrierea in fisier este acoperita.
        try {
            ImageIO.write(outImg, "bmp", new File(path));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
