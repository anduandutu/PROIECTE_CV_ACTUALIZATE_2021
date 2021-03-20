package com.company;
import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.awt.image.WritableRaster;
import java.io.File;
import java.io.IOException;
public class ImageNOR extends  ImageOr {
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
    public ImageNOR(int firstwidth, int secondwidth) {
        super(firstwidth, secondwidth);
    }
    public void doNOR(BufferedImage img1, BufferedImage img2, int height, int width,String path){
        doOr(img1,img2,width,height,path);

        //preiau imaginea creata dupa aplicarea operatiei de OR
        BufferedImage img_result = loadImage(path);
        //si o neg
        ImageNot not = new ImageNot(width,height);
        not.applyNot(img_result,img_result.getHeight(),img_result.getWidth(),path);
    }
}
