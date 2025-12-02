#include <iostream>
#include <string>
using namespace std;

int strLength(const string &s) {
    int c = 0;
    while (c < s.size()) c++;
    return c;
}

void bruteForceSearch(string text, string pat, int result[], int &found, int &comparisons) {
    int n = text.size();
    int m = pat.size();
    found = 0;
    comparisons = 0;

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m) {
            comparisons++;
            if (text[i + j] != pat[j]) break;
            j++;
        }
        if (j == m) {
            result[found++] = i;
        }
    }
}

int main() {
    string text = "the quick brown fox jumps over the lazy dog";
    string pat  = "the";

    int result[100], found, comparisons;

    bruteForceSearch(text, pat, result, found, comparisons);

    cout << "Brute Force Positions: ";
    for (int i = 0; i < found; i++) cout << result[i] << " ";

    cout << "\nTotal Comparisons: " << comparisons << endl;
    return 0;
}

