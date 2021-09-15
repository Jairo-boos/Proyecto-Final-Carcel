#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Carcel
{
char nombre [20],apellido[20];
int edad;
int id;
char pabellon[20];
char crimen [20];
int tiempoCondena;
}Carcel;

FILE *datos;

void agregarPresos(Carcel presos[], int n );

void mostrarPresos(Carcel presos[], int n);

void ordenarPresos(Carcel presos[],int n);

void idPresos(Carcel presos[],int n);


int main(void) 
{
  Carcel presos[40];
  int op;
  int n;
  int parametro;
  char parametroBusqueda[20];
  char user[20];
  char password[20];

  printf("*****CARCEL ESTATAL DE QUITO****\n \n");
  printf("Ingrese su usuario\n");
  scanf("%s",user);
  printf("Ingrese su contraseña\n");
  scanf("%s",password);
  printf("\n \n");
 if((strcmp(user,"Guardia1040")==0) &&(strcmp(password,"506070")==0))
  {

  do
  { 
    printf("\t \t ****BIENVENIDO A LA CARCEL ESTATAL****\n");
    printf("\t------Seleccione la accion que desea realizar-------- \t \t \n");
    
    printf("\t \t 1. Ingresar datos de los reos \n \n");
    printf("\t \t 2. Mostrar a todos los reos \n \n");
    printf("\t \t 3. Ordenar a los reos de menor a mayor tiempo de condena restante \n \n");
    printf("\t \t 4. Buscar datos de un privado de la libertad \n \n");
    printf("\t \t 5. Ingresar datos al archivo \n \n");
    printf("\t \t 6. Salir \n");

    scanf("%d",&op);
    switch(op)
    {
      case 1: 
      printf("\n \t Ingrese el número de presos que desea registrar: \n \n");
      scanf("%d",&n);
      if(n>0)
      {
        agregarPresos(presos,n);     
      }
      else
      {
         printf("\n Por favor ingrese un dato valido \n \n"); 
      }
      break;

      case 2:
      mostrarPresos(presos, n);
      break;

      case 3:
      printf("La lista de reos y su condena es: \n");
      for(int i=0; i<n;i++)
      {
        printf("ID [ %d ] , Tiempo de condena [ %d ] \n",presos[i].id,presos[i].tiempoCondena);
      }
      ordenarPresos(presos, n);
      break;
      case 4:
          printf("\n\t\t Ingrese el parametro por el que desea buscar el preso \n");
          printf("\n\t\t 1. Pabellon\n");
          printf("\n\t\t 2. Nombre o Apellido\n");
          scanf ("%d",&parametro);

          printf("\n\t\t Ingrese el parametro de busqueda: \n");
          scanf ("%s",parametroBusqueda);
          
          printf("\n\t\t Listo de personas privadas de la libertad \n");
          printf("\n ID \t NOMBRE \t APELLIDO \t \t EDAD \t \t CRIMEN \t TIEMPO DE CONDENA \t PABELLON \n ");
          for (int i=0; i<n;i++)
          {
            if(parametro == 1)
            {
              if((strcmp(presos[i].pabellon,parametroBusqueda)==0))
              {
                  printf("\n %d  \t %s  \t \t %s  \t \t %d \t \t \t %s \t \t \t %d \t \t \t  %s \n \n",presos[i].id,presos[i].nombre,presos[i].apellido,presos[i].edad,presos[i].crimen,presos[i].tiempoCondena, presos[i].pabellon);
              }
             //else{printf("\n \n Ingrese un dato valido \n \n");}
            }
            else 
            {
                if((strcmp(presos[i].nombre,parametroBusqueda)==0))
              {
                 printf("\n %d \t \t \t %s \t \t \t %s \t \t \t %d \t \t \t %s \t \t \t %d \t \t \t %s \n",presos[i].id,presos[i].nombre,presos[i].apellido,presos[i].edad,presos[i].crimen,presos[i].tiempoCondena, presos[i].pabellon);
              }
              else if((strcmp(presos[i].apellido,parametroBusqueda)==0))
                  {
                   printf("\n %d \t \t \t %s \t \t \t %s \t \t \t %d \t \t \t %s \t \t \t %d \t \t \t %s \n",presos[i].id,presos[i].nombre,presos[i].apellido,presos[i].edad,presos[i].crimen,presos[i].tiempoCondena, presos[i].pabellon);
                  }
                  else{printf("\n \n \t Ingrese un dato valido \n \n");}
                
            }
           

            }
      break;
      case 5:
      printf("\n**** Resultados almacenados en el archivo**** \n");
            datos = fopen("presos.txt", "w");
      for(int i=0; i<n; i++)
            {
            fprintf(datos,"%d %s %s %d %s %d %s",presos[i].id,presos[i].nombre,presos[i].apellido,presos[i].edad,presos[i].crimen,presos[i].tiempoCondena,presos[i].pabellon);
            }
            fclose(datos);
            printf("\n");
      break;
      default:
        {
            printf("Elija una opcion valida \n \n");
            break;
        }
    }
  
   }while(op!=6);
  }
  else 
  {
     printf("Usuario y contraseña incorrectos \n");
  }
  return 0;
}


   
  

