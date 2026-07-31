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
    int ans = 0;
    
    for(int i = 0; i < n; i++) {
        int l = i;
        int r = i;
        int flipped = 0;
        while(l >= 0 && r < n) {
            if(S[l] != S[r]) {
                if(flipped) {
                    break;
                }
                flipped = 1;
            }
            l--;
            r++;
        }
        ans += (r - l) / 2;
    }

    for(int i = 0; i < n - 1; i++) {
        int l = i;
        int r = i + 1;
        int flipped = 0;
        while(l >= 0 && r < n) {
            if(S[l] != S[r]) {
                if(flipped) {
                    break;
                }
                flipped = 1;
            }
            l--;
            r++;
        }
        ans += (r - l - 1) / 2;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
