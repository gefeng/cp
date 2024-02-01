#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::string s = "";
    char c = 'a';
    while(s.size() < K) {
        s.push_back(c);
        c += 1;
    }

    std::string ans = "";
    for(int i = 0; i < N; i++) {
        ans.append(s); 
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
