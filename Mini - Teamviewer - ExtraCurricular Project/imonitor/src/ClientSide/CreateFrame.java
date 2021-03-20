package ClientSide;

import java.awt.BorderLayout;
import java.beans.PropertyVetoException;
import java.io.IOException;
import java.io.InputStream;
import java.net.*;

import javax.swing.*;

import loggingAndActionMonitoring.QueueEvents;

public class CreateFrame extends Thread {
	String width="",height = "";
	private JFrame frame = new JFrame();
	private JDesktopPane desktop = new JDesktopPane();
	private Socket connectionChannel = null;
	//We may want to open a scrren inside the remote desktop screen
	//Handle Minimize,Maximize,Close Buttons
	private JInternalFrame internalFrame = new JInternalFrame("Remote screen",true,true,true);
	
	private JPanel connectionPanel = new JPanel();
	
	
	
	public CreateFrame(Socket connectionChannel, String width, String height){
		//Creating remote desktop connections
		this.width = width;
		this.height = height;
		this.connectionChannel = connectionChannel;
		//Associate a thread with the connection
		start();
	}
	
	public void drawRemoteGUI() {
		//Setting up the remote view
		frame.add(desktop,BorderLayout.CENTER);
		
		//Setting up default way for closing the remote connection
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		//Setting up default display view
		frame.setExtendedState(frame.getExtendedState() | JFrame.MAXIMIZED_BOTH);
		frame.setVisible(true);
		
		//Showinng the server screen
		//wWhich contains the internalFrame
		internalFrame.setLayout(new BorderLayout());
		internalFrame.getContentPane().add(connectionPanel,BorderLayout.CENTER);
		internalFrame.setSize(100,100);
		desktop.add(internalFrame);
		
		//Resizing to maximum 
		try {
			internalFrame.setMaximum(true);
		}
		catch(PropertyVetoException ex) {
			ex.printStackTrace();
		}
		//
		connectionPanel.setFocusable(true);
		internalFrame.setVisible(true);
	}
	
	public void run() {
		
		//Getting input stream from the client
		InputStream in = null;
		//Draw the GUI which shows the client he has connected to the server
		drawRemoteGUI();
		try {
			in = connectionChannel.getInputStream();
		}
		catch(IOException e){
			e.printStackTrace();
		}
		
		//We start monitoring possible events that happened during the remote conn
		//session
		new ReceivingScreen(in,connectionPanel);
		new SendEvents(connectionChannel,connectionPanel,width,height);
	}
	
}
