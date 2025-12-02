#include <iostream>
#include <string>
using namespace std;

const int prime = 101;
const int base = 256;

void rabinKarp(string text, string pat, int result[], int &found, int falsePos[], int &falseCount) {
    int n = text.size();
    int m = pat.size();

    int patHash = 0, txtHash = 0, h = 1;
    found = 0;
    falseCount = 0;

    for (int i = 0; i < m - 1; i++)
        h = (h * base) % prime;

    for (int i = 0; i < m; i++) {
        patHash = (patHash * base + pat[i]) % prime;
        txtHash = (txtHash * base + text[i]) % prime;
    }

    for (int i = 0; i <= n - m; i++) {
        if (patHash == txtHash) {
            bool match = true;
            for (int j = 0; j < m; j++)
                if (text[i + j] != pat[j]) match = false;

            if (match) result[found++] = i;
            else falsePos[falseCount++] = i;
        }

        if (i < n - m) {
            txtHash = (txtHash - text[i] * h) % prime;
            if (txtHash < 0) txtHash += prime;
            txtHash = (txtHash * base + text[i + m]) % prime;
        }
    }
}

int main() {
    string text = "Data structures and algorithms are fun. Algorithms make tasks easier.";
    string pat  = "Algorithms";

    int result[100], falsePos[100];
    int found, falseCount;

    rabinKarp(text, pat, result, found, falsePos, falseCount);

    cout << "Rabin-Karp Matches at: ";
    for (int i = 0; i < found; i++) cout << result[i] << " ";

    cout << "\nFalse Positives at: ";
    for (int i = 0; i < falseCount; i++) cout << falsePos[i] << " ";

    cout << endl;
    return 0;
}
