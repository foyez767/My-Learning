#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 100000, "n");
    inf.readEoln();

    for (int i = 1; i <= n; i++) {
        string s = inf.readWord();

        if(i < n)
            inf.readSpace();
    }
    inf.readEoln();

    vector<int> cnt;

    for (int i = 1; i <= n; i++) {
        int x = inf.readInt(1, 1000, "x");
        cnt.push_back(x);
        if (i < n) 
            inf.readSpace();
    }
    inf.readEoln();

    for (int i = 1; i <= n; i++) {
        int x = inf.readInt(1, 1000, "x");
        if (i < n) 
            inf.readSpace();
    }
    inf.readEoln();


    for (auto c : cnt) {
        for (int i = 1; i <= c; i++) {
            int x = inf.readInt(-100, 100, "x");
            if (i < c) {
                inf.readSpace();
            }
        }
        inf.readEoln();
    }

    inf.readEof();
}