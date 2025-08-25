#include <iostream>
#include <set>
using namespace std;

int main() {
    
    int q; cin >> q;
    set<int> st;
    
    while (q--) {
        int op; cin >> op;
        int x;
        
        if (op == 1) {
            cin >> x;
            st.insert(x);
        } 
        else if (op == 2) {
            cin >> x;
            auto it = st.find(x);
            st.erase(it); 
        }
        else 
            cout << *st.begin() << '\n';
    }
    
    return 0;
}