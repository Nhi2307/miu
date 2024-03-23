#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define _use_CRT_SECURE_NO_WARNINGS
typedef int ItemType;
//khoi tao SNode
struct SNode {//dinh nghia kieu dl cho 1 nut cua dslk don la SNode
	ItemType Info;//luu thong tin cua nut hien hanh
	SNode* Next;//con tro chi den nut ke sau
};
//khoi tao dslk don
struct SList
{
	SNode* Head;//luu dia chi dau tien trong SList
	SNode* Tail;//luu dia chi cuoi cung trong SList
};
//tao nut chua gia tri x
SNode* createSNode(ItemType x)
{
	SNode* p = new SNode;
	if (p == NULL)
	{
		printf("khong du bo nho de cap phat nut moi!");
		_getch();
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}
//xuat noi dung cua nut
void showSNode(SNode* p)
{
	printf("%d", p->Info);
}
//xoa nut khoi bo nho
void deleteSNode(SNode* p) {
	if (p == NULL) return;
	p->Next = NULL;
	delete p;
}
//khoi tao danh sach rong
void initSList(SList& sl)
{
	sl.Head = NULL;
	sl.Tail = NULL;
}
//kiem tra dslk don rong
int isEmpty(SList sl)
{
	if (sl.Head == NULL)
		return 1; //neu ds rong
	else
		return 0;//neu ds khong rong
}
//duyet danh sach
void showSList(SList sl)
{
	if (isEmpty(sl) == 1)
	{
		printf("\n danh sach rong!");
		return;
	}
	printf("\nnoi dung danh sach la:\t");
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
		showSNode(p);
}
//them nut p co gia tri x vao cuoi ds
int insertTail(SList& sl, SNode* p)
{
	if (p == NULL)
		return 0;//thuc hien khong thanh cong
	if (isEmpty(sl) == 1) {
		sl.Head = p;
		sl.Tail = p;
	}
	else
	{
		sl.Tail->Next = p;
		sl.Tail = p;
	}
	return 1;//thuc hien thanh cong
}
// Hàm ?? chèn ph?n t? x vào tr??c ph?n t? y trong m?ng arr
void chenTruoc(SList& sl, ItemType x, ItemType y) {
	SNode* newNode = createSNode(x);
	if (isEmpty(sl)) {
		sl.Head = newNode;
		sl.Tail = newNode;
		return;
	}

	SNode* prev = NULL;
	SNode* current = sl.Head;

	while (current != NULL && current->Info != y) {
		prev = current;
		current = current->Next;
	}

	if (current == NULL) {
		// Không tìm th?y giá tr? y trong danh sách
		printf("Khong tim thay phan tu co gia tri y trong danh sach.");
		delete newNode;
		return;
	}
	if (prev == NULL) {
		// Nút ch?a giá tr? y là nút ??u tiên c?a danh sách
		newNode->Next = sl.Head;
		sl.Head = newNode;
	}
	else {
		// Chèn newNode vào tr??c nút ch?a giá tr? y
		prev->Next = newNode;
		newNode->Next = current;
	}
}
void showMenu()
{
	printf("\n***********************************");
	printf("\n               MENU                ");
	printf("\n1.Them nut vao cuoi danh sach.");
	printf("\n2. Chen truoc phan tu");
	printf("\n9.Duyet danh sach");
	printf("\n0.Thoat chuong trinh.");
	printf("\n**************************");
}
int main()
{
	SList sl;
	initSList(sl);
	int choice;
	SNode* newNode;
	SNode* searchNode;
	ItemType x, y;
	do
	{
		showMenu();
		printf("\nNhap lua chon cua ban:");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			int m;
			printf("Nhap so ban muon nhap:");
			scanf_s("%d", &m);
			newNode = createSNode(m);
			insertTail(sl, newNode);
			break;
		case 2:
			printf("Nhap gia tri can chen (x): ");
			scanf_s("%d", &x);
			printf("Nhap gia tri muc tieu (y): ");
			scanf_s("%d", &y);
			chenTruoc(sl, x, y);
			break;
		case 9:
			showSList(sl);
			break;
		case 0:
			printf("Thoat chuong trinh.");
		default:
			printf("Lua cho khong hop le !");
		}
	} while (choice != 0);
	return 0;
}
