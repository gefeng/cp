#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, K;
    cin >> N >> K;

    vector<int> v(N + 1, 0);
    for(int i = 1, j = 1, tot = 1; i <= N; i++, j++, tot += j) {
        v[i] = tot; 
    }

    int now = 0;
    int len = 0;
    for(int i = 1; i <= N; i++) {
        if(v[i] <= K) {
            now = v[i];
            len = i;
        }
    }

    if(now == 0) {
        for(int i = 0; i < N; i++) {
            cout << -1000 << " \n"[i == N - 1];
        }
        return;
    }

    if(now == v[N]) {
        for(int i = 0; i < N; i++) {
            cout << 1000 << " \n"[i == N - 1];
        }
        return;
    }

    vector<int> ans(N);
    int sum = 0;
    for(int i = 0; i < len; i++) {
        ans[i] = i + 2;
        sum += i + 2;
    }

    for(int i = len; i < N; i++) {
        ans[i] = -1000;
    }

    int need = K - now;
    if(need != 0) {
        for(int i = 0; i < need - 1; i++) {
            sum -= ans[i];
        }  
        
        sum = sum - 1; 
        sum *= -1;
        ans[len] = sum;
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
