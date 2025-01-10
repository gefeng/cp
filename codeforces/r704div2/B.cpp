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

    std::vector<int> ans;
    std::set<int> all;
    
    for(int i = 0; i < N; i++) {
        all.insert(i + 1);
    }

    int now = N;
    for(int i = N - 1; i >= 0; i--) {
        int j = i;
        while(i >= 0 && A[i] != now) {
            i -= 1;
        }

        for(int k = i; k <= j; k++) {
            ans.push_back(A[k]);
            all.erase(A[k]);
        }

        now = all.empty() ? 0 : *all.rbegin();
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
