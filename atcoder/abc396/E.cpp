#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

bool dfs(std::vector<std::vector<std::pair<int, int>>>& G, int v, int x, std::vector<int>& val, std::vector<int>& vis) {
    val[v] = x;
    vis.push_back(v);
    
    for(auto [nei, w] : G[v]) {
        if(val[nei] == -1) {
            if(!dfs(G, nei, w ^ x, val, vis)) {
                return false;
            } 
        } else {
            if((val[nei] ^ x) != w) {
                return false;
            }
        }
    }

    return true;
}

int assign(std::vector<std::vector<std::pair<int, int>>>& G, int b, int v, int x, std::vector<int>& val) {
    val[v] = x;
    int cnt = x;
    
    for(auto [nei, w] : G[v]) {
        if(val[nei] == -1) {
            int nx = ((w & (1 << b)) ? 1 : 0) ^ x;
            cnt += assign(G, b, nei, nx, val);
        }
    }
    return cnt;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(M);
    std::vector<int> B(M);
    std::vector<int> C(M);

    for(int i = 0; i < M; i++) {
        std::cin >> A[i];
        std::cin >> B[i];
        std::cin >> C[i];
        A[i] -= 1;
        B[i] -= 1;
    }

    std::vector<std::vector<std::pair<int, int>>> G(N);
    for(int i = 0; i < M; i++) {
        G[A[i]].emplace_back(B[i], C[i]); 
        G[B[i]].emplace_back(A[i], C[i]);
    }

    std::vector<int> val(N, -1);
    std::vector<int> tmp(N, -1);
    for(int i = 0; i < N; i++) {
        if(val[i] != -1) {
            continue;
        }

        std::vector<int> vis;
        if(!dfs(G, i, 0, val, vis)) {
            std::cout << -1 << '\n';
            return;
        }

        for(int v : vis) {
            val[v] = 0;
        }

        for(int b = 0; b < 30; b++) {
            int cnt_1 = assign(G, b, i, 0, tmp);
            for(int v : vis) {
                val[v] |= tmp[v] ? (1 << b) : 0;
                tmp[v] = -1;
            }

            int cnt_2 = assign(G, b, i, 1, tmp);
            if(cnt_2 < cnt_1) {
                for(int v : vis) {
                    if(val[v] & (1 << b)) {
                        val[v] ^= (1 << b);
                    }
                    val[v] |= tmp[v] ? (1 << b) : 0;
                }
            }
            for(int v : vis) {
                tmp[v] = -1;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << val[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
