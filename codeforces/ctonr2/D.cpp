#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>
#include <map>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int64_t>> A(N, std::vector<int64_t>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }

    std::map<int64_t, int> m;
    for(int i = 0; i < N; i++) {
        int64_t sum = 0;
        for(int j = 0; j < M; j++) {
            sum += A[i][j] * j;
        }
        m[sum] += 1;
    }

    int64_t which = -1;
    int64_t times = 0;
    for(int i = 0; i < N; i++) {
        int64_t sum = 0;
        for(int j = 0; j < M; j++) {
            sum += A[i][j] * j;
        }
        if(m[sum] == 1) {
            which = i;
            times = sum - (m.begin()->first == sum ? m.rbegin()->first : m.begin()->first);
            break;
        }
    }

    std::cout << which + 1 << ' ' << times << '\n';
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
