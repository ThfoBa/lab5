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
	Uspevaemost& operator++(); //����������
	Uspevaemost operator++(int); //�����������
	void tofile(ofstream& file, string filename);
	void getfromfile(ifstream& file, string filename);
private:
	int srball; //������� ���� �������� �� ���� ��������� 
	int minimum; //�����, ������ �������� ������������ ��������� ������
	int normal; //�����, ������ �������� ������������ ��������� ����������
	int high; //�����, ������ �������� ������������ ��������� �������
	Napravlenie na;
};