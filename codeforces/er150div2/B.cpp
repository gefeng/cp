#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int Q;
    std::cin >> Q;

    std::vector<int> a;
    std::vector<int> b;

    std::string ans = "";
    for(int i = 0; i < Q; i++) {
        int X;
        std::cin >> X;

        int res = 0;
        if(a.empty()) {
            a.push_back(X);
            res = 1;
        } else {
            if(b.empty()) {
                if(X >= a.back()) {
                    a.push_back(X);
                    res = 1;
                } else {
                    if(a[0] >= X) {
                        b.push_back(X);
                        res = 1;
                    }
                }
            } else {
                if(X >= b.back() && a[0] >= X) {
                    b.push_back(X);
                    res = 1;
                }
            }
        }

        ans.push_back((char)(res + '0'));
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
