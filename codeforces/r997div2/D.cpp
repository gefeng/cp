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

    int64_t ans = int64_t(N) * (N + 1) / 2;
    
    for(int x = 1; x <= 10; x++) {
        std::vector<int> a(N);
        for(int i = 0; i < N; i++) {
            if(A[i] <= x) {
                a[i] = -1;
            } else {
                a[i] = 1;
            }
        }

        std::map<int, int> m_odd;
        std::map<int, int> m_eve;
        m_odd[0] = 1;
        
        int sum_1 = 0;
        int sum_2 = 0;
        int pre = -1;
        for(int i = 0, j = 0; i < N; i++) {
            sum_1 += a[i];
            if(A[i] == x) {
                while(j < i) {
                    sum_2 += a[j];
                    if(j % 2 == 0) {
                        m_eve[sum_2] += 1;
                    } else {
                        m_odd[sum_2] += 1;
                    }
                    j += 1;
                }
                pre = i;
            } 

            if(pre != -1) {
                if(i % 2 == 0) {
                    ans -= m_eve[sum_1];
                } else {
                    ans -= m_odd[sum_1];
                }
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
