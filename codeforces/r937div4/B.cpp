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

    std::vector<std::string> ans(N * 2);

    for(int i = 0, k = 0; i < N * 2; i += 2, k ^= 1) {
        for(int j = 0, kk = 0; j < N * 2; j += 2, kk ^= 1) {
            if(k == 0) {
                for(int _{}; _ < 2; _++) {
                    ans[i].push_back(kk == 0 ? '#' : '.');
                    ans[i + 1].push_back(kk == 0 ? '#' : '.');
                }
            } else {
                for(int _{}; _ < 2; _++) {
                    ans[i].push_back(kk == 1 ? '#' : '.');
                    ans[i + 1].push_back(kk == 1 ? '#' : '.');
                }
            }
        }
    }

    for(int i = 0; i < N * 2; i++) {
        std::cout << ans[i] << '\n';
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
