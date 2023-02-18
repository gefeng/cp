#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int INF = (int)2e9;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
    }

    vector<int> dp(N, INF); 
    for(int i = 0; i < N; i++) {
        dp[i] = A[i];
    }

    int ans = -INF;
    for(int i = 0; i < N; i++) {
        for(int to : G[i]) {
            dp[to] = min(dp[to], dp[i]);
            ans = max(ans, A[to] - dp[i]);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
