#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<bool> row(N, false);
    vector<bool> col(N, false);
    vector<pair<int, int>> R(M, {0, 0});

    for(int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;

        R[i].first = X - 1;
        R[i].second = Y - 1;
        row[X - 1] = true;
        col[Y - 1] = true;
    }

    for(auto& r : R) {
        for(int c = 0; c < N; c++) {
            if(!col[c]) {
                cout << "YES" << '\n';
                return;
            }
        }

        for(int r = 0; r < N; r++) {
            if(!row[r]) {
                cout << "YES" << '\n';
                return;
            }
        }
    }

    cout << "NO" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
