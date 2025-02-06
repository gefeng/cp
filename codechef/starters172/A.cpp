#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S, T;
    std::cin >> S >> T;

    int n = S.size();
    int m = T.size();
    
    if(n < m) {
        std::cout << -1 << '\n';
        return;
    }

    int64_t ans = 0;
    std::vector<int> seq;
    int i = n - 1;
    int j = m - 1;
    while(i >= 0 && j >= 0) {
        if(S[i] == T[j]) {
            seq.push_back(i);
            i -= 1;
            j -= 1;
        } else {
            i -= 1;
        }
    }

    if(j >= 0) {
        std::cout << -1 << '\n';
        return;
    }

    std::reverse(seq.begin(), seq.end());

    int64_t offset = 1;
    int pre = -1;
    for(int p : seq) {
        ans += offset * (p - pre - 1);   
        pre = p;
        offset += 1;
    } 
    ans += offset * (n - pre - 1);

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
