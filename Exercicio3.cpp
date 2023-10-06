#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;


struct Produto {
    string codigo;
    string nome;
    double preco;
};


void inserirProduto(vector<Produto>& produtos) {
    if (produtos.size() >= 300) {
        cout << "Limite de produtos atingido." << endl;
        return;
    }

    Produto novoProduto;
    cout << "Digite o código do produto (13 caracteres): ";
    cin >> novoProduto.codigo;

    for (const Produto& p : produtos) {
        if (p.codigo == novoProduto.codigo) {
            cout << "Produto com o mesmo código já existe." << endl;
            return;
        }
    }

    cout << "Digite o nome do produto (até 20 caracteres): ";
    cin.ignore();
    getline(cin, novoProduto.nome);

    cout << "Digite o preço do produto (com duas casas decimais): ";
    cin >> novoProduto.preco;

    produtos.push_back(novoProduto);
    cout << "Produto cadastrado com sucesso." << endl;
}


void excluirProduto(vector<Produto>& produtos, const string& codigo) {
    for (size_t i = 0; i < produtos.size(); i++) {
        if (produtos[i].codigo == codigo) {
            produtos.erase(produtos.begin() + i);
            cout << "Produto excluído com sucesso." << endl;
            return;
        }
    }
    cout << "Produto não encontrado." << endl;
}


void listarProdutos(const vector<Produto>& produtos) {
    cout << "Lista de produtos:" << endl;
    for (const Produto& p : produtos) {
        cout << "Código: " << p.codigo << ", Nome: " << p.nome << ", Preço: R$" << fixed << setprecision(2) << p.preco << endl;
    }
}


void consultarPreco(const vector<Produto>& produtos, const string& codigo) {
    for (const Produto& p : produtos) {
        if (p.codigo == codigo) {
            cout << "O preço do produto " << p.nome << " é R$" << fixed << setprecision(2) << p.preco << endl;
            return;
        }
    }
    cout << "Produto não encontrado." << endl;
}

int main() {
    
    vector<Produto> produtos;

    while (true) {
        cout << "Escolha uma opção:" << endl;
        cout << "1. Inserir um novo produto" << endl;
        cout << "2. Excluir um produto cadastrado" << endl;
        cout << "3. Listar todos os produtos" << endl;
        cout << "4. Consultar o preço de um produto por código" << endl;
        cout << "5. Sair" << endl;

        int escolha;
        cin >> escolha;

        switch (escolha) {
            case 1:
                inserirProduto(produtos);
                break;
            case 2: {
                string codigo;
                cout << "Digite o código do produto a ser excluído: ";
                cin >> codigo;
                excluirProduto(produtos, codigo);
                break;
            }
            case 3:
                listarProdutos(produtos);
                break;
            case 4: {
                string codigo;
                cout << "Digite o código do produto para consulta: ";
                cin >> codigo;
                consultarPreco(produtos, codigo);
                break;
            }
            case 5:
                cout << "Saindo do programa." << endl;
                return 0;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    }

    return 0;
}
