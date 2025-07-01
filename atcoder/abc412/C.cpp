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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::multiset<int> ms;
    for(int i = 1; i < N - 1; i++) {
        ms.insert(A[i]);
    }
    
    int ans = 2;
    int now = A[0];
    while(now * 2 < A.back() && !ms.empty()) {
        auto it = ms.upper_bound(now * 2);
        if(it == ms.begin()) {
            break;
        }

        ans += 1;
        it = std::prev(it);
        now = *it;
        ms.erase(it);
    }

    std::cout << (now * 2 >= A.back() ? ans : -1) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
