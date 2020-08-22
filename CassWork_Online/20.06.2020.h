#pragma once
#include<iostream>
#include<cstring>
using namespace std;

class Object {
protected:
	string type;
public:
	virtual void play() = 0;
	void setType(string _type) {
		type = _type;
	}
	string getType() {
		return type;
	}
};
class MusicalInstruments : public Object {
protected:
	int amount;
public:
	
	
	void setAmount(int amount) {
		this->amount = amount;
	}
	int getAmount(){
		return amount;
	}
};

class Guitar :public MusicalInstruments {
	int NumOfStrings;
public:
	void setNum(int Num) {
		NumOfStrings = Num;
	}
	void play() override {
		cout << "\n Drin drin drin...";
	}

};
class Baraban :public MusicalInstruments {
	int height;
public:
	void getHeight(int H) {
		height = H;
	}
	void play() override {
		cout << "\n Bum bum bum...";
	}

};

class MusicPlayer : public Object {
protected:
	int polyphony;
public:
	MusicPlayer(int p) {
		polyphony = p;
	}
	int getPolyphony() {
		return polyphony;
	}
};
class MP3Player : public MusicPlayer {
	int BattCapacity;
public:
	MP3Player(int cap) {
		BattCapacity = cap;
	}
	void play() override {
		cout << "\n Tuc tuc tururuc...";
	}
	int showCapacity() {
		return BattCapacity;
	}
};
class Smartphone : public MusicPlayer {
	int sizeScrin;
public:
	void play() override {
		cout << "\n Pump it up dic dic...";
	}
};


class Person {
	string Name;
	int Age;
public:
	void set(string name,int age) {

		Name = name;
		Age = age;
	}
	void Listen(Object &obj) {
		obj.play();
	}
};