
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	int mod[8] = { 50000,10000,5000,1000,500,100,50,10 };
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		int arr[8] = { 0, };

		cin >> n;

		for (int i = 0; i < 8; i++)
		{
			arr[i] = n / mod[i];
			n %= mod[i];
		}
		
		cout << "#" << test_case << endl;

		for (int i = 0; i < 8; i++)
			cout << arr[i] << " ";
		cout << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}