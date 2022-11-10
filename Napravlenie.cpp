#include "Napravlenie.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

//����������� ������ �� ����� �����������
Napravlenie::Napravlenie(string nazvanie, int elite, int formstudy) {
	this->nazvanie = nazvanie;
	if ((elite == 1)||(elite == 2))
		this->elite = elite;
	else {
		cout << "������� ������������ �������� elite." << endl;
		this->elite = 1;
	}
	if ((formstudy == 1) || (formstudy == 2))
		this->formstudy = formstudy;
	else {
		cout << "������� ������������ �������� formstudy." << endl;
		this->formstudy = 1;
	}
}

//����������� ������ � ����� ����������
Napravlenie::Napravlenie(int allfields) {
		nazvanie = to_string(allfields);
		elite = allfields;
		formstudy = allfields;
}

//����������� ������ ��� ����������
Napravlenie::Napravlenie() {
	nazvanie = "";
	elite = 1;
	formstudy = 1;
}

//����� ��������� �������� 
void Napravlenie::set(Napravlenie n) {
	this->nazvanie = n.nazvanie;
	this->elite = n.elite;
	this->formstudy = n.formstudy;
}

//����� ����� ������ jobtitle
void Napravlenie::input() {
	string nazvanie;
	int elite, formstudy;
	cout << "\n������� �������� ������ �����������: " << endl;
	cin >> nazvanie;
	cout << "������� ����� ������������ ������ ����������� (1 - �������, 2 - �������): " << endl;
	cin >> elite;
	cout << "������� ����� �������� (1 - �������, 2 - ������): " << endl;
	cin >> formstudy;
	Napravlenie n(nazvanie, elite, formstudy);
	this->set(n);
}

//����� ������
void Napravlenie::output() {
	cout << "�����������: " << nazvanie << endl;
	if (elite == 1)
		cout << "������������ �����������: �������" << endl;
	else
		cout << "������������ �����������: �������" << endl;
	if (formstudy == 1)
		cout << "����� ��������: �������" << endl;
	else
		cout << "����� ��������: ������" << endl;
}

//����� ��� �������������� �������� �����������
void Napravlenie::editnazvanie(string nazvanie, string add) {
	int i;
	//��������� �����
	stringstream ss(this->nazvanie);
	//������ ���������� ���� � ������
	int n = count(this->nazvanie.begin(), this->nazvanie.end(), ' ') + 1;
	string* words = new string[n];
	this->nazvanie = "";
	for (i = 0; i < n; i++) {
		ss >> *(words + i);
	}
	for (i = 0; i < n; i++) {
		//���� ������ ����������
		if (!(*(words + i)).compare(nazvanie)) {
			this->nazvanie += add + " ";
		}
		this->nazvanie += *(words + i) + " ";
	}
}


//���������� ��������� +
Napravlenie Napravlenie::operator + (Napravlenie n1) {
	elite += n1.elite;
	formstudy += n1.formstudy;
	nazvanie += n1.nazvanie;
	return *this;
}

//���������� ��������� ++ ����������
Napravlenie& Napravlenie::operator++() {
	this->elite += 1;
	this->formstudy += 1;
	return *this;
}

//���������� ��������� ++ �����������
Napravlenie Napravlenie::operator++(int) {
	Napravlenie temp = *this;
	++* this;
	return temp;
}

//����� ������ � ����
void Napravlenie::tofile(ofstream& file) {
	file << nazvanie << "\t";
	file << formstudy << "\t";
	file << elite << "\t";
	
}

//����� ������ �� �����
void Napravlenie::getfromfile(ifstream& file) {
	int flag = 0;
	string buff;
	try {
		file >> nazvanie;
		while (!flag) {
			file >> buff;
			if (buff[0] >= '0' && buff[0] <= '9') {
				formstudy = stoi(buff);
				flag = 1;
			}
			else {
				nazvanie += " ";
				nazvanie += buff;
			}
		}
		file >> elite;
	}
	catch (exception& e) {
		throw exception("� ����� ������������ ������ ��� ������.\n");
	}
}