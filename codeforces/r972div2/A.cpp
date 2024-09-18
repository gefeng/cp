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

    std::vector<char> a = {'a', 'e', 'i', 'o', 'u'};

    int n = N / 5;
    int r = N % 5;

    std::string ans = "";
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < n; j++) {
            ans.push_back(a[i]);
        }
        if(r) {
            ans.push_back(a[i]);
            r -= 1;
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
