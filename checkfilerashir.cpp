//метод проверки расширения файла
#include "checkfilerashir.h"
using namespace std;

bool checkfilerashir(string filename) {
	if (filename[filename.length() - 1] == 't' && \
		filename[filename.length() - 2] == 'x' && \
		filename[filename.length() - 3] == 't' && \
		filename[filename.length() - 4] == '.')
		return 1;
	else
		return 0;
}