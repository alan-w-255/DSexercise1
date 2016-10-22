#ifndef _STACK_H_
#define _STACK_H_

#include<iostream>
using namespace std;

class stack
{
public:
	stack();
	~stack();
	double pop();
	int push(double);
	double getTop();
	int Top();
private:
	double S[100] = { 0 };
	int top = 0;
};

#endif