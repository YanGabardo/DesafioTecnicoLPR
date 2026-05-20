#include <iostream>
#include <string>
using namespace std;

//calcular pontuacao
int calcularPontuacao(int criticidade, int pacientes, int tempo, int energia) {
    return (criticidade * 3) + (pacientes * 2) + (tempo * 2) - energia;
}

//exibir alertas
void verificarAlertas(int criticidade, int pacientes, int tempo, int energia) {
    if (tempo > 80 && criticidade > 70) {
        cout << " ALerta:Risco de falha iminente" << endl;
    }
    if (energia > 90) {
        cout << " Alerta:Sobrecarga de energia" << endl;
    }
    if (pacientes > 15 && criticidade > 85) {
        cout << " Alerta:Prioridade absoluta" << endl;
    }
}

int main() {

    //3 equipamentos
    string nomes[3]    = {"Ventilador Pulmonar", "Monitor Multiparametrico", "Bomba de Infusao"};
    int criticidade[3] = {95, 75, 60};
    int energia[3]     = {85, 95, 40};
    int tempo[3]       = {90, 60, 30};
    int pacientes[3]   = {18, 12, 8};

    int pontuacoes[3];

    //calcular pontuacoes
    for (int i = 0; i < 3; i++) {
        pontuacoes[i] = calcularPontuacao(criticidade[i], pacientes[i], tempo[i], energia[i]);
    }

    //exibir dados e alertas
    cout << "CENTRAL HOSPITALAR - UTI" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "\nEquipamento: " << nomes[i] << endl;
        cout << "  Pontuacao: " << pontuacoes[i] << endl;
        verificarAlertas(criticidade[i], pacientes[i], tempo[i], energia[i]);
    }

    //encontrar maior e menor pontuacao
    int idxMaior = 0;
    int idxMenor = 0;

    for (int i = 1; i < 3; i++) {
        if (pontuacoes[i] > pontuacoes[idxMaior]) idxMaior = i;
        if (pontuacoes[i] < pontuacoes[idxMenor]) idxMenor = i;
    }

    //encontrar o intermediario
    int idxMedio = 0;
    for (int i = 0; i < 3; i++) {
        if (i != idxMaior && i != idxMenor) idxMedio = i;
    }

    //resultado final
    cout << "DECISAO FINAL " << endl;
    cout << "Manutencao imediata : " << nomes[idxMaior] << " (" << pontuacoes[idxMaior] << " pts)" << endl;
    cout << "Continua operando   : " << nomes[idxMedio] << " (" << pontuacoes[idxMedio] << " pts)" << endl;
    cout << "Menor prioridade    : " << nomes[idxMenor] << " (" << pontuacoes[idxMenor] << " pts)" << endl;

    return 0;
}
