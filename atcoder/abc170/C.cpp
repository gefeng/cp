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
    int X, N;
    cin >> X >> N;

    set<int> s;
    for(int i = 0; i < N; i++) {
        int Y;
        cin >> Y;
        s.insert(Y);
    }

    int l = X;
    int r = X;
    int ans = 0;
    while(true) {
        if(s.find(l) == s.end()) {
            ans = l; 
            break;
        } 

        if(s.find(r) == s.end()) {
            ans = r;
            break;
        }

        l -= 1; 
        r += 1;
    } 

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
