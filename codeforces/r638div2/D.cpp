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

    int sum = 0;
    int p_2 = 1;
    std::vector<int> seq;
    while(sum + p_2 <= N) {
        sum += p_2;
        seq.push_back(p_2);
        p_2 <<= 1;
    }

    if(sum < N) {
        seq.push_back(N - sum);
        std::sort(seq.begin(), seq.end());
    }

    int m = seq.size();
    std::cout << m - 1 << '\n';
    for(int i = 1; i < m; i++) {
        std::cout << seq[i] - seq[i - 1] << " \n"[i == m - 1];
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
