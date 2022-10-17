#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for(int i = 0; i < n; ) {
        if(s[i] == '0') {
            i++;
            continue;
        }

        int j = i;
        int min_v = a[i];
        while(i < n && s[i] == '1') {
            ans += a[i];
            min_v = min(min_v, a[i]);
            i++;
        }

        if(j && a[j - 1] > min_v) {
            ans -= min_v;
            ans += a[j - 1];
        }
    }

    cout << ans << '\n';
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
