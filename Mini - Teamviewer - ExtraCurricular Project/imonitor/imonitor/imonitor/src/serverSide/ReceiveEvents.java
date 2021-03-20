package serverSide;

import java.awt.AWTEvent;
import java.awt.EventQueue;
import java.awt.Point;
import java.awt.Robot;
import java.awt.Toolkit;
import java.awt.event.MouseEvent;
import java.awt.event.KeyEvent;
import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;

public class ReceiveEvents extends Thread {
	Socket socket = null;
	Robot robot = null;
	boolean continueLoop = true;
	
	
	public ReceiveEvents(Socket client_server, Robot robot) {
		
		this.socket = client_server;
		this.robot = robot;
		start();
	}
	
	public void run() {
		//receiving input from the client side 
		Scanner scanner = null;
		try {
			//continuously receive commands for events
			//from the client
			scanner = new Scanner(socket.getInputStream());
			while(continueLoop) {
				
				int command = scanner.nextInt();
				switch(command) {
					case -1:{
						robot.mousePress(scanner.nextInt());	
						break;
					}
					case -2:{	
						robot.mouseRelease(scanner.nextInt());  
						break;
					}
					case -3:{	
						robot.keyPress(scanner.nextInt());      
						break;
					}
					case -4:{	
						robot.keyRelease(scanner.nextInt());
						break;
					}
					case -5:{	
						robot.mouseMove(scanner.nextInt(), scanner.nextInt());  
						break;
					}
				}
				
			}
			
		}
		catch(IOException e) {
			
			e.printStackTrace();
		}
	}
}
