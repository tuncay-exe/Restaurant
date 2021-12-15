#include <iostream>
#include <iomanip>
#include<istream>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <string>
#include <vector>
using std::string;
enum MOVEMENT
{
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77
};

void printSlow(string word) {
	for (int i = 0; i < word.length(); i++)
	{
		std::cout << word[i];
		Sleep(50);
	}
}

class Sorter {
public:
	// silende 0 qoy
	bool sortVector(std::vector<string>& newVector, short index, string wordapp = "") noexcept {
		newVector.push_back("");
		string word = newVector[index];

		for (short i = 0; i < word.size(); i++)
		{
			if (word[i] == wordapp[0]) {
				return 0;
			}
		}

		word.append(wordapp);
		bool stop = 1;

		for (short i = 0; i < newVector[index].size() && stop; i++)
		{
			stop = 0;
			for (short j = i; j < newVector[index].size(); j++)
			{
				if (word[i] > word[j]) {
					std::swap(word[i], word[j]);
					stop = 1;
				}
			}
		}

		newVector[index] = word;
		return 1;
	}
};

class PrintVisual
{
public:
	short visualChoose(short& PageChoose)noexcept {
		short oldPageChoose = 0;
		short UserChoose = 0;
		short i = 8;
		string arrow = ">========>> ";
		string line = "           ";
		string* choose = new string[8]{};
		string* chooses = new string[8]{};
		while (--i)
		{
			choose[i] = line;
			chooses[i] = " ";
		}
		choose[0] = line;
		chooses[0] = " ";
		while (UserChoose != 13)
		{
			system("cls");
			std::cout << "\n .-\"-._,-'_`-._,-'_`-._,-'_`-._,-'_`-,_,-'_`-,_,-'_`-,_,-'_`-,_,-'_`-,.";
			std::cout << "\n(  ,-'_,-<.>-'_,-<.>-'_,-<.>-'_,-<.>-'_,-<.>-'_,-<.>-'_,-<.>-'_,-~-} ;.";
			std::cout << "\n \\ \\.'_>-._`-<_>-._`-<_>-._`-<_>-._`-<_>-._`-<_>-._`-<_>-._`-._~--. \\ .";
			std::cout << "\n /\\ \\/ ,-' `-._,-' `-._,-' `-._,-' `-._,-' `-._,-' `-._,-' `-._`./ \\ \\ .";
			std::cout << "\n( (`/ /                                                        `/ /.) ) .";
			std::cout << "\n \\ \\ / \\   <RESTAURANT>                                        / / \\ / .";
			std::cout << "\n  \\ \\') )      " << choose[0] << " Create New Food" << chooses[0] << "                   ( (,\\ \\ .";
			std::cout << "\n / \\ / /                                                       \\ / \\ \\ .";
			std::cout << "\n( (`/ /        " << choose[1] << " Create New Ing" << chooses[1] << "                      / /.) ) .";
			std::cout << "\n \\ \\ / \\                                                       / / \\ / .";
			std::cout << "\n  \\ \\') )      " << choose[2] << " Delete Food" << chooses[2] << "                       ( (,\\ \\ .";
			std::cout << "\n / \\ / /                                                       \\ / \\ \\ .";
			std::cout << "\n( (`/ /        " << choose[3] << " Add Ing To Food" << chooses[3] << "                     / /.) ) .";
			std::cout << "\n \\ \\ / \\                                                       / / \\ / .";
			std::cout << "\n  \\ \\') )      " << choose[4] << " Delete Ing From Food" << chooses[4] << "              ( (,\\ \\ .";
			std::cout << "\n / \\ / /                                                       \\ / \\ \\ .";
			std::cout << "\n( ( / /        " << choose[5] << " Change Food's Ing Cook Size" << chooses[5] << "         / /.) ) .";
			std::cout << "\n \\ \\ / \\                                                       / / \\ /.";
			std::cout << "\n  \\ \\') )      " << choose[6] << " Change Stock size" << chooses[6] << "                 ( (,\\ \\ .";
			std::cout << "\n / \\ / /                                                       \\ / \\ \\ .";
			std::cout << "\n( ( / /         " << choose[7] << "Change Price" << chooses[7] << "                        / /.) ) .";
			std::cout << "\n \\ \\ / \\       _       _       _       _       _       _       / / \\ /.";
			std::cout << "\n  \\ `.\\ `-._,-'_`-._,-'_`-._,-'_`-._,-'_`-._,-'_`-._,-'_`-._,-'_/,\\ \\ .";
			std::cout << "\n ( `. `,~-._`-<,>-._`-<,>-._`-<,>-._`-<,>-._`-<,>-._`-<,>-._`-=,' ,\\ \\ .";
			std::cout << "\n  `. `'_,-<_>-'_,-<_>-'_,-<_>-'_,-<_>-'_,-<_>-'_,-<_>-'_,-<_>-'_,\"-' ; .";
			std::cout << "\n    `-' `-._,-' `-._,-' `-._,-' `-._,-' `-._,-' `-._,-' `-._,-' `-.-' .";
			UserChoose = _getch();
			if (UserChoose == 27)
				return -1;
			if (UserChoose == 224) {
				UserChoose = _getch();
				switch (UserChoose)
				{
				case UP:
					if (PageChoose > 0)
						PageChoose--;
					else
						PageChoose = 7;
					break;
				case DOWN:
					if (PageChoose < 7)
						PageChoose++;
					else
						PageChoose = 0;
					break;
				default:
					break;
				}
			}
			choose[oldPageChoose] = line;
			choose[PageChoose] = arrow;
			chooses[oldPageChoose] = " ";
			chooses[PageChoose] = "";
			oldPageChoose = PageChoose;
		}
		return 1;
	}
	void AdminUserLogo(short Choose) noexcept {
		if (Choose) {
			std::cout << "\n .--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--.";
			std::cout << "\n/ .. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\";
			std::cout << "\n\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/ /";
			std::cout << "\n \\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /";
			std::cout << "\n / /\\/ /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /\\/ /\\";
			std::cout << "\n/ /\\ \\/`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'\\ \\/\\ \\";
			std::cout << "\n\\ \\/\\ \\                                                    /\\ \\/ /";
			std::cout << "\n \\/ /\\ \\           _        _             _               / /\\/ /";
			std::cout << "\n / /\\/ /          /_\\    __| | _ __ ___  (_) _ __         \\ \\/ /\\";
			std::cout << "\n/ /\\ \\/          //_\\\\  / _` || '_ ` _ \\ | || '_ \\         \\ \\/\\ \\";
			std::cout << "\n\\ \\/\\ \\         /  _  \\| (_| || | | | | || || | | |        /\\ \\/ /";
			std::cout << "\n \\/ /\\ \\        \\_/ \\_/ \\__,_||_| |_| |_||_||_| |_|       / /\\/ /";
			std::cout << "\n / /\\/ /                                                  \\ \\/ /\\";
			std::cout << "\n/ /\\ \\/                                                    \\ \\/\\ \\";
			std::cout << "\n\\ \\/\\ \\.--..--..--..--..--..--..--..--..--..--..--..--..--./\\ \\/ /";
			std::cout << "\n \\/ /\\/ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ /\\/ /";
			std::cout << "\n / /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\";
			std::cout << "\n/ /\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\";
			std::cout << "\n\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `' /";
			std::cout << "\n `--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'";
			return;
		}
		std::cout << "\n .--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--.";
		std::cout << "\n/ .. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\";
		std::cout << "\n\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/ /";
		std::cout << "\n \\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /";
		std::cout << "\n / /\\/ /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /\\/ /\\";
		std::cout << "\n/ /\\ \\/`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'\\ \\/\\ \\";
		std::cout << "\n\\ \\/\\ \\                                                    /\\ \\/ /";
		std::cout << "\n \\/ /\\ \\                                                  / /\\/ /";
		std::cout << "\n / /\\/ /             /\\ /\\  ___   ___  _ __               \\ \\/ /\\";
		std::cout << "\n/ /\\ \\/             / / \\ \\/ __| / _ \\| '__|               \\ \\/\\ \\";
		std::cout << "\n\\ \\/\\ \\             \\ \\_/ /\\__ \\|  __/| |                  /\\ \\/ /";
		std::cout << "\n \\/ /\\ \\             \\___/ |___/ \\___||_|                 / /\\/ /";
		std::cout << "\n / /\\/ /                                                  \\ \\/ /\\";
		std::cout << "\n/ /\\ \\/                                                    \\ \\/\\ \\";
		std::cout << "\n\\ \\/\\ \\.--..--..--..--..--..--..--..--..--..--..--..--..--./\\ \\/ /";
		std::cout << "\n \\/ /\\/ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ /\\/ /";
		std::cout << "\n / /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\";
		std::cout << "\n/ /\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\";
		std::cout << "\n\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `' /";
		std::cout << "\n `--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'";
	}
	void menuBuy(short choose) {
		if (choose) {
			std::cout << "\n___  ___";
			std::cout << "\n|  \\/  |";
			std::cout << "\n| .  . | ___ _ __  _   _";
			std::cout << "\n| |\\/| |/ _ \\ '_ \\| | | |";
			std::cout << "\n| |  | |  __/ | | | |_| |";
			std::cout << "\n\\_|  |_/\\___|_| |_|\\__,_|";
			return;
		}
		std::cout << "\n______";
		std::cout << "\n| ___ \\";
		std::cout << "\n| |_/ /_   _ _   _";
		std::cout << "\n| ___ \\ | | | | | |";
		std::cout << "\n| |_/ / |_| | |_| |";
		std::cout << "\n\\____/ \\__,_|\\__, |";
		std::cout << "\n              __/ |";
		std::cout << "\n             |___/";
	}
	short Menu(std::vector<string> name, short size, short chooseU) noexcept {
		short PageChoose = 0;
		short oldPageChoose = 0;
		short UserChoose = 0;
		short i = 7;
		size--;
		string* arrow = new string[9]{ ">>","  ","  ","  ", "  ","  ","  ","  ","  " };
		while (UserChoose != 13)
		{
			system("cls");
			std::cout << "\n   ______________________________";
			std::cout << "\n / \\                             \\.";
			std::cout << "\n|   |                            |.";
			std::cout << "\n \\_ |                            |.";
			std::cout << "\n    |  " << arrow[0] << std::setw(24) << std::left << name[0] << "|.";
			std::cout << "\n    |  " << arrow[1] << std::setw(24) << std::left << name[1] << "|.";
			std::cout << "\n    |  " << arrow[2] << std::setw(24) << std::left << name[2] << "|.";
			std::cout << "\n    |  " << arrow[3] << std::setw(24) << std::left << name[3] << "|.";
			std::cout << "\n    |  " << arrow[4] << std::setw(24) << std::left << name[4] << "|.";
			std::cout << "\n    |  " << arrow[5] << std::setw(24) << std::left << name[5] << "|.";
			std::cout << "\n    |  " << arrow[6] << std::setw(24) << std::left << name[6] << "|.";
			std::cout << "\n    |  " << arrow[7] << std::setw(24) << std::left << name[7] << "|.";
			std::cout << "\n    |  " << arrow[8] << std::setw(24) << std::left << name[8] << "|.";
			std::cout << "\n    |                            |.";
			std::cout << "\n    |   _________________________|___";
			std::cout << "\n    |  /                            /.";
			std::cout << "\n    \\_/____________________________/.";
			UserChoose = _getch();
			if (chooseU != 1)
				if (UserChoose == 32)
					return -1;
			if (UserChoose == 27)
				return -2;
			if (UserChoose == 224) {
				UserChoose = _getch();
				switch (UserChoose)
				{
				case UP:
					if (PageChoose > 0)
						PageChoose--;
					else
						PageChoose = size;
					break;
				case DOWN:
					if (PageChoose < size)
						PageChoose++;
					else
						PageChoose = 0;
					break;
				default:
					break;
				}
			}
			arrow[oldPageChoose] = "  ";
			arrow[PageChoose] = ">>";
			oldPageChoose = PageChoose;
		}
		return PageChoose;
	}

