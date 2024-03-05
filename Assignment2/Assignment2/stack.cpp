#include "stack.h"

//Check if the stack is empty
bool Stack::isEmpty() {
	return nums.empty();
}

//Add numbers to the stack
void Stack::push(int num) {
	nums.push_back(num);  
}

//Remove the top of the stack
void Stack::pop() {
	if (!isEmpty()) {
		nums.pop_back();
	}
}

//Returns the top of the stack
int Stack::top() {
	if (!isEmpty()) {
		return nums.back();
	}
}

//Calculates the average of the stack
double Stack::average() {
	if (!isEmpty()) {
		double sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
		}
		double average = sum / nums.size();
		return average;
	}
	else {
		return 0;
	}
}