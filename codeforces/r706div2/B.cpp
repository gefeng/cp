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

    std::set<int> s;
    for(int i = 0; i < N; i++) {
        int X;
        std::cin >> X;
        s.insert(X);
    }

    if(K == 0) {
        std::cout << s.size() << '\n';
        return;
    }

    int mex = 0;
    while(s.find(mex) != s.end()) {
        mex += 1; 
    }

    int max_v = *s.rbegin();
    int ans = 0; 
    if(max_v < mex) {
        ans = s.size() + K; 
    } else {
        s.insert((mex + max_v + 1) / 2);
        ans = s.size();
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
