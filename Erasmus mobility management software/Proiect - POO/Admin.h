#pragma once
#include "Utilizatori_clasa.h"
#include <cstdlib>
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::SqlClient;
public class Admin : public Utilizatori{
public:
	Admin(string firstname, string lastname){
		firstName = firstname;
		lastName = lastname;
	};
	bool verificareAdmin();
};
bool Admin::verificareAdmin(){
	if ((firstName == "Irina" || firstName == "irina") && (lastName == "Severin" || lastName == "severin"))
	{
		return true;
	}
	else{
		return false;
	}
}