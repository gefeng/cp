#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> X(N);
    std::vector<int> Y(N);
    for(int i = 0; i < N; i++) {
        std::cin >> X[i] >> Y[i];
    }

    std::sort(X.begin(), X.end());
    std::sort(Y.begin(), Y.end());

    if(X[0] >= 0 || X.back() <= 0 || Y[0] >= 0 || Y.back() <= 0) {
        std::cout << "Yes" << '\n';
    } else {
        std::cout << "No" << '\n';
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
