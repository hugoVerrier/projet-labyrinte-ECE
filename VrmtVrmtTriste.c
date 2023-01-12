//
// Created by Pas un taille crayon on 14/12/2022.
//

#include "VrmtVrmtTriste.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Cases Menu_Case(){
    int choix;
    Cases K;
    tableau T;
    printf("Creation et modification de Case: \n 1-Creation de case \n 2-Initialisation du tableau \n 0-Quitter \n");
    scanf("%d",&choix);
    switch (choix) {
        case 1:{
            K=Creation_Case(K);
            printf("\nVoulez vous continuer?\n 1- Tableau \n 0 quitter\n");
            scanf("%d",&choix);
        }
        case 2:{
            T=init_Tableau();
        }
        default:{
            printf("Sortie du Menu Case");
            break;
        }
    }
    return K;
}
/*Creation d'une case à partir de son type et de ses coordonees pour changer la case d'un tableau et rempli son ID accordement (ID+direction+coordonnées)*/
Cases Creation_Auto(int TypeK, int CoorX, int CoorY, Cases K){
    int ID_temp, Randomizer, RotaK;
    srand(time(NULL));
    K.IRXYFJDHBGTS[2]=CoorX;
    K.IRXYFJDHBGTS[3]=CoorY;
    Randomizer=rand();
    RotaK=Randomizer%5;
    if (RotaK==0){RotaK+=1;}
    ID_temp = ID_Creation(1, TypeK, RotaK);
    K=Init_Case(K, ID_temp);
    K=direction_Possible(K);
}

Cases Creation_Case(Cases K){
    int Auto, ID_Case, TypeK, RotaK;
    printf("Voulez vous initialiser la case : \n 0- Manuellement \n 1- Automatiquement");
    scanf("%d",&Auto);
    switch (Auto){
        /* initialise une case automatiquement mais rempli l'ID semi manuellement*/
        case 1:{
            ID_Case=ID_Creation(Auto, TypeK, RotaK);
            K=Init_Case(K, ID_Case);
            K= Cases_Completion(K);
            affiche_Case(K);
            break;
        }
        /*initialise une case manuellement*/
        case 0:{
            printf("Insérer le Type : \n 1-I \n 2-L \n3-T\n");
            scanf("%d",&TypeK);
            printf("Insérer la rotation entre 0-4 :" );
            scanf("%d",&RotaK);
            ID_Case=ID_Creation(Auto, TypeK, RotaK);
            K=Init_Case(K, ID_Case);
            K= Cases_Completion(K);
            affiche_Case(K);
            break;
        }
    }

    return K;
}

