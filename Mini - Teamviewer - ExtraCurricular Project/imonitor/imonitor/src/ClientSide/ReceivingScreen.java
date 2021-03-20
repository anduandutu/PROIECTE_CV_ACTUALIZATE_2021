package ClientSide;

import java.io.*;
import java.awt.*;

import javax.imageio.ImageIO;
import javax.swing.JPanel;

public class ReceivingScreen extends Thread{
	
	private ObjectInputStream remoteInputStream = null;
	private JPanel connectionPanel = null;
	private boolean continueStream = true;
	InputStream in = null;
	Image screen = null;
	
	
	public ReceivingScreen(InputStream inStream, JPanel connPanel) {
		// TODO Auto-generated constructor stub
		in = inStream;
		connectionPanel = connPanel;
		start();
	}
	
	public void run() {
		//continuously receiving screen from the station we want to remotely connect to
		try {
			while(true) {
				
				byte[] bytes = new byte[1024*1024];
				int count = 0;
				do {
					//@count -- offset of value
					//read data from input stream starting from the offset set by count
					count+=in.read(bytes,count,bytes.length-count);
					
					
				}while(!(count>4 && bytes[count-2]==(byte) - 1 && bytes[count-1] == (byte) - 39));
				
				//reading current screen frame
				screen = ImageIO.read(new ByteArrayInputStream(bytes));
				screen = screen.getScaledInstance(connectionPanel.getWidth(), connectionPanel.getHeight(), Image.SCALE_FAST);
				//
				//and display it continuously
				Graphics graphics = connectionPanel.getGraphics();
				graphics.drawImage(screen, 0, 0, connectionPanel.getWidth(), connectionPanel.getHeight(),connectionPanel);
			}
		}
		catch(IOException e){
			e.printStackTrace();
		}
		
	}
}
