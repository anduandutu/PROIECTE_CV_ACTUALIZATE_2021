package com.company;

public abstract class AbstractImage {
    protected int width;
    protected int height;
    public int getWidth(){
        return width;
    }
    public int getHeight(){
        return height;
    }
    public abstract int [] getValues();
}
