#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 100;

void run_case() {
    int W, B;
    std::cin >> W >> B;

    std::string S = "wbwbwwbwbwbw";
    std::string s = "";
    for(int i = 0; i < MAX; i++) {
        s.append(S); 
    }

    int n = s.size();
    for(int i = 0; i < n; i++) {
        int cnt_w = 0;
        int cnt_b = 0;
        for(int j = i; j < n; j++) {
            if(s[j] == 'w') {
                cnt_w += 1;
            } else {
                cnt_b += 1;
        
            }

            if(cnt_w == W && cnt_b == B) {
                std::cout << "Yes" << '\n';
                return;
            }
        }
    }

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
