#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

constexpr int INF = int(2e9);

void run_case() {
    int N;
    std::cin >> N;
    
    int M1, M2;
    std::vector<std::vector<int>> G1(N, std::vector<int>(N, 0));
    std::vector<std::vector<int>> G2(N, std::vector<int>(N, 0));
    std::vector<std::vector<int>> C(N, std::vector<int>(N, INF));

    std::cin >> M1;
    for(int i = 0; i < M1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G1[U][V] = 1;
        G1[V][U] = 1;
    }

    std::cin >> M2;
    for(int i = 0; i < M2; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G2[U][V] = 1;
        G2[V][U] = 1;
    }

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            std::cin >> C[i][j];
        }
    }

    std::vector<int> a(N);
    std::iota(a.begin(), a.end(), 0);
    
    int ans = INF;
    do {
        int cost = 0;
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                if(G1[i][j] == G2[a[i]][a[j]]) {
                    continue; 
                }
            
                cost += a[i] < a[j] ? C[a[i]][a[j]] : C[a[j]][a[i]];
            }
        } 
        ans = std::min(ans, cost);
    } while(std::next_permutation(a.begin(), a.end()));

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
