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
	stack numbers; // ������ջ
	stack opts; // ������ջ
	stack pri; // ���ȼ�ջ
	string evalString; // ��Ҫ��ֵ���ַ�����
	double result; // ��ֵ�����
	double cal(double, double, int);
	int getPri(int);
	void popAndCal();//����һ�����������������������㣬����һ�����ȼ���
	void pushOptsAndPri(int);//ѹ������������ȼ���
	void pushANumber(double);
	void incPriList();//���в��������ȼ���9
	void decPriList();//���в��������ȼ���9
};

#endif
