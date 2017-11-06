#pragma once
#include "GA.h"
#include <string>
#include <vector>
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <Windows.h>
#include "GaInAllGraph.h"
#include "GaBetweenVertex.h"
#include "DatabaseWriter.h"
#include "ProblemWeight.h"
#include "GAWithWeight.h"
#include <stdarg.h>
#include <stdlib.h>

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

		bool ch1 = false;



	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage1;

	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TabControl^  Genetic;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::TrackBar^  trackBar2;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;

	private: System::Windows::Forms::TrackBar^  trackBar4;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;




	public:
		bool ch2 = false;

		MyForm(void)
		{
			InitializeComponent();
			textBox5->Enabled = false;
			InitializeTrackBar();
			radioButton1->Checked = false;
			radioButton2->Checked = false;
			radioButton3->Checked = false;
			radioButton4->Checked = false;
			enabledBetweenVertex();
			enabledAllVertex();
			tabPage1->Text = "Genetic Algorithm in an unweighted graph";
			tabPage2->Text = "Genetic Algorithm in an weighted graph";

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

	protected:

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  windowToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  clearToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  canselToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newWindowToolStripMenuItem;

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->windowToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newWindowToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->canselToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->trackBar4 = (gcnew System::Windows::Forms::TrackBar());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->Genetic = (gcnew System::Windows::Forms::TabControl());
			this->menuStrip1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->Genetic->SuspendLayout();
			this->SuspendLayout();
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
			this->menuStrip1->Size = System::Drawing::Size(997, 24);
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
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->tabPage2->Controls->Add(this->label20);
			this->tabPage2->Controls->Add(this->label21);
			this->tabPage2->Controls->Add(this->button3);
			this->tabPage2->Controls->Add(this->button4);
			this->tabPage2->Controls->Add(this->label19);
			this->tabPage2->Controls->Add(this->listBox2);
			this->tabPage2->Controls->Add(this->trackBar4);
			this->tabPage2->Controls->Add(this->textBox10);
			this->tabPage2->Controls->Add(this->textBox11);
			this->tabPage2->Controls->Add(this->textBox12);
			this->tabPage2->Controls->Add(this->label22);
			this->tabPage2->Controls->Add(this->label23);
			this->tabPage2->Controls->Add(this->label24);
			this->tabPage2->Controls->Add(this->label11);
			this->tabPage2->Controls->Add(this->dataGridView2);
			this->tabPage2->Controls->Add(this->textBox8);
			this->tabPage2->Controls->Add(this->textBox9);
			this->tabPage2->Controls->Add(this->label17);
			this->tabPage2->Controls->Add(this->label18);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(965, 541);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->Click += gcnew System::EventHandler(this, &MyForm::tabPage2_Click);
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(650, 38);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(13, 13);
			this->label20->TabIndex = 53;
			this->label20->Text = L"0";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(896, 38);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(25, 13);
			this->label21->TabIndex = 52;
			this->label21->Text = L"500";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(870, 172);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(74, 23);
			this->button3->TabIndex = 51;
			this->button3->Text = L"Clear";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(767, 172);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(74, 23);
			this->button4->TabIndex = 50;
			this->button4->Text = L"Start";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(242, 182);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(40, 13);
			this->label19->TabIndex = 49;
			this->label19->Text = L"Result:";
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(244, 202);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(703, 303);
			this->listBox2->TabIndex = 48;
			this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox2_SelectedIndexChanged);
			// 
			// trackBar4
			// 
			this->trackBar4->Location = System::Drawing::Point(642, 6);
			this->trackBar4->Name = L"trackBar4";
			this->trackBar4->Size = System::Drawing::Size(279, 45);
			this->trackBar4->TabIndex = 47;
			this->trackBar4->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar4_Scroll);
			this->trackBar4->ValueChanged += gcnew System::EventHandler(this, &MyForm::trackBar4_ValueChanged);
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(401, 16);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(41, 20);
			this->textBox10->TabIndex = 41;
			this->textBox10->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox10_TextChanged);
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(401, 70);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(41, 20);
			this->textBox11->TabIndex = 45;
			this->textBox11->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox11_TextChanged);
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(401, 129);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(41, 20);
			this->textBox12->TabIndex = 43;
			this->textBox12->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox12_TextChanged);
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(253, 16);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(107, 13);
			this->label22->TabIndex = 40;
			this->label22->Text = L"Input size population:";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(253, 129);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(100, 13);
			this->label23->TabIndex = 42;
			this->label23->Text = L"Input number steps:";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(253, 70);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(139, 13);
			this->label24->TabIndex = 44;
			this->label24->Text = L"Input probability of mutation:";
			this->label24->Click += gcnew System::EventHandler(this, &MyForm::label24_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(6, 93);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(197, 13);
			this->label11->TabIndex = 29;
			this->label11->Text = L"Input edges and weight between vertex:";
			this->label11->Click += gcnew System::EventHandler(this, &MyForm::label11_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(7, 113);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(210, 396);
			this->dataGridView2->TabIndex = 28;
			this->dataGridView2->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView2_CellContentClick);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(176, 54);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(41, 20);
			this->textBox8->TabIndex = 27;
			this->textBox8->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox8_TextChanged);
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(176, 16);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(41, 20);
			this->textBox9->TabIndex = 26;
			this->textBox9->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox9_TextChanged);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(6, 54);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(99, 13);
			this->label17->TabIndex = 25;
			this->label17->Text = L"Input number edge:";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(6, 16);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(104, 13);
			this->label18->TabIndex = 24;
			this->label18->Text = L"Input number vertex:";
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::Transparent;
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Controls->Add(this->checkBox1);
			this->tabPage1->Controls->Add(this->checkBox2);
			this->tabPage1->Controls->Add(this->label10);
			this->tabPage1->Controls->Add(this->label9);
			this->tabPage1->Controls->Add(this->trackBar2);
			this->tabPage1->Controls->Add(this->label8);
			this->tabPage1->Controls->Add(this->label16);
			this->tabPage1->Controls->Add(this->trackBar1);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Controls->Add(this->label14);
			this->tabPage1->Controls->Add(this->label15);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Controls->Add(this->textBox3);
			this->tabPage1->Controls->Add(this->textBox4);
			this->tabPage1->Controls->Add(this->textBox5);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->listBox1);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(965, 541);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->Click += gcnew System::EventHandler(this, &MyForm::tabPage1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(118, 19);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(41, 20);
			this->textBox1->TabIndex = 20;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(214, 165);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(248, 17);
			this->checkBox1->TabIndex = 4;
			this->checkBox1->Text = L"Select type algorithm to solve problem in graph:";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(631, 165);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(192, 17);
			this->checkBox2->TabIndex = 34;
			this->checkBox2->Text = L"Solve problem between two vertex:";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox2_CheckedChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(896, 130);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(25, 13);
			this->label10->TabIndex = 39;
			this->label10->Text = L"100";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(650, 130);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(13, 13);
			this->label9->TabIndex = 38;
			this->label9->Text = L"0";
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(642, 83);
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(279, 45);
			this->trackBar2->TabIndex = 5;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(649, 55);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(13, 13);
			this->label8->TabIndex = 37;
			this->label8->Text = L"0";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(895, 55);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(25, 13);
			this->label16->TabIndex = 26;
			this->label16->Text = L"500";
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(642, 13);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(279, 45);
			this->trackBar1->TabIndex = 36;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(864, 314);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(74, 23);
			this->button2->TabIndex = 35;
			this->button2->Text = L"Clear";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox6);
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Controls->Add(this->textBox7);
			this->groupBox2->Controls->Add(this->label13);
			this->groupBox2->Location = System::Drawing::Point(631, 178);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(307, 123);
			this->groupBox2->TabIndex = 33;
			this->groupBox2->TabStop = false;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(130, 70);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(41, 20);
			this->textBox6->TabIndex = 25;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(39, 73);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(62, 13);
			this->label12->TabIndex = 21;
			this->label12->Text = L"Last vertex:";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(130, 34);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(41, 20);
			this->textBox7->TabIndex = 20;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(39, 37);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(61, 13);
			this->label13->TabIndex = 19;
			this->label13->Text = L"First vertex:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(761, 314);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(74, 23);
			this->button1->TabIndex = 32;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(211, 324);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(40, 13);
			this->label4->TabIndex = 31;
			this->label4->Text = L"Result:";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton4);
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(214, 178);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(293, 123);
			this->groupBox1->TabIndex = 30;
			this->groupBox1->TabStop = false;
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
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged_1);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(885, 117);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(25, 13);
			this->label14->TabIndex = 28;
			this->label14->Text = L"100";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(646, 117);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(13, 13);
			this->label15->TabIndex = 27;
			this->label15->Text = L"0";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(8, 96);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(66, 13);
			this->label6->TabIndex = 23;
			this->label6->Text = L"Input edges:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(9, 112);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(146, 410);
			this->dataGridView1->TabIndex = 22;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick_1);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(118, 57);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(41, 20);
			this->textBox2->TabIndex = 21;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(382, 13);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(41, 20);
			this->textBox3->TabIndex = 7;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(382, 60);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(41, 20);
			this->textBox4->TabIndex = 18;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(382, 108);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(41, 20);
			this->textBox5->TabIndex = 13;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 13);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Input number edge:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 13);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Input number vertex:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(234, 16);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(107, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Input size population:";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(214, 349);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(724, 173);
			this->listBox1->TabIndex = 15;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(234, 111);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(100, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Input number steps:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(234, 63);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(133, 13);
			this->label7->TabIndex = 17;
			this->label7->Text = L"Input percent for selection:";
			// 
			// Genetic
			// 
			this->Genetic->Controls->Add(this->tabPage1);
			this->Genetic->Controls->Add(this->tabPage2);
			this->Genetic->Location = System::Drawing::Point(12, 41);
			this->Genetic->Name = L"Genetic";
			this->Genetic->SelectedIndex = 0;
			this->Genetic->Size = System::Drawing::Size(973, 567);
			this->Genetic->TabIndex = 5;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(997, 624);
			this->Controls->Add(this->Genetic);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Genetic Algorithm for Longest path problem";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->Genetic->ResumeLayout(false);
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
				for (int i = 0; i < dataGridView1->ColumnCount; i++)  dataGridView1->Columns[i]->Width = 50;
			}
		}

		void table2()
		{
			if (textBox8->Text != "")
			{
				dataGridView2->RowCount = Convert::ToInt32(textBox8->Text);
				dataGridView2->ColumnCount = 3;
				for (int i = 0; i < dataGridView2->ColumnCount; i++)  dataGridView2->Columns[i]->Width = 50;
			}
		}


		bool textIsNotNumber(string s)
		{
			bool has_only_digits = (s.find_first_not_of("0123456789.,") == string::npos);
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
	
			trackBar2->TickStyle = TickStyle::Both;
			trackBar2->Minimum = 0;
			trackBar2->Maximum = 100;
			trackBar2->TickFrequency = 10;
			trackBar2->ValueChanged += gcnew System::EventHandler(this, &MyForm::trackBar2_ValueChanged);
		
			trackBar4->TickStyle = TickStyle::Both;
			trackBar4->Minimum = 0;
			trackBar4->Maximum = 500;
			trackBar4->TickFrequency = 50;
			trackBar4->ValueChanged += gcnew System::EventHandler(this, &MyForm::trackBar4_ValueChanged);


	//		trackBar3->TickStyle = TickStyle::Both;
		//	trackBar3->Minimum = 0;
		//	trackBar3->Maximum = 1;
			//trackBar3->TickFrequency = 0,1;
			//trackBar3->ValueChanged += gcnew System::EventHandler(this, &MyForm::trackBar3_ValueChanged);
			//this->Controls->Add(this->trackBar3);
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
			 DatabaseWriter connect = DatabaseWriter();
				 connect.ConnectDB();

				 listBox1->Items->Clear();

				 bool remark = false;
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

				 if ((textBox1->Text != "") && (textBox2->Text != "") && (textBox3->Text != ""))
				 {
					 Problem D(Convert::ToInt32(textBox1->Text), Convert::ToInt32(textBox2->Text));
					 for (size_t i = 0; i < dataGridView1->RowCount - 1; i++)
					 {
						 D.graph_add(Convert::ToInt32(dataGridView1->Rows[i]->Cells[0]->Value), Convert::ToInt32(dataGridView1->Rows[i]->Cells[1]->Value));
					 }
					 vector < vector<long long> > res;
					 int size = Convert::ToInt32(textBox3->Text);
					 bool status = false;


					 if (checkBox1->Checked == true && textBox4->Text != "" && (radioButton1->Checked == true
						 || (radioButton2->Checked == true) || (radioButton3->Checked == true) || (radioButton4->Checked == true)))
					 {

						 GaInAllGraph population1(size);
						 population1.generateFirstGeneration(D);
						 double percent = 0;
						 percent = Convert::ToDouble(textBox4->Text);
						 int n = 0;
						 population1.percent = percent / 100;
						 if (radioButton1->Checked)
						 {
							 res = population1.start_nonInterseptingPath(D, 1);
							 status = true;
						 }
						 if (radioButton2->Checked)
						 {
							 res = population1.start_intersectingPath(D, 2);
							 status = true;

						 }

						 if (radioButton3->Checked && textBox5->Text != "")
						 {
							 n = Convert::ToInt32(textBox5->Text);
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
								 n = Convert::ToInt32(textBox5->Text);
								 res = population1.start_bothPairsOfPaths(D, 4, n);
								 status = true;
							 }

						 }
						 else if (radioButton4->Checked)
						 {
							 MessageBox::Show("Don't set the number of steps", "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						 }
						 if (status == true)
						 {
							 string resPath = "";
							 if (radioButton1->Checked == true && population1.status == true)
							 {
								 resPath = "There aren't intersepting points and paths.\n";
							 }
							 else  if (radioButton2->Checked == true && population1.status == true)
							 {
								 resPath = "There aren't non-intersepting points and paths.\n";
							 }
							 else  if (radioButton4->Checked == true && population1.status == true)
							 {
								 resPath = "There aren't non-intersepting or intersepting points and paths.\n";
							 }

							 if (radioButton1->Checked == true || radioButton2->Checked == true)
							 {
								 if (population1.status == false)
								 connect.insertData(population1.typeTask, population1, D, 0);
							 }
							 else
							 {
								 if (population1.status == false)
								 connect.insertData(population1.typeTask, population1, D, 1, n);
							 }

							 String^ tmp = Convert::ToString(res[0].size() - 1);
							 string size1 = msclr::interop::marshal_as<string>(tmp);
							 resPath = "The length of longest path is " + size1 + ".\n";
							 writeResPath(listBox1,res, resPath, true);
							 int a = this->listBox1->Items->Count;
							 String^ time;
							 string time_str = "\nTime:" + to_string(population1.time1) + " sec.";
							 time = marshal_as<String^>(time_str);
							 this->listBox1->Items->Insert(a, time);
						 }

					 }

					 else if (checkBox2->Checked == true && textBox5->Text != "" &&
						 textBox6->Text != "" && textBox7->Text != "")
					 {
						 if (Convert::ToInt32(textBox6->Text) == Convert::ToInt32(textBox7->Text))
						 {
							 MessageBox::Show("Vertices can't be equal!", "Error",
								 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
							 textBox6->Text = "";
							 textBox7->Text = "";
						 }
						 else
						 {

							 string resPath = "";
							 GaBetweenVertex object(size);
							 object.startData(Convert::ToInt32(textBox7->Text), Convert::ToInt32(textBox6->Text), D);
							 res = object.Genetic(Convert::ToInt32(textBox5->Text));
							 // res = object.Unic(res);

							 connect.insertData(object.typeTask, object, D, 1, Convert::ToInt32(textBox5->Text));

							 String^ tmp = Convert::ToString(res[0].size() - 1);
							 string size1 = msclr::interop::marshal_as<string>(tmp);


							 resPath = "The length of longest path between " + to_string(object.s) + " and " + to_string(object.t) + " vertices is " + size1 + ".";

							 if (checkBox2->Checked == true && object.status == true)
							 {
								 resPath = "\nFail in find path.\n";
							 }

							 String^ result;

							 result = marshal_as<String^>(resPath);
							 writeResPath(listBox1,res, resPath, false);
							 String^ time;
							 string time_str = "Time:" + to_string(object.time1) + " sec.";
							 time = marshal_as<String^>(time_str);
							 this->listBox1->Items->Add(time);
						 }
					 }

					 else if ((textBox4->Text == "") && checkBox1->Checked == true)
					 {
						 MessageBox::Show("Percent for crossover can't be empty!", "Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					 }
					 else if (checkBox1->Checked == true && (radioButton1->Checked == false
						 || (radioButton2->Checked == false) || (radioButton3->Checked == false) || (radioButton4->Checked == false)))
					 {
						 MessageBox::Show("Don't select algorithm", "Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					 }
					 else if (checkBox2->Checked == true && textBox6->Text == "")
					 {
						 MessageBox::Show("Second vertex can't be empty", "Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					 }
					 else if (checkBox2->Checked == true && textBox7->Text == "")
					 {
						 MessageBox::Show("First vertex can't be empty", "Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					 }

					 else if (checkBox2->Checked == false && checkBox1->Checked == false)
					 {
						 MessageBox::Show("Don't type exercise", "Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					 }
					 else if ((textBox5->Text == "") && (radioButton3->Checked == true || radioButton4->Checked == true || checkBox2->Checked == true))
					 {
						 MessageBox::Show("Don't set number step", "Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					 }
				 }
				 else if (textBox1->Text == "")
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
					 MessageBox::Show("Size population can't be empty!", "Error",
						 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				 }

				 connect.CloseConn(connect.ConnectDB());

	}

	private: void writeResPath(ListBox^ listBox1, vector < vector<long long> > res, string  resPath, bool val)
			 {

				 listBox1->Items->Add(marshal_as<String^>(resPath));
				 resPath = "";

				
				 for (size_t i = 1; i < res[0].size(); i++)
				 {
					 resPath = resPath + "(" + ((val == true) ? to_string(res[0][i - 1] + 1) : to_string(res[0][i - 1]) ) + "," 
						 + ((val == true) ? to_string(res[0][i] + 1) : to_string(res[0][i])) + ") ";
				 }

				listBox1->Items->Add(marshal_as<String^>(resPath));
				 resPath = "";

				 if (res.size() > 1)
				 {

					 for (int i = 1; i < res.size(); i++)
					 {
						 if (res[0].size() == res[i].size())
						 {
						
							 for (size_t j = 1; j < res[i].size(); j++)
							 {
							//	 string str2 = (val == true) ? to_string(res[i][j] + 1) : to_string(res[i][j]);
								 resPath = resPath + "(" + ((val == true) ? to_string(res[i][j - 1] + 1) : to_string(res[i][j - 1])) + ","
									 + ((val == true) ? to_string(res[i][j] + 1) : to_string(res[i][j])) + ") ";
							 }
							 listBox1->Items->Add(marshal_as<String^>(resPath));
							 resPath = "";

						 }

					 }
				 }

			 }

			 private: void writeResPathWithWeight(ListBox^ listBox1, vector < vector<long long> > &res, vector<vector<long long>>&res_weight, string  resPath)
			 {

						  listBox1->Items->Add(marshal_as<String^>(resPath));
						  resPath = "";

						  if (res.size() > 1) resPath = resPath + "1 path:\n";
						  for (size_t i = 1; i < res[0].size(); i++)
						  {
							  resPath = "Pair vertex (" + to_string(res[0][i - 1] + 1) + "," + to_string(res[0][i] + 1) + ")  and weight between vertex " +
								  to_string(res_weight[0][i-1]) + "\n";
							  listBox1->Items->Add(marshal_as<String^>(resPath));
							  resPath = "";
						  }


						  if (res.size() > 1)
						  {
							  for (int i = 1; i < res.size(); i++)
							  {
								  resPath = "";

								  resPath = to_string(i+1) + "path:\n";
								  listBox1->Items->Add(marshal_as<String^>(resPath));

								  if (res[0].size() == res[i].size())
								  {
									  for (size_t j = 1; j < res[i].size(); j++)
									  {
										  resPath =  "Pair vertex (" + to_string(res[i][j - 1] + 1) + "," + to_string(res[i][j] + 1) + ") and weight between vertex " +
											  to_string(res_weight[i][j-1]) + "\n";
										  listBox1->Items->Add(marshal_as<String^>(resPath));
										  resPath = "";

									  }
	
								  }

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

					 if (textBox3->Text == "0" && signal == false)
					 {
						 MessageBox::Show("Size population can't be equal zero!", "Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					 }
					 else
					 {
						 signal = false;
					 }
					 if (isNumber == true || textBox3->Text == "0") textBox3->Text = "";

				 }
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void listBox1_SelectedIndexChanged_1(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
			  private: void createTable(DataGridView^ dataGridView1, int value)
			  {
						   if (value == 1)   dataGridView1->ColumnCount = 2;
						   else if (value == 2)  dataGridView1->ColumnCount = 3;
						   for (int i = 0; i < dataGridView1->ColumnCount; i++)
						   {
							   if (i == 0) dataGridView1->Columns[i]->Name = "First vertex";
							   if (i == 1) dataGridView1->Columns[i]->Name = "Second vertex";
							   if (i == 2 && value==2) dataGridView1->Columns[i]->Name = "Weight between vertex";

							   dataGridView1->Columns[i]->Width = 50;
						   }
							  
			  }
			 private: void visible(DataGridView^ dataGridView, vector<string>table, int i)
			 {
//				 dataGridView->Rows->Add();
				 for (size_t j = 0; j < table.size(); j++)
					 dataGridView->Rows[i]->Cells[j]->Value = marshal_as<String^>(table[j]);
			 }

	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (tabPage1->Visible == true)
				 {
					 textBox1->Text = "";
					 textBox2->Text = "";
					 dataGridView1->ColumnCount = 0;
				 }
				 else  if (tabPage2->Visible == true)
				 {
					 dataGridView2->ColumnCount = 0;
					 textBox9->Text = "";
					 textBox8->Text = "";
				 }
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
						
						 if (tabPage1->Visible == true) createTable(dataGridView1, 1);
						 else if (tabPage2->Visible == true) createTable(dataGridView2, 2);

						 int ch = 0;
						 string s;
						 vector<string> v;

						 ifstream in(path);
						 while ((ch = in.get()) != EOF) {
							 if (char(ch) != '\n') s = s + char(ch);
							 else {
								 v.push_back(s);
								 s.clear();
							 }
						 }    v.push_back(s);
						 in.close();


						
						 if (tabPage1->Visible == true) textBox2->Text = marshal_as<String^>(to_string(v.size()));
						 if (tabPage2->Visible == true) textBox8->Text = marshal_as<String^>(to_string(v.size()));



						 for (size_t i = 0; i < v.size(); i++)
						 {

							 vector<string>  table;
							 int count = 0;
							 string str1 = "";
							 string str2 = "";

							 int pos = 0;
							 for (size_t j = 0; j < v[i].size(); j++)
							 {
								 if (v[i].at(j) != ' ')
								 {
									 str1 = str1 + v[i].at(j);

								 }
								 else if (v[i].at(j) == ' ')
								 {
									 table.push_back(str1);
									 str1 = "";
								 }

								 if (j == (v[i].size() - 1))
								 {
									 table.push_back(str1);
								 }
							 }


							 if (tabPage1->Visible == true)
							 {
								 visible(dataGridView1, table, i);

							    if (max < Convert::ToInt32(dataGridView1->Rows[i]->Cells[0]->Value)) max = Convert::ToInt32(dataGridView1->Rows[i]->Cells[0]->Value);
							     else if (max < Convert::ToInt32(dataGridView1->Rows[i]->Cells[1]->Value)) max = Convert::ToInt32(dataGridView1->Rows[i]->Cells[1]->Value);
							 }
							 else if (tabPage2->Visible == true)
							 {
								 visible(dataGridView2, table, i);
								 if (max < Convert::ToInt32(dataGridView2->Rows[i]->Cells[0]->Value)) max = Convert::ToInt32(dataGridView2->Rows[i]->Cells[0]->Value);
								 else if (max < Convert::ToInt32(dataGridView2->Rows[i]->Cells[1]->Value)) max = Convert::ToInt32(dataGridView2->Rows[i]->Cells[1]->Value);
							 }
						
 }
						 if (tabPage1->Visible == true)
						 {
							 textBox1->Text = marshal_as<String^>(to_string(max));
						 }
						 else if (tabPage2->Visible == true)
						 {
							 textBox9->Text = marshal_as<String^>(to_string(max));
						 }
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

					 if (tabPage1->Visible == true)
					 {

						 if (listBox1->Items->Count > 0)
						 {
							 outputFile.open(path);
							 if (radioButton1->Checked) outputFile << "Genetic Algorithm using non - intersecting paths\n";
							 else if (radioButton2->Checked)  outputFile << "Genetic Algorithm using intersecting paths\n";
							 else if (radioButton3->Checked) outputFile << "Genetic Algorithm using a mutation mechanism \n";
							 else if (radioButton4->Checked) outputFile << "Genetic Algorithm using non - intersecting paths and intersecting paths\n";
							 else if (checkBox2->Checked == true) outputFile << "Genetic Algorithm between two vertex\n";

							 outputFile << "Number of vertices in the graph: " << msclr::interop::marshal_as<string>(Convert::ToString(textBox1->Text)) << endl;
							 outputFile << "Number of edges in the graph: " << msclr::interop::marshal_as<string>(Convert::ToString(textBox2->Text)) << endl;

							 if (checkBox2->Checked == true)
							 {
								 outputFile << "First vertex: " << msclr::interop::marshal_as<string>(Convert::ToString(textBox7->Text)) << endl;
								 outputFile << "Second vertex: " << msclr::interop::marshal_as<string>(Convert::ToString(textBox6->Text)) << endl;
							 }



							 outputFile << "Edges:" << endl;
							 for (size_t i = 0; i < dataGridView1->RowCount - 1; i++)
							 {
								 outputFile << msclr::interop::marshal_as<string>(dataGridView1->Rows[i]->Cells[0]->Value->ToString()) << " " << msclr::interop::marshal_as<string>(dataGridView1->Rows[i]->Cells[1]->Value->ToString()) << endl;
							 }

							 outputFile << "Popultion size: " << msclr::interop::marshal_as<string>(Convert::ToString(textBox3->Text)) << endl;

							 if (checkBox1->Checked == true)
							 {
								 outputFile << "Percent for crossover: " << msclr::interop::marshal_as<string>(Convert::ToString(textBox4->Text) + " %") << endl;
							 }

							 if (radioButton3->Checked || radioButton4->Checked || checkBox2->Checked == true) outputFile << "Number steps: " << msclr::interop::marshal_as<string>(Convert::ToString(textBox5->Text)) << endl;
							 outputFile << "Result:" << endl;



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
					 else if (tabPage2->Visible == true)
					 {
						 if (listBox2->Items->Count > 0)
						 {
							 outputFile.open(path);
							 outputFile << "Genetic Algorithm in an weighted graph\n";

							 outputFile << "Number of vertices in the graph: " << msclr::interop::marshal_as<string>(Convert::ToString(textBox9->Text)) << endl;
							 outputFile << "Number of edges in the graph: " << msclr::interop::marshal_as<string>(Convert::ToString(textBox8->Text)) << endl;

							 outputFile << "Edges and weight between vertex: " << endl;
							 for (size_t i = 0; i < dataGridView2->RowCount - 1; i++)
							 {
								 outputFile << "First vertex - " << msclr::interop::marshal_as<string>(dataGridView2->Rows[i]->Cells[0]->Value->ToString())
									 << " Second vertex - " << msclr::interop::marshal_as<string>(dataGridView2->Rows[i]->Cells[1]->Value->ToString())
									 << " and weight between vertex " << msclr::interop::marshal_as<string>(dataGridView2->Rows[i]->Cells[2]->Value->ToString()) << endl;

							 }

							 outputFile << "Popultion size: " << msclr::interop::marshal_as<string>(Convert::ToString(textBox10->Text)) << endl;
							 outputFile << "Probability of mutation: " << msclr::interop::marshal_as<string>(Convert::ToString(textBox11->Text)) << endl;
							 outputFile << "Number steps: " << msclr::interop::marshal_as<string>(Convert::ToString(textBox12->Text)) << endl;
							 outputFile << "Result:" << endl;

							 for (size_t i = 0; i < listBox2->Items->Count; i++)
							 {
								 outputFile << msclr::interop::marshal_as<string>(listBox2->Items[i]->ToString());
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
				 Clear();
	}

	private: void Clear()
	{
				 if (tabPage1->Visible == true)
				 {
					 textBox1->Text = "";
					 textBox2->Text = "";
					 textBox3->Text = "";
					 textBox4->Text = "";
					 textBox7->Text = "";
					 textBox6->Text = "";

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
					 checkBox1->Checked = false;
					 checkBox2->Checked = false;
					 enabledBetweenVertex();
					 enabledAllVertex();
				 }
				 else if (tabPage2->Visible == true)
				 {
					 dataGridView2->ColumnCount = 0;
					 textBox9->Text = "";
					 textBox8->Text = "";
					 textBox10->Text = "";
					 textBox11->Text = "";
					 textBox12->Text = "";
			//		 trackBar3->Value = trackBar3->Minimum;
					 trackBar4->Value = trackBar4->Minimum;
					 listBox2->Items->Clear();

				 }
	}
	
	private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {

				 if (radioButton3->Checked == true || radioButton4->Checked == true || checkBox2->Checked == true)
				 {

					 if (textBox5->Text != "")
					 {
						 bool isNumber = false;
						 String^ i1 = textBox5->Text;
						 string unmanaged = msclr::interop::marshal_as<string>(i1);
						 isNumber = textIsNotNumber(unmanaged);
						 if (textBox5->Text == "0") MessageBox::Show("Algorithm can't have zero steps", "Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						 if (isNumber == true || textBox5->Text == "0") textBox5->Text = "";
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

				 if (System::Math::Round(trackBar1->Value) != 0)
					 textBox3->Text = (System::Math::Round(trackBar1->Value)).ToString();
	}

	private: bool tmp1 = false;
	private: bool tmp2 = false;

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

				 if (System::Math::Round(trackBar2->Value) != 0 && tmp1 == false)
				 {
					 textBox4->Text = (System::Math::Round(trackBar2->Value)).ToString();
				 }

	}
	private: System::Void button1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {


	}
			 void enabledAllVertex()
			 {
				 radioButton1->Checked = false;
				 radioButton2->Checked = false;
				 radioButton3->Checked = false;
				 radioButton4->Checked = false;
				 radioButton1->Enabled = false;
				 radioButton2->Enabled = false;
				 radioButton3->Enabled = false;
				 radioButton4->Enabled = false;
				 textBox4->Text = "";
				 textBox4->Enabled = false;
				 trackBar2->Enabled = false;
			 }

			 void enabledBetweenVertex()
			 {
				 textBox6->Text = "";
				 textBox7->Text = "";
				 textBox5->Text = "";
				 textBox6->Enabled = false;
				 textBox7->Enabled = false;
			 }

			 void unabledAllVertex()
			 {
				 textBox4->Enabled = true;
				 trackBar2->Enabled = true;
				 radioButton1->Enabled = true;
				 radioButton2->Enabled = true;
				 radioButton3->Enabled = true;
				 radioButton4->Enabled = true;
			 }

			 void unabledBetweenVertex()
			 {

				 textBox6->Enabled = true;
				 textBox7->Enabled = true;
			 }


	private: System::Void textBox7_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (textBox7->Text != "")
				 {
					 bool isNumber = false;
					 String^ i1 = textBox7->Text;
					 string unmanaged = msclr::interop::marshal_as<string>(i1);
					 if (textIsNotNumber(unmanaged))
					 {
						 textBox7->Text = "";
					 }

					 if (textBox7->Text == "0")
					 {
						 MessageBox::Show("First vertex can't be equal zero", "Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						 textBox7->Text = "";
					 }
					 else if (textBox1->Text != "" && isNumber == false)
					 {
						 if (Convert::ToInt32(textBox1->Text) < Convert::ToInt32(textBox7->Text))
						 {
							 MessageBox::Show("Number vertex must't exceed quality of vertices", "Error",
								 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
							 textBox7->Text = "";

						 }
					 }

				 }

	}
	private: System::Void textBox6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (textBox6->Text != "")
				 {
					 bool isNumber = false;
					 String^ i1 = textBox6->Text;
					 string unmanaged = msclr::interop::marshal_as<string>(i1);
					 if (textIsNotNumber(unmanaged))
					 {
						 textBox6->Text = "";
					 }
					 else if (textBox6->Text == "0")
					 {
						 MessageBox::Show("Second vertex can't be equal zero ", "Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						 textBox6->Text = "";
					 }
					 else if (textBox1->Text != "" && isNumber == false)
					 {
						 if (Convert::ToInt32(textBox1->Text) < Convert::ToInt32(textBox6->Text))
						 {
							 MessageBox::Show("Number vertex must't exceed quality of vertices", "Error",
								 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
							 textBox6->Text = "";
						 }
					 }
				 }
	}

private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (ch1 == false)
			 {
				 checkBox1->Checked = false;
				 enabledAllVertex();
				 unabledBetweenVertex();
				 ch1 = true;
				 ch2 = false;
				 textBox5->Enabled = true;
				 textBox4->Enabled = false;
				 trackBar2->Enabled = false;
			 }
			 else
			 {
				 ch1 = false;
				 enabledBetweenVertex();
			 }
}
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (ch2 == false)
			 {
				 checkBox2->Checked = false;
				 enabledBetweenVertex();
				 unabledAllVertex();
				 ch2 = true;
				 ch1 = false;
				 textBox5->Enabled = false;
				 textBox4->Enabled = true;
				 trackBar2->Enabled = true;
			 }
			 else
			 {
				 ch2 = false;
				 enabledAllVertex();
			 }
}




private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 Clear();
}

private: System::Void label11_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label24_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void dataGridView1_CellContentClick_1(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void dataGridView2_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e) {
}



private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 Clear();
}
private: System::Void textBox10_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (textBox10->Text != "")
			 {

				 bool isNumber = false;
				 String^ i1 = textBox10->Text;
				 string unmanaged = msclr::interop::marshal_as<string>(i1);

				 isNumber = textIsNotNumber(unmanaged);

				 if (isNumber == false && (Convert::ToDouble(i1) >= 0 && Convert::ToDouble(i1) <= 500)) trackBar4->Value = Convert::ToDouble(i1);
				 else
				 {
					 trackBar4->Value = 500;
					 textBox10->Text = i1;
				 }

				 if (textBox10->Text == "0" && signal == false)
				 {
					 MessageBox::Show("Size population can't be equal zero!", "Error",
						 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				 }
				 else
				 {
					 signal = false;
				 }
				 if (isNumber == true || textBox10->Text == "0") textBox10->Text = "";

			 }
}
private: System::Void trackBar4_Scroll(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void trackBar4_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (System::Math::Round(trackBar4->Value) != 0)
				 textBox10->Text = (System::Math::Round(trackBar4->Value)).ToString();
}

		 private: System::Void trackBar3_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
					//  if (System::Math::Round(trackBar3->Value) != 0)
						//  textBox11->Text = (System::Math::Round(trackBar3->Value) / 1000).ToString("0.000");
		 }
private: System::Void trackBar3_Scroll(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox11_TextChanged(System::Object^  sender, System::EventArgs^  e) {

			 if (textBox11->Text != "")
			 {

				 bool isNumber = false;
				 String^ i1 = textBox11->Text;
				 string unmanaged = msclr::interop::marshal_as<string>(i1);

				 isNumber = textIsNotNumber(unmanaged);
				 if (isNumber == true)	 textBox11->Text = "";

				 bool tr = false;
				 if (unmanaged[unmanaged.size() - 1] == ',' || unmanaged[unmanaged.size() - 1] == '.' )   tr = true;

				 if (tr == false && isNumber == false)
				 {
					 if ((Convert::ToDouble(textBox11->Text) < 0 || Convert::ToDouble(textBox11->Text) > 1))
					 {
						 MessageBox::Show("Probability of mutation must be between 0 and 1", "Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						 textBox11->Text = "";
					 }
				 }

			 }

			 
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 DatabaseWriter connect = DatabaseWriter();
			 connect.ConnectDB();

			 listBox2->Items->Clear();

			 bool remark = false;
			 for (size_t i = 0; i < dataGridView2->RowCount - 1; i++)
			 {
				 for (size_t j = 0; j < dataGridView2->ColumnCount; j++)
				 {
					 try
					 {
						 dataGridView2->Rows[i]->Cells[j]->Value->ToString();
					 }
					 catch (...)
					 {
						 MessageBox::Show(marshal_as<String^>("Cell [" + to_string(i) + "][" + to_string(j) + "] is empty!"), "Error",
							 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						 return;
					 }
				 }
			 }

			 if ((textBox9->Text != "") && (textBox8->Text != "") &&
				 (textBox10->Text != "") && (textBox11->Text != "") && (textBox12->Text != ""))
			 {
				 ProblemWeight D(Convert::ToInt32(textBox9->Text), Convert::ToInt32(textBox8->Text));
				 for (size_t i = 0; i < dataGridView2->RowCount - 1; i++)
				 {
					 D.graphAddWeight(Convert::ToInt32(dataGridView2->Rows[i]->Cells[0]->Value), Convert::ToInt32(dataGridView2->Rows[i]->Cells[1]->Value), Convert::ToInt32(dataGridView2->Rows[i]->Cells[2]->Value));
				 }
				 int size = Convert::ToInt32(textBox10->Text);

				 GAWithWeight g(size);

				 g.probabilityMutation = Convert::ToDouble(textBox11->Text);
				 g.procedure(D, Convert::ToInt32(textBox12->Text));

				 string  resPath = "The length of longest path is " +  to_string(g.resWeigth) + ".\n";

				 writeResPathWithWeight(listBox2, g.res_population, g.resWeigthPath, resPath);
				 int ct = this->listBox2->Items->Count;
				 this->listBox2->Items->Insert(ct, marshal_as<String^>("\nTime:" + to_string(g.time1) + " sec."));

			 }

			 else if (textBox9->Text == "")
			 {
				 MessageBox::Show("Graph can't have zero edges!", "Error",
					 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			 }
			 else if (textBox8->Text == "")
			 {
				 MessageBox::Show("Graph can't have zero edges!", "Error",
					 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			 }
			 else if ((textBox10->Text == ""))
			 {
				 MessageBox::Show("Size population can't be empty!", "Error",
					 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			 }
			 else if ((textBox11->Text == ""))
			 {
				 MessageBox::Show("Probability of mutation can't be empty!", "Error",
					 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			 }
			 else if ((textBox12->Text == ""))
			 {
				 MessageBox::Show("Algorithm can't have zero steps", "Error",
					 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			 }

}
private: System::Void textBox12_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (textBox12->Text != "")
			 {
				 bool isNumber = false;
				 String^ i1 = textBox12->Text;
				 string unmanaged = msclr::interop::marshal_as<string>(i1);
				 isNumber = textIsNotNumber(unmanaged);
				 if (textBox12->Text == "0") MessageBox::Show("Algorithm can't have zero steps", "Error",
					 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				 if (isNumber == true || textBox12->Text == "0") textBox12->Text = "";
			 }
}
private: System::Void tabPage2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox8_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (textBox8->Text != "")
			 {
				 bool isNumber2 = false;
				 String^ i1 = textBox8->Text;
				 string unmanaged = msclr::interop::marshal_as<string>(i1);
				 isNumber2 = textIsNotNumber(unmanaged);
				 if (textBox8->Text == "0") MessageBox::Show("Graph can't have zero edges!", "Error",
					 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				 if (isNumber2 == true || textBox8->Text == "0") textBox8->Text = "";
				 if (textBox8->Text != "" && textBox8->Text != "0")
					 table2();
			 }
}

private: System::Void textBox9_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (textBox9->Text != "")
			 {
				 bool isNumber1 = false;
				 String^ i1 = textBox9->Text;
				 string unmanaged = msclr::interop::marshal_as<string>(i1);
				 isNumber1 = textIsNotNumber(unmanaged);
				 if (textBox9->Text == "0")  MessageBox::Show("Graph can't have zero vertex!", "Error",
					 MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				 if (isNumber1 == true || textBox9->Text == "0") textBox9->Text = "";
			 }
}
private: System::Void listBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void radioButton1_CheckedChanged_1(System::Object^  sender, System::EventArgs^  e) {
}
};
}
