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
    
    std::map<int64_t, int64_t> m;
    //std::map<int64_t, std::set<int64_t>> m2;

    for(int i = 0; i < N; i++) {
        int S, C;
        std::cin >> S >> C;
        
        m[S] = C;    
        //m2[C].insert(S);
    }

    int64_t ans = 0;
    for(auto [s, c] : m) {
        if(c == 1) {
            continue;
        }

        int64_t ns = s;
        m[s] = 0; 
        while(c != 1) {
            if(c & 1) {
                m[ns] += 1; 
            }
            c /= 2;
            ns *= 2;  
        }

        m[ns] += 1;
    } 

    for(auto [s, c] : m) {
        ans += c;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