	void LoginRegister(short choose)noexcept {
		if (choose) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			std::cout << "\n _                    _";
			std::cout << "\n| |                  (_)";
			std::cout << "\n| |      ___    __ _  _  _ __";
			std::cout << "\n| |     / _ \\  / _` || || '_ \\";
			std::cout << "\n| |____| (_) || (_| || || | | |";
			std::cout << "\n\\_____/ \\___/  \\__, ||_||_| |_|";
			std::cout << "\n	        __/ |";
			std::cout << "\n	       |___/";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			return;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\n______              _       _";
		std::cout << "\n| ___ \\            (_)     | |";
		std::cout << "\n| |_/ / ___   __ _  _  ___ | |_  ___  _ __";
		std::cout << "\n|    / / _ \\ / _` || |/ __|| __|/ _ \\| '__|";
		std::cout << "\n| |\\ \\|  __/| (_| || |\\__ \\| |_|  __/| |";
		std::cout << "\n\\_| \\_|\\___| \\__, ||_||___/ \\__|\\___||_|";
		std::cout << "\n              __/ |";
		std::cout << "\n             |___/";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	void CakeMan(string& retrunWord, string word) noexcept {
		system("cls");
		Sleep(150);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "   ,-.";
		Sleep(150);
		std::cout << "\n _(*_*)_";
		Sleep(150);
		std::cout << "\n(_  o  _)";
		Sleep(150);
		std::cout << "\n  / o \\";
		Sleep(150);
		std::cout << "\n (_/ \\_)";
		Sleep(150);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "\n ________";
		std::cout << "\n|";
		printSlow(word);
		std::cin >> retrunWord;
	}
	short ChooseLogin(short menu) noexcept {
		short PageChoose = 0;
		short UserChoose = 0;
		while (UserChoose != 13)
		{
			system("cls");
			if (menu == 0)
				AdminUserLogo(PageChoose);
			if (menu == 1) {
				LoginRegister(PageChoose);
			}
			if (menu == 2)
				menuBuy(PageChoose);
			UserChoose = _getch();
			if (menu == 1) {
				if (UserChoose == 27)
					return -1;
			}

			if (UserChoose == 224) {
				UserChoose = _getch();
				switch (UserChoose)
				{
				case LEFT:
					if (PageChoose == 0)
						PageChoose = 1;
					else
						PageChoose = 0;
					break;
				case RIGHT:
					if (PageChoose == 1)
						PageChoose = 0;
					else
						PageChoose = 1;
					break;
				default:
					break;
				}
			}

		}
		return PageChoose;
	}
};

class Useful {
	void readIng(string index) {
		std::vector<string> ings;
		string temp;
		std::ifstream fileI("ingtype.txt");

		if (fileI.is_open()) {
			for (short i = 0; !fileI.eof(); i++)
			{
				getline(fileI, temp);
				ings.push_back(temp);
			}
			fileI.close();
		}
		int* numbers = new int[index.size()]{};

		for (short i = 0; i < index.size(); i++)
		{
			numbers[i] = int(index[i]) - 48;
		}

		for (short i = 0; i < index.size(); i++)
		{
			std::cout << numbers[i] << "." << ings[numbers[i]] << "\n";
		}

		delete[] numbers;
	}
public:
	void checkSpacesVector(std::vector<string>& vector) {
		for (short i = 0; i < vector.size(); i++)
		{
			if (vector[i].empty() || vector[i][0] == *" ") {
				DeleteOneThing(vector, i);
			}
		}
	}

