#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::pair<int, int>> a;
    int size = 0;
    for(int x : A) {
        int cnt = 0;
        int y = x;
        while(y % 10 == 0) {
            cnt += 1;
            y /= 10;
        }

        y = x;
        int len = 0;
        while(y) {
            len += 1;
            y /= 10;
        }

        if(cnt) {
            a.emplace_back(len, cnt);
        }
        size += len;
    }

    std::sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
                return x.second > y.second;
            });

    int n = a.size();
    if(n == 1) {
        size -= a[0].second; 
    } else {
        for(int i = 0; i < n; i += 2) {
            size -= a[i].second;
        }
    }
    std::cout << (size >= M + 1 ? "Sasha" : "Anna") << '\n';
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
