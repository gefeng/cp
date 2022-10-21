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

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        int x = A[i];
        while(x % 2 == 0) {
            cnt++;
            x /= 2;
        }
    }

    int need = N - cnt;
    if(need <= 0) {
        cout << 0 << '\n';
        return;
    }

    vector<int> v(N, 0);
    for(int i = 0; i < N; i++) {
        int x = i + 1;
        int y = 0;
        while(x % 2 == 0) {
            y++;
            x /= 2;
        }
        
        v[i] = y; 
    }

    sort(v.begin(), v.end(), greater<int>());

    int p = 0; 
    int ans = 0;
    while(need && p < N) {
        int d = min(need, v[p]);
        if(d) {
            need -= d;
            ans++;
        }
        p++;
    }

    cout << (need == 0 ? ans : -1) << '\n';
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
