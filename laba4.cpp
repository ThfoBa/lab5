#include "Student.h"
#include "checkfilerashir.h"
#include <conio.h>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <iostream>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int i, j;
	byte years = 10;
	byte akadem = 1;
	Experience exp3(years, akadem);
	string str = "Приборостроение и техника", fname = "test.txt";
	int elit = 1;
	int form = 2;
	Napravlenie nap3(str, elit, form);
	int bal1 = 45, bal2 = 20;
	Uspevaemost us3(bal2, 30, 70, 100, nap3);
	Student std, std3(exp3, nap3, us3), arr1[3], arr2[2][2];
	ofstream file;
	file.exceptions(ofstream::badbit | ofstream::failbit);
	try
	{
		if (!checkfilerashir(fname))
			throw exception("Использовано недопустимое расширение файла. Допустимое расширение: \".txt\".\n");
		file.open(fname, ios_base::app);
		std3.tofile(file);
		file.close();
	}
	catch (exception& ex1)
	{
		cout << ex1.what();
	}
	ifstream file1;
	file1.exceptions(ifstream::badbit | ifstream::failbit);
	try
	{
		if (!checkfilerashir(fname))
			throw exception("Использовано недопустимое расширение файла. Допустимое расширение: \".txt\".\n");;
		
		file1.open(fname);
		for (i = 0; i < 3; i++) {
			arr1[i].getfromfile(file1);
			arr1[i].output();
		}
		cout << endl;
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 2; j++) {
				arr2[i][j].getfromfile(file1);
				cout << "arr2[" << i << "]" << endl;
				arr2[i][j].output();
			}
		}
		file1.close();
	}
	catch (exception& ex2)
	{
		cout << ex2.what();
	}
	return 0;
}




