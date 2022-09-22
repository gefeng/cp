#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

using namespace std;
using LL = long long;

void run_case(int T) {
    LL D, X;
    int N;
    cin >> D >> N >> X;

    vector<array<LL, 3>> S(N, {0LL});
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> S[i][j];
        }    
    }
    
    sort(S.begin(), S.end(), [](const array<LL, 3>& a, const array<LL, 3>& b) {
        return a[1] < b[1];
    });

    LL ans = 0LL;
    auto cmp = [](const array<LL, 3>& a, const array<LL, 3>& b) {
        return a[2] < b[2];
    };

    priority_queue<array<LL, 3>, vector<array<LL, 3>>, decltype(cmp)> pq(cmp); 
    for(int i = 0; i < N; i++) {
        pq.push(S[i]);
        LL after = i < N - 1 ? S[i + 1][1] : D;
        LL slots = (after - S[i][1]) * X;

        while(slots > 0 && !pq.empty()) {
            array<LL, 3> best = pq.top();
            pq.pop();

            LL take = min(best[0], slots);
            slots -= take;
            best[0] -= take;
            ans += take * best[2];

            if(best[0]) {
                pq.push(best);
            }
        }
    } 

    cout << "Case #" << T << ": " << ans << '\n';
}

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
