#pragma once
#include "Napravlenie.h"
#include <fstream>
using namespace std;
class Uspevaemost
{
	friend void getbonus(Napravlenie na);
	
public:
	Uspevaemost(int s, int m, int n, int h, Napravlenie nam);
	Uspevaemost(int allfields);
	Uspevaemost();
	void input();
	void output();
	int getstip();
	Uspevaemost operator +(Uspevaemost u1);
	Uspevaemost& operator++(); //префиксный
	Uspevaemost operator++(int); //постфиксный
	void tofile(ofstream& file);
	void getfromfile(ifstream& file);
private:
	int srball; //средний балл студента по всем предметам 
	int minimum; //порог, меньше которого успеваемость считается низкой
	int normal; //порог, меньше которого успеваемость считается нормальной
	int high; //порог, меньше которого успеваемость считается высокой
	Napravlenie na;
};