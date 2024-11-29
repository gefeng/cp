#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> B(N);
    std::vector<int> C(M);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> C[i];
    }

    std::vector<int> ans(M, -1);
    std::vector<std::vector<int>> painter(N + 1);
    for(int i = 0; i < M - 1; i++) {
        painter[C[i]].push_back(i);
    }

    for(int i = 0; i < N; i++) {
        if(A[i] != B[i]) {
            if(painter[B[i]].empty()) {
                continue;
            }
            int when = painter[B[i]].back();
            painter[B[i]].pop_back();
            ans[when] = i;
            A[i] = B[i];
        } 
    } 

    int cnt = 0;
    int last = -1;
    for(int i = 0; i < N; i++) {
        if(A[i] != B[i]) {
            if(B[i] != C.back()) {
                std::cout << "NO" << '\n';
                return;
            }
            cnt += 1;
            last = i;
        }
    }

    if(cnt > 1) {
        std::cout << "NO" << '\n';
        return;
    }

    if(cnt == 0) {
        for(int i = 0; i < N; i++) {
            if(B[i] == C.back()) {
                last = i;
                break;
            }
        }

        if(last == -1) {
            std::cout << "NO" << '\n';
            return;
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int p : painter[i]) {
            ans[p] = last;
        }
    }

    ans[M - 1] = last;

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
