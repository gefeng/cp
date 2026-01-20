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

    for(int i = 1; i < N; i++) {
        if(S[i] < S[i - 1]) {
            std::swap(S[i], S[i - 1]);
            int j = i;
            while(j + 1 < N && S[j] >= S[j + 1]) {
                std::swap(S[j], S[j + 1]);
                j += 1;
            }
            break;
        }
    }

    std::cout << S << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
