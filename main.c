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
 // rani bdlt hna knt ghalt f l asmm 


typedef struct block_entete{
    size_t block_size;
    int nb_block_element;
    int facteur_blockage;
    char data_type[50];
}block_entete;

void insertion_block (char *file_path, Etudiant *T ,int facteur_blockage,n){
    FILE *file= fopen(file_path,"r+b");
    fseek(file,0,SEEK_END);
    block_entete block;
    entete_fichier entete;
    strcpy(block.data_type,"Etudiant");
    block.facteur_blockage=facteur_blockage;
    void *buffer;
    for (int i =0 ;i < n ; i=i+facteur_blockage){
        int facteur;
        if (i + facteur_blockage > n ){
            facteur= facteur_blockage
             while (i + facteur > n ) 
        {
           facteur--;    
        } 
        block.nb_block_element= facteur;
        }
        else{
            facteur=facteur_blockage;
            block.nb_block_element=facteur_blockage;

        }
        
       


        
    }

}












int main(){

  
   


    return 0;
}