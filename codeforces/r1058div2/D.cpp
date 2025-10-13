#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    auto query = [](std::vector<int>& a) {
        int n = a.size();
        std::cout << "? " << n << ' ';
        for(int i = 0; i < n; i++) {
            std::cout << a[i] + 1 << ' ';
        }
        std::cout << std::endl;
        
        int Q;
        std::cin >> Q;
        return Q;
    };

    std::vector<int> a;
    a.push_back(0); 
    
    std::vector<int> ans(N * 2, 0);
    for(int i = 1; i < N * 2; i++) {
        a.push_back(i);
        int res = query(a);
        if(res) {
            a.pop_back();
            ans[i] = res;
        }
    }

    a.clear();
    for(int i = 0; i < N * 2; i++) {
        if(ans[i]) {
            a.push_back(i);
        }
    }

    for(int i = 0; i < N * 2; i++) {
        if(ans[i] == 0) {
            a.push_back(i);
            ans[i] = query(a);
            a.pop_back();
        }
    }

    std::cout << "! ";
    for(int i = 0; i < N * 2; i++) {
        std::cout << ans[i] << ' ';
    }
    std::cout << std::endl;
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
