#include <bits/stdc++.h>

using namespace std;

int main(){
  vector<pair<int, int> > materias(8);
  materias[0] = make_pair(3, 5);
  materias[1] = make_pair(6, 6);
  materias[2] = make_pair(9, 5);
  materias[3] = make_pair(8, 6);
  materias[4] = make_pair(5, 3);
  materias[5] = make_pair(4, 4);
  materias[6] = make_pair(3, 2);
  materias[7] = make_pair(4, 4);

  vector<vector<int> > escolhas(8, vector<int>(17));

for (int i = 0; i < escolhas.size(); i++) {
    for (int j = 0; j < escolhas[i].size(); j++) {
        int antigo = 0, novo = 0;
        int peso = materias[i].first;
        int valor = materias[i].second;
        if(i == 0){
            if(j - peso >= 0) escolhas[i][j] = valor;
        }else{
            antigo = escolhas[i - 1][j];
            if(j - peso >= 0){
                novo = valor + escolhas[i - 1][j - peso];
            }
            escolhas[i][j] = max(antigo, novo);
        }
    }
}

for (int i = 0; i < escolhas.size(); i++) {
    for (int j = 0; j < escolhas[i].size(); j++) {
        cout << escolhas[i][j] << " ";
    }
    cout << endl;
  }
}
