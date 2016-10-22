#include"formatEvalString.h"
extern int priList[];

formatEvalString::formatEvalString(string s) 
{
	charList = s.c_str();
	format();
}
formatEvalString::~formatEvalString() {}

double formatEvalString::getEvalListAt(int i, int j)
{
	return evalList[i][j];
}

// + - * / ^ ( )  ����Ϊ 1 2 3 4 5 6 7;
int formatEvalString::encodeOpt(char ch)
{
	switch (ch)
	{
	case '+': return 1; break;
	case '-': return 2; break;
	case '*': return 3; break;
	case '/': return 4; break;
	case '^': return 5; break;
	case '(': return 6; break;
	case ')': return 7; break;
	default:
		break;
	}
}

void formatEvalString::format()
{
	int i = 0;
	int j = 0;
	char ch;
	while ((ch = charList[i]) != '\0')//�����������ʽ�ַ����飻
	{
		//��������֣���˳����ַ�ת����double�ʹ���charlist��,��־λ��Ϊ0��
		if (ch<= '9' && ch >= '0' || ch == '.')
		{
			string s;
			s.append(1, ch);
			if (!(charList[i + 1] <= '9' && charList[i + 1] >= '0'))
			{
				
				evalList[0][j] = 0;
				evalList[1][j] = stringToNumber(s);
				j++;
				s.clear();
			}
		}
		//�����+ - * / ^, ����Ϊ 1 2 3 4 5 ��־λ��Ϊ 1��
		else if (ch == '+' || ch == '-' || ch == '*'
			|| ch == '/'  || ch == '^')
		{
			evalList[0][j] = 1;
			evalList[1][j] = encodeOpt(ch);
			j++;
		}
		else if (ch == '(')
		{
			evalList[0][j] = 2;
			j++;

		}
		else if (ch == ')')
		{
			evalList[0][j] = 3;
			j++;
		}
		else if (ch == ' ' || ch == '\\t' || ch == ';')
		{
			;
		}
		else
		{
			throw("error: unknow syntax");
			exit(1);
		}
		i++;
	}
	evalList[0][j] = 4;
}

double formatEvalString::stringToNumber(string & str)
{
	istringstream iss(str);
	double num;
	iss >> num;
	return num;
}

