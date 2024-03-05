#pragma once

#include <iostream>
#include <vector> 

using namespace std;

//Stack class that uses a vector and all the functions to add, remove, check the top, and find the average

class Stack {
private:
	vector<int> nums;

public:
	bool isEmpty();
	void push(int num);
	void pop();
	int top();
	double average();
};