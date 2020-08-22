#pragma once
#include<iostream>

using namespace std;

class Beast {
protected:
	int size;
public:
	Beast() {
		size = 0;
	}
	virtual void toGo() {
		cout << this << "change position!" << endl;
	}
	 virtual void doVoice() {
		cout << "Voice is other." << endl;
	}
	void setsize(int size) {
		this->size = size;
	}
	virtual int getsize() {
		return size;
	}
};

class Birds : public Beast {

};
class Pigeons : public Birds {
public:
	Pigeons() {
		setsize(15);
	}
	void toGo() override {
		cout << this << "Fly away!"<<endl;
	}
	void doVoice() override {
		cout << this << " Fe fe fe!"<<endl;
	}
};
class Sparrows : public Birds {
public:
	Sparrows() {
		setsize(10);
	}
	void toGo() override {
		cout << this << "Fly away!" << endl;
	}
	void doVoice() override {
		cout << this << " Chic Chiric!" << endl;
	}
};
class Mammals : public Beast {

};
class Hamster : public Mammals {
public:
	Hamster() {
		setsize(12);
	}
	int getsize() override {
		return this->size;
	}
	void toGo() override {
		cout << this << "Run down a hole!" << endl;
	}
	void doVoice() override {
		cout << this << " Pi pi pi!" << endl;
	}
};
class Cats : Mammals {
	int satiety;
public:
	Cats() {
		setsize(18);
		satiety = 0;
	}
	int getSatiety() {
		return satiety;
	}
	int getsize() override {
		return this->size;
	}
	void toGo() override {
		cout << this << "Run at home!" << endl;
	}
	void doVoice() override {
		cout << this << "Myau Myau!" << endl;
	}
	void Food(Beast* beast) {
		satiety += beast->getsize();
		beast->doVoice();
	}
};
void testBeast() {
	Beast* animal[3];
	animal[0] = new Hamster;
	animal[1] = new Sparrows;
	animal[2] = new Pigeons;
	Cats cat;
	for (size_t i = 0; i < 3; i++)
	{
		cat.Food(animal[i]);
			
	}
	cout << cat.getSatiety();
	
 }