	void DeleteOneThing(std::vector<string>& vector, short index) {
		std::vector<string> newvector;
		for (short i = 0; i < vector.size(); i++)
		{
			if (index != i)
				newvector.push_back(vector[i]);
		}
		vector.clear();
		vector = newvector;
	}

	string getIndexIng(short index) { // for deletion
		std::ifstream fileI("fooding.txt");
		string temp, choose;

		if (fileI.is_open()) {
			for (short i = 0; !fileI.eof(); i++)
			{
				getline(fileI, temp);
				if (index == i) {
					break;
				}
			}
			fileI.close();
		}

		readIng(temp);
		std::cout << "\nChoose :";
		std::cin >> choose;
		return choose;
	}

	string chooseIng() { // add ing
		string temp, choose;
		std::ifstream fileI("ingtype.txt");

		if (fileI.is_open()) {
			for (short i = 0; !fileI.eof(); i++)
			{
				getline(fileI, temp);
				if (!temp.empty())
					std::cout << i << "." << temp << std::endl;
			}
			fileI.close();
		}
		std::cout << "\nChoose :";
		std::cin >> choose;
		return choose;
	}

	short getIndexFood() {
		string name;
		short choose;
		std::ifstream foodN("foodname.txt");

		if (foodN.is_open()) {
			for (short i = 0; !foodN.eof(); i++)
			{
				getline(foodN, name);
				if (!name.empty()) {
					std::cout << i << "." << name << "\n";
				}
			}
			foodN.close();
		}

		std::cout << "\nChoose :";
		std::cin >> choose;
		return choose;
	}
};

class Stream {
	Useful u;
public:
	void ofStreamOut(string txt, std::vector<string>& vector) noexcept {
		u.checkSpacesVector(vector);
		std::ofstream foodI(txt, std::ios_base::out);
		if (foodI.is_open()) {
			for (short i = 0; i < vector.size(); i++)
			{
				foodI << vector[i] << "\n";
			}
			foodI.close();
		}
	}
	void ofStream(string txt, string word)noexcept {
		std::ofstream file(txt, std::ios_base::app);
		if (file.is_open()) {
			file << word << "\n";
			file.close();
		}
	}
	void ifStream(string txt, std::vector<string>& vector) noexcept {
		string temp;
		std::ifstream file(txt);
		if (file.is_open()) {
			for (short i = 0; !file.eof(); i++)
			{
				getline(file, temp);
				vector.push_back(temp);
			}
			file.close();
		}
	}
	string ifStream(string txt, short index) {
		string temp;
		std::ifstream file(txt);
		if (file.is_open()) {
			for (short i = 0; !file.eof(); i++)
			{
				getline(file, temp);
				if (i == index) {
					return temp;
				}
			}
			file.close();
		}
		return "";
	}
};

class UserPanel
{
	Useful ingReader;
	Stream stream;
	PrintVisual printVisual;
public:
	UserPanel() = default;
	int loginUser() noexcept {
		string name;
		string password;
		printVisual.CakeMan(name, "Username :");
		printVisual.CakeMan(password, "Password :");
		std::ifstream fileU("username.txt");

		if (fileU.is_open()) {
			string temp;
			bool isNameFind = 1;
			int index = 1;

			while (!fileU.eof())
			{
				getline(fileU, temp);

				if (name == temp) {
					isNameFind = 0;
					break;
				}

				index++;
			}
			fileU.close();

			if (isNameFind) {
				std::cout << "USERNAME NOT FOUND";
				system("pause");
				return 0;
			}

			std::ifstream fileP("password.txt");

			if (fileP.is_open()) {
				while (!fileP.eof())
				{
					for (int i = 0; i < index - 1; i++)
					{
						getline(fileP, temp);
					}
					getline(fileP, temp);

					if (temp == password) {
						return 1;
					}
				}
			}
		}
		return 0;
	}

