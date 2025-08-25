#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'noPrefix' function below.
 *
 * The function accepts STRING_ARRAY words as parameter.
 */

void noPrefix(vector<string> words) {
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isComplete = false;

        bool add(const string &word, int index = 0) {
            if (isComplete) return false; // existing word is prefix

            if (index == (int)word.size()) {
                isComplete = true;
                return children.empty(); // this word is prefix of another
            }

            char c = word[index];
            if (children.find(c) == children.end()) {
                children[c] = new TrieNode();
            } else if (index + 1 == (int)word.size()) {
                return false; // new word is prefix of an existing word
            }

            return children[c]->add(word, index + 1);
        }
    };

    TrieNode *root = new TrieNode();

    for (int i = 0; i < (int)words.size(); i++) {
        if (!root->add(words[i])) {
            cout << "BAD SET\n" << words[i] << "\n";
            return;
        }
    }
    cout << "GOOD SET\n";
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        string words_item;
        getline(cin, words_item);

        words[i] = words_item;
    }

    noPrefix(words);

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
