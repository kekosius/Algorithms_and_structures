#include <iostream>
using namespace std;

long n, k;

struct node
{
    long number;
    node* prev;
    node* next;
};


int main ()
{
    cin >> n >> k;

    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    node* prev_item = new node{ 1, nullptr, nullptr };
    node* head = prev_item;
    for (long i=2; i <= n; i++)
    {
        node *item = new node{ i, prev_item, nullptr };
        prev_item->next = item;
        prev_item = item;
        if (i == n)
        {
            item->next = head;
            head->prev = item;
        }
    }

    long kol = 0;
    node* current_item = head;
    while (kol != n)
    {
        for (long i = 1; i < k; i++)
            current_item = current_item->next;

        kol++;
        cout << current_item->number << " ";

        current_item->prev->next = current_item->next;
        current_item->next->prev = current_item->prev;
        current_item = current_item->next;

    }

    cout << endl;
    return 0;

}


//
// Created by kekos on 26.04.2021.
//

