#include "ListFuncs.h"

/*
 Даны два упорядоченных списка, в которых могут быть одинаковые
 элементы.Разработать функцию создания одного общего
 упорядоченного списка, исключив повторяющиеся элементы. */

void EnterAndCheckInput(int*); /*Праверка увода*/

int main(int argc, char* argv[])
{
	struct node* list1Root = NULL, * list2Root = NULL;
	struct node* list1 = NULL, * list2 = NULL;

	int i = 0;
	int n1 = 0;
	printf("Size of first list = ");       	   /*Увод першага спіса*/
	EnterAndCheckInput(&n1);   /*Праверка ўвода*/
	printf("Enter elements of first list:\n");
	for (i = 0; i < n1; i++)
	{
		int x = 0;
		scanf("%d", &x);
		if (list1Root == NULL)
		{
			list1Root = (struct node*)malloc(sizeof(struct node));
			MemoryCheck(list1Root);          /*Праверка выдзялення памяці*/
			list1Root->element = x;
			list1Root->next = list1;
		}
		else
			list1 = AddElement(list1Root, x);
	}
	while (getchar() != '\n');

	int n2 = 0;
	printf("\nSize of second list = ");        /*Увод другога спіса*/
	EnterAndCheckInput(&n2);   /*Праверка ўвода*/
	printf("Enter elements of second list:\n");
	for (i = 0; i < n2; i++)
	{
		int x = 0;
		scanf("%d", &x);
		if (list2Root == NULL)
		{
			list2Root = (struct node*)malloc(sizeof(struct node));
			MemoryCheck(list2Root);          /*Праверка выдзялення памяці*/
			list2Root->element = x;
			list2Root->next = list2;
		}
		else
			list2 = AddElement(list2Root, x);
	}
	while (getchar() != '\n');

	system("cls");
	printf("\nFirst list after sort:\n");   /*Сартыроўка і вывад першага спіса*/
	list1Root = Sort(list1Root);
	ShowList(list1Root);
	printf("\nSecond list after sort:\n");  /*Сартыроўка і вывад другога спіса*/
	list2Root = Sort(list2Root);
	ShowList(list2Root);
	DeleteDuplicateElements(list1Root);  /*Выдаленне паўтараючыхся элементаз са спіса*/
	DeleteDuplicateElements(list2Root);
	struct node* generalListRoot = NULL, * generalList = NULL;
	generalListRoot = PlusList(list1Root, generalListRoot);  /*Далучэнне да агульнага спіса спісу №1*/
	generalListRoot = PlusList(list2Root, generalListRoot);  /*Далучэнне да агульнага спіса спісу №2*/
	generalListRoot = Sort(generalListRoot);       	/*Сартыроўка агульнага спісу*/
	DeleteDuplicateElements(generalListRoot);       /*Выдаленне дубляў*/
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~ ~ General list: ~ ~~~~~~~~~~~~~~~~~~~~~~~~~\n"); /*Вывад агульнага спіса*/
	ShowList(generalListRoot);
	printf("\n");

	free(list1Root);
	free(list2Root);
	return 0;
}

void EnterAndCheckInput(int* a)
{
	while (!scanf("%d", &(*a)))
	{
		printf("Wrong input! Try again :)\n");
		while (getchar() != '\n');
		printf("..new input: ");
	}
	while (getchar() != '\n');
}
