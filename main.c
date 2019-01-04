//
//  main.c
//  secondaprovaesamedasola
//
//  Created by Rosemarie Pirlo on 04/01/2019.
//  Copyright © 2019 Rosemarie Pirlo. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define DIMSTRINGA 25

typedef char tipoStringa[25];

enum tipoNomeVisita {oculistica, cardiologia, sangue};
enum tipoGiornoSettimana {lun, mar, mer, gio, ven};
enum tipoAmbulatorio {A, B, C};

typedef struct{
    tipoStringa nomePaziente;
    enum tipoNomeVisita nomeVisita;
    int oraInizio;
    int oraFine;
    enum tipoAmbulatorio Ambulatorio;
    enum tipoGiornoSettimana giornoSettimana;
} tipoVisita;

char *strlwr(char *str) {
    unsigned char *p = (unsigned char *) str;
    
    while (*p) {
        *p = tolower((unsigned char) *p);
        p++;
    }
    
    return str;
}

void leggiVisitaDaniele(tipoVisita* v){
    printf("dammi ora inzio visita compresa tra 9 e 18\n");
    scanf("%d", &v->oraInizio);
    
    printf("dammi ora fine visita seguente \n");
    scanf("%d", &v->oraFine);
    
    printf("dammi nome paziente\n");
    scanf("%24s", v->nomePaziente);
    
    printf("dammi tipo visita\n");
    char buffer[1024];
    scanf("%1023s", buffer);
    strlwr(buffer);
    if (!strcmp(buffer, "oculistica"))
        v->nomeVisita = oculistica;
    else if (!strcmp(buffer, "cardiologia"))
        v->nomeVisita = cardiologia;
    else if (!strcmp(buffer, "sangue"))
        v->nomeVisita = sangue;
    
    printf("dammi ambulatorio \n");
    scanf("%d", &v->Ambulatorio);
    printf("dammi giorno settimana \n");
    scanf("%d", &v->giornoSettimana);
    
    printf("inizializzato\n");
   
 }

void stampaVisita( tipoVisita *v){
   char buffer[1024];
    if (v->nomeVisita == sangue)
        strcpy(buffer, "sangue");
    else if (v->nomeVisita == cardiologia)
        strcpy(buffer, "cardiologia");
    else if (v->nomeVisita == oculistica)
        strcpy(buffer, "oculistica");
    
    printf("Il nome paziente e' %s \n", v->nomePaziente);
    printf("Il tipo visita e' %d \n", v->nomeVisita);
    printf("orario iniziale visita  %d\n", v->oraInizio);
    printf("dammi orario finale visita è %d\n", v->oraFine);
    printf("dammi ambulatorio %d\n", v->Ambulatorio);
    printf("dammi giorno settimana %d\n", v->giornoSettimana);
    
}





/* tipoVisita leggiVisita(tipoVisita v);

tipoVisita leggiVisita(tipoVisita v1){
    
    int m;
    char s[25];
    printf("dammi nome paziente\n");
    
    strcpy(v1.nomePaziente, gets(s));
    printf("dammi tipo visita\n");
    scanf("%d%*c", &m);
    v1.nomeVisita = m;
    printf("dammi orario iniziale visita\n");
    scanf("%d%*c", &m);
    if ( m>9 && m< 18)
    {
        (v1.oraInizio = m);
    }
    else
    {printf("ora iniziale non valida \n");}
    printf("orario finale  visita\n");
    scanf("%d%*c", &m);
    if ( m > v1.oraInizio && m>9 && m <18)
    {
        v1.oraFine = m;
    }
    else
    {printf("ora finale non valida \n");}
    printf("ambulatorio\n");
    scanf("%d%*c", &m);
    v1.Ambulatorio =m;
    printf("giorno settimana\n");
    scanf("%d%*c", &m);
    v1.giornoSettimana =m;
    
    return v1;
} */


void schedulaSettimana(tipoVisita tabulato[5][3]);

void schedulaSettimana(tipoVisita tabulato[5][3]){

    int i, j;
    for(i = lun; i<=ven;i++)
    {
        for (j=0; j<3; j++){
            printf("dammi SOLO impegno per esame %d\n", j);
            leggiVisitaDaniele(&tabulato[i][j]);
            
            if ( tabulato[i][j].nomeVisita != j)
                printf("sei scemo\n");

        }
   
    }
}

