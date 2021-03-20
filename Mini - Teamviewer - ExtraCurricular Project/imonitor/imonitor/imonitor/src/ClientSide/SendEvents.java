package ClientSide;

import java.awt.AWTEvent;
import java.awt.EventQueue;
import java.awt.Point;
import java.awt.Toolkit;
import java.awt.event.*;
import java.io.*;
import java.net.Socket;
import java.awt.AWTEvent;
import java.awt.EventQueue;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JPanel;

public class SendEvents implements KeyListener,MouseMotionListener,MouseListener {
	
	private Socket connectionChannel = null;
	private JPanel connectionPanel = null;
	private PrintWriter writer = null;
	String width = "",height = "";
	double w,h;
	
	
	public SendEvents(Socket connectionChannel, JPanel connectionPanel, String width, String height) {
		this.connectionChannel = connectionChannel;
		this.connectionPanel = connectionPanel;
		this.width = width;
		this.height = height;
		w = Double.valueOf(width.trim()).doubleValue();
		h = Double.valueOf(height.trim()).doubleValue();
		
		//we add listeners for identifying whether the client has
		//made some changes on the remote screen such as mouse Press or Key Press
		this.connectionPanel.addKeyListener(this);
		this.connectionPanel.addMouseListener(this);
		this.connectionPanel.addMouseMotionListener(this);
		//Using the writer is the most important part because it ensures that the action performed by the client
		//will also be performed in the server screen
    	try {
			writer = new PrintWriter(connectionChannel.getOutputStream());
		}
		catch(IOException e) {
			e.printStackTrace();
		}
	}
	//We need to override all methods that are contained in KeyListener,MouseMotionListener,MouseListener
	//However we only need the five events defined in the Commands.java file
	@Override
	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub
	}


	@Override
	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub
		writer.println(Commands.PRESS_MOUSE.getAbbrev());
		int button = e.getButton();
		int xButton = 16;
		if(button == 3) {
			xButton = 4;
		}
		writer.println(xButton);
		writer.flush();
	}


	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub
		writer.println(Commands.RELEASE_MOUSE.getAbbrev());
		int button = e.getButton();
		int xButton = 16;
		if(button == 3) {
			xButton = 4;
		}
		writer.println(xButton);
		writer.flush();
	}


	@Override
	public void mouseEntered(MouseEvent e) {
		//changing the state of mouse
		
		
		
	}


	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}


	@Override
	public void mouseDragged(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}


	@Override
	public void mouseMoved(MouseEvent e) {
		// TODO Auto-generated method stub
		double xScale = (double)(w/connectionPanel.getWidth());
		double yScale = (double)(h/connectionPanel.getHeight());
		writer.println(Commands.MOVE_MOUSE.getAbbrev());
		writer.println((int)(e.getX()*xScale));
		writer.println((int)(e.getY()*yScale));
		writer.flush();
		
	}


	@Override
	public void keyTyped(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}


	@Override
	public void keyPressed(KeyEvent e) {
		//Getting key codes 
		writer.println(Commands.PRESS_KEY.getAbbrev());
		writer.println(e.getKeyCode());
		writer.flush();
	}


	@Override
	public void keyReleased(KeyEvent e) {
		writer.println(Commands.RELEASE_KEY.getAbbrev());
		writer.println(e.getKeyCode());
		writer.flush();
	}

}
