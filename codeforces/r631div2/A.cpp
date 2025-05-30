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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::sort(A.begin(), A.end());
    
    int pre = 0;
    for(int i = 0; i < N; i++) {
        int d = std::max(0, A[i] - pre - 1);
        if(d <= X) {
            X -= d;
        } else {
            pre += X;
            X = 0;
            break;
        }

        pre = A[i];
    }

    if(X) {
        pre += X;
    }

    std::cout << pre << '\n';
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
