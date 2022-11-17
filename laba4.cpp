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
	int years = 10;
	int akadem = 1;
	Experience exp3(years, akadem);
	string str = "Приборостроение и техника", fname = "test.txt";
	int elit = 1;
	int form = 2;
	Napravlenie nap3(str, elit, form);
	int bal1 = 45, bal2 = 20;
	Uspevaemost us3(bal2, 30, 70, 100, nap3);
	Student arr2[2][2], arr1[3]{
		Student(exp3++,nap3++,us3++),
		Student(exp3++,nap3++,us3++),
		Student(exp3++,nap3++,us3++)
	};
	ofstream file;
	file.exceptions(ofstream::badbit | ofstream::failbit);
	try
	{
		file.open(fname, ios_base::app);
		for (i = 0; i < 3; i++) {
			arr1[i].tofile(file, fname);
		}
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
		file1.open(fname);
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 2; j++) {
				arr2[i][j].getfromfile(file1,fname);
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




