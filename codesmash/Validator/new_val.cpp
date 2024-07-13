#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 200000, "n");
    inf.readSpace();
    int m = inf.readInt(1, 200000, "m");

    ensuref(m <= n, "m should be less than or equal to n");

    inf.readEoln();

    string a = inf.readWord();
    ensuref(a.length() <= 200000 && (a.length() == n), "String 'a' should have length less than or equal to 200000");
    inf.readEoln();

    string b = inf.readWord();
    ensuref(b.length() <= 200000 && (b.length() == m), "String 'b' should have length less than or equal to 200000");
    
    ensuref(b.length() <= a.length(), "String 'b' should have length less than or equal to 'a' ");

    inf.readEoln();

    bool batti = true;

    for (int i = 0; i < n; i++) {
        if (!((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))) {
            batti = false;
            break;
        } 
    }

    for (int i = 0; i < m; i++) {
        if (!((b[i] >= 'a' and b[i] <= 'z') || (b[i] >= 'A' and b[i] <= 'Z'))) {
            batti = false;
            break;
        } 
    }

    ensuref(batti == true, "Invalid characters detected");

    inf.readEof();
}