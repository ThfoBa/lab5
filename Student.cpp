#include "Student.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>

int Student::counter = 0;
//����������� ������ �� ����� �����������
Student::Student(Experience e, Napravlenie n, Uspevaemost u) {
	counter++;
	id = counter;
	exp = e;
	nap = n;
	usp = u;
}

//����������� ������ � ����� ����������
Student::Student(int allfields) {
	counter++;
	id = counter;
	Experience e(allfields);
	Napravlenie n(allfields);
	Uspevaemost u(allfields);
	exp = e;
	nap = n;
	usp = u;
	
	
}

//����������� ������ ��� ����������
Student::Student() {
	counter++;
	id = counter;
	Experience e;
	Uspevaemost u;
	Napravlenie n;
	exp = e;
	nap = n;
	usp = u;
}

//����� ������ 
void Student::output() {
	cout << "ID: " << this->id << endl;
	exp.output();
	nap.output();
	usp.output();
	getbonus(nap);
	cout << "\n���������: " << usp.getstip() << endl;
}

//����� ����� 
void Student::input() {
	exp.input();
	nap.input();
	while (getchar() != '\n');
	usp.input();
}

//����� ������ �������� ���������� ���������
void Student::printcounter() {
	cout << "���������� ���������: " << counter << endl;
}

//�����, ������������ �������� ����� ���������
Student* Student::get() {
	return this;
}

//�����, ������������ �������� ����� ������
Student& Student::getadress() {
	return *this;
}

//����� ��������� � ������ ����������� ������
void Student::editnazvanie(string nazvanie, string add) {
	nap.editnazvanie(nazvanie, add);
}

//���������� ��������� +
Student Student::operator + (Student e1) {
	exp = exp + e1.exp;
	nap = nap + e1.nap;
	usp = usp + e1.usp;
	return *this;
}

//���������� ��������� ++ ����������
Student& Student::operator++() {
	this->exp++;
	this->nap++;
	this->usp++;
	return *this;
}

//���������� ��������� ++ �����������
Student Student::operator++(int) {
	Student temp = *this;
	++* this;
	return temp;
}

//����� ������ � ����
void Student::tofile(ofstream& file) {
	file << id << "\t";
	exp.tofile(file);
	nap.tofile(file);
	usp.tofile(file);
}

//����� ������ �� �����
void Student::getfromfile(ifstream& file) {
	try {
		file >> id;
		exp.getfromfile(file);
		nap.getfromfile(file);
		usp.getfromfile(file);
		throw string("� ����� ������������ ������ ��� ������.");
	}
	catch (string e) {
		cout << "Error: " << e << endl;
	}
}