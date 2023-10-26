#pragma once
#include "User.h"

namespace MyRestaurantProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for RegisterForm
	/// </summary>
	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	public:
		RegisterForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			this->CenterToScreen();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RegisterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ userLabel;
	protected:
	private: System::Windows::Forms::Label^ passLabel;
	private: System::Windows::Forms::Label^ verifyPassLabel;
	private: System::Windows::Forms::Label^ nameLabel;
	private: System::Windows::Forms::TextBox^ lbUser;
	private: System::Windows::Forms::TextBox^ lbPassword;
	private: System::Windows::Forms::TextBox^ lbVerifyPassword;
	private: System::Windows::Forms::TextBox^ lbName;




	private: System::Windows::Forms::Button^ btnOK;



	private: System::Windows::Forms::Button^ btnLogin;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->userLabel = (gcnew System::Windows::Forms::Label());
			this->passLabel = (gcnew System::Windows::Forms::Label());
			this->verifyPassLabel = (gcnew System::Windows::Forms::Label());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->lbUser = (gcnew System::Windows::Forms::TextBox());
			this->lbPassword = (gcnew System::Windows::Forms::TextBox());
			this->lbVerifyPassword = (gcnew System::Windows::Forms::TextBox());
			this->lbName = (gcnew System::Windows::Forms::TextBox());
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// userLabel
			// 
			this->userLabel->AutoSize = true;
			this->userLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->userLabel->Location = System::Drawing::Point(32, 130);
			this->userLabel->Name = L"userLabel";
			this->userLabel->Size = System::Drawing::Size(110, 25);
			this->userLabel->TabIndex = 0;
			this->userLabel->Text = L"Username";
			// 
			// passLabel
			// 
			this->passLabel->AutoSize = true;
			this->passLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passLabel->Location = System::Drawing::Point(32, 169);
			this->passLabel->Name = L"passLabel";
			this->passLabel->Size = System::Drawing::Size(106, 25);
			this->passLabel->TabIndex = 1;
			this->passLabel->Text = L"Password";
			// 
			// verifyPassLabel
			// 
			this->verifyPassLabel->AutoSize = true;
			this->verifyPassLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->verifyPassLabel->Location = System::Drawing::Point(32, 205);
			this->verifyPassLabel->Name = L"verifyPassLabel";
			this->verifyPassLabel->Size = System::Drawing::Size(165, 25);
			this->verifyPassLabel->TabIndex = 2;
			this->verifyPassLabel->Text = L"Verify password";
			// 
			// nameLabel
			// 
			this->nameLabel->AutoSize = true;
			this->nameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nameLabel->Location = System::Drawing::Point(32, 241);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(68, 25);
			this->nameLabel->TabIndex = 3;
			this->nameLabel->Text = L"Name";
			// 
			// lbUser
			// 
			this->lbUser->Location = System::Drawing::Point(202, 135);
			this->lbUser->Name = L"lbUser";
			this->lbUser->Size = System::Drawing::Size(298, 20);
			this->lbUser->TabIndex = 4;
			// 
			// lbPassword
			// 
			this->lbPassword->Location = System::Drawing::Point(202, 169);
			this->lbPassword->Name = L"lbPassword";
			this->lbPassword->PasswordChar = '*';
			this->lbPassword->Size = System::Drawing::Size(298, 20);
			this->lbPassword->TabIndex = 5;
			// 
			// lbVerifyPassword
			// 
			this->lbVerifyPassword->Location = System::Drawing::Point(203, 205);
			this->lbVerifyPassword->Name = L"lbVerifyPassword";
			this->lbVerifyPassword->PasswordChar = '*';
			this->lbVerifyPassword->Size = System::Drawing::Size(298, 20);
			this->lbVerifyPassword->TabIndex = 6;
			// 
			// lbName
			// 
			this->lbName->Location = System::Drawing::Point(203, 241);
			this->lbName->Name = L"lbName";
			this->lbName->Size = System::Drawing::Size(298, 20);
			this->lbName->TabIndex = 7;
			// 
			// btnOK
			// 
			this->btnOK->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOK->Location = System::Drawing::Point(284, 317);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(75, 35);
			this->btnOK->TabIndex = 8;
			this->btnOK->Text = L"Ok";
			this->btnOK->UseVisualStyleBackColor = true;
			this->btnOK->Click += gcnew System::EventHandler(this, &RegisterForm::btnOK_Click);
			// 
			// btnLogin
			// 
			this->btnLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLogin->Location = System::Drawing::Point(368, 317);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(133, 33);
			this->btnLogin->TabIndex = 10;
			this->btnLogin->Text = L"Back to login";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &RegisterForm::btnLogin_Click);
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(528, 412);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->btnOK);
			this->Controls->Add(this->lbName);
			this->Controls->Add(this->lbVerifyPassword);
			this->Controls->Add(this->lbPassword);
			this->Controls->Add(this->lbUser);
			this->Controls->Add(this->nameLabel);
			this->Controls->Add(this->verifyPassLabel);
			this->Controls->Add(this->passLabel);
			this->Controls->Add(this->userLabel);
			this->Name = L"RegisterForm";
			this->Text = L"RegisterForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: User^ user = nullptr;
	
	private: System::Void btnOK_Click(System::Object^ sender, System::EventArgs^ e) {
		// Get user input
		String^ username = lbUser->Text;
		String^ password = lbPassword->Text;
		String^ name = lbName->Text;

		// Check if any of the fields are empty
		if (username->Length == 0 || password->Length == 0 || name->Length == 0) {
			MessageBox::Show("Please enter all fields!", "Lacking fields", MessageBoxButtons::OK);
			return;
		}

		// Check if the entered password and verify password match
		if (String::Compare(password, lbVerifyPassword->Text) != 0) {
			MessageBox::Show("Password not matching!", "Password Error", MessageBoxButtons::OK);
			return;
		}

		try {
			// Establish a connection to the database
			String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=myrestaurant;Integrated Security=True";
			SqlConnection^ sqlConn = gcnew SqlConnection(connString);

			// Open the database connection
			sqlConn->Open();

			// Check if the username already exists in the database
			String^ checkQuery = "SELECT COUNT(*) FROM users WHERE username = @username";
			SqlCommand checkCommand(checkQuery, sqlConn);
			checkCommand.Parameters->AddWithValue("@username", username);

			int userCount = Convert::ToInt32(checkCommand.ExecuteScalar());

			// If a user with the same username already exists, show an error message
			if (userCount > 0) {
				MessageBox::Show("Username is already taken!", "Username Error", MessageBoxButtons::OK);
				return;
			}

			// If the username is not taken, insert the new user into the database
			String^ insertQuery = "INSERT into users (username, password, name) VALUES (@username, @pwd, @name);";
			SqlCommand insertCommand(insertQuery, sqlConn);
			insertCommand.Parameters->AddWithValue("@username", username);
			insertCommand.Parameters->AddWithValue("@pwd", password);
			insertCommand.Parameters->AddWithValue("@name", name);

			// Execute the SQL command to insert the user
			insertCommand.ExecuteNonQuery();

			// Create a User object to represent the registered user
			user = gcnew User;
			user->username = username;
			user->password = password;
			user->name = name;

			// Close the registration form
			this->Close();
		}
		catch (Exception^ ex) {
			// Handle any database errors and show an error message
			MessageBox::Show("Failed to register! " + ex->Message, "Database error", MessageBoxButtons::OK);
		}
	}

	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	public: bool switchToLogin = false;
	private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		this->switchToLogin = true;
		this->Close();
	}
};
}
