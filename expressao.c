#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "expressao.h"

// Não consegui utilizar este valor pela biblioteca math.h.
// Defini o M_PI com o mesmo valor que está sendo usado na biblioteca.
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define MAXIMO_PILHA 512

typedef struct
{
  float itens[MAXIMO_PILHA];
  int topo;
} Pilha;

typedef struct
{
  char itens[MAXIMO_PILHA][512];
  int topo;
} PilhaString;

void empilhar(Pilha *pilha, float valor)
{
  if (pilha->topo < MAXIMO_PILHA - 1)
  {
    pilha->itens[++pilha->topo] = valor;
  }
  else
  {
    perror("Erro encontrado: A pilha esta cheia.\n");
  }
}

float desempilhar(Pilha *pilha)
{
  if (pilha->topo >= 0)
  {
    return pilha->itens[pilha->topo--];
  }
  else
  {
    perror("Erro encontrado: A pilha esta vazia.\n");
    return 0;
  }
}

void empilharString(PilhaString *pilha, const char *valor)
{
  if (pilha->topo < MAXIMO_PILHA - 1)
  {
    strcpy(pilha->itens[++pilha->topo], valor);
  }
  else
  {
    perror("Erro encontrado: A pilha de string esta cheia.\n");
  }
}

char *desempilharString(PilhaString *pilha)
{
  if (pilha->topo >= 0)
  {
    return pilha->itens[pilha->topo--];
  }
  else
  {
    perror("Erro encontrado: A pilha de string esta vazia.\n");
    return NULL;
  }
}

int isOperador(char ch)
{
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int isFuncao(char *token)
{
  return (!strcmp(token, "sen") || !strcmp(token, "cos") || !strcmp(token, "tg") ||
          !strcmp(token, "log") || !strcmp(token, "raiz"));
}

float verificarOperador(char operador, float primeiroValor, float segundoValor)
{
  switch (operador)
  {
  case '+':
    return primeiroValor + segundoValor;
  case '-':
    return primeiroValor - segundoValor;
  case '*':
    return primeiroValor * segundoValor;
  case '/':
    return primeiroValor / segundoValor;
  case '^':
    return pow(primeiroValor, segundoValor);
  default:
    return 0;
  }
}

float verificarFuncao(char *operador, float numero)
{
  if (strcmp(operador, "sen") == 0)
    return sin(numero * M_PI / 180);
  if (strcmp(operador, "cos") == 0)
    return cos(numero * M_PI / 180);
  if (strcmp(operador, "tg") == 0)
    return tan(numero * M_PI / 180);
  if (strcmp(operador, "log") == 0)
    return log10(numero);
  if (strcmp(operador, "raiz") == 0)
    return sqrt(numero);
  return 0;
}

float getValor(char *str)
{
  Pilha pilha;
  pilha.topo = -1;
  char *token = strtok(str, " ");

  while (token != NULL)
  {
    if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
    {
      empilhar(&pilha, atof(token));
    }
    else if (isOperador(token[0]))
    {
      float b = desempilhar(&pilha);
      float a = desempilhar(&pilha);
      empilhar(&pilha, verificarOperador(token[0], a, b));
    }
    else if (isFuncao(token))
    {
      float numero = desempilhar(&pilha);
      empilhar(&pilha, verificarFuncao(token, numero));
    }
    token = strtok(NULL, " ");
  }
  return desempilhar(&pilha);
}

char *getFormaInFixa(char *str)
{
  PilhaString pilha;
  pilha.topo = -1;
  char *token = strtok(str, " ");
  static char resultado[512];

  while (token != NULL)
  {
    if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
    {
      empilharString(&pilha, token);
    }
    else if (isOperador(token[0]))
    {
      char b[512], a[512];
      strcpy(b, desempilharString(&pilha));
      strcpy(a, desempilharString(&pilha));
      sprintf(resultado, "(%s %s %s)", a, token, b);
      empilharString(&pilha, resultado);
    }
    else if (isFuncao(token))
    {
      char a[512];
      strcpy(a, desempilharString(&pilha));
      sprintf(resultado, "%s(%s)", token, a);
      empilharString(&pilha, resultado);
    }
    token = strtok(NULL, " ");
  }
  strcpy(resultado, desempilharString(&pilha));
  return resultado;
}
