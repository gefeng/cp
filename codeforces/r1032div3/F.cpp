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

    int64_t S, X;
    std::cin >> S >> X;

    std::vector<int64_t> A(N);
    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        psum[i + 1] = psum[i] + A[i];
    }

    int64_t ans = 0;
    for(int i = 0; i < N; ) {
        if(A[i] != X) {
            i += 1; 
            continue;
        }

        int l = i;
        int r = i;
        while(l >= 0 && A[l] <= X) {
            l -= 1;
        }
        while(r < N && A[r] <= X) {
            r += 1;
        }

        std::map<int64_t, int> m;
        std::vector<int64_t> save;
        int last = -1;
        int64_t sum = 0;
        save.push_back(0);
        for(int j = l + 1; j < r; j++) {
            sum += A[j]; 

            if(A[j] == X) {
                for(int64_t x : save) {
                    m[x] += 1;
                }
                save.clear();
                last = j;
            }

            if(last != -1) {
                if(m.find(sum - S) != m.end()) {
                    ans += m[sum - S];
                }
            }

            save.push_back(sum);
        }
        i = r;
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
