//
// Created by Pas un taille crayon on 14/12/2022.
//

#include "VrmtVrmtTriste.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// FONCTIONS MENU CREATION

// Fonction de Création de Case à partir d'un menu
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
    // Crée un randomiseur qui va donner une case aléatoire selon une rotation aléatoire mais un type donné
    Randomizer=rand();
    RotaK=Randomizer%5;
    if (RotaK==0){RotaK+=1;}
    ID_temp = ID_Creation(1, TypeK, RotaK);
    K=Init_Case(K, ID_temp);
    K=direction_Possible(K);
}
// Crée une case manuellement selon son type et sa rotation - potentiellement obsolète
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
        /*initialise une case manuellement en donnant le type de la case puis sa rotation*/
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

// FONCTIONS DE CREATION DE CASE

/*initialise une case selon son id_ID, et rempli l'id I et sa rotation (utile pour l'affichage des cases sur le plateau)*/
Cases Init_Case(Cases K,int ID_Case){
//initie d'abord une case vide
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if ((i==1)&&(j==1)){
                K.Tab[i][j]=1;}
            else{
                K.Tab[i][j]=0;
            }
        }
    }
    // Modifie la Case vide et lui donne une formation prédéfini selon l'ID case en paramètre
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
            //permet d'initié une case vide si jamais
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
//La fonction a été modifié afin de pouvoir donné un ID création initié selon le type et la rotation
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

// FONCTIONS DEPLACEMENT JOUEUR ET ACTUALISATION TABLEAU / JOUEUR

