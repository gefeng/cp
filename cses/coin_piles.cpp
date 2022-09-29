#include <iostream>

using namespace std;

void run_case() {
    int A, B;
    cin >> A >> B;

    bool ok = false;
    
    if(A == 0 && B == 0) {
        ok = true;
    } else if(A == 0 || B == 0) {
        ok = false;
    } else {
        if(A > B) {
            swap(A, B);
        }

        if((A + B) % 3 != 0 || A * 2 < B) {
            ok = false;
        } else {
            ok = true;
        }
    }
    
    cout << (ok ? "YES" : "NO") << '\n';
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
