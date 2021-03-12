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

        vector<int> en_buyuk_bolen(mr+1, 0);
        for (int i = tl; i <= tr; i++) {
            for (int j = i; j <= mr; j += i) {
                en_buyuk_bolen[j] = i;
            }
        }

        int en_kotu = 0;
        for (int t = tl; t <= tr; t++) {
            en_kotu = max(en_kotu, uzulen(ml, t));
        }

        int cevap = ml;
        int cevap_en_kotu = en_kotu;
        for (int m = ml; m <= mr; m++) {

            if (m-c-1 > 0 && en_buyuk_bolen[m-c-1] != 0) {
                en_kotu = max(en_kotu, uzulen(m, en_buyuk_bolen[m-c-1]) + (m-ml));
            }
            
            if (en_kotu - (m-ml) <= cevap_en_kotu) {
                cevap_en_kotu = max(0, en_kotu - (m-ml));
                cevap = m;
            }
        }

        cout << cevap << '\n';

    }

}