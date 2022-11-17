#include "Experience.h"
#include "checkfilerashir.h"
#include <iostream>
#include <fstream>
using namespace std;

//конструктор класса со всеми параметрами
Experience::Experience(int studyyears, int akadem) {
	if (studyyears >= 0)
		this->studyyears = studyyears;
	else {
		cout << "Указано недопустимое значение studyyears." << endl;
		this->studyyears = 0;
	}
	if (akadem >= 0)
		this->akadem = akadem;
	else {
		cout << "Указано недопустимое значение akadem." << endl;
		this->akadem = 0;
	}
}

//конструктор класса с одним параметром
Experience::Experience(int allfields) {
	studyyears = allfields;
	akadem = allfields;
}
	
	

//конструктор класса без параметров
Experience::Experience() {
	studyyears = 0;
	akadem = 0;
}

//метод ввода 
void Experience::input() {
	int studyyears, akadem;
	cout << "\nВведите количество полных лет обучения: " << endl;
	cin >> studyyears;
	cout << "Введите количество лет, проведённых в академическом отпуске: " << endl;
	cin >> akadem;
	Experience e(studyyears, akadem);
	this->set(e);
}

//метод вывода
void Experience::output() {
	cout << "Количество лет обучения: " << studyyears << endl;
	cout << "Количество лет в академическом отпуске: " << akadem << endl;
	cout << "Количество лет, проведённых в вузе всего: " << allexperience() << endl;
}

//метод возвращающий общее время, проведенное в вузе
float Experience::allexperience() {
	int all;
	all = studyyears;
	all += akadem;
	return all;
};

//метод установки значений
void Experience::set(Experience e) {
	this->studyyears = e.studyyears;
	this->akadem = e.akadem;
}

//перегрузка оператора +
Experience Experience::operator + (Experience e1) {
	studyyears += e1.studyyears;
	akadem += e1.akadem;
	return *this;
}

//перегрузка оператора ++ префиксный
Experience& Experience::operator++() {
	this->studyyears += 1;
	this->akadem += 1;
	return *this;
}

//перегрузка оператора ++ постфиксный
Experience Experience::operator++(int) {
	Experience temp = *this;
	++* this;
	return temp;
}

//метод записи в файл
void Experience::tofile(ofstream& file, string filename) {
	if (!checkfilerashir(filename))
		throw exception("Использовано недопустимое расширение файла. Допустимое расширение: \".txt\".\n");
	file << studyyears << "\t";
	file << akadem << "\t";
}

//метод чтения из файла
void Experience::getfromfile(ifstream& file, string filename) {
	if (!checkfilerashir(filename))
		throw exception("Использовано недопустимое расширение файла. Допустимое расширение: \".txt\".\n");
	try {
		file >> studyyears;
		file >> akadem;
	}
	catch (exception& e) {
		throw exception("В файле недостаточно данных для записи  или неверно указано имя файла.\n");
	}
}