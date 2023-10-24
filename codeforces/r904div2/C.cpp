#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::map<int, int> m;
    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
        m[A[i].first] = 0;
        m[A[i].second] = 0;
    }

    m[1] = 0;
    m[M] = 0;        
    
    int id = 0;
    for(auto& [_, v] : m) {
        v = id++;
    }

    for(auto& [l, r] : A) {
        l = m[l];
        r = m[r];
    }

    std::sort(A.begin(), A.end());

    std::multiset<std::pair<int, int>> mp;
    std::map<int, int> mr;
    std::map<int, int> ml;
    
    int ub = m[M];
    int ans = 0;
    for(int p = 0, i = 0; p <= ub; p++) {
        while(i < N && A[i].first <= p) {
            mp.emplace(A[i].second, A[i].first);
            mr[A[i].second] += 1;
            ml[A[i].first] += 1;
            i += 1;            
        } 

        while(!mp.empty()) {
            auto it = mp.begin();        
            if(it->first < p) {
                if(--mr[it->first] == 0) {
                    mr.erase(it->first);
                }
                if(--ml[it->second] == 0) {
                    ml.erase(it->second);
                }
                mp.erase(it);
            } else {
                break;
            } 
        }
        
        int max_v = mp.size();
        if(max_v == 0) {
            continue;
        }  

        int l = ml.begin()->first;
        int r = mr.rbegin()->first; 
        int min_v = 0;
        if(l > 0 || r < ub) {
           min_v = 0; 
        } else {
            min_v = std::min(ml.begin()->second, mr.rbegin()->second);
        }

        ans = std::max(ans, max_v - min_v);
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
