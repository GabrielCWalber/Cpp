// Analisando Jogos de Civilizações Antigas

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> placa;
typedef placa* lista;
typedef vector<int> vetor;
#define soma first
#define diferenca second

// tamanho do input
int n;

// arquivo de input
ifstream entrada("test_cases/in");

// branch and bound
bool bnb(int n, int valor, int objetivo, lista &placas){
    if(valor == objetivo) return true; // se atingiu o objetivo
    if((valor > objetivo)) return false; // se ultrapassou o objetivo
    if(n > 0){
        if(bnb(n-1, valor+placas[n].diferenca, objetivo, placas)) return true; // somando diferença
        if(bnb(n-1, valor, objetivo, placas)) return true; // sem somar diferença
    }
    return false; // se tudo falhar
}

// inicia o branch and bound
bool testar(int somaDasDiferencas, lista &placas){
    int objetivo = somaDasDiferencas >> 1; // divide por 2
    return bnb(n-1, 0, objetivo, placas);
}

// testa possibilidades removendo placas
placa remocao(bool paridade, int somaDasDiferencas, lista &placas){
    vetor somas;

    // armazena os índices das placas da paridade desejada no vetor
    for(int i = 0; i < n; i++){
        if(placas[i].soma & 1 == paridade){
            somas.push_back(i);
        }
    }

    // ordena o vetor por soma
    sort(somas.begin(), somas.end(), [&placas](const int &a, const int &b) {
        return placas[a].soma < placas[b].soma;
    });

    // realiza tesstes com remoção das placas
    for (int i = 0; i < somas.size(); i++){
        placa placaRemovida = placas[somas[i]];
        int valorRemovido = placaRemovida.diferenca;
        placaRemovida.diferenca = 0;
        if(testar(somaDasDiferencas-valorRemovido, placas)){
            placaRemovida.diferenca = valorRemovido;
            return placaRemovida;
        }
        placaRemovida.diferenca = valorRemovido;
    }
    return placa{-1, -1};
}

void algoritmo(){
    int somaTotal = 0;
    int somaDasDiferencas = 0;
    lista placas = new placa[n];

    // armazena os valores da soma e diferença dos dois números de cada placa
    for(int i = 0; i < n; i++){
        int a, b;
        entrada >> a >> b;
        placas[i].soma = a + b;
        placas[i].diferenca = abs(a - b);
        somaTotal += placas[i].soma;
        somaDasDiferencas += placas[i].diferenca;
    }

    // ordena as placas por diferença em ordem crescente
    sort(placas, placas + n, [](const placa &a, const placa &b) {
        return a.diferenca < b.diferenca;
    });

    bool paridade = somaDasDiferencas & 1; // resulta em 0 se for par, 1 se for impar

    if(paridade == 0){
        if(testar(somaDasDiferencas, placas)){ // testa sem remoção
            cout << (somaTotal >> 1) << " nenhuma placa descartada\n";
            return;
        }
    }
    
    placa retorno = remocao(paridade, somaDasDiferencas, placas);

    if(retorno.soma == -1 && retorno.diferenca == -1){
        cout << "impossível\n";
    }else{
        somaTotal -= retorno.soma; // nova soma, sem a placa removida
        somaTotal = somaTotal >> 1; // soma considerando apenas um dos lados de cada placa

        // calcula os valores originais da placa a partir da soma e da diferença
        int a = (retorno.soma - retorno.diferenca) >> 1;
        int b = (retorno.soma + retorno.diferenca) >> 1;

        cout << somaTotal << " descartada a placa " << a << " " << b << "\n";
    }

}

int main(){
    if(!entrada){
        cerr << "Arquivo de entrada não encontrado.\n";
        return 1;
    }

    entrada >> n; // lê o tamanho da entrada

    // enquanto não ler 0, repete o algoritmo
    while(n > 0){
        algoritmo();
        entrada >> n; // recebe o tamanho da prócima parte da entrada
    }

    entrada.close();

    return 0;
}