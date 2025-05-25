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

    if(N == 1) {
        std::cout << 1 << '\n' << 1 << '\n';
        return;
    }

    std::vector<int> pick(N + 1, 1);
    for(int i = (N % 2 == 0 ? N : N - 1); i >= 1; i--) {
        if(pick[i]) {
            for(int j = 1; j * j <= i - 1; j++) {
                if((i - 1) % j == 0) {
                    pick[j] = 0;
                    pick[(i - 1) / j] = 0;
                }
            }
        } 
    }

    std::vector<int> ans;
    for(int i = 1; i <= (N % 2 == 0 ? N : N - 1); i++) {
        if(pick[i]) {
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
    std::cin.tie(nullptr);

    run_case();
}
