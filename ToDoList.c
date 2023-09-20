#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct deadline
{
        int jour;
        int mois;
        int year;
};

struct data
{
    char name[35];
    char date[35];
    int id;
    char discription[50];
    struct deadline deadline[100];
    char status[35];
};
struct data dt[100];

int main() {
    menu();
}
int menu() {
    int n = 1;
    printf("\n==========================\n\tTo do list :\n==========================\n");
    printf("\n - choisissez une operation :\n\n");
    printf("[1]- Ajouter des taches.\n");
    printf("[2]- Affichier la liste.\n");
    printf("[3]- Modifier une tache.\n");
    printf("[4]- Supprimer une tache par identifiant.\n");
    printf("[5]- Rechercher des taches.\n");
    printf("[6]- Statistiques.\n");
    printf("[7]- Quitter du programme\n\n> ");
    int a;
    scanf("%d",&a);
    switch (a)
    {
    case 1:
        add(n);
    case 2:
        show();
    case 3:
        change();
    case 4:
        delete();
    case 5:
        search();
    case 6:
        status();
    case 7:
    printf("Le program a quitte");
        exit(EXIT_SUCCESS);
    default:
        printf("\nInvalide choice\n");
    }
}
int add() {
    for (int i = 0; i < 100; i++)
    {
        dt[i].deadline[i].jour = 0;
        dt[i].deadline[i].mois = 0;
        dt[i].deadline[i].year = 0;
        struct data dt[i];
        printf("Tache numero %d : \n",i+1);
        printf("Nom de tache :\n> ");
        scanf(" %29[^\n]",&dt[i].name);
        dt[i].id = i;
        printf("Identifiant de tache : %d\n",dt[i].id);
        printf("\nEntrer le deadline de tache :\n\n-Entrer la date sous format 'jj/mm/aaaa'-\n");
        for (int j = 0; j < 10; j++)
        {
            scanf("%d/%d/%d",&dt[i].deadline[i].jour,&dt[i].deadline[i].mois,&dt[i].deadline[i].year);
            if(dt[i].deadline[i].year < 2023 || dt[i].deadline[i].jour < 1 || dt[i].deadline[i].jour > 31 || dt[i].deadline[i].mois > 12 || dt[i].deadline[i].mois < 1 ) {
                printf("Invalide date !!\n Veillez rentrer une date valide. \n");
            }
            else if (dt[i].deadline[i].mois == 2 && dt[i].deadline[i].jour > 28)
            {
                printf("Invalide date !!\n Veillez rentrer une date valide. \n");
            }
            else 
            {
                j = 10;
            }
        }
        printf("status de tache :\n\n");
        printf("\t[1]- A realiser\n");
        printf("\t[2]- En cours de realisation\n");
        printf("\t[3]- Finalisee\n> ");
        int x;
        scanf("%d",&x);
        char stat1[20] = "A realiser";
        char stat2[30] = "En cours de realisation";
        char stat3[30] = "Finalisee";
        if (x == 1)
        {

            strcpy(dt[i].status,"A realiser");
        }
        else if (x == 2) 
        {
            strcpy(dt[i].status,"En cours de realisation");
        }
        else if (x == 3) 
        {
            strcpy(dt[i].status,"Finalisee");
        } else 
        {
            printf("La tache a modifiee comme 'A realiser'\n");
            strcpy(dt[i].status,"A realiser");
        }
        printf("Tache %d a ete ajoutee \t:\nNom du tache :\t%s\nStatus de tache :\t%s\nDeadline de tache :\t%d / %d / %d\nIdentifiant de tache :\t%d\n",i,dt[i].name,dt[i].status,dt[i].deadline[i].jour,dt[i].deadline[i].mois,dt[i].deadline[i].year,dt[i].id);
        printf("Ajouter une autre tache :\n\t[1]-yes\n\t[2]-non\n");
        int y;
        scanf("%d",&y);
        if(y == 2) {
            main();
        } else if (y == 1)
        {
            y = 1;
        }
        else {
            main();
        }
        }
    }
int search(){

}
int change() {

}
int show() {

}
int delete() {

}
int status() {

}