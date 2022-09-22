#include <iostream>
#include <array>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);        // de-sync with c stream
    cin.tie(nullptr);                   // disable flushing of std::cout
    
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    
    int l = max(l1, l2);
    int r = min(r1, r2);
    
    if(l <= r) {
        cout << r - l << '\n';
    } else {
        cout << 0 << '\n';
    }
}
