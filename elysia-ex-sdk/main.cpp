// CLI for external testing features.
#include "features.hpp"
#include "memory.hpp"
#include <iostream>
#include "stdlib.h"

int userChoice() 
{
	int ret;
	system("cls");
	std::cout << "assaultcube external trainer mm yeahh" << "\n";
	std::cout << "NUMBER TO TOGGLE | FEATURE | VALUE | STATE" << "\n";
	std::cout << "[1] Mod Ammo" << features::ammo << features::modAmmo << "\n";
	std::cout << "[2] Mod Health" << features::health << features::modHealth << "\n";
	std::cout << "[3] Mod Armor" << features::armor << features::modArmor << "\n";

	do 
	{
		std::cout << "input: ";
		std::cin >> ret;
	}
	while (reinterpret_cast<int>(ret) != 1 || 2 || 3);
}

void modValue(int choice) {
	switch(choice)
	{
		case 1{}
	}
}

int main()
{
	LPCWSTR targetProcess = L"";
	std::cout << "Hello, World!";
	return 0;
}