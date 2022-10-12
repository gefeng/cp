#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
using LL = long long;


bool contains(unordered_map<int, unordered_map<int, LL>>& map, int x, int y) {
    if(map.find(x) == map.end() || map[x].find(y) == map[x].end()) {
        return false;
    }

    return true;
}

void run_case() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<array<int, 3>>> G(N);
    for(int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;

        A--;
        B--;

        G[A].push_back({B, C, i});
    }

    unordered_map<int, vector<int>> S;
    for(int i = 0; i < K; i++) {
        int E;
        cin >> E;
        E--;
        S[E].push_back(i);
    }

    auto get_pos = [&](int x, int from) {
        if(S.find(x) == S.end()) {
            return -1;
        }

        auto it = lower_bound(S[x].begin(), S[x].end(), from);
        if(it == S[x].end()) {
            return -1;
        }

        return *it;
    };

    auto cmp = [](const array<LL, 3>& a, const array<LL, 3>& b) {
        return a[2] > b[2];
    };

    unordered_map<int, unordered_map<int, LL>> best;
    priority_queue<array<LL, 3>, vector<array<LL, 3>>, decltype(cmp)> pq(cmp);
    
    pq.push({0LL, 0LL, 0LL});
    best[0][0] = 0LL;

    LL ans = -1;
    while(!pq.empty()) {
        array<LL, 3> cur = pq.top();
        pq.pop();

        int node = (int)cur[0];
        int pos = (int)cur[1];
        LL w = cur[2];

        if(best[node][pos] != w) {
            continue;
        }

        if(node == N - 1) {
            ans = w;
            break;
        }

        for(auto& nei : G[node]) {
            int nxt = nei[0];
            int nxt_p = get_pos(nei[2], pos);
            LL nxt_w = w + nei[1];
            if(nxt_p != -1) {
                if(!contains(best, nxt, nxt_p) || best[nxt][nxt_p] > nxt_w) {
                    best[nxt][nxt_p] = nxt_w;
                }
                pq.push({(LL)nxt, (LL)nxt_p, nxt_w});
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
