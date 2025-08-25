#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    int target = 0, targetIdx=-1;
    int freq[26]; memset(freq, 0, sizeof freq);
    
    for (int i = 0; i < s.size(); ++i)
        freq[s[i]-'a']++;
    
    for (int i = 0; i < 26; ++i)
        if (freq[i]!=0)
            if (freq[i]>target){target=freq[i]; targetIdx = i;}
    
    bool yes = true;
    for (int i = 0; i < 26; ++i)
        if (freq[i] != 0 && freq[i]!=target) {
            yes = false;
            break;
        }
    if (yes) return "YES";
    
    yes = true;
    for (int i = 0; i < 26; ++i)
        if (freq[i] != 0 && i != targetIdx && target - freq[i] != 1) {
            yes = false;
            break;
        }
    if (yes) return "YES";
    
    yes = true; int onesCount=0;
    for (int i = 0; i < 26; ++i)
        if (freq[i]) {
            if (freq[i] == 1) 
                onesCount++;
            else if (freq[i] != target && freq[i] != 1)
                return "NO";
        }
    if (onesCount == 1) return "YES";
    
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
