#include"Eval.h"
#include<math.h>

Eval::Eval(){}
Eval::~Eval(){}


//如果是数字；压数字入数字栈；——pushANumber()
//如果优先级栈的栈顶元素小于opt 或者 是空栈；
// 就把opt操作符压入操作符栈
//如果优先级栈大于或等于opt操作的优先级，或者后面没有操作符了
// 数字栈里弹出两个数,在操作符栈弹出一个操作符做运算，从优先级栈弹出一个优先级，把结果压入数字栈中。——popAndCal()
//然后继续比较优先级栈顶与opt操作的优先级大小，如果仍然大于，重复上面操作
// 直到优先级栈顶小于opt 操作优先级，或则，后面没有操作符了。
// 再把opt操作符压入操作符栈,再把优先级压入栈。
double Eval::eval(string s)
{
	formatEvalString fes(s);
	int i = 0;
	do
	{
		double t = fes.getEvalListAt(0, i);//标志符 0 1 2 3 4 stand for "digital" "optional" "(" ")" "ending"
		double a = fes.getEvalListAt(1, i);//1，2， 3， 4， 5代表操作符+-*/^
		//如果是数字
		if (t == 0)
		{
			pushANumber(a);
		}
		//如果是操作数
		else if (t == 1)
		{
			//如果操作数优先级大于栈顶元素
			if ((int)opts.Top() == 0 || getPri((int)a) > pri.getTop())
			{
				pushOptsAndPri((int)a);
			}
			//如果操作数优先级小于等于栈顶元素；
			else if (getPri((int)a) <= pri.getTop())
			{
				while ((int)opts.Top() != 0 && getPri((int)a) < pri.getTop())
				{
					popAndCal();
				} 
				pushOptsAndPri((int)a);
			}
		}
		else if (t == 2)
		{
			incPriList();
		}
		else if (t == 3)
		{
			decPriList();
		}
		else if (t == 4)
		{
			while ((int)numbers.Top() != 1)
			{
				popAndCal();
			}
			return numbers.getTop();
		}
		else
		{

		}
		i++;
	} while (1);

}
double Eval::cal(double x, double y, int opt)
{
	switch (opt)
	{
	case 1: return x + y; break;
	case 2: return x - y; break;
	case 3: return x * y; break;
	case 4: return x / y; break;
	case 5: return pow(x,y); break;
	default:
		break;
	}
}

int Eval::getPri(int opt)
{
	switch (opt)
	{
	case 1:return PriList[0]; break;
	case 2:return PriList[1]; break;
	case 3:return PriList[2]; break;
	case 4:return PriList[3]; break;
	case 5:return PriList[4]; break;
	case 6:return PriList[5]; break;
	default:return -1;
		break;
	}
}

void Eval::popAndCal()
{
	double tresult = cal(numbers.pop(), numbers.pop(), (int)opts.pop());
	pri.pop();
	numbers.push(tresult);
}

void Eval::pushOptsAndPri(int topt)
{
	opts.push(topt);
	pri.push(PriList[topt]);
}

void Eval::pushANumber(double num)
{
	numbers.push(num);
}

void Eval::incPriList()
{	
	for (int k = 0; k < 5; k++)
	{
		PriList[k] += 9;
	}
}

void Eval::decPriList()
{
	for (int k = 0; k < 5; k++)
	{
		PriList[k] -= 9;
	}
}
