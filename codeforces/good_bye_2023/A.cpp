#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int p = 2023;
    for(int x : A) {
        if(p % x != 0) {
            std::cout << "No" << '\n';
            return;
        }
        p /= x;
    }

    std::vector<int> ans;
    int x = 1;
    while(p % 7 == 0) {
        p /= 7;
        x *= 7;
    }
    while(p % 17 == 0) {
        p /= 17;
        x *= 17;
    }

    if(p != 1) {
        std::cout << "No" << '\n';
        return;
    }

    ans.push_back(x);

    while(ans.size() != K) {
        ans.push_back(1);
    }
    

    std::cout << "Yes" << '\n';
    for(int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " \n"[i == ans.size() - 1];
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
