package ClientSide;

import java.awt.EventQueue;
import java.net.*;
import javax.swing.JOptionPane;

public class StartClient {

	static String port = "1";
	public static void main(String args[]) throws NumberFormatException, UnknownHostException {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				//We use the EventQueue for saving connection events
				//Such as entering the IP .
				String ip = JOptionPane.showInputDialog("Please enter the ip address you want to connect to:");
				try {
					//Initialize the connection. The client needs to enter a password for authentication
					new StartClient().initialize(ip,Integer.parseInt(port));
				} catch (NumberFormatException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					System.err.println("Invalid format!");
				} catch (UnknownHostException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					System.err.println("Invalid host!");
				}
			}
		});
	}
	
	public void initialize(String ip_adress, int portToConnectTo) throws UnknownHostException {
		//In the initialization part we verify that the client will not connect to his own ip ]
		//Because it will result in streaming continously a remote screen inside another remote screen
		String my_own_ip = InetAddress.getLocalHost().getHostAddress();
		System.out.println(my_own_ip + "is trying to connect to" + ip_adress);
		if(my_own_ip.trim().contentEquals(ip_adress) == false) {
			try {
				Socket communicationChannel = new Socket(ip_adress,portToConnectTo);
				System.out.println("Connecting to partner...");
				
				//Provide an authentication process
				Authentication frame1 = new Authentication(communicationChannel);
				frame1.setSize(300,80);
				frame1.setLocation(500,300);
				frame1.setVisible(true);
				
			}
			catch(Exception e) {
				e.printStackTrace();
			}
		}
		else {
			System.err.println("You cannot connect to your own ip");
			System.exit(1);
		}
	}
}
