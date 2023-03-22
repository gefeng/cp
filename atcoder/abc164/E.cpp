#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

using LL = long long;

const LL INF = (LL)2e18;
const int MAX = 2500;

struct data {
    int v;
    int s;
    LL t;
    data(int _v, int _s, LL _t) : v(_v), s(_s), t(_t) {}
    
    bool operator < (const data& other) const {
        return t > other.t; 
    }
};

void run_case() {
    int N, M, S;
    std::cin >> N >> M >> S;

    S = std::min(S, MAX);

    std::vector<std::vector<std::array<int, 3>>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V, A, B;
        std::cin >> U >> V >> A >> B;
        U -= 1;
        V -= 1;
        G[U].push_back({V, A, B});
        G[V].push_back({U, A, B});
    }

    std::vector<std::array<int, 2>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i][0] >> A[i][1];
    }

    std::priority_queue<data> pq;
    std::vector<std::vector<LL>> best(N, std::vector<LL>(MAX + 1, INF));

    pq.emplace(0, S, 0LL);
    best[0][S] = 0LL;

    while(!pq.empty()) {
        data cur = pq.top();
        pq.pop();

        int v = cur.v;
        int s = cur.s;
        LL t = cur.t;

        if(t != best[v][s]) {
            continue;
        }

        { 
            int ns = std::min(s + A[v][0], MAX);
            LL nt = t + A[v][1];
            if(best[v][ns] > nt) {
                pq.emplace(v, ns, nt);
                best[v][ns] = nt;
            }
        }

        for(std::array<int, 3>& nei : G[v]) {
            int nv = nei[0];
            int ns = s - nei[1];
            LL nt = t + nei[2];
            
            if(ns >= 0 && best[nv][ns] > nt) {
                pq.emplace(nv, ns, nt);
                best[nv][ns] = nt;
            }
        }
    }

    for(int i = 1; i < N; i++) {
        LL min_t = INF;
        for(int j = 0; j <= MAX; j++) {
            min_t = std::min(min_t, best[i][j]);
        }

        std::cout << min_t << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
