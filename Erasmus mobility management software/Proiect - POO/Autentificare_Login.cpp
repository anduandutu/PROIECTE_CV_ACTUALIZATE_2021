#include "Autentificare_Login.h"
[STAThread]
int main(array<System::String ^> ^args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ProiectPOO::Autentificare_Login forma1;
	Application::Run(%forma1);
	return 0;
}



