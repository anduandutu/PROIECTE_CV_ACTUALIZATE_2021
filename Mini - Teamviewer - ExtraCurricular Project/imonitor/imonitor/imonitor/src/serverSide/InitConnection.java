package serverSide;

import java.awt.*;
import java.io.*;
import java.net.*;
import java.nio.file.Path;
import java.nio.file.Paths;

import javax.swing.*;

import loggingAndActionMonitoring.QueueEvents;
public class InitConnection {

	ServerSocket socket = null;
	DataInputStream pass = null;
	DataOutputStream verify = null;
	String width = "",height = "";
	
	public InitConnection(int port, String value1) {
		// TODO Auto-generated constructor stub
		Robot robot = null;
		Rectangle rect = null;
		try {
			//establishing connection
			System.out.println("Initializing connection...");
			socket = new ServerSocket(port);
			
			//initializing display parameters
			GraphicsEnvironment GEnv = GraphicsEnvironment.getLocalGraphicsEnvironment();
			GraphicsDevice GDev = GEnv.getDefaultScreenDevice();
			Dimension  screenDim = Toolkit.getDefaultToolkit().getScreenSize();
			String width = ""+ screenDim.getWidth();
			String height = "" + screenDim.getHeight();
			rect = new Rectangle(screenDim);
			robot = new Robot(GDev);
			
			
			drawGUI();
			
			while(true) {
				//try establishing a client-server connection
				Socket client_server = socket.accept();
				pass = new DataInputStream(client_server.getInputStream());
				verify = new DataOutputStream(client_server.getOutputStream());
				String password = pass.readUTF();
				
				//if the password matches
				if(password.equals(value1)) {
					//Then it means connection is valid
					verify.writeUTF("valid");
					verify.writeUTF(width);
					verify.writeUTF(height);
					
					
					//All of the following will happen at the same time
					
					//continously send Screens to client
					new SendScreen(client_server,robot,rect);
					//continously receive events from the client
					new ReceiveEvents(client_server,robot);
					//write to a log file authentication data
					new loggingAndActionMonitoring.LogData(client_server,socket);
					
					//And monitor for changes in files accesible on Desktop
					boolean recursive = true;
			        String desktopPath = System.getProperty("user.home") + "/Desktop";
					
			        // register directory and process its events
			        Path dir = Paths.get(desktopPath.replace("\\", "/"));
			        new QueueEvents(dir, recursive).processEvents();
				}
				else {
					//invalidate the connection
					verify.writeUTF("Invalid");
				}
			}
			
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	private void drawGUI() {
		
	}
}
