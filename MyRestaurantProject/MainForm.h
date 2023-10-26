#pragma once
#include "User.h"
#include <tuple>
#include <vcclr.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <list>


namespace MyRestaurantProject {

	using namespace System;            // Include the System namespace
	using namespace System::Data;      // Include System::Data for ADO.NET
	using namespace System::Data::SqlClient;  // Include SqlClient for SQL Server database access
	using namespace System::Collections::Generic;  // Include Collections for generic collections
	using namespace System::Windows::Forms;  // Include Windows::Forms for Windows Forms GUI

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	/// 
	/// 
	/// 
	/// 
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		array<String^>^ timeWindow = gcnew array<String^>(9);
		MainForm(User^ user)
		{
			InitializeComponent();
			welcomeLabel->Text = "Welcome " + user->name;
			this->CenterToScreen();

			timeWindow[0] = "7:30AM-9:00AM";
			timeWindow[1] = "9:00AM-10:30AM";
			timeWindow[2] = "10:30AM-12:00NN";
			timeWindow[3] = "12:00NN-1:30PM";
			timeWindow[4] = "1:30PM-3:00PM";
			timeWindow[5] = "3:00PM-4:30PM";
			timeWindow[6] = "4:30PM-6:00PM";
			timeWindow[7] = "6:00PM-7:30PM";
			timeWindow[8] = "7:30PM-9:00PM";

			currentUser = user->username;
		}

		int timeWindowToIndex(String^ input) {
			for (int i = 0; i < 9; i++) {
				if (input == timeWindow[i]) {
					return i;
				}
			}
		}
	private: System::Windows::Forms::Button^ getReservations;
	private: System::Windows::Forms::Button^ getReservation;
	public:

		String^ currentUser;


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ welcomeLabel;
	private: System::Windows::Forms::ListBox^ listView;

	private: System::Windows::Forms::Button^ btnSignOut;
	private: System::Windows::Forms::Label^ selectLabel;

	private: static int CompareRoomVacancies(Tuple<String^, int>^ a, Tuple<String^, int>^ b) {
		return b->Item2 - a->Item2; // Reverse the order for descending
	}

