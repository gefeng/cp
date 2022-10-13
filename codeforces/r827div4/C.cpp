#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    vector<string> A(8, "");
    for(int i = 0; i < 8; i++) {
        cin >> A[i];
    }

    string r = "RRRRRRRR";
    string b = "BBBBBBBB";
    
    for(int i = 0; i < 8; i++) {
        if(A[i] == r) {
            cout << 'R' << '\n';
            return;
        }
    }

    cout << 'B' << '\n';
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
