//#include <stdlib.h>
#include "no.h"

//só será criado um nó quando precisar de uma informação, por isso int i
//analogia: entrar em um vagão para poder entrar na linha do trem
//O retorno da construção é o ponteiro do nó e não a struct em si
//porque é necessário saber o endereço das structs para elas serem ligadas
s_no * constroi_no (int i){ 
    //  ponteiro novo guarda o endereço recebido = pega o endereço do espaço alocado em memoria  aloca um espaço em memória  do tamanho da struct no                                                           
    s_no * novo = (s_no *) malloc (sizeof(s_no));
    //condição para caso a alocação de memoria falhe
    if (novo != NULL){
        novo->info = i;
        novo->proximo = NULL;  
    }
    return novo; //caso ela falhe, retorna null e não constroi
}

