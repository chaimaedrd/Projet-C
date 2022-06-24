#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8
struct user{                //structure des infos d'utilisateur 
	char name[20];
	char email[20];
	char password[20];
	char username[20];
	char phone[20];
};
//////////////////////////////////////
typedef struct Salle{         // structure infos du salle
	char ID[20];
    int dd,mm,yy;
    char flr[20];
    char nomE[20];
    char type[20];
    int de, jusq;
}Salle;
//////////////////////////////////////
typedef struct Cellule{          //structure liste chainee
	Salle data;
	struct Cellule *next;
}Cellule;
typedef Cellule* liste;
/////////////////////////////////////
void takeinput(char ch[50]){     //fonction lire
	fgets(ch,20,stdin);
	ch[strlen(ch)-1]=0;
}
char generateUsername(char email[20], char username[20]){  //determine username de l'email par exemple si on a "abcde@gmail.com" , username est "abcde"
	//chaimae123@gmail.com
	for(int i=0;i<strlen(email);i++){
		if(email[i]=='@') break;
		else username[i]=email[i];
	}
}
////////////////////////////////////////
void takepassword(char pwd[20]){         // fonction lire password et l'affiche des etoiles a l'entrer 
	int i;
	char ch;
	while(1){
		ch=getch();
		if(ch == ENTER || ch == TAB){
			pwd[i]='\0';
			break;
		}
		else if(ch == BCKSPC){
			if(i>0){
				i--;
				printf("\b \b");
			}
		}
		else{
			pwd[i++]=ch;
			printf("* \b");
		}
	}
}
/////////////////////////////////////
void ajouterSalle(liste *L,Salle V )    //fonction Ajout du salle au debut 
{
    Cellule *b;
    b=(Cellule*)malloc(sizeof(Cellule));
    b->data=V;
    b->next = NULL;
    b->next=(*L);
    (*L)=b;
}
////////////////////////////////////

