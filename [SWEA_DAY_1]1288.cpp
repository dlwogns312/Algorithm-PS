
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int check = 0b1111111111;
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{

		int get;
		cin >> get;

		int set = 0;
		int temp = get;
		int ch;
		int dig;

		while (1)
		{ 
			ch = 1;
			while (ch<=get)
			{
				dig = (get % (ch * 10) - get % ch) / ch;
				set |= (1 << dig);
				ch *= 10;
			}
			if (check == set)
				break;
			get += temp;
			
		}

		printf("#%d %d\n", test_case, get);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}