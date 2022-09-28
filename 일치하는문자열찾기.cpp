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
	// key : oneLine, value : ��ǥ '��'

	for (int row = 0; row <= Height - PN; row++)
		for (int col = 0; col <= Width - PN; col++)// ������ ����
		{
			string oneLine = ""; // row,col���� 3x3�� �ش��ϴ� �κ��� �� �ٷ� -> key
			for (int i = row; i < row + 3; i++)
				for (int j = col; j < col + 3; j++)
					oneLine += MAP[i][j];
			um[oneLine].push_back({ row, col });
		}

	string KEY = "";
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			KEY += pattern[row][col];


	for (auto coord : um[KEY]) // <- �з��� �߱⿡ �ּ����� �۾��� �� �κ�
	{
		int row = coord.first;
		int col = coord.second;
		int flag = 0; // �ϳ��� �ٸ� �κ��� �ִ°�?
		for (int i = 0; i < PN; i++)
			for (int j = 0; j < PN; j++)
				if (pattern[i][j] != MAP[row + i][col + j])
					// pattern : 0,0�� ����, MAP : row, col�� ����
					flag = 1; // �ٸ��� �ִٸ� ���
		if (!flag) // ����� ���� == �ٸ� �κ��� ���ٸ� �Ϻ��� ��ġ
			cout << row << "," << col << "\n";
	}
}