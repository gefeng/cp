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

    std::string ans = "";
    for(int i = 0; i <= N; i++) {
        char c = '-';
        for(int j = 1; j < 10; j++) {
            if(N % j == 0 && i % (N / j) == 0) {
                c = (char)(j + '0'); 
                break;
            }
        }

        ans.push_back(c);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
