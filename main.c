#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Etudiant{
    char matricule[20];
    char nom[100];
    char prenom[100];
    float moyenne;
}Etudiant;
 typedef struct entete_fichier{
   size_t file_size;
   char file_name[100];
   char file_extension[30];
   int nb_element;
 }entete_fichier;
typedef struct block_entete{
    size_t block_size;
    int nb_block_element;
    int facteur_blockage;
    char data_type[50];
}block_entete;



void read_element(Etudiant x){

    printf("matricule) : %s \n",x.matricule);
    printf("nom / prenom : %s / %s \n",x.nom,x.prenom);
    printf("moyenne : %s \n",x.moyenne);
}

void search (char *file_path, char *mat){
    FILE *fic=fopen(*file_path,"rb");
    entete_fichier Ftete;
    fread(&Ftete,sizeof(entete_fichier),1,fic);
    Etudiant T[Ftete.nb_element]; 
    block_entete Tbloc;
    int trouver =0,  i=0 ,c ,j;
    while(fread(&Tbloc,sizeof(block_entete),1,fic)> 0 && trouver == 0){
        if(Tbloc.nb_block_element!=0){
            fread(T+i,sizeof(Etudiant),Tbloc.nb_block_element,fic){
                c=Tbloc.nb_block_element;
                j=i;
                while(c>0 && trouver==0){
                    if(strcmp(T[j].matricule,mat)==0){
                        trouver=1;
                        read_element(t[j]);
                    }j++;  c--;
                    }
               i=i+Tbloc.nb_block_element;     



            }




        }




    }
   





}












int main(){

  
   


    return 0;
}