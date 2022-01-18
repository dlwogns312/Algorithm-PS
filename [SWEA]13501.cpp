
#include<iostream>
#include<list>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		list<int> lt;
		int n, m, l;
		cin >> n >> m >> l;
		int temp;
		auto itr=lt.begin();

		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			lt.push_back(temp);
		}
		
		while (m--)
		{
			char c;
			cin >> c;
			if (c == 'D')
			{
				int x;
				cin >> x;
				itr = lt.begin();
				for (int i = 0; i < x; i++)
					itr++;
				lt.erase(itr);
			}
			else if (c == 'I')
			{
				int x, y;
				cin >> x >> y;
				itr = lt.begin();
				for (int i = 0; i < x; i++)
					itr++;
				lt.insert(itr, y);
			}
			else
			{
				int x, y;
				cin >> x >> y;
				itr = lt.begin();
				for (int i = 0; i < x; i++)
					itr++;
				*itr = y;
			}

		}
		if (lt.size() < l)
			cout << "#" << test_case << " " << -1 << endl;
		else
		{
			itr = lt.begin();
			for (int i = 0; i < l; i++)
				itr++;
			cout << "#" << test_case << " " << *itr << endl;
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}