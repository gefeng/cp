#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <set>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A.begin(), A.end());

    int max_s = A.back() * 2;
    int ans = 0; 
    for(int s = 1; s <= max_s; s++) {
        std::multiset<int> ms;
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            int t = s - A[i]; 
            if(ms.find(t) != ms.end()) {
                cnt += 1;
                ms.erase(ms.find(t));
            } else {
                ms.insert(A[i]);
            }
        }

        ans = std::max(ans, cnt);
    }

    std::cout << ans << '\n';
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
