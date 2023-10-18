#include <iostream>

class Data {
public:
    // Construtor padrão
    Data() : dia(1), mes(1), ano(2000) {}

    // Construtor sobrecarregado
    Data(int novoDia, int novoMes, int novoAno) : dia(novoDia), mes(novoMes), ano(novoAno) {}

    // Método para configurar a data
    void setData(int novoDia, int novoMes, int novoAno) {
        dia = novoDia;
        mes = novoMes;
        ano = novoAno;
    }

    // Método para obter a data atual
    void getData(int& outDia, int& outMes, int& outAno) {
        outDia = dia;
        outMes = mes;
        outAno = ano;
    }

    // Método para avançar para o próximo dia
    void avancarDia() {
        dia++;
        if (dia > diasNoMes(mes, ano)) {
            dia = 1;
            mes++;
            if (mes > 12) {
                mes = 1;
                ano++;
            }
        }
    }

    // Método para voltar para o dia anterior
    void diaAnterior() {
        dia--;
        if (dia < 1) {
            mes--;
            if (mes < 1) {
                mes = 12;
                ano--;
            }
            dia = diasNoMes(mes, ano);
        }
    }

    // Destrutor
    ~Data() {
        // Nenhuma ação necessária no destrutor neste exemplo simples
    }

private:
    int dia;
    int mes;
    int ano;

    // Função auxiliar para determinar quantos dias há em um mês
    int diasNoMes(int mes, int ano) {
        int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // Verificar se é um ano bissexto (fevereiro tem 29 dias)
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
            diasPorMes[2] = 29;
        }

        return diasPorMes[mes];
    }
};

int main() {
    Data data;
    int dia, mes, ano;

    data.setData(30, 10, 2023);
    data.getData(dia, mes, ano);
    std::cout << "Data atual: " << dia << "/" << mes << "/" << ano << std::endl;

    data.avancarDia();
    data.getData(dia, mes, ano);
    std::cout << "Data avançada para o próximo dia: " << dia << "/" << mes << "/" << ano << std::endl;

    data.diaAnterior();
    data.getData(dia, mes, ano);
    std::cout << "Data voltada para o dia anterior: " << dia << "/" << mes << "/" << ano << std::endl;

    return 0;
}

