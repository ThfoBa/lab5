#pragma once
#include "Experience.h"
#include "Uspevaemost.h"
#include "Napravlenie.h"
#include "checkfilerashir.h"
#include <fstream>
using namespace std;

class Student {
	friend void getbonus(Napravlenie na);
	
public:
	Student(Experience e, Napravlenie n, Uspevaemost u);
	Student(int allfields);
	Student();
	void output();
	void input();
	static void printcounter();
	Student* get();
	Student& getadress();
	void editnazvanie(string nazvanie, string add);
	Student operator + (Student e1);
	Student& operator++(); //����������
	Student operator++(int); //�����������
	void tofile(ofstream& file, string filename);
	void getfromfile(ifstream& file, string filename);
private:
	static int counter;
	int id; //�������������� �����
	Experience exp; //���������� ��� �������� � ����
	Napravlenie nap; //�������� �����������
	Uspevaemost usp; //������������ ��������
};