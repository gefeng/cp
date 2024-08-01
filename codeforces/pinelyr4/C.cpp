#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

constexpr int MAX = 40;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }


    int t = MAX;
    std::vector<int> ans;
    
    bool good = false;
    while(t) {
        bool end = true;
        for(int i = 0; i < N; i++) {
            if(A[i] != A[0]) {
                end = false;
            }
        }

        if(end) {
            good = true;
            ans.push_back(A[0]);
            break;
        }

        int x = *std::max_element(A.begin(), A.end());
        x /= 2;
        for(int i = 0; i < N; i++) {
            A[i] = std::abs(A[i] - x);
        }
        ans.push_back(x);
        t -= 1;
    }

    if(!good) {
        std::cout << -1 << '\n';
        return;
    }
    
    int k = ans.size();
    std::cout << k << '\n';
    for(int i = 0; i < k; i++) {
        std::cout << ans[i] << " \n"[i == k - 1];
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
