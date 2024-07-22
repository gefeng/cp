#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int64_t INF = (int64_t)1e18;

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    std::map<int, std::vector<int>> m;
    for(int i = 0; i < N; i++) {
        m[A[i] % K].push_back(A[i]);
    }

    int cnt_odd = 0; 
    int64_t ans = 0;
    for(auto& [r, v] : m) {
        int size = v.size();
        if(size % 2 == 1) {
            if(N % 2 == 0) {
                std::cout << -1 << '\n';
                return;
            }  
            if(++cnt_odd > 1) {
                std::cout << -1 << '\n';
                return;
            }
                
            std::vector<int64_t> psum1(size + 1, 0);
            std::vector<int64_t> psum2(size + 1, 0);
            for(int i = 0; i < size; i++) {
                if(i % 2 == 0) {
                    psum1[i + 1] = psum1[i];
                } else {
                    psum1[i + 1] = psum1[i] + v[i] - v[i - 1];
                }
            }
            for(int i = 1; i < size; i++) {
                if(i % 2 == 0) {
                    psum2[i + 1] = psum2[i] + v[i] - v[i - 1];
                } else {
                    psum2[i + 1] = psum2[i];
                }
            }

            int64_t sum = INF;
            for(int i = 0; i < size; i++) {
                if(i % 2 == 0) {
                    sum = std::min(sum, psum1[i] + psum2[size] - psum2[i + 1]);
                } else {
                    sum = std::min(sum, psum1[i - 1] + psum2[size] - psum2[i + 2] + v[i + 1] - v[i - 1]);
                }
            }
            ans += sum / K;
        } else {
            for(int i = 0; i < size; i += 2) {
                ans += (v[i + 1] - v[i]) / K;
            }
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
