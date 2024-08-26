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

    std::string S;
    std::cin >> S;
    
    std::vector<std::pair<int, int>> a(26);
    for(int i = 0; i < 26; i++) {
        a[i].second = i;
    }

    for(char c : S) {
        a[c - 'a'].first += 1;
    }

    std::sort(a.begin(), a.end(), std::greater<std::pair<int, int>>());
    std::vector<std::string> s(a[0].first, std::string(1, (char)(a[0].second + 'a')));
    std::string ans = "";
    
    int p = 0;
    int n = s.size();
    for(int i = 1; i < 26; i++) {
        if(a[i].first == 0) {
            break;
        }

        char c = (char)(a[i].second + 'a');

        while(a[i].first > 0) {
            s[p].push_back(c);
            p = (p + 1) % n;
            a[i].first -= 1;
        }
    }

    for(auto& x : s) {
        ans.append(x);
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
