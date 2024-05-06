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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> s;
    for(int i = 0; i < N; i++) {
        int cur = A[i];
        while(!s.empty() && s.back() == cur) {
            s.pop_back();
            cur += 1;
        }
        s.push_back(cur);
    }

    std::cout << s.size() << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
