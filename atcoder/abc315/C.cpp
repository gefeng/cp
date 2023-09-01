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

    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i];
    }

    std::vector<std::vector<int>> a(N + 1);
    for(int i = 0; i < N; i++) {
        a[A[i]].push_back(B[i]);
    }

    for(int i = 1; i <= N; i++) {
        std::sort(a[i].begin(), a[i].end());
    }

    std::map<int, int> m;
    for(int i = 1; i <= N; i++) {
        if(!a[i].empty()) {
            m[a[i].back()] += 1;
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        int sz = a[i].size();
        if(sz > 1) {
            ans = std::max(ans, a[i][sz - 1] + a[i][sz - 2] / 2);
        }

        if(sz) {
            int s = a[i].back();
            if(--m[s] == 0) {
                m.erase(s); 
            }

            if(!m.empty()) {
                ans = std::max(ans, s + m.rbegin()->first);
            }
            m[s] += 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
