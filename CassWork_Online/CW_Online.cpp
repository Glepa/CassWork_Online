#include<iostream>
#include<vector>
#include<list>
#include<cstdlib>
#include<ctime>
//#include"06_06_20.h"
//#include"13.06.2020.h"
//#include"20.06.2020.h"
//#include"27.06.2020.h"
//#include"04.07.2020.h"
//#include"18.07.2020.h"
//#include"25.07.2020.h"
//#include"29.08.20.h"
//#include"05.09.2020.h"
//#include"12.09.2020.h"
#include"19.09.2020.h"

using namespace std;
int main() {
	//int size = 25;
	//int* arr = new int[size];
	//for (size_t i = 0; i < size; i++)
	//{
	//	arr[i] = i + 1;
	//}
	//Stack <int> st(arr, size);
	//try {
	//	st.add(27);
	//}
	//catch (string str) {
	//	cout << "\n Err! " << str;
	//}
	//--------------------------------------
	/*Dictonary dic("Hello");
	dic.addWord("World");
	dic.addWord("p_pot");
	SearchWord search; 
	if (search(dic, "Hello")) cout << "\nOk!";
	else cout << "\n No word!";
	if (search(dic, "Word")) cout << "\nOk!";
	else cout << "\n No word!";*/
//---------------------------------------------
	/*vector<int>vect(100);
	list<int>lst(100);
	srand(time(NULL));
	auto iterV = vect.begin();
	auto iterVEnd = vect.end();
	auto iterL = lst.begin();
	auto iterLEnd = lst.end();
	for (; iterV != vect.end() && iterL!=lst.end(); ++iterV, ++iterL) {
		*iterV = rand() % 100;
		*iterL = rand() % 100;
	}
	 iterV = vect.begin();
	 iterL = lst.begin();
	auto Collection = newColl(iterV, iterVEnd, iterL,iterLEnd);
	auto Collection2 = understudy(iterV, iterVEnd, iterL, iterLEnd);
	cout << "\n\n";
	for (int& a : Collection2) {
		cout << setw(3) << a << ' ';
	}*/
	//__________________________________________________________
	DinArray <int> dArr(3);
	thread t1([&dArr](){dArr.generate();});
	thread t2([&dArr]() {dArr.print(); });
	thread t3([&dArr]() {dArr.resize(5); });
	t1.join();
	t2.join();
	t3.join();
	t2 = thread([&dArr]() {dArr.print(); });
	t2.join();
	return 0;
}

