#include "MainWindow.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

int main(array<String^>^ args) 
{
    Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ParallelPrograming1::MainWindow form;
	Application::Run(% form);
	
	//system("pause");

	return 0;
}
