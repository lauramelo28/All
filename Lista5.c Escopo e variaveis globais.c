/*
10/05/22
5� Lista de exerc�cios - Modulariza��o; Procedimentos e Escopo de vari�veis
Aluna: Laura En�sia Rodrigues Melo
Turma: Eng. Software - noite
Professor: Roberto

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

int exe1();
int exe2();
int exe3();
int exe4();
int exe5();
int exe6();
int exe7();
int exe8();
int exe9();
int exe10();

int valorInt1, valorInt2;
int limite1, limite2;
float intervalo1, intervalo2;
float interv1, interv2;
char linha[50];

int main(){
    int opcao;
    do{
        printf("\n\n-----------------------------------------");
        printf("\nDigite o exercicio que deseja: ");
        scanf("%i", &opcao);

        switch (opcao){
            case 1:
               exe1();
            break;
            case 2:
                exe2();
            break;
            case 3:
                exe3();
            break;
            case 4:
                exe4();
            break;
            case 5:
                exe5();
            break;
            case 6:
                exe6();
            break;
            case 7:
                exe7();
            break;
            case 8:
                exe8();
            break;
            case 9:
                exe9();
            break;
            case 10:
                exe10();
            break;
            default:
                printf("\nOpcao invalida");
        }
    }
    while(opcao!=10);
    return 0;
}

int exe1(){
    /*1) Crie um procedimento para:
            -ler uma palavra do teclado;
            -mostrar todas as letras mai�sculas que est�o na palavra digitada.
            DICA: Definir um teste para determinar se um caractere � letra mai�scula.

    Teste: Entrada    Sa�da
            LaurA      L A

    */

    void palavraMaiuscula(){
        int i;
        char palavra[20];

        printf("\nDigite uma palavra: ");
        fflush(stdin);
        gets(palavra);

        printf("\nA palavra '%s' tem as seguintes letras maiusculas: ", palavra);

        for(i=0; palavra[i] != '\0';i++){
            if(palavra[i]>='A' && palavra[i]<='Z'){
                printf("%c ", palavra[i]);
            }
        }
    }

    palavraMaiuscula();
    return 0;
}

int exe2(){
    /*2) Crie um procedimento para:
            -ler uma palavra do teclado;
            -ler um caractere do teclado
            -transforme toda a palavra em mai�scula;
            -contar e mostrar as letras mai�sculas menores que o caractere, e quantas letras s�o maiores que o caractere, e
            quantas s�o iguais ao caractere lido

    Teste: Entrada      Sa�da
            Laura       LAURA
              z         5 menores
                        0 maiores
                        0 iguais
   OBS: O PROGRAMA COMPARA O CARACTER COM A PALAVRA MAIUSCULA
    */

        void palavraMaiuscula_Caracter(){
        int i,qtdMenorCaracter,qtdMaiorCaracter, qtdIgualCaracter;
        char palavra[20], palavraMa[20], caracter;
        qtdMenorCaracter=0;
        qtdMaiorCaracter=0;
        qtdIgualCaracter=0;

        printf("\nDigite uma palavra: ");
        fflush(stdin);
        gets(palavra);

        printf("\nDigite um caracter: ");
        fflush(stdin);
        scanf("%c", &caracter);

        printf("\nA palavra '%s' maiuscula e: ", palavra);

        for(i=0; palavra[i] != '\0'; i++){
            if(palavra[i]>='a' && palavra[i]<='z'){
                palavraMa[i]= palavra[i]-32;
            }
            else{
                palavraMa[i]= palavra[i];
            }

            if(palavraMa[i] < caracter){
                    qtdMenorCaracter++;
                }
            else{
                if(palavraMa[i] > caracter){
                    qtdMaiorCaracter++;

                }
                else{
                    qtdIgualCaracter++;
                }
            }

           // printf("%c", palavraMa[i]);
        }
        printf("%s", palavraMa);

        printf("\n");
        printf("\nTotal de letras menores que o caracter: %i", qtdMenorCaracter);
        printf("\nTotal de letras maiores que o caracter: %i", qtdMaiorCaracter);
        printf("\nTotal de letras iguais o caracter: %i", qtdIgualCaracter);
        printf("\n");
    }

    palavraMaiuscula_Caracter();
    return 0;
}

