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

    std::string S;
    std::cin >> S;

    int p1 = -1;
    int p2 = -1;
    int p3 = -1;
    for(int i = 0; i < N; i++) {
        if(S[i] == '|') {
            if(p1 == -1) {
                p1 = i;
            } else {
                p2 = i;
            }
        }
        if(S[i] == '*') {
            p3 = i;
        }
    }

    std::cout << (p3 > p1 && p3 < p2 ? "in" : "out") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