	void registerUser() noexcept {
		string name;
		string password;
		printVisual.CakeMan(name, "Username :");
		printVisual.CakeMan(password, "Password :");
		std::ofstream usernameT("username.txt", std::ios_base::app);

		if (usernameT.is_open()) {
			usernameT << name << "\n";
		}

		usernameT.close();
		std::ofstream passwordT("password.txt", std::ios_base::app);

		if (passwordT.is_open()) {
			passwordT << password << "\n";
		}

		passwordT.close();
	}

	short UserChoosePage() noexcept {
	whileStart:
		std::vector<string> foodName, foods;
		std::vector<short> vector;
		stream.ifStream("foodname.txt", foodName);
		short size = foodName.size() - 1;
		foodName[size] = "Coming soon";

		for (short i = size; i < 9; i++)
		{
			foodName.push_back("Coming soon");
		}

		short pageChoose, buymenu;
		buymenu = printVisual.ChooseLogin(2);

		while (true)
		{
			pageChoose = printVisual.Menu(foodName, size, buymenu);
			if (!buymenu) {
				stream.ifStream("foodname.txt", foods);
				std::cout << "\n\n_________________________________\n";
				std::cout << "If Press space u will buy these foods\n";
				for (short i = 0; i < vector.size(); i++)
				{
					std::cout << foods[vector[i]] << "\n";
				}
				if (vector.empty())
					std::cout << "\nNothing\n";
				system("pause");
			}
			if (pageChoose == -2) {
				return -1;
			}
			if (pageChoose == -1) {
				if (!buymenu)
					break;
			}
			system("cls");
			vector.push_back(pageChoose);
			printFoodInside(pageChoose);
			system("pause");
		}

		short error = buyFoods(vector);

		if (error == -1) {
			system("cls");
			std::cout << "SORRY WE DONT HAVE FOOD TO COOK\n";
			system("pause");
			vector.clear();
			goto whileStart;
		}
		system("cls");
		std::cout << "YOUR FOOD IS READY\n";
		system("pause");
		goto whileStart;
	}
private:

