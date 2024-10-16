#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::sort(A.begin(), A.end());
    
    std::vector<int> right(N, 0);
    for(int i = 0; i < N; i++) {
        right[i] = A[i].second;
    }

    std::vector<int> lis;
    for(int i = 0; i < N; i++) {
        if(lis.empty() || lis.back() < right[i]) {
            lis.push_back(right[i]);
        } else {
            auto it = std::upper_bound(lis.begin(), lis.end(), right[i]);
            *it = right[i];
        }
    }

    std::cout << lis.size() << '\n';
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
