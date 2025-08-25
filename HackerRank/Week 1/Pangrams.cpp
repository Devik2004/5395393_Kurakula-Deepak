#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    bool freq[26];
    memset(freq, false, sizeof(freq));

    for (int i = 0; i < s.size(); i++) {
        char ch = tolower(s[i]);
        if (ch >= 'a' && ch <= 'z') {
            freq[ch - 'a'] = true;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (!freq[i]) return "not pangram";
    }
    return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
