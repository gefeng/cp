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

    std::array<int, 26> seen{};
    for(int i = 0; i < N; i++) {
        seen[S[i] - 'a'] = 1; 
    }

    std::string as;
    for(int i = 0; i < 26; i++) {
        if(seen[i]) {
            as.push_back((char)(i + 'a'));
        }
    }

    int n = as.size();
    std::string ans = "";
    for(int i = 0; i < N; i++) {
        ans.push_back(as[n - 1 - as.find(S[i])]); 
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
