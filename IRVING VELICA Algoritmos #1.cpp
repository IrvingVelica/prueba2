/* Fecha de creacion: 17 de Agosto del 2018  Fecha de Modificacion: 17 de Agosto del 2018 */
/* Autor: Irving Velica Adame*/
/* Descripcion: Programa que genera datos de 40 en 40 (max. 200) de datos de alumnos */
/* Nombre Archivo: IRVING VELICA Algoritmos #1.cpp*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _tdato{
     long matri;
     char nombre[30];
     char paterno[30];
     char materno[30];
     int edad;
     char sexo[10];
}
Tdato;

Tdato GeneraDatos( Tdato vectR[], int i );
int erased( Tdato vectR[200], long dato, int i);
int search( Tdato vectR[200], long dato, int i );
void order( Tdato vectR[200], int i );
void print( Tdato vectR[200], int i );
int Validamatri( long mat, int i, Tdato vectR[] );
void Genarchivo(Tdato vectR[200], int i);
void Leearchivo(Tdato vectR[200], int i);

int main (){
	int choose, op, i=0, firstflag=0, temp, w;
	long dato;
	Tdato reg, vectR[200];
	srand(time(NULL));
	printf("\t\tAlgoritmos Practica #1 \n \n");
	do{
    printf("\t\t  M  A  I  N      M  E  N  U \n");
	printf("1) Agregar datos \n");
	printf("2) Eliminar dato \n");
	printf("3) Buscar dato \n");
	printf("4) Ordenar dato \n");
	printf("5) Imprimir dato/s \n");
	printf("6) Generar Archivo de texto \n");
	printf("7) Salir \n");
      scanf ("%d",&choose);
	  switch(choose){
               case 1:
			   if( i<200 )
			   {
			   	for( w=0;(w<40&&w<200);w++ )
                   {
                   vectR[i]=GeneraDatos( vectR, i );
				   i++;
                   }
                   printf("Registro Generado \n");
			   }
			   else
			   {
			   	  printf("Limite de registros alcanzado \n");
			   }
			   firstflag=1;
               break;
               case 2:
               if(firstflag==0){
               		printf("Aun no se genera ningun registro \n");
               	}
               	else{
               	printf("Ingrese la matricula que desea eliminar \n");
               	scanf("%ld",&dato);
               	temp=erased( vectR,dato, i );
               	if(temp!=-1){
               	vectR[temp].matri=0;
               	printf("la matricula ha sido eliminada \n");
			    }
			    else{
			   	 printf("No se encontro la matricula \n");
			    }
			    }
               break;
               case 3:
               	if(firstflag==0){
               		printf("Aun no se genera ningun registro \n");
               	}
               	else{
               	printf("Ingrese la matricula que desea buscar \n");
               	scanf("%ld",&dato);
               	temp=search( vectR,dato, i );
               if(temp!=-1){
               	  printf("La matricula %d esta en el registro \n",vectR[temp].matri);
			   }
			   else
			   {
			   	 printf("No se encontro la matricula \n");
			   }
			   }
               break;
               case 4:
               	if(firstflag==0){
               		printf("Aun no se genera ningun registro \n");
               	}
               	else{
               order(vectR, i);
			    }
               break;
               case 5:
               if(firstflag==0){
               		printf("Aun no se genera ningun registro \n");
               	}
               	else{
               print(vectR, i);
			   }
               break;
               case 6:
               	if(firstflag==0){
               		printf("Aun no se genera ningun registro \n");
               	}
               	else{
               Genarchivo(vectR, i);
			   }
               	break;
               	case 7:
               	break;
               default:
               printf("Opcion no valida\n");
               break;
		}
	printf("Desea realizar otra accion? \n");
	printf("1) Si\n");
	printf("2) No \n");
	scanf("%d",&op);
	system("CLS");
    }
    while(op==1);
	return 0;
}


Tdato GeneraDatos(Tdato vectR[], int i){
      char nombreH[40][40]={"Victor","Jorge","Yair","Fidel","Cesar","Fernando","Juan","Leonardo","Rodolfo",
      "Miguel","Rogelio","Ernesto","Oskar","Josue","Raul","Antonio","Luis","Sebastian","Aldo","Esteban",
      "Irving","Pablo","Olaf","Erick","Alan","Ivan","Enrique","Ricardo","Yepiz","Jesus","Cristo","Eugenio","Juan",
	  "Marvin","Yamil","German","Arturo","Carlos","Robin","Remmy"};
      char nombreM[40][40]={"Alma","Alejandra","Maria","Carmen","Flor","Luna","Magdalena","Nancy",
      "Consuelo","Lizbeth","Luana","Maya","Ana","Karla","Juliet","Mildrem","Vera","Fernanda","Alicia",
      "Johana","Roxana","Lucia","Ivonne","Melisa","Cristal","Juracy","Paula","Geneva","Adriana","Lissa","Soraya",
	  "Ernestina","Marimar","Concepcion","Moana","Itzel","Teresa","Susana","Kosaki"};
      char paterno[40][40]={"Echeverria","Zavaleta","Esquivel","Wong","Garcia","Aguilar","Leon","Quintero",
      "Bezerra","Navarro","Huerta","Montes","Valles","Mejia","Aviles","Candelero","Vazquez","Rodriguez",
      "Hernandez","Santos","Villa","Martinez","Hidalgo","Velica","Perez","Galarza","Montoña","Rubio","Meraz",
	  "Noriega"};
      char materno[40][40]={"Garcia","Rivas","Rios","Carrillo","Nieto","Gallegos","Arriaga","Ramirez",
      "Rojas","Romano","Morales","Diaz","Guitierrez","Ramos","Paez","Peralta","Suarez","Ochoa","Toledo",
      "Osuna","Castaneda","Vallejo","Silva","Flores","Blanco","Larios","Adame","Zamudio","Valverde","Solares",
	  "Magaña","Basurto"};
	  Tdato reg;
      long mat, aux;
      int dat, num;
      num=(rand()%2);
      if(num%2){
         strcpy(reg.nombre, nombreH[rand()%30]);
         strcpy(reg.paterno, paterno[rand()%30]);
         strcpy(reg.materno, materno[rand()%30]);
         strcpy(reg.sexo, "Hombre");
		 }
       else{
        strcpy(reg.nombre, nombreM[rand()%30]);
        strcpy(reg.paterno, paterno[rand()%30]);
        strcpy(reg.materno, materno[rand()%30]);
        strcpy(reg.sexo, "Mujer");
        }
        do{
            mat=(long)(340000+rand()%9999);
            aux=Validamatri(mat, i, vectR);
		}while(aux!=1);
        reg.matri=mat;       
        reg.edad=(int)(18+rand()%10);
        return reg;
}

int erased(Tdato vectR[], long dato, int i){
	int j=0;
   for(j=0;j<i;j++)
    {
    	if(vectR[j].matri==dato)
          {
          	return j;
          }
    }
    return -1;
}

int search(Tdato vectR[], long dato, int i){
   int j;
   for(j=0;j<i;j++)
    {
    	if(vectR[j].matri==dato)
          {
          	return j;
          }
    }
    return -1;
}

void order(Tdato vectR[200], int i){
	int cont, j, pasos;
	Tdato temp;
	for((cont=i/2);cont!=0;cont/=2)
	{
		for(pasos=1;pasos!=0;)
		{
			pasos=0;
			for(j=cont;j<i;j++)
			{
				if(vectR[j-cont].matri>vectR[j].matri)
				{
					temp=vectR[j];
					vectR[j]=vectR[j-cont];
					vectR[j-cont]=temp;
					pasos++;
				}
			}
		}
	}
	for(j=0;j<i;j++)
	{
		printf("||  Matricula  #%2d  ||  %6ld  ||\n",j+1, vectR[j].matri);
	}
    system("pause");
}

void print(Tdato vectR[], int i){
	int j;
	printf("   Matricula ||Ap. Paterno||Ap. Materno|| Nombre ||  Edad  || Sexo\n");
	for(j=0;j<i;j++)
	{
		printf("%6ld  ||%8s  ||%8s   ||%8s   ||%4d  ||%s \n",vectR[j].matri, vectR[j].paterno, vectR[j].materno, vectR[j].nombre, vectR[j].edad, vectR[j].sexo);
	}
	system("pause");
}

void Genarchivo(Tdato vectR[200], int i){
	char namae[50];
	int j;
	FILE *fa;
	printf("Ingrese el nombre del archivo (con su extension) que desea generar \n");
	scanf("%s",&namae);
	fa=fopen(namae,"w+");
     if(fa)
       {
       	    for(j=0;j<i;j++)
       		{
				fprintf(fa,"%3d||%6ld  ||%8s  ||%8s   ||%8s   ||%4d  ||%s \n",j+1,vectR[j].matri, vectR[j].paterno, vectR[j].materno, vectR[j].nombre, vectR[j].edad, vectR[j].sexo);
			}
       }
       fclose(fa);
    printf("Archivo Generado \n");
}

int Validamatri(long mat, int i, Tdato vectR[]){
	int j;
	for(j=0;j<=i;j++)
		{
			if(vectR[j].matri==mat)
			{
				return 0;
			}
		}
	return 1;
}