void stampaSettimana(tipoVisita tabulato[5][3]);
void stampaSettimana(tipoVisita tabulato[5][3]){
 
    int i, j;
    for(i = lun; i<=ven;i++)
    {
        for (j=0; j<3; j++){
            
            stampaVisita(&tabulato[i][j]);
            
        }
        
        
    }
}


int contaVisite(tipoVisita tabulato[5][3], tipoStringa nome);
int contaVisite(tipoVisita tabulato[5][3], tipoStringa nome){
    
    int cont=0;
    int i, j;
    for(i = lun; i<=ven;i++)
    {
        for (j=0; j<3; j++){
    
    if (!strcmp(tabulato[i][j].nomePaziente, nome) )
        cont++;
        }
        }
    return cont;
}

enum tipoNomeVisita patologiaCritica(tipoVisita tabulato[5][3], enum tipoAmbulatorio g);
enum tipoNomeVisita patologiaCritica(tipoVisita tabulato[5][3], enum tipoAmbulatorio g){
    
    enum tipoNomeVisita cont =0;
    int i, j, cont0 =0, cont1=0, cont2=0;
    for(i = lun; i<=ven;i++)
    {
        for (j=0; j<3; j++){
            if (tabulato[i][j].Ambulatorio == g)
            {
                switch(tabulato[i][j].nomeVisita){
                    case 0: cont0++; break;
                    case 1: cont1++; break;
                    case 2: cont2++; break;
                }

            }
        }
    }
    
    if (cont0 > cont1 && cont0 > cont2)
    {printf("il maggiore nell'ambulatorio %d è oculistica", g );
        cont = 0;}
    else {
        if (cont0 < cont1 && cont1 > cont2)
        {printf("il maggiore nell'ambulatorio %d è cardiologia", g );
            cont = 1;
        }
        else if (cont0 < cont2 && cont1 < cont2)
        { printf("il maggiore nell'ambulatorio %d è sangue", g );
            cont = 2;
    }
    }
  return cont;
}

tipoVisita Settimana(tipoVisita tabulato[5][3], enum tipoGiornoSettimana g);
tipoVisita Settimana(tipoVisita tabulato[5][3], enum tipoGiornoSettimana g){
    
    tipoVisita tabSettimana[3];
    int k=0;
    int i, j;
    for(i = lun; i<=ven;i++)
    {
        for (j=0; j<3; j++){
            if (tabulato[i][j].giornoSettimana == g)
                
            {   tabSettimana[k] = tabulato[i][j];
                k++; }
        }
    }

    return *tabSettimana;
}



void stampaArray(tipoVisita *tabSettimana);
void stampaArray(tipoVisita *tabSettimana){
    int i;
    for(i=0; i<3;i++){
        stampaVisita(tabSettimana);
    }
    
}
        
        


int main(int argc, const char * argv[]) {
    
//    tipoVisita v, z;
//    tipoVisita arch[5][3];
    /*v.oraInizio = 9;
    v.oraFine = 10;
    v.nomeVisita = sangue;*/
    char nome[25];
    tipoVisita *p;
    tipoVisita v;
    tipoVisita arch[5][3];
    leggiVisitaDaniele(&v);
   stampaVisita(&v);
    
//    e funziona
    
    
    schedulaSettimana(arch);
    stampaSettimana(arch);
    
    printf("che paziente studiamo?\n");
    gets(nome);
    contaVisite(arch, nome);
    int g;
    printf("che ambulatorio studiamo?\n");
    scanf("%d\n", &g);
    patologiaCritica(arch,g);
    printf("che giorno della settimana studiamo?\n");
    scanf("%d\n", &g);
    * p= Settimana(arch,g);
    
    stampaArray(p );
   
    /*int m;
    char s[25];
    printf("dammi nome paziente\n");
    strcpy(v.nomePaziente, gets(s));
    printf("dammi tipo visita\n");
    scanf("%d%*c", &m);
    v.nomeVisita = m;
   printf("dammi orario iniziale visita\n");
    scanf("%d%*c", &m);
    if ( m>9 && m< 18)
            {
        (v.oraInizio = m);
       }
       else
      {printf("ora iniziale non valida \n");}
        printf("dammi orario finale  visita\n");
       scanf("%d%*c", &m);
       if ( m > v.oraInizio && m>9 && m <18)
     {
      v.oraFine = m;
     }
    else
    {printf("ora finale non valida \n");}*/

// leggiVisita(v);
//    ;
//  stampaVisita(leggiVisita(v));
//    schedulaSettimana(arch);
//    stampaSettimana(arch);
    
    return 0;
}



