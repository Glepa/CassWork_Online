//#include"06_06_20.h"
//#include"13.06.2020.h"
//#include"20.06.2020.h"
//#include"27.06.2020.h"
//#include"04.07.2020.h"
//#include"18.07.2020.h"
#include"25.07.2020.h"
#include<iostream>

using namespace std;
int main() {
	int size = 10;
	vector<int> colletion = NumCollection(size);
	int rule{ [&colletion]()->int {
		int n = 0;
		for (size_t i = 0; i < colletion.size(); i++)
		{
			if (!((colletion[i] / 10) % 10)) {
				cout << endl << colletion[i];
				n++;
			}
		}
		return n;}() 
	};
	cout << "\n Koll-vo num:" << rule ;
	return 0;
}

