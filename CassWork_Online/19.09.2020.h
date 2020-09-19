#pragma once
#include<iostream>
#include<mutex>


using namespace std;
template <class T>
class DinArray {
	T* arr;
	int size;
	mutex mtArr;
public:
	DinArray(int size_){
		size = size_;
		arr = new T[size];
	}
	void generate() {
		mtArr.lock();
			for (size_t i = 0; i < size; i++)
			{
				arr[i] = i * i + i;
			}
		mtArr.unlock();
	}
	void print() {
		mtArr.lock();
		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i]<<' ';
		}
		cout << endl;
		mtArr.unlock();
	}
	void resize(int size_) {
		mtArr.lock();
		T* mass = new T[size_];
			for (size_t i = 0; i < size_; i++)
			{
				if (i < size)
					mass[i] = arr[i];
				else mass[i] = 0;
			}
			swap(arr, mass);
			size = size_;
			delete[] mass;
		mtArr.unlock();
	}
};