	short buyFoods(std::vector<short> index) noexcept {
		std::vector<string> ing, cook, stock;
		string allFood;

		stream.ifStream("fooding.txt", ing);
		stream.ifStream("stock.txt", stock);
		stream.ifStream("cooksize.txt", cook);

		std::cout << "Do u wanna take more ings?Y/N";
		for (short i = 0; i < index.size(); i++)
		{
			std::cout << "";
		}


		for (short v = 0; v < index.size(); v++)
		{
			string numberV = cook[index[v]];
			string numberS = "000";
			string numberI = "0";
			short newstock;
			for (short i = 0, c = 0; c < cook[index[v]].size(); i++, c += 3)
			{
				numberS[0] = numberV[c];
				numberS[1] = numberV[c + 1];
				numberS[2] = numberV[c + 2];
				numberI = ing[index[v]][i];

				if (stoi(stock[stoi(numberI)]) - stoi(numberS) < 0) {
					return -1;
				}

				newstock = stoi(stock[stoi(numberI)]) - stoi(numberS);
				stock[stoi(numberI)] = std::to_string(newstock);
				numberS = "000";
			}
		}
		ingReader.checkSpacesVector(stock);
		stream.ofStreamOut("stock.txt", stock);
	}

	void printFoodInside(short index) {
		std::cout << "\nName :" << stream.ifStream("foodname.txt", index);
		std::cout << "\nPrice :" << stream.ifStream("price.txt", index);
		std::cout << "\n";
		printIng(index);
	}

