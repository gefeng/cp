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
    
    std::vector<std::pair<int, int>> A(N);
    std::vector<int> freq(N * 2 + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
        if(A[i].first == A[i].second) {
            freq[A[i].first] += 1;
        }
    }

    std::vector<std::pair<int, int>> range;
    for(int i = 1; i <= N * 2; ) {
        if(freq[i] == 0) {
            i += 1;
        } else {
            int j = i;
            while(i <= N * 2 && freq[i] != 0) {
                i += 1;
            }
            range.emplace_back(j, i - 1); 
        }
    }

    std::string ans(N, '0');
    for(int i = 0; i < N; i++) {
        auto [l, r] = A[i];
        if(l == r) {
            if(freq[l] == 1) {
                ans[i] = '1';
            }
        } else {
            auto it = std::upper_bound(range.begin(), range.end(), r, [](int x, const auto& a) {
                        return x < a.first;
                    }); 
            if(it != range.begin()) {
                it--; 
                if(it->first <= l && it->second >= r) {
                    continue;
                }  
                ans[i] = '1';
            } else {
                ans[i] = '1';
            }
        }
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
