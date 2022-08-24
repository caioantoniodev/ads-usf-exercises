#include <stdio.h>

/*
Enunciado:

Faça uma função na linguagem C que encontre o tempo de autonomia de uma bateria utilizando a seguinte fórmula:

T = (C x V) / P

Onde:

T = Tempo (h)
C = Capacidade (Ah)
P = Potência (W)
V = Tensão (V)

No programa principal, faça a coleta do usuário dos dados necessários, realize a chamada da função criada e mostre o resultado obtido.
*/

int calcAutonomyBattery(double capacity, double potency, double voltage) {
    return (int) capacity * voltage / potency;
}

void buildAutonomy(int autonomyBattery, int *ss, int *mm, int *hh) {
    (*ss) = autonomyBattery % 60;
    (*mm) = (autonomyBattery / 60) % 60;
    (*hh) = autonomyBattery / 60 / 60;
}

int main() {

    double capacity = 0, potency = 0, voltage = 0;

    printf("Enter the battery capacity: ");
    scanf("%lf", &capacity);

    printf("Enter the battery potency: ");
    scanf("%lf", &potency);

    printf("Enter the battery voltage: ");
    scanf("%lf", &voltage);

    int autonomyBattery = calcAutonomyBattery(capacity, potency, voltage);
    int ss;
    int mm;
    int hh;

    buildAutonomy(autonomyBattery, &ss, &mm, &hh);

    printf("%i:%i:%i\n", ss, mm, hh);

    return 0;
}


