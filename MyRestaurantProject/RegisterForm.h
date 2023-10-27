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




	private: System::Windows::Forms::LinkLabel^ linkLabel1;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegisterForm::typeid));
			this->userLabel = (gcnew System::Windows::Forms::Label());
			this->passLabel = (gcnew System::Windows::Forms::Label());
			this->verifyPassLabel = (gcnew System::Windows::Forms::Label());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->lbUser = (gcnew System::Windows::Forms::TextBox());
			this->lbPassword = (gcnew System::Windows::Forms::TextBox());
			this->lbVerifyPassword = (gcnew System::Windows::Forms::TextBox());
			this->lbName = (gcnew System::Windows::Forms::TextBox());
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->SuspendLayout();
			// 
			// userLabel
			// 
			this->userLabel->AutoSize = true;
			this->userLabel->BackColor = System::Drawing::Color::Transparent;
			this->userLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->userLabel->ForeColor = System::Drawing::Color::White;
			this->userLabel->Location = System::Drawing::Point(47, 197);
			this->userLabel->Name = L"userLabel";
			this->userLabel->Size = System::Drawing::Size(83, 20);
			this->userLabel->TabIndex = 0;
			this->userLabel->Text = L"Username";
			// 
			// passLabel
			// 
			this->passLabel->AutoSize = true;
			this->passLabel->BackColor = System::Drawing::Color::Transparent;
			this->passLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passLabel->ForeColor = System::Drawing::Color::White;
			this->passLabel->Location = System::Drawing::Point(47, 243);
			this->passLabel->Name = L"passLabel";
			this->passLabel->Size = System::Drawing::Size(78, 20);
			this->passLabel->TabIndex = 1;
			this->passLabel->Text = L"Password";
			// 
			// verifyPassLabel
			// 
			this->verifyPassLabel->AutoSize = true;
			this->verifyPassLabel->BackColor = System::Drawing::Color::Transparent;
			this->verifyPassLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->verifyPassLabel->ForeColor = System::Drawing::Color::White;
			this->verifyPassLabel->Location = System::Drawing::Point(47, 289);
			this->verifyPassLabel->Name = L"verifyPassLabel";
			this->verifyPassLabel->Size = System::Drawing::Size(121, 20);
			this->verifyPassLabel->TabIndex = 2;
			this->verifyPassLabel->Text = L"Verify password";
			// 
			// nameLabel
			// 
			this->nameLabel->AutoSize = true;
			this->nameLabel->BackColor = System::Drawing::Color::Transparent;
			this->nameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nameLabel->ForeColor = System::Drawing::Color::White;
			this->nameLabel->Location = System::Drawing::Point(47, 335);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(51, 20);
			this->nameLabel->TabIndex = 3;
			this->nameLabel->Text = L"Name";
			// 
			// lbUser
			// 
			this->lbUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbUser->Location = System::Drawing::Point(51, 220);
			this->lbUser->Name = L"lbUser";
			this->lbUser->Size = System::Drawing::Size(259, 21);
			this->lbUser->TabIndex = 4;
			// 
			// lbPassword
			// 
			this->lbPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbPassword->Location = System::Drawing::Point(51, 266);
			this->lbPassword->Name = L"lbPassword";
			this->lbPassword->PasswordChar = '*';
			this->lbPassword->Size = System::Drawing::Size(259, 21);
			this->lbPassword->TabIndex = 5;
			// 
			// lbVerifyPassword
			// 
			this->lbVerifyPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbVerifyPassword->Location = System::Drawing::Point(51, 312);
			this->lbVerifyPassword->Name = L"lbVerifyPassword";
			this->lbVerifyPassword->PasswordChar = '*';
			this->lbVerifyPassword->Size = System::Drawing::Size(259, 21);
			this->lbVerifyPassword->TabIndex = 6;
			// 
			// lbName
			// 
			this->lbName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbName->Location = System::Drawing::Point(51, 358);
			this->lbName->Name = L"lbName";
			this->lbName->Size = System::Drawing::Size(259, 21);
			this->lbName->TabIndex = 7;
			// 
			// btnOK
			// 
			this->btnOK->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(78)), static_cast<System::Int32>(static_cast<System::Byte>(79)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->btnOK->FlatAppearance->BorderSize = 0;
			this->btnOK->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnOK->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOK->ForeColor = System::Drawing::Color::White;
			this->btnOK->Location = System::Drawing::Point(50, 385);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(74, 26);
			this->btnOK->TabIndex = 8;
			this->btnOK->Text = L"Sign up";
			this->btnOK->UseVisualStyleBackColor = false;
			this->btnOK->Click += gcnew System::EventHandler(this, &RegisterForm::btnOK_Click);
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->BackColor = System::Drawing::Color::Transparent;
			this->linkLabel1->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->linkLabel1->Location = System::Drawing::Point(229, 465);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(69, 13);
			this->linkLabel1->TabIndex = 11;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Back to login";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &RegisterForm::linkLabel1_LinkClicked);
			// 
			// RegisterForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(856, 533);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->btnOK);
			this->Controls->Add(this->lbName);
			this->Controls->Add(this->lbVerifyPassword);
			this->Controls->Add(this->lbPassword);
			this->Controls->Add(this->lbUser);
			this->Controls->Add(this->nameLabel);
			this->Controls->Add(this->verifyPassLabel);
			this->Controls->Add(this->passLabel);
			this->Controls->Add(this->userLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"RegisterForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
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
	private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		this->switchToLogin = true;
		this->Close();
	}

};
}
