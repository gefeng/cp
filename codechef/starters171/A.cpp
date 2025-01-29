#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::string s = "BGR";

    int ans = N;
    do {
        std::string t = "";
        for(int i = 0, j = 0; i < N; i++, j = (j + 1) % 3) {
            t.push_back(s[j]); 
        }
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            if(S[i] != t[i]) {
                cnt += 1;
            }
        }
        ans = std::min(ans, cnt);
    } while(std::next_permutation(s.begin(), s.end()));

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
