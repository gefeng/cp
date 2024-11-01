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

    auto query = [](int a, int b) {
        std::cout << "? " << a << ' ' << b << std::endl;
        int Q;
        std::cin >> Q;
        return Q;
    };

    std::vector<int> ans(N, -1);
    ans[1] = 0;

    std::vector<std::pair<int, int>> a;
    
    int pre = 1;
    for(int i = 2; i < N; i++) {
        int res = query(pre, i); 
        if(res == 0) {
            ans[i] = pre;
            if(i - pre > 1) {
                a.emplace_back(pre + 1, i - 1);
            }
            pre = i;
        } else {
            if(i == N - 1) {
                a.emplace_back(pre + 1, i);
            }
        }
    }

    int n = a.size();
    if(n != 0) {
        std::set<int> s;
        for(int i = a[0].first; i <= a[0].second; i++) {
            ans[i] = 0;
            s.insert(i);
        }

        for(int i = 1; i < n; i++) {
            auto [l, r] = a[i];
            for(int v = l; v <= r; v++) {
                while(true) {
                    int p = *s.begin();
                    int res = query(p, v);
                    if(res == 0) {
                        ans[v] = p;
                        s.erase(s.begin());
                        s.insert(v);
                        break;
                    }
                    s.erase(p);
                }
            }
        }
    }

    std::cout << "! ";
    for(int i = 1; i < N; i++) {
        std::cout << ans[i] << ' ';
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
