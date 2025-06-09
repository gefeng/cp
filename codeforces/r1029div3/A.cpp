#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X;
    std::cin >> N >> X;

    std::vector<int> A(N);
    int p = -1;
    int q = -1;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        if(A[i] == 1 && p == -1) {
            p = i;
        }
        if(A[i] == 1) {
            q = i;
        }
    }

    std::cout << (p == -1 || q - p + 1 <= X ? "Yes" : "No") << '\n';
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
