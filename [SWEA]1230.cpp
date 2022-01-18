#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<list>
using namespace std;



int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	//cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, x, y, s;
		char c;
		list<int>lt;

		auto itr = lt.begin();

		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> x;
			lt.push_back(x);
		}

		cin >> n;
		while (n--)
		{
			cin >> c;
			if (c == 'I')
			{
				list<int> temp;
				itr = lt.begin();
				cin >> x >> y;
				for (int i = 0; i < x; i++)
					itr++;

				for (int i = 0; i < y; i++)
				{
					cin >> s;
					temp.push_back(s);
				}
				lt.splice(itr, temp);
			}

			else if (c == 'D')
			{
				itr = lt.begin();
				cin >> x >> y;
				for (int i = 0; i < x; i++)
					itr++;
				for (int i = 0; i < y; i++)
					itr = lt.erase(itr);
			}

			else
			{
				cin >> y;
				for (int i = 0; i < y; i++)
				{
					cin >> s;
					lt.push_back(s);
				}
			}
		}

		itr = lt.begin();
		cout << "#" << test_case << " ";
		for (int i = 0; i < 10; i++)
		{
			cout << *itr << " ";
			itr++;
		}
		cout << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}