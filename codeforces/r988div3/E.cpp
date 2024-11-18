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
        int64_t Q;
        std::cin >> Q;
        return Q;
    };

    std::string ans = "";
    int64_t pre = 0;
    for(int i = N - 2; i >= 0; i--) {
        int64_t res = query(i, N - 1);
        if(res != pre) {
            if(ans.empty()) {
                int64_t cnt = N - i - 1 - res;
                while(cnt--) {
                    ans.push_back('0');
                }
                cnt = res;
                while(cnt--) {
                    ans.push_back('1');
                }
            }
            ans.push_back('0'); 
            pre = res;
        } else {
            if(res) {
                ans.push_back('1');
            } 
        }
    }

    if(ans.size() != N) {
        std::cout << "! IMPOSSIBLE" << std::endl;
        return;
    }
    
    std::reverse(ans.begin(), ans.end());
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
