#pragma once

namespace AirLineManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Passengers
	/// </summary>
	public ref class Passengers : public System::Windows::Forms::Form
	{
	public:
		Passengers(void)
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
		~Passengers()
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Passengers::typeid));
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
			this->panel1->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
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
			this->panel5->Location = System::Drawing::Point(709, 0);
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
			this->button4->Click += gcnew System::EventHandler(this, &Passengers::button4_Click);
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->button3);
			this->panel4->Location = System::Drawing::Point(473, 0);
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
			this->button3->Click += gcnew System::EventHandler(this, &Passengers::button3_Click);
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
			this->button5->Click += gcnew System::EventHandler(this, &Passengers::button5_Click);
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
			this->button2->Click += gcnew System::EventHandler(this, &Passengers::button2_Click);
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
			this->button1->Click += gcnew System::EventHandler(this, &Passengers::button1_Click);
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::Transparent;
			this->panel7->Location = System::Drawing::Point(0, 115);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(1177, 729);
			this->panel7->TabIndex = 3;
			// 
			// Passengers
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1178, 844);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->panel1);
			this->Name = L"Passengers";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Passengers";
			this->Load += gcnew System::EventHandler(this, &Passengers::Passengers_Load);
			this->panel1->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		private:
			System::Windows::Forms::DataGridView^ dgv;
			void LoadPassengers();

			System::Void Passengers_Load(System::Object^ sender, System::EventArgs^ e);

			System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);

	};
}
