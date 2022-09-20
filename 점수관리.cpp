// *** user.cpp ***
#include <list>
#include <vector>
#include <iterator>
#include <cstring>
#define max(a, b) (a>b)?a:b

using namespace std;
struct node
{
	int id, Class, score;
};
list<int> v[6][6];
list<int>::iterator itr[100001];
int top_number[6];
int Class_number[100001];

void init() {
	memset(Class_number, 0, sizeof(Class_number));
	memset(top_number, 0, sizeof(top_number));

	for (int i = 0; i < 6; i++)
		for(int j=0;j<6;j++)
			v[i][j].clear();
}

void addStudent(int id, int classNum, int score) {
	itr[id] = v[classNum][score].insert(v[classNum][score].end(), id);
	Class_number[id] = classNum;
}

void eraseStudent(int id) {
	(* itr[id]) = -1;
}

void updateStudentScore(int id, int score) {
	eraseStudent(id);
	addStudent(id, Class_number[id], score);
}

void updateClassScore(int classNum, int newScore) {
	int tmp;
	if (newScore < 0)
	{
		for (int i = 2; i <6; i++)
		{
			tmp = i + newScore;
			if (tmp < 1)
				v[classNum][1].splice(v[classNum][1].end(), v[classNum][i]);
			else
				v[classNum][tmp].splice(v[classNum][tmp].end(), v[classNum][i]);
		}
	}
	else
	{
		for (int i = 4; i > 0; i--)
		{
			tmp = i + newScore;
			if (tmp > 5)
				v[classNum][5].splice(v[classNum][5].end(), v[classNum][i]);
			else
				v[classNum][tmp].splice(v[classNum][tmp].end(), v[classNum][i]);
		}
	}
}

int bestStudent(int classNum) {
	
	int tmp = 0;
	for (int i = 5; i > 0; i--)
	{
		for (auto it : v[classNum][i])
		{
			if (it == -1)
				continue;
			tmp = max(tmp, it);
		}
		if (tmp)
			return tmp;
	}
}