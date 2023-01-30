#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int timer = 0;

void dfs(vector<vector<int>>& G, vector<int>& in, vector<int>& out, int v) {
    in[v] = timer++;
    
    for(int nei : G[v]) {
        dfs(G, in, out, nei);        
    }

    out[v] = timer++;
}

void run_case() {
    int N;
    cin >> N;

    vector<vector<int>> G(N);
    for(int i = 1; i < N; i++) {
        int P;
        cin >> P;
        P -= 1;
        G[P].push_back(i);
    }

    vector<int> in(N, 0);
    vector<int> out(N, 0);
    dfs(G, in, out, 0);

    queue<int> q;
    vector<vector<int>> levels;
    q.push(0);
    while(!q.empty()) {
        int sz = q.size();

        levels.emplace_back();
        while(sz--) {
            int v = q.front();
            q.pop();
            
            levels.back().push_back(in[v]);

            for(int nei : G[v]) {
                q.push(nei);
            }
        }
    }

    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int U, D;
        cin >> U >> D;
        U -= 1;

        if(D >= levels.size()) {
            cout << 0 << '\n';
            continue;
        }

        int t_in = in[U];
        int t_out = out[U];
        vector<int>& v = levels[D];

        auto l = lower_bound(v.begin(), v.end(), t_in);
        auto r = upper_bound(v.begin(), v.end(), t_out);
        cout << r - l << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
