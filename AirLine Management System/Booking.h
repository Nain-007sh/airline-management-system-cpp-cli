#pragma once

namespace AirLineManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Booking
	/// </summary>
	public ref class Booking : public System::Windows::Forms::Form
	{
	public:
		Booking(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Booking()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label3;


	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::ComboBox^ comboBox5;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Booking::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel7->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->panel5);
			this->panel1->Controls->Add(this->panel6);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1177, 109);
			this->panel1->TabIndex = 1;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->button3);
			this->panel4->Location = System::Drawing::Point(711, 3);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(230, 99);
			this->panel4->TabIndex = 3;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(63, 32);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(120, 50);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Passengers";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Booking::button3_Click);
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::Transparent;
			this->panel5->Controls->Add(this->button4);
			this->panel5->Location = System::Drawing::Point(475, 3);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(230, 99);
			this->panel5->TabIndex = 6;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(63, 32);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(120, 50);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Booking";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Booking::button4_Click);
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->button5);
			this->panel6->Location = System::Drawing::Point(947, 0);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(230, 99);
			this->panel6->TabIndex = 5;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(69, 32);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(120, 50);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Contact";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Booking::button5_Click);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->button2);
			this->panel3->Location = System::Drawing::Point(237, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(230, 99);
			this->panel3->TabIndex = 2;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(66, 32);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(120, 50);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Flights";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Booking::button2_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->button1);
			this->panel2->Location = System::Drawing::Point(1, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(230, 99);
			this->panel2->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(62, 32);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 50);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Home";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Booking::button1_Click);
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::Transparent;
			this->panel7->Controls->Add(this->label9);
			this->panel7->Controls->Add(this->label8);
			this->panel7->Controls->Add(this->comboBox5);
			this->panel7->Controls->Add(this->label7);
			this->panel7->Controls->Add(this->button6);
			this->panel7->Controls->Add(this->dateTimePicker1);
			this->panel7->Controls->Add(this->label6);
			this->panel7->Controls->Add(this->comboBox4);
			this->panel7->Controls->Add(this->label5);
			this->panel7->Controls->Add(this->comboBox3);
			this->panel7->Controls->Add(this->label4);
			this->panel7->Controls->Add(this->comboBox2);
			this->panel7->Controls->Add(this->label3);
			this->panel7->Controls->Add(this->comboBox1);
			this->panel7->Controls->Add(this->label2);
			this->panel7->Controls->Add(this->label1);
			this->panel7->Location = System::Drawing::Point(20, 128);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(555, 678);
			this->panel7->TabIndex = 2;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Bold));
			this->label9->Location = System::Drawing::Point(163, 539);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(74, 31);
			this->label9->TabIndex = 15;
			this->label9->Text = L"6000";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Bold));
			this->label8->Location = System::Drawing::Point(37, 539);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(80, 31);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Price:";
			// 
			// comboBox5
			// 
			this->comboBox5->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Location = System::Drawing::Point(169, 393);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(364, 44);
			this->comboBox5->TabIndex = 13;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Bold));
			this->label7->Location = System::Drawing::Point(28, 400);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(56, 31);
			this->label7->TabIndex = 12;
			this->label7->Text = L"TO:";
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10, System::Drawing::FontStyle::Bold));
			this->button6->Location = System::Drawing::Point(169, 611);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(229, 50);
			this->button6->TabIndex = 11;
			this->button6->Text = L"Confirm Booking";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Booking::button6_Click);
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(169, 472);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 26);
			this->dateTimePicker1->TabIndex = 10;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Bold));
			this->label6->Location = System::Drawing::Point(28, 468);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(78, 31);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Date:";
			// 
			// comboBox4
			// 
			this->comboBox4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Location = System::Drawing::Point(169, 319);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(364, 44);
			this->comboBox4->TabIndex = 8;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Bold));
			this->label5->Location = System::Drawing::Point(28, 326);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(96, 31);
			this->label5->TabIndex = 7;
			this->label5->Text = L"FROM:";
			// 
			// comboBox3
			// 
			this->comboBox3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(169, 236);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(364, 44);
			this->comboBox3->TabIndex = 6;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &Booking::comboBox1_SelectedIndexChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Bold));
			this->label4->Location = System::Drawing::Point(28, 243);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(116, 31);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Seat No:";
			// 
			// comboBox2
			// 
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(169, 150);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(364, 44);
			this->comboBox2->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Bold));
			this->label3->Location = System::Drawing::Point(28, 157);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(145, 31);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Passenger:";
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(169, 62);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(364, 44);
			this->comboBox1->TabIndex = 2;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Booking::comboBox1_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(28, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(90, 31);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Flight:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 16, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(107, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(152, 42);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Booking";
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::Transparent;
			this->panel8->Location = System::Drawing::Point(590, 128);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(587, 710);
			this->panel8->TabIndex = 3;
			this->panel8->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Booking::panel8_Paint);
			// 
			// Booking
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1178, 844);
			this->Controls->Add(this->panel8);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->panel1);
			this->Name = L"Booking";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Booking";
			this->Load += gcnew System::EventHandler(this, &Booking::Booking_Load);
			this->panel1->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private:
	void EnsureBookingsGrid();
	void LoadFlights();
	void LoadCustomers();
	void LoadSeatNumbers();
	void LoadBookingsGrid();
	double GetSelectedFlightPrice();
	void ShowSelectedFlightRoute();

private:
	System::Windows::Forms::DataGridView^ bookingsGrid;



	System::Void Booking_Load(System::Object^ sender, System::EventArgs^ e);
	System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	System::Void dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	System::Void button6_Click(System::Object^ sender, System::EventArgs^ e);

	System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void panel8_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);


};
}
