package com.company;

public class ImageConversions {

    /**
     * Converts a Binary Fast image into a greylevel representation
     */
    public static int[] binary2gs(BinaryFast image) {
        //metoda folosita pentru a transforma un obiect de tip BinaryImage intr-o reprezentare grayscale pe 8 biți
        int [] gs = new int [image.w*image.h];
        for(int i = 0; i < image.w; i++) {
            for(int j = 0; j < image.h; j++) {
                gs[j*image.w+i] = image.pixels[i][j] & 0x000000ff;}}

        return gs;
    }

}