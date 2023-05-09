#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    int cnt1 = 0;
    int cnt2 = 0;
    std::set<int> s;
    for(int x : A) {
        if(x == -1) {
            cnt1 += 1;
        } else if(x == -2) {
            cnt2 += 1;
        } else {
            s.insert(x);
        }
    }

    std::vector<int> v;
    for(int x : s) {
        v.push_back(x);
    }

    int sz = v.size();

    int ans = 0;
    ans = std::max(ans, std::min(M, cnt1 + sz));
    ans = std::max(ans, std::min(M, cnt2 + sz));

    for(int i = 0; i < sz; i++) {
        int l = std::min(v[i] - 1, cnt1 + i);
        int r = std::min(M - v[i], cnt2 + sz - i - 1);

        ans = std::max(ans, l + r + 1);
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
