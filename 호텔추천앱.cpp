#include<vector>
#include<set>
using namespace std;

set<pair<int, int>> rooms[11][11][5][5]; // [region] [bedCnt] [roomType] [viewType] = price, room 번호
vector<int> Hotel2Room[1001]; // index : hotel Id, value : room 번호
struct Room {
    int region, bedCnt, roomType, viewType, price, id;
    set<pair<int, int>> reserveList; // 예약 리스트
    set<pair<int, int>>::iterator it; // rooms의 어디에 있는가? <- risePrice에서 가격을 올릴때, rooms도 반영되도록 활용
    void init(int roomInfo[], int rid) { // 객실정보, 객실id
        region = roomInfo[0], bedCnt = roomInfo[1], roomType = roomInfo[2],
            viewType = roomInfo[3], price = roomInfo[4], id = rid;
        reserveList.clear();
        it = rooms[region][bedCnt][roomType][viewType].insert({ price, id }).first;
        // rooms에 알맞게 분류해서 data를 추가, 추가된 위치의 iterator를 it에 연결
    }

    int updatePrice() { // 인상 이후의 가격을 반환
        // 10프로 인상
        price += price / 10;
        rooms[region][bedCnt][roomType][viewType].erase(it); // 본래 위치에 있던 기록을 삭제 <- 이전 가격
        it = rooms[region][bedCnt][roomType][viewType].insert({ price, id }).first;
        // <- 새로운 기록에 대한 등록
        return price;
    }
    int reserve(pair<int, int> period) { // period기간으로 예약을 시도(예약이 안되면 -1, 예약이되면 해당 객실ID)
        auto next_it = reserveList.lower_bound({ period.first , 0 });
        // next_it : period라는 날짜 '이후'로 가장 가까운 예약
        if (next_it != reserveList.end() && next_it->first < period.second)
            // 불가능 여부판별(다음 체크인이 내 체크 아웃보다 빠른 경우)
            return -1;
        if (next_it != reserveList.begin() && prev(next_it, 1)->second > period.first)
            // 불가능 여부 판별(이전 체크아웃이 내 체크인보다 늦는 경우)
            return -1;
        // 예약 가능
        reserveList.insert(period); // 내 기간으로 예약
        return id;
    }
};

vector<Room> roomData; // index : room번호


void init(int N, int roomCnt[]) {
    roomData.clear();
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 5; k++)
                for (int l = 0; l < 5; l++)
                    rooms[i][j][k][l].clear();
    for (int i = 0; i < 1001; i++)
        Hotel2Room[i].clear();
    roomData = vector<Room>(100001);
}

void addRoom(int hotelID, int roomID, int roomInfo[]) {
    Hotel2Room[hotelID].push_back(roomID); // hotelID의 호텔에 roomID라는 객실이 있다.
    roomData[roomID].init(roomInfo, roomID);
}

int findRoom(int requirements[]) { // <- set을 사용한 이유
    pair<int, int> period = { requirements[0] , requirements[1] }; // 체크인, 체크아웃
    int region = requirements[2], bedCnt = requirements[3],
        roomType = requirements[4], viewType = requirements[5];
    for (auto room : rooms[region][bedCnt][roomType][viewType])
    {
        // 4가지 조건에 맞는 객실 리스트
        // 가격 순서대로 예약을 시도
        int ret = roomData[room.second].reserve(period);
        if (ret == -1) continue; // 예약 실패
        return room.second; // 예약한 객실의 ID
    }
    return -1;
}

int risePrices(int hotelID) {
    int ret = 0;
    for (auto rid : Hotel2Room[hotelID])
    {
        ret += roomData[rid].updatePrice();
    }
    return ret;
}