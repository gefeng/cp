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

    int n = S.size();
    std::string t1 = "";
    std::string t2 = "";

    for(int i = 0; i < n; i++) {
        t1.append("()");
        t2.push_back('(');
    }

    for(int i = 0; i < n; i++) {
        t2.push_back(')'); 
    }

    if(t1.find(S) == std::string::npos) {
        std::cout << "YES" << '\n';
        std::cout << t1 << '\n';
        return;
    } 
    if(t2.find(S) == std::string::npos) {
        std::cout << "YES" << '\n';
        std::cout << t2 << '\n';
        return;
    }
    std::cout << "NO" << '\n';
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
