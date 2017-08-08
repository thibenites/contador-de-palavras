/* Contador de palavras
Este programa recebera uma serie de caracteres representando palavras em sua entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>

int letra(char c);
int strlenght(char *str);
int main() {

  char c[1000];
  int i, lenght, words;

  i = 0;
  words = 0;
  
  scanf("%[^\n]s", c);
  
  lenght = strlenght(c);
  
  for(i=0; i<(lenght+1); i++){  //checa cada caracter para saber se é uma letra/número ou não
    if(letra(c[i]) == 1){   //se for uma letra não faz nada
        //do nothing
    }
    else if(letra(c[i]) == 2){  //se for um número não faz nada
        //do nothing
    }
    else{   //caso seja algo diferente de letra ou numero faz testes para saber se deve contabilizar a palavra
        if((letra(c[i-1]) != 1) && (letra(c[i-1]) != 2)){   //se o caracter anterior já for algo diferente de letra/nº, nada é feito
            //do nothing
        }
        else if((letra(c[i-1]) == 2) && (letra(c[i+1]) == 2)){  //se o caracter anterior e próximo forem números, indica ponto flutuante
            //do nothing
        }
        else{   //se chegou até aqui, contabiliza uma palavra a mais
            words++;
        }
    }
  }
  
  printf("%d\n", words);

  return 0;
}

int letra(char c){  //função que determina se a char é uma letra/numero ou não
    int x = 0;
    
    if(((c > 64) && (c < 91)) || ((c > 96) && (c < 123))){   //letra
        x = 1;
    }
    else if((c > 47) && (c < 58)){  //número
        x = 2;
    }
    else{
        x = 0;
    }
    
    return x;    
}

int strlenght(char *str){   //função que determina o tamanho da string
    int i = 0;
    
    while(str[i] != '\0'){
        i++;
    }
    
    return i;
}
