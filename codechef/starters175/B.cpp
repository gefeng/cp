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
    int N, X;
    std::cin >> N >> X;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int64_t, std::vector<int>> m;
    for(int i = 0; i < N; i++) {
        m[A[i]].push_back(i);
    }

    int ans = 0;
    for(auto& [x, pos_x] : m) {
        ans = std::max(ans, int(pos_x.size()));
        if(X == 1) {
            continue;
        }

        int64_t y = x * X;
        if(m.find(y) == m.end()) {
            continue;
        }

        std::vector<int>& pos_y = m[y];

        int size_x = pos_x.size();
        int size_y = pos_y.size();
    
        std::vector<int> a(size_x + size_y);
        for(int i = 0, j = 0, k = 0; i < size_x || j < size_y; ) {
            if(j == size_y) {
                a[k++] = 1;
                i += 1;
            } else if(i == size_x) {
                a[k++] = -1;
                j += 1;
            } else {
                if(pos_x[i] < pos_y[j]) {
                    a[k++] = 1;
                    i += 1;
                } else {
                    a[k++] = -1;
                    j += 1;
                }
            }
        }

        int sum = 0;
        int max_v = 0;
        int cnt = 0;
        int l = 0;
        for(int i = 0; i < size_x + size_y; i++) {
            sum += a[i]; 
            if(a[i] == -1) {
                cnt += 1;
            }
            if(sum < 0) {
                sum = 0;
                cnt = 0;
                l = i + 1;
            } else {
                max_v = std::max(max_v, sum);
                ans = std::max(ans, size_y - cnt + (i - l + 1 - cnt));
            }
        }
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
