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
	Napravlenie& operator++(); //����������
	Napravlenie operator++(int); //�����������
	void tofile(ofstream& file);
	void getfromfile(ifstream& file);
private:
	string nazvanie; //�������� �����������
	int formstudy; //����� �������� (������/������)
	int elite; //����� ������������ ����������� (���� ������� � ������)

};