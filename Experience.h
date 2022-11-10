#pragma once
#include <fstream>
using namespace std;
class Experience
{
	
public:
	Experience(int s, int a);
	Experience(int x);
	Experience();
	void input();
	void output();
	float allexperience();
	void set(Experience e);
	Experience operator +(Experience e1);
	Experience& operator++(); //префиксный
	Experience operator++(int); //постфиксный
	void tofile(ofstream& file);
	void getfromfile(ifstream& file);
private:
	int studyyears; //кол-во реальных лет обучения
	int akadem; //кол-во лет в академе
};