	private: System::Void RefreshReservations(String^ selectedRoom, String^ selectedDay) {
		reservationView->Items->Clear();
		reservedView->Items->Clear();

		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=myrestaurant;Integrated Security=True";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);

		try {
			sqlConn->Open();

			for (int i = 0; i < timeWindow->Length; i++) {
				String^ sqlQuery = "SELECT * FROM " + selectedRoom + " WHERE " + selectedDay + " != @none AND timeIndex = @selectedTime;";
				SqlCommand^ command = gcnew SqlCommand(sqlQuery, sqlConn);
				command->Parameters->AddWithValue("@none", "NONE");
				command->Parameters->AddWithValue("@selectedTime", timeWindowToIndex(timeWindow[i]) + 1);

				SqlDataReader^ reader = command->ExecuteReader();
				if (!reader->Read()) {
					reservationView->Items->Add(timeWindow[i]);
				}
				else if (currentUser == reader[selectedDay]->ToString()) {
					reservedView->Items->Add(timeWindow[i]);
				}

				reader->Close();
			}
		}
		catch (SqlException^ ex) {
			MessageBox::Show("SQL Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		finally {
			sqlConn->Close();
		}
	}



	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ListBox^ reservationView;
	private: System::Windows::Forms::ListBox^ reservedView;





	private: System::Windows::Forms::Button^ btnSuggest;



	private: System::Windows::Forms::Button^ btnReserve;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::ComboBox^ cbDay;
	private: System::Windows::Forms::Label^ label1;




	protected:

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
			this->welcomeLabel = (gcnew System::Windows::Forms::Label());
			this->listView = (gcnew System::Windows::Forms::ListBox());
			this->btnSignOut = (gcnew System::Windows::Forms::Button());
			this->selectLabel = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->reservationView = (gcnew System::Windows::Forms::ListBox());
			this->reservedView = (gcnew System::Windows::Forms::ListBox());
			this->btnSuggest = (gcnew System::Windows::Forms::Button());
			this->btnReserve = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->cbDay = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->getReservation = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// welcomeLabel
			// 
			this->welcomeLabel->AutoSize = true;
			this->welcomeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->welcomeLabel->Location = System::Drawing::Point(12, 9);
			this->welcomeLabel->Name = L"welcomeLabel";
			this->welcomeLabel->Size = System::Drawing::Size(171, 29);
			this->welcomeLabel->TabIndex = 0;
			this->welcomeLabel->Text = L"welcomeLabel";
			// 
			// listView
			// 
			this->listView->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listView->FormattingEnabled = true;
			this->listView->ItemHeight = 24;
			this->listView->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"N201", L"N202", L"N203", L"N204", L"N205" });
			this->listView->Location = System::Drawing::Point(21, 130);
			this->listView->Name = L"listView";
			this->listView->Size = System::Drawing::Size(133, 268);
			this->listView->TabIndex = 1;
			this->listView->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::listView_SelectedIndexChanged);
			// 
			// btnSignOut
			// 
			this->btnSignOut->BackColor = System::Drawing::Color::RosyBrown;
			this->btnSignOut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSignOut->Location = System::Drawing::Point(517, 12);
			this->btnSignOut->Name = L"btnSignOut";
			this->btnSignOut->Size = System::Drawing::Size(113, 36);
			this->btnSignOut->TabIndex = 2;
			this->btnSignOut->Text = L"Sign out";
			this->btnSignOut->UseVisualStyleBackColor = false;
			this->btnSignOut->Click += gcnew System::EventHandler(this, &MainForm::btnSignOut_Click);
			// 
			// selectLabel
			// 
			this->selectLabel->AutoSize = true;
			this->selectLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->selectLabel->Location = System::Drawing::Point(16, 74);
			this->selectLabel->Name = L"selectLabel";
			this->selectLabel->Size = System::Drawing::Size(77, 29);
			this->selectLabel->TabIndex = 3;
			this->selectLabel->Text = L"select";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(200, 97);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(144, 29);
			this->label2->TabIndex = 9;
			this->label2->Text = L"reservations";
			// 
			// reservationView
			// 
			this->reservationView->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->reservationView->FormattingEnabled = true;
			this->reservationView->ItemHeight = 24;
			this->reservationView->Location = System::Drawing::Point(205, 130);
			this->reservationView->MultiColumn = true;
			this->reservationView->Name = L"reservationView";
			this->reservationView->Size = System::Drawing::Size(187, 268);
			this->reservationView->TabIndex = 10;
			// 
			// reservedView
			// 
			this->reservedView->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->reservedView->FormattingEnabled = true;
			this->reservedView->ItemHeight = 24;
			this->reservedView->Location = System::Drawing::Point(440, 130);
			this->reservedView->Name = L"reservedView";
			this->reservedView->Size = System::Drawing::Size(187, 268);
			this->reservedView->TabIndex = 12;
			// 
			// btnSuggest
			// 
			this->btnSuggest->Location = System::Drawing::Point(21, 404);
			this->btnSuggest->Name = L"btnSuggest";
			this->btnSuggest->Size = System::Drawing::Size(75, 23);
			this->btnSuggest->TabIndex = 13;
			this->btnSuggest->Text = L"Suggest";
			this->btnSuggest->UseVisualStyleBackColor = true;
			this->btnSuggest->Click += gcnew System::EventHandler(this, &MainForm::btnSuggest_Click);
			// 
			// btnReserve
			// 
			this->btnReserve->Location = System::Drawing::Point(205, 404);
			this->btnReserve->Name = L"btnReserve";
			this->btnReserve->Size = System::Drawing::Size(75, 23);
			this->btnReserve->TabIndex = 15;
			this->btnReserve->Text = L"Reserve";
			this->btnReserve->UseVisualStyleBackColor = true;
			this->btnReserve->Click += gcnew System::EventHandler(this, &MainForm::btnReserve_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Location = System::Drawing::Point(440, 404);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(75, 23);
			this->btnDelete->TabIndex = 16;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &MainForm::btnDelete_Click);
			// 
			// cbDay
			// 
			this->cbDay->FormattingEnabled = true;
			this->cbDay->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Monday", L"Tuesday", L"Wednesday", L"Thursday", L"Friday",
					L"Saturday", L"Sunday"
			});
			this->cbDay->Location = System::Drawing::Point(21, 106);
			this->cbDay->Name = L"cbDay";
			this->cbDay->Size = System::Drawing::Size(121, 21);
			this->cbDay->TabIndex = 17;
			this->cbDay->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::cbDay_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(435, 97);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(108, 29);
			this->label1->TabIndex = 18;
			this->label1->Text = L"reserved";
			// 
			// getReservation
			// 
			this->getReservation->BackColor = System::Drawing::Color::MistyRose;
			this->getReservation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->getReservation->Location = System::Drawing::Point(517, 58);
			this->getReservation->Name = L"getReservation";
			this->getReservation->Size = System::Drawing::Size(113, 36);
			this->getReservation->TabIndex = 19;
			this->getReservation->Text = L"Reservations";
			this->getReservation->UseVisualStyleBackColor = false;
			this->getReservation->Click += gcnew System::EventHandler(this, &MainForm::getReservation_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(642, 467);
			this->Controls->Add(this->getReservation);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cbDay);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnReserve);
			this->Controls->Add(this->btnSuggest);
			this->Controls->Add(this->reservedView);
			this->Controls->Add(this->reservationView);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->selectLabel);
			this->Controls->Add(this->btnSignOut);
			this->Controls->Add(this->listView);
			this->Controls->Add(this->welcomeLabel);
			this->Name = L"MainForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnSignOut_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	public: bool onFirstRun = true;


	private: System::Void listView_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		reservationView->Items->Clear();
		reservedView->Items->Clear();

		String^ selectedDay = cbDay->SelectedItem->ToString();
		String^ selectedRoom = listView->SelectedItem->ToString();

		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=myrestaurant;Integrated Security=True";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);

		try {
			sqlConn->Open();

			RefreshReservations(selectedRoom, selectedDay);
		}
		catch (SqlException^ ex) {
			MessageBox::Show("SQL Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		finally {
			sqlConn->Close();
		}
	}

	private: System::Void btnReserve_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ selectedDay = cbDay->SelectedItem->ToString();
		String^ selectedRoom = listView->SelectedItem->ToString();
		String^ selectedTime = reservationView->SelectedItem->ToString();

		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=myrestaurant;Integrated Security=True";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);

		try {
			sqlConn->Open();

			// Build the SQL query to update the database entry
			String^ sqlQuery = "UPDATE " + selectedRoom + " SET " + selectedDay + " = @username WHERE timeIndex = @selectedTime;";
			SqlCommand^ command = gcnew SqlCommand(sqlQuery, sqlConn);
			command->Parameters->AddWithValue("@username", currentUser);
			command->Parameters->AddWithValue("@selectedTime", timeWindowToIndex(selectedTime) + 1);

			int rowsAffected = command->ExecuteNonQuery();

			MessageBox::Show("Reservation for " + currentUser + " success!", "Success", MessageBoxButtons::OK);

			RefreshReservations(selectedRoom, selectedDay);
		}
		catch (SqlException^ ex) {
			MessageBox::Show("SQL Error", "Database error", MessageBoxButtons::OK);
		}
	}
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		cbDay->SelectedIndex = 0;
	}

	private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		if (listView->SelectedIndex == -1 || reservedView->SelectedIndex == -1) {
			// No room or reservation is selected, handle this case
			return;
		}

		String^ selectedDay = cbDay->SelectedItem->ToString();
		String^ selectedRoom = listView->SelectedItem->ToString();
		String^ selectedTime = reservedView->SelectedItem->ToString();

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
				reservedView->Items->Remove(selectedTime);
				reservationView->Items->Add(selectedTime);
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
	private: System::Void cbDay_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (onFirstRun) {
			onFirstRun = false;
		}
		else {
			String^ selectedDay = cbDay->SelectedItem->ToString();
			String^ selectedRoom = listView->SelectedItem->ToString();
			RefreshReservations(selectedRoom, selectedDay);
		}
	}

	public: int FindEarliestDay(array<int>^ earliestWindows) {
		int minIndex = -1; // Initialize minIndex with an invalid value
		int minValue = 9;  // Set an initial value greater than any possible index

		for (int i = 0; i < earliestWindows->Length; i++) {
			if (earliestWindows[i] != -1 && earliestWindows[i] < minValue) {
				minIndex = i;
				minValue = earliestWindows[i];
			}
		}

		// minIndex now contains the index of the day with the earliest time window
		return minIndex;
	}

	private: System::Void btnSuggest_Click(System::Object^ sender, System::EventArgs^ e) {
		// Connect to the database
		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=myrestaurant;Integrated Security=True";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);

		try {
			sqlConn->Open();

			int maxVacancies = 0;
			String^ suggestedRoom = "";

			// Define arrays for day names and time slots
			array<String^>^ dayNames = gcnew array<String^> { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
			array<String^>^ timeSlots = gcnew array<String^> {
				"7:30AM-9:00AM", "9:00AM-10:30AM", "10:30AM-12:00PM",
					"12:00PM-1:30PM", "1:30PM-3:00PM", "3:00PM-4:30PM",
					"4:30PM-6:00PM", "6:00PM-7:30PM", "7:30PM-9:00PM"
			};

			for (int roomNumber = 201; roomNumber <= 202; roomNumber++) {
				String^ roomName = "N" + roomNumber.ToString("D3");

				// Initialize the number of vacancies for this room
				int roomVacancies = 0;

				for (int timeIndex = 1; timeIndex <= 9; timeIndex++) {
					for (int dayIndex = 0; dayIndex < 7; dayIndex++) {
						String^ selectedDay = dayNames[dayIndex];

						// Construct the query
						String^ sqlQuery = "SELECT " + selectedDay + " FROM " + roomName + " WHERE timeIndex = " + timeIndex + ";";
						SqlCommand^ command = gcnew SqlCommand(sqlQuery, sqlConn);
						SqlDataReader^ reader = command->ExecuteReader();

						if (reader->Read()) {
							String^ reservationStatus = reader[selectedDay]->ToString();
							if (reservationStatus == "NONE") {
								// Found a vacant time slot
								roomVacancies++;
							}
						}

						reader->Close();
					}
				}

				// If this room has more vacancies, update the suggestion
				if (roomVacancies > maxVacancies) {
					maxVacancies = roomVacancies;
					suggestedRoom = roomName;
				}
			}

			// Display the room with the most vacancies
			if (maxVacancies > 0) {
				String^ suggestionMessage = "Room with the greatest number of vacant reservations:\n";
				suggestionMessage += suggestedRoom + " - " + maxVacancies + " vacancies";
				MessageBox::Show(suggestionMessage, "Suggested Room", MessageBoxButtons::OK);
			}
			else {
				MessageBox::Show("No available reservations found.", "Suggestion", MessageBoxButtons::OK);
			}
		}
		catch (SqlException^ ex) {
			MessageBox::Show("SQL Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		finally {
			sqlConn->Close();
		}
	}


	String^ dayIndexToDay(int dayIndex) {
		switch (dayIndex) {
		case 1:
			return "Monday";
		case 2:
			return "Tuesday";
		case 3:
			return "Wednesday";
		case 4:
			return "Thursday";
		case 5:
			return "Friday";
		case 6:
			return "Saturday";
		case 7:
			return "Sunday";
		default:
			return "";
		}
	}








	String^ GetTimeSlotFromTimeIndex(int timeIndex) {
		// Define time slots corresponding to timeIndex
		array<String^>^ timeslots = gcnew array<String^> {
			"7:30AM-9:00AM", "9:00AM-10:30AM", "10:30AM-12:00PM",
				"12:00PM-1:30PM", "1:30PM-3:00PM", "3:00PM-4:30PM",
				"4:30PM-6:00PM", "6:00PM-7:30PM", "7:30PM-9:00PM"
		};
		return timeslots[timeIndex - 1]; // Retrieve time slot from array
	}






	private: System::Void getReservation_Click(System::Object^ sender, System::EventArgs^ e) {
		// Connect to the database
		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=myrestaurant;Integrated Security=True";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);

		try {
			sqlConn->Open();

			// Create a dictionary to store reservations by day
			Dictionary<String^, String^> reservationsByDay;

			// Days of the week
			array<String^>^ days = gcnew array<String^>{"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

			for each (String ^ day in days) {
				// Initialize the reservations string for the current day
				reservationsByDay[day] = "";

				// Iterate through room tables N201 and N202
				for (int roomNumber = 201; roomNumber <= 202; roomNumber++) {
					String^ roomName = "N" + roomNumber.ToString("D3");

					// Query the database to get the user's reservations for this room and day
					String^ sqlQuery = "SELECT timeIndex FROM " + roomName + " WHERE " + day + " = @userName;";
					SqlCommand^ command = gcnew SqlCommand(sqlQuery, sqlConn);
					command->Parameters->AddWithValue("@userName", currentUser); // Replace with the user's username

					SqlDataReader^ reader = command->ExecuteReader();

					while (reader->Read()) {
						int timeIndex = safe_cast<int>(reader["timeIndex"]);
						String^ time = timeWindow[timeIndex - 1]; // Assuming you have a timeWindow array

						// Append reservation information for the day
						reservationsByDay[day] += roomName + " - " + time + "\n";
					}

					reader->Close();
				}
			}

			// Display the collected reservations information by day
			String^ reservationsMessage = "";
			for each (String ^ day in days) {
				if (!String::IsNullOrEmpty(reservationsByDay[day])) {
					reservationsMessage += "Reservations for " + day + ":\n";
					reservationsMessage += reservationsByDay[day] + "\n\n";
				}
			}

			if (!String::IsNullOrEmpty(reservationsMessage)) {
				MessageBox::Show(reservationsMessage, "Reservations", MessageBoxButtons::OK);
			}
			else {
				MessageBox::Show("No reservations found for the user.", "Reservations", MessageBoxButtons::OK);
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
}