#include<iostream>
#include<fstream>
using namespace std;

void Input(int*& a, int& n)
{
	ifstream f;
	
	f.open("data.txt", fstream::in);
	
	if (f.fail())
	{
		cout << "[ERROR] File khong ton tai!";
		
		return;
	}
	
	f >> n;
	
	a = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		f.ignore();
		f >> a[i];
	}
	
	f.close();
	
	cout << "Mang da duoc tao tu file.";
}

void Output(int* a, int n)
{
	ofstream f;
	
	f.open("data.txt", fstream::app);
	
	if (f.fail())
	{
		cout << "[ERROR] File khong ton tai!";
		
		return;
	}
	
	f << endl;
	f << "Mang sau khi sap xep: ";
	
	for (int i = 0; i < n; i++)
		f << a[i] << "    ";
		
	cout << "\nMang da sap xep duoc ghi vao file.";
	cout << "\nHay kiem tra file de xem ket qua.";
}

void InterchangeSort(int* List, int num)
{
	for (int i = 0; i < num - 1; i++)
		for (int j = i; j < num; j++)
			if (List[i] > List[j])
				swap(List[i], List[j]);
}

void InsertionSort(int* List, int num)
{
	for (int i = 1; i < num; i++)
	{
		int e = List[i];
		int k;
		
		for (k = i - 1; k > -1; k--)
		{
			if (List[k] < e) break;
			
			List[k + 1] = List[k];
		}
		
		List[k + 1] = e;
	}
}

void SelectionSort(int* List, int num)
{
	int min;
	
	for (int i = 0; i < num; i++)
	{
		min = i;
		
		for (int j = i + 1; j < num; j++)
			if (List[j] < List[min])
				min = j;
				
		swap(List[i], List[min]);
	}
}

void Xuat(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "    ";
}

int main()
{
	int* A;
	int n, i;
	
	Input(A, n);
	
	cout << "\nMang: ";
	Xuat(A, n);
	
	cout << "\n 1. InterchangeSort  \n";
	cout << " 2. SelectionSort   \n";
	cout << " 3. InsertionSort   \n";
	
	cout << "Chon loai sap xep: ";
	cin >> i;
	
	switch (i)
	{
		case 1:
		{
			cout << "\n___InterchangeSort___\n";
			InterchangeSort(A, n);
			
			break;
		}
	
		case 2:
		{
			cout << "\n___SelectionSort___\n";
			SelectionSort(A, n);
			
			break;
		}
	
		case 3:
		{
			cout << "\n___InsertionSort___\n";
			InsertionSort(A, n);
			
			break;
		}
		
		default:
		{
			cout << "\nLoai sap xep chua duoc thiet lap.\n";
			
			break;
		}
	}
	
	if (i <= 3)
	{
		cout << "\nMang sau khi sap xep: ";
		
		Xuat(A, n);
		Output(A, n);
	}
	
	return 0;
}