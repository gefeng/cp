#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;

void run_case() {
    int N, X;
    cin >> N >> X;

    if(N % X != 0) {
        cout << -1 << '\n'; 
        return;
    }
    
    vector<int> ans(N + 1);
    ans[1] = X;
    ans[N] = 1;
    if(X != N) {
        ans[X] = N;
    }

    for(int i = 2; i < N; i++) {
        if(i != X) {
            ans[i] = i;
        }
    }

    int p = X;
    for(int i = X + 1; i < N; i++) {
        if(N % i == 0 && i % p == 0) {
            swap(ans[p], ans[i]);
            p = i;
        }
    }

    for(int i = 1; i <= N; i++) {
        cout << ans[i] << " \n"[i == N];
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
