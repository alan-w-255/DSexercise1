#pragma once
/*
�Ա�׼������ַ����д���
�Ȱѱ��ʽ�洢��һ���ַ������У�
����һ��double�Ͷ�ά�����ʾһ���������ʽ
��һά��¼Ԫ�ص�˳����ǲ������������ֵı�ʶ
�ڶ�ά��¼���ֻ��߲�������
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
