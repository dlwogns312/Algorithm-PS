/// *** user.cpp ***
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 50000
#define WORD_MAXLEN 11

unordered_set<string> used;
unordered_map<char, set<string>> word_list;
vector<string> round_end;
int arr[MAXN+1];
int n, m;

void init(int N, int M, char words[50000][WORD_MAXLEN]) {
	n = N; m = M;

	used.clear(); word_list.clear(); round_end.clear();
	memset(arr, 0, sizeof(arr));

	for (int i = 0; i < m; i++)
	{
		word_list[words[i][0]].insert(words[i]);
	}
}
void reset()
{
	for (int i = 0; i < round_end.size(); i++)
	{
		string str = round_end[i];
		reverse(str.begin(), str.end());

		if(used.find(str)==used.end())
			word_list[str[0]].insert(str);
	}

	round_end.clear();
}
int playGame(int playerId, char startChar) {
	int ret;

	while (1)
	{
		if (playerId > n)
			playerId = 1;

		if (arr[playerId])
		{
			playerId++;
			continue;
		}

		if (word_list[startChar].empty())
		{
			arr[playerId]++;
			reset();
			return playerId;
		}

		auto it = word_list[startChar].begin();
		
		string str = *it;
		word_list[startChar].erase(it);
		round_end.push_back(str);
		used.insert(str);
		
		playerId++;
		startChar = str[str.length() - 1];
	}

}