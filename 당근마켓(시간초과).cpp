#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, vector<int>> m;
int arr[30001];
int add_num;

int n;

void init(int N) {
	m.clear();
	n = N;
	add_num = 0;
}

void addCarrot(int price, int tagCnt, char tagName[][10]) {
	arr[add_num] = price;
	for (int i = 0; i < tagCnt; i++)
	{
		m[tagName[i]].push_back(add_num);
	}
	add_num++;
}

int sellCarrot(char tag1[], char tag2[], char tag3[]) {
	unordered_map<int,int>s;
	set<pair<int,int>>ret;

	for (int i = 0; i < m[tag1].size(); i++)
	{
		s[m[tag1][i]]++;
	}
	for (int i = 0; i < m[tag2].size(); i++)
	{
		s[m[tag2][i]]++;
	}
	for (int i = 0; i < m[tag3].size(); i++)
	{
		s[m[tag3][i]]++;
	}

	for (auto it : s)
	{
		if (it.second == 3&&arr[it.first]!=-1)
			ret.insert({ arr[it.first],it.first });
	}

	if (ret.empty())
		return -1;
	else
	{
		pair<int, int>tmp;
		tmp = *ret.begin();
		arr[tmp.second] = -1;
		return tmp.first;
	}
}

void updatePrice(char tag1[], int addPrice) {
	for (int i = 0; i < m[tag1].size(); i++)
		if(arr[m[tag1][i]]!=-1)
			arr[m[tag1][i]] += addPrice;
}