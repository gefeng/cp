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
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] -= 1;
    }

    vector<int> pos(N, 0);
    for(int i = 0; i < N; i++) {
        pos[A[i]] = i;
    }

    int l = 0;
    int r = 0;
    if(N & 1) {
        l = N / 2;
        r = N / 2;
    } else {
        l = N / 2 - 1;
        r = N / 2;
    }

    int ans = N  / 2;
    int i = pos[l];
    int j = pos[r];
    while(i <= j && l >= 0) {
        if(i != j) {
            ans -= 1;
        }
        if(l && pos[l - 1] < pos[l] && pos[r] < pos[r + 1]) {
            l -= 1;
            r += 1;
            i = pos[l];
            j = pos[r];
        } else {
            break;
        }
    }
    
    cout << ans << '\n';
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
