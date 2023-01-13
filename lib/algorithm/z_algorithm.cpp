#include <vector>
#include <string>

using namespace std;

vector<int> z_algorithm(string& s) {
    int n = s.length();
    vector<int> z(n, 0);

    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        z[i] = max(0, min(z[i - l], r - i + 1));
        while(i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            l = i;
            r = i + z[i];
            z[i] += 1;
        }
    } 

    return z;
}
