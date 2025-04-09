#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<std::string>> B(M, std::vector<std::string>(N));
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> B[i][j];
        }
    }

    std::vector<int> cnt(N, 0);
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(A[j] == B[i][j]) {
                cnt[j] += 1;
            }
        }
    }
    
    int ans = INF;
    for(int i = 0; i < M; i++) {
        std::vector<int> match(N, 0);
        int cand = N;
        for(int j = 0; j < N; j++) {
            if(A[j] == B[i][j]) {
                cnt[j] -= 1;
                match[j] = 1;
            }
        }

        for(int j = 0; j < N; j++) {
            if(!match[j]) {
                if(cnt[j] == 0) {
                    cand = INF;
                    break;
                }
                cand += 2;
            }
        }

        ans = std::min(ans, cand);

        for(int j = 0; j < N; j++) {
            if(A[j] == B[i][j]) {
                cnt[j] += 1;
            }
        }
    }

    std::cout << (ans == INF ? -1 : ans) << '\n';    
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
