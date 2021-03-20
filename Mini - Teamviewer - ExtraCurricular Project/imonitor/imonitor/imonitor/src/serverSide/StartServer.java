package serverSide;

import java.awt.EventQueue;


public class StartServer {
	
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			  public void run() {
				//setting password for remote connection to the client
				//which has the role of a server right now
				SetPassword connectFrame = new SetPassword();
				connectFrame.setSize(300,80);
				connectFrame.setLocation(500,300);
				connectFrame.setVisible(true);
			}
		});
	}

}
