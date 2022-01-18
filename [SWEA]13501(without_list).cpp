
#include<iostream>
#include<list>

using namespace std;

typedef struct node
{
	int data;
	struct node* next;
}buffer;

void insert(buffer* get, int data, buffer* next)
{
	buffer* temp = (buffer*)malloc(sizeof(buffer));
	temp->data = data;
	temp->next = next;
	get->next = temp;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		buffer* head = (buffer*)malloc(sizeof(buffer));
		head->next = NULL;

		int n, m, l, tmp;
		cin >> n >> m >> l;
		buffer* temp = head;

		while (n--)
		{
			cin >> tmp;
			insert(temp, tmp, 0);
			temp = temp->next;
		}
		while (m--)
		{
			char c;
			cin >> c;
			if (c == 'I')
			{
				int x, y;
				cin >> x >> y;

				temp = head;
				for (int i = 0; i < x; i++)
					temp = temp->next;
				insert(temp, y, temp->next);
			}
			else if (c == 'D')
			{
				int x;
				cin >> x;

				temp = head;
				for (int i = 0; i < x; i++)
					temp = temp->next;
				temp->next = temp->next->next;
			}
			else
			{
				int x, y;
				cin >> x >> y;
				temp = head->next;
				for (int i = 0; i < x; i++)
					temp = temp->next;
				temp->data = y;
			}
		}
		temp = head->next;
		for (int i = 0; i < l; i++)
		{
			if (temp->next == NULL)
			{
				temp = NULL;
				break;
			}
			else
				temp = temp->next;
		}
		if (!temp)
			cout << "#" << test_case << " " << -1 << endl;
		else
			cout << "#" << test_case << " " << temp->data << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}