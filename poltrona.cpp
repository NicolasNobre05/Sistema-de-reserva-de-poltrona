// Caso coloque no navegador, tira o system("cls");
#include <stdio.h>
#include <cstdlib>
#include <ctype.h>


char fileira;
int col;
int poltrona;
char fileirasPermitidas[] = {'A','B', 'C', 'D', 'E', 'F'};
char continua = 'S';
bool onibusCheio;
int classeReserva;

char matriz[5][6] = {
        {'0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0'}
    };


int imprimirMatriz(){
    int lin = 1;
    onibusCheio = true;

    printf("\n       FILEIRAS");
    printf("\n   A  B  C  D  E  F");
    printf("\n");

    for (int i = 0; i < 5; ++i) {
            printf("%i", lin);
            printf("|");
            lin = lin + 1;
            for (int j = 0; j < 6; ++j) {
                if(matriz[i][j] != 'X'){
                    onibusCheio= false;
                }

                if (matriz[i][j] == 'X')
                {
                    printf("\033[31m %c \033[0m", matriz[i][j]);
                }else{
                    printf("\033[36m %c \033[0m", matriz[i][j]);
                }
                
            }
            printf("\n");
        };
        printf("\n Poltrona reservada = X |");
        printf(" Poltrona livre = 0\n");
        printf("Economica - Fileiras [B-E] |");
        printf("Executiva - Fileiras [A-F]");
        return onibusCheio;
}

int encerrarSistema(){
    printf("\nDeseja reservar outra poltrona? (S/N) ");
    scanf(" %c", &continua);
    continua = toupper(continua);
    system("cls");
    return continua;
}

int classePassagens(){
    printf("\n Escolha sua classe: ");
    printf("\n [1] Economica ");
    printf("\n [2] Executiva ");

    scanf("%i", &classeReserva);

    switch (classeReserva)
    {
    case 1:
        printf("\n Digite a fileira desejada (B-E): ");
        break;
    
    case 2:
        printf("\n Digite a fileira desejada (A-F): ");
        break;
    };
};

int main() {

    

    while (continua =='S'){
        //VERIAVEL QUE PRECISA SER REDEFINIDA A CADA CICLO
        int verificacaofileira = 0;
        
        
        //CABEÇALHO
        printf("\n---------------------------------------------------------------------");
        
        //imprimir matriz
        imprimirMatriz();
        
        printf("\n---------------------------------------------------------------------");

        //VERIFICAR SE O ONIBUS NÃO ESTÁ LOTADO
        if (onibusCheio){
            printf("\n\033[37;41m Onibus cheio, aguarde o proximo \033[0m");
            break;
        };
        

        classePassagens();
        
        //VERIFICAR FILEIRA
        scanf( " %c", &fileira);
        
        if (classeReserva == 1){
            if (fileira == 'A' || fileira == 'F')
            {
                
                printf("Fileiras invalidas para a sua classe");
            };
            
        };

        //transformar de minuscula para maiuscula
        fileira = toupper(fileira);

        for (int o = 0; o <= 4; o++){
            if (fileira == fileirasPermitidas[o]){
                verificacaofileira = 1;
            }
        }

        if (verificacaofileira == 0){
            system("cls");
            printf("\033[37;41m Fileira invalida... escolha uma valida \033[0m");
            continue;
        }
        
        //VERIFICAR POLTRONA
        printf("\n Digite a linha desejada (1-5): ");
        scanf("%i", &poltrona);
        
        if (poltrona < 1 || poltrona > 5){
            system("cls");
            printf("\033[37;41m Poltrona invalida... escolha uma valida \033[0m");
            continue;
        }

        //TRANSFORMAR CHAR EM INT
        switch(fileira){
            case 'A':
                col = 0;
                break;
            
            case 'B':
                col = 1;
                break;
                
            case 'C':
                col = 2;
                break;
            
            case 'D':
                col = 3;
                break;
                
            case 'E':
                col = 4;
                break;
                
            case 'F':
                col = 5;
                break;
        };
        
        /*Para diminuir uma unidade da variavel poltrona */
        poltrona -=1;

        system("cls");

        //CASO A POLTRONA JÁ ESTEJA RESERVADA
        if (matriz[poltrona][col] == 'X')
        {
            printf("\033[37;41m POLTRONA RESERVADA. RESERVE OUTRA \033[0m");

        }else{
            matriz[poltrona][col] = 'X';
            imprimirMatriz();
            printf("\n\033[30;42m Poltrona reservada: %c%i \033[0m\n",fileira,poltrona+1);
            encerrarSistema();

            if (continua != 'S' && continua != 'N'){
                system("cls");
                printf("\033[37;41mOpcao invalida... \033[0m");
                encerrarSistema();
            };
        }
    }

    printf("\033[30;42mObrigado pela preferencia! Tenha um boa viagem...\033[0m\n");

    return 0;
}
