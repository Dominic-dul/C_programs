//Program counts, how many integers squares there are in the provided array, which ends in 0;
#include <stdio.h>

int main() {
    int kiekKvadratu = 0, i, skaicius;
    char simbolis;

	printf ("Iveskite sveikuju skaiciu seka, kuri baigiasi 0: \n");

    do{
        printf("Skaicius:\n");
        while ((scanf("%d%c", &skaicius, &simbolis)) == 0 || simbolis != '\n')
        {
            scanf("%*[^\n]");
            printf("Jus ivedete ne sveikaji skaiciu arba ivede nepaspaudete ENTER. Veskite is naujo:\n");
        }

		if (skaicius == 1) 
		{
			kiekKvadratu++;
			continue;
		}
		
        for (i = 1; i <= skaicius/2; ++i)
            if(i*i == skaicius)
            {
                kiekKvadratu++;
				break;
            }

    }while (skaicius != 0);

    printf ("Sekoje esanciu skaiciu, kurie yra kito skaiciaus kvadratai, yra %d", kiekKvadratu);
    return 0;
}
