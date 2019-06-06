#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int k, n, m, l, N, i, j;
	cout << "Введите k значений:\n";
	cin >> k;
	cout << "Введите n значений:\n";
	cin >> n;
	cout << "Введите m значений:\n";
	cin >> m;
	cout << "Введите l значений:\n";
	cin >> l;

	ofstream output;
	output.open("C:\\1.txt");
	output.is_open();

	for (int i = 0; i < k; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			for (int h = 0; h < m; h++) 
			{
				output << rand() % 25 << " ";
			}

			output << "\n";
		}
	}
	output.close();

	output.open("C:\\2.txt");
	output.is_open();

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int h = 0; h < l; h++)
			{
				output << rand() % 45 << " ";
			}

			output << "\n";
		}
	}
	output.close();

	ifstream input1("C:\\1.txt");
	ifstream input2("C:\\2.txt");
	output.open("C:\\3.txt");
	if (input1.is_open() && input2.is_open())
	{

		
		output.is_open();

		for (int z = 0; z < k; z++)
		{

			int** A = new int* [n];
			int** B = new int* [m];
			int** C = new int* [n];

			for (int i = 0; i < n; i++)
			{
				A[i] = new int[m];
				for (int j = 0; j < m; j++)
				{
					input1 >> A[i][j];
				}
			}

			


			for (int i = 0; i < m; i++)
			{
				B[i] = new int[m];
				for (int j = 0; j < l; j++)
				{
					input2 >> B[i][j];
				}
			}

			cout << "\n-Первая матрица-\n\n";
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					cout << A[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "\n----------\n\n";

			cout << "\n-Вторая матрица-\n\n";
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < l; j++)
				{
					cout << B[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "\n----------\n\n";
			
			
			cout << "\n-Итоговая матрица-\n\n";
			for (int r = 0; r < n; r++)
			{
				for (int i = 0; i < l; i++)
				{
					C[i] = new int[l];
					C[r][i] = 0;
					for (int j = 0; j < m; j++)
					{
						C[r][i] += A[r][j] * B[j][i];
						
					}
					output << C[r][i] << " ";
					cout << C[r][i] << " ";

				}
				output << "\n";
				cout << "\n";
			}
			output << "\n----------\n\n";
			cout << "\n----------\n\n";
			delete[] A, B, C;
		
		}
		output.close();
	}
	input1.close();
	input2.close();
}

