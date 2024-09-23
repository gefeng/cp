#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int M;
    std::cin >> M;
    
    std::vector<int> ans;
    
    for(int i = 10; i >= 0; i--) {
        int x = int(std::pow(3, i));
        while(x <= M) {
            M -= x;
            ans.push_back(i);
        }
    }

    int size = ans.size();
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] << " \n"[i == size - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
