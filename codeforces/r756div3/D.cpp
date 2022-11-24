#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

int d = 0;

bool dfs_1(vector<vector<int>>& G, vector<int>& pos, int cur, int lb) {
    if(pos[cur] < lb) {
        return false;
    }

    for(int nei : G[cur]) {
        if(!dfs_1(G, pos, nei, pos[cur])) {
            return false;
        }
    }

    return true;
}

void dfs_2(vector<vector<int>>& G, vector<int>& d, int cur, vector<int>& ans) {
    for(int nei : G[cur]) {
        ans[nei] = d[nei] - d[cur];
        dfs_2(G, d, nei, ans);
    } 
}

void run_case() {
    int N;
    cin >> N;

    d = 0;

    vector<int> P(N);
    vector<vector<int>> G(N);
    int root = 0;
    for(int i = 0; i < N; i++) {
        cin >> P[i];
        P[i] -= 1;
        if(P[i] == i) {
            root = i;
        } else {
            G[P[i]].push_back(i);
        }
    }

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] -= 1;
    }

    vector<int> pos(N);
    for(int i = 0; i < N; i++) {
        pos[A[i]] = i;
    }

    if(!dfs_1(G, pos, root, -1)) {
        cout << -1 << '\n';
        return;
    }

    vector<int> d(N, 0);
    for(int i = 0; i < N; i++) {
        d[A[i]] = i;
    }

    vector<int> ans(N, 0);
    dfs_2(G, d, root, ans);

    for(int i = 0; i < N; i++) {
        cout << ans[i] << " \n"[i == N - 1];
    }
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
