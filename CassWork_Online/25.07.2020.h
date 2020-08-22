#pragma once
#include<iostream>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<vector>

using namespace std;
 
vector<int> NumCollection(int size) {
	srand(time(NULL));
	vector<int>num(size);
	for (size_t i = 0; i < size; i++)
	{
		num[i] = 100 + rand() % 899;
		cout << num[i] << ' ';
	}
	return num;
}



//int main() {
//	int size = 10;
//	int* colletion = NumCollection(size);
//	auto rule = [size, &colletion]()->int {
//		int n = 0;
//		for (size_t i = 0; i < size; i++)
//		{
//			if (!(colletion[i] / 10) % 10) {
//				cout << colletion[i];
//				n++;
//			}
//		}
//		return n;
//	}();
//	cout << "\n Koll-vo num:" << rule;
//	delete[]colletion;
//	return 0;
//}