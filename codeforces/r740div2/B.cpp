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
    int A, B;
    std::cin >> A >> B;

    std::set<int> ans;
    int n = A + B;
    for(int x = 0; x <= A; x++) {
        int y = (n + 1) / 2 + x - A;
        if(y >= 0 && y <= B) {
            ans.insert(x + y); 
        }
        y = n / 2 + x - A;
        if(y >= 0 && y <= B) {
            ans.insert(x + y); 
        }
    }

    int k = ans.size();
    std::cout << k << '\n';
    for(int x : ans) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
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
