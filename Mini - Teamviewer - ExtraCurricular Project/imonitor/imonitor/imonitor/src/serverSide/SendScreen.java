package serverSide;

import java.awt.*;
import java.awt.image.*;
import java.io.*;
import java.net.*;
import javax.imageio.ImageIO;

public class SendScreen extends Thread  {
	//extends the Thread Class as we associate a Thread with the client-server connection
	Socket screenSocket = null;
	Robot robot = null;
	Rectangle rect = null;
	boolean continueLoop = true;
	OutputStream out = null;
	public static String currentPath;
	
	public SendScreen(Socket client_server, Robot robot, Rectangle rect) {
		// TODO Auto-generated constructor stub
		this.screenSocket = client_server;
		this.rect = rect;
		this.robot = robot;
		//associate a thread with the current socket transmission
		start();
	}
	
	public void run() {
		//retrieve outputStream
		try {
			out = screenSocket.getOutputStream();
		}
		catch(IOException e) {
			e.printStackTrace();
		}
		//continuously send screens to Clients
		while(continueLoop) {
			//capture images and store them continously using the @img parameter
			BufferedImage img = robot.createScreenCapture(rect);
			try {
				ImageIO.write(img, "jpeg", out);
			}
			catch(IOException e) {
				e.printStackTrace();
			}
			//The Thread associated with the connection thread will interrupt the sleeping thread asociated 
			//with the server
			try {
				Thread.sleep(10);
			}
			catch(InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}
