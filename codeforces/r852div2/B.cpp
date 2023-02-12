#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int X, Y;
    cin >> X >> Y;
 
    vector<int> ans;
 
    for(int i = X; i > Y; i--) {
        ans.push_back(i);
    }
 
    for(int i = Y; i < X; i++) {
        ans.push_back(i);
    }
 
    int sz = ans.size();
    cout << sz << '\n';
    for(int i = 0; i < sz; i++) {
        cout << ans[i] << " \n"[i == sz - 1];
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
