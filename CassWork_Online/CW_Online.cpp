//#include"06_06_20.h"
//#include"13.06.2020.h"
//#include"20.06.2020.h"
//#include"27.06.2020.h"
//#include"04.07.2020.h"
//#include"18.07.2020.h"
//#include"25.07.2020.h"
#include"29.08.20.h"
#include<iostream>

using namespace std;
int main() {
	int size = 25;
	int* arr = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = i + 1;
	}
	Stack <int> st(arr, size);
	try {
		st.add(27);
	}
	catch (string str) {
		cout << "\n Err! " << str;
	}
}

