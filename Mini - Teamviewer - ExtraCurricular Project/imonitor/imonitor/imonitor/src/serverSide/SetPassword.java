package serverSide;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class SetPassword extends JFrame implements ActionListener{
	
	static String port = "1";
	
	
	JButton submit;
	JPanel panel;
	JTextField text1,text2;
	String value1,value2;
	JLabel label, label1,label2;
	
	SetPassword(){
		
		//GUI for getting password from client
		label1 = new JLabel();
		label1.setText("Introduce the password");
		text1 = new JTextField(20);
		label = new JLabel();
		this.setLayout(new BorderLayout());
		submit = new JButton("Submit password!");
		
		panel = new JPanel(new GridLayout(2,1));
		panel.add(label1);
		panel.add(text1);
		panel.add(label);
		panel.add(submit);
		add(panel,BorderLayout.CENTER);
		
		
		submit.addActionListener(this);
		setTitle("Connecting to the other client...");
		
	}
	@Override
	public void actionPerformed(ActionEvent ae) {
		// TODO Auto-generated method stub
		value1 = text1.getText();
		dispose();
		//after receiving the password 
		//we start the connection
		new InitConnection(Integer.parseInt(port),value1);
	}
	
	public String getValue1() {
		return value1;
	}
	
	public static void main(String args[]) {
		SetPassword frame1 = new SetPassword();
		frame1.setSize(300,50);
		frame1.setLocation(500,300);
		frame1.setVisible(true);
	}
}
