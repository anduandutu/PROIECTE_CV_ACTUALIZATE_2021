package com.company;
import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class ImageOr implements Image {
    private int im_width1;
    private int im_width2;
    public int getHeight(){
        return im_width1;
    }
    public int getWidth(){
        return im_width2;
    }
    public void setWidth(int width){
        im_width1 = width;
    }
    public void setHeight(int height){
        im_width2 = height;
    }

    public ImageOr(int firstwidth, int secondwidth){
        setWidth(firstwidth);
        setHeight(secondwidth);
    }

    public void doOr(BufferedImage img1, BufferedImage img2, int width1, int height1, String path){
        BufferedImage outImg = new BufferedImage(width1, height1, BufferedImage.TYPE_INT_RGB);
        int diff;
        int result; // Stores output pixel
        for (int i = 0; i < height1; i++) {
            for (int j = 0; j < width1; j++) {
                int rgb1 = img1.getRGB(j, i);
                int rgb2 = img2.getRGB(j, i);
                int r1 = (rgb1 >> 16) & 0xff;
                int g1 = (rgb1 >> 8) & 0xff;
                int b1 = (rgb1) & 0xff;
                int r2 = (rgb2 >> 16) & 0xff;
                int g2 = (rgb2 >> 8) & 0xff;
                int b2 = (rgb2) & 0xff;
                diff = Math.abs(r1 - r2);
                diff += Math.abs(g1 - g2);
                diff += Math.abs(b1 - b2);
                diff /= 3; // ne asiguram ca este o valoare intre  0 - 255
                result = (diff << 16) | (diff << 8) | diff;
                outImg.setRGB(j, i, result); //setez pixelul rezultat
            }
        }
        try {
            ImageIO.write(outImg,"bmp", new File(path));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
