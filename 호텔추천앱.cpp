#include<vector>
#include<set>
using namespace std;

set<pair<int, int>> rooms[11][11][5][5]; // [region] [bedCnt] [roomType] [viewType] = price, room ��ȣ
vector<int> Hotel2Room[1001]; // index : hotel Id, value : room ��ȣ
struct Room {
    int region, bedCnt, roomType, viewType, price, id;
    set<pair<int, int>> reserveList; // ���� ����Ʈ
    set<pair<int, int>>::iterator it; // rooms�� ��� �ִ°�? <- risePrice���� ������ �ø���, rooms�� �ݿ��ǵ��� Ȱ��
    void init(int roomInfo[], int rid) { // ��������, ����id
        region = roomInfo[0], bedCnt = roomInfo[1], roomType = roomInfo[2],
            viewType = roomInfo[3], price = roomInfo[4], id = rid;
        reserveList.clear();
        it = rooms[region][bedCnt][roomType][viewType].insert({ price, id }).first;
        // rooms�� �˸°� �з��ؼ� data�� �߰�, �߰��� ��ġ�� iterator�� it�� ����
    }

    int updatePrice() { // �λ� ������ ������ ��ȯ
        // 10���� �λ�
        price += price / 10;
        rooms[region][bedCnt][roomType][viewType].erase(it); // ���� ��ġ�� �ִ� ����� ���� <- ���� ����
        it = rooms[region][bedCnt][roomType][viewType].insert({ price, id }).first;
        // <- ���ο� ��Ͽ� ���� ���
        return price;
    }
    int reserve(pair<int, int> period) { // period�Ⱓ���� ������ �õ�(������ �ȵǸ� -1, �����̵Ǹ� �ش� ����ID)
        auto next_it = reserveList.lower_bound({ period.first , 0 });
        // next_it : period��� ��¥ '����'�� ���� ����� ����
        if (next_it != reserveList.end() && next_it->first < period.second)
            // �Ұ��� �����Ǻ�(���� üũ���� �� üũ �ƿ����� ���� ���)
            return -1;
        if (next_it != reserveList.begin() && prev(next_it, 1)->second > period.first)
            // �Ұ��� ���� �Ǻ�(���� üũ�ƿ��� �� üũ�κ��� �ʴ� ���)
            return -1;
        // ���� ����
        reserveList.insert(period); // �� �Ⱓ���� ����
        return id;
    }
};

vector<Room> roomData; // index : room��ȣ


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
    Hotel2Room[hotelID].push_back(roomID); // hotelID�� ȣ�ڿ� roomID��� ������ �ִ�.
    roomData[roomID].init(roomInfo, roomID);
}

int findRoom(int requirements[]) { // <- set�� ����� ����
    pair<int, int> period = { requirements[0] , requirements[1] }; // üũ��, üũ�ƿ�
    int region = requirements[2], bedCnt = requirements[3],
        roomType = requirements[4], viewType = requirements[5];
    for (auto room : rooms[region][bedCnt][roomType][viewType])
    {
        // 4���� ���ǿ� �´� ���� ����Ʈ
        // ���� ������� ������ �õ�
        int ret = roomData[room.second].reserve(period);
        if (ret == -1) continue; // ���� ����
        return room.second; // ������ ������ ID
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