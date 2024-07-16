#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N;
    std::cin >> N;

    std::vector<int64_t> ans;

    int64_t x = N;
    while(true) {
        ans.push_back(x);

        int last = -1;
        for(int i = 0 ; i <= 60; i++) {
            if(x & (int64_t(1) << i)) {
                last = i; 
                break;
            }
        }

        int64_t nx = x ^ int64_t(1) << last;
        for(int i = 0; i <= 60; i++) {
            if((N & (int64_t(1) << i)) && !(nx & int64_t(1) << i) && !(x & int64_t(1) << i)) {
                nx |= int64_t(1) << i; 
            } 
        }
        
        if(nx >= x) {
            for(int i = 0; i <= 60; i++) {
                if(nx < x) {
                    break;
                }
                if((nx & int64_t(1) << i) && (x & int64_t(1) << i)) {
                    nx ^= int64_t(1) << i;
                }
            }   
        }

        if(nx >= x) {
            break;
        }

        if(nx == 0) {
            break;
        }
        
        x = nx;
    }

    std::reverse(ans.begin(), ans.end());
    
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
