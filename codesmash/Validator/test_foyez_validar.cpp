#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 1500, "n");
    inf.readEoln();

    for (int i = 1; i <= n; i++) {
        string s = inf.readWord("[a-z]{1, 10}", "s");
        ensuref(s.length() <= 10, "String 's' should have length less than or equal to 15");

        if(i < n)
            inf.readSpace();
    }
    inf.readEoln();

    vector<int> cnt;

    for (int i = 1; i <= n; i++) {
        int x = inf.readInt(1, 1500, "x");
        cnt.push_back(x);
        if (i < n) 
            inf.readSpace();
    }
    inf.readEoln();

    for (int i = 1; i <= n; i++) {
        int x = inf.readInt(0, 1500, "x");
        if (i < n) 
            inf.readSpace();
    }
    inf.readEoln();


    for (auto c : cnt) {
        for (int i = 1; i <= c; i++) {
            int x = inf.readInt(-1500, 1500, "x");
            if (i < c) {
                inf.readSpace();
            }
        }
        inf.readEoln();
    }

    inf.readEof();
}