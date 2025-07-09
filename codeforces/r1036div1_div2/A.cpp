#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> a(A);
    std::ranges::sort(a);

    std::vector<int> ans;
    for(int i = 0; i < N; i++) {
        if(A[i] == a[i]) {
            continue;
        }
        ans.push_back(A[i]);
    }

    if(ans.empty()) {
        std::cout << "No" << '\n';
        return;
    }

    int size = ans.size();
    std::cout << "Yes" << '\n' << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] << " \n"[i == size - 1];
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
