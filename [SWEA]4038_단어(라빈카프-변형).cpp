#include<iostream>
#include<cstring>

typedef long long ll;

using namespace std;

char b[500001], s[100001];

int n, m;

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
		cin >> b >> s;
		result = 0;
		ll com[5] = { 0, };
		ll temp[5] = { 0, };
		ll mod[5]{ 1,1,1,1,1 };

		int s_len = strlen(s), b_len = strlen(b);

		for (int i = 0; i < s_len; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				com[j] = com[j] * (j+1) + s[i];
				temp[j] = temp[j] * (j+1) + b[i];
				mod[j] *= (j+1);
			}
		}
		
		for (int j = 0; j < 5; j++)
			mod[j] = mod[j]/(j+1);

		int flag=1;
		for(int i=0;i<5;i++)
			if (com[i] != temp[i])
			{
				flag = 0;
				break;
			}
		if (flag)
			result++;
		
		for (int i = 1; i < b_len - s_len + 1; i++)
		{
			flag = 1;
			for (int j = 0; j < 5; j++)
			{
				temp[j] = (temp[j] - mod[j] * b[i - 1]) * (j+1) + b[s_len + i - 1];
				if (temp[j] != com[j])
					flag = 0;
			}
			if (flag)
				result++;
			
		}

		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}