#ifndef PROJET_LABYRINTE_ECE_STRUCTURES_H
#define PROJET_LABYRINTE_ECE_STRUCTURES_H


typedef struct {
    int x,y,nbJoueur,couleurT,Dcase;// couleur ici permet de colorer le rectangle du joueur,Jaune=0,Bleu=1,Rouge=2,vert=3;
    char pseudo[20],couleur[6];//couleur ici srt a comparer a du text
    int TresorDeck[8],TresorRecup[8];
    Texture2D pions;
}Joueur;

typedef struct {
    int nbJoueur, nbSauvegarde;
}DonneesPartie;

typedef struct{
    int Tab[3][3];
    int IRXYFJDHBGTS[12];
    int rotation,type,tresor;
}Cases;

typedef struct{
    Cases Matrice[7][7];
    Cases restante;
}tableau;

#endif
