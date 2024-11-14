#include <stdio.h>
#include "expressao.h"

int main()
{
  printf("-------------------------------------------------------------\n");
  printf("TESTES DO PROFESSOR: \n");
  printf("-------------------------------------------------------------\n\n");

  Expressao expressoes[] = {
      {"3 4 + 5 *", "(3 + 4) * 5", 35},
      {"7 2 * 4 +", "7 * 2 + 4", 18},
      {"8 5 2 4 + * +", "8 + 5 * (2 + 4)", 38},
      {"6 2 / 3 + 4 *", "(6 / 2 + 3) * 4", 24},
      {"9 5 2 8 * 4 + * +", "9 + 5 * (2 + 8 * 4)", 109},
      {"2 3 + log 5 /", "log(2 + 3) / 5", 0.14},
      {"10 log 3 ^ 2 +", "(log 10)^3 + 2", 3},
      {"45 60 + 30 cos *", "(45 + 60) * cos(30)", 90.93},
      {"0.5 45 sen 2 ^ +", "sen(45)^2 + 0.5", 1}};

  for (int i = 0; i < 9; i++)
  {
    float resultado = getValor(expressoes[i].posFixa);
    printf("Expressao %s\nResultado - %.2f\nGabarito - %.2f\n\n",
           expressoes[i].posFixa, resultado, expressoes[i].Valor);
  }

  printf("-------------------------------------------------------------\n");
  printf("TESTES REALIZADOS PELO GRUPO: \n");
  printf("-------------------------------------------------------------\n\n");

  Expressao testesDoGrupo[] = {
      {"6 3 * 4 +", "6 * 3 + 4", 22},
      {"10 3 4 * + 5 -", "10 + 3 * 4 - 5", 17},
      {"8 5 6 2 * + +", "8 + 5 + 6 * 2", 25},
      {"3 log 2 + 10 *", "(log 3 + 2) * 10", 24.77},
      {"45 2 + 60 cos *", "(45 + 2) * cos(60)", 23.5}};

  for (int i = 0; i < 5; i++)
  {
    float resultado = getValor(testesDoGrupo[i].posFixa);
    printf("Expressao %s\nResultado - %.2f\nGabarito - %.2f\n\n",
           testesDoGrupo[i].posFixa, resultado, testesDoGrupo[i].Valor);
  }

  return 0;
}