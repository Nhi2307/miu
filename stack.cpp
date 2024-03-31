#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//khai baos Stack
typedef int ItemType;//dinh nghia kieu dl cua mot phan tu
struct StackNode
{
	//ding nghia kieu dl cho 1 nut cua Stack la StackNode
	ItemType Info;
	StackNode* Next;
};
struct Stack
{
	//dinh nghia kieu dl cho Stack
	StackNode* Tp;
};
//tao mot nut moi cho Stack
StackNode* createStackNode(ItemType x)
{
	StackNode* p = new StackNode;
	if (p == NULL)
	{
		printf("khong du bo nho de cap phat!");
		_getch();
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}
//3. Khoi tao Stack
void intiStack(Stack& s)
{
	//inititalize Stack
	s.Tp = NULL;
}
//4. Kiem tra Stack rong
int isEmpty(Stack s) //Stack co rong hay khong
{
	if (s.Tp == NULL) //Neu Stack rong
		return 1;
	else
		return 0; //Neu Stack khong rong
}
void main()
{
	ItemType x;
	Stack myStack;
	intiStack(myStack);
	if (isEmpty(myStack))
		printf("Stack la rong\n");
	else
		printf("Stack khong rong\n");
}
