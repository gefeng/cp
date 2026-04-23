#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int query(std::vector<int>& a) {
    int k = a.size();
    std::cout << "? " << k << " ";
    for(int i = 0; i < k; i++) {
        std::cout << a[i] + 1 << ' ';
    }
    std::cout << std::endl;
    
    int Q;
    std::cin >> Q;
    return Q;
}

void run_case() {
    int N;
    std::cin >> N;
    
    int n = N * 2 + 1;
    std::vector<int> ans;
    
    for(int t = 0; t < 3; t++) {
        int lo = 0;
        int hi = ans.empty() ? n - 1 : ans.back() - 1;
        int p = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            std::vector<int> a;
            for(int i : ans) {
                a.push_back(i);
            }

            for(int i = 0; i <= mid; i++) {
                a.push_back(i);
            }

            if(query(a) % 2 != (((mid + t) % 2) ^ 1)) {
                p = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        ans.push_back(p);
    }
        
    std::ranges::sort(ans);
    
    std::cout << "! ";
    for(int i = 0; i < 3; i++) {
        std::cout << ans[i] + 1 << ' ';
    }
    std::cout << std::endl;
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
