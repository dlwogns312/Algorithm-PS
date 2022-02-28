#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct Trie {
	bool fin;
	Trie* next[26];

	Trie() : fin(false) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i])
				delete(next[i]);
	}

	void insert(char* key) {
		if (*key == '\0')
			fin = true;
		else
		{
			int cur = *key - 'a';
			if (next[cur] == NULL)
				next[cur] = new Trie();
			next[cur]->insert(key + 1);
		}
	}

	bool find(char* key) {
		if (*key == '\0')
		{
			if (fin)
				return true;
			return false;
		}
		int cur = *key - 'a';
		if (next[cur] == NULL)
			return false;
		return next[cur]->find(key + 1);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n,m;
	cin >> n >> m;
	Trie* root = new Trie();
	char temp[501];

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		root->insert(temp);
	}

	int cnt = 0;

	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		if (root->find(temp))
			cnt++;
	}

	cout << cnt << "\n";


	return 0;
}