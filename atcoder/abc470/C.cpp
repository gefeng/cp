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
    int N, Q;
    std::cin >> N >> Q;

    int ans = 0;
    std::set<int> s;
    std::vector<int> a(N, 0);
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
        
        if(T == 1) {
            int P;
            std::cin >> P;
            P--;
            a[P]++; 
            ans ^= a[P] - 1;
            ans ^= a[P];
            if(a[P] == 1) {
                s.insert(P);
            }
        } else {
            int res = 0;
            std::vector<int> remove;
            for(int p : s) {
                if(--a[p] == 0) {
                    remove.push_back(p);
                }
                if(a[p]) {
                    res ^= a[p];
                }
            }
            for(int p : remove) {
                s.erase(p);
            }
            ans = res;
        }
        std::cout << ans << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
