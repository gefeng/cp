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
    
    auto query = [](int i, int j) {
        std::cout << "? " << i + 1 << ' ' << j + 1 << std::endl;
        int Q;
        std::cin >> Q;
        return Q;
    };

    int ans = -1;
    for(int i = 0; i < N; i += 2) {
        if(i + 1 == N) {
            ans = i;
            break;
        }

        int res_1 = query(i, i + 1);
        int res_2 = query(i + 1, i);
        
        if(res_1 != res_2) {
            int j = i ? i - 1 : i + 2; 
            res_1 = query(i, j);
            res_2 = query(j, i);
            if(res_1 != res_2) {
                ans = i;
            } else {
                ans = i + 1; 
            }
            break;
        }
    }

    std::cout << "! " << ans + 1 << std::endl;
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
