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
    
    std::vector<int> A(N << 1);
    for(int i = 0; i < (N << 1); i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    
    std::vector<std::pair<int, int>> ans;
    for(int i = 0; i < (N << 1) - 1; i++) {
        std::multiset<int> ms;
        int x = A.back();
        ans.emplace_back(A[i], A.back());

        for(int j = 0; j < (N << 1) - 1; j++) {
            if(j != i) {
                ms.insert(A[j]);
            }
        }

        while(!ms.empty()) {
            int b = *ms.rbegin(); 
            ms.erase(ms.find(b));
            
            int a = x - b;
            if(ms.find(a) != ms.end()) {
                ms.erase(ms.find(a));
            } else {
                break;
            }

            ans.emplace_back(a, b);

            x = b;
        }

        if(ms.empty()) {
            std::cout << "YES" << '\n';
            std::cout << A[i] + A.back() << '\n';
            for(int i = 0; i < N; i++) {
                std::cout << ans[i].first << ' ' << ans[i].second << '\n';
            }
            return;
        }
        ans.clear();
    }

    std::cout << "NO" << '\n';
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
