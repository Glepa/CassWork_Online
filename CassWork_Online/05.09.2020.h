#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<iterator>
using namespace std;
 
class SearchWord;
class Dictonary {
	vector <string> word;
public:
	Dictonary(const string str) {
		bool n = true;
		for (size_t i = 0; i < str.size(); i++)
		{
			if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || str[i] == 33 ||
				str[i] == 34 || str[i] == 45 || str[i] == 58 || str[i] == 59 || str[i] == 63)
				continue;
			else n = false;
		}
		if (n) word.push_back(str);
		else cout << "\nErr!Is not word!";
	}
	 void addWord(const string str) {
		 bool n = true;
		 for (size_t i = 0; i < str.size(); i++)
		 {
			 if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || str[i] == 33 ||
				 str[i] == 34 || str[i] == 45 || str[i] == 58 || str[i] == 59 || str[i] == 63)
				 continue;
			 else n = false;
		 }
		 if(n) word.push_back(str);
		 else cout << "\nErr!Is not word!";
	}
	 void delWord(const string str) {
		 vector<string>::iterator iter = word.begin();
		 for (size_t i = 0; i < word.size(); i++)
		 {
			 if (word[i] == str) {
				 word.erase((iter += i));
				 iter = word.begin();
			 }
		 }
	 }
	 void delWord(int i) {
		 vector<string>::iterator iter = word.begin();
		 word.erase((iter += i));
	 }
	 void show() {
		 for (size_t i = 0; i < word.size(); i++)
		 {
			 cout << word[i];
		 }
	 }
	 int size() {
		 return word.size();
	 }
	 friend SearchWord;
};

class SearchWord {
public:
	bool operator () (const Dictonary& dic, const string str) {
		for (size_t i = 0; i < dic.word.size(); i++)
		{
			if (dic.word[i] == str) return true;
		}
		return false;
	}
};

