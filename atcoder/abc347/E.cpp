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
    int N, Q;
    std::cin >> N >> Q;

    std::set<int> s;
    std::vector<int> a(Q);
    std::vector<int64_t> psum(Q + 1, 0);
    std::vector<int64_t> ans(N, 0);
    std::vector<int> pre(N + 1, -1);
    for(int i = 0; i < Q; i++) {
        int X;
        std::cin >> X;
        X -= 1;

        if(s.find(X) == s.end()) {
            s.insert(X);
            pre[X] = i;
        } else {
            s.erase(X);
            int j = pre[X];
            ans[X] += psum[i] - psum[j];
            pre[X] = -1;
        }
        a[i] = s.size(); 
        psum[i + 1] = psum[i] + a[i];
    }

    for(int i = 0; i < N; i++) {
        if(pre[i] != -1) {
            ans[i] += psum[Q] - psum[pre[i]];
        }
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
