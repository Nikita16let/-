#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
#include<queue>
int* visited = NULL;
int a = 0;
struct list_node
{
	struct list_node* next;
	int num;
};
int size_list = 0;
struct list_node *head;
struct list_node* tail;
void BFC(int** matrix, int start);
void BFC_q(int** matrix, int start);
void createList(void);
void push(int data);
int pop();
void main()
{
	setlocale(LC_ALL, "Rus");
	int** matrix = NULL;
	int i = 0;
	int j = 0;
	int sum = 0;
	printf_s("Введите количество вершин: ");
	scanf_s("%d", &a);
	srand(time(NULL));
	matrix = (int**)malloc(a * sizeof(int));
	visited = (int*)malloc(a * sizeof(int));
	for (i = 0; i < a; i++) visited[i] = 0;
	for (i = 0; i < a; i++)
	{
		matrix[i] = (int*)malloc(a * sizeof(int));
	}
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < a; j++)
		{
			if (i == j)
			{
				matrix[i][j] = 0;
				continue;
			}

			if (rand() % 21 > 10) matrix[i][j] = 1;
			else matrix[i][j] = 0;
			matrix[j][i] = matrix[i][j];
		}

	}

	printf_s("Матрица:\n");
	for (i = 0; i < a; i++)
	{
		printf_s("%d|", i);
		for (j = 0; j < a; j++)
		{
			printf_s("%d ", matrix[i][j]);
		}
		printf_s("\n");
	}
	printf_s("Введите стартовый узел:");
	int start = 0;
	scanf_s("%d", &start);
	printf_s("Обход с использованием queue;\n");
	BFC(matrix, start);
	for (i = 0; i < a; i++) visited[i] = 0;
	printf_s("\nОбход с использованием самостоятельно написанных функций:\n");
	BFC_q(matrix, start);
}

void BFC(int** matrix, int start)
{
	int st = 0;
	st = start;
	queue <int> Q;
	visited[st] = 1;
	Q.push(st);
	while (!Q.empty())
	{
		st = Q.front();
		Q.pop();
		printf_s("%d", st);
		for (int i = 0; i < a; i++)
		{
			if (matrix[st][i] == 1 && visited[i] == 0)
			{
			Q.push(i);
			visited[i] = 1;
			}
			
		}
	}
}
void BFC_q(int** matrix, int start)
{
	int st = 0;
	st = start;
	visited[st] = 1;
	push(st);
	while (size_list!=0)
	{
		st = pop();
		printf_s("%d", st);
		for (int i = 0; i < a; i++)
		{
			if (matrix[st][i] == 1 && visited[i] == 0)
			{
				push(i);
				visited[i] = 1;
			}

		}
	}
}

void createList(void)
{
	head = NULL;
	tail = NULL;
}
void push(int data)
{
	struct list_node* lt = (struct list_node*)malloc(sizeof(struct list_node));
	lt->num = data;
	if (head == NULL)
	{
		head = lt;
		head->next = NULL;
		tail = head;
	}	
	else
	{
      tail->next = lt;
	  tail = lt;
	  tail->next = NULL;
	}
	size_list = ++size_list;
}
int pop()
{
	int data = 0;
	struct list_node* elem = head;
	data = elem->num;
	size_list = --size_list;
	head = head->next;
	free(elem);
	return data;
}