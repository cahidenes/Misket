#include <bits/stdc++.h>

#define inf 1000000000

using namespace std;

int tl, tr, ml, mr, c;

int uzulen(int m, int t) {
    if (m % t <= c && m >= t) return 0;
    else return t - m%t;
}

int main() {

    int D;
    cin >> D;
    while (D--) {

        cin >> tl >> tr >> ml >> mr >> c;

        int min_en_kotu_ihtimal = inf;
        int cevap = 0;

        for (int m = ml; m <= mr; m++) {

            int en_kotu_ihtimal = 0;
            for (int t = max(tl, min(tr, c+1)); t <= tr; t++) {
                en_kotu_ihtimal = max(en_kotu_ihtimal, uzulen(m, t));
            }

            if (en_kotu_ihtimal <= min_en_kotu_ihtimal) {
                min_en_kotu_ihtimal = en_kotu_ihtimal;
                cevap = m;
            }

        }

        cout << cevap << '\n';

    }
}