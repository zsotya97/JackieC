#include "Fuggvenyek.h"
int main()
{
	setlocale(LC_ALL, "");
	FILE* beolvas;
	Adatok* lista, * elso;
	beolvas = fopen("jackie.txt", "r");
	char szoveg[51];
	lista = (Adatok*)malloc(sizeof(Adatok));
	fgets(szoveg, sizeof(szoveg), beolvas);
	Jackie temp;
	fscanf(beolvas, "%d\t%d\t%d\t%d\t%d\t%d", &temp.year, &temp.races, &temp.wins, &temp.podium, &temp.poles, &temp.fastests);
	lista = add(lista, temp);
	elso = lista;
	int szamlalo = 1;
	while (fscanf(beolvas, "%d\t%d\t%d\t%d\t%d\t%d", &temp.year, &temp.races, &temp.wins, &temp.podium, &temp.poles, &temp.fastests)!=EOF)
	{
		lista = add(lista, temp);
		szamlalo++;
	}
	Jackie* adatok = (Adatok*)malloc(szamlalo * sizeof(Jackie));
	Adatok* elem;
	int i = 0;
	for (elem = elso; elem != NULL; elem = elem->kov)
	{

		adatok[i] = elem->adat;
		i++;
	}
	torles(elso);
	fclose(beolvas);
	printf("3. feladat: %d\n", szamlalo);

	Jackie max = adatok[0];
	for (size_t i = 0; i < szamlalo; i++)
	{
		if (adatok[i].races > max.races)max = adatok[i];
	}

	printf("4. feladat: %d\n", max.year);
	int evtizedek[9][2], evtized = 9, kezdo = 1900;
	for (size_t i = 0; i < evtized; i++)
	{
		int ev = kezdo + ((i + 1) * 10), szamolas = 0;
		for (size_t j = 0; j < szamlalo; j++)
		{

			if (adatok[j].year >= ev && (ev + 9) >= adatok[j].year)szamolas += adatok[j].wins;

		}
		evtizedek[i][0] = ev - kezdo;
		evtizedek[i][1] = szamolas;
	}
	puts("5. feladat:");
	for (int i = 8; i >= 0; i--)
	{
		if (evtizedek[i][1] > 0)printf("\t%d-es évek: %d megnyert verseny\n", evtizedek[i][0], evtizedek[i][1]);
	}
	FILE* kiiras;
	for (size_t i = 0; i < szamlalo; i++)
	{
		for (size_t j = 0; j < szamlalo - i - 1; j++)
		{
			if (adatok[j].year < adatok[j + 1].year)
			{
				Jackie csere;
				csere = adatok[j + 1];
				adatok[j + 1] = adatok[j];
				adatok[j] = csere;
			}

		}
	}
	puts("6. feladat: jackie.html");
	kiiras = fopen("jackie.html", "w");
	fputs("<!DOCTYPE html>", kiiras);
	fputs("<html lang='en'>", kiiras);
	fputs("<meta charset='UTF-8'>", kiiras);
	fputs("<meta http-equiv='X-UA-Compatible' content='IE=edge'>", kiiras);
	fputs("<meta name='viewport' content='width=device-width, initial-scale=1.0'>", kiiras);
	fputs("<title>Jackie Stewart<\title>", kiiras);
	fputs("<style>\ntable, tr, td{ border: 1px solid black; }\n</style>", kiiras);
	fputs("</head><body>", kiiras);
	fputs("<h1>Jackie Stewart</h1>", kiiras);
	fputs("<table>", kiiras);
	for (size_t i = 0; i < szamlalo; i++)
		fprintf(kiiras, "<tr>\n<td>%d<\td>\n<td>%d<\td>\n<td>%d<\td>\n<\tr>\n", adatok[i].year, adatok[i].races, adatok[i].wins);
	fputs("<\table>", kiiras);
	fputs("</body></html>", kiiras);
	fclose(kiiras);
	getch();
}