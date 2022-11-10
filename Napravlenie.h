#pragma once
#include <string>
#include <fstream>
using namespace std;

class Napravlenie
{
	friend void getbonus(Napravlenie na);
	
public:
	Napravlenie(string n, int e, int f);
	Napravlenie(int allfields);
	Napravlenie();
	void input();
	void output();
	void set(Napravlenie n);
	void editnazvanie(string nazvanie, string add);
	Napravlenie operator +(Napravlenie n1);
	Napravlenie& operator++(); //префиксный
	Napravlenie operator++(int); //постфиксный
	void tofile(ofstream& file);
	void getfromfile(ifstream& file);
private:
	string nazvanie; //название направления
	int formstudy; //форма обучения (платка/бюджет)
	int elite; //класс престижности направления (типа обычное и крутое)

};