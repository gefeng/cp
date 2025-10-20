#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B;
    std::cin >> A >> B;

    if(A == B) {
        std::cout << 0 << '\n';
        return;
    }
    
    int ha = -1;
    int hb = -1;
    for(int i = 29; i >= 0; i--) {
        if(A & (1 << i)) {
            ha = i;
            break;
        }
    } 

    for(int i = 29; i >= 0; i--) {
        if(B & (1 << i)) {
            hb = i;
            break;
        }
    } 

    if(hb > ha) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<int> ans;
    int x = 0;
    for(int i = ha; i >= 0; i--) {
        if(!(A & (1 << i))) {
            x |= 1 << i;
        }
    }

    ans.push_back(x);
    
    A ^= x;
    
    ans.push_back(A ^ B);
    
    std::cout << 2 << '\n';
    std::cout << ans[0] << ' ' << ans[1] << '\n';

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
