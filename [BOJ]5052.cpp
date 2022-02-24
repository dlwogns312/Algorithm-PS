#include <iostream>
#include <cstring>
#include <string>

using namespace std;

bool result;

struct Trie {
	bool fin;
	Trie* next[10];

	Trie() : fin(false) {
		memset(next, 0, sizeof(next));
	}

	~Trie() {
		for (int i = 0; i < 10; i++)
			if (next[i])
				delete next[i];
	}

	void insert(char* str);
	bool find(char* str);

};

Trie* root;

void Trie::insert(char* str)
{
	if (*str == NULL)
	{
		fin = true;
		return;
	}
	int cur = *str - '0';
	if (next[cur] == NULL)
		next[cur] = new Trie();
	next[cur]->insert(str + 1);
}
bool Trie::find(char* str)
{
	if (*str == NULL)
		return true;
	if (fin == true)
		return false;
	int cur = *str - '0';
	return next[cur]->find(str + 1);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	char str[10000][11];
	

	while (t--)
	{
		int n;
		cin >> n;
		root = new Trie();
		for(int i=0;i<n;i++)
		{
			cin >> str[i];
		}

		for (int i = 0; i < n; i++)
		{
			root->insert(str[i]);
		}
		result = true;
		for (int i = 0; i < n; i++)
		{
			if (result)
				result = root->find(str[i]);
			else
				break;
		}
		if (result)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}