////////////////////////////////////
void afficher(liste L)       //Affichage de la liste
{
    Cellule *temp;
    if(L==NULL)
        printf("La liste est Vide");
        else{
            temp=L;
            while(temp!=NULL)
            {
                printf("%s:\n%s : %d / %d / %d : [%s | %s] de %d jusqu a %d\n",temp->data.flr,temp->data.nomE,temp->data.dd, temp->data.mm, temp->data.yy ,temp->data.ID, temp->data.type, temp->data.de, temp->data.jusq);
                temp=temp->next;
            }
        }
}
//////////////////////////////////////
void supp_salle()//Fonction pour supprimer une salle
{	
	char ID[20];
    int dd,mm,yy;
    char flr[20];
    char nomE[20];
    char type[20];
    int de, jusq;
	char ANCIEN[30]="salle.txt", NOUVEAU[30]="enregister2.txt"; 
	FILE *INFILE, *OUTFILE;
	Salle S;

    INFILE = fopen(ANCIEN, "r"); 
    if (!INFILE) 
         printf("\aERREUR: Impossible d'ouvrir le fichier: %s.\n", ANCIEN);
 	else{
 		OUTFILE = fopen(NOUVEAU, "w"); 
    	if (!OUTFILE) 
        	printf("\aERREUR: Impossible d'ouvrir le fichier: %s.\n", NOUVEAU);
        else{
        	printf("\n\ndonner le nom de la salle a supprimer: \n");
			scanf("%s",S.ID);
			printf("\ndonner le nom de l enseignant: \n");
			scanf("%s",S.nomE);
			printf("\ndonner le jour-mois-annee de la reservation a supprimer: \n");
			scanf("%d-%d-%d",&S.dd,&S.mm,&S.yy);
			printf("\ndonner le debut de la reservation a supprimer: \n");
			scanf("%d",&S.de);
			printf("\ndonner la fin de la reservation a supprimer: \n");
			scanf("%d",&S.jusq);
  			while(fscanf(INFILE,"%s %d %d %d %s %s %s %d %d\n",flr,&dd,&mm,&yy,nomE,ID,type,&de,&jusq)!=EOF){
				if(stricmp(S.ID,ID)!=0 || S.dd!=dd || S.mm!=mm || S.yy!=yy || S.de!=de || S.jusq!=jusq){
				fprintf(OUTFILE,"%s %d %d %d %s %s %s %d %d\n",flr,dd,mm,yy,nomE,ID,type,de,jusq);
				}
			}
		}
  fclose(OUTFILE);
  fclose(INFILE); 
  //
  INFILE = fopen(NOUVEAU, "r"); 
  if (!OUTFILE) 
   printf("\aERREUR: Impossible d'ouvrir le fichier: %s.\n", ANCIEN);
 	else{
 		OUTFILE = fopen(ANCIEN, "w"); 
    	if (!OUTFILE) 
        	printf("\aERREUR: Impossible d'ouvrir le fichier: %s.\n", NOUVEAU);
        else{
  			while(fscanf(INFILE,"%s %d %d %d %s %s %s %d %d\n",flr,&dd,&mm,&yy,nomE,ID,type,&de,&jusq)!=EOF){
				fprintf(OUTFILE,"%s %d %d %d %s %s %s %d %d\n",flr,dd,mm,yy,nomE,ID,type,de,jusq);
			}
  		
		}
	fclose(OUTFILE);
    fclose(INFILE); 
}
}
}
////////////////////////////////////
void modifier_salle()//Fonction pour modifier une salle
{	
    char sal1[20]="salle.01";
    char sal2[20]="salle.10";
    char sal3[20]="salle.20";
    char sal4[20]="salle.30";
	char ID[20];
    int dd,mm,yy;
    char flr[20];
    char nomE[20];
    char type[20];
    int de, jusq;
	char ANCIEN[30]="salle.txt", NOUVEAU[30]="enregister2.txt"; 
	FILE *INFILE, *OUTFILE;
	Salle S;
	Salle S2;

    INFILE = fopen(ANCIEN, "r"); 
    if (!INFILE) 
         printf("\aERREUR: Impossible d'ouvrir le fichier: %s.\n", ANCIEN);
 	else{
 		OUTFILE = fopen(NOUVEAU, "w"); 
    	if (!OUTFILE) 
        	printf("\aERREUR: Impossible d'ouvrir le fichier: %s.\n", NOUVEAU);
        else{
        	printf("\n\ndonner le nom de la salle a modifier: \n");
			scanf("%s",S.ID);
			printf("\ndonner la filiere: \n");
			scanf("%s",S.flr);
			printf("\ndonner le nom de l enseignant: \n");
			scanf("%s",S.nomE);
			printf("\ndonner le jour-mois-annee de la reservation a modifier: \n");
			scanf("%d-%d-%d",&S.dd,&S.mm,&S.yy);
			printf("\ndonner le debut de la reservation a modifier: \n");
			scanf("%d",&S.de);
			printf("\ndonner la fin de la reservation a modifier: \n");
			scanf("%d",&S.jusq);
			//nouveau données
			 printf("\n\n         \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd  NOUVELLES VALEURS  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
			printf("\n\ndonner a nouveau le nom de la salle : \n");
			scanf("%s",S2.ID);
			printf("\ndonner le nom du nouveau enseignant: \n");
			scanf("%s",S2.nomE);
			printf("\ndonner la nouvelle filiere: \n");
			scanf("%s",S2.flr);
			printf("\ndonner les nouveaux jour-mois-annee de la reservation : \n");
			scanf("%d-%d-%d",&S2.dd,&S2.mm,&S2.yy);
			printf("\ndonner le debut de la reservation : \n");
			scanf("%d",&S2.de);
			printf("\ndonner la fin de la reservation : \n");
			scanf("%d",&S2.jusq);
			printf("Nom de salle:\t");
    if(stricmp(sal1,S2.ID)<0 && stricmp(sal2,S2.ID)>=0)
    	strcpy(S2.type,"TP");
    else if(stricmp(sal2,S2.ID)<0 && stricmp(sal3,S2.ID)>=0)
    	strcpy(S2.type,"TD");
    else if(stricmp(sal3,S2.ID)<0 && stricmp(sal4,S2.ID)>=0)
    	strcpy(S2.type,"COURS");
    else
		printf("salle non trouvable !");  
	printf("Type de salle(TD,TP,Cour): %s \t\n",S2.type);
  			while(fscanf(INFILE,"%s %d %d %d %s %s %s %d %d\n",flr,&dd,&mm,&yy,nomE,ID,type,&de,&jusq)!=EOF){
				if(stricmp(S.ID,ID)==0 && S.dd==dd && S.mm==mm && S.yy==yy && S.de==de && S.jusq==jusq)
					fprintf(OUTFILE,"%s %d %d %d %s %s %s %d %d\n",S2.flr,S2.dd,S2.mm,S2.yy,S2.nomE,S2.ID,S2.type,S2.de,S2.jusq);
				else
					fprintf(OUTFILE,"%s %d %d %d %s %s %s %d %d\n",flr,dd,mm,yy,nomE,ID,type,de,jusq);	
			}
		}
  fclose(OUTFILE);
  fclose(INFILE);
INFILE = fopen(NOUVEAU, "r"); 
  if (!OUTFILE) 
   printf("\aERREUR: Impossible d'ouvrir le fichier: %s.\n", ANCIEN);
 	else{
 		OUTFILE = fopen(ANCIEN, "w"); 
    	if (!OUTFILE) 
        	printf("\aERREUR: Impossible d'ouvrir le fichier: %s.\n", NOUVEAU);
        else{
  			while(fscanf(INFILE,"%s %d %d %d %s %s %s %d %d\n",flr,&dd,&mm,&yy,nomE,ID,type,&de,&jusq)!=EOF){
				fprintf(OUTFILE,"%s %d %d %d %s %s %s %d %d\n",flr,dd,mm,yy,nomE,ID,type,de,jusq);
			}
  		
		}
	fclose(OUTFILE);
    fclose(INFILE); 
}
	 }     
}
///////////////////////////////////
void HeadOfDepart(liste l1){           //fonction contient la case head of departement 
    int t;
	Salle V;
    int imp1,imp2;
    FILE *fichier; // file pour enregistrer les info et puis les appeles par condition de filiere pour un etudiant et par condition du nom pour l'enseignant
    fichier=fopen("salle.txt","a");
	int option;
	do{
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\t      BIENVENUE");
	printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
	printf("\t     [1] Ajout dans l'emploi de temps\n\n");
	printf("\t     [2] Suppression dans l'emploi de temps\n\n");
	printf("\t     [3] Modification sur l'emploi de temps\n\n");
	printf("\t     [4] RETOUR\n\n");
	printf("\n\n\t      ENTRER VOTRE CHOIX:  "); 
	scanf("%d",&option);
	fgetc(stdin);
	system("cls");
    switch(option){
    	case 1:
    		do{
		        printf("\n    Entrer la filiere (CP-GI-GC-GEER-GEE-ID-GM): ");
                scanf("%s", V.flr);
                do{
            
			        printf("\n    Entrer le nom de l'enseignant:   ");
			        scanf("%s",V.nomE);
			        printf("\n    Les types: \n\n");
	        	    printf("     [1] TP\n\n");
   			        printf("     [2] TD\n\n");
    				printf("     [3] COURS\n\n");
					int start;
					start=0;
    			    while(start!=1){		
				    	printf("\n    Entrer le type du salle: ");
    					scanf("%d",&t);
					    switch(t){
    						case 1:
							    start=1;
    							strcpy(V.type,"TP");
    							printf("\n    Donner le nom du salle (entre 1 et 10): \n\n");
    					    break;
    						case 2:
    							start=1;
    							strcpy(V.type,"TD");
    							printf("\n    Donner le nom du salle (entre 11 et 20) :\n\n");
    					    break;
    						case 3:
    							start=1;
    							strcpy(V.type,"COURS");
    							printf("\n    Donner le nom du salle (entre 21 et 30) :\n\n");
    						break;
    						default:
							    start=0;
    							printf("\n    !!Type non existante!! \n\n");
						    break;
						}
					}		
		        printf("    nom du salle: ");
				fflush(stdin);
		        gets(V.ID);
		        printf("\n    Donner la date sous la forme DD-MM-YY:  \t");
		        scanf("%d-%d-%d", &V.dd, &V.mm, &V.yy);
		        int b=0;
		        while(b==0){
	    	        printf("\n    Entrer la date de debut :  \t");
		            scanf("%d", &V.de);
		            printf("\n    Entrer la date du fin :  \t");
		            scanf("%d", &V.jusq);
	    	        if(V.de>=V.jusq)
	    	        	printf("\n    !!Temps impossible!!\n");
	    	        else
    	            	b=1;
    	        }
		        ajouterSalle(&l1,V);
		        system("cls");
		        printf("\n\n  ->> Tappez 1 pour ajouter une autre salle et 0 pour quitter: \t");
		        scanf("%d", &imp1);
	            }while(imp1!=0);
		        system("cls");
		        printf("\n\n  ->>Tappez 1 pour ajouter une autre filiere et 0 pour quitter:\t");
		        scanf("%d",&imp2);
		    }while(imp2!=0);
			system("cls");
			afficher(l1);
		    for(;l1!=NULL;l1=l1->next){
			    fprintf(fichier,"%s %d %d %d %s %s %s %d %d\n", l1->data.flr, l1->data.dd, l1->data.mm, l1->data.yy, l1->data.nomE, l1->data.ID, l1->data.type, l1->data.de, l1->data.jusq);
			}
			fclose(fichier);
			getch();
			system("cls");
		break;
		case 2:
			supp_salle();
			getch();
			system("cls");
		break;	
		case 3:
			modifier_salle();
			getch();
			system("cls");
	    break;
	    case 4:	
	    break;
	    }
    }while(option!=4);
}
///////////////////////////////////
void EmploiEns(){            //fonction contient la case de lemploi du temps pour un enseignant
	char ID[20];
    int dd,mm,yy;
    char flr[20];
    char nomE[20];
    char type[20];
    int de, jusq;
	struct user usr;
	FILE *fichier, *fp;
	fichier=fopen("salle.txt","r");
	while(fscanf(fichier,"%s %d %d %d %s %s %s %d %d\n",flr,&dd,&mm,&yy,nomE,ID,type,&de,&jusq)!=EOF){
		fp=fopen("Users.txt","r");
		while(fread(&usr,sizeof(struct user),1,fp)){
			if(strcmp(usr.username,nomE)==0){
				printf("%s:\n %d / %d / %d : [%s | %s] de %d jusqu a %d\n",flr,dd, mm, yy , ID, type, de, jusq);
			}
		}
	}
	fclose(fp);
	fclose(fichier);
}
///////////////////////////////////
void Reservation(liste l1){
    Salle VR;
    int b=0;
	char ID[20];
    int dd,mm,yy;
    char flr[20];
    char nomE[20];
    char type[20];
    int de, jusq;
    char sal1[20]="salle.01";
    char sal2[20]="salle.10";
    char sal3[20]="salle.20";
    char sal4[20]="salle.30";
    int sp;
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\t      RESERVATION D UNE SALLE");
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");

    
    printf("    Nom de salle:\t");
    scanf("%s",VR.ID);

    if(stricmp(sal1,VR.ID)<0 && stricmp(sal2,VR.ID)>=0)
    	strcpy(VR.type,"TP");
    else if(stricmp(sal2,VR.ID)<0 && stricmp(sal3,VR.ID)>=0)
    	strcpy(VR.type,"TD");
    else if(stricmp(sal3,VR.ID)<0 && stricmp(sal4,VR.ID)>=0)
    	strcpy(VR.type,"COURS");
    else
		printf("\n     salle non trouvable !");  
	printf("\n    Type de salle(TD,TP,Cour): %s \t\n",VR.type);
    
 //  scanf("%s",VR.type);
    printf("\n    Date(d-m-a):\t");
    scanf("%d-%d-%d",&VR.dd,&VR.mm,&VR.yy);
    while(b==0){
    	printf("\n    Date de debut:\t");
    	scanf("%d",&VR.de);
    	printf("\n    Date de fin:\t");
    	scanf("%d",&VR.jusq);
    	if(VR.de>=VR.jusq)
    		printf("\n    Impossible de reserver pendant cette periode!!!\n");
    	else
    		b=1;
    	}
    FILE *fichier;
	fichier=fopen("salle.txt","a+");
		if(fichier==NULL)
			printf("\n Impossible d ouvrire ce fichier!!\n");
	while(fscanf(fichier,"%s %d %d %d %s %s %s %d %d\n",flr,&dd,&mm,&yy,nomE,ID,type,&de,&jusq)!=EOF){
		if(strcmp(VR.ID,ID)==0 && VR.dd==dd && VR.mm==mm && VR.yy==yy && VR.de==de && VR.jusq==jusq){
			sp=1;
		break;
		}
		else{
			sp=2;
		}
    }
    fflush(stdin);
    switch(sp){
    	case 1:
    		printf("\n    ---> Salle pleinne!");
    	break;
    	case 2:
        	printf("\n    ---> Nom:\t");
        	scanf("%s",VR.nomE);
	        printf("\n    ---> Filiere:\t");
        	scanf("%s",VR.flr);
        	ajouterSalle(&l1,VR);
        	fprintf(fichier,"%s %d %d %d %s %s %s %d %d\n", l1->data.flr, l1->data.dd, l1->data.mm, l1->data.yy, l1->data.nomE, l1->data.ID, l1->data.type, l1->data.de, l1->data.jusq);
            printf("\n\n\tRESERVATION REUSSITE.");
		break;
	}
	fclose(fichier);
}
//////////////////////////////////
void signUP(){
	printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\t      INSCRIPTION");
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");

	FILE *fp;
	struct user user;
	char password2[20];
			fflush(stdin);
		    printf("\n   ENTRER VOTRE NOM: ");
		    takeinput(user.name);
		    printf("\n   ENTRER VOTRE MAIL: ");
		    takeinput(user.email);
		    printf("\n   ENTRER VOTRE TEL: ");
		    takeinput(user.phone);
		    printf("\n   ENTRER VOTRE MOT DE PASSE: ");
		    takepassword(user.password);
		    printf("\n\n   CONFIRMER VOTRE MOT DE PASSE: ");
		    takepassword(password2);
		    if(!strcmp(user.password,password2)){
		    	generateUsername(user.email,user.username);
		    	fp = fopen("personne.dat","a+");
		    	printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
		    	fwrite(&user, sizeof(struct user),1, fp);
		    	
		    	if(fwrite!=NULL){
		    		printf("\n   ENREGISTRATION REUSSITE, VOTRE NOM D UTILISATEUR EST:  \n\n\t\t\t%s\n", user.username);
		    		getch();
				}
				else{
					printf("\n   PARDON!QUELQUE CHOSE S EST MAL PASSE :(  ");
				}
				fclose(fp);
			}
			else{
				printf("\n\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
				printf("\n        MOT DE PASSE NE CORRESPOND PAS. \n");
				Beep(750,300);
				getch();
			}
}
//////////////////////////////////
void EmploiEtu(){               //fonction contient la case de lemploi du temps pour un etudiant
	char fi[20];
	char ID[20];
    int dd,mm,yy;
    char flr[20];
    char nomE[20];
    char type[20];
    int de, jusq;
    FILE *fichier;
    printf("La filiere: ");
    scanf("%s",fi);
    fichier=fopen("salle.txt","r");
	while(fscanf(fichier,"%s %d %d %d %s %s %s %d %d\n",flr,&dd,&mm,&yy,nomE,ID,type,&de,&jusq)!=EOF){
		if(strcmp(flr,fi)==0){
			printf("%s:\n %d / %d / %d : Mr.%s : [%s | %s] de %d jusqu a %d\n",flr,dd, mm, yy , nomE, ID, type, de, jusq);
		}
	}
	fclose(fichier);
}
//////////////////////////////////////////
void LOGIN(){
	int op;
	int a=0;
	printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\t      LOGIN");
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");

	liste l1;
	l1=NULL;
	system("color 0b"); //bleu color
	FILE *fp;
	int opt, opt2,usrFound=0;
	char password2[20];
	char username[20], pword[20];
	struct user usr;
			fflush(stdin);
			printf("\n   ENTRER VOTRE NOM D'UTILISATEUR: ");
			takeinput(username);
		do{
			printf("\n   ENTRER VOTRE MOT DE PASSE: ");
			takepassword(pword);	
			fp=fopen("personne.dat","r");
			while(fread(&usr,sizeof(struct user),1,fp)){
				if(!strcmp(usr.username,username)){
					
					if(!strcmp(usr.password,pword)){
						a=3;
						int AorR;
						system("cls");
						printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
   					    printf("\t\tWELCOME %s",usr.name);
    					printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
					    printf("\n\n         \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd  MENU  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
						printf("\t      [1] COORDINATEUR\n\n");
   						printf("\t      [2] PROFESSEUR\n\n");
    					printf("\t      [3] ETUDIANT\n\n");
    					printf("\t      [4] RETOUR\n\n");
    					printf("         \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	                    printf("\n\n\t      ENTRER VOTRE CHOIX:  "); 
                    	scanf("%d",&opt2);
                    	fgetc(stdin);
						system("cls");
	                    switch(opt2){
	                        case 1:	
	                        	HeadOfDepart(l1);
                            break;
                            case 2:
                            
                                
                            		printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
                            		printf("\t[1] AFFICHAGE DE L EMPLOIS DU TEMPS \n\n");
                            		printf("\t[2] RESERVATION D UNE SALLE \n\n");
                            		printf("\t[3] MODIFICATION D UNE RESERVATION \n\n");
                            		printf("\t[4] SUPPRESSION D UNE RESERVATION\n\n");
                            		printf("\t[5] RETOUR\n\n");
                            		printf("\n\nVEUILLEZ SAISIR VOTRE CHOIX:\n");
                                scanf("%d", &AorR);
                                switch(AorR){
                                    case 1:
                                    	system("cls");
                                    	EmploiEns();
                                    	getch();
                                    break;
                                    case 2:
                                    	system("cls");
                                    	Reservation(l1);
                                    	getch();
                                    break;
                                    case 3:
									    system("cls");
                                    	modifier_salle();
                                    	getch();
                                    	
                                    break;
                                    case 4:
									    system("cls");
                                    	supp_salle();
                                    	getch();
                                    	
                                    break;
                                    case 5:
                                    break;
                                }
                            	
                            break;
                            case 3:
                            	printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
                            	printf("\t[1] AFFICHAGE DE L EMPLOIS DU TEMPS \n\n");
                            	printf("\t[2] RETOUR\n\n");
                            	printf("\n\nVEUILLEZ SAISIR VOTRE CHOIX:\n");
								scanf("%d",&op);
                            	fgetc(stdin);
					        	system("cls");
					        	switch(op){
                                    case 1:
                                    	EmploiEtu();
                            	        getch();
                            	        system("cls");
                                    break;
                                    case 2:
                                    break;
                                }
                            break; 
							case 4:
							break;
						
	                    }
				    }
					else{
  						printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
						a++;	
					if(a!=3)
						printf("\n\n   ENTREE INVALIDE, VEUILLEZ RESSAYER...\n\n");
					
						getch();//holds the screen
						Beep(800,300);
						if(a==3){
				printf("\n DESOLE! VOUS AVEZ SAISIE UNE ENTREE INVALIDE 3 FOIS!!\n");
				getch();
			}			
					}
						}
					}
			}while(a<3);
			

				 usrFound=1;
			
			if(!usrFound){
				printf("\n\nUser is not registred!");
				Beep(800,300);
	
			}
			fclose(fp);
}

//////////////////////////////////

///////////////////////LA FONCTION MAIN/////////////////////////
int main()
{
    int num,i;
    do{
    system("cls");
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t    APPLICATION DE GESTION DES SALLES");
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd  MENU  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    printf("\t   [1] INSCRIPTION\n\n");
    printf("\t   [2] LOGIN\n\n");
    printf("\t   [3] QUITTER\n\n");
    printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("   ENTRER VOTRE CHOIX: ");
    scanf("%d",&num);
    system("cls");
    switch(num)
    {
    case 1:
        signUP();//for list of bus
        break;
    case 2:
        LOGIN();//for booking the tickets
        break;
    }
    }while(num != 3);
    system("CLS");
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t    MERCI D'AVOIR UTILISER CETTE PLATEFORME");
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    printf("\n\n");
    printf("      \t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd  REALISER PAR:  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n\n");
	printf("\t\t      CHAYMAA OUALI\n\n");
    printf("\t\t      CHAIMAE DARDOURI\n\n");
    printf("\t\t      AYOUB ADIL\n\n");
    printf("\n      \t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd  ENCADRER PAR:  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n\n");
	printf("\t\t      Mr A.BAHRI\n\n");
    getch();
    return 0;
}
