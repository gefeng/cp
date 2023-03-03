#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int K;
    cin >> K;
    
    string S;
    cin >> S;

    string t = "FBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFB";
    
    cout << (t.find(S) != string::npos ? "YES" : "NO") << '\n';
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
