#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <vector>
#include <string>
using namespace std;

#define max(a,b) a>b?a:b

int result;
int num;

string str;

void dfs(int idx, int cur)
{
	if (cur == num)
	{
		result = max(result, stoi(str));
		return;
	}
	for (int i = 0; i < str.size(); i++)
	{
		for (int j = i + 1; j < str.size(); j++)
		{
			swap(str[i], str[j]);
			dfs(i, cur + 1);
			swap(str[j], str[i]);
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	

	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		
		result = 0;

		cin >> str;
		cin >> num;
		
		if (num > str.size())
			num = str.size();

		dfs(0, 0);

		cout << "#" << test_case << " " << result <<endl;
		

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}