#include <iostream>
#include <map>
#include <string>
#include <windows.h>
#include <cctype>
#include <fstream>
#include <ctime>

#include "Slovar.h"

using namespace std;
int StrToInt(const string& str)
{
	int num = 0;
	for (int i = 0; i < str.length(); ++i) 
	{
		num += (static_cast<int>(str[i] - '0'))*pow(10, (str.length() - 1 - i));
	}
	return num;
}
void toLower(string& s) {
	for (int i = 0; i < s.length(); ++i) {
		s[i] = tolower(s[i]); // tolower is for char
	}
}

void toUpper(string& s) {
	for (int i = 0; i < s.length(); ++i) {
		s[i] = toupper(s[i]); // toupper is for char
	}
}

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL));

	Slovar x;

	string str;
	string key, equal;
	ifstream in;
	in.open("FileOut.txt");
	map <string, string> book;
	int k = 0;
	while (in)
	{
	getline(in, key);
	getline(in, equal);
	book.insert(make_pair(key, equal));
	k++;
	}
	k--;

	bool f{ true };
	int* right = new int[k];
	memset(right, 0, k*sizeof(*right));
	int rnum = 0;

	map <string, string>::iterator it;
	do{
		it = book.begin();
		rnum = (rand() % k);
		for (int i = 0; i < rnum; ++i) 
			it++;

		cout << "Переведите : " << it->first << ':';
		cin >> str;
		toLower(str);
		if (str == it->second)
		{
			right[rnum]++;
			cout << "Правильно!!!\n";
		}
		else
			cout << "Неправильно!!! Правильный перевод : " << it->second << endl;

		if (right[rnum] == 3)
		{
			cout << "Вы выучили слово" << it->first << '(' << it->second << ')' << endl;
			right[rnum] = 0; // неправильно //дичь какая-то
			book.erase(it);
			k--;
		}
		if (k == 0) f = false;
	} while (f);

	delete[] right;
	system("pause");
	return 0;
}
