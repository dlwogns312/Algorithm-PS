
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, m;
		cin >> n >> m;

		int temp = 1 << n;
		temp--;


		int result = m & temp;
		result ^= temp;

		if (!result)
			printf("#%d ON\n", test_case);
		else
			printf("#%d OFF\n", test_case);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}