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

unordered_map<string,int> tagid;

unordered_map<int, vector<int>> onetag;

struct threetags
{
	int tagid[3];

	bool operator==(threetags right)const
	{
		return tagid[0] == right.tagid[0] && tagid[1] == right.tagid[1] && tagid[2] == right.tagid[2];
	}
};

struct cmp
{
	size_t operator()(threetags a)const
	{
		return a.tagid[0] * 10000 + a.tagid[1] * 3000 + a.tagid[2];
	}
};
unordered_map<threetags, vector<int>,cmp> tags;

int arr[30001];
int add_num;
int tag_num;
int n;

void init(int N) {
	n = N;
	add_num = 0;
	tag_num = 0;
	tagid.clear(); onetag.clear(); tags.clear();
}

void addCarrot(int price, int tagCnt, char tagName[][10]) {
	arr[add_num] = price;
	threetags tmp;
	int for_sort[5];
	for (int i = 0; i < tagCnt; i++)
	{
		if (tagid.find(tagName[i]) == tagid.end())
			tagid[tagName[i]] = tag_num++;
		
		onetag[tagid[tagName[i]]].push_back(add_num);
		for_sort[i] = tagid[tagName[i]];
	}
	sort(for_sort, for_sort + tagCnt);

	for (int i = 0; i < tagCnt-2; i++)
	{
		tmp.tagid[0] = for_sort[i];
		for (int j = i + 1; j < tagCnt - 1; j++)
		{
			tmp.tagid[1] = for_sort[j];
			for (int k = j + 1; k < tagCnt; k++)
			{
				tmp.tagid[2] = for_sort[k];
				tags[tmp].push_back(add_num);
			}
		}
	}

	add_num++;
}

int sellCarrot(char tag1[], char tag2[], char tag3[]) {
	if (tagid.find(tag1) == tagid.end() || tagid.find(tag2) == tagid.end() || tagid.find(tag3) == tagid.end())
		return -1;

	threetags tmp = { tagid[tag1],tagid[tag2],tagid[tag3] };
	sort(tmp.tagid, tmp.tagid + 3);
	
	int ret = 9999999999;
	int k=-1;
	for (int i = 0; i < tags[tmp].size(); i++)
	{
		if (arr[tags[tmp][i]] < ret&&arr[tags[tmp][i]]>0)
		{
			ret = arr[tags[tmp][i]];
			k = tags[tmp][i];
		}
	}

	if (k == -1)
		return -1;
	arr[k] = -1;
	return ret;
}

void updatePrice(char tag1[], int addPrice) {
	int tmp = tagid[tag1];
	for (int i = 0; i < onetag[tmp].size(); i++)
	{
		if (arr[onetag[tmp][i]] > 0)
			arr[onetag[tmp][i]] += addPrice;
	}
}