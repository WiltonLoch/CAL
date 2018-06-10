#include <bits/stdc++.h>

using namespace std;

int main(){

    string genoma = "ABAZDC";
    string feature = "BACBAD";

    vector<vector<int> > escolhas(feature.length() + 1, vector<int>(genoma.length() + 1));

    for (size_t i = 0; i < genoma.length(); i++) {
        if(i < feature.length()) escolhas[i][0] = 0;
        escolhas[0][i] = 0;
    }

    for (size_t i = 1; i < escolhas.size(); i++) {
        for (size_t j = 1; j < escolhas[i].size(); j++) {
            escolhas[i][j] = max(escolhas[i - 1][j], escolhas[i][j - 1]);
            if(genoma[j - 1] == feature[i - 1]){
                escolhas[i][j] = max(escolhas[i][j], escolhas[i - 1][j - 1] + 1);
            }
        }
    }

    for (size_t i = 0; i < escolhas.size(); i++) {
        for (size_t j = 0; j < escolhas[i].size(); j++) {
            cout << escolhas[i][j] << " ";
        }
        cout << endl;
      }
}
