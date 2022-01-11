#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

typedef struct stock
{
    int order_num;
    int num;
    int price;
    struct stock* next;
}stock;

vector<vector<int>> success(6);

int order_list[200001];
int cnt;
stock** forbuy=NULL;
stock** forsell=NULL;

void init()
{
  
    if (!forbuy)
    {
        forbuy = (stock**)malloc(sizeof(stock*) * 6);
        forsell = (stock**)malloc(sizeof(stock*) * 6);

        for (int i = 1; i <= 5; i++)
        {
            forbuy[i] = (stock*)malloc(sizeof(stock));
            forbuy[i]->num = 0;
            forbuy[i]->order_num = 0;
            forbuy[i]->price = 0;
            forsell[i] = (stock*)malloc(sizeof(stock));
            forsell[i]->num = 0;
            forsell[i]->order_num = 0;
            forsell[i]->price = 0;
        }
    }

    for (int i = 1; i <= 5; i++)
    {
        forbuy[i]->next = NULL;
        forsell[i]->next = NULL;
        success[i].clear();
    }
    cnt = 0;
    memset(order_list, 0, sizeof(order_list));
}

int buy(int mNumber, int mStock, int mQuantity, int mPrice)
{
    bool check = true;
    int quantity = mQuantity;

    while (check)
    {
        check = false;

        stock* change=forsell[mStock]->next;

        if (change&&change->price<=mPrice)
        {
            check = true;
            if (change->num <= quantity)
            {
                quantity -= change->num;
                change->num = 0;
                success[mStock].push_back(change->price);

                forsell[mStock]->next = change->next;
                free(change);
            }

            else
            {
                change->num -= quantity;
                quantity = 0;
                success[mStock].push_back(change->price);
                check = false;
                break;
            }
        }
    }

    if (quantity)
    {
        stock* temp=NULL;
        for (temp = forbuy[mStock]; temp->next != NULL; temp = temp->next)
        {
            if (temp->next->price<mPrice)
                break;
        }
        order_list[mNumber] = mStock;
        stock* node = (stock*)malloc(sizeof(stock));
        node->next=temp->next;
        node->order_num = mNumber;
        node->num = quantity;
        node->price = mPrice;
        temp->next = node;
    }

    mQuantity = quantity;
    return quantity;
}

int sell(int mNumber, int mStock, int mQuantity, int mPrice)
{
    bool check = true;
    int quantity = mQuantity;

    while (check)
    {
        check = false;
        stock* change = forbuy[mStock]->next;
   

        if (change&&change->price>=mPrice)
        {
            check = true;
            if (change->num <= quantity)
            {
                quantity -= change->num;
                change->num = 0;
                success[mStock].push_back(change->price);

                forbuy[mStock]->next = change->next;
                free(change);
            }

            else
            {
                change->num -= quantity;
                quantity = 0;
                success[mStock].push_back(change->price);
                check = false;
            }
        }
    }

    if (quantity)
    {
        stock* temp = NULL;;
        for (temp = forsell[mStock]; temp->next != NULL; temp = temp->next) {
            if (temp->next->price>mPrice)
                break;
        }
        order_list[mNumber] = mStock+5;
        stock* node = (stock*)malloc(sizeof(stock));
        node->next = temp->next;
        node->order_num = mNumber;
        node->num = quantity;
        node->price = mPrice;
        temp->next = node;
    }
    mQuantity = quantity;
    return quantity;
}

void cancel(int mNumber)
{
    if (!order_list[mNumber])
        return;
    else
    {
        int temp = order_list[mNumber];
        order_list[mNumber] = 0;
        if (temp <= 5)
        {
            for (stock* forerase = forbuy[temp]; forerase->next != NULL; forerase = forerase->next)
            {
                if (forerase->next->order_num == mNumber)
                {
                    stock* era = forerase->next;
                    forerase->next = era->next;
                    free(era);
                    return;
                }
            }
        }
        else
        {
            temp -= 5;
            for (stock* forerase = forsell[temp]; forerase->next != NULL; forerase = forerase->next)
            {
                if (forerase->next->order_num == mNumber)
                {
                    stock* era = forerase->next;
                    forerase->next = era->next;
                    free(era);
                    return;
                }
            }
        }
    }
}

int bestProfit(int mStock)
{
    int result=0;

    for (int i = success[mStock].size() - 1; i >= 1; i--)
    {
        if (result >= success[mStock][i])
            continue;
        for (int j = i-1; j >= 0; j--)
            if (result < success[mStock][i] - success[mStock][j])
                result = success[mStock][i] - success[mStock][j];
    }

    return result;
}