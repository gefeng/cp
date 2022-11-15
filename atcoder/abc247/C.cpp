#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

vector<int> dfs(int n) {
    if(n == 1) {
        return {1};
    } 

    vector<int> ret = dfs(n - 1);
    
    vector<int> res;
    for(int i = 0; i < ret.size(); i++) {
        res.push_back(ret[i]);
    }

    res.push_back(n);

    for(int i = 0; i < ret.size(); i++) {
        res.push_back(ret[i]);
    }
    
    return res;
}

void run_case() {
    int N;
    cin >> N;
    
    vector<int> ans = dfs(N);
    int sz = ans.size();
    for(int i = 0; i < sz; i++) {
        cout << ans[i] << " \n"[i == sz - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
