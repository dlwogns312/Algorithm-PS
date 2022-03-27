#include <iostream>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

struct node
{
	int score, num;
};

bool cmp(node a, node b)
{
	return a.score > b.score;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<node> arr(8);

	for (int i = 0; i < 8; i++)
	{
		int temp;
		cin >> temp;
		arr[i].score = temp;
		arr[i].num = i + 1;
	}

	sort(arr.begin(), arr.end(), cmp);
	int result = 0;
	set<int>save;
	for (int i = 0; i < 5; i++)
	{
		result += arr[i].score;
		save.insert(arr[i].num);
	}

	cout << result << "\n";
	for (auto iter = save.begin(); iter != save.end(); iter++)
		cout << *iter << " ";


}