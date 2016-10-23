#pragma once
/*
对标准输入的字符进行处理
先把表达式存储在一个字符数组中；
在用一个double型二维数组表示一个算术表达式
第一维记录元素的顺序和是操作符还是数字的标识
第二维记录数字或者操作符；
*/
#ifndef _FORMATEVALSTRING_H_
#define _FORMATEVALSTRING_H_
#include <iostream>
#include<string>
#include<sstream>
using namespace std;

class formatEvalString {
public:
	formatEvalString(string);
	~formatEvalString();
	double getEvalListAt(int, int);
private:
	double evalList[2][100] = { 0 };
	const char* charList;
	int encodeOpt(char); // 
	void format();
	double stringToNumber(string);
};


#endif
