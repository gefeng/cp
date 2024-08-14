#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int M;
    std::cin >> M;
    for(int i = 0; i < M; i++) {
        std::string S;
        std::cin >> S;

        if(S.size() != N) {
            std::cout << "No" << '\n';
            continue;
        }

        std::map<int, int> m1;
        std::map<int, int> m2;
        bool ok = true;
        for(int i = 0; i < N; i++) {
            int c = S[i] - 'a';
            if(m1.find(c) == m1.end()) {
                if(m2.find(A[i]) != m2.end()) {
                    ok = false;
                    break;
                }
                m1[c] = A[i]; 
                m2[A[i]] = c;
            } else {
                if(m1[c] != A[i] || m2[A[i]] != c) {
                    ok = false;
                    break;
                }
            }
        }

        std::cout << (ok ? "Yes" : "No") << '\n';
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
