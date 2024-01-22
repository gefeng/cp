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

    std::vector<int> A(N);
    std::vector<int> nxt(N, -1);
    int first = -1;
    for(int i = 0; i < N; i++) {
        int P;
        std::cin >> P;
        if(P != -1) {
            P -= 1;
            nxt[P] = i;
        } else {
            first = i;
        }
    }

    int cur = first;
    while(cur != -1) {
        std::cout << cur + 1 << " ";
        cur = nxt[cur];
    }

    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
