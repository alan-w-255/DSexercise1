#include"stack.h"
#include"eval.h"
#include"formatEvalString.h"
#include<string>

int main(void)
{
	for (int l = 0; l < 100; l++)
	{
		cout << "����������������ʽ\n"<<
			"(����Ӣ���ַ����� ����exit�������,��Ҫ����հ��ַ�)" << endl;
		string evalString;
		cin >> evalString;
		Eval E =  Eval();
		double result = E.eval(evalString);
		cout << "���Ϊ��" << result << endl;
	}
	return 0;
}