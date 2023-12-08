#pragma once
#include <omp.h>
#include "mpi.h"
#include <vector>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

# define PI 3.141592653589793238462643383279502884L 

std::pair<std::vector<double>, std::vector<double>> scheme(double c, double constLambda, double T, int K, double L, int I, double l, int currI, int currK);

namespace ParallelPrograming1 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	/// <summary>
	/// —водка дл€ MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::TextBox^ textBoxC;
	private: System::Windows::Forms::TextBox^ textBoxLambda;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxT;
	private: System::Windows::Forms::TextBox^ textBoxI;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBoxL;
	private: System::Windows::Forms::TextBox^ textBoxK;
	private: System::Windows::Forms::TextBox^ textBoxThickness;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ launch;
	private: System::Windows::Forms::Button^ clear;
	private: System::Windows::Forms::TextBox^ textBoxCurrK;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBoxCurrI;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::DataGridView^ table;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ graphic;

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

	protected:


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			this->textBoxC = (gcnew System::Windows::Forms::TextBox());
			this->textBoxLambda = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxT = (gcnew System::Windows::Forms::TextBox());
			this->textBoxI = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBoxL = (gcnew System::Windows::Forms::TextBox());
			this->textBoxK = (gcnew System::Windows::Forms::TextBox());
			this->textBoxThickness = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->launch = (gcnew System::Windows::Forms::Button());
			this->clear = (gcnew System::Windows::Forms::Button());
			this->textBoxCurrK = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBoxCurrI = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->table = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->graphic = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->graphic))->BeginInit();
			this->SuspendLayout();
			// 
			// textBoxC
			// 
			this->textBoxC->Location = System::Drawing::Point(1045, 45);
			this->textBoxC->Name = L"textBoxC";
			this->textBoxC->Size = System::Drawing::Size(100, 22);
			this->textBoxC->TabIndex = 2;
			this->textBoxC->Text = L"3";
			// 
			// textBoxLambda
			// 
			this->textBoxLambda->Location = System::Drawing::Point(1045, 95);
			this->textBoxLambda->Name = L"textBoxLambda";
			this->textBoxLambda->Size = System::Drawing::Size(100, 22);
			this->textBoxLambda->TabIndex = 3;
			this->textBoxLambda->Text = L"1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(1041, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(79, 19);
			this->label1->TabIndex = 10;
			this->label1->Text = L"c, 10 ^ 14";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(1041, 70);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(134, 19);
			this->label2->TabIndex = 11;
			this->label2->Text = L"lambda, 10 ^ (-6)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(1041, 120);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(98, 19);
			this->label3->TabIndex = 12;
			this->label3->Text = L"T, 10 ^ (-20)";
			// 
			// textBoxT
			// 
			this->textBoxT->Location = System::Drawing::Point(1045, 145);
			this->textBoxT->Name = L"textBoxT";
			this->textBoxT->Size = System::Drawing::Size(100, 22);
			this->textBoxT->TabIndex = 13;
			this->textBoxT->Text = L"1,33";
			// 
			// textBoxI
			// 
			this->textBoxI->Location = System::Drawing::Point(1045, 295);
			this->textBoxI->Name = L"textBoxI";
			this->textBoxI->Size = System::Drawing::Size(100, 22);
			this->textBoxI->TabIndex = 19;
			this->textBoxI->Text = L"800";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(1041, 270);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(15, 19);
			this->label4->TabIndex = 18;
			this->label4->Text = L"I";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(1041, 220);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(91, 19);
			this->label5->TabIndex = 17;
			this->label5->Text = L"L, 10 ^ (-6)";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(1041, 170);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(21, 19);
			this->label6->TabIndex = 16;
			this->label6->Text = L"K";
			// 
			// textBoxL
			// 
			this->textBoxL->Location = System::Drawing::Point(1045, 245);
			this->textBoxL->Name = L"textBoxL";
			this->textBoxL->Size = System::Drawing::Size(100, 22);
			this->textBoxL->TabIndex = 15;
			this->textBoxL->Text = L"4";
			// 
			// textBoxK
			// 
			this->textBoxK->Location = System::Drawing::Point(1045, 195);
			this->textBoxK->Name = L"textBoxK";
			this->textBoxK->Size = System::Drawing::Size(100, 22);
			this->textBoxK->TabIndex = 14;
			this->textBoxK->Text = L"800";
			// 
			// textBoxThickness
			// 
			this->textBoxThickness->Location = System::Drawing::Point(1045, 345);
			this->textBoxThickness->Name = L"textBoxThickness";
			this->textBoxThickness->Size = System::Drawing::Size(100, 22);
			this->textBoxThickness->TabIndex = 21;
			this->textBoxThickness->Text = L"3";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(1041, 320);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(86, 19);
			this->label7->TabIndex = 20;
			this->label7->Text = L"l, 10 ^ (-6)";
			// 
			// launch
			// 
			this->launch->Location = System::Drawing::Point(1045, 609);
			this->launch->Name = L"launch";
			this->launch->Size = System::Drawing::Size(130, 42);
			this->launch->TabIndex = 22;
			this->launch->Text = L"«апуск";
			this->launch->UseVisualStyleBackColor = true;
			this->launch->Click += gcnew System::EventHandler(this, &MainWindow::launch_Click);
			// 
			// clear
			// 
			this->clear->Location = System::Drawing::Point(1045, 678);
			this->clear->Name = L"clear";
			this->clear->Size = System::Drawing::Size(130, 42);
			this->clear->TabIndex = 23;
			this->clear->Text = L"ќчистить";
			this->clear->UseVisualStyleBackColor = true;
			this->clear->Click += gcnew System::EventHandler(this, &MainWindow::clear_Click);
			// 
			// textBoxCurrK
			// 
			this->textBoxCurrK->Location = System::Drawing::Point(1045, 472);
			this->textBoxCurrK->Name = L"textBoxCurrK";
			this->textBoxCurrK->Size = System::Drawing::Size(100, 22);
			this->textBoxCurrK->TabIndex = 27;
			this->textBoxCurrK->Text = L"500";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(1041, 447);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(18, 19);
			this->label8->TabIndex = 26;
			this->label8->Text = L"k";
			// 
			// textBoxCurrI
			// 
			this->textBoxCurrI->Location = System::Drawing::Point(1045, 410);
			this->textBoxCurrI->Name = L"textBoxCurrI";
			this->textBoxCurrI->Size = System::Drawing::Size(100, 22);
			this->textBoxCurrI->TabIndex = 25;
			this->textBoxCurrI->Text = L"200";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(1041, 385);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(15, 19);
			this->label9->TabIndex = 24;
			this->label9->Text = L"i";
			// 
			// table
			// 
			this->table->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->table->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->table->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5
			});
			this->table->Enabled = false;
			this->table->Location = System::Drawing::Point(1192, 20);
			this->table->Name = L"table";
			this->table->RowHeadersWidth = 51;
			this->table->RowTemplate->Height = 24;
			this->table->Size = System::Drawing::Size(300, 700);
			this->table->TabIndex = 30;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"I";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->Width = 39;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"K";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->Width = 44;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"delta u(hx,ht/2)";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->Width = 121;
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"delta u(hx,ht/4)";
			this->dataGridViewTextBoxColumn4->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->Width = 121;
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"delta";
			this->dataGridViewTextBoxColumn5->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			this->dataGridViewTextBoxColumn5->Width = 66;
			// 
			// graphic
			// 
			chartArea1->Name = L"ChartArea1";
			this->graphic->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->graphic->Legends->Add(legend1);
			this->graphic->Location = System::Drawing::Point(12, 12);
			this->graphic->Name = L"graphic";
			this->graphic->Size = System::Drawing::Size(1000, 700);
			this->graphic->TabIndex = 31;
			this->graphic->Text = L"chart1";
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1532, 753);
			this->Controls->Add(this->graphic);
			this->Controls->Add(this->table);
			this->Controls->Add(this->textBoxCurrK);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBoxCurrI);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->clear);
			this->Controls->Add(this->launch);
			this->Controls->Add(this->textBoxThickness);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBoxI);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBoxL);
			this->Controls->Add(this->textBoxK);
			this->Controls->Add(this->textBoxT);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxLambda);
			this->Controls->Add(this->textBoxC);
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
	{}
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
		data = scheme(this->c, this->constLambda, this->T, this->K, this->L, this->I, this->l, currI, currK);
				
		//std::ifstream fin("valuesPython1.txt");
		//double size = data.second.size();
		//double value;
		//double sum = 0;
		//
		//for (double j = 0; j < size; j++)
		//{
		//	fin >> value;
		//	sum += pow((value - data.second[j]), 2);
		//	//std::cout << j << " " << value << " " << data.second[j];
		//	//std::cout << std::endl;
		//}
		//fin.close();
		//double MSE = sum / size;
		//std::cout << "MSE " << MSE << std::endl;

		Series^ series = gcnew Series(L"явна€ разностна€ схема, " + "I = " + I + " K = " + K + " " + currColorIndex);
		series->Color = nextColor;
		series->IsVisibleInLegend = true;
		series->IsXValueIndexed = true;
		series->ChartType = SeriesChartType::Line;
		this->graphic->Series->Add(series);
		for (double i = 0; i < data.first.size(); i++)
		{
			series->Points->AddXY(data.first[i], data.second[i]);
		}
		
		FillTable(data);
		
		std::cout << std::endl;

		ChartImageFormat imageFormat = ChartImageFormat::Png;
		this->graphic->SaveImage("image.png", imageFormat);
	}
	private: System::Void FillTable(std::pair<std::vector<double>, std::vector<double>> data)
	{
		std::pair<std::vector<double>, std::vector<double>> data2;
		data2 = scheme(this->c, this->constLambda, this->T, this->K, this->L, 2 * this->I, this->l, 2 * currI, currK);

		std::pair<std::vector<double>, std::vector<double>> data4;
		data4 = scheme(this->c, this->constLambda, this->T, this->K, this->L, 4 * this->I, this->l, 4 * currI, currK);

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