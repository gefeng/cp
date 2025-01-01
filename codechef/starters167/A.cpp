#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = int(1e6);

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int x = A[0];
    std::sort(A.begin(), A.end());
    
    int l = 1;
    int r = MAX;

    auto it_1 = std::upper_bound(A.begin(), A.end(), x);
    auto it_2 = std::lower_bound(A.begin(), A.end(), x);
    if(it_1 != A.end()) {
        int y = *it_1;
        r = x + (y - x) / 2;
    }

    if(it_2 != A.begin()) {
        it_2--;
        int y = *it_2;
        l = x - (x - y) / 2;
    }

    std::cout << r - l + 1 << '\n';
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
