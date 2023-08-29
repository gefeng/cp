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

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::string t = "vika";
    int k = 0;
    for(int i = 0; i < M && k < 4; i++) {
        for(int j = 0; j < N; j++) {
            if(A[j][i] == t[k]) {
                k += 1;
                break;
            }
        }
    }

    std::cout << (k == 4 ? "YES" : "NO") << '\n';
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
