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
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> A(N);
    std::vector<int> pos(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
        pos[A[i]] = i;
    }

    std::set<int> s;
    int ans = N;
    for(int l = 0, r = 0; r < N; r++) {
        s.insert(pos[r]);
        if(s.size() > K) {
            s.erase(pos[l++]);
        } 
    
        if(r - l + 1 == K) {
            ans = std::min(ans, *s.rbegin() - *s.begin());
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
