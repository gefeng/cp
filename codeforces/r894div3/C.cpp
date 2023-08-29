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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> ans;
    for(int i = N - 1; i >= 0; ) {
        int cnt = A[i] - ans.size();
        int h = i + 1;
        //std::cout << h << '\n';
        for(int j = 0; j < cnt; j++) {
            ans.push_back(h);
            if(ans.size() > N) {
                std::cout << "NO" << '\n';
                return;
            }
        }

        for(int j = i; i >= 0 && A[i] == A[j]; i--) {}
    }

    for(int i = 0; i < N; i++) {
        //std::cout << ans[i] << '\n';
        if(ans[i] != A[i]) {
            std::cout << "NO" << '\n';
            return;
        }
    }

    std::cout << "YES" << '\n';
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
