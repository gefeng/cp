#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S;
    
    int ans = 0;
    while(std::getline(std::cin, S)) {
        int p = S.find(','); 
        int n = S.size();
        std::string s1 = S.substr(0, p);
        std::string s2 = S.substr(p + 1, n - p - 1);

        int p1 = s1.find('-');
        int p2 = s2.find('-');

        int l1 = stoi(s1.substr(0, p1));
        int r1 = stoi(s1.substr(p1 + 1, s1.size() - p1 - 1));

        int l2 = stoi(s2.substr(0, p2));
        int r2 = stoi(s2.substr(p2 + 1, s2.size() - p2 - 1));

        if((l1 >= l2 && l1 <= r2) || (l2 >= l1 && l2 <= r1)) {
            ans += 1;
        } 
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
