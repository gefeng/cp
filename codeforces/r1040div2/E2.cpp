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
    int N;
    std::cin >> N;

    auto query = [](const std::vector<int>& a) {
        int k = a.size();
        std::cout << "? " << k << ' ';
        for(int i = 0; i < k; i++) {
            std::cout << a[i] + 1 << ' ';
        }
        std::cout << std::endl;

        int Q;
        std::cin >> Q;
        return Q;
    };

    std::vector<int> a(N);
    std::vector<int> b;
    std::iota(a.begin(), a.end(), 0);

    int p = -1;
    int q = -1;
    if(query(a) == 0) {
        p = N - 1;
        q = 0;
    } else {
        int lo = 0;
        int hi = N - 1;
        while(lo <= hi) {
            if(hi - lo == 1) {
                p = lo;
                q = hi;
                break;
            }
            int mid = (lo + hi) >> 1;
            
            a.clear();
            b.clear();
            for(int i = lo; i <= mid; i++) {
                a.push_back(i);
            }
            for(int i = mid + 1; i <= hi; i++) {
                b.push_back(i);
            }
            
            int x = query(a);
            int y = query(b);
            if(x == 0 && y == 0) {
                p = mid;
                q = mid + 1;
                break;
            }
            if(x >= y) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
    }

    std::string ans(N, '.');
    for(int i = 0; i < N; i += 8) {
        a.clear();
        int sum = 0;
        for(int j = 0; j < 8 && j + i < N; j++) {
            for(int k = 0; k < (1 << j); k++) {
                a.push_back(k == 0 ? i + j : p);
                a.push_back(q);
            }
            a.push_back(q);
            sum += (1 << j) * ((1 << j) + 1) / 2;
        }
        int res = query(a);

        int x = sum - res;
        for(int j = 0; j < 8 && j + i < N; j++) {
            ans[i + j] = x & (1 << j) ? ')' : '(';
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
