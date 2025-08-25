#include <bits/stdc++.h>
using namespace std;

int countSwaps(vector<int> arr, vector<int> sortedArr) {
    int n = arr.size();
    unordered_map<int, int> indexMap;

    for (int i = 0; i < n; i++) {
        indexMap[arr[i]] = i;
    }

    int swaps = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != sortedArr[i]) {
            swaps++;

            int currentVal = arr[i];
            int correctVal = sortedArr[i];

            // swap arr[i] with the correct value's position
            int correctIndex = indexMap[correctVal];

            swap(arr[i], arr[correctIndex]);

            // update indexMap
            indexMap[currentVal] = correctIndex;
            indexMap[correctVal] = i;
        }
    }
    return swaps;
}

int lilysHomework(vector<int> arr) {
    vector<int> incArr = arr;
    vector<int> decArr = arr;

    sort(incArr.begin(), incArr.end());
    sort(decArr.rbegin(), decArr.rend());

    int incSwaps = countSwaps(arr, incArr);
    int decSwaps = countSwaps(arr, decArr);

    return min(incSwaps, decSwaps);
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);
    int n = stoi(n_temp);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    stringstream ss(arr_temp_temp);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) ss >> arr[i];

    int result = lilysHomework(arr);

    fout << result << "\n";

    fout.close();
    return 0;
}
