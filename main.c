#include <stdio.h>
#include "expressao.h"

int main()
{
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
    printf("Expressao %s\nResultado do pai - %.2f\nGabarito do marselo - %.2f\n\n",
           expressoes[i].posFixa, resultado, expressoes[i].Valor);
  }

  return 0;
}