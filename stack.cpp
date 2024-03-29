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
void main()
{
	ItemType x;
}