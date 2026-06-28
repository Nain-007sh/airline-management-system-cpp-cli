#pragma once

namespace AirLineManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Dashboard
	/// </summary>
	public ref class Dashboard : public System::Windows::Forms::Form
	{
	public:
		Dashboard(void)
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
		~Dashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Panel^ panel11;
	private: System::Windows::Forms::Panel^ panel10;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Dashboard::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel11->SuspendLayout();
			this->panel10->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel8->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->panel5);
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->panel6);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1177, 109);
			this->panel1->TabIndex = 2;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::Transparent;
			this->panel5->Controls->Add(this->button4);
			this->panel5->Location = System::Drawing::Point(473, 0);
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
			this->button4->Click += gcnew System::EventHandler(this, &Dashboard::button4_Click);
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->button3);
			this->panel4->Location = System::Drawing::Point(711, 0);
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
			this->button3->Click += gcnew System::EventHandler(this, &Dashboard::button3_Click);
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
			this->button5->Click += gcnew System::EventHandler(this, &Dashboard::button5_Click);
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
			this->button2->Click += gcnew System::EventHandler(this, &Dashboard::button2_Click);
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
			this->button1->Click += gcnew System::EventHandler(this, &Dashboard::button1_Click);
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::Transparent;
			this->panel7->Controls->Add(this->panel11);
			this->panel7->Controls->Add(this->panel10);
			this->panel7->Controls->Add(this->panel9);
			this->panel7->Controls->Add(this->panel8);
			this->panel7->Location = System::Drawing::Point(0, 115);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(1177, 728);
			this->panel7->TabIndex = 3;
			// 
			// panel11
			// 
			this->panel11->BackColor = System::Drawing::Color::Lime;
			this->panel11->Controls->Add(this->label7);
			this->panel11->Controls->Add(this->label8);
			this->panel11->Location = System::Drawing::Point(895, 353);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(225, 117);
			this->panel11->TabIndex = 2;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 16, System::Drawing::FontStyle::Bold));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(45, 56);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(38, 42);
			this->label7->TabIndex = 7;
			this->label7->Text = L"0";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 16, System::Drawing::FontStyle::Bold));
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(56, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(129, 42);
			this->label8->TabIndex = 6;
			this->label8->Text = L"Earned";
			// 
			// panel10
			// 
			this->panel10->BackColor = System::Drawing::Color::Cyan;
			this->panel10->Controls->Add(this->label5);
			this->panel10->Controls->Add(this->label6);
			this->panel10->Location = System::Drawing::Point(369, 353);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(225, 117);
			this->panel10->TabIndex = 2;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 16, System::Drawing::FontStyle::Bold));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(88, 56);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(38, 42);
			this->label5->TabIndex = 5;
			this->label5->Text = L"0";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 16, System::Drawing::FontStyle::Bold));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(36, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(168, 42);
			this->label6->TabIndex = 4;
			this->label6->Text = L"Bookings";
			// 
			// panel9
			// 
			this->panel9->BackColor = System::Drawing::Color::Gold;
			this->panel9->Controls->Add(this->label3);
			this->panel9->Controls->Add(this->label4);
			this->panel9->Location = System::Drawing::Point(601, 115);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(225, 117);
			this->panel9->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 16, System::Drawing::FontStyle::Bold));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(91, 56);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 42);
			this->label3->TabIndex = 3;
			this->label3->Text = L"0";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 16, System::Drawing::FontStyle::Bold));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(14, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(199, 42);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Passengers";
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::Red;
			this->panel8->Controls->Add(this->label2);
			this->panel8->Controls->Add(this->label1);
			this->panel8->Location = System::Drawing::Point(127, 115);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(225, 117);
			this->panel8->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 16, System::Drawing::FontStyle::Bold));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(83, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 42);
			this->label2->TabIndex = 1;
			this->label2->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 16, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(46, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(125, 42);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Flights";
			// 
			// Dashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1178, 844);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->panel1);
			this->Name = L"Dashboard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dashboard";
			this->Load += gcnew System::EventHandler(this, &Dashboard::Dashboard_Load);
			this->panel1->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->panel11->ResumeLayout(false);
			this->panel11->PerformLayout();
			this->panel10->ResumeLayout(false);
			this->panel10->PerformLayout();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		private:
			bool IsAdminOrStaff();
			void LoadDashboardStats();

			System::Void Dashboard_Load(System::Object^ sender, System::EventArgs^ e);

			System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);


	};
}
