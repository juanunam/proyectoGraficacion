#include<stdio.h>
#include<vector>
using namespace std;
int vertices[16][3];

int main(){
  int cara=0;
  int vertice=1;
  printf("int vertices[54][4][3]= \n{\n");
  for(int z=-3;z<=3;z=z+6){

        printf("// Cara %d \n",cara+1 );
  for(int p=-3;p<3;p=p+2){
    for(int i=-3;i<3;i=i+2){
      printf(" { //vertice %d\n",vertice);vertice++;
      for(int j=0;j<=2;j=j+2)
      for(int k=0;k<=2;k=k+2)
      if(j!=2||k!=2)
      printf("  {%d,%d,%d},",z, i+j,p+k);
      else
      printf("  {%d,%d,%d}\n",z, i+j,p+k);

      printf(" },\n");
    }
  }

    cara++;
}
  for(int z=-3;z<=3;z=z+6){
      printf("// Cara %d \n",cara+1 );
  for(int p=-3;p<3;p=p+2){
    for(int i=-3;i<3;i=i+2){
     printf(" { //vertice %d\n",vertice);vertice++;
      for(int j=0;j<=2;j=j+2)
        for(int k=0;k<=2;k=k+2)
          if(j!=2||k!=2)
            printf("  {%d,%d,%d},", i+j,z,p+k);
          else
            printf("  {%d,%d,%d}\n", i+j,z,p+k);

     printf(" },\n");
    }
  }
    cara++;
}
for(int z=-3;z<=3;z=z+6){
    printf("// Cara %d \n",cara+1 );
  for(int p=-3;p<3;p=p+2){
    for(int i=-3;i<3;i=i+2){
      printf(" { //vertice %d\n",vertice);vertice++;
      for(int j=0;j<=2;j=j+2)
      for(int k=0;k<=2;k=k+2){

        if(j==2&&k==2)
        printf("  {%d,%d,%d}\n", i+j,p+k,z);
        else
        printf("  {%d,%d,%d},", i+j,p+k,z);
      }

        printf("  }");
        if(vertice!=55)
         printf(",\n");

    }

  }
    cara++;
}

  printf("\n};");
/*  GLfloat color[8][3] =
  {
      {0.0,1.0,0.0}, //Verde
      {1.0,0.0,0.0}, // Rojo
      {1.0,1.0,0.0}, //amarillo
      {1.0,1.0,1.0},//Blanco
      {0.0,0.0,1.0},//Azul
      {0.9,0.38,0.0}, //naranja
      {1.0,1.0,1.0},//Blanco
      {0.0,1.0,1.0},
  };*/
  printf("\n int colores[54]=\n{\n");
  for(int i=0;i<6;i++){
    for (int k = 0; k < 9; k++) {
      if(i==5&&k==8)
      printf("%d\n",i);
      else
      printf("%d,\n",i);
    }
  }
  printf("};\n");
}
