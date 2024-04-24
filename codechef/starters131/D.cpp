#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int MAX = int(1e7);

std::vector<int> min_pf(MAX + 1, 0);

void run_case() {
    int X, Y;
    std::cin >> X >> Y;

    auto get_digits = [](int x) {
        std::vector<int> digits;
        while(x) {
            digits.push_back(x % 10);
            x /= 10;
        }
        std::reverse(digits.begin(), digits.end());
        return digits;
    };

    std::vector<int> digits_x = get_digits(X);
    std::vector<int> digits_y = get_digits(Y); 

    std::sort(digits_x.begin(), digits_x.end());
    std::sort(digits_y.begin(), digits_y.end());

    std::set<int> s;
    do {
        if(digits_x[0] == 0) {
            continue;
        }

        int x = 0;
        for(int d : digits_x) {
            x = x * 10 + d; 
        }
        
        int y = x;
        while(y != 1) {
            int f = min_pf[y];
            s.insert(f);
            while(y % f == 0) {
                y /= f;
            }
        }
    } while(std::next_permutation(digits_x.begin(), digits_x.end()));

    int ans = 1;
    do {
        if(digits_y[0] == 0) {
            continue;
        }

        int x = 0;
        for(int d : digits_y) {
            x = x * 10 + d; 
        }
        
        int y = x;
        while(y != 1) {
            int f = min_pf[y];
            if(s.find(f) != s.end()) {
                ans = std::max(ans, f);
            }
            while(y % f == 0) {
                y /= f;
            }
        }
    } while(std::next_permutation(digits_y.begin(), digits_y.end()));

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    for(int i = 2; i <= MAX; i++) {
        if(min_pf[i] == 0) {
            for(int j = i; j <= MAX; j += i) {
                if(min_pf[j] == 0) {
                    min_pf[j] = i;
                }
            }
        }
    } 
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
