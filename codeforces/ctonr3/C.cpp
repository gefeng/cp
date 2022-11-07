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

    string A, B;
    cin >> A >> B;

    vector<pair<int, int>> ans;
    if(A != B) {
        for(int i = 0; i < N; i++) {
            if(A[i] == B[i]) {
                cout << "NO" << '\n';
                return;
            }
        } 
    }

    if(A == B) {
        ans.emplace_back(1, N);
        for(int i = 0; i < N; i++) {
            A[i] = A[i] == '0' ? '1' : '0';
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] == '0') {
            ans.emplace_back(i + 1, i + 1);
            cnt += 1;
        }
    } 
    
    if(B[0] == '0') {
        B[0] = cnt % 2 == 1 ? '1' : '0'; 
    } else {
        B[0] = cnt % 2 == 1 ? '1' : '0';
    }

    if(B[0] == '0') {
        ans.emplace_back(1, N);
    } else {
        ans.emplace_back(1, 1);
        ans.emplace_back(2, N);
    }

    cout << "YES" << '\n';
    int sz = ans.size();
    cout << sz << '\n';
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
