#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    int h = (s[0] - '0') * 10 + (s[1] - '0');  // hour as number
    string ampm = s.substr(8, 2);              // AM or PM

    if (ampm == "AM") {
        if (h == 12) h = 0;                   // midnight -> 00
    } else {
        if (h != 12) h += 12;                 // add 12 for PM (except 12PM)
    }

    // make new hour string
    string hh;
    if (h < 10) hh = "0" + to_string(h);
    else hh = to_string(h);

    return hh + s.substr(2, 6);               // hh:mm:ss
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
