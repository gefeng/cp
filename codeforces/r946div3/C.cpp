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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<std::pair<int, int>, int> m;
    int64_t ans = 0;
    for(int i = 2; i < N; i++) {
        std::pair<int, int> p = {A[i - 1], A[i]};
        if(m.find(p) != m.end()) {
            ans += m[p];
        }
        m[p] += 1;
    }

    m.clear();
    for(int i = 1; i < N - 1; i++) {
        std::pair<int, int> p = {A[i - 1], A[i]};
        if(m.find(p) != m.end()) {
            ans += m[p];
        }
        m[p] += 1;
    }

    m.clear();
    for(int i = 2; i < N; i++) {
        std::pair<int, int> p = {A[i - 2], A[i]};
        if(m.find(p) != m.end()) {
            ans += m[p];
        }
        m[p] += 1;
    }

    std::map<std::tuple<int, int, int>, int> m2;
    for(int i = 2; i < N; i++) {
        std::tuple<int, int, int> t = {A[i - 2], A[i - 1], A[i]};
        if(m2.find(t) != m2.end()) {
            ans -= m2[t] * 3;
        }
        m2[t] += 1;
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
