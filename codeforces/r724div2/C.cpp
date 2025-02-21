#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::string S;
    std::cin >> S;

    std::vector<int> ans(N + 1, 0);
    std::map<std::pair<int, int>, int> s;
    int cnt_d = 0;
    int cnt_k = 0;
    for(int i = 0; i < N; i++) {
        cnt_d += S[i] == 'D' ? 1 : 0;
        cnt_k += S[i] == 'K' ? 1 : 0;
        
        int a = cnt_d;
        int b = cnt_k;
        if(a != 0 && b != 0) {
            int g = gcd(a, b);
            a /= g;
            b /= g;
            ans[i + 1] = ++s[{a, b}];
        } else {
            ans[i + 1] = ans[i] + 1;
        }
    }

    for(int i = 1; i <= N; i++) {
        std::cout << ans[i] << " \n"[i == N];
    } 
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
