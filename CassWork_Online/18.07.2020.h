#pragma once
#include <iostream>
#include<functional>
using namespace std;
//class Functor {
//	int delta;
//public:
//	Functor() {
//		delta = 0;
//	}
//	Functor(int newDelta) {
//		delta = newDelta;
//	}
//	void setDelta(int& newDelta) {
//		delta = newDelta;
//	}
//	int operator ()(int &num){
//		if (num) return delta * num;
//		else return delta + num;
//	}
//};
//void f00(Functor &deltaStep) {
//	int num1 = 4, num2 = 9;
//	for (size_t i = 0; i < 5; i++)
//	{
//		cout << "\n num1 = " << num1;
//		cout << "\n num2 = " << num2;
//		num1 += deltaStep(num1);
//		num2 += deltaStep(num2);
//	}
//}
	/*int main() {
		Functor test(8);
		f00(test);
		return 0;
	}*/
class Digit {
	int value;
public:
	Digit() {
		value = 0;
	}
	int getVal() const {
		return value;
	}
	Digit& operator ++() {
		this->value += 1;
		return *this;
	}
	Digit& operator ++(int k) {
		this->value += 1;
		return *this;
	}
};
namespace std {
	template<>
	struct equal_to <Digit> {
		bool operator()(Digit& x, Digit& y) {
			return(x.getVal() == y.getVal());
		}
	};
}
class Segment;

class Point {
	int X;
	int Y;
public:
	Point() {
		X = 0;
		Y = 0;
	}
	Point(int num) {
		X = num;
		Y = num;
	}
	Point(int xCoord, int yCoord) {
		X = xCoord;
		Y = yCoord;
	}
	int getX() {
		return X;
	}
	int getY() {
		return Y;
	}
	friend Segment& operator+(const Point& start, const Point& end);
};

class Segment {
	Point start;
	Point end;
public:
	int getStartX() {
		return start.getX();
	}
	int getStartY() {
		return start.getY();
	}
	int getEndX() {
		return end.getX();
	}
	int getEndY() {
		return end.getY();
	}
	
	friend Segment& operator+(const Point& start, const Point& end);
};
namespace std {
	template<>
	struct equal_to <Segment> {
		bool operator()(Segment& a, Segment& b) {
			return(a.getStartX() == b.getStartX()&&a.getStartY() == b.getStartY()&&a.getEndX() == b.getEndX() && a.getEndY() == b.getEndY());
		}
	};
}
Segment& operator+(const Point& start, const Point& end)
{
	Segment result;
	result.start.X = start.X;
	result.start.Y = start.Y;
	//result.end = end;
	result.end.X = end.X;
	result.end.Y = end.Y;

	return result;
}