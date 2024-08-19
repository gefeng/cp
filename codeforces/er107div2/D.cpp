#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> nxt(K, 0);
    std::string ans = "";
    int now = 0;
    int st = 0;
    for(int i = 0; i < N; i++) {
        ans.push_back((char)(now + 'a'));
        
        if(now == K - 1) {
            st = (st + 1) % K;
            if(st == 0) {
                nxt.assign(K, 0);
            }
            now = st;
        } else {
            int c = nxt[now];
            nxt[now] += 1; 
            now = c;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
