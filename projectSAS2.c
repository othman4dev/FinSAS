#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

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
    printf("\033[1;32m==========================\n\tTo do list :\n==========================\n\033[0m");
    printf("\n \033[1;34m- choisissez une operation :\033[0m\n\n");
    printf("[\033[1;34m1\033[0m]- Ajouter des taches.\n");
    printf("[\033[1;34m2\033[0m]- Affichier la liste.\n");
    printf("[\033[1;34m3\033[0m]- Modifier une tache.\n");
    printf("[\033[1;34m4\033[0m]- Supprimer une tache par identifiant.\n");
    printf("[\033[1;34m5\033[0m]- Rechercher des taches.\n");
    printf("[\033[1;34m6\033[0m]- Statistiques.\n");
    printf("[\033[1;34m7\033[0m]- Quitter du programme.\n\n> ");
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
        printf(" \n \033[1;34mTache N°%d\033[0m : \n\n",i+1);
        printf("\033[1;33mNom de tache :\033[0m\n> ");
        scanf(" %29[^\n]",&dt[i].name);
        printf("\033[1;33mDescription de tache :\033[0m\n> ");
        scanf(" %29[^\n]",&dt[i].discription);
        dt[i].id = i + 1;
        printf("\033[1;36mIdentifiant de tache : %d\033[0m\n",dt[i].id);
        printf("\033[1;33m\nEntrer le deadline de tache :\033[0m\n\n\033[1;36m-Entrer la date sous format 'jj/mm/aaaa'-\033[0m\n");
        for (int j = 0; j < 10; j++)
        {
            scanf("%d/%d/%d",&dl[i].jour,&dl[i].mois,&dl[i].year);
            if(dl[i].year < 2023 || dl[i].jour < 1 || dl[i].jour > 31 || dl[i].mois > 12 || dl[i].mois < 1 ) {
                printf("\033[1;31m\nInvalide date !!\nVeillez rentrer une date valide. \n\n\033[0m");
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
        
        printf("\n\n\033[1;33mstatus de tache :\n\033[0m\n");
        int s = 0;
        printf("\t[\033[1;34m1\033[0m]- A realiser\n");
        printf("\t[\033[1;34m2\033[0m]- En cours de realisation\n");
        printf("\t[\033[1;34m3\033[0m]- Finalisee\n> ");
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
        printf("\033[1;32mTache %d a ete ajoutee \t:\033[0m\n\033[1;33mNom du tache :\033[0m\t%s\n\033[1;33mStatus de tache :\033[0m\t%s\n\033[1;33mDeadline de tache :\033[0m\t%d / %d / %d\n\033[1;33mIdentifiant de tache :\033[0m\t%d\n",i+1,dt[i].name,dt[i].status,dl[i].jour,dl[i].mois,dl[i].year,dt[i].id);
        count++;
        printf("\n\033[1;31mAjouter une autre tache ?:\033[0m\n\t[\033[1;34m1\033[0m]-oui\n\t[\033[1;34m2\033[0m]-non\n> ");
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
printf("\n\033[1;32mListe des taches :\n\n\033[0m");
    for (int i = 0; i < count; i++)
    {
        printf("\033[1;34m%d\033[0m- %s > \033[1;35m%s\033[0m.\n\t( %d / %d / %d )\n",i+1,dt[i].name,dt[i].status,dl[i].jour,dl[i].mois,dl[i].year);
    }
    printf("\n\n[\033[1;34m1\033[0m]- Triee Alphabitiquemet.\n[\033[1;34m2\033[0m]- Triee par deadline.\n[\033[1;34m3\033[0m]- affichier dont le deadline est dans 3 jours ou moins.\n\n> ");
    int a ;
    scanf("%d",&a);
    if (a == 1)
    {
        int index[count];
    	int codes[count];
                
        for(int i = 0;i<count;i++){
        	int temp = dt[i].name[0];
        	for(int i = 0;i<count;i++){
    		int temp = dt[i].name[0];
            codes[i] = temp;
            index[i] = dt[i].id - 1;
        	}
        }
        for(int i = 0;i<count;i++){
        for(int j = 0;j<count;j++){
            if (codes[j]>codes[j+1]){
                int temp = codes[j+1];
                codes[j+1] = codes[j];
                codes[j] = temp;
                int indextemp = index[j+1];
                index[j+1]=index[j];
                index[j]=indextemp;
            }
        }
        printf("La liste des taches classer en ordre alphabitique\n");
        for(int p = 0;p<count;p++){
            	printf("\033[1;34m%d\033[0m- %s > \033[1;35m%s\033[0m.\n\t( %d / %d / %d )\n",p+1,dt[index[p]].name,dt[index[p]].status,dl[index[p]].jour,dl[index[p]].mois,dl[index[p]].year);
        	}
        }
        a = 0;
    } else if (a == 2) {
        int index[count];
        int time[count];
        for(int i = 0;i<=count;i++){
        	int temp = dl[i].year * 10000;
            temp = temp + (dl[i].mois * 100) ;
            temp = temp + dl[i].jour;
            time[i] = temp;
            index[i] = dt[i].id - 1;
        }
        for(int i = 0;i<count;i++){
        for(int j = 0;j<count;j++){
            if (time[j]>time[j+1]){
                int temp = time[j+1];
                time[j+1] = time[j];
                time[j] = temp;
                int indextemp = index[j+1];
                index[j+1]=index[j];
                index[j]=indextemp;
            }
        }
        printf("La liste des taches classer par deadline\n");
        for(int p = 0;p<=count;p++){
            	printf("\033[1;34m%d\033[0m- %s > \033[1;35m%s\033[0m.\n\t( %d / %d / %d )\n",p+1,dt[index[p]].name,dt[index[p]].status,dl[index[p]].jour,dl[index[p]].mois,dl[index[p]].year);
        	}
        }
        a = 0;
    } else if (a == 3) {
    time_t currentTime;
    struct tm *timeInfo;

    time(&currentTime);
    timeInfo = localtime(&currentTime);

    int year = timeInfo->tm_year + 1900; // Years since 1900, so add 1900
	int month = timeInfo->tm_mon + 1; // Months are zero-based, so add 1
    int day = timeInfo->tm_mday;
    int now = (year*10000)+(month*100)+(day);
    int index[count];
        int time[count];
        for(int i = 0;i<count;i++){
        	int temp = (dl[i].year * 10000) + (dl[i].mois * 100) + dl[i].jour;
            time[i] = temp;
            index[i] = dt[i].id - 1;
        }
        for(int i = 0;i<count;i++){
        for(int j = 0;j<count;j++){
            if (time[j]>time[j+1]){
                int temp = time[j+1];
                time[j+1] = time[j];
                time[j] = temp;
                int indextemp = index[j+1];
                index[j+1]=index[j];
                index[j]=indextemp;
            }
        }
        printf("La liste des taches classer pour les taches dont le deadline est dans 3 jours ou moins\n");
        for(int p = 0;p<count;p++){
                int temp = (dl[p].year * 10000) + (dl[p].mois * 100) + dl[p].jour;
                if(temp - now >= 3 && temp - now <= 6){
            	printf("\033[1;34m%d\033[0m- %s > \033[1;35m%s\033[0m.\n\t( %d / %d / %d )\n",p+1,dt[index[p]].name,dt[index[p]].status,dl[index[p]].jour,dl[index[p]].mois,dl[index[p]].year);
                }
        	}
        }
        a = 0;
    } else {
        printf("\n\033[1;31mChoix invalide.\033[0m\n");
    }
    main();
}
int delete() {

}
int status() {

}