#pragma once
#include <fstream>
using namespace std;

class StdException : public exception {
public:
	StdException(const char* const& message);
};