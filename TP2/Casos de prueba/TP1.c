#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Listar en pantalla las especies cuyo % de variación es negativo.
int main()
{
    FILE *html;
    FILE *punto1;
    char *pchar;
    char *especie;
    char variacion[5];
    char *substring;
    char buffer[2048];


    if (html = fopen("SSL-TP2.html","rt"))
    {
        punto1 = fopen("punto1.csv","w");
        fprintf(punto1, "Especie; Variación\n");
        
        while (fgets(buffer,2048,html)) // Lee una línea y guarda en buffer.
        {
            if ((pchar = strstr(buffer, "data-order")) && strstr(buffer, "Cdo.</td>")) // Verifica que en la línea existan data order y celda al contado
            {
                /*Leemos la Especie */

                while (*pchar != '>')
                    pchar++;
                int i = 0;
                pchar++;
                substring = strtok(pchar, "</td>");
                especie = substring;
                printf("%s:", especie);

                substring = strtok(NULL, "/"); /*Vencimiento */                                
                substring = strtok(NULL, "/"); /*Cant. Nominal */               
                substring = strtok(NULL, "/");  /*Compra */
                substring = strtok(NULL, "/"); /*Venta */
                substring = strtok(NULL, "/"); // Cant.Nominal
                substring = strtok(NULL, "/"); // Ultimo

               /*Escribamos la Variacion y la Epecie*/

                i = 0;
                substring = strtok(NULL, "/");
                while (i != 3){
                    if (*substring == '>')
                    {
                        i++;
                    }
                    substring++;
                }

                if (*substring == '-')
                {
                    fprintf(punto1, "%s;", especie);
                    while (*substring != '<')
                    {
                    fprintf(punto1,"%c", *substring); 
                    substring++;
                    }
                    fprintf(punto1, "\n");
                } 
            }
        }
        fclose(html);
        fclose(punto1);
    }

    return 0;
}