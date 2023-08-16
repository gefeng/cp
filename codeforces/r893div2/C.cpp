#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> a;
    std::map<int, int> m;

    for(int i = 1; i <= N; i++) {
        int x = i * 2;
        if(x > N) {
            break;
        }

        if(m.find(i) != m.end()) {
            int j = m[i];
            a[j].push_back(x);
            m[x] = j;
        } else {
            a.emplace_back();
            a.back().push_back(i);
            a.back().push_back(x);
            m[i] = a.size() - 1;
            m[x] = a.size() - 1;
        }
    }

    std::vector<int> vis(N + 1, 0);
    std::vector<int> ans;
    for(auto& v : a) {
        for(int x : v) {
            ans.push_back(x);
            vis[x] = 1;
        } 
    }

    for(int i = 1; i <= N; i++) {
        if(!vis[i]) {
            ans.push_back(i);
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
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
