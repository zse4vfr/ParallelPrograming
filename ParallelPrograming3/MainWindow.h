#pragma once
#include <omp.h>
#include "mpi.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#using <System.Windows.Forms.DataVisualization.dll>

# define PI 3.141592653589793238462643383279502884L 

std::pair<std::vector<double>, std::vector<double>> scheme(System::String^% filename, double c, double constLambda, double T, int K, double L, int I, double l, int currI, int currK);

namespace ParallelPrograming3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	/// <summary>
	/// ������ �� MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: double c;
	private: double constLambda;
	private: double T;
	private: int K;
	private: double L;
	private: int I;
	private: double l;
	private: int currI;
	private: int currK;
	private: int currColorIndex = 0;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridView^ table;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ graphic;
	private: System::Windows::Forms::Button^ launch;
	private: System::Windows::Forms::Button^ clear;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxC;
	private: System::Windows::Forms::TextBox^ textBoxLambda;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBoxK;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBoxT;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxCurrI;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBoxThickness;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBoxI;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBoxL;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBoxCurrK;
	private: System::Windows::Forms::Label^ label9;




	protected:


	private:
		/// <summary>
		/// ���������� ��������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� �� ��������� ������������ � �� �������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			this->table = (gcnew System::Windows::Forms::DataGridView());
			this->graphic = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->launch = (gcnew System::Windows::Forms::Button());
			this->clear = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxC = (gcnew System::Windows::Forms::TextBox());
			this->textBoxLambda = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxK = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBoxT = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxCurrI = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBoxThickness = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBoxI = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBoxL = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxCurrK = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->graphic))->BeginInit();
			this->SuspendLayout();
			// 
			// table
			// 
			this->table->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->table->Location = System::Drawing::Point(1192, 20);
			this->table->Name = L"table";
			this->table->RowHeadersWidth = 51;
			this->table->RowTemplate->Height = 24;
			this->table->Size = System::Drawing::Size(300, 700);
			this->table->TabIndex = 0;
			// 
			// graphic
			// 
			chartArea2->Name = L"ChartArea1";
			this->graphic->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->graphic->Legends->Add(legend2);
			this->graphic->Location = System::Drawing::Point(12, 12);
			this->graphic->Name = L"graphic";
			this->graphic->Size = System::Drawing::Size(1000, 700);
			this->graphic->TabIndex = 31;
			this->graphic->Text = L"chart1";
			// 
			// launch
			// 
			this->launch->Location = System::Drawing::Point(1031, 610);
			this->launch->Name = L"launch";
			this->launch->Size = System::Drawing::Size(130, 42);
			this->launch->TabIndex = 2;
			this->launch->Text = L"������";
			this->launch->UseVisualStyleBackColor = true;
			this->launch->Click += gcnew System::EventHandler(this, &MainWindow::launch_Click);
			// 
			// clear
			// 
			this->clear->Location = System::Drawing::Point(1031, 678);
			this->clear->Name = L"clear";
			this->clear->Size = System::Drawing::Size(130, 42);
			this->clear->TabIndex = 3;
			this->clear->Text = L"��������";
			this->clear->UseVisualStyleBackColor = true;
			this->clear->Click += gcnew System::EventHandler(this, &MainWindow::clear_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(1041, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(79, 19);
			this->label1->TabIndex = 4;
			this->label1->Text = L"c, 10 ^ 14";
			// 
			// textBoxC
			// 
			this->textBoxC->Location = System::Drawing::Point(1045, 45);
			this->textBoxC->Name = L"textBoxC";
			this->textBoxC->Size = System::Drawing::Size(100, 22);
			this->textBoxC->TabIndex = 5;
			this->textBoxC->Text = L"3";
			// 
			// textBoxLambda
			// 
			this->textBoxLambda->Location = System::Drawing::Point(1045, 104);
			this->textBoxLambda->Name = L"textBoxLambda";
			this->textBoxLambda->Size = System::Drawing::Size(100, 22);
			this->textBoxLambda->TabIndex = 7;
			this->textBoxLambda->Text = L"1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(1041, 79);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(134, 19);
			this->label2->TabIndex = 6;
			this->label2->Text = L"lambda, 10 ^ (-6)";
			// 
			// textBoxK
			// 
			this->textBoxK->Location = System::Drawing::Point(1045, 212);
			this->textBoxK->Name = L"textBoxK";
			this->textBoxK->Size = System::Drawing::Size(100, 22);
			this->textBoxK->TabIndex = 11;
			this->textBoxK->Text = L"800";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(1041, 187);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(21, 19);
			this->label4->TabIndex = 10;
			this->label4->Text = L"K";
			// 
			// textBoxT
			// 
			this->textBoxT->Location = System::Drawing::Point(1045, 160);
			this->textBoxT->Name = L"textBoxT";
			this->textBoxT->Size = System::Drawing::Size(100, 22);
			this->textBoxT->TabIndex = 9;
			this->textBoxT->Text = L"1,33";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(1041, 129);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(98, 19);
			this->label3->TabIndex = 8;
			this->label3->Text = L"T, 10 ^ (-20)";
			// 
			// textBoxCurrI
			// 
			this->textBoxCurrI->Location = System::Drawing::Point(1045, 439);
			this->textBoxCurrI->Name = L"textBoxCurrI";
			this->textBoxCurrI->Size = System::Drawing::Size(100, 22);
			this->textBoxCurrI->TabIndex = 19;
			this->textBoxCurrI->Text = L"200";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(1041, 414);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(15, 19);
			this->label8->TabIndex = 18;
			this->label8->Text = L"i";
			// 
			// textBoxThickness
			// 
			this->textBoxThickness->Location = System::Drawing::Point(1045, 369);
			this->textBoxThickness->Name = L"textBoxThickness";
			this->textBoxThickness->Size = System::Drawing::Size(100, 22);
			this->textBoxThickness->TabIndex = 17;
			this->textBoxThickness->Text = L"3";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(1041, 344);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(82, 19);
			this->label7->TabIndex = 16;
			this->label7->Text = L"l, 10 ^(-6)";
			// 
			// textBoxI
			// 
			this->textBoxI->Location = System::Drawing::Point(1045, 319);
			this->textBoxI->Name = L"textBoxI";
			this->textBoxI->Size = System::Drawing::Size(100, 22);
			this->textBoxI->TabIndex = 15;
			this->textBoxI->Text = L"800";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(1041, 297);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(15, 19);
			this->label6->TabIndex = 14;
			this->label6->Text = L"I";
			// 
			// textBoxL
			// 
			this->textBoxL->Location = System::Drawing::Point(1045, 272);
			this->textBoxL->Name = L"textBoxL";
			this->textBoxL->Size = System::Drawing::Size(100, 22);
			this->textBoxL->TabIndex = 13;
			this->textBoxL->Text = L"4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(1041, 247);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(91, 19);
			this->label5->TabIndex = 12;
			this->label5->Text = L"L, 10 ^ (-6)";
			// 
			// textBoxCurrK
			// 
			this->textBoxCurrK->Location = System::Drawing::Point(1045, 493);
			this->textBoxCurrK->Name = L"textBoxCurrK";
			this->textBoxCurrK->Size = System::Drawing::Size(100, 22);
			this->textBoxCurrK->TabIndex = 21;
			this->textBoxCurrK->Text = L"500";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(1041, 468);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(18, 19);
			this->label9->TabIndex = 20;
			this->label9->Text = L"k";
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1532, 753);
			this->Controls->Add(this->textBoxCurrK);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBoxCurrI);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBoxThickness);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBoxI);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBoxL);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBoxK);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBoxT);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBoxLambda);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBoxC);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->clear);
			this->Controls->Add(this->launch);
			this->Controls->Add(this->graphic);
			this->Controls->Add(this->table);
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->graphic))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainWindow_Load(System::Object^ sender, System::EventArgs^ e)
	{
		launch_Click(sender, e);
	}
	private: System::Void launch_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->c = System::Double::Parse(this->textBoxC->Text);
		this->constLambda = System::Double::Parse(this->textBoxLambda->Text);
		this->T = System::Double::Parse(this->textBoxT->Text);
		this->K = System::Int32::Parse(this->textBoxK->Text);
		this->L = System::Double::Parse(this->textBoxL->Text);
		this->I = System::Int32::Parse(this->textBoxI->Text);
		this->l = System::Double::Parse(this->textBoxThickness->Text);
		this->currI = System::Int32::Parse(this->textBoxCurrI->Text);
		this->currK = System::Int32::Parse(this->textBoxCurrK->Text);

		array<Color>^ colors = { Color::Green, Color::Blue, Color::Red, Color::Yellow, Color::Brown, Color::Purple };

		Color nextColor = colors[currColorIndex % colors->Length];
		currColorIndex++;

		std::pair<std::vector<double>, std::vector<double>> data;
		String^ filename = "image";
		data = scheme(filename, this->c, this->constLambda, this->T, this->K, this->L, this->I, this->l, currI, currK);

		Series^ series = gcnew Series(L"����� ���������� �����, " + "I = " + I + " K = " + K + " " + currColorIndex);
		series->Color = nextColor;
		series->IsVisibleInLegend = true;
		series->IsXValueIndexed = true;
		series->ChartType = SeriesChartType::Line;
		this->graphic->Series->Add(series);
		for (double i = 0; i < data.first.size(); i++)
		{
			series->Points->AddXY(data.first[i], data.second[i]);
		}

		//FillTable(data);

		std::cout << std::endl;

		ChartImageFormat imageFormat = ChartImageFormat::Png;
		this->graphic->SaveImage(filename, imageFormat);
	}
	private: System::Void FillTable(std::pair<std::vector<double>, std::vector<double>> data)
	{
		String^ filename = "image";
		std::pair<std::vector<double>, std::vector<double>> data2;
		data2 = scheme(filename, this->c, this->constLambda, this->T, this->K, this->L, 2 * this->I, this->l, 2 * currI, currK);

		std::pair<std::vector<double>, std::vector<double>> data4;
		data4 = scheme(filename, this->c, this->constLambda, this->T, this->K, this->L, 4 * this->I, this->l, 4 * currI, currK);

		double delta1 = abs(data.second[this->currK] - data2.second[this->currK]);
		double delta2 = abs(data2.second[this->currK] - data4.second[this->currK]);
		double delta = /*delta2 == 0 ? */delta1 / delta2/* : 0*/;

		array<String^>^ row = { this->I.ToString(), this->K.ToString(), delta1.ToString(), delta2.ToString(), delta.ToString() };
		this->table->Rows->Add(row);
	}
	private: System::Void clear_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->table->Rows->Clear();
		this->graphic->Series->Clear();
		this->currColorIndex = 0;
	}
};
}