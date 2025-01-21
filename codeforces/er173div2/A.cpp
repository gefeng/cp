#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int64_t dfs(int64_t x) {
    if(x <= 3) {
        return 1;
    }
    
    return dfs(x / 4) * 2;
}

void run_case() {
    int64_t N;
    std::cin >> N;
    
    std::cout << dfs(N) << '\n';
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
