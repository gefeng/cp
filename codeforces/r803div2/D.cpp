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

    auto query = [](int l, int r) {
        std::cout << "? " << l + 1 << ' ' << r + 1 << std::endl;
        std::vector<int> a(r - l + 1);
        for(int i = 0; i < r - l + 1; i++) {
            std::cin >> a[i];
            a[i] -= 1;
        }
        return a;
    };

    int lo = 0;
    int hi = N - 1;
    int ans = -1;
    while(lo <= hi) {
        int len = hi - lo + 1;
        int mid = 0;
        
        if((len / 2) % 2 == 0) {
            mid = lo + len / 2; 
        } else {
            mid = lo + len / 2 - 1;
        }
    
        std::vector<int> a = query(lo, mid);
        int n = a.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] >= lo && a[i] <= mid) {
                cnt += 1;
            } 
        }
        if(cnt % 2 == 0) {
            lo = mid + 1;
        } else {
            ans = mid + 1;
            hi = mid - 1;
        }
    }

    std::cout << "! " << ans << std::endl;
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
