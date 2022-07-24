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

class NumberContainers {
public:
    unordered_map<int, int> map;
    unordered_map<int, set<int>> imap;

    NumberContainers() {
                 
    }
    
    void change(int index, int number) {
        if(map.count(index)) { 
            int old = map[index];
            imap[old].erase(index);
            if(imap[old].empty()) {
                imap.erase(old);
            }
        }
        
        map[index] = number;
        imap[number].insert(index);
    }
    
    int find(int number) {
        if(imap.count(number)) {
            return *imap[number].begin();
        }

        return -1;
    }
};
