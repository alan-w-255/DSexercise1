#include"stack.h"

stack::stack()
{
	top = 0;

}

stack::~stack()
{
}

double stack::getTop()
{
	return S[top-1];
}
int stack::Top()
{
	return top;
}
int stack::push(double d)
{
	S[top] = d;
	top += 1;
	return 0;
}
double stack::pop()
{
	top -= 1;
	return S[top];
}
