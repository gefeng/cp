#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    if(N < K && M < K) {
        std::cout << -1 << '\n';
        return;
    }

    if(std::abs(N - M) > K) {
        std::cout << -1 << '\n';
        return;
    }

    std::string ans = "";
    if(N >= M) {
        ans.append(std::string(K, '0')); 
        N -= K;
        while(N || M) {
            if(N == 0) {
                ans.push_back('1');
                M -= 1;
                continue;
            }
            if(M == 0) {
                ans.push_back('0');
                N -= 1;
                continue;
            }
            ans.push_back('1');
            ans.push_back('0');
            M -= 1;
            N -= 1;
        }
    } else {
        ans.append(std::string(K, '1'));
        M -= K;
        while(N || M) {
            if(N == 0) {
                ans.push_back('1');
                M -= 1;
                continue;
            }
            if(M == 0) {
                ans.push_back('0');
                N -= 1;
                continue;
            }
            ans.push_back('0');
            ans.push_back('1');
            M -= 1;
            N -= 1;
        }
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
