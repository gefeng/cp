#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, D;
    std::cin >> N >> D;
    
    std::vector<int> ans;
    for(int i = 1; i <= 9; i += 2) {
        if(D % i == 0) {
            ans.push_back(i);
            continue;
        }
        
        if(i == 3 && N > 2) {
            ans.push_back(i); 
            continue;
        }

        if(i == 7 && N > 2) {
            ans.push_back(i);
            continue;
        }

        if(i == 9) {
            if(D % 3 == 0) {
                if(N > 2) {
                    ans.push_back(i);
                }
            } else {
                if(N > 5) {
                    ans.push_back(i);
                }
            }
            continue;
        }
    }

    int n = ans.size();
    for(int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
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