// Determine le nombre de deplacement possible pour un joueur dans ses alentours
int nb_Mvt_Possible(tableau T, Joueur J){
    Cases K_D, K_G, K_H, K_B, K_Actu;
    int Dep;
    //Determine d'abord les cases aux alentour du joueur
    K_D=T.Matrice[J.y][J.x+1];
    K_G=T.Matrice[J.y][J.x-1];
    K_B=T.Matrice[J.y+1][J.x];
    K_H=T.Matrice[J.y-1][J.x];
    K_Actu=T.Matrice[J.y][J.x];
    // Rend le nombre de deplacement possible dans les alentours de la case actuelle
    if ((K_Actu.IRXYFJDHBGTS[6]==1)&&(K_D.IRXYFJDHBGTS[9]==1)){
        Dep++;
    }
    else if ((K_Actu.IRXYFJDHBGTS[9]==1)&&(K_G.IRXYFJDHBGTS[6]==1)){
        Dep++;
    }
    else if ((K_Actu.IRXYFJDHBGTS[7]==1)&&(K_H.IRXYFJDHBGTS[8]==1)){
        Dep++;
    }
    else if ((K_Actu.IRXYFJDHBGTS[8]==1)&&(K_B.IRXYFJDHBGTS[7]==1)){
        Dep++;
    }
    return Dep;
    //Le nombre de mouvement est différent de la possibilité de mouvement et permettra de détecter un cul de sac
}
// Determine si le mouvement est possible pour un joueur selon l'input
int Dir_Actu_Poss(tableau T, Joueur J, int input){
    Cases K_D, K_G, K_H, K_B, K_Actu;
    int Dep;
    //Cases aux alentours
    K_D=T.Matrice[J.y][J.x+1];
    K_G=T.Matrice[J.y][J.x-1];
    K_B=T.Matrice[J.y+1][J.x];
    K_H=T.Matrice[J.y-1][J.x];
    K_Actu=T.Matrice[J.y][J.x];
    // Prend l'input et compare les directions pour vérifier l'egibilité du mouvement
    if((input=='A')&&(K_Actu.IRXYFJDHBGTS[7]==1)&&(K_H.IRXYFJDHBGTS[8]==1)){
        Dep++;
    }
    else if((input=='B')&&(K_Actu.IRXYFJDHBGTS[8]==1)&&(K_B.IRXYFJDHBGTS[7]==1)){
        Dep++;
    }
    else if((input=='C')&&(K_Actu.IRXYFJDHBGTS[6]==1)&&(K_D.IRXYFJDHBGTS[9]==1)){
        Dep++;
    }
    else if((input=='D')&&(K_Actu.IRXYFJDHBGTS[9]==1)&&(K_G.IRXYFJDHBGTS[6]==1)){
        Dep++;
    }
    return Dep;
    //Ici la fonction rendra 0 ou 1 car elle permet de verifier le mouvement pour un input determiné soit une direction prédeterminée
}
// Permet au joueur de se déplacer jusqu'à ce que le joueur rentre dans un cul de sac
tableau Deplacement_joueur(tableau T, Joueur J){
    int Dep_Prec=4, Dep_Actu, Dir_Poss;
    int input=getchar();
    Dep_Actu= nb_Mvt_Possible(T, J);
    // Deplacement jusqu'a la fin du tour determiné par la touche entrer ou un cul de sac
    //Theoriquement le cul de sac est determiné par le nombre de deplacement precedent et de la case actuelle, si la case à un seul deplacement possible c'est que le joueur est dans un cul de sac
    //Afin que le joueur ne soit pas bloquer dès le début le 1er deplacement precedent est initialiser a 4
    while(input!='\n'){
        while((Dep_Prec>=1)&&(Dep_Actu!=1)){
            Dir_Poss= Dir_Actu_Poss(T,J,input);
            if(Dir_Poss==1){
                //Modifie le tableau selon le mouvement du joueur
                if(input=='A'){
                T.Matrice[J.y-1][J.x].IRXYFJDHBGTS[5]=T.Matrice[J.y][J.x].IRXYFJDHBGTS[5];
                T.Matrice[J.y][J.x].IRXYFJDHBGTS[5]=0;
                }
                else if(input=='B'){
                    T.Matrice[J.y+1][J.x].IRXYFJDHBGTS[5]=T.Matrice[J.y][J.x].IRXYFJDHBGTS[5];
                    T.Matrice[J.y][J.x].IRXYFJDHBGTS[5]=0;}
                else if(input=='C'){
                    T.Matrice[J.y][J.x+1].IRXYFJDHBGTS[5]=T.Matrice[J.y][J.x].IRXYFJDHBGTS[5];
                    T.Matrice[J.y][J.x].IRXYFJDHBGTS[5]=0;}
                else if(input=='D'){
                    T.Matrice[J.y][J.x-1].IRXYFJDHBGTS[5]=T.Matrice[J.y][J.x].IRXYFJDHBGTS[5];
                    T.Matrice[J.y][J.x].IRXYFJDHBGTS[5]=0;}
                Dep_Prec=Dep_Actu;
                Dep_Actu= nb_Mvt_Possible(T,J);
                // Actualise le joueur et le plateau si un tresor est présent et si il correspond à un des tresors cherche étant donné que les coordonées du joueur ne changent pas toutes seules
                J= Actu_Joueur(T,J);
                if(T.Matrice[J.y][J.x].IRXYFJDHBGTS[10]>0){
                    T= Actu_Trez_Tableau(T, J);
                }
            }
        }
    }
    return T;
}
// Actualise les coordonnées d'un joueur( et son deck de trésor )?
Joueur Actu_Joueur(tableau T, Joueur J){
    int i, j;
    for (i=0;i<7;i++){
        for(j=0;j<7;j++){
            if(T.Matrice[i][j].IRXYFJDHBGTS[5]==J.nbJoueur){
                J.x=j;
                J.y=i;
            }
        }
    }
    if(T.Matrice[J.y][J.x].IRXYFJDHBGTS[10]>0) {
        J = Recuperation_Trez(T, J);
    }
    return J;
}
// Actualise le tableau pour faire disparaitre les trésors recupérer
tableau Actu_Trez_Tableau(tableau T, Joueur J){
    for(int i=0;i<8;i++){
        if(J.TresorDeck[i]==T.Matrice[J.y][J.x].IRXYFJDHBGTS[10]){
            T.Matrice[J.y][J.x].IRXYFJDHBGTS[10]=0;
        }
    }
    return T;
}

// FONCTIONS INITIALISATION TABLEAU

