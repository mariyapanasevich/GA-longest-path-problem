#pragma once
#include "GA.h"
#include <string>
#include <msclr\marshal_cppstd.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <Windows.h>
#include <SQLAPI.h>

using namespace std;
using namespace msclr::interop;

namespace form1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			textBox5->Enabled = false;
			InitializeTrackBar();
			InitializeTrackBar2();
		}


	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ðåñóðñû.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  windowToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  clearToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  canselToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newWindowToolStripMenuItem;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TrackBar^  trackBar2;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;


	private:
		/// <summary>
		/// Òðåáóåòñÿ ïåðåìåííàÿ êîíñòðóêòîðà.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Îáÿçàòåëüíûé ìåòîä äëÿ ïîääåðæêè êîíñòðóêòîðà - íå èçìåíÿéòå
		/// ñîäåðæèìîå äàííîãî ìåòîäà ïðè ïîìîùè ðåäàêòîðà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->windowToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newWindowToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->canselToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Input number vertex:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Input number edge:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 108);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(148, 377);
			this->dataGridView1->TabIndex = 2;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(119, 34);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(41, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(119, 60);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(41, 20);
			this->textBox2->TabIndex = 4;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->windowToolStripMenuItem,
					this->fileToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(692, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MyForm::menuStrip1_ItemClicked);
			// 
			// windowToolStripMenuItem
			// 
			this->windowToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->newWindowToolStripMenuItem,
					this->clearToolStripMenuItem, this->canselToolStripMenuItem
			});
			this->windowToolStripMenuItem->Name = L"windowToolStripMenuItem";
			this->windowToolStripMenuItem->Size = System::Drawing::Size(63, 20);
			this->windowToolStripMenuItem->Text = L"Window";
			// 
			// newWindowToolStripMenuItem
			// 
			this->newWindowToolStripMenuItem->Name = L"newWindowToolStripMenuItem";
			this->newWindowToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->newWindowToolStripMenuItem->Text = L"New window";
			this->newWindowToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::newWindowToolStripMenuItem_Click);
			// 
			// clearToolStripMenuItem
			// 
			this->clearToolStripMenuItem->Name = L"clearToolStripMenuItem";
			this->clearToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->clearToolStripMenuItem->Text = L"Clear";
			this->clearToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::clearToolStripMenuItem_Click);
			// 
			// canselToolStripMenuItem
			// 
			this->canselToolStripMenuItem->Name = L"canselToolStripMenuItem";
			this->canselToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->canselToolStripMenuItem->Text = L"Cansel";
			this->canselToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::canselToolStripMenuItem_Click);
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openToolStripMenuItem,
					this->saveToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveToolStripMenuItem_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(204, 41);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(107, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Input size population:";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(343, 38);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(41, 20);
			this->textBox3->TabIndex = 7;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton4);
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(286, 129);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(303, 124);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Select type algorithm to slovle the problem:";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &MyForm::groupBox1_Enter);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(14, 92);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(270, 17);
			this->radioButton4->TabIndex = 3;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"using non - intersecting paths and intersecting paths";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton4_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(14, 69);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(158, 17);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"using a mutation mechanism";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton3_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(14, 46);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(136, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"using intersecting paths";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(14, 23);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(163, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"using non - intersecting paths";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(204, 308);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(40, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Result:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(588, 270);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::button1_MouseClick);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(326, 273);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(41, 20);
			this->textBox5->TabIndex = 13;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(220, 275);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(100, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Input number steps:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(9, 85);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(66, 13);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Input edges:";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(205, 325);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(458, 160);
			this->listBox1->TabIndex = 15;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged_1);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(395, 27);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(268, 45);
			this->trackBar1->TabIndex = 16;
			this->trackBar1->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			this->trackBar1->ValueChanged += gcnew System::EventHandler(this, &MyForm::trackBar1_ValueChanged);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(343, 82);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(41, 20);
			this->textBox4->TabIndex = 18;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(204, 85);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(137, 13);
			this->label7->TabIndex = 17;
			this->label7->Text = L"Input percent for crossover:";
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(395, 78);
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(268, 45);
			this->trackBar2->TabIndex = 19;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar2_Scroll);
			this->trackBar2->ValueChanged += gcnew System::EventHandler(this, &MyForm::trackBar2_ValueChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(402, 63);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(13, 13);
			this->label8->TabIndex = 20;
			this->label8->Text = L"0";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(638, 63);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(25, 13);
			this->label9->TabIndex = 21;
			this->label9->Text = L"500";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(402, 110);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(13, 13);
			this->label10->TabIndex = 22;
			this->label10->Text = L"0";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(638, 110);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(25, 13);
			this->label11->TabIndex = 23;
			this->label11->Text = L"100";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(692, 504);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Genetic Algorithm for Longest path problem";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void table()
		{
			if (textBox2->Text != "")
			{
				dataGridView1->RowCount = Convert::ToInt32(textBox2->Text);
				dataGridView1->ColumnCount = 2;
				dataGridView1->Columns[0]->Width = 50;
				dataGridView1->Columns[1]->Width = 50;
			}
		}

		bool textIsNotNumber(string s)
		{
			bool has_only_digits = (s.find_first_not_of("0123456789") == string::npos);
			if (!has_only_digits)
			{
				MessageBox::Show("Text is't number!", "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				return true;
			}
			else return false;
		}

		void InitializeTrackBar()
		{
			trackBar1->TickStyle = TickStyle::Both;
			trackBar1->Minimum = 0;
			trackBar1->Maximum = 500;
			trackBar1->TickFrequency = 50;
			trackBar1->ValueChanged += gcnew System::EventHandler(this, &MyForm::trackBar1_ValueChanged);
			this->Controls->Add(this->trackBar1);
		}

		void InitializeTrackBar2()
		{
			trackBar2->TickStyle = TickStyle::Both;
			trackBar2->Minimum = 0;
			trackBar2->Maximum = 100;
			trackBar2->TickFrequency = 10;
			trackBar2->ValueChanged += gcnew System::EventHandler(this, &MyForm::trackBar2_ValueChanged);
			this->Controls->Add(this->trackBar2);
		}



	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {

	}
	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (textBox1->Text != "")
				 {
					 bool isNumber1 = false;
					 String^ i1 = textBox1->Text;
					 string unmanaged = msclr::interop::marshal_as<string>(i1);
					 isNumber1 = textIsNotNumber(unmanaged);
					 if (textBox1->Text == "0")  MessageBox::Show("Graph can't have zero vertex!", "Error",
						 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					 if (isNumber1 == true || textBox1->Text == "0") textBox1->Text = "";
				 }
	}



	private: System::Void radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (radioButton4->Checked == true) textBox5->Enabled = true;
	}
	private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (radioButton3->Checked == true) textBox5->Enabled = true;
	}
	private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (radioButton2->Checked == true) textBox5->Enabled = false;
	}
	private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (radioButton1->Checked == true) textBox5->Enabled = false;
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 listBox1->Items->Clear();

				 bool remark = false;
				 pair<int,int> coord;

				 for (size_t i = 0; i < dataGridView1->RowCount - 1; i++)
				 {

					 try
					 {
						dataGridView1->Rows[i]->Cells[0]->Value->ToString();
					 }
					 catch (...) {
						 string str = "Cell [" + to_string(i) + "][0] is empty!";
						 String^ res = marshal_as<String^>(str);
						 MessageBox::Show(res, "Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						 return;
					 }

					 try
					 {
						 dataGridView1->Rows[i]->Cells[1]->Value->ToString();
					 }
					 catch (...) {
						 string str = "Cell [" + to_string(i) + "][1] is empty!";
						 String^ res = marshal_as<String^>(str);
						 MessageBox::Show(res, "Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						 return;
					 }
					
				 }

				 if ((textBox1->Text != "") && (textBox2->Text != "") && (textBox3->Text != "") && (textBox4->Text != ""))
				 {
					 Problem D(Convert::ToInt32(textBox1->Text), Convert::ToInt32(textBox2->Text));
					 for (size_t i = 0; i < dataGridView1->RowCount - 1; i++)
					 {
						 D.graph_add(Convert::ToInt32(dataGridView1->Rows[i]->Cells[0]->Value), Convert::ToInt32(dataGridView1->Rows[i]->Cells[1]->Value));
					 }
					 vector < vector<long long> > res;
					 int size = Convert::ToInt32(textBox3->Text);
					 bool status = false;

					 GA population1(size);
					 population1.generateFirstGeneration(D);
					 double percent = 0;
					 percent = Convert::ToDouble(textBox4->Text);

					 population1.percent = percent / 100;
					 if (radioButton1->Checked)
					 {
						 res = population1.start_nonInterseptingPath(D, 1);
						 status = true;
					 }
					 if (radioButton2->Checked)
					 {
						 res = population1.start_intersctingPaths(D, 2);
						 status = true;
					 }

					 if (radioButton3->Checked && textBox5->Text != "")
					 {
						 
							 int n = Convert::ToInt32(textBox5->Text);
							 res = population1.start_mutationMechanism(D, 3, n);
							 status = true;
						 }
					 else if (radioButton3->Checked)
						 {
							 MessageBox::Show("Don't set the number of steps", "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						 }
					 

					 if (radioButton4->Checked && textBox5->Text != "")
					 {
						 if (textBox5->Text != "")
						 {
							 int n = Convert::ToInt32(textBox5->Text);
							 res = population1.start_bothPairsOfPaths(population1, D, 4, n);
							 status = true;
						 }
						 
					 }
					 else if (radioButton4->Checked)
						 {
							 MessageBox::Show("Don't set the number of steps", "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						 }
					 if (status == true)
					 {

						 String^ tmp = Convert::ToString(res[0].size() - 1);
						 string size1 = msclr::interop::marshal_as<string>(tmp);
						 string resPath = "The length of longest path is " + size1 + ".\n";

						 String^ result;
						 result = marshal_as<String^>(resPath);
						 this->listBox1->Items->Insert(0, result);

						 resPath = "";
						 for (size_t i = 0; i < res.size(); i++)
						 {

							 for (size_t j = 0; j < res[i].size()-1; j++)
							 {
								 String^ tmp1 = Convert::ToString(res[i][j]+1);
								 String^ tmp2 = Convert::ToString(res[i][j+1] + 1);
								 string str = "("+msclr::interop::marshal_as<string>(tmp1)+"," + msclr::interop::marshal_as<string>(tmp2)+")";
								 resPath = resPath + str + " ";
							 }
							 String^ result1;
							 result1 = marshal_as<String^>(resPath);
							 this->listBox1->Items->Insert(i + 1, result1);
							 resPath = "";
						 }

						 int a=this->listBox1->Items->Count;
						 String^ time;
						 string time_str = "\nTime:"+to_string(population1.time1) + " sec.";
						 time = marshal_as<String^>(time_str);
						 this->listBox1->Items->Insert(a, time);
					 }
	 
				 }
				 else
				 {
					  if (textBox1->Text == "")
					 {
						 MessageBox::Show("Graph can't have zero edges!", "Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					 }
					 else if (textBox2->Text == "")
					 {
						 MessageBox::Show("Graph can't have zero edges!", "Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					 }
					 else if ((textBox3->Text == ""))
					 {
						 MessageBox::Show("Size population can't be equal zero!", "Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					 }
					 else if ((textBox4->Text == ""))
					 {
						 MessageBox::Show("Percent for crossover can't be equal zero!", "Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					 }

				 }

				 


	}
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {

				 if (textBox2->Text != "")
				 {
					 bool isNumber2 = false;
					 String^ i1 = textBox2->Text;
					 string unmanaged = msclr::interop::marshal_as<string>(i1);
					 isNumber2 = textIsNotNumber(unmanaged);
					 if (textBox2->Text == "0") MessageBox::Show("Graph can't have zero edges!", "Error",
						 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					 if (isNumber2 == true || textBox2->Text == "0") textBox2->Text = "";
					 if (textBox2->Text != "" && textBox2->Text != "0")  table();
				 }
	}
	private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {

				 if (textBox3->Text != "")
				 {
				
					 bool isNumber = false;
					 String^ i1 = textBox3->Text;
					 string unmanaged = msclr::interop::marshal_as<string>(i1);

					 isNumber = textIsNotNumber(unmanaged);

					 if (isNumber == false && (Convert::ToDouble(i1) >= 0 && Convert::ToDouble(i1) <= 500)) trackBar1->Value = Convert::ToDouble(i1);	
					 else
					 {
						 trackBar1->Value = 500;
						 textBox3->Text = i1;
					 }
					 
						 if (textBox3->Text == "0") MessageBox::Show("Size population can't be equal zero!", "Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						 if (isNumber == true || textBox3->Text == "0") textBox3->Text = "";
					 
				 }
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void listBox1_SelectedIndexChanged_1(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 textBox1->Text = "";
				 textBox2->Text = "";
				 dataGridView1->ColumnCount = 0;
				 OpenFileDialog openFileDialog;
				 openFileDialog.InitialDirectory = "";
				 openFileDialog.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
				 openFileDialog.FilterIndex = 1;
				 openFileDialog.RestoreDirectory = true;

				 int max = 0;
				 if (openFileDialog.ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 String^ tmp_path = Convert::ToString(openFileDialog.FileName);
					 string path = msclr::interop::marshal_as<string>(tmp_path);
					 string str;
					 ifstream infile;
					 dataGridView1->ColumnCount = 2;
					 dataGridView1->Columns[0]->Width = 50;
					 dataGridView1->Columns[1]->Width = 50;
					 int ch = 0; 
					 string s;  
					 vector<string> v;  

					 ifstream in(path);     //îòêðûëè äëÿ ÷òåíèÿ  ôàéë
					 while ((ch = in.get()) != EOF) {   //îáúÿñíåíèå íèæå
						 if (char(ch) != '\n') s = s + char(ch);
						 else {
							 v.push_back(s); //Åñëè òåêóùèé ñèìâîë ïåðåíîñ, òî çàïèñûâàåì ñòðîêó â âåêòîð
							 s.clear(); //Î÷èùàåì ñòðîêó
						 }
					 }    v.push_back(s); //Äîïèñûâàåì ïîñëåäíþþ ñòðîêó â âåêòîð.
					 in.close(); //Çàêðûâàåì ôàéë

					 for (size_t i = 0; i < v.size(); i++)
					 {
						 int count = 0;
						 string str1 = "";
						 string str2 = "";

						 for (size_t j = 0; j < v[i].size(); j++)
						 {
							 count++;
							 if (v[i].at(j) != ' ')
							 {
								 str1 = str1 + v[i].at(j);

							 }
							 else
							 {
								 break;
							 }
						 }

						 for (size_t j = count; j < v[i].size(); j++)
						 {
							 str2 = str2 + v[i].at(j);
						 }



						 dataGridView1->Rows->Add();
						 dataGridView1->Rows[i]->Cells[0]->Value = marshal_as<String^>(str1);
						 dataGridView1->Rows[i]->Cells[1]->Value = marshal_as<String^>(str2);

						 if (max < Convert::ToInt32(dataGridView1->Rows[i]->Cells[0]->Value))
						 {
							 max = Convert::ToInt32(dataGridView1->Rows[i]->Cells[0]->Value);
						 }
						 else if (max < Convert::ToInt32(dataGridView1->Rows[i]->Cells[1]->Value))
						 {
							 max = Convert::ToInt32(dataGridView1->Rows[i]->Cells[1]->Value);
						 }

					 }

					 String^ result1;
					 string vertex = to_string(max);
					 result1 = marshal_as<String^>(vertex);
					 String^ result2;
					 string edge = to_string(dataGridView1->RowCount - 1);
					 result2 = marshal_as<String^>(edge);
					 textBox1->Text = result1;
					 textBox2->Text = result2;
				 }

	}
	private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 
				 SaveFileDialog saveFileDialog1;
				 saveFileDialog1.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
				 saveFileDialog1.Title = "Save in text file";
				 saveFileDialog1.InitialDirectory = "";
				 saveFileDialog1.FilterIndex = 1;
				 saveFileDialog1.RestoreDirectory = true;

				 if (saveFileDialog1.ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 string path = msclr::interop::marshal_as<string>(Convert::ToString(saveFileDialog1.FileName));
					 ofstream outputFile;
					
					 if (listBox1->Items->Count > 0)
					 {
						 outputFile.open(path);
						 if (radioButton1->Checked) outputFile << "Genetic Algorithm using non - intersecting paths\n";
						 else if (radioButton2->Checked)  outputFile << "Genetic Algorithm using intersecting paths\n";
						 else if (radioButton3->Checked) outputFile << "Genetic Algorithm using a mutation mechanism \n";
						 else if (radioButton4->Checked) outputFile << "Genetic Algorithm using non - intersecting paths and intersecting paths\n";

						 outputFile << "Number of vertices in the graph : " << msclr::interop::marshal_as<string>(Convert::ToString(textBox1->Text)) << endl;
						 outputFile << "Number of edges in the graph : " << msclr::interop::marshal_as<string>(Convert::ToString(textBox2->Text)) << endl;

						 outputFile << "Edges:"<<endl;
						 for (size_t i = 0; i < dataGridView1->RowCount-1; i++)
						 {
							 outputFile << msclr::interop::marshal_as<string>(dataGridView1->Rows[i]->Cells[0]->Value->ToString()) << " " << msclr::interop::marshal_as<string>(dataGridView1->Rows[i]->Cells[1]->Value->ToString()) << endl;
						 }

						 outputFile << "Popultion size: " << msclr::interop::marshal_as<string>(Convert::ToString(textBox3->Text)) << endl;
						 outputFile << "Percent for crossover: " << msclr::interop::marshal_as<string>(Convert::ToString(textBox4->Text)+" %") << endl;

						 if (radioButton3->Checked || radioButton4->Checked) outputFile << "Number steps: " << msclr::interop::marshal_as<string>(Convert::ToString(textBox5->Text)) << endl;
						 outputFile << "Result:"  <<endl;

						 for (size_t i = 0; i < listBox1->Items->Count; i++)
						 {
							 outputFile << msclr::interop::marshal_as<string>(listBox1->Items[i]->ToString()) << endl;
						 }

						 MessageBox::Show("File successfully saved!", "Save",
							 MessageBoxButtons::OK, MessageBoxIcon::Information);

						 outputFile.close();
					 }
					 else
					 {
						 MessageBox::Show("Window result is empty!", "Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					 }
				 }

	}
private: System::Void canselToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Application::Exit();
}
private: System::Void newWindowToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 MyForm^ frm = gcnew MyForm;
			 frm->Show(this);
}

		 private: bool signal = false;
private: System::Void clearToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = "";
			 textBox2->Text = "";
			 textBox3->Text = "";
			 textBox4->Text = "";
            
			 radioButton1->Checked = false;
			 radioButton2->Checked = false;
			 radioButton3->Checked = false;
			 radioButton4->Checked = false;
			 dataGridView1->ColumnCount = 0;
			 textBox5->Text = "";
			 textBox5->Enabled = false;
			 listBox1->Items->Clear();

			 signal = true;
			 trackBar1->Value = trackBar1->Minimum;
			 
			 trackBar2->Value = trackBar2->Minimum;


}
private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {

			 if (radioButton3->Checked == true || radioButton4->Checked == true)
			 {

				 if (textBox5->Text != "")
				 {
					 bool isNumber = false;
					 String^ i1 = textBox5->Text;
					 string unmanaged = msclr::interop::marshal_as<string>(i1);
					 isNumber = textIsNotNumber(unmanaged);
					 if (textBox5->Text == "0") MessageBox::Show("Algorithm can't have zero steps", "Error",
						 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					 if (isNumber == true || textBox3->Text == "0") textBox5->Text = "";
				 }
			 }
			 else
			 {
				 textBox5->Text = "";
			 }
}
private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
}
private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
}
	private: System::Void trackBar1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {


					 textBox3->Text = (System::Math::Round(trackBar1->Value)).ToString();
	}

private: bool tmp1 = false;
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (textBox4->Text != "" && tmp1 == false)
			 {
				 bool isNumber = false;
				 String^ i1 = textBox4->Text;
				 string unmanaged = msclr::interop::marshal_as<string>(i1);
				 isNumber = textIsNotNumber(unmanaged);
				 bool st = false;

				 if (isNumber == false)
				 {

					 if (textBox4->Text == "0")
					 {
						 MessageBox::Show("Percent for crossover can't be equal zero!", "Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					 }

					 double tmp = Convert::ToDouble(i1);
					 if (tmp <= 0 || tmp > 100)
					 {
						 tmp1 = true;
						 trackBar2->Value = 0;
						 st = true;
						 textBox4->Text = "";
						 MessageBox::Show("Percent for crossover must be between 1 and 100!", "Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);

					 }
				 }
				 if (isNumber == true || textBox4->Text == "0" || st == true)
				 {
					 tmp1 = true;
					 trackBar2->Value = 0;
					 textBox4->Text = "";
				 }
			      else trackBar2->Value = Convert::ToDouble(i1);
				 
			 }
			 else tmp1 = false;

}
private: System::Void trackBar2_Scroll(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void trackBar2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 
			 if (System::Math::Round(trackBar2->Value) != 0 && tmp1==false)
			 {
				 textBox4->Text = (System::Math::Round(trackBar2->Value)).ToString();
			 }
			
}
private: System::Void button1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
}
};
}