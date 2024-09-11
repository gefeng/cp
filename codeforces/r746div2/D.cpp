#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <numeric>

int query(std::vector<int>& a) {
    int n = a.size();
    std::cout << "? " << n << ' ';
    for(int i = 0; i < n; i++) {
        std::cout << a[i] + 1 << ' ';
    }
    std::cout << std::endl;

    int Q;
    std::cin >> Q;
    return Q;
}

void dfs(std::vector<std::vector<int>>& G, int v, int p, std::vector<int>& tour) {
    tour.push_back(v);
    for(int nei : G[v]) {
        if(nei != p) {
            dfs(G, nei, v, tour);
            tour.push_back(v);
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }
    
    std::vector<int> a(N);
    std::iota(a.begin(), a.end(), 0);
    int max_v = query(a);
    
    std::vector<int> tour;
    dfs(G, 0, -1, tour);

    int lo = 0;
    int hi = tour.size() - 1;
    std::pair<int, int> ans = {-1, -1};
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        std::set<int> left;
        std::set<int> right;
        for(int i = lo; i <= mid; i++) {
            left.insert(tour[i]);
        }

        for(int i = mid; i <= hi; i++) {
            right.insert(tour[i]);
        }     
        
        if(left.size() <= 1) {
            a = std::vector<int>(right.begin(), right.end());            
            ans = {a[0], a[1]};
            break;
        }
        if(right.size() <= 1) {
            a = std::vector<int>(left.begin(), left.end());
            ans = {a[0], a[1]};
            break;
        }

        
        a = std::vector<int>(left.begin(), left.end());
        int q = query(a);
        if(q == max_v) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    std::cout << "! " << ans.first + 1 << ' ' << ans.second + 1 << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
