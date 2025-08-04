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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = 0;
    int64_t sum = 0;
    std::set<int64_t> s;
    s.insert(0);
    for(int i = 0; i < N; i++) {
        sum += A[i]; 
        if(s.find(sum) != s.end()) {
            ans += 1;
            s.clear();
            s.insert(0);
            s.insert(A[i]);
            sum = A[i];
        } else {
            s.insert(sum);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
