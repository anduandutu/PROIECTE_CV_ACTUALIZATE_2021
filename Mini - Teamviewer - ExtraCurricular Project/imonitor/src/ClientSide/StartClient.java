package ClientSide;

import java.awt.EventQueue;
import java.net.*;
import javax.swing.JOptionPane;
import java.util.regex.*;
public class StartClient {

	static String port = "1027";
	private static final String IPV4_REGEX =
					"^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\." +
					"(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\." +
					"(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\." +
					"(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$";

	private static final Pattern IPv4_PATTERN = Pattern.compile(IPV4_REGEX);


	public static boolean isValidInet4Address(String ip) {
		if (ip == null) {
			return false;
		}

		Matcher matcher = IPv4_PATTERN.matcher(ip);

		return matcher.matches();
	}
	public static void main(String args[]) throws NumberFormatException, UnknownHostException {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				//We use the EventQueue for saving connection events
				//Such as entering the IP .
				String ip = JOptionPane.showInputDialog("Please enter the ip address you want to connect to:");
				try {
					//Initialize the connection. The client needs to enter a password for authentication
					if(isValidInet4Address(ip)){
					new StartClient().initialize(ip,Integer.parseInt(port));
					}
					else{
						System.err.println("Please enter a valid ip address for initializing the connection");
						System.exit(1);
					}
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
				System.err.println("Connection timeout... The server you are trying to connect to is not open.");
			}
		}
		else {
			System.err.println("You cannot connect to your own ip");
			System.exit(1);
		}
	}
}