	void printIng(short index) {
		std::vector<string> vector;
		std::vector<string> vector1;
		string numberS = "000";
		short number;
		string ings = stream.ifStream("fooding.txt", index);
		stream.ifStream("ingtype.txt", vector);
		stream.ifStream("cooksize.txt", vector1);
		string numberV = vector1[index];
		for (short i = 0, c = 0; i < ings.size(); i++, c += 3)
		{
			number = short(ings[i]) - 48;
			std::cout << vector[number];
			if (numberV[c] != *"0")
				std::cout << numberV[c];
			std::cout << " :" << numberV[c + 1] << numberV[c + 2];
			std::cout << std::endl;
		}
	}
};

class AdminPanel {
	Useful _ingReader;
	PrintVisual printVisual;
	Sorter sorter;
	Stream stream;
public:
	bool loginAdmin() noexcept {
		string password;
		printVisual.CakeMan(password, "Password :");

		if ("kod" == password) {
			return 1;
		}

		return 0;
	}

	short adminChoosePage() {
		short choose = 0;
		short food;
		string ings;
		while (true)
		{
			system("cls");
			if (printVisual.visualChoose(choose) == -1)
				return -1;
			choose++;
			system("cls");
			switch (choose)
			{
			case 1:
				addFoodName();
				break;
			case 2:
				addIngType();
				break;
			case 3:
				deleteFood(_ingReader.getIndexFood());
				break;
			case 4:
				addIngToFood(_ingReader.getIndexFood());
				break;
			case 5:
				deleteIngFromFood(_ingReader.getIndexFood());
				break;
			case 6:
				food = _ingReader.getIndexFood();
				changeCookSize(food, _ingReader.getIndexIng(food));
				break;
			case 7:
				changeStockSize(stoi(_ingReader.chooseIng()));
				break;
			case 8:
				changePrice(_ingReader.getIndexFood());
				break;
			default:
				break;
			}
		}
		return 1;
	}
private:
#pragma region Usefull
	void DeleteOneChar(std::vector<string>& vector, short index, string type) {
		for (short i = 0, c = 0; i < vector[index].size() + 1; i++, c++)
		{
			if (vector[index][i] == type[0]) {
				vector[index].erase(i, i + 1);
			}
		}
	}
#pragma endregion
	void addFoodName() {
		string foodName, name;
		short choose = -1;

		printSlow("Food Name :");
		std::cin >> foodName;

		stream.ofStream("foodname.txt", foodName);
		std::ifstream foodNR("foodname.txt");

		if (foodNR.is_open()) {
			for (short i = 0; !foodNR.eof(); i++)
			{
				getline(foodNR, name);
				if (name == foodName)
				{
					choose = i;
					break;
				}
			}
			foodNR.close();
		}
		addIngToFood(choose);
		addPrice();
	}

	void deleteFood(short index) {
		std::vector<string> vector;
		std::vector<string> names;
		names.push_back("foodname.txt");
		names.push_back("fooding.txt");
		names.push_back("cooksize.txt");
		names.push_back("price.txt");
		for (short i = 0; i < 4; i++)
		{
			stream.ifStream(names[i], vector);
			_ingReader.DeleteOneThing(vector, index);
			stream.ofStreamOut(names[i], vector);
			vector.clear();
		}
	}

