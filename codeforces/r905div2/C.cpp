#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int, int> m;
    std::set<int> s;
    
    for(int i = 0; i < N; i++) {
        m[A[i]] = i; 
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        if(m[A[i]] == i) {
            ans += s.size() + (s.find(A[i]) == s.end() ? 1 : 0);
        }
        s.insert(A[i]);
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
