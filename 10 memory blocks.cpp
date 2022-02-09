#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	int act;
	int act_in3;
	int size[10] = { 0 };
	int size_b;
	int* blocks[10] = { 0 };
	bool exit = false;
	int block_num;
	do {
		cout << "______________________" << endl << "Выберите действие" << endl << "1.Показать статистику" << endl << "2.Выделить память" << endl << "3.Очистить память" << endl << "4.Выйти" << endl;
		cin >> act;
		if (act >= 1 && act <= 4) {
			switch (act) {
			case 1: cout << "Статистика:" << endl;
				for (int i = 0; i < 10; i++) {
					cout << "Блок" << " " << i + 1 << " " << "-" << " " << size[i] << "Mb" << endl;
				}
				break;
			case 2: cout << endl << "Введите номер блока, для которого хотите выделить память (от 1 до 10)" << endl;
				cin >> block_num;
				if (block_num >= 1 && block_num <= 10) {
					if (size[block_num - 1] == 0) {
						cout << "Введите размер памяти для блока" << " " << block_num << " " << "в мегабайтах" << endl;
						cin >> size_b;
						size[block_num - 1] = size_b;
						blocks[block_num - 1] = new int[size_b * 262144];
						for (int i = 0; i < size_b * 262144; i++) {
							*(blocks[block_num - 1] + i) = i;
						}
						cout << "Память для блока выделена!" << endl;
					}
					else {
						cout << "Блок занят, размер блока = " << size[block_num - 1] << endl;
					}
				}
				else {
					cout << "Такого блока нет" << endl;
				}
				break;
			case 3: cout << "1.Очистить определённый блок" << endl << "2.Очистить все блоки" << endl;
				cin >> act_in3;
				if (act_in3 >= 1 && act_in3 <= 2) {
					if (act_in3 == 1) {
						cout << "Введите номер блока, котороый хотите очистить (от 1 до 10)" << endl;
						cin >> block_num;
						if (block_num >= 1 && block_num <= 10) {
							if (size[block_num - 1] == 0) {
								cout << "Блок не имеет выделенной памяти" << endl;
							}
							else {
								delete[] blocks[block_num - 1];
								size[block_num - 1] = 0;
								cout << "Блок успешно очищен!" << endl;
							}
						}
						else {
							cout << "Такого блока нет" << endl;
						}
					}
					else {
						for (int i = 0; i < 10; i++) {
							delete[] blocks[i];
						}
						for (int i = 0; i < 10; i++) {
							size[i] = 0;
						}
						cout << "Все блоки успешно очищены!" << endl;
					}
				}
				else {
					cout << "Такого действия нет" << endl;
				}
				break;
			case 4: exit = true;
			}
		}
	} while (!exit);
}