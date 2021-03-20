package ClientSide;

import java.net.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.io.*;

@SuppressWarnings("serial")
public class Authentication extends JFrame implements ActionListener {
		
	private Socket connectionChannel = null;
	DataOutputStream passConnection = null;
	DataInputStream verification = null;
	String verify = "";
	
	//for GUI elements
	JButton submit;
	JPanel panel;
	JLabel label,label1;
	String width = "",height ="";
	JTextField text1;
	
	//Constructor
	Authentication(Socket connect){
		
		//Setting Application Layout
		label1 = new JLabel();
		label1.setText("Password");
		text1 = new JTextField(30);
		//Setting the socked used for remote connection
		this.connectionChannel = connect;
		
		label = new JLabel();
		label.setText("");
		this.setLayout(new BorderLayout());
		submit = new JButton("Submit");
		panel = new JPanel(new GridLayout(2,1));
		
		
		//Adding GUI Elements 
		panel.add(label1);
		panel.add(text1);
		panel.add(label);
		panel.add(submit);
		add(panel,BorderLayout.CENTER);
		//Wait for the user to press the submit button
		submit.addActionListener(this);
		setTitle("Login Form");

		
	}

	@Override
	public void actionPerformed(ActionEvent AE) {
		String pass_Auth = text1.getText();
		try {
			//Verification of Authentication Data 
			this.passConnection = new DataOutputStream(this.connectionChannel.getOutputStream());
			verification = new DataInputStream(this.connectionChannel.getInputStream());
			passConnection.writeUTF(pass_Auth);
			verify = verification.readUTF();
		}
		catch(Exception e) {
			e.printStackTrace();
		}
		
		//Verify that program received a valid password for the remote connection
		if(verify.equals("valid")) {
			
			
			//Obtaining display parameters
			try {
				width = verification.readUTF();
				height = verification.readUTF();
			} catch (IOException e) {
				e.printStackTrace();
			}
			//Display remote scrren
			new CreateFrame(this.connectionChannel,width,height);
			//clear the resources
			dispose();
		}
		else {
			//Notify the user of password invalidation
			System.err.print("Please enter a valid password");
			JOptionPane.showMessageDialog(this, "The password you entered is incorrect","Error",JOptionPane.ERROR_MESSAGE);
			System.exit(1);
			dispose();
			
		}
	}
}