	void addIngToFood(short index) {
		std::vector<string> ings;
		string temp;
		string type = _ingReader.chooseIng();

		stream.ifStream("fooding.txt", ings);

		if (!sorter.sortVector(ings, index, type))
			return;
		std::ofstream foodI("fooding.txt", std::ios_base::out);

		stream.ofStreamOut("fooding.txt", ings);
		addCookSize(index);
	}

	void deleteIngFromFood(short index) {
		std::vector<string> vector;
		string type = _ingReader.getIndexIng(index);
		stream.ifStream("fooding.txt", vector);
		DeleteOneChar(vector, index, type);
		stream.ofStreamOut("fooding.txt", vector);
		vector.clear();

		stream.ifStream("cooksize.txt", vector);
		short types = stoi(type);
		if (types == 0)
			vector[index].erase(types, types + 3);
		else
			vector[index].erase(types + 1, types + 3);

		stream.ofStreamOut("cooksize.txt", vector);
		vector.clear();
	}

	void addIngType() {
		string name;
		printSlow("Ing Name :");
		std::cin >> name;
		stream.ofStream("ingtype.txt", name);
		addStockSize();
	}

	void addCookSize(short index) {
		std::vector<string> vector;
		string size;
		printSlow("Size :");
		std::cin >> size;
		if (stoi(size) < 10 && stoi(size) > 0) {
			size.append("00");
			std::swap(size[0], size[2]);
		}
		else if (stoi(size) < 100 && stoi(size) >= 10) {
			size.append("0");
			std::swap(size[0], size[1]);
			std::swap(size[0], size[2]);
		}
		else if (stoi(size) > 999 || stoi(size) < 0)
			throw string("SENCANI DUZ YAZ");

		stream.ifStream("cooksize.txt", vector);
		vector[index].append(size);
		stream.ofStreamOut("cooksize.txt", vector);
	}

	void changeCookSize(short index, string typeT) throw(string) {
		std::vector<string> vector;
		short type = stoi(typeT);
		string size;
		printSlow("Size :");
		std::cin >> size;
		if (size.size() == 1) {
			size.append("00");
			std::swap(size[0], size[2]);
		}
		else if (size.size() == 2) {
			size.append("0");
			std::swap(size[0], size[1]);
			std::swap(size[0], size[2]);
		}
		else if (size.size() > 3)
			return;

		stream.ifStream("cooksize.txt", vector);
		vector[index][type * 3] = size[0];
		vector[index][type * 3 + 1] = size[1];
		vector[index][type * 3 + 2] = size[2];
		stream.ofStreamOut("cooksize.txt", vector);
	}

	void addStockSize() {
		string size;
		printSlow("Stock Size :");
		std::cin >> size;
		stream.ofStream("stock.txt", size);
	}

	void changeStockSize(short index) {
		std::vector<string> vector;
		string size;
		printSlow("Size :");
		std::cin >> size;
		if (size.size() == 1) {
			size.append("00");
			std::swap(size[0], size[2]);
		}
		else if (size.size() == 2) {
			size.append("0");
			std::swap(size[0], size[1]);
			std::swap(size[0], size[2]);
		}
		else if (size.size() > 3)
			return;

		stream.ifStream("stock.txt", vector);
		vector[index] = size;
		stream.ofStreamOut("stock.txt", vector);
	}

	void changePrice(short index) {
		string size;
		printSlow("Price :");
		std::cin >> size;
		std::vector<string> vector;
		stream.ifStream("price.txt", vector);
		vector[index] = size;
		stream.ofStreamOut("price.txt", vector);
	}

	void addPrice() {
		string price;
		printSlow("Price :");
		std::cin >> price;
		stream.ofStream("price.txt", price);
	}
};

int main() {
	UserPanel user;
	PrintVisual printVisual;
	AdminPanel ap;
whileStart:
	short choose = printVisual.ChooseLogin(0);
	if (choose == 1) {
		while (true)
		{
			if (ap.loginAdmin())
				if (ap.adminChoosePage() == -1)
					goto whileStart;
		}
	}
	else {
		while (true)
		{
			choose = printVisual.ChooseLogin(1);
			if (choose == 1)
			{
				if (user.loginUser()) {
					if (user.UserChoosePage() == -1)
						goto whileStart;
				};
			}
			else if (choose == 0)
				user.registerUser();
			else if (choose == -1)
				goto whileStart;
		}
	}
	return 1;
}
