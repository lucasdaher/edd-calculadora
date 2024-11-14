#include <stdio.h>
#include "expressao.h"

int main()
{
  Expressao expressoes[] = {
      {"6 3 * 4 +", "6 * 3 + 4", 22},
      {"10 3 4 * + 5 -", "10 + 3 * 4 - 5", 17},
      {"8 5 6 2 * + +", "8 + 5 + 6 * 2", 25},
      {"3 log 2 + 10 *", "(log 3 + 2) * 10", 20.47}, // corrigir problema
      {"45 2 + 60 cos *", "(45 + 2) * cos(60)", 23.5}};

  for (int i = 0; i < 5; i++)
  {
    float resultado = getValor(expressoes[i].posFixa);
    printf("Expressao %s\nResultado do pai - %.2f\nGabarito do marselo - %.2f\n\n",
           expressoes[i].posFixa, resultado, expressoes[i].Valor);
  }

  return 0;
}