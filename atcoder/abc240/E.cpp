#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

const int INF = (int)1e9;

int generator = 1;

pair<int, int> dfs(vector<vector<int>>& G, vector<pair<int, int>>& ans, int cur, int pre) {
    vector<int>& v = G[cur];

    if(pre != -1 && v.size() == 1) {
        ans[cur] = {generator, generator};
        generator += 1;
        return ans[cur];
    }

    int l = INF;
    int r = 0;
    for(int nei : v) {
        if(nei != pre) {
            pair<int, int> res = dfs(G, ans, nei, cur);
            l = min(l, res.first);
            r = max(r, res.second);
        }
    }

    ans[cur] = {l, r};
    return {l, r};
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

    vector<pair<int, int>> ans(N);

    dfs(G, ans, 0, -1);

    for(int i = 0; i < N; i++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
