#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<set<int>> G(N);
    vector<int> id(N, 0);
    for(int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        X -= 1;
        Y -= 1;

        if(G[X].find(Y) == G[X].end()) {
            G[X].insert(Y);
            id[Y] += 1;
        }
    }

    queue<int> q;
    for(int i = 0; i < N; i++) {
        if(id[i] == 0) {
            q.push(i);
        }
    }

    vector<int> solved;
    while(!q.empty()) {
        int sz = q.size();
        if(sz > 1) {
            cout << "No" << '\n';
            return;
        }
        
        int cur = q.front();
        q.pop();
        solved.push_back(cur);

        for(int nei : G[cur]) {
            if(--id[nei] == 0) {
                q.push(nei);
            }
        }
    }
    
    if(solved.size() != N) {
        cout << "No" << '\n';
        return;
    }

    cout << "Yes" << '\n';
    vector<int> ans(N, 0);
    int cur = 1;
    for(int x : solved) {
        ans[x] = cur++;
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
