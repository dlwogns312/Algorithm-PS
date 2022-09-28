#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
char MAP[1001][1001];
char pattern[21][21];
int main()
{
	int Height, Width;
	cin >> Height >> Width;
	for (int i = 0; i < Height; i++)
		cin >> MAP[i];
	int PN;
	cin >> PN;
	for (int i = 0; i < PN; i++)
		cin >> pattern[i];

	unordered_map<string, vector<pair<int, int>>> um;
	// key : oneLine, value : 좌표 '들'

	for (int row = 0; row <= Height - PN; row++)
		for (int col = 0; col <= Width - PN; col++)// 기준점 세팅
		{
			string oneLine = ""; // row,col부터 3x3에 해당하는 부분을 한 줄로 -> key
			for (int i = row; i < row + 3; i++)
				for (int j = col; j < col + 3; j++)
					oneLine += MAP[i][j];
			um[oneLine].push_back({ row, col });
		}

	string KEY = "";
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			KEY += pattern[row][col];


	for (auto coord : um[KEY]) // <- 분류를 했기에 최소한의 작업이 될 부분
	{
		int row = coord.first;
		int col = coord.second;
		int flag = 0; // 하나라도 다른 부분이 있는가?
		for (int i = 0; i < PN; i++)
			for (int j = 0; j < PN; j++)
				if (pattern[i][j] != MAP[row + i][col + j])
					// pattern : 0,0을 기준, MAP : row, col을 기준
					flag = 1; // 다른게 있다면 기록
		if (!flag) // 기록이 없다 == 다른 부분이 없다면 완벽히 일치
			cout << row << "," << col << "\n";
	}
}