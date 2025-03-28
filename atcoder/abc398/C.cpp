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

    std::map<int, int> freq;
    std::map<int, int> last;
    for(int i = 0; i < N; i++) {
        freq[A[i]] += 1;
        last[A[i]] = i;
    }
    
    int ans = -1;
    int max_v = 0;
    for(auto [x, f] : freq) {
        if(f == 1) {
            if(x > max_v) {
                max_v = x;
                ans = last[x] + 1;
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
