#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;
using LL = long long;

const LL INF = (LL)2e18;

void run_case() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] -= 1;
    }

    vector<int> C(N);
    for(int i = 0; i < N; i++) {
        cin >> C[i];
    }

    LL ans = -INF;
    for(int i = 0; i < N; i++) {
        int cur_p = A[i];
        LL sum = 0LL;
        vector<bool> vis(N, false);
        vector<int> costs;

        do {
            costs.push_back(C[cur_p]);
            vis[cur_p] = true;
            sum += C[cur_p];
            cur_p = A[cur_p];
        } while(!vis[cur_p]);

        int len = costs.size();

        if(sum > 0) {
            int rounds = max(0, K / len - 1);
            int left = K - rounds * len;

            LL score = 1LL * rounds * sum;
            ans = max(ans, score);
            for(int j = 0, cur_p = A[i]; j < left; j++, cur_p = A[cur_p]) {
                score += C[cur_p]; 
                ans = max(ans, score);
            }
        } else {
            LL score = 0LL;
            for(int j = 0, cur_p = A[i]; j < min(K, len); j++, cur_p = A[cur_p]) {
                score += C[cur_p];
                ans = max(ans, score);
            }
        }
    } 

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
