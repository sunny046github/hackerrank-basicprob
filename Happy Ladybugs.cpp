
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int cnt[1 << 8];
int main(){
    int Q;
    cin >> Q;
    for(int a0 = 0; a0 < Q; a0++){
        int n;
        cin >> n;
        string b;
        cin >> b;
        
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i++)
            cnt[b[i]]++;
        
        bool OK = true;
        for(int i = 'A'; i <= 'Z'; i++)
            if(cnt[i] == 1) OK = false;
        if(OK == false) {
            puts("NO");
            continue;
        }
        
        if(OK == true) {
            if(cnt['_'] != 0) {
                puts("YES");
                continue;
            }
            
            for(int i = 0; i < n; i++) {
                bool tmp = false;
                if(i - 1 >= 0 && b[i] == b[i - 1]) tmp = true;
                if(i + 1 <  n && b[i] == b[i + 1]) tmp = true;
                if(tmp == false) OK = false;
            }
            puts(OK ? "YES" : "NO");
        }
    }
    return 0;
}
