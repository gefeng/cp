#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int64_t N, L, R;
    std::cin >> N >> L >> R;
    
    int64_t sum = 0;
    std::vector<int> ans;
    for(int i = 0; i <= N; i++) {
        sum += i; 
        if(sum >= L) {
            int x = sum - (L - 1);
            int l = -1;
            int r = -1;
            int cnt2 = 0;
            sum -= x;
            for(int j = N; j > i; j--) {
                sum += j;
                if(sum >= L && sum <= R) {
                    l = l == -1 ? j : l;
                    r = j;
                } else {
                    break;
                }
            }

            for(int j = 0; j < i; j++) {
                if(j + 1 != x) {
                    ans.push_back(j + 1);
                }
            }
            
            for(int j = 0; j < N - i; j++) {
                ans.push_back(N - j);
            }
            ans.push_back(x);
            
            break;
        }
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
