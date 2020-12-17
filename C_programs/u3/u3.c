//Program pirnts all the words from the file, whose 2nd from the beginning and 3 from the ending letters are the same
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 256

bool ArTinka(char *zodis, int size)
{
    if (size >= 3)
    {
        if (*(zodis+1) == *(zodis+size-3))
        {
            return true;
        }
        else return false;
    }
    else return false;
}
void ZodziuAtrinkimas (char *zodis, int *eilutesDydis, char **tinkamiZodziai, int *irasymoPozicija)
{
        if (ArTinka(zodis, strlen(zodis)))
        {
            *eilutesDydis += strlen(zodis);
            *tinkamiZodziai = (char*)realloc(*tinkamiZodziai, (*eilutesDydis)*sizeof(char));
            if (*tinkamiZodziai == NULL)
                {
                    printf ("Ivyko klaida irasant zodzius(-i)\n");
                    exit(1);
                }
            else
                {
                    strcpy(zodis+strlen(zodis), " ");
                    strcpy(*tinkamiZodziai+*irasymoPozicija, zodis);
                    *irasymoPozicija += strlen(zodis);
                }

        }
		else return;
}
char* failuVardai()
{
    char *failoPavadinimas;
    failoPavadinimas = (char*)malloc(MAX_SIZE*sizeof(char));

    scanf ("%s", failoPavadinimas);
	
    if (failoPavadinimas == NULL)
    {
        printf ("Ivyko klaida dirbant su failu");
        exit(1);
    }

    return failoPavadinimas;
}
int main (int argc, char*argv[]){

    int eilutesDydis = 0, irasymoPozicija = 0;
    char *pradiniaiZodziai, *zodis, *tinkamiZodziai = NULL, *duomPavadinimas, *rezPavadinimas;

    printf("Iveskite ivesties failo pavadinima:\n");
    duomPavadinimas = failuVardai();

    printf ("Iveskite isvesites failo pavadinima:\n");
    rezPavadinimas = failuVardai();

    FILE *fPointerSkaitymas = fopen (duomPavadinimas, "r");
    FILE *fPointerRasymas = fopen (rezPavadinimas, "w");

    if (fPointerSkaitymas == NULL || fPointerRasymas == NULL)
    {
        printf("Ivyko klaida dirbant su failu(-ais). \n");
        exit(1);
    }

    pradiniaiZodziai =(char*)malloc(MAX_SIZE*sizeof(char));

    if (pradiniaiZodziai == NULL)
    {
        printf("Neuztenka atminties! \n");
        exit(1);
    }

    while (fgets(pradiniaiZodziai, MAX_SIZE, fPointerSkaitymas) != 0)
    {
        zodis = strtok(pradiniaiZodziai, " \n");

        while (zodis != NULL)
        {
            ZodziuAtrinkimas(zodis, &eilutesDydis, &tinkamiZodziai, &irasymoPozicija);
            zodis = strtok(NULL, " \n");
        }
    }

    free(pradiniaiZodziai);
    free(duomPavadinimas);

    fclose(fPointerSkaitymas);

    if (tinkamiZodziai == NULL)
    {
        printf ("Tokiu zodziu ivesties faile nera\n");

        fclose(fPointerRasymas);
        free(rezPavadinimas);

        exit(1);
    }

    strcpy(tinkamiZodziai+strlen(tinkamiZodziai)-1, "\0");
    fprintf(fPointerRasymas, "%s", tinkamiZodziai);

    fclose(fPointerRasymas);
    tinkamiZodziai = (char*)realloc(tinkamiZodziai, 0);
    free(rezPavadinimas);

    return 0;
}
