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

    assert(p != -1 && q != -1);

    std::string ans(N, '.');
    ans[p] = '(';
    ans[q] = ')';
    
    int j = -1;
    int k = -1;
    for(int i = 0; i < N; i++) {
        if(i == p || i == q) {
            continue;
        }
        
        if(j == -1) {
            j = i;
        } else {
            k = i;
            a.clear();
            a.push_back(j);
            a.push_back(j);
            a.push_back(q);
            a.push_back(q);
            a.push_back(p);
            a.push_back(k);
            int x = query(a);

            if(x == 0) {
                ans[j] = ')';
                ans[k] = '(';
            } else if(x == 1) {
                ans[j] = ')';
                ans[k] = ')';
            } else if(x == 2) {
                ans[j] = '(';
                ans[k] = '(';
            } else {
                ans[j] = '(';
                ans[k] = ')';
            }
            j = -1;
            k = -1;
        }
    }
    if(j != -1 && k == -1) {
        a.clear();
        a.push_back(p);
        a.push_back(j);
        int x = query(a);
        if(x == 0) {
            ans[j] = '(';
        } else {
            ans[j] = ')';
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
