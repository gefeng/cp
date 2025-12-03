#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, C;
    std::cin >> N >> C;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::string S;
    std::cin >> S;
    
    int bal = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == '0') {
            bal += A[i];  
        }
    }

    if(bal >= C) {
        int sum = 0;
        for(int i = 0; i < N; i++) {
            if(S[i] == '1') {
                sum += A[i];
            }
        }
        bal = std::max(bal, bal - C + sum);
    }

    std::cout << bal << '\n';
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
