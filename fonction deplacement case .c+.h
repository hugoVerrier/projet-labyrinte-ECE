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
// Fonction de deplacement des cases sur une colonne donnée en fonction de son sens
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
tableau Deplacement_Case(tableau T /* input*/){
    int input, CoorX=0, CoorY=0, sens;
    printf("Comment voulez vous insérer la case restante? 1- Horizontalement 2- Verticalement :\n");
    scanf("%d", &input);
    switch (input) {
        //Utilise l'input du clavier pour demander au joueur ou il veut deplacer sa case
        case 1:{
            /* IL FAUT CHANGER L'INPUT AFIN D'ETRE ADAPTE A LA SAISIE CLAVIER
             while (input != enter){
                 sens=0;
            while((CoorY>=0)&&(CoorY<=6)){
            if(input KeyUP){
            CoorY++;
            }
            else if(input KeyDOWN){
                CoorY--;
             }
             else if((input KeyUP)&&(CoorY==0)){
                CoorY==0;
             }
             else if((input KeyDOWN)&&(CoorY==6)){
                CoorY==6;
             }
             if(input KeyLEFT){
             sens=-1;
             }
             else if(input KeyRIGHT){
             sens=1;
             }
             }
            }
            T = Deplacement_Case_X(sens, CoorY, T);
            break;*/
        }
        case 2:{
            /* Meme Chose
            while (input != enter){
                sens=0;
                while((CoorX>=0)&&(CoorX<=6)){
                    if(input KeyRIGHT){
                        CoorX++;
                    }
                    else if(input KeyLEFT){
                        CoorX--;
                    }
                    else if((input KeyLEFT)&&(CoorX==0)){
                        CoorX==0;
                    }
                    else if((input KeyRIGHT)&&(CoorX==6)){
                        CoorX==6;
                    }
                    if(input KeyUP){
                        sens=-1;
                    }
                    else if(input KeyUP){
                        sens=1;
                    }
                }
            }
            T = Deplacement_Case_Y(sens, CoorX, T);
            break;
             */}
        default:{
            printf("Veuillez insérer un mouvement valide");
            scanf("%d",&input);
        }
    }
    return T;
}


// .h associé 
tableau Deplacement_Case_X(int sens, int CoorY, tableau T);
tableau Deplacement_Case_Y(int sens, int CoorX, tableau T);
tableau Deplacement_Case(tableau T);
