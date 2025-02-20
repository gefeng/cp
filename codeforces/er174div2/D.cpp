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

    int l = 0;
    int r = n - 1;
    while(l < r && S[l] == S[r]) {
        l += 1;
        r -= 1;
    }
    
    if(l > r) {
        std::cout << 0 << '\n';
        return;
    }

    std::array<int, 26> freq = {};
    std::array<int, 26> rolling = {};
    for(int p = l; p <= r; p++) {
        freq[S[p] - 'a'] += 1;
    }

    int last = l;
    for(int p = l; p <= r; p++) {
        rolling[S[p] - 'a'] += 1;
        if(rolling[S[p] - 'a'] * 2 == freq[S[p] - 'a']) {
            last = std::max(last, p); 
        }
    }

    if(last == (l + r) / 2) {
        while(S[last] == S[n - 1 - last]) {
            last -= 1;
        }
    }

    int ans = last - l + 1;
    
    last = r;
    rolling.fill(0);
    for(int p = r; p >= l; p--) {
        rolling[S[p] - 'a'] += 1;
        if(rolling[S[p] - 'a'] * 2 == freq[S[p] - 'a']) {
            last = std::min(last, p); 
        }
    }

    if(last == (l + r) / 2 + 1) {
        while(S[last] == S[n - 1 - last]) {
            last += 1;
        }
    }

    ans = std::min(ans, r - last + 1);
    
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
