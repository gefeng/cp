#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::map<int, int> mx;
    std::map<int, int> my;
    std::map<int, int> md1;
    std::map<int, int> md2;
    for(int i = 0; i < N; i++) {
        mx[A[i].first] += 1;
        my[A[i].second] += 1;
        md1[A[i].first + A[i].second] += 1;
        md2[A[i].first - A[i].second] += 1;
    }
    
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        int x = A[i].first;
        int y = A[i].second;

        int64_t cntx = std::max(0, mx[x] - 1);
        int64_t cnty = std::max(0, my[y] - 1);
        int64_t cntd1 = std::max(0, md1[x + y] - 1);
        int64_t cntd2 = std::max(0, md2[x - y] - 1);
        
        ans += cntx + cnty + cntd1 + cntd2;
    }

    std::cout << ans << '\n';
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
