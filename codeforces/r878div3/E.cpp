#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

void run_case() {
    std::vector<std::string> S(2);
    
    std::cin >> S[0] >> S[1];

    int X, Q;
    std::cin >> X >> Q;

    int cnt = 0;
    int n = S[0].size();
    for(int i = 0; i < n; i++) {
        if(S[0][i] != S[1][i]) {
            cnt += 1;
        }
    }

    std::queue<std::pair<int, int>> q;
    int t = 0;

    for(int i = 0; i < Q; i++) {
        int TYPE;
        std::cin >> TYPE;

        t += 1;

        if(!q.empty() && t - q.front().second == X) {
            int j = q.front().first;
            q.pop();
            if(S[0][j] != S[1][j]) {
                cnt += 1;
            }
        }
        
        if(TYPE == 1) {
            int P;
            std::cin >> P;
            P -= 1;
            if(S[0][P] != S[1][P]) {
                cnt -= 1;
            }

            q.emplace(P, t);
        } else if(TYPE == 2) {
            std::array<int, 4> A;
            for(int j = 0; j < 4; j++) {
                std::cin >> A[j];
                A[j] -= 1;
            }

            if(S[0][A[1]] != S[1][A[1]]) {
                cnt -= 1;
            }
            if(S[0][A[3]] != S[1][A[3]]) {
                cnt -= 1;
            }

            std::swap(S[A[0]][A[1]], S[A[2]][A[3]]);

            if(S[0][A[1]] != S[1][A[1]]) {
                cnt += 1;
            }
            if(S[0][A[3]] != S[1][A[3]]) {
                cnt += 1;
            }
        } else {
            std::cout << (cnt == 0 ? "YES" : "NO") << '\n';
        }
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