int exe3(){
    /*3) Crie um procedimento para:
        -ler uma cadeia de caracteres do teclado;
        -contar e mostrar todos s�mbolos que forem letras, ou mai�sculas ou min�sculas.

    Teste:   Entrada            Sa�da
            5caneta/*7      c a n e t a
                                 6
    */

    void qtdeCaracter(){
        int i, qtdLetra;
        char cadeia[30];
        qtdLetra=0;

        printf("\nDigite uma cadeia de caracter: ");
        fflush(stdin);
        gets(cadeia);

        printf("\nSimbolos da cadeia que sao letras: ");
        for(i=0; cadeia[i] != '\0'; i++){
            if((cadeia[i]>='A' && cadeia[i]<='Z')|| (cadeia[i]>='a' && cadeia[i]<='z')) {
                printf(" %c", cadeia[i]);
                qtdLetra++;
            }
        }
         printf("\nQuantidade de caracteres que sao letras: %i\n", qtdLetra);
    }

    qtdeCaracter();
  return 0;
}

int exe4(){
    /*4) Crie um procedimento para:
        -ler uma cadeia de caracteres do teclado;
        -contar e mostrar todos os d�gitos, percorrendo desde o fim at� o in�cio da cadeia de caracteres.

    Teste: Entrada    Sa�da
            12345     54321
                        5
    */

    void contadorDigito(){
        int i,j,qtdDigito, aux;
        char cadeia[20] ;

        printf("\nDigite uma cadeia: ");
        fflush(stdin);
        gets(cadeia);

        aux=0;
        qtdDigito=0;
        i=0;

        while (cadeia[i]!= '\0' ){
            i++;
        }

        printf("\nOs digitos em '%s' desde o fim sao: ",cadeia);
        while(i>=0){
            if(cadeia[i]>='0' && cadeia[i]<='9'){
                qtdDigito++;
                printf(" %c", cadeia[i]);
            }
            i--;
        }
        printf("\nQuantidade de digitos nessa cadeia: %i\n",qtdDigito);
    }

    contadorDigito();
    return 0;
}

int exe5(){
    /*5) Crie um procedimento para:
        - ler uma cadeia de caracteres do teclado;
        - contar e mostrar tudo o que n�o for d�gito e tamb�m n�o for letra min�scula.

    Teste:     Entrada         Sa�da
            ANA*25-gato//      ANA*-//
                                7
    */


    void cadeiaSemDig_SemLM(){
        int i, qtdCaracter;
        char cadeia[20];
        printf("\nDigite uma cadeia: ");
        fflush(stdin);
        gets(cadeia);

        i=0;
        qtdCaracter=0;
        printf("\nCadeia sem digitos e sem letras minusculas: ");
        while(cadeia[i] != '\0'){
            if( !((cadeia[i]>='a') && (cadeia[i]<='z')) && !((cadeia[i]>='0') && (cadeia[i])<='9')){
                qtdCaracter++;
                printf("%c", cadeia[i]);
            }
            i++;
        }
        printf("\nA qtd de caracteres que nao sao digitos nem letras minusculas e: %i", qtdCaracter);
    }

    cadeiaSemDig_SemLM();
    return 0;
}

int exe6(){
    /*6) Crie um procedimento para:
        - ler dois valores inteiros positivos, limites para definirem um intervalo; ( esses valores dever�o ser globais
        - ler uma quantidade de valores inteiros a serem testados �FLAG -1; um por vez;
        - contar e mostrar dentre esses valores lidos os que forem m�ltiplos de 2 e de 3, ao mesmo tempo, e perten�am ao
        intervalo.

    Teste:      Entrada                     Sa�da
                 1 20                         2
            2 6 12 15 19 -1                  6 12
    */

    void multiplo2e3(){

        int valor, qtd, numerosMultiplos[50], posicao;

        printf("\nVoce ira digitar varios valores. Caso queira parar digite '-1': ");
        printf("\nDigite um valor: ");
        scanf("%i", &valor);

        qtd=0;
        posicao=0;

        while(valor != -1){
            if(valor>=valorInt1 && valor<=valorInt2){
                if(valor%2==0 && valor%3==0){
                    numerosMultiplos[posicao++]=valor;
                    qtd++;
                }
            }
            printf("\nDigite um valor: ");
            scanf("%i", &valor);
        }

        printf("\nQtd de valores dentro dos limites e multiplos de 2 e 3: %i", qtd);
        printf("\n\nOs valores sao:");

        for(int i=0; i<qtd; i++){
            printf(" %i", numerosMultiplos[i]);
        }

    }

    printf("\nDigite o primeiro valor para o limite: ");
    scanf("%i", &valorInt1);
    printf("\nDigite o segundo valor para o limite: ");
    scanf("%i", &valorInt2);

    multiplo2e3();
    return 0;
}


