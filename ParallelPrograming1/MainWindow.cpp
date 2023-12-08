#include "MainWindow.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

int main(array<String^>^ args) 
{ 
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ParallelPrograming1::MainWindow form;
	Application::Run(% form);

	return 0;
}

std::pair<std::vector<double>, std::vector<double>> scheme(double c, double constLambda, double T, int K, double L, int I, double l, int currI, int currK)
{
	c *= pow(10, 14);
	constLambda *= pow(10, -6);
	T *= pow(10, -20);
	L *= pow(10, -6);
	l *= pow(10, -6);

	double ht = T / K;
	double hz = L / I;

	double gamma = pow((c * ht / hz), 2);

	std::vector<double> temp(K + 1, 0);
	std::vector<double> arrayT(K + 1, 0);
	std::vector<std::vector<double>> u(K + 1, std::vector<double>(I + 1, 0));

	for (int k = 0; k < K + 1; k++)
	{
		arrayT[k] = k * ht;
	}

	for (int i = 0; i <= I; i++)
	{
		u[0][i] = 0;
		u[1][i] = u[0][i];
	}

	for (int k = 2; k < K + 1; k++)
	{
		u[k][0] = sin(2 * PI * c * k * ht / constLambda);
	}

	//Последовательный вариант программы
	auto start = std::chrono::high_resolution_clock::now();
	//__pragma(loop(no_vector))
	for (int k = 1; k < K; k++)
	{
		//__pragma(loop(no_vector))
		for (int i = 1; i < I; i++)
		{
			u[k + 1][i] = u[k][i] * (2 - 2 * gamma - pow((c * ht * PI / l), 2)) + gamma * (u[k][i + 1] + u[k][i - 1]) - u[k - 1][i];
		}
		u[k + 1][I] = u[k + 1][I - 1];
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	// Выводим затраченное время в консоль
	std::cout << "Sequential version was completed in " << duration << " milliseconds" << std::endl;

	//	// Параллельный вариант работы программы openmp
	//	
	//	auto start = std::chrono::high_resolution_clock::now();
	//
	//	for (int k = 1; k < K; k++)
	//	{
	//#pragma omp parallel for
	//		for (int i = 1; i < I; i++)
	//		{
	//			u[k + 1][i] = u[k][i] * (2 - 2 * gamma - pow((c * ht * PI / l), 2)) + gamma * (u[k][i + 1] + u[k][i - 1]) - u[k - 1][i];
	//		}
	//		u[k + 1][I] = u[k + 1][I - 1];
	//	}
	//	
	//	auto end = std::chrono::high_resolution_clock::now();
	//	
	//	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	//	
	//	// Выводим затраченное время в консоль
	//	std::cout << "Parallel version was completed in " << duration << " milliseconds" << std::endl;

	for (int k = 0; k <= K; k++)
	{
		temp[k] = u[k][currI];
	}

	return std::make_pair(arrayT, temp);
}	