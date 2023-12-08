#include "MainWindow.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ParallelPrograming3::MainWindow form;
	Application::Run(% form);

	system("pause");

	return 0;
}

std::pair<std::vector<double>, std::vector<double>> scheme(System::String^% filename, double c, double constLambda, double T, int K, double L, int I, double l, int currI, int currK)
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

	for (int k = 0; k < K + 1; k++)
	{
		arrayT[k] = k * ht;
	}

	int halfI = (I + 1) / 2;
	int halfK = (K + 1) / 2;

	// Инициализация среды параллельных вычислений MPI.
	MPI_Init(NULL, NULL);

	// Получение ранга текущего процесса в группе запущенных приложений.
	// MPI_COMM_WORLD - коммуникатор, объединяющий все процессы параллельной программы.
	int rank = -1;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	// Получение количества процессов в группе.
	int count_processes = -1;
	MPI_Comm_size(MPI_COMM_WORLD, &count_processes);

	double starttime, endtime;
	starttime = MPI_Wtime();

	if (rank == 0)
	{
		std::vector<std::vector<double>> u1(K + 1, std::vector<double>(halfI + 1, 0));

		for (int i = 0; i <= halfI; i++)
		{
			u1[0][i] = 0;
			u1[1][i] = u1[0][i];
		}

		for (int k = 2; k < K + 1; k++)
		{
			u1[k][0] = sin(2 * PI * c * k * ht / constLambda);
		}

		for (int k = 1; k < K; k++)
		{
			for (int i = 1; i < halfI; i++)
			{
				u1[k + 1][i] = u1[k][i] * (2 - 2 * gamma - pow((c * ht * PI / l), 2)) + gamma * (u1[k][i + 1] + u1[k][i - 1]) - u1[k - 1][i];
			}

			double send = u1[k][halfI];
			MPI_Send(&send, 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);
			double recv;
			MPI_Recv(&recv, 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

			u1[k + 1][halfI] = u1[k][halfI] * (2 - 2 * gamma - pow((c * ht * PI / l), 2)) + gamma * (recv + u1[k][halfI - 1]) - u1[k - 1][halfI];
		}

		if (currI <= halfI)
		{
			for (int k = 0; k <= K; k++)
			{
				temp[k] = u1[k][currI];
			}
		}
		filename = filename + rank.ToString() + ".png";
	}
	else
	{
		std::vector<std::vector<double>> u2(K + 1, std::vector<double>(I - halfI, 0));

		for (int i = 0; i < I - halfI; i++)
		{
			u2[0][i] = 0;
			u2[1][i] = u2[0][i];
		}

		for (int k = 1; k < K; k++)
		{
			for (int i = I - halfI - 2; i > 0; i--)
			{
				u2[k + 1][i] = u2[k][i] * (2 - 2 * gamma - pow((c * ht * PI / l), 2)) + gamma * (u2[k][i + 1] + u2[k][i - 1]) - u2[k - 1][i];
			}

			double recv;
			MPI_Recv(&recv, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			double send = u2[k][0];
			MPI_Send(&send, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);

			u2[k + 1][0] = u2[k][0] * (2 - 2 * gamma - pow((c * ht * PI / l), 2)) + gamma * (u2[k][1] + recv) - u2[k - 1][0];

			u2[k + 1][I - halfI - 1] = u2[k + 1][I - halfI - 2];
		}

		if (currI > halfI)
		{
			int t = currI - halfI;
			for (int k = 0; k <= K; k++)
			{
				temp[k] = u2[k][t];
			}
		}
		filename = filename + rank.ToString() + ".png";
	}

	MPI_Barrier(MPI_COMM_WORLD);

	endtime = MPI_Wtime();
	printf("That took %f seconds in rank %d\n", endtime - starttime, rank);

	// Завершение работы среды параллельных вычислений MPI
	MPI_Finalize();

	return std::make_pair(arrayT, temp);
}