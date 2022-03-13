#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

#define MOD 1000000

using namespace std;
int result[5001] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;

	int temp = 0;
	int check = 1;
	if (str[0] - '0' == 0)
		check = 0;
	temp = str[0] - '0';
	result[1] = 1;
	result[0] = 1;
	if (check) {
		for (int i = 2; i <= str.length(); i++)
		{
			if(str[i-1]-'0'!=0)
				result[i] = result[i - 1];
			temp = temp * 10 + (str[i - 1] - '0');
			if (str[i - 1] - '0' == 0 && temp > 26)
			{
				check = 0;
				break;
			}
			if (temp <= 26&&temp>=10)
				result[i] = (result[i] + result[i - 2]) % MOD;
			temp = str[i - 1] - '0';
		}
	}
	if (check)
		cout << result[str.length()] << "\n";
	else
		cout << 0 << "\n";
	
	
	return 0;

}