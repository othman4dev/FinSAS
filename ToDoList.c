#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<windows.h>
typedef struct 
{
    int day;
    int month;
    int year;
}timeCreated;



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

int done = 0;

int todo = 0;

int doing = 0;

 //stores the id of deleted tasks.
int deleted[100];

int counter(int index) {
    int deadline = dl[index].year + dl[index].mois + dl[index].jour;
    
    time_t currentTime;
    struct tm *timeInfo;

    time(&currentTime);
    timeInfo = localtime(&currentTime);

    int year = timeInfo->tm_year + 1900; // Years since 1900, so add 1900
	int month = timeInfo->tm_mon + 1; // Months are zero-based, so add 1
    int day = timeInfo->tm_mday;
    int now = (year*365)+(month*30)+(day);
}

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
    for (int i = 0; i < 10; i++)
    {
        printf("\033[1;31m-\033[0m");
        Sleep(10);
    }
    char closed[19] = "Le program a quitte";
    for (int i = 0; i < 19; i++)
    {
        printf("\033[1;31m%c\033[0m",closed[i]);
        Sleep(10);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("\033[1;31m-\033[0m");
        Sleep(10);
    }
    printf("\n\n");
        exit(EXIT_SUCCESS);
    default:
        printf("\nInvalide choice\n");
        main();
    }
}
int add() {
    for (int i = count; i < 100; i++)
    {
        printf(" \n \033[1;34mTache NO%d\033[0m : \n\n",i+1);
        printf("\033[1;33mNom de tache :\033[0m\n> ");
        scanf(" %29[^\n]",&dt[i].name);
        printf("\033[1;33mDescription de tache :\033[0m\n> ");
        scanf(" %29[^\n]",&dt[i].discription);
        dt[i].id = i + 1;
        printf("\n\033[1;36mIdentifiant de tache : %d\033[0m\n",dt[i].id);
        printf("\033[1;33m\nEntrer le deadline de tache :\033[0m\n\t\033[1;36m-Entrer la date sous format 'jj/mm/aaaa'-\033[0m\n\n> ");
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
            todo++;
        }
        else if (s == 2) 
        {
            strcpy(dt[i].status,"En cours de realisation");
            doing++;
        }
        else if (s == 3) 
        {
            strcpy(dt[i].status,"Finalisee");
            done++;
        } else 
        {
            printf("La tache a configurait comme 'A realiser'\n");
            strcpy(dt[i].status,"A realiser");
            todo++;
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
    printf("\n\033[1;33mLa liste des taches est comme suivant :\033[0m\n\n");
    for (int i = 0; i < count; i++)
    {
        if (dt[i].id != 999)
        {
            printf("[\033[1;34m%d\033[0m]- %s > \033[1;35m%s\033[0m.\n\t( %d / %d / %d )\n",i+1,dt[i].name,dt[i].status,dl[i].jour,dl[i].mois,dl[i].year);
        }
    }
    printf("[\033[1;34m%d\033[0m]- exit.\n\n",count+1);
    printf("\n\033[1;36mChoisir une tache pour la modifiee :\033[0m\n\n>");
    int c;
    scanf("%d", &c);
    if(c == count + 1){
        main();
    }
    printf("\033[1;34m[%d]\033[0m- %s > \033[1;35m%s\033[0m.\n\t( %d / %d / %d )\n\n",c,dt[c-1].name,dt[c-1].status,dl[c-1].jour,dl[c-1].mois,dl[c-1].year);
    printf("\033[1;33mChanger :\033[0m\n");
    printf("[1]- Le titre.\t[2]- Description.\t[3]- Le deadline.\t[4]- Le status.\n> ");
    int changes;
    scanf("%d",&changes);
    if (changes == 1)
    {
        printf("\033[1;34m[%d]\033[0m- %s > \033[1;35m%s\033[0m.\n\t( %d / %d / %d )\n\nEntrer le nouveau Titre :\n\n> ",c,dt[c-1].name,dt[c-1].status,dl[c-1].jour,dl[c-1].mois,dl[c-1].year);
        strcpy(dt[c-1].name,dt[count+1].name);
        scanf(" %29[^\n]",&dt[c-1].name);
        printf("\033[1;32m\n      (!) Le titre a ete modifiee   \n\033[0m");
        change();
    } else if (changes == 2) {
        printf("\033[1;34m[%d]\033[0m- %s > \033[1;35m%s\033[0m.\n\t( %d / %d / %d )\n\nEntrer la nouvelle description :\n\n> ",c,dt[c-1].name,dt[c-1].status,dl[c-1].jour,dl[c-1].mois,dl[c-1].year);
        strcpy(dt[c-1].name,dt[count+1].name);
        scanf(" %29[^\n]",&dt[c-1].name);
        printf("\033[1;32m\n      (!) La description a ete modifiee   \n\033[0m");
        change();
    } else if (changes == 3) {
        printf("\033[1;34m[%d]\033[0m- %s > \033[1;35m%s\033[0m.\n\t( %d / %d / %d )\n\nEntrer le nouveau deadline :\n\n> ",c,dt[c-1].name,dt[c-1].status,dl[c-1].jour,dl[c-1].mois,dl[c-1].year);
        for (int j = 0; j < count; j++)
        {
            scanf("%d/%d/%d",&dl[c-1].jour,&dl[c-1].mois,&dl[c-1].year);
            if(dl[c-1].year < 2023 || dl[c-1].jour < 1 || dl[c-1].jour > 31 || dl[c-1].mois > 12 || dl[c-1].mois < 1 ) {
                    printf("\033[1;31m\nInvalide date !!\nVeillez rentrer une date valide. \n\n\033[0m");
                }
                else if (dl[c-1].mois == 2 && dl[c-1].jour > 28)
                {
                    printf("Invalide date !!\n Veillez rentrer une date valide. \n");
                }
                else 
                {
                    j = 10;
                }
        }
        printf("\033[1;32m\n      (!) Le deadline a ete modifiee   \n\033[0m");
        change();
    } else if (changes == 4) {
        printf("\033[1;34m[%d]\033[0m- %s > \033[1;35m%s\033[0m.\n\t( %d / %d / %d )\n\nEntrer la nouvelle status :\n\n> ",c,dt[c-1].name,dt[c-1].status,dl[c-1].jour,dl[c-1].mois,dl[c-1].year);
        printf("\n\n\033[1;33mStatus de tache :\n\033[0m\n");
        int s = 0;
        strcpy(dt[c-1].status,dt[count+1].status);
        printf("\t[\033[1;34m1\033[0m]- A realiser\n");
        printf("\t[\033[1;34m2\033[0m]- En cours de realisation\n");
        printf("\t[\033[1;34m3\033[0m]- Finalisee\n> ");
        scanf("%d",&s);
        if (s == 1)
        {
            if(dt[c-1].status == "A realiser") {
                    //nothing
                } else if (dt[c-1].status == "En cours de realisation")
                {
                    doing--;
                } else if (dt[c-1].status == "Finalisee")
                {
                    done--;
                }
            strcpy(dt[c-1].status,"A realiser");
            printf("La tache a configurait comme 'A realiser'\n");
            todo++;
        }
        else if (s == 2) 
        {
            if(dt[c-1].status == "A realiser") {
                    todo--;
                } else if (dt[c-1].status == "En cours de realisation")
                {
                    //nothing
                } else if (dt[c-1].status == "Finalisee")
                {
                    done--;
                }
            strcpy(dt[c-1].status,"En cours de realisation");
            printf("La tache a configurait comme 'En cours de realisation'\n");
            doing++;
        }
        else if (s == 3) 
        {
            if(dt[c-1].status == "A realiser") {
                    todo--;
                } else if (dt[c-1].status == "En cours de realisation")
                {
                    doing--;
                } else if (dt[c-1].status == "Finalisee")
                {
                    //nothing
                }
            strcpy(dt[c-1].status,"Finalisee");
            printf("La tache a configurait comme 'Finalisee'\n");
        } else
        {
            if(dt[c-1].status == "A realiser") {
                    //nothing
                } else if (dt[c-1].status == "En cours de realisation")
                {
                    doing--;
                } else if (dt[c-1].status == "Finalisee")
                {
                    done--;
                }
            printf("La tache a configurait comme 'A realiser'\n");
            strcpy(dt[c-1].status,"A realiser");
        }
        printf("\n\n\033[1;32m(!)- La tache a ete modifie.\033[0m\n\n");
        main();
    }
}
int show() {
printf("\n\033[1;32mListe des taches :\n\n\033[0m");
    for (int i = 0; i < count; i++)
    {
        if (dt[i].id != 999)
        {
            printf("\033[1;34m%d\033[0m- %s > \033[1;35m%s\033[0m.\n\t( %d / %d / %d )\n",i+1,dt[i].name,dt[i].status,dl[i].jour,dl[i].mois,dl[i].year);
        }
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
        }
        printf("La liste des taches classer en ordre alphabitique :\n\n");
        for(int p = 0;p<count;p++){
                if (dt[p].id != 999)
                {
                    printf("\033[1;34m%d\033[0m- %s > \033[1;35m%s\033[0m.\n\t( %d / %d / %d )\n",p+1,dt[index[p]].name,dt[index[p]].status,dl[index[p]].jour,dl[index[p]].mois,dl[index[p]].year);
                }
        	}
        a = 0;
    } else if (a == 2) {
        int index[count+1];
        int time[count+1];
        for(int i = 0;i<=count;i++){
        	int temp = dl[i].year * 10000;
            temp = temp + (dl[i].mois * 100);
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
        }
        printf("La liste des taches classer par deadline :\n\n");
        for(int p = 0;p<=count;p++){
                if (dt[p].id != 999)
                {
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
        }
        printf("\033[1;33mLa liste des taches classer pour les taches dont le deadline est dans 3 jours ou moins :\033[0m\n\n");
        for(int p = 0;p<count;p++){
                int temp = (dl[p].year * 10000) + (dl[p].mois * 100) + dl[p].jour;
                if(temp - now <= 3 && temp - now >= 0){
                    if (dt[p].id != 999)
                    {
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
    int id;
    char target[20];
    int tests = 0;
    printf("\n\033[1;33mEntrer L'ID de tache :\033[0m\n> ");
    scanf("%d",&id);
    for ( int i = 0; i <= count; i++)
    {
        if (dt[i].id == id)
        {
            printf("La tache saisie est \n\n\033[1;34m%d\033[0m- %s > \033[1;35m%s\033[0m.\n\t( %d / %d / %d )\n\n",id,dt[i].name,dt[i].status,dl[i].jour,dl[i].mois,dl[i].year);
            printf("Confirmer ?\n");
            int confirm;
            printf("\t[\033[1;34m1\033[0m]- \033[1;31mSupprimer.\033[0m\n");
            printf("\t[\033[1;34m2\033[0m]- \033[1;33mAnnuler.\033[0m\n\n");
            scanf("%d",&confirm);
            if (confirm == 1)
            {
                if(dt[i].status == "A realiser") {
                    todo--;
                } else if (dt[i].status == "En cours de realisation")
                {
                    doing--;
                } else if (dt[i].status == "Finalisee")
                {
                    done--;
                }
                dt[i] = dt[count+1];
                dl[i] = dl[count+1];
                dt[i].id = 999;
                strcpy(dt[i].name,"Deleted");
                printf("\033[1;34mLa tache a ete supprimer.\033[0m\n");
            } else if (confirm == 2)
            {
                printf("\033[1;34mLa tache n'a ete pas supprimer.\033[0m\n");
            }
            
        } else {
            tests++;
        }
        if (tests == count + 1)
        {
            printf("\033[1;33m(!) - La tache est introuvable\n\033[0m");
            break;
        }
    }
    main();
}
int status() {
    printf("\n\n--Vous avez \033[1;34m%d\033[0m tache(s).\n\n\tParmi il y a:\n",count);

    printf("\n\n--Vous avez \033[1;34m%d\033[0m tache(s) a realiser.\n",todo);

    printf("\n\n--Vous avez \033[1;34m%d\033[0m tache(s) En realisation.\n",doing);

    printf("\n\n--Vous avez \033[1;34m%d\033[0m tache(s) En realisation.\n",done);   


}
