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

void run_case() {
    int N;
    cin >> N;

    vector<int> T(N);
    vector<vector<int>> A(N);

    for(int i = 0; i < N; i++) {
        cin >> T[i];

        int K;
        cin >> K;
        A[i].resize(K, 0);
        for(int j = 0; j < K; j++) {
            cin >> A[i][j];
            A[i][j] -= 1;
        }
    }

    vector<bool> vis(N, false);
    vis[N - 1] = true;
    queue<int> q;
    q.push(N - 1);

    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int cur = q.front();
            q.pop();

            for(int nei : A[cur]) {
                if(!vis[nei]) {
                    vis[nei] = true;
                    q.push(nei);
                }
            }
        }
    }

    LL ans = 0LL;
    for(int i = 0; i < N; i++) {
        if(vis[i]) {
            ans += T[i];
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
