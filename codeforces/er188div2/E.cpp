#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S;
    std::cin >> S;
    
    int n = S.size();

    if(n == 1) {
        std::cout << S << '\n';
        return;
    }

    std::array<int, 10> freq{};

    for(int i = 0; i < n; i++) {
        freq[S[i] - '0'] += 1;
    }
    
    std::string ans = "";
    for(int x = 0; x <= n * 9; x++) {
        std::array<int, 10> a = freq;
        std::vector<int> steps;
        
        int now = x;
        bool ok = true;
        while(true) {
            int sum = 0;
            int y = now;
            steps.push_back(now);
            while(y) {
                sum += y % 10;
                if(a[y % 10] == 0) {
                    ok = false;
                    break;
                }
                a[y % 10]--;
                y /= 10;
            }
            if(!ok) {
                break;
            }

            if(now < 10) {
                break;
            } 
            now = sum;
        }

        if(!ok) {
            continue;
        }

        int sum = 0;
        for(int i = 0; i < 10; i++) {
            sum += i * a[i];
        }
        if(sum != x) {
            continue;
        }

        for(int i = 9; i >= 0; i--) {
            for(int j = 0; j < a[i]; j++) {
                ans.push_back(static_cast<char>(i + '0'));
            }
        }

        for(int x : steps) {
            ans.append(std::to_string(x));
        }

        break;
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
