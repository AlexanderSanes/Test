#include <iostream>
#include <map>
#include <string>
#include <windows.h>
#include <cctype>
#include <fstream>

using namespace std;
void toLower(basic_string<char>& s) {
	for (basic_string<char>::iterator p = s.begin(); p != s.end(); ++p) {
		*p = tolower(*p);
	}
}
void toUpper(basic_string<char>& s) {
	for (basic_string<char>::iterator p = s.begin();p != s.end(); ++p) {
		*p = toupper(*p); // toupper is for char
	}
}

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string str;
	string key, equal;
	ifstream in;
	in.open("FileOut.txt");
	map <string, string> book;

	while (in)
	{
	getline(in, key);
	getline(in, equal);
	book.insert(make_pair(key, equal));
	}

	for (map <string, string>::iterator i = book.begin(); i != book.end(); i++)
	{
	cout << "Переведите : " << i->first << ':';
	cin >> str;
	toLower(str);
	if (str == i->second)
	{
		cout << "Правильно!!!(нажмите enter, чтобы продолжить...)";
		cin.get();
		cin.get();
	}
	else
	cout << " Неправильно!!! Правильный перевод : " << i->second << endl ;
	}

	system("pause");
	return 0;
}
