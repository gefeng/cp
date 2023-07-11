#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <queue>

constexpr int INF = (int)1e9;

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::string S;
    std::cin >> S;

    auto to_decimal = [](std::string& s) {
        int n = s.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                res |= 1 << i;
            }
        }
        return res;
    };

    std::vector<std::array<int, 3>> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i][0];
        
        std::string T1, T2;
        std::cin >> T1 >> T2;
        
        A[i][1] = to_decimal(T1);
        A[i][2] = to_decimal(T2);
    }

    std::vector<std::vector<std::pair<int, int>>> G(1 << N);
    for(int i = 0; i < (1 << N); i++) {
        for(auto& a : A) {
            int ns = i;
            for(int j = 0; j < N; j++) {
                if((a[1] & (1 << j)) && (i & (1 << j))) {
                    ns ^= 1 << j;
                }
            }

            ns |= a[2];

            G[i].emplace_back(ns, a[0]);
        } 
    }

    auto cmp = [](const auto& a, const auto& b) {
        return a.second > b.second;
    };

    std::vector<int> best(1 << N, INF);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);

    int init = to_decimal(S);
    best[init] = 0;
    pq.emplace(init, 0);
    while(!pq.empty()) {
        std::pair<int, int> cur = pq.top();
        pq.pop();

        int s = cur.first;
        int d = cur.second;

        if(best[s] != d) {
            continue;
        }

        for(std::pair<int, int>& nei : G[s]) {
            int ns = nei.first;
            int nd = d + nei.second;
            if(best[ns] > nd) {
                best[ns] = nd;
                pq.emplace(ns, nd);
            }
        }
    }

    std::cout << (best[0] == INF ? -1 : best[0]) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
