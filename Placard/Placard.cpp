// Placard.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct sAposta
{
	Cliente umCliente;
	int valorAposta;
	char jogo[100];
}Aposta;

typedef struct sModalidade
{
	char modalidade[30];
}Modalidade;
typedef struct sModalidades
{
	Modalidade modalidades[10];
}Modalidades;

typedef struct sCliente
{
	char nome[100];
	float saldo;
	int nrApostas[100];
}Cliente;
typedef struct sCLientes
{
	Cliente clientes[1000];
}Clientes;

void Carregamento(Cliente a, float carregamento)
{
	a.saldo += carregamento;
}


void SeparaParaArray(char* arrayMod[], char modalidades[], char carater[])
{

	int index = 0;

	char *modalidade = strtok(modalidades, carater);

	// Enquando exister o separador.
	while (modalidade != NULL)
	{
		arrayMod[index] = modalidade;
		index++;

		modalidade = strtok(NULL, carater);
	}

	// Será necessário que todos as posições do array não preenchidas seja NULL, para mais tarde usar como condição de paragem.
	for (int i = index; i < 10; i++)
	{
		arrayMod[i] = NULL;
	}
}

char* ImportaModalidades(char path[])
{
	char str[49];

	FILE *fp = fopen(path, "r");
	fgets(str, 49, fp);

	fclose(fp);

	return str;
}

int main()
{
	char str[255];
	strcpy(str, ImportaModalidades("C:\\Users\\Rafael\\Documents\\Visual Studio 2015\\Projects\\AED_TrabalhoPratico\\Debug\\mod.txt"));

	char *arrayModalidades[10];
	SeparaParaArray(arrayModalidades, str, ";");

	// Teste Pull GIT

	return 0;
}