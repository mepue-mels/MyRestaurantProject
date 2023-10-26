
#include "LoginForm.h"
#include "RegisterForm.h"
#include "MainForm.h"
#include "AdminForm.h"
using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	User^ user = nullptr;
	while (true) {
		MyRestaurantProject::LoginForm loginForm;
		loginForm.ShowDialog();

		if (loginForm.switchToRegister) {
			MyRestaurantProject::RegisterForm registerForm;
			registerForm.ShowDialog();

			if (registerForm.switchToLogin) {
				continue;
			}
			else {
				user = registerForm.user; 
			}
		}
		else {
			user = loginForm.user;
		}

		if (user->username == "root") {
			MyRestaurantProject::AdminForm adminForm;
			adminForm.ShowDialog();
		}
		else {
			MyRestaurantProject::MainForm mainForm(user);
			mainForm.ShowDialog();
		}
		
	}


	//if (user != nullptr) {
	//	MyRestaurantProject::MainForm mainForm(user);
	//	Application::Run(% mainForm);
//	}
	//else {
	//	MessageBox::Show("Authentication Cancelled", "Program.cpp", MessageBoxButtons::OK);
	//}

}