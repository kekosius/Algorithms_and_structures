#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

using namespace std;


struct point {
    long x;
    long y;
    long num;
    double angle;
};

int sort (const void* a, const void* b);

int sort_angle (const void* a, const void* b);

int main()
{
    long n = 0;
    cin >> n;

    point a[n];

    for (long i = 0; i < n; i++){
        cin >> a[i].x;
        cin >> a[i].y;
        a[i].num = i+1;
    }

    qsort(a, n, sizeof(point), sort);

    int x = a[0].x;
    int y = a[0].y;

    for (long i = 0; i < n; i++){
        a[i].x = a[i].x - x;
        a[i].y = a[i].y - y;
    }

    for (long i = 0; i < n; i++) {
        if (a[i].x == 0){
            if (a[i].y > 0) {a[i].angle = 90;}
            if (a[i].y < 0) {a[i].angle = -90;}
            if (a[i].y == 0) {a[i].angle = -100;}
        }
        else {a[i].angle = atan( a[i].y/a[i].x)*180/PI;}

    }

    long zero = a[0].num;

    qsort(a, n, sizeof(point), sort_angle);


    cout << zero << ' ' << a[((int) n)/2].num << endl;

    return 0;
}

int sort (const void* a, const void* b){
    const point* x_1 = (const point*)a;
    const point* x_2 = (const point*)b;
    long s = ((x_1 -> x) - (x_2 -> x));
    return (s);
}

int sort_angle (const void* a, const void* b){
    const point* angle_1 = (const point*)a;
    const point* angle_2 = (const point*)b;
    double s = ((angle_1 -> angle) - (angle_2 -> angle));
    return (s);
}



//
// Created by kekos on 20.04.2021.
//

