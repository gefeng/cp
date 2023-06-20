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
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> pos(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;

        pos[A[i]] = i;
    }

    std::set<int> s;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int j = pos[i]; 
        
        if(s.empty() || *s.rbegin() < j) {
            ans += 1;
        }

        s.insert(j);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
