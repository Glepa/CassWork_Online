#pragma once
#include<iostream>
using namespace std;

class ExcpObj_Interface{
public:
	virtual void show(const char* Err) = 0;
};
class ExcepObj : public exception, public ExcpObj_Interface {
protected:
	string name;
	int num;
public:
	ExcepObj() = delete;
	ExcepObj(const char* msg, const string Obj, int numErr) :exception(msg) {
		name = Obj;
		num = numErr;
	}
	void show(const char* Err) override {
		cout << Err;
	}
};
class ExcepObj1 : public ExcepObj {
	
public:
	ExcepObj1(const char* msg, const string Obj, int numErr) : ExcepObj(msg,Obj,numErr) {}
	void show(const char *Err) override {
		cout << Err << endl;
		cout << " Objekt: " << this->name << endl;
		cout << "Number Err: " << this->num << endl;
	}
};
class ExcepObj2 : public ExcepObj {

public:
	ExcepObj2(const char* msg, const string Obj, int numErr) : ExcepObj(msg, Obj, numErr) {}
	void show(const char* Err) override {
		cout << Err << endl;
		cout << " Objekt: " << this->name << endl;
		cout << "Number Err: " << this->num << endl;
	}
};
class Objekt {
protected:
	int num;
	string name;
public:
	Objekt() {
		num = 0;
		name = "Unknow";
	}
	Objekt(const char* name, int num) {
		this->name = name;
		this->num = num;
	}
	~Objekt(){}
	virtual int func() {
		return num;
	}
};
class Objekt1 : public Objekt {
	int param1;
	int param2;
public:
	Objekt1() : Objekt() {
		param1 = 0;
		param2 = 1;
	}
	Objekt1(int param1, int param2) : Objekt("Objekt1", 1) {
		if (param1 > param2)throw ExcepObj1("Err >", this->name, 1);
		else {
			this->param1 = param1;
			this->param2 = param2;
		}
	}
	int func() override {
		if(param1/param2 == 1) throw ExcepObj1("Err =", this->name, 2);
		return param1 / param2;
	}
};

class Objekt2 : public Objekt {
	int param1;
	int param2;
public:
	Objekt2() : Objekt() {
		param1 = 1;
		param2 = 0;
	}
	Objekt2(int param1, int param2) : Objekt("Objekt2", 1) {
		if (param1 < param2)throw ExcepObj2("Err <", this->name, 1);
		else {
			this->param1 = param1;
			this->param2 = param2;
		}
	}
	int func() override {
		if (param2 / param1 == 1) throw ExcepObj2("Err =", this->name, 2);
		return param2 / param1;
	}
};