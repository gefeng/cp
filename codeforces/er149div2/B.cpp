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
    int N;
    std::cin >> N;
    
    std::string S;
    std::cin >> S;

    /*int ans = N + 1;
    for(int i = 0; i <= N; i++) {
        std::set<int> seen;
        seen.insert(0);
        int x = 0;
        for(int j = i - 1; j >= 0; j--) {
            if(S[j] == '<') {
                x -= 1;
            } else {
                x += 1;
            }
             
            seen.insert(x);
        } 
        
        x = 0;
        for(int j = i; j < N; j++) {
            if(S[j] == '<') {
                x += 1;
            } else {
                x -= 1;
            }
             
            seen.insert(x);
        }

        ans = std::min(ans, (int)seen.size());
    }

    std::cout << ans << '\n';*/

    int ans = 2;
    int cnt = 1;
    for(int i = 1; i < N; i++) {
        if(S[i] == S[i - 1]) {
            cnt += 1;
        } else {
            cnt = 1;
        }
        ans = std::max(ans, cnt + 1);
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
