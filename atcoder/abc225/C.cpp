#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N, vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> G[i][j];
        }
    }

    int sr = (G[0][0] - 1) / 7;
    int sc = (G[0][0] - 1) % 7;

    if(sc + M > 7) {
        cout << "No" << '\n';
        return;
    }

    LL cur = 7LL * sr + sc + 1LL;

    for(int i = 0; i < N; i++) {
        if(G[i][0] != cur) {
            cout << "No" << '\n';
            return;
        } 

        for(int j = 1; j < M; j++) {
            if(G[i][j] != G[i][j - 1] + 1) {
                cout << "No" << '\n';
                return;
            }
        }
        
        cur += 7LL;
    }

    cout << "Yes" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
