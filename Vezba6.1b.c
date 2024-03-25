// Vezba6.1b.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Upis artikala u artikli.txt fajl
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	char marka[20], model[20];
	float cena;
	int n, i;
	printf("Unesi broj artikala:");
	scanf("%d", &n);
	FILE* f = fopen("artikli.txt", "w");
	if (f == NULL)
	{
		printf("Greska pri otvaranju datoteke");
		return 1;
	}
	for (i = 0; i < n; i++)
	{
		puts("Unesi marku:");
		getchar();
		gets(marka); // preskace
		puts("Unesi model:");
		gets(model);
		puts("Unesi cenu:");
		scanf("%f", &cena);
		// upis u fajl
		fprintf(f, "%s\n%s\n%.2f\n",
			marka, model, cena);
	}
	fclose(f);
	f= fopen("artikli.txt", "r");
	if (f == NULL)
	{
		printf("Greska pri otvaranju datoteke");
		return 1;
	}
	for (i = 0; i < n; i++)
	{
		fgets(marka, 20, f);
		fgets(model, 20, f);
		fscanf(f, "%f", &cena);
		printf("Marka: %s\nModel: %s\nCena: %.2f\n",
						marka, model, cena);
	}
}
