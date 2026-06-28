#pragma once

namespace AirLineManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ContactUs
	/// </summary>
	public ref class ContactUs : public System::Windows::Forms::Form
	{
	public:
		ContactUs(void)
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
		~ContactUs()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Panel^ panel8;

	private: System::Windows::Forms::Label^ label13;

	private: System::Windows::Forms::Label^ label15;

	private: System::Windows::Forms::Label^ label17;

	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button6;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ContactUs::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel8->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->panel6);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Location = System::Drawing::Point(2, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1177, 109);
			this->panel1->TabIndex = 0;
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
			this->button3->Click += gcnew System::EventHandler(this, &ContactUs::button3_Click);
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
			this->button5->Click += gcnew System::EventHandler(this, &ContactUs::button5_Click);
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
			this->button2->Text = L"FLIGHTS";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ContactUs::button2_Click);
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
			this->button1->Text = L"HOME";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ContactUs::button1_Click);
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::Transparent;
			this->panel5->Controls->Add(this->button4);
			this->panel5->Location = System::Drawing::Point(475, 1);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(230, 99);
			this->panel5->TabIndex = 4;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(63, 32);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(120, 50);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Booking";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &ContactUs::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 16, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(39, 130);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(194, 42);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Conatct Us";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(48, 186);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(320, 36);
			this->label2->TabIndex = 6;
			this->label2->Text = L"We are here to help you";
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::Transparent;
			this->panel7->Controls->Add(this->label10);
			this->panel7->Controls->Add(this->label11);
			this->panel7->Controls->Add(this->label8);
			this->panel7->Controls->Add(this->label9);
			this->panel7->Controls->Add(this->label6);
			this->panel7->Controls->Add(this->label7);
			this->panel7->Controls->Add(this->label5);
			this->panel7->Controls->Add(this->label4);
			this->panel7->Controls->Add(this->label3);
			this->panel7->Location = System::Drawing::Point(46, 255);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(322, 411);
			this->panel7->TabIndex = 7;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::Black;
			this->label10->Location = System::Drawing::Point(27, 357);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(261, 27);
			this->label10->TabIndex = 16;
			this->label10->Text = L"Monday-Friday (9AM-6PM)";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::Transparent;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::Black;
			this->label11->Location = System::Drawing::Point(20, 318);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(128, 27);
			this->label11->TabIndex = 15;
			this->label11->Text = L"Office Hour";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Black;
			this->label8->Location = System::Drawing::Point(23, 265);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(196, 27);
			this->label8->TabIndex = 14;
			this->label8->Text = L"support@skyair.com";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Black;
			this->label9->Location = System::Drawing::Point(16, 226);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(114, 27);
			this->label9->TabIndex = 13;
			this->label9->Text = L"Email Info";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(20, 181);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(170, 27);
			this->label6->TabIndex = 12;
			this->label6->Text = L"+92 328 8036625";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Black;
			this->label7->Location = System::Drawing::Point(13, 142);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(123, 27);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Phone Info";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(20, 103);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(222, 27);
			this->label5->TabIndex = 10;
			this->label5->Text = L"SKY AIR, SkyAir Karachi";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(13, 64);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(119, 27);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Office Info";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(12, 17);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(262, 31);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Conatct Information";
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::Transparent;
			this->panel8->Controls->Add(this->button6);
			this->panel8->Controls->Add(this->textBox4);
			this->panel8->Controls->Add(this->textBox3);
			this->panel8->Controls->Add(this->textBox2);
			this->panel8->Controls->Add(this->textBox1);
			this->panel8->Controls->Add(this->label13);
			this->panel8->Controls->Add(this->label15);
			this->panel8->Controls->Add(this->label17);
			this->panel8->Controls->Add(this->label19);
			this->panel8->Controls->Add(this->label20);
			this->panel8->Location = System::Drawing::Point(432, 136);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(734, 530);
			this->panel8->TabIndex = 17;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(342, 453);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(120, 50);
			this->button6->TabIndex = 1;
			this->button6->Text = L"Send";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &ContactUs::button6_Click);
			// 
			// textBox4
			// 
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(142, 357);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(532, 44);
			this->textBox4->TabIndex = 19;
			// 
			// textBox3
			// 
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(142, 261);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(532, 44);
			this->textBox3->TabIndex = 18;
			// 
			// textBox2
			// 
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(142, 183);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(532, 44);
			this->textBox2->TabIndex = 17;
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(142, 95);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(532, 44);
			this->textBox1->TabIndex = 16;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::Transparent;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::Black;
			this->label13->Location = System::Drawing::Point(20, 318);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(102, 27);
			this->label13->TabIndex = 15;
			this->label13->Text = L"Message";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->BackColor = System::Drawing::Color::Transparent;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->ForeColor = System::Drawing::Color::Black;
			this->label15->Location = System::Drawing::Point(16, 226);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(67, 27);
			this->label15->TabIndex = 13;
			this->label15->Text = L"Email";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->BackColor = System::Drawing::Color::Transparent;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->ForeColor = System::Drawing::Color::Black;
			this->label17->Location = System::Drawing::Point(13, 142);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(86, 27);
			this->label17->TabIndex = 11;
			this->label17->Text = L"Subject";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->BackColor = System::Drawing::Color::Transparent;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->ForeColor = System::Drawing::Color::Black;
			this->label19->Location = System::Drawing::Point(13, 64);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(73, 27);
			this->label19->TabIndex = 9;
			this->label19->Text = L"Name";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->BackColor = System::Drawing::Color::Transparent;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->ForeColor = System::Drawing::Color::Black;
			this->label20->Location = System::Drawing::Point(12, 17);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(253, 31);
			this->label20->TabIndex = 8;
			this->label20->Text = L"Send Message Here";
			// 
			// ContactUs
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1178, 844);
			this->Controls->Add(this->panel8);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Name = L"ContactUs";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ContactUs";
			this->Load += gcnew System::EventHandler(this, &ContactUs::ContactUs_Load);
			this->panel1->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private:
	System::Void ContactUs_Load(System::Object^ sender, System::EventArgs^ e);

	System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);

	// 🔴 THIS WAS MISSING (MAIN ERROR)
	System::Void button6_Click(System::Object^ sender, System::EventArgs^ e);

};
}
