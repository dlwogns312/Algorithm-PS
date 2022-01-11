#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <memory.h>
#include <stack>
using namespace std;

#define max(a,b) a>b ? a:b

typedef struct stock
{
    int order_num;
    int price;
    struct stock* next;

}stock;


stock** forbuy = NULL;
stock** forsell = NULL;

int save[200001];

int max_profit[6];
int low_price[6];

void init()
{

    if (!forbuy)
    {
        forbuy = (stock**)malloc(sizeof(stock*) * 6);
        forsell = (stock**)malloc(sizeof(stock*) * 6);

        for (int i = 1; i <= 5; i++)
        {
            forbuy[i] = (stock*)malloc(sizeof(stock));
            forbuy[i]->price = 0;
            forsell[i] = (stock*)malloc(sizeof(stock));
            forsell[i]->price = 0;
        }
    }

    for (int i = 1; i <= 5; i++)
    {
        forbuy[i]->next = NULL;
        forsell[i]->next = NULL;
        max_profit[i] = 0;
        low_price[i] = 1000001;
    }

    memset(save, 0, sizeof(save));
}

int buy(int mNumber, int mStock, int mQuantity, int mPrice)
{
    bool check = true;
    int quantity = mQuantity;

    
    while (check)
    {   
        check = false;
        stock* change = NULL;

        if (forsell[mStock]->next != NULL)
        {
            for (stock* temp = forsell[mStock]->next; temp != NULL; temp = temp->next)
            {
                if (temp->price <= mPrice && save[temp->order_num])
                {
                    if (!change)
                        change = temp;
                    else if (change->price >= temp->price)
                        change = temp;
                }
            }
        }
        if (change)
        {
            check = true;
            int num = save[change->order_num];
            if (num <= quantity)
            {
                quantity -= num;
                save[change->order_num] = 0;
            }

            else
            {
                save[change->order_num] -= quantity;
                quantity = 0;
                check = false;
            }

            if (change->price < low_price[mStock])
                low_price[mStock] = change->price;
            else if (change->price > max_profit[mStock])
                max_profit[mStock] = max(max_profit[mStock], change->price - low_price[mStock]);
        }
    }

    if (quantity)
    {
        stock* node = (stock*)malloc(sizeof(stock));
        node->next = forbuy[mStock]->next;;
        node->order_num = mNumber;
        save[mNumber] = quantity;
        node->price = mPrice;
        forbuy[mStock]->next = node;
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

        if(forbuy[mStock]->next != NULL)
        {
            for (stock* temp = forbuy[mStock]->next; temp != NULL; temp = temp->next)
            {
                if (temp->price >= mPrice && save[temp->order_num])
                {
                    if (!change)
                        change = temp;
                    else if (temp->price >= change->price)
                        change = temp;
                }
            }
        }

        if (change)
        {
            check = true;
            int num = save[change->order_num];
           
            if (num <= quantity)
            {
                quantity -= num;
                save[change->order_num] = 0;
            
            }

            else
            {
                save[change->order_num] -= quantity;
                quantity = 0;
              
                check = false;
            }

            if (change->price < low_price[mStock])
                low_price[mStock] = change->price;
            else if (change->price > max_profit[mStock])
                max_profit[mStock] = max(max_profit[mStock], change->price - low_price[mStock]);
        
          
        }
       
    }

    if (quantity)
    {
        stock* node = (stock*)malloc(sizeof(stock));
        node->next = forsell[mStock]->next;;
        node->order_num = mNumber;
        save[mNumber] = quantity;
        node->price = mPrice;
        forsell[mStock]->next = node;
    }
    mQuantity = quantity;
    return quantity;
}

void cancel(int mNumber)
{
    save[mNumber]= 0;
}

int bestProfit(int mStock)
{
    return max_profit[mStock];
}