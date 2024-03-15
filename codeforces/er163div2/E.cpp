#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    int n = std::min(N, K);

    std::vector<int> val(N, 0);
    std::vector<int> clique(N, 0);
    int q = 0;
    for(int i = 0; i < N; i += n) {
        int l = i;
        int r = std::min(N - 1, i + n - 1);
        int len = r - l + 1;

        for(int j = 0; j < len / 2; j++) {
            val[i + j] = l + j + (len + 1) / 2;
        }
        for(int j = len / 2; j < len; j++) {
            val[i + j] = l++; 
        }

        q += 1;
        for(int j = 0; j < len; j++) {
            clique[i + j] = q; 
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << val[i] + 1 << " \n"[i == N - 1];
    }

    std::cout << q << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << clique[i] << " \n"[i == N - 1];
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
