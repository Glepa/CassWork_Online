#pragma once
#include<iostream>
using namespace std;
template<typename T>
class Stack {
	int size;
	T* mass;
public:
	Stack() {
		size=0;
		mass =nullptr;
	}
	Stack(T* val, int _size) {
		size = _size;
		if (sizeof(T) * size > 100) throw "Stack limit exceeded";
		else {
			mass = new T[size];
			for (size_t i = 0; i < size; i++)
			{
				mass[i] = val[i];
			}
		}
	}
	Stack(const Stack& st) {
		this->size = st.size;
		if (this->mass) delete[] this->mass;
		this->mass = new T[this->size];
		for (size_t i = 0; i < size; i++)
		{
			this->mass[i] = st.mass[i];
		}
	}
	void add(T val) {
		size++;
		string str;
		if (sizeof(T) * size > 100) throw str = "Stack limit exceeded";
		else {
			if (mass) {
				T* mass2 = new T[size];
				for (size_t i = 0; i < size; i++)
				{
					if (i < size - 1)
						mass2[i] = mass[i];
					else mass2[i] = val;
				}
				swap(mass, mass2);
				delete[] mass2;
			}
			else {
				mass = new T[size];
				mass[0] = val;
			}
		}
	}
	void del(T val) {
		if (mass) {
			int n = 0;
			for (size_t i = 0; i < size; i++)
			{
				if (mass[i] == val) {
					int temp = mass[i];
					for (size_t j = i; j < size - 1; j++)
					{
						mass[i] = mass[i + 1];
					}
					mass[size - 1] = temp;
					n++;
				}
			}
			if (n) {
				size -= n;
				T* mass2 = new T[size];
				for (size_t i = 0; i < size; i++)
				{
					if (i < size - 1)
						mass2[i] = mass[i];
					else mass2[i] = val;
				}
				swap(mass, mass2);
				delete[] mass2;
			}
			else cout << "\n Missing value";
		}
		else cout << "\n Stack is Empty!";
	}
};

//int main() {
//	int size = 25;
//	int* arr = new int[size];
//	for (size_t i = 0; i < size; i++)
//	{
//		arr[i] = i + 1;
//	}
//	Stack <int> st(arr, size);
//	try {
//		st.add(27);
//	}
//	catch (string str) {
//		cout << "\n Err! " << str;
//	}
//}