int exe7(){
    /*7) Crie um procedimento para:
            - ler dois valores inteiros positivos, limites para definirem um intervalo ( esses valores dever�o ser globais)
            - ler uma quantidade de valores inteiros a serem testados;- Flag -1, um por vez;
            - contar e mostrar dentre esses valores lidos os que forem m�ltiplos de 3, que n�o forem tamb�m m�ltiplos de 5, e
            perten�am ao intervalo.

    Teste:        Entrada                     Sa�da
                   1  20                        4
            5 10 3 12 15 18 9 -1           3 12 18 9
    */

    void multiplo3eNao5(){

        int valor, qtd, vetorNumero[50], posicao;
        printf("\nVoce ira digitar varios valores. Caso queira parar digite '-1': ");
        printf("\nDigite um valor: ");
        scanf("%i", &valor);

        qtd=0;
        posicao=0;

        while(valor != -1){
            if(valor>=limite1 && valor<=limite2){
                if(valor%3==0 && valor%5!=0){
                    vetorNumero[posicao++]=valor;
                    qtd++;
                }
            }
            printf("\nDigite um valor: ");
            scanf("%i", &valor);
        }
        printf("\nQtd de numeros multiplos de 3 e nao de 5, dentro do intervalo: %i", qtd);
        printf("\n\nOs valores sao:");

        for(int i=0; i<qtd; i++){
            printf(" %i", vetorNumero[i]);
        }
    }

    printf("\nDigite o primeiro valor para o limite: ");
    scanf("%i", &limite1);
    printf("\nDigite o segundo valor para o limite: ");
    scanf("%i", &limite2);
    multiplo3eNao5();
    return 0;
}

int exe8(){
    /*8) Crie um procedimento para:
        - ler dois valores reais, o primeiro menor que o segundo, caso n�o seja emita uma mensagem de erro e pe�a novamente, para
        definirem um intervalo; ( esses valores dever�o ser globais)
        - Crie outro procedimento para:
        - ler a quantidade de valores reais a serem testados, e ler outros tantos valores quantos os indicados por essa quantidade;
        - contar e mostrar todos os valores lidos, pertencentes ao do intervalo, cujas partes inteiras forem n�meros �mpares.
        DICA: Usar conforma��o de tipo (type casting) para isolar a parte inteira (int), antes de testar se � impar
    Teste:       Entrada                     Sa�da
                   1                         qtd 3
                   20                       1 7 19
                   4
          1.65 12.99 7.658 19.4

    */


    float intervalo1, intervalo2;

    void testeValorIntervalo(){
        while(intervalo1 > intervalo2){
            printf("\nERRO!! \nO primeiro valor deve ser MENOR que o segundo valor.\n");
            printf("\nDigite novamente o primeiro valor: ");
            scanf("%f", &intervalo1);
            printf("\nDigite novamente o primeiro valor: ");
            scanf("%f", &intervalo2);
        }
    }

    void valoresReaisTestados(){
        int qtdReal,qtdPertencente, casting, vetorImpar[50], posicao;
        float valorReal;

        qtdPertencente=0;
        posicao=0;

        printf("\nDigite a quantidade dos valores reais: ");
        scanf("%i", &qtdReal);

        for(int i=0; i<qtdReal;i++){
            printf("\nDigite um valor real: ");
            scanf("%f", &valorReal);

                if(valorReal>=intervalo1 && valorReal<=intervalo2){
                    casting = (int) valorReal;
                    if((casting % 2) !=0 ){
                        vetorImpar[posicao++]=casting;
                        qtdPertencente++;
                    }
                }
        }
        printf("\nQtd de valores dentro do int. e parte inteira impar: %i", qtdPertencente);
        printf("\n\nOs valores sao:");
        for(int i=0; i<qtdPertencente; i++){
            printf(" %i", vetorImpar[i]);
        }
    }


    printf("\nDigite o primeiro valor do intervalo: ");
    scanf("%f", &intervalo1);
    printf("\nDigite o segundo valor do intervalo: ");
    scanf("%f", &intervalo2);
    testeValorIntervalo();
    valoresReaisTestados();
    return 0;
}

