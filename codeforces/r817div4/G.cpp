#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <vector>

using namespace std;

void run_case() {
    int n;
    cin >> n;

    vector<int> ans(n, 0);
    
    int tot_odd = n / 2;
    int tot_eve = (n + 1) / 2;
    
    int last_odd = 0;
    int last_eve = 0;
    for(int i = 0, j = 0; i < tot_eve - 1; i++, j += 2) {
        last_eve ^= j + 2; 
        ans[j] = j + 2;
    } 

    for(int i = 0, j = 1; i < tot_odd - 1; i++, j += 2) {
        last_odd ^= j;
        ans[j] = j;
    }

    last_odd |= 1 << 30;
    last_eve |= 1 << 30;

    if(n % 2 == 0) {
        ans[n - 1] = last_odd;
        ans[n - 2] = last_eve;
    } else {
        ans[n - 1] = last_eve;
        ans[n - 2] = last_odd;
    }

    int res1 = 0;
    int res2 = 0;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) res1 ^= ans[i];
        if(i % 2 == 1) res2 ^= ans[i];
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        run_case();
    }
}
