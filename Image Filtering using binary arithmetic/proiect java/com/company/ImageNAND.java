package com.company;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.awt.image.WritableRaster;
import java.io.File;
import java.io.IOException;

public class ImageNAND extends ImageAnd {
    public ImageNAND(int firstwidth, int secondwidth) {
        super(firstwidth, secondwidth);
    }
    public void doNAND(BufferedImage img1,BufferedImage img2, int width,int height,String path){
        doAnd(img1,img2,width,height,path);

        BufferedImage img_result = loadImage(path);
        ImageNot not = new ImageNot(width,height);
        not.applyNot(img_result,img_result.getHeight(),img_result.getWidth(),path);
    }
    //tratarea exceptiilor de citire a imaginii
    public static BufferedImage loadImage(String fileName){
        BufferedImage img;

        try{
            img = ImageIO.read(new File(fileName));
        } catch (Exception e) {
            e.printStackTrace();
            throw new RuntimeException(e);
        }
        return img;
    }
}
