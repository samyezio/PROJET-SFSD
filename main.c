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

void creefichier(char *nomfichier,char *extension){
    char *nomfichiercomplet=malloc(strlen(name) + strlen(extension)+2);
    strcpy(nomfichiercomplet,nomfichier);
    strcpy(nomfichiercomplet,extension);
    FILE *fichier=fopen(nomfichiercomplet,"wb");
    entete_fichier entete;
    strcpy(entete.file_name,nomfichier);
    strcpy(entete.file_extension,extension);
    entete.file_size=sizeof(entete_fichier);
    entete.nb_element=0;
    fwrite(&entete,sizeof(entete_fichier),1,fichier);
    fclose(fichier);
    free(nomfichiercomplet);

}






















void insertion_block (char *file_path, Etudiant *T ,int facteur_blockage, int n){
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
        block.block_size = sizeof(Etudiant) * facteur_blockage;
        size_t block_memory_size = sizeof(block_header) + block.block_size;
        buffer = malloc(block_memory_size);
        memcpy( buffer , &block , sizeof(block_header) );
        memcpy (buffer + sizeof (block_header),(Etudiant *)T+i,sizeof (Etudiant)*facteur);
        fwrite (buffer,block_memory_size,1,file);
        free(buffer);
        
    }

}



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
   
   /*void supprimer(char *file_path,char *mat){
   FILE *fichier = fopen(file_path,"r+b"); //ouvrir le fichier en mode lecture ecriture binaire.
   struct entete_fichier entete;
   struct block_entete block;
   fread(&entete,sizeof(entete_fichier),1,fichier); //recuperer l'entete de notre fichier (les informations).
   struct Etudiant T[entete.nb_element];  //un tableau pour stocker les enregistrement .


   }*/




}


int main ()
{

    return 0 ;
}
