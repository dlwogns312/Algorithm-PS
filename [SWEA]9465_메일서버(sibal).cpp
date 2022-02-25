#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

#define HASH_SIZE (1<<18)
#define DIV (HASH_SIZE-1)

typedef unsigned long long ll;



vector<int> user[1001];

int email[10000][10];
int total_email[10000];
int n, k;
int now;


void init(int N, int K)
{
	n = N; k = K;
	memset(user, 0, sizeof(user));
	now = 0;
}

void sendMail(char subject[], int uID, int cnt, int rlDs[])
{
	ll key = 5381;
	int email_cnt = 0;
	total_email[now] = 0;

	for (int i = 0; i < cnt; i++)
	{

		if (user[rlDs[i]].size() == k)
			user[rlDs[i]].erase(user[rlDs[i]].begin());
		user[rlDs[i]].push_back(now);
	}
	
	for (int i = 0; subject[i] != '\n'; i++)
	{
		if (subject[i] == ' ')
		{
			email[now][email_cnt++] = (key & DIV);
			total_email[now] = (total_email[now] + key) & DIV;
			key = 5381;
			continue;
		}
		key = (key << 5) + key + subject[i] - 'a' + 1;
	}

	
	now++;
}

int getCount(int uID)
{
	return user[uID].size();
}

int deleteMail(int uID, char subject[])
{
	ll key = 5381;
	for (int i = 0; subject[i] != '\n'; i++)
	{
		if (subject[i] == ' ')
			continue;
		key = (key << 5) + key + subject[i] - 'a' + 1;
	}
	int temp = (int)(key & DIV);
	int cnt=0;
	for (int i = 0; i < user[uID].size(); i++)
	{
		if (total_email[user[uID][i]] == temp)
		{
			user[uID].erase(user[uID].begin() + i);
			cnt++;
		}
	}

	return cnt;
}

int searchMail(int uID, char text[])
{
	int cnt = 0;
	ll key = 5381;
	int temp;
	for (int i = 0; text[i]; i++)
	{
		key = (key << 5) + key + text[i] - 'a' + 1;
	}
	temp = (int)(key & DIV);

	for (int i = 0; i < user[uID].size(); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (email[user[uID][i]][j] == 0)
				break;
			if (email[user[uID][i]][j] == temp)
				cnt++;
		}
	}

	return cnt;
}