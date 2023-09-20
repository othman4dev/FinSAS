#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct
{
        int jour;
        int mois;
        int year;
}deadline;

typedef struct
{
    char name[35];
    char date[35];
    int id;
    char discription[100];
    char status[35];
}data;
data dt[100];
deadline dl[100];

int count = 0;

int main() {
    menu();
}
int menu() {
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
        add();
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
        main();
    }
}
int add() {
    for (int i = count; i < 100; i++)
    {
        printf("Tache numero %d : \n",i+1);
        printf("Nom de tache :\n> ");
        scanf(" %29[^\n]",&dt[i].name);
        printf("Description de tache :\n> ");
        scanf(" %29[^\n]",&dt[i].discription);
        dt[i].id = i + 1;
        printf("Identifiant de tache : %d\n",dt[i].id);
        printf("\nEntrer le deadline de tache :\n\n-Entrer la date sous format 'jj/mm/aaaa'-\n");
        for (int j = 0; j < 10; j++)
        {
            scanf("%d/%d/%d",&dl[i].jour,&dl[i].mois,&dl[i].year);
            if(dl[i].year < 2023 || dl[i].jour < 1 || dl[i].jour > 31 || dl[i].mois > 12 || dl[i].mois < 1 ) {
                printf("Invalide date !!\n Veillez rentrer une date valide. \n");
            }
            else if (dl[i].mois == 2 && dl[i].jour > 28)
            {
                printf("Invalide date !!\n Veillez rentrer une date valide. \n");
            }
            else 
            {
                j = 10;
            }
        }
        
        printf("status de tache :\n\n");
        int s = 0;
        printf("\t[1]- A realiser\n");
        printf("\t[2]- En cours de realisation\n");
        printf("\t[3]- Finalisee\n> ");
        scanf("%d",&s);
        if (s == 1)
        {
            strcpy(dt[i].status,"A realiser");
        }
        else if (s == 2) 
        {
            strcpy(dt[i].status,"En cours de realisation");
        }
        else if (s == 3) 
        {
            strcpy(dt[i].status,"Finalisee");
        } else 
        {
            printf("La tache a configurait comme 'A realiser'\n");
            strcpy(dt[i].status,"A realiser");
        }
        printf("Tache %d a ete ajoutee \t:\nNom du tache :\t%s\nStatus de tache :\t%s\nDeadline de tache :\t%d / %d / %d\nIdentifiant de tache :\t%d\n",i+1,dt[i].name,dt[i].status,dl[i].jour,dl[i].mois,dl[i].year,dt[i].id);
        count++;
        printf("\nAjouter une autre tache ?:\n\t[1]-oui\n\t[2]-non\n> ");
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
    for (int i = 0; i <= count; i++)
    {
        printf("\nListe des taches :\n\n");
        printf("%d- %s > %s.\n\t( %d / %d / %d )\n",i+1,dt[i].name,dt[i].status,dl[i].jour,dl[i].mois,dl[i].year);
    }
    printf("\n\n[1]- Triee Alphabitiquemet.\n[2]- Triee par deadline.\n[3]- affichier dont le deadline est dans 3 jours ou moins.");
    int a ;
    scanf("%d",&a);
    if (a == 1)
    {
        int index = 0;
        for (int i = 0; i < count; i++)
        {
            if (dt[i].name[0]>dt[i+1].name[0])
            {
                index = i;
            } else {
                index = i+1;
            }
            printf("index is : %d",index);
             
        }
        
    } else if (a == 2)
    {
        
    } else if (a == 3) {
    } else {
        printf("\nInvalide choix.\n");
    }
    main();
}
int delete() {

}
int status() {

}