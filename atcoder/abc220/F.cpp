#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

pair<LL, int> dfs_1(vector<vector<int>>& G, vector<int>& cnt, int v, int p, int d) {
    LL sum = d;
    int tot = 1;

    for(int nei : G[v]) {
        if(nei == p) {
            continue;
        }
        pair<LL, int> res = dfs_1(G, cnt, nei, v, d + 1);
        sum += res.first;
        tot += res.second;
    }

    cnt[v] = tot;
    return {sum, tot};
}

void dfs_2(vector<vector<int>>& G, vector<int>& cnt, vector<LL>& ans, int v, int p, LL pre_sum) {
    int l = cnt[v];
    int r = G.size() - cnt[v];

    if(v == 0) {
        ans[v] = pre_sum;
    } else {
        ans[v] = pre_sum + r - l;
    }

    for(int nei : G[v]) {
        if(nei == p) {
            continue;
        }
        dfs_2(G, cnt, ans, nei, v, ans[v]);
    }
}

void run_case() {
    int N;
    cin >> N;

    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        cin >> U >> V;
        U -= 1;
        V -= 1;

        G[U].push_back(V);
        G[V].push_back(U);
    }

    vector<int> cnt(N, 0);
    LL sum = dfs_1(G, cnt, 0, -1, 0).first;

    vector<LL> ans(N, 0LL);
    dfs_2(G, cnt, ans, 0, -1, sum); 

    for(int i = 0; i < N; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
