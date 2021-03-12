#include <bits/stdc++.h>

#define inf 1000000000

using namespace std;

int tl, tr, ml, mr, c;

int main() {

    int D;
    cin >> D;
    while (D--) {

        cin >> tl >> tr >> ml >> mr >> c;

        vector<int> en_kotu_ihtimaller(mr+2+tr, 0);
        en_kotu_ihtimaller[0] = 1;
        en_kotu_ihtimaller[tr] = -1;

        for (int t = tl; t <= tr; t++) {
            for (int i = (c+1) % t; i <= mr; i += t) {
                if (c >= t) continue;
                en_kotu_ihtimaller[i]++;
                en_kotu_ihtimaller[i+t-c-1]--;
            }
        }

        for (int i = 1; i < en_kotu_ihtimaller.size(); i++)
            en_kotu_ihtimaller[i] += en_kotu_ihtimaller[i-1];

        for (int i = mr; i >= ml; i--) {
            if (en_kotu_ihtimaller[i] == 0) {
                cout << i << '\n';
                break;
            }
        }
    }
}