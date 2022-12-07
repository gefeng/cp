#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;
using LL = long long;

LL to_hash(vector<int>& v) {
    LL h = 0LL;
    for(int x : v) {
        h = h * 10LL + x;
    }
    return h;
}

void run_case() {
    int M;
    cin >> M;

    vector<vector<int>> G(9);
    for(int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;

        U -= 1;
        V -= 1;

        G[U].push_back(V);
        G[V].push_back(U);
    }

    vector<int> A(8, 0);
    for(int i = 0; i < 8; i++) {
        cin >> A[i];
        A[i] -= 1;
    }

    queue<vector<int>> q;
    unordered_set<LL> vis;
    q.push(A);
    vis.insert(to_hash(A));

    int ans = 0;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            vector<int> cur = q.front();
            q.pop();

            bool end = true;
            for(int i = 0; i < 8; i++) {
                if(cur[i] != i) {
                    end = false;
                    break;
                }
            }
            if(end) {
                cout << ans << '\n';
                return;
            }

            int empty = 0;
            vector<bool> seen(9, false);
            for(int x : cur) {
                seen[x] = true;
            }
            for(int i = 0; i < 9; i++) {
                if(!seen[i]) {
                    empty = i;
                    break;
                }
            }

            for(int nei : G[empty]) {
                vector<int> nxt(cur.begin(), cur.end());
                for(int i = 0; i < 8; i++) {
                    if(nxt[i] == nei) {
                        nxt[i] = empty;
                        break;
                    }
                }
                LL h = to_hash(nxt);
                if(vis.find(h) == vis.end()) {
                    q.push(nxt);
                    vis.insert(h);
                }
            }
        }
        ans += 1;
    }
    
    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
