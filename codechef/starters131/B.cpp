#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int MAX = int(2e5);

std::set<int> good;

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> ans(N);
    if(good.find(N + 1) != good.end()) {
        for(int i = 0; i < N; i++) {
            ans[i] = N - i;
        }
    } else {
        for(int i = 1; i < N; i++) {
            int x = i + 1;
            int y = i + 1 + N; 
            if(good.find(x) != good.end() && good.find(y) != good.end()) {
                for(int j = 0; j < i; j++) {
                    ans[j] = i - j; 
                }

                for(int j = i; j < N; j++) {
                    ans[j] = N - (j - i);
                }
                break;
            }
        } 
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    for(int i = 1; i <= MAX + MAX; i++) {
        int x = i;
        bool is_good = false;
        while(x) {
            if(x % 3 == 2) {
                is_good = true;
                break;
            }
            x /= 3;
        }
        if(is_good) {
            good.insert(i);
        }
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
