#include <iostream>

using namespace std;

constexpr int MAX_NUM = 1000000;
//const int MAX_NUM = 1000000;
extern void putIn(int n, int a);
extern int closeDoor(int n);
extern void arrest(int n);
extern void clearRoom();

int door_num;
int thief;


void Sol(int l, int r, int& room_idx) { // [l, r] -> [l, mid] : false, [l, mid + 1] : true
    while (l <= r) {
        int lo = l - 1, hi = r + 1;
        while (lo + 1 < hi) {
            const int mid = lo + hi >> 1;
            for (int i = l; i <= mid; i++) putIn(room_idx, i);
            if (!closeDoor(room_idx++)) lo = mid;
            else hi = mid;
        }
        if (hi == r + 1) break;
        arrest(hi), l = hi + 1;
    }
}

void investigate() {
    const int B = 8516; int room_idx = 0; clearRoom();
    for (int i = 0; i < MAX_NUM; i += B) {
        const int l = i, r = min(i + B, MAX_NUM) - 1;
        for (int j = l; j <= r; j++) putIn(room_idx, j);
        if (closeDoor(room_idx++)) Sol(l, r, room_idx);
    }
}