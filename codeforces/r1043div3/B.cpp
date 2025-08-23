#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int64_t N;
    std::cin >> N;
    
    std::vector<int64_t> ans;
    int64_t p10 = 10;
    while(true) {
        if(p10 + 1 > N) {
            break;
        }
        
        if(N % (p10 + 1) == 0) {
            ans.push_back(N / (p10 + 1));
        }
        p10 *= 10;
    }

    std::ranges::sort(ans);
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());

    int size = ans.size();
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] << " \n"[i == size - 1];
    }
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
