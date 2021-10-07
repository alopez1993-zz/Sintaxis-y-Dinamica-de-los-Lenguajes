#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void informe1();
void informe2();
void informe3();

int main()
{
    // Presentación de menú en pantalla

    int informe;
    printf("\n Inserte el nro de reporte requerido:\n1) Especies cuyo porcentaje de variación es negativo.\n2) CSV: Especie; Precio de compra; Precio de venta; Apertura; Precio Máximo; Precio Mínimo.\n3) HTML: Informe 1 (En color verde las filas de las especies cuyo precio de compra y precio de venta es menor al precio de apertura)\n\n");
    scanf("%d", &informe);

    if (informe == 1)
    {
        informe1();
    }
    else
    {
        if (informe == 2)
        {
            informe2();
        }
        else
        {
            if (informe == 3)
            {
                informe3();
            }
            else
            {
                printf("Introduzca un valor permitido (1/3)\n");
            }
            
            
        }
    
    }
    printf("\n Reporte generado en ruta del ejecutable. Gracias, vuelva pronto :)");
    return 0;
}


// Listar en pantalla las especies cuyo % de variación es negativo.
void informe1()
{
    FILE *html;
    FILE *punto1;
    char *pchar;
    char *especie;
    char variacion[5];
    char *substring;
    char buffer[2048];


    if (html = popen("wget -q -O - https://bolsar.info/lideres.php --no-check-certificate","r"))
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

}


// Especie; Precio de compra; Precio de venta; Apertura; Precio Máximo; Precio Mínimo.
void informe2()
{
    FILE *html;
    FILE *punto2;
    char *pchar;
    char *substring;
    char buffer[2048];


    if (html = popen("wget -q -O - https://bolsar.info/lideres.php --no-check-certificate","r"))
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

}

/* Mismo reporte que el listado A pero en una tabla html, indicando en color verde las 
filas de las especies cuyo precio de compra y precio de venta es menor al precio 
de apertura. */
void informe3()
{
    FILE *html;
    FILE *punto3;
    char *pchar;
    char *especie;
    double compra;
    char bcompra[5];
    double venta;
    char bventa[5];
    double variacion;
    char bvariacion[5];
    double apertura;
    char bapertura[5];
    char *substring;
    char buffer[2048];


    if (html = popen("wget -q -O - https://bolsar.info/lideres.php --no-check-certificate","r"))
    {
        punto3 = fopen("punto3.html","w");
        fprintf(punto3, "<table>\n<tr>\n<th> Especie </th><th> Variacion </th>\n</tr>\n");
        
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

                substring = strtok(NULL, "/"); /*Vencimiento */                                
                substring = strtok(NULL, "/"); /*Cant. Nominal */   

               /*Guardamos la Compra */

                i = 0;
                substring = strtok(NULL, "/");
                while (i != 2){
                    if (*substring == '>')
                    {
                        i++;
                    }
                    substring++;
                }
                
                int c = 0;
                while (*substring != '<'){
                    bcompra[c] = *substring;
                    if (bcompra[c] == ',') // Reemplazo coma por punto para poder convertir el string en float.
                    {
                        bcompra[c] = '.';
                    }
                    c++;
                    substring++;
                }

                compra = atof(bcompra);

                /*Guardamos la Venta */

                i = 0;
                substring = strtok(NULL, "/");
                while (i != 2){
                    if (*substring == '>')
                    {
                        i++;
                    }
                    substring++;
                }
                
                c = 0;
                while (*substring != '<'){
                    bventa[c] = *substring;
                    if (bventa[c] == ',') // Reemplazo coma por punto para poder convertir el string en float.
                    {
                        bventa[c] = '.';
                    }
                    c++;
                    substring++;
                }
                
                venta = atof(bventa);

                substring = strtok(NULL, "/"); // Cant.Nominal
                substring = strtok(NULL, "/"); // Ultimo
                
                /*Guardamos la Variacion */

                i = 0;
                substring = strtok(NULL, "/");
                while (i != 3){
                    if (*substring == '>')
                    {
                        i++;
                    }
                    substring++;
                }
                
                c = 0;
                while (*substring != '<'){
                    bvariacion[c] = *substring;
                    if (bvariacion[c] == ',') // Reemplazo coma por punto para poder convertir el string en float.
                    {
                        bvariacion[c] = '.';
                    }
                    c++;
                    substring++;
                }
                variacion = atof(bvariacion);

                substring = strtok(NULL, "/"); // Estilo y color
                substring = strtok(NULL, "/"); // Estilo y color
               
               /*Guardamos la Apertura */

                i = 0;
                substring = strtok(NULL, "/");
                while (i != 2){
                    if (*substring == '>')
                    {
                        i++;
                    }
                    substring++;
                }
                
                c = 0;
                while (*substring != '<'){
                    bapertura[c] = *substring;
                    if (bapertura[c] == ',') // Reemplazo coma por punto para poder convertir el string en float.
                    {
                        bapertura[c] = '.';
                    }
                    c++;
                    substring++;
                }
                apertura = atof(bapertura);

                if (variacion < 0)
                {
                    if (venta < apertura && compra < apertura)
                    {
                    fprintf(punto3, "<tr>\n");
                    fprintf(punto3, "<td> <span style=\"color:#10da10;\"> %s </span></td>", especie);
                    fprintf(punto3, "<td> <span style=\"color:#10da10;\"> %f </span></td>\n", variacion);
                    fprintf(punto3, "</tr>\n"); 
                    }
                    else
                    {
                    fprintf(punto3, "<tr>\n");
                    fprintf(punto3, "<td> <span> %s </span></td>", especie);
                    fprintf(punto3, "<td> <span> %f </span></td>\n", variacion);
                    fprintf(punto3, "</tr>\n");
                    }
                }
            
            }
        }
        fprintf(punto3, "</table>\n"); 
        fclose(html);
        fclose(punto3);
    }

}