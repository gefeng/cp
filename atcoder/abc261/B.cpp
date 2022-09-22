#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);        // de-sync with c stream
    cin.tie(nullptr);                   // disable flushing of std::cout
    
    int n = 0;
    vector<string> g;

    cin >> n;
    g.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> g[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j) {
                if((g[i][j] == 'W' && g[j][i] != 'L') || (g[i][j] == 'L' && g[j][i] != 'W') ||
                        (g[i][j] == 'D' && g[j][i] != 'D')) {
                    cout << "incorrect" << '\n';
                    return 0;
                }
            }
        }
    }

    cout << "correct" << '\n';
}
