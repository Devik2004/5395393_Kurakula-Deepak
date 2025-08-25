#include <iostream>
#include <stack>
using namespace std;

int main() {
    int Q; cin >> Q; 
    string S="";
    stack<string> lastOperations;
    
    while(Q--) {
        int op, k; cin >> op; 
        string addedString;
        switch (op) {
            case 1:
                cin >> addedString;
                lastOperations.push(S);
                S += addedString;
            break;
            case 2:
                cin >> k;
                lastOperations.push(S);
                S.erase(S.size()-k);
            break;
            case 4:
                S = lastOperations.top();
                lastOperations.pop();
            break;
            default:
                cin >> k;
                cout << S[k-1] << '\n';
        }
    }
    
    return 0;
}