#include"stack.h"
#include"eval.h"
#include"formatEvalString.h"
#include<string>

int main(void)
{
	for (int l = 0; l < 100; l++)
	{
		cout << "请输入你的算术表达式(请用英文字符输入)：" << endl;
		string evalString;
		cin >> evalString;
		Eval E =  Eval();
		double result = E.eval(evalString);
		cout << "结果为：" << result << endl;
	}
	return 0;
}