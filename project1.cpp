#include <iostream>
#include <string>

#define N 1000
int nC = 0;
int nF = 0;

int posC=0;
int posF=0;

using namespace std;

struct cliente {
    int id;
    string nome;
    int tel;
};

struct filme {
    int cod;
    string titulo;
    string genero;
    int ano;
    int idCliente;
};

void menu(){
    cout << "\n8====== MENU DE OPCOES ======>\n"
         << "1 - Para cadastrar clientes.\n"
         << "2 - Para cadastrar filmes.\n"
         << "3 - Para listar clientes.\n"
         << "4 - Para listar filmes.\n"
         << "5 - Para buscar filmes por cliente.\n"
         << "6 - Para gerar relatório geral.\n"
         << "0 - Para sair.\n"
         << "Digite sua opcao: ";
}

void cadastrarCliente(cliente *c){
    cout << "\nDigite o id do cliente: ";
    cin >> c->id;
    cout << "Digite o nome do cliente: ";
    cin.ignore();
    getline(cin, c->nome);
    cout << "Digite o telefone do cliente: ";
    cin >> c->tel;
}

void cadastrarFilme(filme *f, cliente vet[], int nC){
    cout << "\nDigite o codigo do filme: ";
    cin >> f->cod;
    cout << "Digite o titulo do filme: ";
    cin.ignore();
    getline(cin, f->titulo);
    cout << "Digite o genero do filme: ";
    getline(cin, f->genero);
    cout << "Digite o ano do filme: ";
    cin >> f->ano;
    cout << "Digite o id do cliente que alugou: ";
    cin >> f->idCliente;
}

void listarCliente(cliente vet[]) {
    for (int i=0; i<posC; i++){
        cout << "\nCliente num: " << i+1 << endl
             << "Id: " << vet[i].id << endl
             << "Nome: " << vet[i].nome << endl
             << "Telefone: " << vet[i].tel << endl;
    }
}

void listarFilme(filme vet[]) {
    for (int i=0; i<posF; i++){
        cout << "\nFilme num: " << i+1 << endl
             << "Codigo: " << vet[i].cod << endl
             << "Titulo: " << vet[i].titulo << endl
             << "Genero: " << vet[i].genero << endl
             << "Ano: " << vet[i].ano << endl
             << "Cliente que alugou: " << vet[i].idCliente << endl;
    }
}

void juntarClientes(cliente vet[], cliente c) {
    if (posC < N) {
        vet[posC++] = c;
        nC++;
    }
    else
        cout << "Cliente demais.";
}

void juntarFilmes(filme vet[], filme f) {
    if (posF < N){
        vet[posF++] = f;
        nF++;
    }
    else
        cout << "Cliente demais.";
}

void filmesCliente(filme vet[], int idBusca) {
    cout << "\nInsira o ID do cliente para a busca: ";
    cin >> idBusca;
    cout << endl << "Filmes alugados:\n";
    int cont = 0;
    for (int i=0; i<nF; i++){
        int id = vet[i].idCliente;
        if (id == idBusca){
            cout << vet[i].titulo << endl;
            cont++;
        }
    }
    if (cont==0){
        cout << "Nao ha filmes alugados.\n";
    }
}

void relatorio(cliente vetC[], filme vetF[]) {
    cout << "\nRelatorio...\n";
    int vetCF[nC];
    for (int i=0; i<nC; i++){
        int idC = vetC[i].id;
        int cont=0;
        for (int j=0; j<nF; j++){
            int idF = vetF[j].idCliente;
            if (idC == idF){
                cont++;
            }
        vetCF[i] = cont;
        }
    cout << "O cliente " << vetC[i].nome << " alugou " << cont << " filmes\n";
    }
}

int main(){
    cliente client;
    cliente clientes[N];

    filme film;
    filme filmes[N];
    int opcao;
    int idBusca;

    menu();
    cin >> opcao;
    while (opcao != 0) {
        switch (opcao) {
            case 1:
                cadastrarCliente(&client);
                juntarClientes(clientes, client);
                break;
            case 2:
                cadastrarFilme(&film);
                juntarFilmes(filmes, film);
                break;
            case 3:
                listarCliente(clientes);
                break;
            case 4:
                listarFilme(filmes);
                break;
            case 5:
                filmesCliente(filmes, idBusca);
                break;
            case 6:
                relatorio(clientes, filmes);
                break;
            default:
                cout << "Opcao invalida, Digite novamente...\n";
                break;
        }
    menu();
    cin >> opcao;
    }

    return 69;
}
