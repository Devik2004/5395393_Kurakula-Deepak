#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bomberMan' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 */

vector<string> getMirrorOf(vector<string> grid) {
    const int r = grid.size(), c = grid[0].size();
    int i, j; char tracker[r][c];
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
            tracker[i][j] = '0';
            
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
            if (grid[i][j] == 'O') {
                if (i!=0) tracker[i-1][j] = 'X';
                if (i!=r-1) tracker[i+1][j] = 'X';
                if (j!=0) tracker[i][j-1] = 'X';
                if (j!=c-1) tracker[i][j+1] = 'X';
                tracker[i][j] = 'X';        
            }
            else if (tracker[i][j] != 'X') tracker[i][j] = '.';
            
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
            grid[i][j] = (tracker[i][j]=='X')?'.':'O';
            
    return grid;
}

vector<string> bomberMan(int n, vector<string> grid) {
    int r = grid.size(), c = grid[0].size();
    
    if (n == 1) 
        return grid;
        
    if (n%2==0) {
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                grid[i][j] = 'O';
        return grid;
    }
    
    grid = getMirrorOf(grid);
    
    if (n % 4 == 3)
        return grid;
        
    return getMirrorOf(grid);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
