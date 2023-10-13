#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::string X, S;
    std::cin >> N >> M >> X >> S;
    
    int ans = 0;
    while(X.size() < M) {
        X += X; 
        ans += 1;
    }

    if(X.find(S) == std::string::npos) {
        X += X;
        ans += 1;
        if(X.find(S) == std::string::npos) {
            ans = -1;
        }
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
