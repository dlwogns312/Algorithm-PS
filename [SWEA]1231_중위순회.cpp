/////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<vector>
#include<string>

using namespace std;

typedef struct tree
{
	char data;
	int left;
	int right;
}tree;

vector<tree>v;

void inorder(int pointer)
{
	if (pointer)
	{
		inorder(v[pointer].left);
		cout << v[pointer].data ;
		inorder(v[pointer].right);
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
		int ori_n;
		cin >> n;
		v.resize(n + 1);

		ori_n = n;
		for (int i = 1; i <= n; i++)
		{
			v[i].data = 0;
			v[i].left = 0;
			v[i].right = 0;
		}
		string str;
		int temp,a,b;
		for (int i = 1; i < (n+1)/2; i++)
		{
			cin >> temp;
			cin  >> str >> a >> b;

			v[temp].data = str[0];
			v[temp].left = a;
			v[temp].right = b;
		}
		if (n % 2==0)
		{
			cin >> temp;
			cin >> str >> a;

			v[temp].data = str[0];
			v[temp].left = a;
			n++;
		}
		for (int i = (n + 1) / 2; i <= ori_n; i++)
		{
			cin >> temp >> str;
			v[temp].data = str[0];
		}


		cout << "#" << test_case << " ";
		inorder(1);
		cout << "\n";

		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}