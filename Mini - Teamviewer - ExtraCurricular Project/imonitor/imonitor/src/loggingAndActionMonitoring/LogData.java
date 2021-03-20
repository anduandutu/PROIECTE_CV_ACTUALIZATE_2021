package loggingAndActionMonitoring;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.logging.FileHandler;
import java.util.logging.Logger;
public class LogData {

	public LogData(Socket client_server, ServerSocket socket) throws SecurityException, IOException {
		// TODO Auto-generated constructor stub
		boolean append = true;
		//create a log file
        FileHandler handler = new FileHandler("default.log", append);
        Logger logger = Logger.getLogger("loggingAndActionMonitoring");
        logger.addHandler(handler);
         
        //add info regarding the type of connection used in the log file
        logger.info("IP Connected:"+client_server.getInetAddress());
        logger.info("Port:"+client_server.getLocalPort());
        switch(client_server.getLocalPort()) {
        	case 1: logger.info("Connection type: TCPMUX"); break;
        	case 5: logger.info("Connection type: RJE"); break;
        	case 21: logger.info("Connection type: FTP"); break;
        	case 22: logger.info("Connection type: SSH"); break;
        	case 23: logger.info("Connection type: Telnet"); break;
        	case 42: logger.info("Connection type: HNS"); break;
        	case 53: logger.info("Connection type: DNS"); break;
        	case 80: logger.info("Connection type: HTTP"); break;
        	case 161: logger.info("Connection type: SNMP"); break;
        	case 443: logger.info("Connection type: HTTPS"); break;
        	case 546: logger.info("Connection type: DHCP"); break;
        	default: logger.info("Connection type: Private"); break;
        }
        	
	}
	
}
