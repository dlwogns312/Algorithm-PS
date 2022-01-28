const int MAX_NUM = 1000000;
extern void putIn(int n, int a);
extern int closeDoor(int n);
extern void arrest(int n);
extern void clearRoom();

int door_num;
int thief;


void binary_search(int l, int r)
{
    int m = (l + r) / 2;
    int result_l, result_r;

    
    if (l == r)
    {
        putIn(door_num, l);
        result_l = closeDoor(door_num);
        door_num++;
        if (result_l)
        {
            arrest(l);
            thief++;
            return;
        }
    }
    else if (r - l == 1)
    {
        putIn(door_num, l);
        result_l = closeDoor(door_num);
        door_num++;
        if (result_l)
        {
            arrest(l);
            thief++;
        }

        putIn(door_num, r);
        result_r = closeDoor(door_num);
        door_num++;
        if (result_r)
        {
            arrest(r);
            thief++;
        }

    }
    else {
        int div1, div2,result1,result2,result3;
        div1 = (r-l+1) / 3+l;
        div2 = (r - l + 1) / 3 * 2 + l;

        for (int i = l; i < div1; i++)
        {
            putIn(door_num, i);
        }
        result1 = closeDoor(door_num);
        door_num++;

        for (int i = div1; i < div2; i++)
        {
            putIn(door_num, i);
        }
        result2 = closeDoor(door_num);
        door_num++;

        for (int i = div2; i <= r; i++)
        {
            putIn(door_num, i);
        }
        result3 = closeDoor(door_num);
        door_num++;
        
        if (result1)
        {
            binary_search(l, div1-1);
            if (thief >= 1000)
                return;
        }
        if (result2)
        {
            binary_search(div1, div2 - 1);
            if (thief >= 1000)
                return;
        }
        if (result3)
        {
            binary_search(div2, r);
            if (thief >= 1000)
                return;
        }

    }

}

void investigate() {
    door_num = 0;
    thief = 0;
    clearRoom();
    binary_search(0, MAX_NUM - 1);
}