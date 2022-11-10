#include "Uspevaemost.h"
#include "Napravlenie.h"
#include <iostream>

void getbonus(Napravlenie na)
{
	if (na.elite == 1)
		cout << "Бонус не положен";
	else
		cout << "Положен бонус в размере 2000";
}