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
        A[i] -= 1;
    }

    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<std::vector<int>> box(N);
    for(int i = 0; i < N; i++) {
        box[A[i]].push_back(B[i]);
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        std::sort(box[i].begin(), box[i].end());
        for(int w : box[i]) {
            ans += w;
        } 
        if(!box[i].empty()) {
            ans -= box[i].back();
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
