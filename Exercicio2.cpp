#include <iostream>
#include <string>

using namespace std;

// Definição da estrutura Empregado
struct Empregado {
    string nome;
    string sobrenome;
    int anoNascimento;
    string RG;
    int anoAdmissao;
    double salario;
};


void Reajusta_dez_porcento(Empregado *empregados, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        empregados[i].salario *= 1.10; 
    }
}

int main() {
    const int maxEmpregados = 50;
    Empregado empregados[maxEmpregados];

   
    empregados[0] = {"João", "Silva", 1985, "12345678", 2010, 3000.0};
    empregados[1] = {"Maria", "Santos", 1990, "87654321", 2015, 3500.0};
    

    int numEmpregados = 2; 

    
    cout << "Salários antes do reajuste:" << endl;
    for (int i = 0; i < numEmpregados; i++) {
        cout << empregados[i].nome << " " << empregados[i].sobrenome << ": R$" << empregados[i].salario << endl;
    }

    // Chamando a função para reajustar salários
    Reajusta_dez_porcento(empregados, numEmpregados);

    // Imprimindo salários após o reajuste
    cout << "\nSalários após o reajuste de 10%:" << endl;
    for (int i = 0; i < numEmpregados; i++) {
        cout << empregados[i].nome << " " << empregados[i].sobrenome << ": R$" << empregados[i].salario << endl;
    }

    return 0;
}
