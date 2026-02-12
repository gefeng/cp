#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int lo = 0;
    int hi = N;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        std::multiset<int> ms(A.begin(), A.end());
        
        bool win = true;
        for(int i = 1; i <= mid; i++) {
            int ub = mid - i + 1;
            auto it = ms.upper_bound(ub);
            if(it != ms.begin()) {
                ms.erase(std::prev(it)); 
                if(!ms.empty()) {
                    int x = *ms.begin();
                    ms.erase(ms.begin());
                    ms.insert(x + ub);
                }
            } else {
                win = false;
                break;
            }
        }

        if(win) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
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
