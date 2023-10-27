#pragma once

namespace MyRestaurantProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for AdminForm
	/// </summary>
	public ref class AdminForm : public System::Windows::Forms::Form
	{
	public:
		AdminForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			this->CenterToScreen();
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ tbUsername;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnDelete;


	private: System::Windows::Forms::Button^ btnSignOut;

	private: System::Windows::Forms::Label^ label4;


	private: System::Windows::Forms::ComboBox^ cbDay;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::ComboBox^ cbRoom;
	private: System::Windows::Forms::Button^ btnView;
	private: System::Windows::Forms::ListBox^ listView1;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminForm::typeid));
			this->tbUsername = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnSignOut = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->cbDay = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->cbRoom = (gcnew System::Windows::Forms::ComboBox());
			this->btnView = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// tbUsername
			// 
			this->tbUsername->Location = System::Drawing::Point(295, 384);
			this->tbUsername->Name = L"tbUsername";
			this->tbUsername->Size = System::Drawing::Size(277, 20);
			this->tbUsername->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(179, 379);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Username";
			// 
			// btnDelete
			// 
			this->btnDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->btnDelete->Location = System::Drawing::Point(578, 379);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(46, 25);
			this->btnDelete->TabIndex = 2;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &AdminForm::btnDelete_Click);
			// 
			// btnSignOut
			// 
			this->btnSignOut->BackColor = System::Drawing::Color::Transparent;
			this->btnSignOut->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSignOut.BackgroundImage")));
			this->btnSignOut->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSignOut->FlatAppearance->BorderSize = 0;
			this->btnSignOut->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSignOut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSignOut->Location = System::Drawing::Point(22, 394);
			this->btnSignOut->Name = L"btnSignOut";
			this->btnSignOut->Size = System::Drawing::Size(74, 15);
			this->btnSignOut->TabIndex = 4;
			this->btnSignOut->UseVisualStyleBackColor = false;
			this->btnSignOut->Click += gcnew System::EventHandler(this, &AdminForm::button2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(179, 341);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(155, 25);
			this->label4->TabIndex = 7;
			this->label4->Text = L"User Deletion";
			// 
			// cbDay
			// 
			this->cbDay->FormattingEnabled = true;
			this->cbDay->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Monday", L"Tuesday", L"Thursday", L"Friday", L"Saturday",
					L"Sunday"
			});
			this->cbDay->Location = System::Drawing::Point(184, 191);
			this->cbDay->Name = L"cbDay";
			this->cbDay->Size = System::Drawing::Size(121, 21);
			this->cbDay->TabIndex = 9;
			this->cbDay->SelectedIndexChanged += gcnew System::EventHandler(this, &AdminForm::cbDay_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(203, 267);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 29);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Delete";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AdminForm::button1_Click);
			// 
			// cbRoom
			// 
			this->cbRoom->FormattingEnabled = true;
			this->cbRoom->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"N201", L"N202", L"N203", L"N204", L"N205" });
			this->cbRoom->Location = System::Drawing::Point(184, 164);
			this->cbRoom->Name = L"cbRoom";
			this->cbRoom->Size = System::Drawing::Size(121, 21);
			this->cbRoom->TabIndex = 12;
			this->cbRoom->SelectedIndexChanged += gcnew System::EventHandler(this, &AdminForm::cbRoom_SelectedIndexChanged);
			// 
			// btnView
			// 
			this->btnView->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnView->Location = System::Drawing::Point(203, 224);
			this->btnView->Name = L"btnView";
			this->btnView->Size = System::Drawing::Size(86, 29);
			this->btnView->TabIndex = 13;
			this->btnView->Text = L"View";
			this->btnView->UseVisualStyleBackColor = true;
			this->btnView->Click += gcnew System::EventHandler(this, &AdminForm::btnView_Click);
			// 
			// listView1
			// 
			this->listView1->FormattingEnabled = true;
			this->listView1->Location = System::Drawing::Point(332, 100);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(292, 225);
			this->listView1->TabIndex = 14;
			// 
			// AdminForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(644, 442);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->btnView);
			this->Controls->Add(this->cbRoom);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->cbDay);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->btnSignOut);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tbUsername);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"AdminForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AdminForm";
			this->Load += gcnew System::EventHandler(this, &AdminForm::AdminForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
		   /*private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
			   String^ usernameToDelete = tbUsername->Text;

			   if (usernameToDelete->Length == 0) {
				   MessageBox::Show("Please fill in a username!", "Username error", MessageBoxButtons::OK);
				   return;
			   }

			   try {
				   String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=myrestaurant;Integrated Security=True";
				   SqlConnection sqlConn(connString);
				   sqlConn.Open();

			   //	String^ sqlQuery = "SELECT * FROM users WHERE username=@username;";
			   //	SqlCommand command(sqlQuery, % sqlConn);
			   //	command.Parameters->AddWithValue("@username", usernameToDelete);

			   //	SqlDataReader^ reader = command.ExecuteReader();

					   String^ delQuery = "DELETE from users WHERE username='rommel123';";
					   SqlCommand command(delQuery, % sqlConn);
					   command.BeginExecuteNonQuery();
					   this->Close();

			   }
			   catch (Exception^ e) {
				   MessageBox::Show("Failed to connect to database", "Database Connection Error", MessageBoxButtons::OK);
			   }

		   }
		   */
	private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ usernameToDelete = tbUsername->Text;
		
		array<String^>^ dayArray = gcnew array<String^> {
			"Monday",
				"Tuesday",
				"Wednesday",
				"Thursday",
				"Friday",
				"Saturday",
				"Sunday"
		};

		if (usernameToDelete->Length == 0) {
			MessageBox::Show("Please fill in a username!", "Username error", MessageBoxButtons::OK);
			return;
		}

		if (usernameToDelete == "root") {
			MessageBox::Show("Cannot delete admin user!", "Username error", MessageBoxButtons::OK);
			return;
		}

		try {
			String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=myrestaurant;Integrated Security=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			// Step 1: Delete user from users table
			String^ delUserQuery = "DELETE from users WHERE username=@username";
			SqlCommand command(delUserQuery, % sqlConn);
			command.Parameters->AddWithValue("@username", usernameToDelete);

			int userRowsAffected = command.ExecuteNonQuery();

			// Step 2: Delete records from the selectedDay column in the database
			if (userRowsAffected > 0) {
				for (int i = 0; i < 7; i++) {
					String^ delRecordsQuery = "DELETE from N201 WHERE " + dayArray[i] + " = @username";
					SqlCommand recordsCommand(delRecordsQuery, % sqlConn);
					recordsCommand.Parameters->AddWithValue("@username", usernameToDelete);

					int recordsRowsAffected = recordsCommand.ExecuteNonQuery();

					if (recordsRowsAffected > 0) {
						MessageBox::Show("User and related records deleted successfully.", "Success", MessageBoxButtons::OK);
					}
				}
			}
			else {
				MessageBox::Show("User not found or deletion failed.", "Error", MessageBoxButtons::OK);
			}

			this->Close();

		}
		catch (Exception^ ex) {
			MessageBox::Show("Failed to connect to the database: " + ex->Message, "Database Connection Error", MessageBoxButtons::OK);
		}
	}

	int timeWindowToIndex(String^ input) {
		array<String^>^ timeArray = gcnew array<String^> {
			"7:30AM-9:00AM", "9:00AM-10:30AM", "10:30AM-12:00PM",
				"12:00PM-1:30PM", "1:30PM-3:00PM", "3:00PM-4:30PM",
				"4:30PM-6:00PM", "6:00PM-7:30PM", "7:30PM-9:00PM"
		};

		for (int i = 0; i < 9; i++) {
			if (input == timeArray[i]) {
				return i;
			}
		}
	}


	private: System::Void RefreshReservations(String^ selectedRoom, String^ selectedDay) {
		listView1->Items->Clear();

		array<String^>^ timeArray = gcnew array<String^> {
			"7:30AM-9:00AM", "9:00AM-10:30AM", "10:30AM-12:00PM",
				"12:00PM-1:30PM", "1:30PM-3:00PM", "3:00PM-4:30PM",
				"4:30PM-6:00PM", "6:00PM-7:30PM", "7:30PM-9:00PM"
		};


		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=myrestaurant;Integrated Security=True";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);

		try {
			sqlConn->Open();

			for (int i = 0; i < 9; i++) {
				String^ sqlQuery = "SELECT * FROM " + selectedRoom + " WHERE " + selectedDay + " != @none AND timeIndex = @selectedTime;";
				SqlCommand^ command = gcnew SqlCommand(sqlQuery, sqlConn);
				command->Parameters->AddWithValue("@none", "NONE");
				command->Parameters->AddWithValue("@selectedTime", timeWindowToIndex(timeArray[i]) + 1);

				SqlDataReader^ reader = command->ExecuteReader();
				if (reader->Read()) {
					listView1->Items->Add(timeArray[i]);
				}
				

				reader->Close();
			}
		}
		catch (SqlException^ ex) {

		}
		finally {
			sqlConn->Close();
		}
	}

	public: bool isFirstOpen = true;

	private: System::Void cbDay_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	
	}




	private: System::Void AdminForm_Load(System::Object^ sender, System::EventArgs^ e) {
		cbDay->SelectedIndex = 0;
		cbRoom->SelectedIndex = 0;

		String^ currentDay = cbDay->Text;
		String^ currentRoom = cbRoom->Text;
		RefreshReservations(currentRoom, currentDay);
	}
	private: System::Void cbRoom_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void btnView_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ currentDay = cbDay->Text;
		String^ currentRoom = cbRoom->Text;

		RefreshReservations(currentRoom, currentDay);

		// Build the SQL query to select reservations where the entry is not "NONE"
		String^ sqlQuery = "SELECT timeIndex, " + currentDay + " FROM " + currentRoom + " WHERE " + currentDay + " != 'NONE';";

		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=myrestaurant;Integrated Security=True";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);

		try {
			sqlConn->Open();

			SqlCommand^ command = gcnew SqlCommand(sqlQuery, sqlConn);
			SqlDataReader^ reader = command->ExecuteReader();

			String^ reservationsInfo = "Reservations for " + currentRoom + " on " + currentDay + ":\n";

			while (reader->Read()) {
				int timeIndex = reader->GetInt32(0); // Get the timeIndex
				String^ reservation = reader[currentDay]->ToString(); // Get the reservation entry

				// Append reservation data and username (assuming username is stored in the entry)
				reservationsInfo += "Time Slot: " + timeIndex + ", Reservation: " + reservation + "\n";
			}

			reader->Close();

			// Display the reservation information in a message box
			MessageBox::Show(reservationsInfo, "Reservations", MessageBoxButtons::OK);
		}
		catch (SqlException^ ex) {
			MessageBox::Show("SQL Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		finally {
			sqlConn->Close();
		}
	}
	private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (listView1->SelectedIndex == -1) {
			// No room or reservation is selected, handle this case
			return;
		}

		String^ selectedDay = cbDay->SelectedItem->ToString();
		String^ selectedRoom = cbRoom->SelectedItem->ToString();
		String^ selectedTime = listView1->SelectedItem->ToString();

		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=myrestaurant;Integrated Security=True";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);

		try {
			sqlConn->Open();

			// Build the SQL query to update the database entry
			String^ sqlQuery = "UPDATE " + selectedRoom + " SET " + selectedDay + " = @none WHERE timeIndex = @selectedTime;";
			SqlCommand^ command = gcnew SqlCommand(sqlQuery, sqlConn);
			command->Parameters->AddWithValue("@none", "NONE");
			command->Parameters->AddWithValue("@selectedTime", timeWindowToIndex(selectedTime) + 1);

			// Execute the SQL command to update the database
			int rowsAffected = command->ExecuteNonQuery();

			if (rowsAffected > 0) {
				// Reservation was successfully canceled
				MessageBox::Show("Reservation canceled for " + selectedTime, "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				listView1->Items->Remove(selectedTime);
				RefreshReservations(selectedRoom, selectedDay);
			}
			else {
				// No reservation found for the selected time or other error occurred
				MessageBox::Show("Failed to cancel the reservation.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (SqlException^ ex) {
			MessageBox::Show("SQL Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		finally {
			sqlConn->Close();
		}
	}
	};
};


