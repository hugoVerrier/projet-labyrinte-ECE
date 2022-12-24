Cases Menu_Case(){
    int choix;
    Cases K;
    printf("Creation et modification de Case: \n 1-Tableau  \n 0-Quitter \n");
    scanf("%d",&choix);
    switch (choix) {
        case 1:{
            K=Creation_Case(K);
            printf("\nVoulez vous continuer?\n 1- Tableau \n 2- Id-Info\n 0 quitter\n");
            scanf("%d",&choix);
        }
        default:{
            printf("Sortie du Menu Case");
            break;
        }
    }
    return K;
}

Cases Creation_Case(Cases K){
    int Auto, ID_Case;
    printf("Voulez vous initialiser la case : \n 0- Manuellement \n 1- Automatiquement");
    scanf("%d",&Auto);
    switch (Auto){
        /* initialise une case automatiquement mais rempli l'ID semi manuellement*/
        case 1:{
            ID_Case=ID_Creation(Auto);
            K=Init_Case(K, ID_Case);
            K= Cases_Completion(K);
            affiche_Case(K);
            break;
        }
        /*initialise une case manuellement*/
        case 0:{
            ID_Case=ID_Creation(Auto);
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
            K.IRXYFJDHBGT[0]=1;
            K.IRXYFJDHBGT[1]=1;
            break;
        }
        case 1:{/* I-2*/
            K.Tab[1][0]=1;
            K.Tab[1][2]=1;
            K.IRXYFJDHBGT[0]=1;
            K.IRXYFJDHBGT[1]=2;
            break;
        }
        case 2:{/* L-1*/
            K.Tab[0][1]=1;
            K.Tab[1][2]=1;
            K.IRXYFJDHBGT[0]=2;
            K.IRXYFJDHBGT[1]=1;
            break;
        }
        case 3:{/* L-2*/
            K.Tab[2][1]=1;
            K.Tab[1][2]=1;
            K.IRXYFJDHBGT[0]=2;
            K.IRXYFJDHBGT[1]=2;
            break;
        }
        case 4:{/* L-3*/
            K.Tab[2][1]=1;
            K.Tab[1][0]=1;
            K.IRXYFJDHBGT[0]=2;
            K.IRXYFJDHBGT[1]=3;
            break;
        }
        case 5:{/* L-4*/
            K.Tab[0][1]=1;
            K.Tab[1][0]=1;
            K.IRXYFJDHBGT[0]=2;
            K.IRXYFJDHBGT[1]=4;
            break;
        }
        case 6:{/* T-1*/
            K.Tab[0][1]=1;
            K.Tab[1][2]=1;
            K.Tab[1][0]=1;
            K.IRXYFJDHBGT[0]=3;
            K.IRXYFJDHBGT[1]=1;
            break;
        }
        case 7:{
            /* T-2*/
            K.Tab[0][1]=1;
            K.Tab[1][2]=1;
            K.Tab[2][1]=1;
            K.IRXYFJDHBGT[0]=3;
            K.IRXYFJDHBGT[1]=2;
            break;
        }
        case 8:{
            /* T-3*/
            K.Tab[1][0]=1;
            K.Tab[1][2]=1;
            K.Tab[2][1]=1;
            K.IRXYFJDHBGT[0]=3;
            K.IRXYFJDHBGT[1]=3;
            break;
        }
        case 9:{
            /* T-4*/
            K.Tab[0][1]=1;
            K.Tab[2][1]=1;
            K.Tab[1][0]=1;
            K.IRXYFJDHBGT[0]=3;
            K.IRXYFJDHBGT[1]=4;
            break;
        }
    }
    printf("Initialisation de la case..;\n");
    return K;
}
/*print de la case seulement après avoir fait la case complete*/
void affiche_Case(Cases K){
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++){
            printf("%d  ", K.Tab[i][j]);
        }
        printf("\n");
    }
    for(int k=0;k<11;k++){
        printf("%d\t",K.IRXYFJDHBGT[k]);
    }
}
/*utilise le tableau de la case et rempli l'id selon les directions possible*/
Cases direction_Possible(Cases K){
    if (K.Tab[1][0]==1){
        K.IRXYFJDHBGT[9]=1;
        printf("Gauche ");
    }
    if (K.Tab[0][1]==1){
        K.IRXYFJDHBGT[7]=1;
        printf("Haut ");
    }
    if (K.Tab[2][1]==1){
        K.IRXYFJDHBGT[8]=1;
        printf("Bas ");
    }
    if (K.Tab[1][2]==1){
        K.IRXYFJDHBGT[6]=1;
        printf("Droite  ");
    }
    if (K.Tab[1][0]==0){
        K.IRXYFJDHBGT[9]=0;
        printf("Non Gauche ");
    }
    if (K.Tab[0][1]==0){
        K.IRXYFJDHBGT[7]=0;
        printf("Non Haut ");
    }
    if (K.Tab[2][1]==0){
        K.IRXYFJDHBGT[8]=0;
        printf("Non Bas ");
    }
    if (K.Tab[1][2]==0){
        K.IRXYFJDHBGT[6]=0;
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
    K.IRXYFJDHBGT[2]=X;
    K.IRXYFJDHBGT[3]=Y;
    if ((X%2==0)&&(Y%2==0)){
        K.IRXYFJDHBGT[4]=1;
    }
    else{
        K.IRXYFJDHBGT[4]=0;
    }
    printf("Le joueur est il present?");
    scanf("%d", &Psc);
    K.IRXYFJDHBGT[5]=Psc;
    K=direction_Possible(K);
    printf("Tresor?");
    scanf("%d",&trez);
    K.IRXYFJDHBGT[10]=trez;
    printf("Completion de la case...\n");
    return K;
}
/*Cree un ID Case pour pouvoir initier une case selon les modèles disponible*/
int ID_Creation(int Auto){
    int ID_Crea;
    if (Auto==1){
        srand(time(NULL));
        int Random, ID_Creation;
        Random=rand();
        ID_Crea = Random%10;
    }
    else if(Auto==0){
        int TypeK, RotaK;
        printf("Quel case voulez vous créer? : \n1- I \n2- L \n3- T\n");
        scanf("%d", &TypeK);
        switch (TypeK) {
            case 1:{
                printf("I- Choisissez la rotation entre 1 et 2\n");
                scanf("%d",&RotaK);
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
                printf("L- Choisissez la rotation entre 1 et 4\n");
                scanf("%d",&RotaK);
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
                printf("T- Choisissez la rotation entre 1 et 4\n");
                scanf("%d",&RotaK);
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
    }
    printf("Creation de l'ID de la case...\n");
    return ID_Crea;
}
