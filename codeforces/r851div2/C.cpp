#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    if(N % 2 == 0) {
        cout << "No" << '\n';
        return;
    }

    int sum = (3 * N + 3) / 2;
    vector<pair<int, int>> ans;
    int a = 1;
    int b = sum - a;
    while(a < b) {
        ans.emplace_back(a, b);
        sum += 1;
        a += 2;
        b -= 1;
    } 

    a = 2;
    b = sum - a;
    while(ans.size() != N) {
        ans.emplace_back(a, b); 
        sum += 1;
        a += 2;
        b -= 1;
    }

    cout << "Yes" << '\n';
    for(auto& p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
