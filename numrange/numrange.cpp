// numrange.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include <limits>
using namespace std;

int main()
{
	cout << "type: \t\t" << "------------------size-----------------------" << endl;
	cout << "bool: \t\t" << "Bytes:" << sizeof(bool);
	cout << "\tMaxValue:" << (numeric_limits<bool>::max)();
	cout << "\t\tMinValue:" << (numeric_limits<bool>::min)() << endl;
	cout << "char: \t\t" << "Bytes:" << sizeof(char);
	cout << "\tMaxValue:" << (numeric_limits<char>::max)();
	cout << "\t\tMinValue:" << (numeric_limits<char>::min)() << endl;
	cout << "signed char: \t" << "Bytes:" << sizeof(signed char);
	cout << "\tMaxValue:" << (numeric_limits<signed char>::max)();
	cout << "\t\tMinValue:" << (numeric_limits<signed char>::min)() << endl;
	cout << "unsigned char: \t" << "Bytes:" << sizeof(unsigned char);
	cout << "\tMaxValue:" << (numeric_limits<unsigned char>::max)();
	cout << "\t\tMinValue:" << (numeric_limits<unsigned char>::min)() << endl;
	cout << "wchar_t: \t" << "Bytes:" << sizeof(wchar_t);
	cout << "\tMaxValue:" << (numeric_limits<wchar_t>::max)();
	cout << "\t\tMinValue:" << (numeric_limits<wchar_t>::min)() << endl;
	cout << "short: \t\t" << "Bytes:" << sizeof(short);
	cout << "\tMaxValue:" << (numeric_limits<short>::max)();
	cout << "\t\tMinValue:" << (numeric_limits<short>::min)() << endl;
	cout << "int: \t\t" << "Bytes:" << sizeof(int);
	cout << "\tMaxValue:" << (numeric_limits<int>::max)();
	cout << "\tMinValue:" << (numeric_limits<int>::min)() << endl;
	cout << "unsigned: \t" << "Bytes:" << sizeof(unsigned);
	cout << "\tMaxValue:" << (numeric_limits<unsigned>::max)();
	cout << "\tMinValue:" << (numeric_limits<unsigned>::min)() << endl;
	cout << "long: \t\t" << "Bytes:" << sizeof(long);
	cout << "\tMaxValue:" << (numeric_limits<long>::max)();
	cout << "\tMinValue:" << (numeric_limits<long>::min)() << endl;
	cout << "double: \t\t" << "Bytes:" << sizeof(long);
	cout << "\tMaxValue:" << (numeric_limits<double>::max)();
	cout << "\tMinValue:" << (numeric_limits<double>::min)() << endl;
	cout << "type: \t\t" << "************size**************" << endl;
	return 0;
}
