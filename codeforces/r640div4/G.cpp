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

    if(N < 4) {
        cout << -1 << '\n';
        return;
    }

    vector<int> ans;
    ans.reserve(N);

    int m = N / 4 - 1;

    int cur = 1;
    for(int i = 0; i < m; i++) {
        ans.push_back(cur + 1);
        ans.push_back(cur + 3);
        ans.push_back(cur);
        ans.push_back(cur + 2);
        cur += 4;
    }

    if(N % 4 < 2) {
        ans.push_back(cur + 1);
        ans.push_back(cur + 3);
        ans.push_back(cur);
        ans.push_back(cur + 2);
        cur += 4;
        
        if(N % 4 != 0) {
            ans.push_back(cur);
        }
    } else if(N % 4 == 3) {
        ans.push_back(cur);
        ans.push_back(cur + 4);
        ans.push_back(cur + 1);
        ans.push_back(cur + 5);
        ans.push_back(cur + 2);
        ans.push_back(cur + 6);
        ans.push_back(cur + 3);
    } else {
        ans.push_back(cur);
        ans.push_back(cur + 3);
        ans.push_back(cur + 1);
        ans.push_back(cur + 4);
        ans.push_back(cur + 2);
        ans.push_back(cur + 5);
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << " \n"[i == N - 1];
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
