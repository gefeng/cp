#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int64_t dfs(std::vector<int>& a) {
    if(a.size() == 1) {
        return a[0] == 0 ? 0 : 1;
    }

    int64_t res = 0;
    int n = a.size();
    int p = std::min_element(a.begin(), a.end()) - a.begin();
    std::vector<int> l;
    std::vector<int> r;
    
    for(int x : a) {
        if(x) {
            res += 1;
        }
    }

    for(int i = 0; i < p; i++) {
        l.push_back(a[i] - a[p]);
    } 

    for(int i = p + 1; i < n; i++) {
        r.push_back(a[i] - a[p]);
    }

    int64_t cnt = a[p];
    if(!l.empty()) {
        cnt += dfs(l); 
    }
    if(!r.empty()) {
        cnt += dfs(r);
    }

    res = std::min(res, cnt);

    return res;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::cout << dfs(A) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
