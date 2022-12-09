#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
//11_6

int pro(int n) {
	for (int i = 2; i <= sqrt(n); i++) 
	{
		if (n % i == 0) 
		{
			return 0;
		}
	}
	return 1;

}


int main()
{
	ifstream file("test.txt");
	int number, parni = 0, kvad_neparnih = 0, rizn = 0, prost = 0;
	string s;
	int max_par = 0, max_nep = 0;
	int max = 0;
	int kolich = 0;
	int mc = 0;
	while (!file.eof()) 
	{
		getline(file, s);
		number = stoi(s);
		printf("%d\n", number);
		if (number % 2 == 0) 
		{
			parni++;
			if (number > max_par) {
				max_par = number;
			}
		}
		else 
		{
			double k;
			k = sqrt(number);
			if (k == (int)k) 
			{
				kvad_neparnih++;
			}
			if (number > max_nep) 
			{
				max_nep = number;
			}
		}
		int x = pro(number);
		if (x != 0) 
		{
			prost++;
		}
		if (number > max) 
		{
			max = number;
			kolich++;
			if (kolich > mc) 
			{
				mc = kolich;
			}
		}
		else 
		{
			max = 0;
			kolich = 0;
		}
	}
	rizn = max_par - max_nep;
	cout << "A)NUMBER OF EVEN NUMBERS=" << parni << endl;
	cout << "B)NUMBER OF SQUARES OF ADD NUMBERS=" << kvad_neparnih << endl;
	cout << "C)DIFFERENCE BETWEEN THE BIGGEST EVEN AND THE LEAST ODD NUMBER=" <<rizn << endl;
	cout << "D)NUMBER OF SIMPLE=" << prost << endl;
	cout << "E)NUMBER OF ELEMENTS IN THE BIGGEST RISING SUBSEQUENCE=" << mc+1 << endl;
	file.close();
}

