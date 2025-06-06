#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, A, B;
    std::cin >> N >> A >> B;

    std::string ans = "";
    std::string s = "";
    for(int i = 0, j = 0; i < A; i++, j = (j + 1) % B) {
        s.push_back(char(j + 'a')); 
    }

    int p = 0;
    while(ans.size() != N) {
        ans.push_back(s[p]);
        p += 1;
        p %= A;
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
