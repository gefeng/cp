#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int sum = std::accumulate(A.begin(), A.end(), 0);

    std::vector<int> divisors;
    for(int f = 1; f * f <= sum; f++) {
        if(sum % f == 0) {
            divisors.push_back(f);
            if(f * f != sum) {
                divisors.push_back(sum / f);
            }
        }
    }
    
    int ans = N;
    for(int s : divisors) {
        if(sum % s != 0) {
            continue;
        }
        
        int thickness = 0;
        bool ok = true;
        for(int i = 0; i < N; ) {
            int j = i;
            int now = 0;
            while(i < N && now + A[i] <= s) {
                now += A[i++];
            }
            if(now != s) {
                ok = false;
                break;
            }
            thickness = std::max(thickness, i - j);
        }

        if(ok) {
            ans = std::min(ans, thickness);
        }
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
