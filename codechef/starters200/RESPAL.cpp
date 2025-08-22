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
    
    std::string ans(N, 'a');
    for(int i = 0; i < N; i += 3) {
        for(int j = 0; j < 3; j++) {
            if(i + j < N) {
                ans[i + j] = static_cast<char>(j + 'a'); 
            }
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
