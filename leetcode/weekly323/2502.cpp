#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Allocator {
public:
    vector<int> v;
    int sz;
    Allocator(int n) {
        v.resize(n, 0);
        sz = n;
    }
    
    int allocate(int size, int mID) {
        for(int i = 0; i < sz; ) {
            if(v[i] == 0) {
                int j = i;
                while(i < sz && v[i] == 0) {
                    i += 1;
                }  
                
                if(i - j >= size) {
                    for(int k = j; k < min(i, j + size); k++) {
                        v[k] = mID;
                    }
                    return j;
                }
            } else {
                i += 1;
            }
        }
        
        return -1;
    }
    
    int free(int mID) {
        int sum = 0;
        for(int i = 0; i < sz; ) {
            if(v[i] == mID) {
                int j = i;
                while(i < sz && v[i] == mID) {
                    v[i] = 0;
                    i += 1;
                }
                sum += i - j;
            } else {
                i += 1;
            }
        }
        
        return sum;
    }
};
