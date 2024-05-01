#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> seen(K, 0);
    for(int i = 0; i < K; i++) {
        for(auto& s : A) {
            if(s[i] == '0') {
                continue;
            }
            bool ok = true;
            for(int j = 0; j < K; j++) {
                if(j != i && s[j] == '1') {
                    ok = false;
                    break;
                }
            } 

            if(ok) {
                seen[i] = 1;
            }
        }
    }

    for(int i = 0; i < K; i++) {
        if(!seen[i]) {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::cout << "Yes" << '\n';
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
