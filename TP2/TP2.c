#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Especie; Precio de compra; Precio de venta; Apertura; Precio Máximo; Precio Mínimo.
int main()
{
    FILE *html;
    FILE *punto2;
    char *pchar;
    char *substring;
    char buffer[2048];


    if (html = fopen("SSL-TP2.html","rt"))
    {
        punto2 = fopen("punto2.csv","w");
        fprintf(punto2, "Especie;Precio de compra;Precio de venta;Apertura;Precio Mínimo;Precio Máximo\n");
        
        while (fgets(buffer,2048,html)) // Lee una línea y guarda en buffer.
        {
            if ((pchar = strstr(buffer, "data-order")) && strstr(buffer, "Cdo.</td>")) // Verifica que en la línea existan data order y celda al contado
            {
                /*Escribamos el nombre de la Especie */

                while (*pchar != '>')
                    pchar++;
                int i = 0;
                pchar++;
                substring = strtok(pchar, "</td>");
                fprintf(punto2,"%s;", substring);

                /*Escribamos el Vencimiento */

                substring = strtok(NULL, "/");
                while (i != 2){
                    if (*substring == '>')
                    {
                        i++;
                    }
                    substring++;
                }
                while (*substring != '<'){
                    //fprintf(punto2, "%c", *substring);
                    substring++;
                }
                //fprintf(punto2, ";"); 

                /* Escribamos la Cant. Nominal */

                i = 0;
                substring = strtok(NULL, "/");
                while (i != 2){
                    if (*substring == '>')
                    {
                        i++;
                    }
                    substring++;
                }
                while (*substring != '<'){
                    //fprintf(punto2, "%c", *substring);
                    substring++;
                }
                //fprintf(punto2, ";"); 

                /*Escribamos la Compra */

                i = 0;
                substring = strtok(NULL, "/");
                while (i != 2){
                    if (*substring == '>')
                    {
                        i++;
                    }
                    substring++;
                }
                while (*substring != '<'){
                    fprintf(punto2, "%c", *substring);
                    substring++;
                }
                fprintf(punto2, ";");

                /*Escribamos la Venta */

                i = 0;
                substring = strtok(NULL, "/");
                while (i != 2){
                    if (*substring == '>')
                    {
                        i++;
                    }
                    substring++;
                }
                while (*substring != '<'){
                    fprintf(punto2, "%c", *substring);
                    substring++;
                }
                fprintf(punto2, ";");

               substring = strtok(NULL, "/"); // Cant.Nominal
               substring = strtok(NULL, "/"); // Ultimo
               substring = strtok(NULL, "/"); // Variacion
               substring = strtok(NULL, "/"); // Estilo y color
               substring = strtok(NULL, "/"); // Estilo y color
               
               /*Escribamos la Apertura */

                i = 0;
                substring = strtok(NULL, "/");
                while (i != 2){
                    if (*substring == '>')
                    {
                        i++;
                    }
                    substring++;
                }
                while (*substring != '<'){
                    fprintf(punto2, "%c", *substring);
                    substring++;
                }
                fprintf(punto2, ";");

               /*Escribamos el Minimo */

                i = 0;
                substring = strtok(NULL, "/");
                while (i != 2){
                    if (*substring == '>')
                    {
                        i++;
                    }
                    substring++;
                }
                while (*substring != '<'){
                    fprintf(punto2, "%c", *substring);
                    substring++;
                }
                fprintf(punto2, ";");

               /*Escribamos el Maximo */

                i = 0;
                substring = strtok(NULL, "/");
                while (i != 2){
                    if (*substring == '>')
                    {
                        i++;
                    }
                    substring++;
                }
                while (*substring != '<'){
                    fprintf(punto2, "%c", *substring);
                    substring++;
                }
                fprintf(punto2, ";"); 
                fprintf(punto2, "\n"); 
            }
        }
        fclose(html);
        fclose(punto2);
    }

    return 0;
}