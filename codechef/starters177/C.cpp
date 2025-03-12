#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = 0;
    std::map<int, int> m_1;
    std::map<int, int> m_2;
    std::map<int, int> m_3;
    std::map<int, int> m_4;

    for(int i = 0; i < N; i++) {
        int64_t cnt = 0;
        std::vector<int> set_bits;
        for(int j = 0; j < 30; j++) {
            if(A[i] & (1 << j)) {
                set_bits.push_back(j);
            }
        }
        
        int n = set_bits.size();
        for(int m = 0; m < (1 << n); m++) {
            int c = __builtin_popcount(m);
            if(c == 1) {
                int k = 0;
                for(int j = 0; j < n; j++) {
                    if(m & (1 << j)) {
                        k ^= 1 << set_bits[j];
                    }
                }
                if(m_1.find(k) != m_1.end()) {
                    cnt += m_1[k];
                }
            } else if(c == 2) {
                int k = 0;
                for(int j = 0; j < n; j++) {
                    if(m & (1 << j)) {
                        k ^= 1 << set_bits[j];
                    }
                }
                if(m_2.find(k) != m_2.end()) {
                    cnt -= m_2[k];
                }
            } else if(c == 3) {
                int k = 0;
                for(int j = 0; j < n; j++) {
                    if(m & (1 << j)) {
                        k ^= 1 << set_bits[j];
                    }
                }
                if(m_3.find(k) != m_3.end()) {
                    cnt += m_3[k];
                }
            } else if(c == 4) {
                int k = 0;
                for(int j = 0; j < n; j++) {
                    if(m & (1 << j)) {
                        k ^= 1 << set_bits[j];
                    }
                }
                if(m_4.find(k) != m_4.end()) {
                    cnt -= m_4[k];
                }
            }
        }

        ans += (i - cnt) + 2 * cnt;

        for(int m = 0; m < (1 << n); m++) {
            int c = __builtin_popcount(m);
            if(c == 1) {
                int k = 0;
                for(int j = 0; j < n; j++) {
                    if(m & (1 << j)) {
                        k ^= 1 << set_bits[j];
                    }
                }
                m_1[k] += 1;
            } else if(c == 2) {
                int k = 0;
                for(int j = 0; j < n; j++) {
                    if(m & (1 << j)) {
                        k ^= 1 << set_bits[j];
                    }
                }
                m_2[k] += 1;
            } else if(c == 3) {
                int k = 0;
                for(int j = 0; j < n; j++) {
                    if(m & (1 << j)) {
                        k ^= 1 << set_bits[j];
                    }
                }
                m_3[k] += 1;
            } else {
                int k = 0;
                for(int j = 0; j < n; j++) {
                    if(m & (1 << j)) {
                        k ^= 1 << set_bits[j];
                    }
                }
                m_4[k] += 1;
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
