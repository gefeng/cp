#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, A, B;
    cin >> N >> A >> B;
 
    if(A == B && A == N) {
        cout << "Yes" << '\n';
        return;
    }
 
    if(A + B >= N) {
        cout << "No" << '\n';
        return;
    }
 
    if(N - A - B > 1) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
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
