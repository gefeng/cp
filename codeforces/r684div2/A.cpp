#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X, Y, H;
    std::cin >> N >> X >> Y >> H;

    std::string S;
    std::cin >> S;
    
    int ans = 0;
    for(int i = 0; i < N; i++) {
        ans += S[i] == '0' ? X : Y;
    } 
    if(X < Y) {
        if(X + H < Y) {
            ans = 0;
            for(int i = 0; i < N; i++) {
                ans += S[i] == '0' ? X : X + H;
            }
        }
    } else if(X > Y) {
        if(Y + H < X) {
            ans = 0;
            for(int i = 0; i < N; i++) {
                ans += S[i] == '0' ? Y + H : Y;
            }
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
