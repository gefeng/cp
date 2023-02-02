#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

const int INF = 2e9;

void run_case() {
    int N, M, D;
    cin >> N >> M >> D;

    vector<int> P(N);
    vector<int> A(M);
    vector<int> pos(N + 1, 0);

    for(int i = 0; i < N; i++) {
        cin >> P[i];
        pos[P[i]] = i;
    }

    for(int i = 0; i < M; i++) {
        cin >> A[i];
    }

    int ans = INF;
    for(int i = 1; i < M; i++) {
        int p1 = pos[A[i - 1]];
        int p2 = pos[A[i]];

        if(p2 > p1 && p2 <= p1 + D) {
            int cnt = p2 - p1;

            int delta = D + 1 - cnt;
            if(p1 - delta >= 0 || p2 + delta < N || p1 + N - p2 - 1 >= delta) {
                cnt = min(cnt, delta);
            }
            ans = min(ans, cnt);
        } else {
            cout << 0 << '\n';
            return;
        }
    }

    cout << ans << '\n';
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
