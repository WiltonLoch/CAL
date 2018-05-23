#include <bits/stdc++.h>

// > 1 0
// \/ 0 1
// < -1 0
// /\ 0 -1

using namespace std;

void enfileirarMovimentos(vector<vector<int> > tab, int mov, queue< pair< vector<vector<int> > , int> > &fila_tabuleiros);
bool testaFim(vector< vector<int> > &tab);
void mostrar(vector< vector<int> > &tab);
int gerarCodigo(vector< vector<int> > &tab);
void realizarMovimento(int movX, int movY, vector< vector<int> > &tab, bool desfazer = false);
bool trocar(int i, int j, int movX, int movY, vector<vector<int> > &tab);

int main(){
    vector< vector<int> > tab(3, vector<int>(3));
    queue<pair<vector<vector<int> >, int > > fila_tabuleiros;
    map<int, bool> visitados;
    int menor = 123456789;
    for (size_t i = 0; i < tab.size(); i++) {
        for (size_t j = 0; j < tab[i].size(); j++) {
        cin >> tab[i][j];
        }
    }



    enfileirarMovimentos(tab, 1, fila_tabuleiros);
    visitados[gerarCodigo(tab)] = true;

    while(!fila_tabuleiros.empty()){
        if(!testaFim(fila_tabuleiros.front().first)){
            if(visitados[gerarCodigo(fila_tabuleiros.front().first)] != true){
                visitados[gerarCodigo(fila_tabuleiros.front().first)] = true;
                enfileirarMovimentos(fila_tabuleiros.front().first, fila_tabuleiros.front().second + 1, fila_tabuleiros);
            }
        }else{
            menor = fila_tabuleiros.front().second;
            break;
        }
        fila_tabuleiros.pop();
    }
    cout << menor << endl;

}

void enfileirarMovimentos(vector<vector<int> > tab, int mov, queue< pair< vector<vector<int> > , int> > &fila_tabuleiros){
    for (size_t i = 0; i < tab.size(); i++) {
        for (size_t j = 0; j < tab[i].size(); j++) {
            if(tab[i][j] == 0){
                    if(trocar(i, j, 0, 1, tab)){
                        fila_tabuleiros.push(make_pair(tab, mov));
                        trocar(i + 1, j, 0, -1, tab);
                    }
                    if(trocar(i, j, 0, -1, tab)){
                        fila_tabuleiros.push(make_pair(tab, mov));
                        trocar(i - 1, j, 0, 1, tab);
                    }
                    if(trocar(i, j, 1, 0, tab)){
                        fila_tabuleiros.push(make_pair(tab, mov));
                        trocar(i, j + 1, -1, 0, tab);
                    }
                    if(trocar(i, j, -1, 0, tab)){
                        fila_tabuleiros.push(make_pair(tab, mov));
                    }
                return;
            }
        }
    }
}

bool trocar(int i, int j, int movX, int movY, vector<vector<int> > &tab){
    if(i + movY >= 0 && i + movY <= 2 && j + movX >= 0 && j + movX <= 2){
        int aux = tab[i + movY][j + movX];
        tab[i + movY][j + movX] = tab[i][j];
        tab[i][j] = aux;
        return true;
    }
    return false;
}

bool testaFim(vector< vector<int> > &tab){
    bool fim  = true;
    if(tab[2][2] != 0) return false;
    for (size_t i = 0; i < tab.size(); i++) {
        for (size_t j = 0; j < tab[i].size(); j++) {
            if(j < 2 || i < 2){
                if((unsigned)tab[i][j] != (i * 3 + j + 1)) fim = false;
            }
        }
    }
    return fim;
}

void mostrar(vector< vector<int> > &tab){
    for (size_t i = 0; i < tab.size(); i++) {
        for (size_t j = 0; j < tab[i].size(); j++) {
            cout << tab[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int gerarCodigo(vector< vector<int> > &tab){
    int sum = 0;
   for(int i = 0; i < 3; i ++){
       for(int x = 0; x < 3; x++){
           sum += tab[i][x] * pow(9, (i * 3) + x);
       }
   }
   return sum;
}
