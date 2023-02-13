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

    vector<vector<int>> A(M);
    for(int i = 0; i < M; i++) {
        int C;
        cin >> C;

        for(int j = 0; j < C; j++) {
            int X;
            cin >> X;

            A[i].push_back(X);
        }
    }

    int ans = 0;
    for(int i = 0; i < (1 << M); i++) {
        bool ok = true;
        vector<bool> seen(N + 1, false);
        for(int j = 0; j < M; j++) {
            if(i & (1 << j)) {
                for(int x : A[j]) {
                    seen[x] = true;
                }
            }
        }

        for(int j = 1; j <= N; j++) {
            if(!seen[j]) {
                ok = false;
                break;
            }
        }

        if(ok) {
            ans += 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
