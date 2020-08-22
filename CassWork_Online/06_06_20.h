#pragma once
#include<iostream>
using namespace std;
template <typename T>
class List {
	class Node
	{
	public:
		Node() {
			data = 0;
			next = nullptr;
		}
		Node(T data) {
			this->data = data;
			next = nullptr;
		}
		~Node() {
			delete next;
		}
		void setNext(Node* tail) {
			next = tail;
		}
		Node* getTail(T& data) {
			next = new Node(data);
			return next;
		}
	private:
		T data;
		Node* next;
	};

	Node* begin;
	Node* end;
	size_t length;
public:
	List() {
		begin = new Node;
		end = begin;
		length = 1;
	}
	void append(T& data) {
		
		end = end->getTail(data);
		length++;
	}
	~List() {
		delete begin;
	}
	Node* operator [](int k) {
		if (k>length) {
			cout << "Err!";
			exit(1);//exit code лучше неиспользовать!
		}
		return begin + k;
	}
};
void testList() {
	List<int> test;
	for (int i = 1; i < 10; i++)
	{
		test.append(i);

	}
	for (int i = 0; i < 10; i++) {
		cout << test[i] << endl;
	}
}