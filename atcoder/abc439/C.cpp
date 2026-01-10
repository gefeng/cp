#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <unordered_set>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> sq;
    for(int x = 1; x * x <= N; x++) {
        sq.push_back(x * x);
    }
    
    std::vector<int> s(N + 1, 0);
    std::vector<int> t(N + 1, 0);
    int n = sq.size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int x = sq[i] + sq[j];
            if(x <= N) {
                if(s[x]) {
                    if(t[x]) {
                        t[x] = 0;
                    }
                } else {
                    t[x] = 1;
                    s[x] = 1;
                }
            }
        }
    }

    std::vector<int> ans;
    for(int i = 1; i <= N; i++) {
        if(t[i]) {
            ans.push_back(i);
        }
    }

    int k = ans.size();
    std::cout << k << '\n';
    for(int x : ans) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
