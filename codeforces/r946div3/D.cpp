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
    
    std::string S;
    std::cin >> S;

    std::map<char, int> m;
    for(int i = 0; i < N; i++) {
        m[S[i]] += 1;
    }

    if(m['N'] % 2 != m['S'] % 2 || m['E'] % 2 != m['W'] % 2) {
        std::cout << "NO" << '\n';
        return;
    }

    std::map<char, int> who = {{'N', 0}, {'S', 0}, {'W', 1}, {'E', 1}};
    std::string ans;
    for(int i = 0; i < N; i++) {
        if(who[S[i]] == 0) {
            ans.push_back('R');
        } else {
            ans.push_back('H');
        }
        who[S[i]] ^= 1;
    }

    bool unique = true;
    for(int i = 0; i < N; i++) {
        if(ans[i] != ans[0]) {
            unique = false;
            break;
        }
    }

    if(unique) {
        std::cout << "NO" << '\n';
    } else {
        std::cout << ans << '\n';
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
