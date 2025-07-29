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
    int N;
    std::cin >> N;
    
    std::vector<int> eve;
    std::vector<int> odd;
    for(int i = 0; i < N; i++) {
        int X;
        std::cin >> X;

        if(X % 2 == 0) {
            eve.push_back(X);
        } else {
            odd.push_back(X);
        }
    }
    
    std::ranges::sort(eve);
    std::ranges::sort(odd);
    
    int64_t d = 0;
    for(int i = eve.size() - 1, j = odd.size() - 1, t = 0; i >= 0 || j >= 0; t ^= 1) {
        if(t == 0) {
            if(i < 0 || (j >= 0 && odd[j] > eve[i])) {
                j -= 1;
            } else {
                d += eve[i--];
            }
        } else {
            if(j < 0 || (i >= 0 && eve[i] > odd[j])) {
                i -= 1;
            } else {
                d -= odd[j--];
            }
        }
    }

    if(d == 0) {
        std::cout << "Tie" << '\n';
    } else {
        std::cout << (d > 0 ? "Alice" : "Bob") << '\n';
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
