//Programs asks for n intervals. Then it asks to enter an integer number and it prints all the intervals which include the given integer number.
#include <stdio.h>
#include <stdlib.h>


int Didesnis (int a, int b)
{
    if (abs(a) > abs(b)) return abs(a);
    else return abs(b);
}
int Mazesnis (int a, int b)
{
    if (abs(a) < abs(b)) return abs(a);
    else return abs(b);
}
 int main()
 {
     int n, g, Intervalai[1000][2], intervalo_pradzia, intervalo_pabaiga, kiek = 0;
     char tarpas;

     printf("Iveskite sveikaji skaiciu n, kuris rodo, kiek bus ivesta skaiciu poru: \n");

     while (scanf("%d%c", &n, &tarpas) == 0 || tarpas != '\n')
     {
		 	scanf("%*[^\n]");
            printf ("Ivestis neteisinga. Veskite is naujo:\n");
     }


     printf ("Iveskite %d skaiciu poras(-a) a ir b \n", n);

     for (int i = 0; i < n; ++i)
     {
         scanf ("%d%d", &Intervalai[i][0], &Intervalai[i][1]);
     }

     printf ("Iveskite sveikaji skaiciu g \n");

     while (scanf("%d%c", &g, &tarpas) == 0 || tarpas != '\n')
     {
         scanf("%*[^\n]");
         printf ("Ivestis neteisinga. Veskite is naujo\n");
     }

     for (int i = 0; i < n; ++i)
     {
         intervalo_pradzia = Mazesnis(Intervalai[i][0], Intervalai[i][1]);
         intervalo_pabaiga = Didesnis(Intervalai[i][0], Intervalai[i][1]);

         if (g >= intervalo_pradzia && g <= intervalo_pabaiga)
         {
             printf ("%d %d\n", intervalo_pradzia, intervalo_pabaiga);
             kiek++;
         }
     }

     printf ("Is viso tokiu intervalu yra: %d\n", kiek);

    return 0;
 }
