
#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

typedef struct tree
{
	char data;
	int value;
	int left;
	int right;
}tree;

vector<tree>v;

int check_num(char c)
{
	if (c >= '0' && c <= '9')
		return 1;
	else
		return 0;
}

int postorder(int idx)
{
	switch (v[idx].data)
	{
	case '+':
		return postorder(v[idx].left) + postorder(v[idx].right);
		break;
	case '-':
		return postorder(v[idx].left) - postorder(v[idx].right);
		break;
	case '*':
		return postorder(v[idx].left) * postorder(v[idx].right);
		break;
	case '/':
		return postorder(v[idx].left) / postorder(v[idx].right);
		break;
	default:
		return v[idx].value;
		break;
	}
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int test_case;
	int T;
	
	T = 10;
	int n;
	

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		v.resize(n + 1);
		
		string str;
		int temp,a,b;
		
		for (int i = 0; i < n; i++)
		{
			cin >> temp >> str;
			if (!check_num(str[0]))
			{
				cin >> a >> b;
				v[temp] = { str[0],0,a,b };
				continue;
			}

			/*a = str[0] - '0';
			for (int j = 1; str[j] != NULL; j++)
				a = (a * 10) + str[j] - '0';*/

			v[temp] = { 0,stoi(str),0,0 };
		}

		cout << "#" << test_case << " " << postorder(1) << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}