#include <iostream>
#include <map>
#include <string>
#include <windows.h>
#include <cctype>
#include <fstream>

using namespace std;
int StrToInt(string str)
{
	int num = 1;
	return num;
}
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

	string str{ "Hello World!" };
	int num;
	num = StrToInt(str);
	cout << "num = " << num << endl;





	//string str;
	//string key, equal;
	//ifstream in;
	//in.open("FileOut.txt");
	//map <string, string> book;
	//int n = 10;
	//string num;
	//int k;

	//for (int i = 0; i <= n || in; ++i)
	//{
	//getline(in, num);
	//getline(in, key);
	//getline(in, equal);
	//book.insert(make_pair(key, equal));
	//}

	//for (map <string, string>::iterator it = book.begin(); it != book.end(); it++)
	//{
	//cout << "Переведите : " << it->first << ':';
	//cin >> str;
	//toLower(str);
	//if (str == it->second)
	//{
	//	cout << "Правильно!!!(нажмите enter, чтобы продолжить...)";
	//	cin.get();
	//	cin.get();
	//}
	//else
	//cout << " Неправильно!!! Правильный перевод : " << it->second << endl ;
	//}

	system("pause");
	return 0;
}
