#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<int64_t>> best(N, std::vector<int64_t>(N, INF));
    std::vector<std::array<int, 3>> E(M);
    for(int i = 0; i < M; i++) {
        int U, V, T;
        std::cin >> U >> V >> T;
        U -= 1;
        V -= 1;
        E[i] = {U, V, T};
        best[U][V] = std::min(best[U][V], int64_t(T));
        best[V][U] = std::min(best[V][U], int64_t(T));
    }

    for(int i = 0; i < N; i++) {
        best[i][i] = 0;
    }

    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(best[i][k] != INF && best[k][j] != INF) {
                    best[i][j] = std::min(best[i][j], best[i][k] + best[k][j]);
                }
            }
        }
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int K;
        std::cin >> K;
        
        std::vector<int> B(K);
        for(int j = 0; j < K; j++) {
            std::cin >> B[j];
            B[j] -= 1;
        }

        int64_t res = INF;
        do {
            for(int k = 0; k < (1 << K); k++) {
                int v = 0; 
                int64_t t = 0;
                for(int p = 0; p < K; p++) {
                    int l = E[B[p]][0];
                    int r = E[B[p]][1];
                    int w = E[B[p]][2];
                    if(k & (1 << p)) {
                        std::swap(l, r); 
                    }

                    t += best[v][l] + w;
                    v = r;
                }
                t += best[v][N - 1];
                res = std::min(res, t);
            }
        } while(std::next_permutation(B.begin(), B.end()));
        
        std::cout << res << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
