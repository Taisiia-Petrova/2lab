#include <iostream>

#include <fstream>

#include <string>

using namespace std;

ofstream file("fout.txt");

struct cell

{

	int x, y, value;

};

//�������� �������

void clear(int **arr, int n)

{

	for (int i = 0; i < n; ++i)

	{

		arr[i] = new int[n];

		arr[0][i] = i;

		arr[i][0] = i;

	}

	for (int i = 1; i < n; ++i)

		for (int j = 1; j < n; ++j)

			arr[i][j] = -1;

}

//������� �������� ����������� ���������� ������

bool place(int **arr, int n, cell c)

{

	for (int i = 0; i < c.x; ++i)

	{

		if (c.value == arr[c.y][i]) return false;

	}

	for (int i = 0; i < c.y; ++i)

	{

		if (c.value == arr[i][c.x]) return false;

	}

	return true;

}

//���������� ������

void show(int **arr, int n)

{

	for (int i = 0; i < n; ++i)

	{

		for (int j = 0; j < n; ++j)

		{

			cout << arr[i][j] � ' ';

		}

		cout << endl;

	}

	cout << endl;

}

void show(int **arr, int n, ofstream &file)

{

	for (int i = 0; i < n; ++i)

	{

		for (int j = 0; j < n; ++j)

		{

			file << arr[i][j] << ' ';

		}

		file << endl;

	}

	file << endl;

}

//������� � �������� ������� ����������� ��������� �������

void create(int **arr, int n, cell c, long int &kol)

{
	if (!place(arr, n, c)) // �������� ����������� �����������

		return;

	arr[c.y][c.x] = c.value; //����� ��������� �������

							 //show(arr, n);

	if (n < 5) {

		show(arr, n, file);

	}

	cell new_c = c;

	++new_c.x;

	if (new_c.x == n) //������ �� ������ ���������

	{

		new_c.x = 1;

		++new_c.y;

		if (new_c.y == n) //������� �� ����� �����������

		{

			if (n < 5) {
				cout << "" << endl;
				show(arr, n);
				//show(arr, n, file);
			}

			++kol;

			arr[c.y][c.x] = -1;

			return;

		}

	}

	int i = 0;

	while (i != n)

	{

		new_c.value = (new_c.value + 1) % n;

		create(arr, n, new_c, kol); // �������� ������ �������

		++i;
	}


	arr[c.y][c.x] = -1;

	return;

}

int main()
{

	setlocale(LC_ALL, "Rus");

	int n, c = 0;

	long int kol = 0;

	cout << "�������� ������ ����� ������� ������. " << endl;

	cout << "1 - �� �������" << endl;

	cout << "2 - �� �����" << endl;

	cin >> c;
	if (c == 1)
	{
		cout << "������� n" << endl;

		cin >> n;

		while (!cin) {

			cout << "�� ������� �����. ��������� ��� ���." << endl;

			cin.clear();

			if (n < 0)

			{

				cout << "�� ����� ������������� �����" << endl;

				while (n < 0) {
					while (cin.get() != '\n');

					cin >> n;

				}

				cout << "������� ������ ������� �����" << endl;

				cin >> n;

			}

		}

		if (n >= 7)

		{

			cout << "��������, ����� ������� ������� �������. ";

			while (n >= 7) {

				cout << "������� ������ ��������" << endl;

				cin >> n;

			}

		}

		if (n < 7 && n>0)

		{

			int **arr = new int*[n];

			for (int i = 0; i < n; ++i)

			{

				clear(arr, n);

				create(arr, n, { 1,1,i }, kol);

			}

			cout << endl << "����� ����������� ��������� ���������: " << kol << endl;

			return 0;

		}
	}
	if (c == 2)
	{


		ifstream fin("fin.txt");

		if ((fin >> n) && n < 8 && n>2)
		{

			cout << "��������� ������ ���������� �������: " << n << endl;

			int **arr = new int*[n];

			for (int i = 0; i < n; ++i)

			{

				clear(arr, n);

				create(arr, n, { 1,1,i }, kol);

			}

			cout << endl << "����� ����������� ��������� ���������: " << kol << endl;

		}
	}

	system("pause");

	return 0;
}