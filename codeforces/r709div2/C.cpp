#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <numeric>

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<int>> A(M);
    for(int i = 0; i < M; i++) {
        int K;
        std::cin >> K;
        for(int j = 0; j < K; j++) {
            int P;
            std::cin >> P;
            P -= 1;
            A[i].push_back(P);
        }
    } 

    int t = (M + 1) / 2;
    std::vector<int> used(N, 0);
    std::vector<int> ans(M, -1);
    for(int i = 0; i < M; i++) {
        ans[i] = A[i][0];
        used[A[i][0]] += 1;
    }

    for(int i = 0; i < N; i++) {
        if(used[i] > t) {
            for(int j = 0; j < M; j++) {
                if(ans[j] != i) {
                    continue; 
                }
                for(int k : A[j]) {
                    if(k != i && used[i] > t && used[k] < t) {
                        used[k] += 1;
                        used[i] -= 1;
                        ans[j] = k;
                        break;
                    }
                }
            }
            if(used[i] > t) {
                std::cout << "NO" << '\n';
                return;
            }
        }
    }

    std::cout << "YES" << '\n';
    for(int i = 0; i < M; i++) {
        std::cout << ans[i] + 1 << " \n"[i == M - 1];
    }
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
