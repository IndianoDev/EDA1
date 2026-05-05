#include <stdio.h>

int main()
{
    int teatro[15][20];
    int fila;
    int lugar;
    int reservados = 0;
    int total = 300;

    for (int fileiras = 0; fileiras < 15; fileiras++)
    {
        for (int assentos = 0; assentos < 20; assentos++)
        {
            teatro[fileiras][assentos] = 0;
        }
    }
    for (int fileiras = 0; fileiras < 15; fileiras++)
    {
        for (int assentos = 0; assentos < 20; assentos++)
        {
            printf("%d ", teatro[fileiras][assentos]);
        }
        printf("\n");
    }

    
    while (reservados < total) 
    {
        printf("Digite a fileira que voce quer:");
        scanf("%d", &fila);
    
        printf("Agora digite o assento que voce quer:");
        scanf("%d", &lugar);

        if (teatro[fila][lugar] == 1)
        {
            printf("este lugar ja foi ocupado");
        }
        else
        {
            teatro[fila][lugar] = 1; reservados++;
            printf("Assento adicionado com sucesso:");
        }
        printf("\n --- LUGARES VAGOS --- \n");
        
        for (int fileiras = 0; fileiras < 15; fileiras++)
        {
            for (int assentos = 0; assentos < 20; assentos++)
            {
                printf("%d ", teatro[fileiras][assentos]);
            }
            printf("\n");
        }
    }


    return 0;
}
