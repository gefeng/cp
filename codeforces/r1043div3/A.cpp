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
    std::string A, B, S;

    std::cin >> N >> A >> M >> B >> S;

    for(int i = 0; i < M; i++) {
        if(S[i] == 'V') {
            A = B[i] + A;
        } else {
            A.push_back(B[i]);
        }
    }

    std::cout << A << '\n';
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
