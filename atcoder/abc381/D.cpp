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
    
    int ans = 0;
    std::vector<int> seen(N + 1, 0);
    for(int l = 0, r = 0; r < N; ) {
        if(r + 1 < N && A[r] == A[r + 1]) {
            if(seen[A[r]]) {
                while(seen[A[r]] > 0) {
                    seen[A[l]] -= 1;
                    l += 1;
                }
                seen[A[r]] += 2;
                r += 2; 
            } else {
                seen[A[r]] += 2;
                r += 2;
            }
        } else {
            if(r + 1 == N) {
                break;
            }
            
            while(l != r) {
                seen[A[l]] -= 2;
                l += 2;
            }
        
            if(r - 1 >= 0 && A[r - 1] == A[r]) {
                l = r - 1;
                r = l;
            } else {
                r += 1;
                l = r;
            }
        } 
        ans = std::max(ans, r - l);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
