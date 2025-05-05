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
    std::vector<int> ones;
    for(int i = 0; i < n; ) {
        int j = i;
        while(S[i] == S[j]) {
            i += 1;
        }
        
        if(S[j] == '1') {
            ones.push_back(i - j);
        }
    }

    std::sort(ones.begin(), ones.end(), std::greater<int>());
    
    int size = ones.size();
    int ans = 0;
    for(int i = 0; i < size; i += 2) {
        ans += ones[i];
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
