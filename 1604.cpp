#include <iostream>
#include <stdlib.h>

using namespace std;

struct sign {
    long count;
    long num;
};

int sort (const void* a, const void* b);


int main()
{
    long k = 0;
    cin >> k;

    sign road[k];

    long sum = 0;
    long max = 0;
    long min = 0;
    long max_num = 0;
    long min_num = 0;

    max = 0;
    min = 10000;


    for (long i = 0; i < k; i++)
    {
        cin >> road[i].count;
        road[i].num = i+1;
        sum = sum + road[i].count;
        if (road[i].count >= max){
            max = road[i].count;
            max_num = i;
        }
        if (road[i].count < min && i != max_num){
            min = road[i].count;
            min_num = i;
        }
    }


    while (sum > 0)
    {
        if (road[max_num].count > 0){
            cout  << road[max_num].num << ' ';
            road[max_num].count--;
            sum--;
        }

        if (road[min_num].count > 0){
            cout << "Выводим " <<road[min_num].num << ' ';
            road[min_num].count--;
            sum--;
        }

        max = 0;
        min = 10000;

        for (long i = 0; i < k; i++ ){
            if (road[i].count > 0){
                if (road[i].count >= max){
                    max = road[i].count;
                    max_num = i;
                }
                if (road[i].count < min && i != max_num){
                    min = road[i].count;
                    min_num = i;
                }
            }
        }

    }

    return 0;
}



//
// Created by kekos on 06.04.2021.
//

