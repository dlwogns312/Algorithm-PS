#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

typedef struct Node
{
	int data;
	struct Node* next;
}buffer;


void node(buffer* get, int data)
{
	buffer* temp = (buffer*)malloc(sizeof(buffer));
	temp->data = data;
	temp->next = NULL;
	get->next = temp;
}

void insert(buffer* get, int data, buffer* ne)
{
	buffer* temp = (buffer*)malloc(sizeof(buffer));
	temp->data = data;
	temp->next = ne;
	get->next = temp;
}

int main(int argc, char** argv)
{
	int test_case;
	int T=10;
	
	//cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		int temp;
		
		buffer* head=NULL;

		buffer* save=NULL;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			if (!head)
			{
				head = (buffer*)malloc(sizeof(buffer));
				head->data = temp;
				head->next = NULL;
				save = head;
			}
			else
			{
				node(save, temp);
				save = save->next;
			}
		}
		
		cin >> n;


		for (int i = 0; i < n; i++)
		{
			int where = 1;
			char c; cin >> c;
			int x; cin >> x;
			int y; cin >> y;
			
			save = head;
			if (!x)
			{
				buffer* ins = (buffer*)malloc(sizeof(buffer));
				y--;
				cin >> temp;
				ins->data = temp;
				ins->next = save;
				head = ins; save = head;

				while (y--)
				{
					cin >> temp;
					insert(save, temp, save->next);
					save = save->next;
				}
			}
			else {
				while (where != x)
				{
					save = save->next;
					where++;
				}
				while (y--)
				{
					cin >> temp;
					insert(save, temp, save->next);
					save = save->next;
				}
			}
		}
		save = head;

		printf("#%d ", test_case);
		for (int i = 0; i < 10; i++)
		{
			printf("%d ", save->data);
			save = save->next;
		}
		printf("\n");
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}