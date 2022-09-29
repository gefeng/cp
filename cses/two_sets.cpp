#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int N;
    cin >> N;

    LL sum = (1LL + N) * N / 2LL;

    if(sum & 1) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';

        if(N & 1) {
            int size_1 = N / 2;
            int size_2 = N / 2 + 1;

            cout << size_1 << '\n'; 
            int cur = 1;
            for(int i = 0; i < size_1 - 1; i += 2) {
                cout << cur << ' ' << N - cur << ' ';
                cur++;
            }
            cout << N << '\n';

            cout << size_2 << '\n';
            for(int i = 0; i < size_2; i += 2) {
                cout << cur << ' ' << N - cur << " \n"[i == size_2 - 2];
                cur++;
            }
        } else {
            int size = N / 2;
            
            cout << size << '\n';
            int cur = 1;
            for(int i = 0; i < size; i += 2) {
                cout << cur << ' ' << N - cur + 1 << " \n"[i == size - 2];
                cur++;
            }
            
            cout << size << '\n';
            for(int i = 0; i < size; i += 2) {
                cout << cur << ' ' << N - cur + 1 << " \n"[i == size - 2];
                cur++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
