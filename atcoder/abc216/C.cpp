#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    LL N;
    cin >> N;
    
    LL x = N;
    string s = "";
    while(x) {
        if(x & 1LL) {
            x -= 1LL;
            s.push_back('A');
        } else {
            x /= 2LL;
            s.push_back('B');
        }
    }

    reverse(s.begin(), s.end());

    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
