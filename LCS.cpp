#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
void Longest_Common_Subsequence(string s1, string s2) {
    int a = s1.length();
    int b = s2.length();

    int lcs[100][100];

    for(int x = 0; x <= a; x++) {
        lcs[x][0] = 0;
    }
    for(int y = 0; y <= b; y++) {
        lcs[0][y] = 0;
    }

    for(int i = 1; i <= a; i++) {
        for(int j = 1; j <= b; j++) {
            if(s1[i-1] == s2[j-1]) {
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }
            else {
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }

    cout << "LCS Length: " << lcs[a][b] << endl;
}

int main() {
    string s1, s2;

    cout << "Enter the first string: ";
    cin >> s1;

    cout << "Enter the second string: ";
    cin >> s2;

    Longest_Common_Subsequence(s1, s2);

    return 0;
}
