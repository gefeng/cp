#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

std::vector<std::string> dfs(int N) {
    if(N == 0) {
        std::vector<std::string> res;
        res.push_back(std::string(1, '#'));
        return res;
    } 

    std::vector<std::string> ret = dfs(N - 1);
    
    int n = ret.size();
    std::vector<std::string> res;
    
    for(int i = 0; i < n; i++) {
        std::string s = "";
        for(int j = 0; j < 3; j++) {
            s.append(ret[i]); 
        } 
        res.push_back(s);
    }

    for(int i = 0; i < n; i++) {
        std::string s = ""; 
        s.append(ret[i]);
        s.append(std::string(n, '.'));
        s.append(ret[i]);
        res.push_back(s);
    }

    for(int i = 0; i < n; i++) {
        std::string s = "";
        for(int j = 0; j < 3; j++) {
            s.append(ret[i]); 
        } 
        res.push_back(s);
    }

    return res;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::string> ans = dfs(N); 
    for(int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
