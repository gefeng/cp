#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}
void run_case() {
    int N;
    cin >> N;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> last(1001, -1);
    for(int i = 0; i < N; i++) {
        last[A[i]] = i;
    } 

    int ans = -1;
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= 1000; j++) {
            if(gcd(i, j) == 1 && last[i] != -1 && last[j] != -1) {
                ans = max(ans, last[i] + last[j] + 2); 
            }
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