/*initialise une case selon son id_ID, et rempli l'id I et sa rotation (utile pour l'affichage des cases sur le plateau)*/
Cases Init_Case(Cases K,int ID_Case){

    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if ((i==1)&&(j==1)){
                K.Tab[i][j]=1;}
            else{
                K.Tab[i][j]=0;
            }
        }
    }
    switch (ID_Case) {
        case 0:{ /* I-1*/
            K.Tab[0][1]=1;
            K.Tab[2][1]=1;
            K.IRXYFJDHBGTS[0]=1;
            K.IRXYFJDHBGTS[1]=1;
            break;
        }
        case 1:{/* I-2*/
            K.Tab[1][0]=1;
            K.Tab[1][2]=1;
            K.IRXYFJDHBGTS[0]=1;
            K.IRXYFJDHBGTS[1]=2;
            break;
        }
        case 2:{/* L-1*/
            K.Tab[0][1]=1;
            K.Tab[1][2]=1;
            K.IRXYFJDHBGTS[0]=2;
            K.IRXYFJDHBGTS[1]=1;
            break;
        }
        case 3:{/* L-2*/
            K.Tab[2][1]=1;
            K.Tab[1][2]=1;
            K.IRXYFJDHBGTS[0]=2;
            K.IRXYFJDHBGTS[1]=2;
            break;
        }
        case 4:{/* L-3*/
            K.Tab[2][1]=1;
            K.Tab[1][0]=1;
            K.IRXYFJDHBGTS[0]=2;
            K.IRXYFJDHBGTS[1]=3;
            break;
        }
        case 5:{/* L-4*/
            K.Tab[0][1]=1;
            K.Tab[1][0]=1;
            K.IRXYFJDHBGTS[0]=2;
            K.IRXYFJDHBGTS[1]=4;
            break;
        }
        case 6:{/* T-1*/
            K.Tab[0][1]=1;
            K.Tab[1][2]=1;
            K.Tab[1][0]=1;
            K.IRXYFJDHBGTS[0]=3;
            K.IRXYFJDHBGTS[1]=1;
            break;
        }
        case 7:{
            /* T-2*/
            K.Tab[0][1]=1;
            K.Tab[1][2]=1;
            K.Tab[2][1]=1;
            K.IRXYFJDHBGTS[0]=3;
            K.IRXYFJDHBGTS[1]=2;
            break;
        }
        case 8:{
            /* T-3*/
            K.Tab[1][0]=1;
            K.Tab[1][2]=1;
            K.Tab[2][1]=1;
            K.IRXYFJDHBGTS[0]=3;
            K.IRXYFJDHBGTS[1]=3;
            break;
        }
        case 9:{
            /* T-4*/
            K.Tab[0][1]=1;
            K.Tab[2][1]=1;
            K.Tab[1][0]=1;
            K.IRXYFJDHBGTS[0]=3;
            K.IRXYFJDHBGTS[1]=4;
            break;
        }
        case 10:{
            break;
        }
    }
    printf("Initialisation de la case..;\n");
    return K;
}
/*print de la case seulement après avoir fait la case complete*/
void affiche_Case(Cases K){
    for (int i=0;i<3;i++) {
        printf("\n");
        for (int j=0;j<3;j++){
            printf("\t");
            printf("%d", K.Tab[i][j]);
        }
    }
    printf("\n\n");
}
/*utilise le tableau de la case et rempli l'id selon les directions possible*/
Cases direction_Possible(Cases K){
    if (K.Tab[1][0]==1){
        K.IRXYFJDHBGTS[9]=1;
        printf("Gauche ");
    }
    if (K.Tab[0][1]==1){
        K.IRXYFJDHBGTS[7]=1;
        printf("Haut ");
    }
    if (K.Tab[2][1]==1){
        K.IRXYFJDHBGTS[8]=1;
        printf("Bas ");
    }
    if (K.Tab[1][2]==1){
        K.IRXYFJDHBGTS[6]=1;
        printf("Droite  ");
    }
    if (K.Tab[1][0]==0){
        K.IRXYFJDHBGTS[9]=0;
        printf("Non Gauche ");
    }
    if (K.Tab[0][1]==0){
        K.IRXYFJDHBGTS[7]=0;
        printf("Non Haut ");
    }
    if (K.Tab[2][1]==0){
        K.IRXYFJDHBGTS[8]=0;
        printf("Non Bas ");
    }
    if (K.Tab[1][2]==0){
        K.IRXYFJDHBGTS[6]=0;
        printf("Non Droite ");
    }
    printf("Remplissage des directions...\n");
    return K;
}
/* rempli L'id avec les coordonées, la fixation, la presence du joueur, ses directions possibles, et la presence d'un tresor*/
Cases Cases_Completion(Cases K){
    int X, Y, Psc, trez;
    printf("Saisissez les coordonnées de la case :");
    scanf("%d %d", &X, &Y);
    K.IRXYFJDHBGTS[2]=X;
    K.IRXYFJDHBGTS[3]=Y;
    if ((X%2==0)&&(Y%2==0)){
        K.IRXYFJDHBGTS[4]=1;
    }
    else{
        K.IRXYFJDHBGTS[4]=0;
    }
    printf("Le joueur est il present?");
    scanf("%d", &Psc);
    K.IRXYFJDHBGTS[5]=Psc;
    K=direction_Possible(K);
    printf("Tresor?");
    scanf("%d",&trez);
    K.IRXYFJDHBGTS[10]=trez;
    printf("Completion de la case...\n");
    return K;
}
/*Cree un ID Case pour pouvoir initier une case selon les modèles disponible*/
int ID_Creation(int Auto, int TypeK,int RotaK){
    int ID_Crea;
    /*if (Auto==1){
        srand(time(NULL));
        int Random, ID_Creation;
        Random=rand();
        ID_Crea = Random%10;
    }
    else if(Auto==0){*/
        switch (TypeK) {
            case 1:{
                /*printf("I- Choisissez la rotation entre 1 et 2\n");
                scanf("%d",&RotaK);*/
                switch (RotaK) {
                    case 1:{
                        ID_Crea=0;
                        break;
                    }
                    case 2:{
                        ID_Crea=1;
                        break;
                    }
                }
                break;
            }
            case 2:{
                /*printf("L- Choisissez la rotation entre 1 et 4\n");
                scanf("%d",&RotaK);*/
                switch (RotaK) {
                    case 1:{ID_Crea=2;
                        break;}
                    case 2:{ID_Crea=3;
                        break;}
                    case 3:{ID_Crea=4;
                        break;}
                    case 4:{ID_Crea=5;
                        break;}
                }
                break;
            }
            case 3:{
                /*printf("T- Choisissez la rotation entre 1 et 4\n");
                scanf("%d",&RotaK);*/
                switch (RotaK) {
                    case 1:{ID_Crea=6;
                        break;}
                    case 2:{ID_Crea=7;
                        break;}
                    case 3:{ID_Crea=8;
                        break;}
                    case 4:{ID_Crea=9;
                        break;}
                }
                break;
            }
            default:{
                printf("Veuillez choisir un type valide de case:");
                scanf("%d", &TypeK);
                break;
            }
        }
    /*}*/
    printf("Creation de l'ID de la case...\n");
    return ID_Crea;
}
/*Determine si un deplacement joueur est possible entre deux case rend Dep=1  si oui sinon Dep=0*/
int Mvt_Possible(Cases K1, Cases K2){
    int DiffX, DiffY, X1, X2, Y1, Y2, Dep;
    X1=K1.IRXYFJDHBGTS[2];
    X2=K2.IRXYFJDHBGTS[2];
    Y1=K1.IRXYFJDHBGTS[3];
    Y2=K2.IRXYFJDHBGTS[3];
    DiffX=X1-X2;
    DiffY=Y1-Y2;
    if ((DiffX==0)&&(DiffY==1)) {
        Dep = ((K1.IRXYFJDHBGTS[7]==1)&&(K2.IRXYFJDHBGTS[8]==1))? 1:0;
    }
    if ((DiffX==0)&&(DiffY==-1)) {
        Dep = ((K1.IRXYFJDHBGTS[8]==1)&&(K2.IRXYFJDHBGTS[7]==1))? 1:0;
    }
    if ((DiffX==1)&&(DiffY==0)) {
        Dep = ((K1.IRXYFJDHBGTS[6]==1)&&(K2.IRXYFJDHBGTS[9]==1))? 1:0;
    }
    if ((DiffX==-1)&&(DiffY==0)) {
        Dep = ((K1.IRXYFJDHBGTS[9]==1)&&(K2.IRXYFJDHBGTS[6]==1))? 1:0;
    }
    else {
        Dep = 0;
        Mvt_Impossible();
    }

    return Dep;
}
/* Print que le mouvement est impossible*/
void Mvt_Impossible(){
    printf("Le mouvement est impossible");
}
/*initialisation d'un tableau vide avec uniquement les cases fixes et complète son ID sans joueurs ni tresor*/
tableau Init_Tableau_Fixe(){
    int ID_Cree, i, j;
    Cases K_i;
    tableau T;
    printf("Case fixe generation..");
    for (i=0;i<7;i++){
        for (j=0;j<7;j++){
            K_i.IRXYFJDHBGTS[2]=i;
            K_i.IRXYFJDHBGTS[3]=j;
            K_i.IRXYFJDHBGTS[11]=0;
            K_i.IRXYFJDHBGTS[10]=0;
            K_i.IRXYFJDHBGTS[5]=0;
    if((i==0)&&(j==0)){
        ID_Cree=3;
        K_i= Init_Case(K_i, ID_Cree);
        K_i.IRXYFJDHBGTS[11]=1;
        K_i.IRXYFJDHBGTS[4]=1;
    }
    else if((i==0)&&(j==2)){
        ID_Cree=8 ;
        K_i= Init_Case(K_i, ID_Cree);
        K_i.IRXYFJDHBGTS[4]=1;
    }
    else if((i==0)&&(j==4)){
        ID_Cree= 8;
        K_i= Init_Case(K_i, ID_Cree);
        K_i.IRXYFJDHBGTS[4]=1;
    }
    else if((i==0)&&(j==6)){
        ID_Cree= 4;
        K_i= Init_Case(K_i, ID_Cree);
        K_i.IRXYFJDHBGTS[11]=2;
        K_i.IRXYFJDHBGTS[4]=1;
    }
    else if((i==2)&&(j==0)){
        ID_Cree= 7;
        K_i= Init_Case(K_i, ID_Cree);
        K_i.IRXYFJDHBGTS[4]=1;
    }
    else if((i==2)&&(j==2)){
        ID_Cree= 7;
        K_i= Init_Case(K_i, ID_Cree);
        K_i.IRXYFJDHBGTS[4]=1;
    }
    else if((i==2)&&(j==4)){
        ID_Cree= 8;
        K_i= Init_Case(K_i, ID_Cree);
        K_i.IRXYFJDHBGTS[4]=1;
    }
    else if((i==2)&&(j==6)){
        ID_Cree= 9;
        K_i= Init_Case(K_i, ID_Cree);
        K_i.IRXYFJDHBGTS[4]=1;
    }
    else if((i==4)&&(j==0)){
        ID_Cree=7 ;
        K_i= Init_Case(K_i, ID_Cree);
        K_i.IRXYFJDHBGTS[4]=1;
    }
    else if((i==4)&&(j==2)){
        ID_Cree=6 ;
        K_i= Init_Case(K_i, ID_Cree);
        K_i.IRXYFJDHBGTS[4]=1;
    }
    else if((i==4)&&(j==4)){
        ID_Cree= 9;
        K_i= Init_Case(K_i, ID_Cree);
        K_i.IRXYFJDHBGTS[4]=1;
    }
    else if((i==4)&&(j==6)){
        ID_Cree= 9;
        K_i= Init_Case(K_i, ID_Cree);
        K_i.IRXYFJDHBGTS[4]=1;
    }
    else if((i==6)&&(j==0)){
        ID_Cree= 2;
        K_i= Init_Case(K_i, ID_Cree);
        K_i.IRXYFJDHBGTS[11]=3;
        K_i.IRXYFJDHBGTS[4]=1;
    }
    else if((i==6)&&(j==2)){
        ID_Cree= 6;
        K_i= Init_Case(K_i, ID_Cree);
        K_i.IRXYFJDHBGTS[4]=1;
    }
    else if((i==6)&&(j==4)){
        ID_Cree= 6;
        K_i= Init_Case(K_i, ID_Cree);
        K_i.IRXYFJDHBGTS[4]=1;
    }
    else if((i==6)&&(j==6)){
        ID_Cree=5 ;
        K_i= Init_Case(K_i, ID_Cree);
        K_i.IRXYFJDHBGTS[11]=4;
        K_i.IRXYFJDHBGTS[4]=1;
    }
    else {
        ID_Cree=10 ;
        K_i= Init_Case(K_i, ID_Cree);
        K_i.IRXYFJDHBGTS[4]=0;
    }
    K_i= direction_Possible(K_i);
T.Matrice[i][j]=K_i;
}}
    return T;
}
/* Affiche un tableau T*/
void affiche_Tableau(tableau T){
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++){
            /*affiche_Case(T.Matrice[i][j]);*/
            printf("Case (%d,%d), type: %d rota:%d ID :", T.Matrice[i][j].IRXYFJDHBGTS[2], T.Matrice[i][j].IRXYFJDHBGTS[3], T.Matrice[i][j].IRXYFJDHBGTS[0], T.Matrice[i][j].IRXYFJDHBGTS[1]);
            for (int k=0; k<12; k++){
                printf("%d  ",T.Matrice[i][j].IRXYFJDHBGTS[k]);
            }
            printf("\t \n");
        }
        printf("\n");
    }
    printf("\nCase restante:\n");
    affiche_Case(T.restante);
}
/* initialise un tableau vide et le rempli de case selon son itérateur (nb determiné de case de type K)*/
tableau init_Tableau(){
    int Rand_Case, NBL, NBT, NBI, NBTot, Chargement, TypeK;
    tableau T;
    Cases K_i;
    srand(time(NULL));
    T = Init_Tableau_Fixe();
    NBI=12;
    NBL=16;
    NBT=6;
    Chargement=0;
    for (int i=0; i<7; i++){
        for(int j=0;j<7;j++){
            if (T.Matrice[i][j].IRXYFJDHBGTS[4]==0){
                Rand_Case=rand();
                Rand_Case=Rand_Case%3;
                /*Choisi le type de Case à utiliser de manière aléatoire*/
                switch (Rand_Case) {
                    case 0:{
                        TypeK=1;
                        NBI--;
                    }
                    case 1:{
                        TypeK=2;
                        NBL--;
                    }
                    case 2:{
                        TypeK=3;
                        NBT--;
                    }
                }
                K_i=Creation_Auto(TypeK, i, j, K_i);
                T.Matrice[i][j]=K_i;
            }
            Chargement=(((Chargement+1)/49)*100);
            printf("Chargement tableau %d %", Chargement);
        }
    }
    NBTot=(NBL+NBT+NBI);
    if(NBTot==1){
        printf("Initialisation Case restante");
        if(NBI==1){
            TypeK=1;
            K_i=Creation_Auto(TypeK, 8, 8, K_i);
            T.restante=K_i;

        }
        else if(NBT==1){
            TypeK=3;
            K_i=Creation_Auto(TypeK, 8, 8, K_i);
            T.restante=K_i;
        }
        else if(NBL==1){
            TypeK=1;
            K_i=Creation_Auto(TypeK, 8, 8, K_i);
            T.restante=K_i;
        }
        T.restante.IRXYFJDHBGTS[11]=0;
        T.restante.IRXYFJDHBGTS[10]=0;
        T.restante.IRXYFJDHBGTS[5]=0;
        T.restante.IRXYFJDHBGTS[4]=0;
    }
    else{
        printf("Erreur de Generation du tableau");
    }
    affiche_Tableau(T);
    return T;
}

