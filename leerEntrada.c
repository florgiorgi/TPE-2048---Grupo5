#include <stdio.h>
#include <string.h>

int leerEntrada(char *nombreArchivo, char *dirVec);

int
main()
{
int estado;
char nombreArchivo[36];
char dirVec;
estado=leerEntrada(nombreArchivo, &dirVec);
if(estado)
    if(estado!=5)
        printf("\nNo hay errores.\n");
    else
        printf("estado ERROR");
else
    printf("\nHay algun error.\n");
printf("\nEl estado es %d\n", estado);
if(estado==1)
    printf("\nLa direccion del vector sera: %c\n", dirVec);
if(estado==3)
    printf("\nEl nombre del archivo es: %s\nNo te lo olvides!\n", nombreArchivo);

return 0;
}


int
leerEntrada(char *nombreArchivo, char *dirVec)
{
enum estado {MOVIMIENTO=1, UNDO, SAVE, QUIT, ERROR};
char turno, c, s;
char * quit="uit\n";
char * save="ve ";
char * undo="ndo\n";
int i, j, estado=0;

turno=getchar();

	    switch(turno) {
			case 'w': {
			    if(getchar()=='\n') {
                    *dirVec=turno;
                    estado=MOVIMIENTO;
			    } else
                    estado=ERROR;
			    break;
			}
			case 'a': {
			    if(getchar()=='\n') {
                    *dirVec=turno;
                    estado=MOVIMIENTO;
			    } else
                    estado=ERROR;
			    break;
			}
			case 'd': {
			    if(getchar()=='\n') {
                    *dirVec=turno;
                    estado=MOVIMIENTO;
			    } else
                    estado=ERROR;
			    break;
			}
			case 'u': {
			    for(i=0; i<4 && getchar() == undo[i] ; i++)
               			;
                	    if(i==4)
		                    estado=UNDO;
			    else
		                    estado=ERROR;
                	break;
			}
			case 's': {
			    c=getchar();
			    if(c=='\n') {
                    *dirVec=turno;
                    estado=MOVIMIENTO;
			    } else if(c=='a') {
			        for(i=0; i<3 && getchar() == save[i] ; i++)
                        ;
                    if(i==3) {
                        estado=SAVE;
                        j=0;
                        do
                            nombreArchivo[j] = getchar();
                        while(j<35 && (nombreArchivo[j++]!='\n'));
                        nombreArchivo[j]='\0';
                        if(j==35)
                            printf("\nEl nombre del archivo guardo solo los primeros 35 chars!!\n");
                        } else
                            estado=ERROR;
                } else
                    estado=ERROR;
				break;
			}
			case 'q': {
			    for(i=0; i<4 && getchar() == quit[i] ; i++)
                       ;
                if(i==4) {
                    estado=QUIT;
                    printf("Desea guardar antes de salir? (y/n)\n");
                    do {
                        s=getchar();
                        if(s!='y' || s!='n')
                            printf("Comando no reconocido. Desea guardar antes de salir?  (y/n)");
                    } while(s!='y' || s!='n');
                }
                else
                    estado=ERROR;
			    break;
			}
			default:
                   estado=ERROR;
	    }

return estado;
}
