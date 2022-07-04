#include <iostream>
using namespace std;

struct gas_tube {
    int A, B;
    int C;
};

int main() {
    int N, M, S, F;
    cin >> N >> M;
    gas_tube tubes[M];
    int res[N+1];
    fill_n(res, N+1, -1);

    for (int i = 0; i < M; i++) {
        cin >> tubes[i].A >> tubes[i].B >> tubes[i].C;
    }

    cin >> S >> F;

    res[S] = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++)
            if (res[tubes[j].A] != -1 && res[tubes[j].B] < res[tubes[j].A] + tubes[j].C)
                res[tubes[j].B] = res[tubes[j].A] + tubes[j].C;
    }

    if (res[F] != -1) cout << res[F]; // cout cost
    else cout << "No solution";
    return 0;
}



//
// Created by kekos on 17.05.2021.
//

