#include <iostream>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int k;
queue<string>q;

void myswap(string& mystr, int left, int right)
{
	char temp = mystr[left];
	mystr[left] = mystr[right];
	mystr[right] = temp;
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str >> k;
	q.push(str);

	for (int i = 0; i < k; i++)
	{
		set<string>s;
		int qsize = q.size();

		for (int j = 0; j < qsize; j++)
		{
			string temp = q.front();
			q.pop();
			if (s.count(temp))
				continue;

			s.insert(temp);
			
			for(int l=0;l<temp.size()-1;l++)
				for(int r=l+1;r<temp.size();r++)
					if (!(l == 0 && temp[r] == '0'))
					{
						myswap(temp, l, r);
						q.push(temp);
						myswap(temp, l, r);
					}
		}
	}
	
	string ans = "0";
	while (!q.empty())
	{
		ans = max(ans, q.front());
		q.pop();
	}
	if (ans[0] == '0')
		cout << "-1";
	else
		cout << ans;
	return 0;

}