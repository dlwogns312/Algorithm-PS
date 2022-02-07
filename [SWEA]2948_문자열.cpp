#include<iostream>

#define H_size (1<<18)
#define Maxn 100000
#define div (H_size-1)

using namespace std;

int n, m;
int nodecnt;

void Strcpy(char* empty, char* str)
{
	while (*str)
		*empty++ = *str++;
	*empty = 0;
	return;
}

bool Strcmp(char* stra, char* strb)
{
	while (*stra)
	{
		if (*stra++ != *strb++)
			return false;
	}
	return *stra == *strb;
}
struct node
{
	char key[51];
	node* next;
	node* alloc(char* _str, node* _next)
	{
		Strcpy(key, _str);
		next = _next;
		return this;
	}
}nodes[Maxn];

node* hashtable[H_size];

void init()
{
	nodecnt = 0;
	for (int i = 0; i < H_size; i++)
		hashtable[i]=nullptr;
}

int getkey(char* str)
{
	unsigned long long key = 5381;
	for (int i = 0; str[i]; i++)
		key = ((key << 5) + key) + (str[i] - 'a' + 1);

	return (int)(key & div);
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	int T;

	cin >> T;
	
	int result;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> n >> m;
		result = 0;
		
		char str[51];

		for (int i = 0; i < n; i++)
		{
			cin >> str;
			int temp = getkey(str);
			hashtable[temp] = nodes[nodecnt++].alloc(str, hashtable[temp]);
		}

		for (int i = 0; i < m; i++)
		{
			cin >> str;
			int wh = getkey(str);

			for(node*  temp=hashtable[wh];temp;temp=temp->next)
				if (Strcmp(temp->key,str))
				{
					result++;
					break;
				}
		}

		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}