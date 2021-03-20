package application;

import java.net.UnknownHostException;

import ClientSide.StartClient;
import serverSide.StartServer;
public class App {
	
	public static void usage() {
		System.err.println("Compilation failed!");
		System.out.println("Mod de utilizare al aplicatiei:");
		System.out.println("1. Pe un calculator se ruleaza App.java cu argumentul 'server' - cel la care vrem sa ne conectam");
		System.out.println("\t 1.1 De asemenea, aflam ip-ul server-ului pentru a il putea introduce ca data de autentificare");
		System.out.println("\t 1.2 Setam parola ca data de autentificare si asteptam ca un client sa se conecteze");
		System.out.println("2. Pe un alt calculator se ruleaza App.java cu argumentul 'client' - cel care se conecteaza");
		System.out.println("\t 2.1 Se introduce ip-ul calculatorului la care dorim sa ne conectam ");
		System.out.println("\t 2.2 Se introduce parola de autentificare");
		System.out.println("3. In acest moment ar trebui sa putem observa faptul ca suntem pregatiti sa lucram remote pe calculatorul la care ne-am conectat iar orice modificare");
		System.out.println("   pe remote dektop este monitorizata.");
		System.out.println("4. Pentru oprirea conexiunii, se va opri mai intai server-ul si apoi se va opri conexiunea din partea clientului");
		System.out.println("   pentru a ne asigura ca toate thread-urile se inchid in mod automat corespunzator");
	}
	public static void main(String[] args) throws NumberFormatException, UnknownHostException {
		// TODO Auto-generated method stub
		if(args.length == 1) {
			switch(args[0]) {
				case "server": StartServer.main(new String[] {}); break;
				case "client": StartClient.main(new String[] {}); break;
				default: usage();break;
			}
		}
		else {
			usage();
		}
	}

}
