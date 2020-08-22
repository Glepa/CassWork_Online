#pragma once
#include<iostream>
#include<string>

using namespace std;
class Objekt{
protected:
	int id;
	string name;
public:
	Objekt() {
		id = 0;
		name = '\0';
	}
	~Objekt(){}
	void setID(int ID) {
		id = ID;
	}
	void setName(string Name) {
		name = Name;
	}
	virtual void show() = 0;
};
class Resours : public virtual Objekt {
	string Using[3];
public:
	Resours() :Objekt() {
		for (size_t i = 0; i < 3; i++)
		{
			Using[i] = '\0';
		}
	}
	~Resours() {}
	void setUsing(string _using[3]) {
		for (size_t i = 0; i < 3; i++)
		{
			Using[i] = _using[i];
		}
	}
	void show() {
		for (size_t i = 0; i < 3; i++)
		{
			cout << this->Using[i];
		}
		cout << endl;
	}
};
class Materials : public virtual Objekt {
	string Combin[3];
public:
	Materials() :Objekt() {
		for (size_t i = 0; i < 3; i++)
		{
			Combin[i] = '\0';
		}
	}
	~Materials() {}
	void setComb(string combin[3]) {
		for (size_t i = 0; i < 3; i++)
		{
			Combin[i] = combin[i];
		}
	}
	void show() {
		
		for (size_t i = 0; i < 3; i++)
		{
			cout << this->Combin[i];
		}
		cout << endl;
	}

};
class Board: public Materials,public Resours {
public:
	void show() {
		cout << id << endl << name << endl;
		Resours::show();
		Materials::show();
	}
};
