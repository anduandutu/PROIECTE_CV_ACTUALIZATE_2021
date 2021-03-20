package com.company;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.awt.image.WritableRaster;
import java.io.File;
import java.io.IOException;

public class ImageXOR extends ImageNAND {

    public ImageXOR(int firstwidth, int secondwidth) {
        super(firstwidth, secondwidth);
    }
    static String out1 = "C:\\Users\\andrei.gheorghe1901\\Desktop\\Anul_3\\AWJ\\out1.bmp";
    static String out2 = "C:\\Users\\andrei.gheorghe1901\\Desktop\\Anul_3\\AWJ\\out2.bmp";
    public void doXOR(BufferedImage img1,BufferedImage img2,int width,int height,String path){
        BufferedImage out1_intermediar = loadImage(out1);
        BufferedImage out2_intermediar = loadImage(out2);
        //mai intai am negat cele 2 imagini si salvat in out1 si out2
        ImageNAND nand1 = new ImageNAND(width,height);

        nand1.doNAND(out1_intermediar,img2,width,height,out1);
        nand1.doNAND(img1,out2_intermediar,width,height,out2);

        BufferedImage out_final1 = loadImage(out1);
        BufferedImage out_final2 = loadImage(out2);
        nand1.doNAND(out_final1,out_final2,width,height,path);
    }
}
