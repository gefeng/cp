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
    std::cin >> S;

    std::string ans = "";
    int h = stoi(S.substr(0, 2));
    int m = stoi(S.substr(3, 2));
    
    if(h == 0) {
        ans.append("12:");
        ans.append(S.substr(3, 2));
        ans.append(" AM");
    } else if(h == 12) {
        ans.append(S);
        ans.append(" PM");
    } else if(h < 12) {
        ans.append(S); 
        ans.append(" AM");
    } else {
        std::string hs = std::to_string(h - 12);
        if(hs.size() == 1) {
            hs = "0" + hs;
        }
        
        ans.append(hs);
        ans.append(S.substr(2, 3));
        ans.append(" PM");
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
