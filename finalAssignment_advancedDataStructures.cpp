#include <iostream>
#include <vector>

using namespace std;

struct Node {
    string name;
    vector<Node*> neighbors;
    int inDegree;
    Node(string name) : name(name), inDegree(0) {}
};

using vn = vector<Node*>;

Node* addNode(string name, vn& g) {
    Node* node = new Node(name);
    g.push_back(node);
    return node;
}

void deleteNodes(vn& g) {
    for(Node* node : g) {
        delete node;
    }
}

void addEdge(Node* u, Node* v) {
    u->neighbors.push_back(v);
    v->inDegree++;
}

void printSolution(const vn& s) {
    for(const Node* node : s) {
        cout << node->name << "\n";
    }
}

void kahnsTopSort(vn& g, vn& s) { // Kahn's topological sorting algorithm
    for(Node* node : g) {
        if(!node->inDegree) {
            s.push_back(node);
        }
    }

    for(int i = 0; i < s.size(); ++i) {
        for(Node* neighbor : s[i]->neighbors) {
            if(!--(neighbor->inDegree)) {
                s.push_back(neighbor);
            }
        }
    }

    cout << "\n";
    if(s.size() == g.size()) {
        printSolution(s);
    } else {
        cout << "Error: the graph is not acyclic.\n";
    }
    cout << "\n";
}

int main() {
    vn graph, solution;

    Node* apa = addNode("Análise e Projeto de Algoritmos", graph);
    Node* apf = addNode("Algoritmos e Programação: Fundamentos", graph);
    Node* dihc = addNode("Design de Interação Humano-Computador", graph);
    Node* ead = addNode("Algoritmos e Programação: Estruturas Avançadas de Dados", graph);
    Node* ed = addNode("Algoritmos e Programação: Estruturas de Dados", graph);
    Node* esap = addNode("Engenharia de Software: Arquitetura e Padrões", graph);
    Node* esf = addNode("Engenharia de Software: Fundamentos", graph);
    Node* fbd = addNode("Fundamentos de Banco de Dados", graph);
    Node* mc = addNode("Matemática para Computação", graph);
    Node* oac = addNode("Organização e Arquitetura de Computadores", graph);
    Node* oo = addNode("Algoritmos e Programação: Orientação a Objetos", graph);
    Node* rl = addNode("Raciocínio Lógico", graph);
    Node* sd = addNode("Sistemas Digitais", graph);
    Node* sgbd = addNode("Sistemas de Gerência de Banco de Dados", graph);
    Node* soaa = addNode("Sistemas Operacionais: Análise e Aplicações", graph);
    Node* sof = addNode("Sistemas Operacionais: Fundamentos", graph);

    addEdge(apf, oo);
    addEdge(ed, apa);
    addEdge(ed, ead);
    addEdge(ed, sof);
    addEdge(esf, dihc);
    addEdge(esf, esap);
    addEdge(fbd, sgbd);
    addEdge(mc, apa);
    addEdge(oac, sof);
    addEdge(oo, ed);
    addEdge(oo, fbd);
    addEdge(rl, fbd);
    addEdge(rl, sd);
    addEdge(sd, oac);
    addEdge(sof, soaa);
    
    kahnsTopSort(graph, solution);

    deleteNodes(graph);

    return 0;
}