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

    int64_t ans = 0;
    int cnt0 = 0;
    std::map<std::vector<int>, int> m; 
    for(int i = 0; i < N; i++) {
        if(A[i] == 0) {
            cnt0 += 1;
            ans += i;
            continue;
        }
        int x = A[i];
        std::vector<int> k;
        for(int f = 2; f * f <= x; f++) {
            if(x % f == 0) {
                int p = 0;
                while(x % f == 0) {
                    x /= f;
                    p ^= 1;
                }

                if(p) {
                    k.push_back(f); 
                }
            }
        }
        if(x > 1) {
            k.push_back(x);
        }

        if(m.find(k) != m.end()) {
            ans += m[k];
        } 
        ans += cnt0;

        m[k] += 1;
    } 

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
