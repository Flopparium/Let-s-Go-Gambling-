#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <conio.h>
using namespace std;

int main()
{
	vector<int> slots = { 0,0,0 };
	char inp;
	int code, coins = 10;
	cout << "PRESS R TO PLAY\n";
	cout << " _____ " << "\n";
	cout << "|" << slots[0] << "|" << slots[1] << "|" << slots[2] << "|\n";
	cout << "|_____|\n";
	while (true) {
		inp = _getch();
		code = static_cast<int>(inp);
		if (inp == 114) {
			coins--;
			for (int i = 0; i < 20; i++) {
				system("cls");
				slots[0] = rand() % 10;
				slots[1] = rand() % 10;
				slots[2] = rand() % 10;
				if (coins > 999) {
					coins = 999;
				}
				cout << "Coins: " << coins << "\n";
				cout << " _____ " << "\n";
				cout << "|" << slots[0] << "|" << slots[1] << "|" << slots[2] << "|\n";
				cout << "|_____|\n";
				if (slots[0] == slots[1] && slots[1] == slots[2]) {
					if (slots[0] == 7) {
						coins += 20;
						cout << "!JACKPOT!\n";
					}
					else if (slots[0] == 6) {
						coins += 6;
					}
					else coins += 5;
					break;
				}
			}
		}
		if (inp == 101) return 0;
		if (coins <= 0) {
			cout << "!GAME OVER!";
			return 0;
		}
		if (coins >= 999) {
			cout << "!YOU WIN!";
			return 0;
		}
	}
	return 0;
}