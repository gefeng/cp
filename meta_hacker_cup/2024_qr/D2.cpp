#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 3e6;

void run_case(int T) {
    int N, G;
    std::cin >> N >> G;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> slots(MAX + 1, 0);
    int p = 0;
    for(int i = 0; i < N; i++) {
        slots[p + A[i] - 1] += 1;
        p += 1;
    }

    std::vector<int> balls;
    int offset = p - 1;
    p = 0;
    for(int i = 0; i <= MAX; i++) {
        while(slots[i]) {
            balls.push_back(p + 1 - offset);
            p++;
            slots[i]--;
        }
        p += 1;
    }

    std::reverse(balls.begin(), balls.end());

    auto it = std::lower_bound(balls.begin(), balls.end(), G, std::greater<int>());

    int min_d = MAX;
    int which = -1;
    
    if(it != balls.end()) {
        min_d = std::abs(*it - G);
        which = it - balls.begin();
    }

    if(it != balls.begin()) {
        it--;
        if(std::abs(G - *it) <= min_d) {
            min_d = std::abs(G - *it);
            which = it - balls.begin(); 
        }
    }

    std::cout << "Case #" << T << ": " << which + 1 << ' ' << min_d << '\n';
}

int main() {
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
