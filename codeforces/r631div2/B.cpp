#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> ans;
    std::vector<int> suffix(N + 1, 0);
    std::vector<int> seen(N + 1, 0);
    bool has_dup = false;
    int max_v = 0;
    int min_v = N + 1;
    for(int i = 1; i <= N; i++) {
        max_v = std::max(max_v, A[N - i]); 
        min_v = std::min(min_v, A[N - i]);
        if(seen[A[N - i]]) {
            has_dup = true;
        }
        seen[A[N - i]] = 1;
        if(!has_dup && max_v == i && min_v == 1 && max_v - min_v + 1 == i) {
            suffix[i] = 1;
        }
    }

    max_v = 0;
    min_v = N + 1;
    has_dup = false;
    seen.assign(N + 1, 0);
    for(int i = 1; i < N; i++) {
        max_v = std::max(max_v, A[i - 1]); 
        min_v = std::min(min_v, A[i - 1]);
        if(seen[A[i - 1]]) {
            has_dup = true;
        }
        seen[A[i - 1]] = 1;
        if(!has_dup && max_v == i && min_v == 1 && max_v - min_v + 1 == i && suffix[N - i]) {
            ans.push_back(i);  
        }
    }

    int k = ans.size();
    std::cout << k << '\n';
    for(int i = 0; i < k; i++) {
        std::cout << ans[i] << ' ' << N - ans[i] << '\n';
    }
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
