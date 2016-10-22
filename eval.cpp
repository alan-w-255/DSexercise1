#include"Eval.h"
#include<math.h>

Eval::Eval(){}
Eval::~Eval(){}


//��������֣�ѹ����������ջ������pushANumber()
//������ȼ�ջ��ջ��Ԫ��С��opt ���� �ǿ�ջ��
// �Ͱ�opt������ѹ�������ջ
//������ȼ�ջ���ڻ����opt���������ȼ������ߺ���û�в�������
// ����ջ�ﵯ��������,�ڲ�����ջ����һ�������������㣬�����ȼ�ջ����һ�����ȼ����ѽ��ѹ������ջ�С�����popAndCal()
//Ȼ������Ƚ����ȼ�ջ����opt���������ȼ���С�������Ȼ���ڣ��ظ��������
// ֱ�����ȼ�ջ��С��opt �������ȼ������򣬺���û�в������ˡ�
// �ٰ�opt������ѹ�������ջ,�ٰ����ȼ�ѹ��ջ��
double Eval::eval(string s)
{
	formatEvalString fes(s);
	int i = 0;
	do
	{
		double t = fes.getEvalListAt(0, i);//��־�� 0 1 2 3 4 stand for "digital" "optional" "(" ")" "ending"
		double a = fes.getEvalListAt(1, i);//1��2�� 3�� 4�� 5���������+-*/^
		//���������
		if (t == 0)
		{
			pushANumber(a);
		}
		//����ǲ�����
		else if (t == 1)
		{
			//������������ȼ�����ջ��Ԫ��
			if ((int)opts.Top() == 0 || getPri((int)a) > pri.getTop())
			{
				pushOptsAndPri((int)a);
			}
			//������������ȼ�С�ڵ���ջ��Ԫ�أ�
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
