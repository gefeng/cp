#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

void run_case(int T) {
    int N, G;
    std::cin >> N >> G;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    
    auto it = std::lower_bound(A.begin(), A.end(), G);
    
    int min_d = INF;
    int id = -1;
    if(it != A.end()) {
        int d = *it - G;
        if(d < min_d) {
            min_d = d;
            id = N - 1 - int(it - A.begin());
        }
    }

    if(it != A.begin()) {
        it = std::prev(it);
        int d = G - *it;
        if(d < min_d) {
            min_d = d;
            id = N - 1 - int(it - A.begin());
        }
    }

    std::cout << "Case #" << T << ": " << id + 1 << ' ' << min_d << '\n';
}

int main() {
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
