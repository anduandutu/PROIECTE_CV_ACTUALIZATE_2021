package com.company;
import java.awt.*;
import java.lang.Math;
import java.lang.Object.*;
import java.util.*;
public class BinaryFast extends AbstractImage{
    public static final int background = (new Color(0,0,0)).getRGB();
    /**
     * Foreground is white.
     */
    public static final int foreground = (new Color(255,255,255)).getRGB();
    /**
     * Width of the image.
     */
    public int w;
    /**
     * Height of the image.
     */
    public int h;
    /**
     * Size of the image (w*h), number of pixels.
     */
    public int s;
    /**
     * The 2D array of all pixels.
     */
    public int [][] pixels;
    /**
     * The hash set storing positions of foreground edge pixels as Points.
     */
    public HashSet foregroundEdgePixels = new HashSet();
    /**
     * The hash set storing positions of background edge pixels as Points.
     */
    public HashSet backgroundEdgePixels = new HashSet();
    public BinaryFast(int [][] p, int width, int height) { //constructor
        pixels = p;
        w = width;
        h = height;
        s = w * h;
        generateForegroundEdge();
        generateBackgroundEdgeFromForegroundEdge();
    }
    public int [] convertToArray(){
        int [] p = new int [s];
        for(int j=0;j<h;++j){
            for(int i=0;i<w;++i){
                p[(j*w)+i]=pixels[i][j];
            }
        }
        return p;
    }
    /**
     * Generates the foreground edge hash set from the 2D array of pixels.
     */
    public void generateForegroundEdge(){
        foregroundEdgePixels.clear();
        Point p;
        for(int n=0;n<h;++n){
            for(int m=0;m<w;++m){
                if(pixels[m][n]==foreground){
                    p = new Point(m,n);
                    for(int j=-1;j<2;++j){
                        for(int i=-1;i<2;++i){
                            if((p.x+i>=0)&&(p.x+i<w)&&(p.y+j>=0)&&(p.y+j<h)){
                                if((pixels[p.x+i][p.y+j]==background)&&
                                        (!foregroundEdgePixels.contains(p))){
                                    foregroundEdgePixels.add(p);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    /**
     * Generates the background edge hash set from the foreground edge
     * hash set and the 2D array of pixels.
     */
    public void generateBackgroundEdgeFromForegroundEdge(){
        backgroundEdgePixels.clear();
        Point p,p2;
        Iterator it = foregroundEdgePixels.iterator();
        while(it.hasNext()){
            p = new Point((Point) it.next());
            for(int j=-1;j<2;++j){
                for(int i=-1;i<2;++i){
                    if((p.x+i>=0)&&(p.x+i<w)&&(p.y+j>=0)&&(p.y+j<h)){
                        p2 = new Point(p.x+i,p.y+j);
                        if(pixels[p2.x][p2.y]==background){
                            backgroundEdgePixels.add(p2);
                        }
                    }
                }
            }
        }
    }

    /**
     * Returns the int [] values of the Binary Fast image
     * @return int[] the greylevel array of the image
     */
    public int [] getValues() {
        int []values1D = new int[s];
        int []graylevel = new int[s];
        values1D = convertToArray();
        for(int i = 0; i < s; i++) {
            graylevel[i] = values1D[i] & 0x000000ff;
        }
        return graylevel;
    }
}
