#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

const int INF = (int)2e9;

void run_case() {
    int N, M, X;
    cin >> N >> M >> X;

    int ans = INF;
    vector<vector<int>> A(N, vector<int>(M, 0));
    vector<int> C(N, 0);

    for(int i = 0; i < N; i++) {
        cin >> C[i];

        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    for(int i = 1; i < (1 << N); i++) {
        vector<int> algo(M, 0);
        int cost = 0;
        for(int j = 0; j < N; j++) {
            if(i & (1 << j)) {
                for(int k = 0; k < M; k++) {
                    algo[k] += A[j][k];
                }
                cost += C[j];
            }
        }

        bool ok = true;
        for(int i = 0; i < M; i++) {
            if(algo[i] < X) {
                ok = false;
                break;
            } 
        }

        if(ok) {
            ans = min(ans, cost); 
        }
    }

    cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
