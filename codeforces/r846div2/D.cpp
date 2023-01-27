#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

int query(int x) {
    cout << "- " << x << endl;

    int res;
    cin >> res;
    
    return res;
}

void run_case() {
    int N;
    cin >> N;

    int ans = 0;
    int cnt = N;
    for(int i = 0, p = 0; i < N; i++, p++) {
        int x = 1 << p;
        int q = query(x);

        if(q < cnt) {
            ans |= 1 << p;
        } else {
            p += q - cnt + 1;
            ans |= 1 << p;
        }

        cnt = q;
    }

    cout << "! " << ans << endl;
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
