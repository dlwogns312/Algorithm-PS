#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <memory.h>
#include <stack>
using namespace std;

typedef struct stock
{
    int order_num;
    int num;
    int price;
    struct stock* next;
}stock;

vector<vector<int>> success(6);

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
    
}

int buy(int mNumber, int mStock, int mQuantity, int mPrice)
{
    bool check = true;
    int quantity = mQuantity;

    while (check)
    {
        check = false;

        stock* change=NULL;
        if (forsell[mStock]->next != NULL)
        {
            for (stock* temp = forsell[mStock]->next; temp != NULL; temp = temp->next)
            {
                if (temp->price <= mPrice && temp->num)
                {
                    if (!change)
                        change = temp;
                    else if (change->price > temp->price)
                        change = temp;
                }
            }
        }

        if (change)
        {
            check = true;
            if (change->num <= quantity)
            {
                quantity -= change->num;
                change->num = 0;
                success[mStock].push_back(change->price);
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

    if (quantity != mQuantity)
    {
        for (stock* temp = forsell[mStock]; temp->next != NULL;)
        {
            if (!temp->next->num)
            {
                stock* forerase = temp->next;
                temp->next = forerase->next;
                free(forerase);
            }
            else
                temp = temp->next;
        }
    }
    if (quantity)
    {
        stock* temp=NULL;
        for ( temp = forbuy[mStock]; temp->next != NULL; temp = temp->next);
        stock* node = (stock*)malloc(sizeof(stock));
        node->next=NULL;
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
        stock* change = NULL;

        if (forbuy[mStock]->next != NULL)
        {
            for (stock* temp = forbuy[mStock]->next; temp != NULL; temp = temp->next)
            {
                if (temp->price >= mPrice && temp->num)
                {
                    if (!change)
                        change = temp;
                    else if (temp->price > change->price)
                        change = temp;
                }
            }
        }

        if (change)
        {
            check = true;
            if (change->num <= quantity)
            {
                quantity -= change->num;
                change->num = 0;
                success[mStock].push_back(change->price);
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

    if (quantity != mQuantity)
    {
        stock* temp;
        for ( temp = forbuy[mStock]; temp->next != NULL;)
        {
            if (!temp->next->num)
            {
                stock* forerase = temp->next;
                temp->next = forerase->next;
                free(forerase);
            }
            else
                temp = temp->next;
        }
    }
    if (quantity)
    {
        stock* temp = NULL;;
        for (temp = forsell[mStock]; temp->next != NULL; temp = temp->next);
        stock* node = (stock*)malloc(sizeof(stock));
        node->next = NULL;
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
    for (int i = 1; i <= 5; i++)
    {
        for (stock* temp = forbuy[i]; temp->next != NULL; temp = temp->next)
        {
            if (temp->next->order_num == mNumber)
            {
                stock* forerase = temp->next;
                temp->next = forerase->next;
                free(forerase);
                return;
            }
        }

        for (stock* temp = forsell[i]; temp->next != NULL; temp = temp->next)
        {
            if (temp->next->order_num == mNumber)
            {
                stock* forerase = temp->next;
                temp->next = forerase->next;
                free(forerase);
                return;
            }
        }
    }
}

int bestProfit(int mStock)
{
    int result=0;

    for (int i = success[mStock].size() - 1; i >= 0; i--)
    {
        if (result >= success[mStock][i])
            continue;
        for (int j = i; j >= 0; j--)
            if (result < success[mStock][i] - success[mStock][j])
                result = success[mStock][i] - success[mStock][j];
    }

    return result;
}