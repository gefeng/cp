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
    string S;
    cin >> S;
    
    vector<int> ans;
    ans.push_back(1);
    int cnt = 1;
    for(int i = 1; i < N - 1; i++) {
        cnt += 1;
        if(S[i] == S[i - 1]) {
            cnt = max(1, cnt - 1); 
        } else {
            cnt = i + 1;
        }
        ans.push_back(cnt);
    }

    for(int i = 0; i < N - 1; i++) {
        cout << ans[i] << " \n"[i == N - 2];
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
