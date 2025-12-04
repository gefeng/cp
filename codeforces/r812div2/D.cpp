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

    auto query = [](int a, int b) {
        std::cout << "? " << a << ' ' << b << std::endl;
        int Q;
        std::cin >> Q;
        return Q;
    };

    int ans = 0;
    std::vector<int> now(1 << N, 0);

    std::iota(now.begin(), now.end(), 1);
    
    while(true) {
        if(now.size() == 1) {
            ans = now[0];
            break;
        }
        if(now.size() == 2) {
            ans = query(now[0], now[1]) == 1 ? now[0] : now[1];
            break;
        }

        int size = now.size();
        std::vector<int> nxt;
        for(int i = 0; i < size; i += 4) {
            int q = query(now[i], now[i + 2]);
            if(q == 0) {
                q = query(now[i + 1], now[i + 3]);
                nxt.push_back(q == 1 ? now[i + 1] : now[i + 3]);
            } else {
                if(q == 1) {
                    q = query(now[i], now[i + 3]);
                    nxt.push_back(q == 1 ? now[i] : now[i + 3]);
                } else {
                    q = query(now[i + 1], now[i + 2]);
                    nxt.push_back(q == 1 ? now[i + 1] : now[i + 2]);
                }
            }
        }
        
        now = std::move(nxt);
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
