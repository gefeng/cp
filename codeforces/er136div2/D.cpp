#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

pair<int, int> dfs(vector<vector<int>>& G, int max_depth, int cur) {
    int ret_d = 0;
    int ret_o = 0;

    for(int c : G[cur]) {
        pair<int, int> res = dfs(G, max_depth, c);

        if(cur != 0 && res.first == max_depth) {
            ret_o++;
        } else {
            ret_d = max(ret_d, res.first);
        }

        ret_o += res.second;
    } 

    return {ret_d + 1, ret_o};
}

void run_case() {
    int N, K;
    cin >> N >> K;

    vector<int> P(N, -1);
    for(int i = 1; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }

    vector<vector<int>> G(N);
    for(int i = 0; i < N; i++) {
        int p = P[i];

        if(p != -1) {
            G[p].push_back(i);
        }
    }

    int lo = 1;
    int hi = 200000;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;

        int tot = dfs(G, mid, 0).second;
        if(tot <= K) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
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