//OP1
void agregarPresos(Carcel presos[], int n)
{
  for(int i=0; i<n; i++)
  {
    presos[i].id=i;
      printf("\n Ingrese el nombre del preso %d: ",i+1);
      scanf("%s",presos[i].nombre);
      printf("\n Ingrese el apellido del preso %d: ",i+1);
      scanf("%s",presos[i].apellido);
      printf("\n Ingrese la edad del preso %d: ",i+1);
      scanf("%d",&presos[i].edad);
       if(presos[i].edad>0)
      {    
      }
      else
      {
         printf("\n Por favor ingrese un dato valido \n \n"); 
      }
      printf("\n Ingrese el crimen cometido del preso %d: ",i+1);
      scanf("%s",presos[i].crimen);
      printf("\n Ingrese el tiempo en anios de condena del preso %d: ",i+1);
      scanf("%d",&presos[i].tiempoCondena);
       if(presos[i].tiempoCondena>0)
      {   
      }
      else
      {
         printf("\n Por favor ingrese un dato valido \n \n"); 
      }
         printf("\n Ingrese el pabellon al que pertenece el preso %d: \n",i+1);
          printf(" A \t  B \t  C \n \n");
         scanf("%s",presos[i].pabellon); 
         if(strcmp(presos[i].pabellon, "a")==0)
           {
           } 
          else
           { 
             if(strcmp(presos[i].pabellon, "b")==0)
             {
             }
             else
             {
                if(strcmp(presos[i].pabellon, "c")==0)
                {

                }
                else {printf("Ingrese una opcion valida de pabellon \n \n");}
             }
          }   
      
  }
}
//OP 2
void mostrarPresos(Carcel presos [], int n)
{
  printf("\n Lista de Presos registrados son:\n");
  printf("****************\n");
  for (int i=0; i<n;i++)
    {
      printf("* ID: %d\n",presos[i].id);
      printf("* Nombre: %s\n",presos[i].nombre);
      printf("* Apellido: %s\n",presos[i].apellido);
      printf("* Edad: %d\n",presos[i].edad);
      printf("* Crimen cometido: %s \n",presos[i].crimen);
      printf("* Tiempo de condena: %d\n",presos[i].tiempoCondena);
      printf("* Pabellon: %s \n",presos[i].pabellon);
      printf("****************\n \n");
    }
}
// OP 3
void ordenarPresos(Carcel presos[],int n)
{
    int aux;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(presos[j].tiempoCondena>presos[j+1].tiempoCondena)
            {
            aux=presos[j].tiempoCondena;
            presos[j].tiempoCondena=presos[j+1].tiempoCondena;
            presos[j+1].tiempoCondena=aux;
            }
             for (int n=0;n<i;n++)
            {
              if(n<i)
              {
                aux=presos[i].id;
                presos[i].id=presos[i+1].id;
                
              }
            }

        }
         printf( "[ %d ][ID %d ]",presos[i].tiempoCondena, presos[i].id);
         
    }
    printf("\n \n");
}