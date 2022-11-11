#include "Napravlenie.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

//конструктор класса со всеми параметрами
Napravlenie::Napravlenie(string nazvanie, int elite, int formstudy) {
	this->nazvanie = nazvanie;
	if ((elite == 1)||(elite == 2))
		this->elite = elite;
	else {
		cout << "Указано недопустимое значение elite." << endl;
		this->elite = 1;
	}
	if ((formstudy == 1) || (formstudy == 2))
		this->formstudy = formstudy;
	else {
		cout << "Указано недопустимое значение formstudy." << endl;
		this->formstudy = 1;
	}
}

//конструктор класса с одним параметром
Napravlenie::Napravlenie(int allfields) {
		nazvanie = to_string(allfields);
		elite = allfields;
		formstudy = allfields;
}

//конструктор класса без параметров
Napravlenie::Napravlenie() {
	nazvanie = "";
	elite = 1;
	formstudy = 1;
}

//метод установки значений 
void Napravlenie::set(Napravlenie n) {
	this->nazvanie = n.nazvanie;
	this->elite = n.elite;
	this->formstudy = n.formstudy;
}

//метод ввода класса jobtitle
void Napravlenie::input() {
	string nazvanie;
	int elite, formstudy;
	cout << "\nВведите название вашего направления: " << endl;
	cin >> nazvanie;
	cout << "Введите класс престижности вашего направления (1 - обычный, 2 - высокий): " << endl;
	cin >> elite;
	cout << "Введите форму обучения (1 - платное, 2 - бюджет): " << endl;
	cin >> formstudy;
	Napravlenie n(nazvanie, elite, formstudy);
	this->set(n);
}

//метод вывода
void Napravlenie::output() {
	cout << "Направление: " << nazvanie << endl;
	if (elite == 1)
		cout << "Престижность направления: Обычная" << endl;
	else
		cout << "Престижность направления: Высокая" << endl;
	if (formstudy == 1)
		cout << "Форма обучения: Платное" << endl;
	else
		cout << "Форма обучения: Бюджет" << endl;
}

//метод для редактирования названия направления
void Napravlenie::editnazvanie(string nazvanie, string add) {
	int i;
	//строковый поток
	stringstream ss(this->nazvanie);
	//посчет количества слов в строке
	int n = count(this->nazvanie.begin(), this->nazvanie.end(), ' ') + 1;
	string* words = new string[n];
	this->nazvanie = "";
	for (i = 0; i < n; i++) {
		ss >> *(words + i);
	}
	for (i = 0; i < n; i++) {
		//если строки одинаковые
		if (!(*(words + i)).compare(nazvanie)) {
			this->nazvanie += add + " ";
		}
		this->nazvanie += *(words + i) + " ";
	}
}


//перегрузка оператора +
Napravlenie Napravlenie::operator + (Napravlenie n1) {
	elite += n1.elite;
	formstudy += n1.formstudy;
	nazvanie += n1.nazvanie;
	return *this;
}

//перегрузка оператора ++ префиксный
Napravlenie& Napravlenie::operator++() {
	this->elite += 1;
	this->formstudy += 1;
	return *this;
}

//перегрузка оператора ++ постфиксный
Napravlenie Napravlenie::operator++(int) {
	Napravlenie temp = *this;
	++* this;
	return temp;
}

//метод записи в файл
void Napravlenie::tofile(ofstream& file) {
	file << nazvanie << "\t";
	file << formstudy << "\t";
	file << elite << "\t";
	
}

//метод чтения из файла
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
		throw string("В файле недостаточно данных для записи.");
	}
	catch (string e) {
		cout << "Error: " << e << endl;
	}
	
}