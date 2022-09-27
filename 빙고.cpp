/*=== user.cpp ===*/
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <unordered_map>
#include <set>
#include <map>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct Word
{
    int row, col;
    int diagCnt;
};

struct cmp
{
    bool operator()(const Word& a, const Word& b)const
    {
        if (a.diagCnt != b.diagCnt)
            return a.diagCnt < b.diagCnt;
        if (a.row != b.row)
            return a.row > b.row;
        return a.col > b.col;
    }
};
struct Line {
    int cnt;
    priority_queue<Word,vector<Word>,cmp> words;
};

Line row[1001][10];
Line col[1001][10];
Line diagonal[1001][2];

string arr[1001][10][10];

unordered_set<string> word_list;

int ret,now_round,now_uid;
int winner[1001];
struct usercoord
{
    int uid, row, col;
};

unordered_map<string, vector<usercoord>> wordcoord;
int n, m;

void init(int N, int M) {
    n = N;  m = M;
    word_list.clear();
    wordcoord.clear();
    memset(winner, 0, sizeof(winner));
    for (int i = 1; i <= m; i++)
    {
        diagonal[i][0].words = priority_queue<Word, vector<Word>, cmp>();
        diagonal[i][1].words = priority_queue<Word, vector<Word>, cmp>();
        for (int j = 0; j < 10; j++)
        {
            row[i][j].words = priority_queue<Word, vector<Word>, cmp>();
            col[i][j].words=priority_queue<Word, vector<Word>, cmp>();
        }
    }
    ret = 0;
    now_round = 1;
    now_uid = 1;
}

void registerUser(int uid, char board[10][10][11]) {
    diagonal[uid][0].cnt = n;
    diagonal[uid][1].cnt = n;
    for (int i = 0; i < n; i++)
    {
        row[uid][i].cnt = n;
        col[uid][i].cnt = n;

        for (int j = 0; j < n; j++)
        {
            arr[uid][i][j] = board[i][j];
            wordcoord[board[i][j]].push_back({ uid,i,j });
            
            Word tmp;
            tmp.col = j; tmp.row = i;
            if (i == j)
            {
                if (i + j == n - 1)
                {
                    tmp.diagCnt = 2;
                    row[uid][i].words.push(tmp);
                    col[uid][j].words.push(tmp);
                    diagonal[uid][0].words.push(tmp);
                    diagonal[uid][1].words.push(tmp);
                }
                else {
                    tmp.diagCnt = 1;
                    row[uid][i].words.push(tmp);
                    col[uid][j].words.push(tmp);
                    diagonal[uid][0].words.push(tmp);
                }
            }
            else if (i + j == n - 1)
            {
                tmp.diagCnt = 1;
                row[uid][i].words.push(tmp);
                col[uid][j].words.push(tmp);
                diagonal[uid][1].words.push(tmp);
            }
            else
            {
                tmp.diagCnt = 0;
                row[uid][i].words.push(tmp);
                col[uid][j].words.push(tmp);
            }
        }
    }
}

string playRound(int uid) {
    int min_num = min(diagonal[uid][0].cnt, diagonal[uid][1].cnt);
    
    for (int i = 0; i < n; i++)
    {
        min_num = min(min_num, min(row[uid][i].cnt, col[uid][i].cnt));
    }
    Word tmp;
    priority_queue<Word, vector<Word>, cmp>pq;
    if (min_num == diagonal[uid][0].cnt)
    {
        while (1)
        {
            tmp = diagonal[uid][0].words.top();
            if (word_list.find(arr[uid][tmp.row][tmp.col]) == word_list.end())
            {
                pq.push(tmp);
                break;
            }
            else
                diagonal[uid][0].words.pop();
        }
    }
    if (min_num == diagonal[uid][1].cnt)
    {
        while (1)
        {
            tmp = diagonal[uid][1].words.top();
            if (word_list.find(arr[uid][tmp.row][tmp.col]) == word_list.end())
            {
                pq.push(tmp);
                break;
            }
            else
                diagonal[uid][1].words.pop();
        }
    }

        for (int i = 0; i < n; i++)
        {
            if (min_num == col[uid][i].cnt)
            {
                while (1)
                {
                    tmp = col[uid][i].words.top();
                    if (word_list.find(arr[uid][tmp.row][tmp.col]) == word_list.end())
                    {
                        pq.push(tmp);
                        break;
                    }
                    else
                        col[uid][i].words.pop();
                }
            }
            if (min_num == row[uid][i].cnt)
            {
                while (1)
                {
                    tmp = row[uid][i].words.top();
                    if (word_list.find(arr[uid][tmp.row][tmp.col]) == word_list.end())
                    {
                        pq.push(tmp);
                        break;
                    }
                    else
                        row[uid][i].words.pop();
                }
            }
        }
        tmp = pq.top();

    for (int i = 0; i < wordcoord[arr[uid][tmp.row][tmp.col]].size(); i++)
    {
        int t_row = wordcoord[arr[uid][tmp.row][tmp.col]][i].row;
        int t_col = wordcoord[arr[uid][tmp.row][tmp.col]][i].col;
        int t_uid = wordcoord[arr[uid][tmp.row][tmp.col]][i].uid;

        row[t_uid][t_row].cnt--;
        col[t_uid][t_col].cnt--;
        if (t_row == t_col)
            diagonal[t_uid][0].cnt--;
        if (t_row + t_col == n - 1)
            diagonal[t_uid][1].cnt--;

        if (!row[t_uid][t_row].cnt)
        {
            ret = 1;
            winner[t_uid]++;
        }
        if(!col[t_uid][t_col].cnt)
        {
            ret = 1;
            winner[t_uid]++;
        }
         if(!diagonal[t_uid][0].cnt)
         {
             ret = 1;
             winner[t_uid]++;
         }
        if(!diagonal[t_uid][1].cnt)
        {
            ret =1;
            winner[t_uid]++;
        }
    }
    word_list.insert(arr[uid][tmp.row][tmp.col]);
    return arr[uid][tmp.row][tmp.col];
}

void playNRound(int roundCnt, char word[]) {
    for (; now_round <= roundCnt; now_round++)
    {
        if (now_uid > m)
            now_uid = 1;
        strcpy(word,playRound(now_uid++).c_str());
    }
}

int getResult() {
    while (!ret)
    {
        if (now_uid > m)
            now_uid = 1;
        playRound(now_uid++);
    }
    int MAX=winner[1];
    for (int i = 2; i <= m; i++)
        MAX = max(MAX, winner[i]);

    ret = 0;
    for (int i = 1; i <= m; i++)
        if (winner[i] == MAX)
            ret += i;

    return ret;
}