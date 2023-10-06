#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Passagem {

    int assento;
    bool viagem;

    int dia;
    int mes;
    int hora;

    string nome;
    string cpf;
    int idade;
};


int main(){

    vector<Passagem> passagens;
    Passagem novaPassagem;
    char viagem='I';
    char continuar='N';
    int op;

    do{
        cout << "------------- VENDAS DE PASSAGENS --------------------" << endl;
        cout << "Digite o nome do passageiro: " << endl;
        getline(cin >> ws, novaPassagem.nome);
        cout << "Digite a idade do passageiro: " << endl;
        cin >> novaPassagem.idade;
        cout << "Digite o CPF do passageiro: " << endl;
        getline(cin >> ws, novaPassagem.cpf);
        cout << "Digite o dia da viagem: " << endl;
        cin >> novaPassagem.dia;
        cout << "Digite o mes da viagem: " << endl;
        cin >> novaPassagem.mes;
        cout << "Digite o horário da viagem: (8- 8h | 10- 10h | 13- 13h | 15- 15h | 20- 20h)" << endl;
        cin >> novaPassagem.hora;
        cout << "Passagem de ida ou volta? (I - Ida / V - Volta): " << endl;
        cin >> viagem;
        if (viagem == 'I' || viagem == 'i'){
            novaPassagem.viagem = true;
        }
        else if (viagem == 'V' || viagem == 'v'){
            novaPassagem.viagem = false;
        }

        cout << "Digite o numero do assento do passageiro " << novaPassagem.nome << endl;
        cin >> novaPassagem.assento;

        passagens.push_back(novaPassagem);
        novaPassagem = {};

        cout << "Desejar continuar emitindo passagens? (S - sim / N - nao) " << endl;
        cin >> continuar;
    } while (continuar=='S' || continuar=='s');

    cout  << "---------- RELATORIOS ----------" << endl;
    cout << "Digite" << endl;
    cout << "1. Total arrecadado para uma determinada viagem" << endl;
    cout << "2. Total arrecadado para uma determinado mes" << endl;
    cout << "3. Nome do passageiro em uma determinada poltrona P de uma determinada viagem" << endl;
    cout << "4. Qual o horario de viagem mais rentavel" << endl;
    cout << "5. Qual a media de idade dos passageiros" << endl;
    cin >> op;

    switch (op) {
        
        case 3:
            int poltrona;
            cout << "Digite o numero de uma poltrona: " << poltrona << endl;
            cin >> poltrona;
            for (const Passagem& p : passagens) {
                if (p.assento == poltrona) {
                    cout << "Nome do passageiro: " << p.nome << endl;
                }
            }

        case 5:
            double mediaIdade;
            double somatorioIdade=0;
            for(const Passagem& p : passagens){
                somatorioIdade += p.idade;
            }

            mediaIdade = somatorioIdade / passagens.size();
            cout << "Media da idade dos passageiros: " << mediaIdade << endl;
            break;
        
        }

    return 0;
}