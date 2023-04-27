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

    std::map<int, int> m;
    for(int x : A) {
        for(int f = 2; f * f <= x; f += 1) {
            while(x % f == 0) {
                m[f] += 1;
                x /= f;
            }
        }

        if(x > 1) {
            m[x] += 1;
        }
    }
    
    int ans = 0;
    for(auto [k, v] : m) {
        ans += v / 2;
        m[k] = v % 2;
    }

    int cnt = 0;
    for(auto [k, v] : m) {
        cnt += v; 
    }

    ans += cnt / 3;

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
