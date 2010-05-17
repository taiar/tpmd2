#include <stdio.h>
#include <string.h>
#include "lista.h"
 
//Lista global, apenas para deixar o código sem muitos parâmetros.
lista list;
 
/*Registro de um cliente*/
typedef struct{
 unsigned int id;
 char name[64];
 char email[64];
} TRegister;
 
void insertRegister(unsigned int id, char *name, char *email)
{
 TRegister reg;
  
 reg.id = id;
 strcpy(reg.name, name);
 strcpy(reg.email, email);
 listaInsere(&list, (void *) &reg, sizeof(TRegister));
}
 
void printRegister(TRegister *reg)
{
 if (reg == NULL){
  printf("Registro inválido!\n\n");
  return;
 }
  
 printf("|Registro %u\n",  reg->id);
 printf("|-Nome:   %s\n",    reg->name);
 printf("|-E-mail: %s\n\n", reg->email);
}
 
/*
  Função que compara um nome com um registro.
  Utilizada como parâmetro para retrieveData.
*/
int compare(void *reg, void *name)
{
 if (strcmp(((TRegister *)reg)->name, name) == 0)
  return 1;
 return 0;
}
 
/*Fim Registro de um cliente*/
 
int main()
{
 TRegister *reg;
  
 listaCria(&list);
  
 //Insere alguns registros na lista.
 insertRegister(1, "Fernanda Lara dos Santos", "flara@eita.com.br");
 insertRegister(2, "Valéria Pereira Souza", "valeria@oloco.com.br");
 insertRegister(3, "Pedro Malta Ribeiro", "thenerd666@devil.com");
 insertRegister(4, "João Henrique Pato", "joaoh@foble.com");
  
 //Procura por João e imprime os seus dados.
 reg = listaRetorna(&list, compare, (void *) "João Henrique Pato");
 printRegister(reg);
  
 //Procura por Fernanda e imprime os seus dados.
 reg = listaRetorna(&list, compare, (void *) "Fernanda Lara dos Santos");
 printRegister(reg);
  
 //Remove João.
 listaRemove(&list, compare, (void *) "João Henrique Pato");
  
 //Procura novamente por João, que não mais existe na lista.
 reg = listaRetorna(&list, compare, (void *) "João Henrique Pato");
 printRegister(reg);
  
 //Procura por Pedro.
 reg = listaRetorna(&list, compare, (void *) "Pedro Malta Ribeiro");
 printRegister(reg);
  
 listaFree(&list);
 return 0;
}
