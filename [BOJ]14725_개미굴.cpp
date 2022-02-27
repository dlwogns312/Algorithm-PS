#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct Trie {

	map<string, Trie*>m;

	Trie() {}
	~Trie() {
		for (map<string, Trie*>::iterator iter = m.begin(); iter != m.end(); iter++)
			delete(*iter).second;
	}

	void insert(vector<string>& v, int idx)
	{
		if (v.size() == idx)
			return;

		if (m.find(v[idx]) == m.end())
		{
			m.insert({ v[idx], new Trie() });
			m[v[idx]]->insert(v, idx + 1);
		}
		else
			m[v[idx]]->insert(v, idx + 1);
	}

	void find(int depth) {
		for (map<string, Trie*>::iterator iter = m.begin(); iter != m.end(); iter++) {
			for (int i = 0; i < depth; i++)
				cout << "--";
			cout << (*iter).first << "\n";

			(*iter).second->find(depth + 1);
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	Trie* root = new Trie();

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		vector<string>v(x);

		for (int j = 0; j < x; j++)
			cin >> v[j];

		root->insert(v, 0);
	}
	
	root->find(0);
	delete root;
	return 0;
}