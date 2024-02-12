#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Data
{
public:
	Data(int aLength,int missLength);
	string stringA;
	string stringB;
	vector<string> matchedM;
	vector<char> missX;
	vector<int> matchedA; 
	vector<int> matchedB;
	int optimalAdd;
	int oldDuo;
	int maxDuo;
	void createMatchedA();
	int createDuo();
	void createMatchedM();
	void restructMatchedB();
};
