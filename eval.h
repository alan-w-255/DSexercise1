#ifndef _EVAL_H_
#define _EVAL_H_

#include<iostream>
#include<string>
#include "stack.h"
#include "formatEvalString.h"

using namespace std;
class Eval
{
public:
	Eval();
	~Eval();
	double  eval(string);
	friend class formatEvalString;
private:
	int PriList[6] = { 1, 1, 2, 2, 3, 0};
	stack numbers; // 操作数栈
	stack opts; // 操作符栈
	stack pri; // 优先级栈
	string evalString; // 需要求值的字符串；
	double result; // 求值结果；
	double cal(double, double, int);
	int getPri(int);
	void popAndCal();//弹出一个操作符和两个数据做运算，弹出一个优先级；
	void pushOptsAndPri(int);//压入操作符和优先级；
	void pushANumber(double);
	void incPriList();//所有操作数优先级加9
	void decPriList();//所有操作数优先级减9
};

#endif