/*initialisation d'un tableau vide avec uniquement les cases fixes et complète son ID sans joueurs ni tresor*/
tableau Init_Tableau_Fixe(){
    int ID_Cree, i, j;
    Cases K_i;
    tableau T;
    printf("Case fixe generation..");
    //Initie L'id afin que les joueurs ne soient pas malplacés et que le tableau soit initié vide
    for (i=0;i<7;i++){
        for (j=0;j<7;j++){
            K_i.IRXYFJDHBGTS[2]=i;
            K_i.IRXYFJDHBGTS[3]=j;
            K_i.IRXYFJDHBGTS[11]=0;
            K_i.IRXYFJDHBGTS[10]=0;
            K_i.IRXYFJDHBGTS[5]=0;
     // initie chaque case fixe de manière prédéterminé en parcourant le tableau entier
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
/* Affiche un tableau T - obsolete*/
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
/* initialise un tableau vide et le rempli de case selon son itérateur (nb determiné de case de type K) - obsolete*/
tableau init_Tableau(){
    int Rand_Case, NBL, NBT, NBI, NBTot, Chargement, TypeK;
    tableau T;
    Cases K_i;
    srand(time(NULL));
    T = Init_Tableau_Fixe();
    // crée un nombre prédéterminé de case selon leur type et les randomise dans le plateau
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
    //Cherche le type de la case restante et la stock dans le tableau
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

// FONCTIONS DEPLACEMENT DE CASES

// Fonction de deplacement des cases sur une ligne donnée en fonction de son sens à partir d'une case de sauvegarde
tableau Deplacement_Case_X(int sens, int CoorY, tableau T){
    int i;
    Cases K_Save;
    switch (sens) {
        case 1:{
            K_Save=T.Matrice[CoorY][6];
            for (i=0;i<6;i++){
                T.Matrice[CoorY][i+1]=T.Matrice[CoorY][i];
            }
            T.Matrice[CoorY][0]=T.restante;
            T.restante=K_Save;
            break;
        }
        case -1:{
            K_Save=T.Matrice[CoorY][0];
            for (i=0;i<6;i++){
                T.Matrice[CoorY][i]=T.Matrice[CoorY][i+1];
            }
            T.Matrice[CoorY][6]=T.restante;
            T.restante=K_Save;
            break;
        }
    }
    printf("Deplacement des Cases sur la ligne %d dans le sens %d", CoorY, sens);
    return T;
}
// Fonction de deplacement des cases sur une colonne donnée en fonction de son sens à partir d'une case de sauvegarde
tableau Deplacement_Case_Y(int sens, int CoorX, tableau T){
    int i;
    Cases K_Save;
    switch (sens) {
        case 1:{
            K_Save=T.Matrice[6][CoorX];
            for (i=0;i<6;i++){
                T.Matrice[i+1][CoorX]=T.Matrice[i][CoorX];
            }
            T.Matrice[0][CoorX]=T.restante;
            T.restante=K_Save;
            break;
        }
        case -1:{
            K_Save=T.Matrice[0][CoorX];
            for (i=0;i<6;i++){
                T.Matrice[i][CoorX]=T.Matrice[i+1][CoorX];
            }
            T.Matrice[6][CoorX]=T.restante;
            T.restante=K_Save;
            break;
        }
    }
    printf("Deplacement des Cases sur la colonne %d dans le sens %d", CoorX, sens);
    return T;
}
// Utilise les 2 fonctions précédente pour que le joueur puisse choisir l'insertion de la case restante à sa guise dans tous les sens possible
tableau Deplacement_Case(tableau T ){
    int CoorX=0, CoorY=0, sens;
    printf("Comment voulez vous insérer la case restante? 1- Horizontalement 2- Verticalement :\n");
    int input=getchar();
    switch (input) {
        //Utilise l'input du clavier pour demander au joueur ou il veut deplacer sa case
        case 1:{
            // A = up B = down C= right D=left
             while (input !='\n'){
                 sens=0;
            while((CoorY>=0)&&(CoorY<=6)){
            if(input=='A'){
            CoorY++;
            }
            else if(input=='B'){
                CoorY--;
             }
             else if((input=='A')&&(CoorY==0)){
                CoorY=0;
             }
             else if((input =='B')&&(CoorY==6)){
                CoorY=6;
             }
             if(input=='D'){
             sens=-1;
             }
             else if(input =='C'){
             sens=1;
             }
             }
            }
            T = Deplacement_Case_X(sens, CoorY, T);
            //Déplace le joueur d'une partie du plateau à l'autre si il est à l'extremité du plateau et est éjécté par le deplacemetn des cases
            if ((sens==1)&&(T.Matrice[CoorY][6].IRXYFJDHBGTS[5]>=1)){
                T.Matrice[CoorY][0].IRXYFJDHBGTS[5] = T.restante.IRXYFJDHBGTS[5];
                T.restante.IRXYFJDHBGTS[5]=0;
            }
            else if((sens==-1)&&(T.Matrice[CoorY][0].IRXYFJDHBGTS[5]>=1)){
                T.Matrice[CoorY][6].IRXYFJDHBGTS[5] = T.restante.IRXYFJDHBGTS[5];
                T.restante.IRXYFJDHBGTS[5]=0;
            }
            break;
        }
        case 2:{

            while (input != '\n'){
                sens=0;
                while((CoorX>=0)&&(CoorX<=6)){
                    if(input=='C'){
                        CoorX++;
                    }
                    else if(input=='D'){
                        CoorX--;
                    }
                    else if((input=='D')&&(CoorX==0)){
                        CoorX=0;
                    }
                    else if((input=='C')&&(CoorX==6)){
                        CoorX=6;
                    }
                    if(input=='A'){
                        sens=-1;
                    }
                    else if(input=='B'){
                        sens=1;
                    }
                }
            }
            T = Deplacement_Case_Y(sens, CoorX, T);
            //Deplace le joueur d'une partie du plateau à l'autre
            if ((sens==1)&&(T.Matrice[6][CoorX].IRXYFJDHBGTS[5]>=1)){
                T.Matrice[0][CoorX].IRXYFJDHBGTS[5] = T.restante.IRXYFJDHBGTS[5];
                T.restante.IRXYFJDHBGTS[5]=0;
            }
            else if((sens==-1)&&(T.Matrice[0][CoorX].IRXYFJDHBGTS[5]>=1)){
                T.Matrice[6][CoorX].IRXYFJDHBGTS[5] = T.restante.IRXYFJDHBGTS[5];
                T.restante.IRXYFJDHBGTS[5]=0;
             }
        break;}
        default:{
            printf("Veuillez insérer un mouvement valide");
            scanf("%d",&input);
        }
    }
    return T;
}

// FONCTIONS TRESORS

//Assigne des tresors aléatoirement sur le plateau
tableau Plateau_RandTresor(tableau T){
    int rand_i, rand_j, i, j, nb_Trez=24, verif_trez;
    srand(time(NULL));
    while(nb_Trez>0) {
        //Cree des coordonées aléatoire permettant d'inité les trésors de manière aléatoire
        rand_i = rand();
        rand_j = rand();
        i = rand_i % 7;
        j = rand_j % 7;
        // Assigne des trésors sur les cases mobiles et fixes différentes des spawns jusqu'à ce que plus de tresor soit disponible.
        if ((i % 2 != 0) || (j % 2 != 0)) {
            //assigne des trésors sur les cases mobiles
            if(T.Matrice[i][j].IRXYFJDHBGTS[10]==0){
                T.Matrice[i][j].IRXYFJDHBGTS[10]=nb_Trez;
                nb_Trez--;
            }
        }
        else if((i%6!=0)&&(j%6!=0)){
            //assigne des tresors sur les cases fixes différentes des spawns
            if(T.Matrice[i][j].IRXYFJDHBGTS[10]==0){
                T.Matrice[i][j].IRXYFJDHBGTS[10]=nb_Trez;
                nb_Trez--;
            }
        }
        i=0;
        j=0;
        rand_i=0;
        rand_j=0;
    }
    //Vérifie qu'il y a bel et bien 24 tresors
    for (i=0;i<7;i++){
        for(j=0;j<7;j++){
            if(T.Matrice[i][j].IRXYFJDHBGTS[10]>0){
                verif_trez++;
            }
        }
    }
    if(verif_trez==24){
        printf("Le compte est bon");
    }
    else{
        printf("Il y a boule en trop : %d trez", verif_trez);
    }
    return T;
}
// Recuperation de tresor sur une case et adapte la liste de tresor recupérer
Joueur Recuperation_Trez(tableau T, Joueur Jul){
    int k=0;
    //cherche la place dans son tableau de tresors récuperer la place du trésor trouvé
    while(Jul.TresorRecup[k]!=0){
        k++;
    }
    // ajoute le tresor trouvé au tresors récupérer
    for(int i=0;i<8;i++){
        if(Jul.TresorDeck[i]==T.Matrice[Jul.y][Jul.x].IRXYFJDHBGTS[10]){
            Jul.TresorRecup[k]=Jul.TresorDeck[i];
        }
    }
    return Jul;
}

// FONCTIONS TOUR PAR TOUR

tableau Tour_par_Tour(tableau T, Joueur J1, Joueur J2, Joueur J3, Joueur J4, int nb_Joueur) {
    int input = getchar();
    int num_J=0;
    while (input !=/* esc*/num_J) {
        //Prend le nombre de joueurs et met les joueurs dans une boucle (avec la touche Esc en sortie) dans lequel le joueur déplace une case puis se déplace jusqu'au cul de sac
        num_J=(num_J%nb_Joueur)+1;
        switch (num_J) {
            case 1: {
                printf("%s C'est a toi de jouer", J1.pseudo);
                T= Deplacement_Case(T);
                T= Deplacement_joueur(T,J1);
                break;
            }
            case 2: {
                printf("%s C'est a toi de jouer", J2.pseudo);
                T= Deplacement_Case(T);
                T= Deplacement_joueur(T,J2);
                break;
            }
            case 3: {
                printf("%s C'est a toi de jouer", J3.pseudo);
                T= Deplacement_Case(T);
                T= Deplacement_joueur(T,J3);
                break;
            }
            case 4: {
                printf("%s C'est a toi de jouer", J4.pseudo);
                T= Deplacement_Case(T);
                T= Deplacement_joueur(T,J4);
                break;
            }
    }
        num_J++;
}
    return T;
}
