#include <iostream>
#include <stdio.h>
using namespace std;



void BinaryOut(int value){

	unsigned int order = sizeof(int)*8; // Количество разрядов
	unsigned int mask = 1 << (order - 1); // Маска побитового сравнения
	cout << "int " << value << " = ";
	for (int i = 1; i <= order; i++)
	{
		putchar(value & mask ? '1' : '0');
		value <<= 1; // Побитовый сдвиг числа
		if (i % 8 == 0)
		{
			putchar(' ');
		}
		if (i % order - 1 == 0)
		{
			putchar(' ');
		}
	}
	cout << endl;
};





void BinaryOut(float value){
	union MyUnion
	{
		float box;
		int newvalue;
	};
	MyUnion ford;
	ford.box = value;
	
	unsigned int order = sizeof(int)* 8; // Количество разрядов
	unsigned int mask = 1 << (order - 1); // Маска побитового сравнения
	cout  << "float "<< value << " = ";
	for (int i = 1; i <= order; i++)
	{
		putchar(ford.newvalue & mask ? '1' : '0');
		ford.newvalue <<= 1; // Побитовый сдвиг числа
		if (i  == 1)
		{
			putchar(' ');
		}
		else if (i  == 9)
		{
			putchar(' ');
		}
	}
	cout << endl;
};

void BinaryOut(double value){
	union MyUnion
	{
		double box;
		int newvalue[2];
	};
	MyUnion ford;
	ford.box = value;

	unsigned int order = sizeof(int)* 8; // Количество разрядов
	unsigned int mask = 1 << (order - 1); // Маска побитового сравнения
	cout << "double " << value << " = ";
	for (int z = 0; z < 2; z++){
		for (int i = 1; i <= order; i++)
		{
			putchar(ford.newvalue[z] & mask ? '1' : '0');
			ford.newvalue[z] <<= 1; // Побитовый сдвиг числа
			if (z == 0 && i == 1)
			{
				putchar(' ');
			}
			else if (z == 0 && i == 12)
			{
				putchar(' ');
			}
		}
	}
	cout << endl;
};





int main(){
	
	cout << "int = " << sizeof(int) << endl;
	cout << "unsigned int = " << sizeof(unsigned int) << endl;
	cout << "short int = " << sizeof(short int) << endl;
	cout << "unsigned short int = " << sizeof(unsigned short int) << endl;
	cout << "long int = " << sizeof(long int) << endl;
	cout << "unsigned long int = " << sizeof(unsigned long int) << endl;
	cout << "float = " << sizeof(float) << endl;
	cout << "double = " << sizeof(double) << endl;
	cout << "long double = " << sizeof(long double) << endl;
	cout << "char = " << sizeof(char) << endl;
	cout << "bool = " << sizeof(bool) << endl << endl << endl;


	while (true)
	{


		cout << "If you want to enter int, press 1." << endl;
		cout << "If you want to enter float, press 2." << endl;
		cout << "If you want to enter double, press 3." << endl;
		cout << "Press any key to exit." << endl;
		int change;
		cin >> change;
		if (change == 1){
			cout << "Enter your number" << endl;
			int value;
			cin >> value;
			BinaryOut(value);
		}
		else if (change == 2){
			cout << "Enter your number" << endl;
			float value;
			cin >> value;
			BinaryOut(value);
		}
		else if (change == 3)
		{
			cout << "Enter your number" << endl;
			double value;
			cin >> value;
			BinaryOut(value);
		}
		else { break; }
	}



	system("pause");
	return 0;
}