int exe9(){
    /*9) Crie um procedimento para:
        - ler dois valores reais, maiores que 0 e menores que 1, caso n�o seja emita uma mensagem de erro e pe�a novamente, para
        definirem um intervalo de precis�o; ; ( esses valores dever�o ser globais)
        Crie um procedimento para:
        - ler uma quantidade de valores reais a serem testados, e ler outros tantos valores quantos os indicados por essa quantidade; -
        contar e mostrar todos os valores lidos que tenham suas partes fracion�rias ao intervalo de precis�o. DICA: Usar conforma��o de
        tipo (type casting) para isolar a parte inteira (int), e obter a parte fracion�ria mediante a subtra��o da parte inteira, antes de testar.
    Teste:   Entrada                                   Sa�da
             0.1 0.7                                    qtd: 3
             5                                          0.587 0.48 0.32
             1.96 1.587 6.48 9.32 10.99

    */


    float interv1, interv2;

    void testeValorIntervalo(){
        while((interv1 <= 0 || interv1 >=1) || (interv2 <= 0 || interv1 >=2) ){
            printf("\nERRO!! \nOs valores devem estar entre 0 e 1\n");
            printf("\nDigite novamente o primeiro valor: ");
            scanf("%f", &intervalo1);
            printf("\nDigite novamente o segundo valor: ");
            scanf("%f", &intervalo2);
        }
    }

    void valoresReaisTestados(){
        int qtdReal,qtdPertencente, castingInt,posicao;
        float valorReal, decimal, vetorFracionarios[50];

        qtdPertencente =0;
        posicao=0;

        printf("\nDigite a quantidade dos valores reais: ");
        scanf("%i", &qtdReal);

        for(int i=0; i<qtdReal;i++){
            printf("\nDigite um valor real: ");
            scanf("%f", &valorReal);
                castingInt = (int) valorReal;
                decimal = valorReal-castingInt;

                if(decimal>interv1 && decimal<interv2){
                    vetorFracionarios[posicao++]=decimal;
                    qtdPertencente++;
                }
        }
        printf("\nA quantidade de valores que pertence as condicoes e: %i", qtdPertencente);

        printf("\n\nOs valores que tem suas partes fracionarias ao intervalo de precisao sao:");
        for(int i=0; i<qtdPertencente; i++){
            printf(" %f", vetorFracionarios[i]);
        }
    }


    printf("\nDigite o primeiro valor do intervalo: ");
    scanf("%f", &interv1);
    printf("\nDigite o segundo valor do intervalo: ");
    scanf("%f", &interv2);
    testeValorIntervalo();
    valoresReaisTestados();

    return 0;
}

int exe10(){
    /*10) Crie um procedimento para:
            ler uma linha do teclado; defina essa linha como global ;
            - separar em outra cadeia de caracteres e mostrar todos os s�mbolos n�o alfanum�ricos (letras ou d�gitos) na cadeia de caracteres.

    Teste: Entrada            Sa�da
            ab@caxi*+.         @*+.

    */

    void cadeiaNaoAlfanumerica(){
        int i;
        char cadeia[50];

        printf("\nA cadeia formada por simbolos nao alfanumericos e:  ");
        for(i=0; linha[i] != '\0'; i++){
            if( !((linha[i]>='A') && (linha[i]<='Z')) && !((linha[i]>='a') && (linha[i]<='z')) && !( (linha[i]>='0') && (linha[i])<='9') ){
                    cadeia[i] = linha[i];
                    printf("%c",cadeia[i]);
            }
        }
    }

    printf("\nDigite uma linha: ");
    fflush(stdin);
    gets(linha);
    cadeiaNaoAlfanumerica();
    return 0;
}
