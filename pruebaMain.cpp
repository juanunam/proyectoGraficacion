#include <GL/glut.h>
#include <cmath>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream> 
#include <map>
#include <stack>
using namespace std;

//================================================================
//variables de OpenGL
//================================================================
int anteriorW=0;
int anteriorH=0;
int cuadranteX,cuadranteY;
double X11,X12,X21,X22,Y11,Y12,Y21,Y22;
//================================================================
//variables de archivos
//================================================================
stack<string> vectorPasos;
stack<int> vectorParametros;
stack<string> vectorColores;
map<string,string> mapaAccion;
map<string,int> mapaParametro;
map<string,int> mapaCaminos;
//================================================================
//variables constantes
//================================================================


#define PI 3.141592


//================================================================
//================================================================
double rotate_z = 0;
double rotate_y = 0;
double rotate_x = 0;
double translate_x=0;
double translate_y=0;
//================================================================
//variables para poner tiempo en pantalla
//================================================================
time_t horaInicio;
time_t horaActual;
//================================================================
//================================================================

//================================================================
//variables vertices
//================================================================

int vertices[54][4][3]=
{
// Cara 1
 { //vertice 1
  {-3,-3,-3},  {-3,-3,-1},  {-3,-1,-3},  {-3,-1,-1}
 },
 { //vertice 4
  {-3,-3,-1},  {-3,-3,1},  {-3,-1,-1},  {-3,-1,1}
 },
 { //vertice 7
  {-3,-3,1},  {-3,-3,3},  {-3,-1,1},  {-3,-1,3}
 },
 { //vertice 2
  {-3,-1,-3},  {-3,-1,-1},  {-3,1,-3},  {-3,1,-1}
 },
 { //vertice 5
  {-3,-1,-1},  {-3,-1,1},  {-3,1,-1},  {-3,1,1}
 },
 { //vertice 8
  {-3,-1,1},  {-3,-1,3},  {-3,1,1},  {-3,1,3}
 },
 { //vertice 3
  {-3,1,-3},  {-3,1,-1},  {-3,3,-3},  {-3,3,-1}
 },
 { //vertice 6
  {-3,1,-1},  {-3,1,1},  {-3,3,-1},  {-3,3,1}
 },
 { //vertice 9
  {-3,1,1},  {-3,1,3},  {-3,3,1},  {-3,3,3}
 },
// Cara 2 
 { //vertice 16
  {3,-3,1},  {3,-3,3},  {3,-1,1},  {3,-1,3}
 },
 { //vertice 13
  {3,-3,-1},  {3,-3,1},  {3,-1,-1},  {3,-1,1}
 },
 { //vertice 10
  {3,-3,-3},  {3,-3,-1},  {3,-1,-3},  {3,-1,-1}
 },
 { //vertice 17
  {3,-1,1},  {3,-1,3},  {3,1,1},  {3,1,3}
 },
 { //vertice 14
  {3,-1,-1},  {3,-1,1},  {3,1,-1},  {3,1,1}
 },
 { //vertice 11
  {3,-1,-3},  {3,-1,-1},  {3,1,-3},  {3,1,-1}
 },
 { //vertice 18
  {3,1,1},  {3,1,3},  {3,3,1},  {3,3,3}
 },
 { //vertice 15
  {3,1,-1},  {3,1,1},  {3,3,-1},  {3,3,1}
 },
 { //vertice 12
  {3,1,-3},  {3,1,-1},  {3,3,-3},  {3,3,-1}
 },

// Cara 3
 { //vertice 25
  {-3,-3,1},  {-3,-3,3},  {-1,-3,1},  {-1,-3,3}
 },
 { //vertice 22
  {-3,-3,-1},  {-3,-3,1},  {-1,-3,-1},  {-1,-3,1}
 },
 { //vertice 19
  {-3,-3,-3},  {-3,-3,-1},  {-1,-3,-3},  {-1,-3,-1}
 },
 { //vertice 26
  {-1,-3,1},  {-1,-3,3},  {1,-3,1},  {1,-3,3}
 },
 { //vertice 23
  {-1,-3,-1},  {-1,-3,1},  {1,-3,-1},  {1,-3,1}
 },
 { //vertice 20
  {-1,-3,-3},  {-1,-3,-1},  {1,-3,-3},  {1,-3,-1}
 },
 { //vertice 27
  {1,-3,1},  {1,-3,3},  {3,-3,1},  {3,-3,3}
 },
 { //vertice 24
  {1,-3,-1},  {1,-3,1},  {3,-3,-1},  {3,-3,1}
 },
 { //vertice 21
  {1,-3,-3},  {1,-3,-1},  {3,-3,-3},  {3,-3,-1}
 },
// Cara 4

 { //vertice 36
  {1,3,1},  {1,3,3},  {3,3,1},  {3,3,3}
 },
 { //vertice 33
  {1,3,-1},  {1,3,1},  {3,3,-1},  {3,3,1}
 },
 { //vertice 30
  {1,3,-3},  {1,3,-1},  {3,3,-3},  {3,3,-1}
 },

 { //vertice 35
  {-1,3,1},  {-1,3,3},  {1,3,1},  {1,3,3}
 },
 { //vertice 32
  {-1,3,-1},  {-1,3,1},  {1,3,-1},  {1,3,1}
 },
 { //vertice 29
  {-1,3,-3},  {-1,3,-1},  {1,3,-3},  {1,3,-1}
 },

 { //vertice 34
  {-3,3,1},  {-3,3,3},  {-1,3,1},  {-1,3,3}
 },
 { //vertice 31
  {-3,3,-1},  {-3,3,1},  {-1,3,-1},  {-1,3,1}
 },
 { //vertice 28
  {-3,3,-3},  {-3,3,-1},  {-1,3,-3},  {-1,3,-1}
 },
// Cara 5

 { //vertice 39
  {1,-3,-3},  {1,-1,-3},  {3,-3,-3},  {3,-1,-3}
  },
 { //vertice 38
  {-1,-3,-3},  {-1,-1,-3},  {1,-3,-3},  {1,-1,-3}
  },
 { //vertice 37
  {-3,-3,-3},  {-3,-1,-3},  {-1,-3,-3},  {-1,-1,-3}
  },

 { //vertice 42
  {1,-1,-3},  {1,1,-3},  {3,-1,-3},  {3,1,-3}
  },
 { //vertice 41
  {-1,-1,-3},  {-1,1,-3},  {1,-1,-3},  {1,1,-3}
  },

 { //vertice 40
  {-3,-1,-3},  {-3,1,-3},  {-1,-1,-3},  {-1,1,-3}
  },

 { //vertice 45
  {1,1,-3},  {1,3,-3},  {3,1,-3},  {3,3,-3}
},
 { //vertice 44
  {-1,1,-3},  {-1,3,-3},  {1,1,-3},  {1,3,-3}
  },
 { //vertice 43
  {-3,1,-3},  {-3,3,-3},  {-1,1,-3},  {-1,3,-3}
  },
// Cara 6
 { //vertice 46
  {-3,-3,3},  {-3,-1,3},  {-1,-3,3},  {-1,-1,3}
  },
 { //vertice 47
  {-1,-3,3},  {-1,-1,3},  {1,-3,3},  {1,-1,3}
  },
 { //vertice 48
  {1,-3,3},  {1,-1,3},  {3,-3,3},  {3,-1,3}
  },
 { //vertice 49
  {-3,-1,3},  {-3,1,3},  {-1,-1,3},  {-1,1,3}
  },
 { //vertice 50
  {-1,-1,3},  {-1,1,3},  {1,-1,3},  {1,1,3}
  },
 { //vertice 51
  {1,-1,3},  {1,1,3},  {3,-1,3},  {3,1,3}
  },
 { //vertice 52
  {-3,1,3},  {-3,3,3},  {-1,1,3},  {-1,3,3}
  },
 { //vertice 53
  {-1,1,3},  {-1,3,3},  {1,1,3},  {1,3,3}
  },
 { //vertice 54
  {1,1,3},  {1,3,3},  {3,1,3},  {3,3,3}
  }
};
 int colores[54]=
{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1,
  2, 2, 2, 2, 2, 2, 2, 2, 2,
  3, 3, 3, 3, 3, 3, 3, 3, 3,
  4, 4, 4, 4, 4, 4, 4, 4, 4,
  5, 5, 5, 5, 5, 5, 5, 5, 5
};
GLfloat color[8][3] =
{
  {1.0,1.0,0.0}, //amarillo 0
  {1.0,1.0,1.0},//Blanco 1
  {0.0,1.0,0.0}, //Verde 2
  {0.0,0.0,1.0},//Azul 3
  {1.0,0.0,0.0}, // Rojo 4
  {0.9,0.38,0.0}, //naranja 5
  {1.0,1.0,1.0},//Blanco
  {0.0,0.0,0.0}//negro
};
//================================================================
//Funciones prototipo
//================================================================
void relizarAccion(string accion,int parametro);
bool completado();
string convierteColores();
void guardarArchivo();
void guardarPasos();
void dibujaVertice(int vertice);
void relizarAccion(string accion,int parametro);
void permutaVertices(int a,int b);
void permutaVerticesRenglon(int a,int b,int renglon);
void permutaVerticesColumna(int a,int b,int columna);
void giraDerecha(int renglon);
void giraIzquierda(int renglon);
void giraArriba(int columna);
void giraAbajo(int columna);
void arriba();
void abajo();
void derecha();
void izquierda();
//================================================================
//================================================================
//================================================================
//Funciones consulta al cubo
//================================================================
bool completado(){
  int numeroInicial=0;
  for (int j = 0; j < 6; ++j)
  {
    numeroInicial=colores[j*9];
    for(int i=0;i<9;i++){
      if(numeroInicial!=colores[j*9+i])
        return false;
    }
  }
  return true;
}

string convierteColores(){
  string nodos="";
  for (int i = 0; i < 54; ++i)
  {
     nodos+=to_string(colores[i]);
  }
  return nodos;
}
//================================================================
//Funciones para guardar el final
//================================================================
void guardarArchivo(){
  FILE* archivoTres;
    cout<<"sa"<<endl;
  archivoTres = fopen("mapa.txt", "w");
    cout<<"sa"<<endl;
  for (auto it = std::begin(mapaAccion); it!=std::end(mapaAccion); ++it){
    string numerosDelMapa=it->first;
    cout<<numerosDelMapa<<endl;
    fprintf(archivoTres, "%s %d %d %s\n",numerosDelMapa.c_str(),mapaCaminos[numerosDelMapa],mapaParametro[numerosDelMapa],mapaAccion[numerosDelMapa].c_str() );
  }
  fclose(archivoTres);

}
void guardarPasos(){

  string pasosCadena="";
  string numeracionCadena="";
  int tamanoPila=vectorPasos.size();
  for (int i = 0; i < tamanoPila; ++i)
  {
    numeracionCadena=vectorColores.top();
    pasosCadena=vectorPasos.top(); 
    if(mapaCaminos[numeracionCadena]!=0){
       if(mapaCaminos[numeracionCadena]>i+1){
          mapaCaminos[numeracionCadena]=i+1;
          mapaParametro[numeracionCadena]=vectorParametros.top();
          mapaAccion[numeracionCadena]=vectorPasos.top();
       }
    }else{
      mapaCaminos[numeracionCadena]=i+1;
      mapaParametro[numeracionCadena]=vectorParametros.top();
      mapaAccion[numeracionCadena]=vectorPasos.top();
      printf("Paso!\n");
    }
    vectorPasos.pop(); 
    vectorColores.pop();
    vectorParametros.pop();
  }
  guardarArchivo();
}
void inicializarMapa(){
  string filename="mapa.txt";
  ifstream file(filename.c_str());
  if(!file)
  {
    cout << "No hay archivo mapa.txt: " << filename << endl;
    return;
  }else{
    string lineaNumeros,lineaAccion;
    int peso,parametro;

    while(file>>lineaNumeros){
       file>>peso;
       file>>parametro;
       file>>lineaAccion;
       mapaCaminos[lineaNumeros]=peso;
       mapaParametro[lineaNumeros]=parametro;
       mapaAccion[lineaNumeros]=lineaAccion;
       cout<<lineaNumeros<<" "<<peso<<" "<<" "<<parametro<<" "<<lineaAccion<<endl;
  
    }
  }
    file.close();

}

//=================================================================
//=================================================================
//Funciones para operar en el cubo
//=================================================================

void relizarAccion(string accion,int parametro){
  bool giroBool=true;

  vectorPasos.push(accion);
  vectorParametros.push(parametro);
  vectorColores.push(convierteColores());
  if(accion=="derecha"){
    derecha();
    giroBool=false;
  }else if(accion =="izquierda"){
    izquierda();
    giroBool=false;

  }else if(accion =="arriba"){
    arriba();
    giroBool=false;

  }else if(accion =="abajo"){
    abajo();
    giroBool=false;

  }else if(accion=="giraderecha"){
    giraDerecha(parametro);
  }else if(accion =="giraizquierda"){
    giraIzquierda(parametro);
  }else if(accion =="giraarriba"){
    giraArriba(parametro);
  }else if(accion =="giraabajo"){
    giraAbajo(parametro);
  }

  cout<<convierteColores()<<endl;
  if(completado()){
    printf("listo!\n");
    guardarPasos();
  }
}

void permutaVertices(int a,int b){
    int originalA=a;
    a=a*9;
    b=b*9;
    for(int i=0;i<9;i++){
      int aux=colores[a+i];
      colores[a+i]=colores[b+i];
      colores[b+i]=aux;
    }
    
    if(originalA==3 && b==0){
      for(int i=0;i<4;i=i+1){

        int aux=colores[a+i];
        colores[a+i]=colores[a+(8-i)];
        colores[a+(8-i)]=aux;
        aux=colores[b+i];
        colores[b+i]=colores[b+(8-i)];
        colores[b+(8-i)]=aux;
      }
    }
 
}
void permutaVerticesRenglon(int a,int b,int renglon){

    a=a*9;
    b=b*9;
    for(int i=renglon*3;i<3*(renglon+1);i++){
      int aux=colores[a+i];
      colores[a+i]=colores[b+i];
      colores[b+i]=aux;
    }
   
 
}
void permutaVerticesColumna(int a,int b,int columna){

    int originalA=a;
    a=a*9;
    b=b*9;
    for(int i=columna;i<9;i=i+3){
      if(originalA==3 && b==0){

        int aux=colores[a+i];
        colores[a+i]=colores[b+8-i];
        colores[b+8-i]=aux;

      }else{

      int aux=colores[a+i];
      colores[a+i]=colores[b+i];
      colores[b+i]=aux;
      }
    }

     
 
}
void giraDerecha(int renglon){
      renglon=2-renglon;
      permutaVerticesRenglon(1,4,renglon);
      permutaVerticesRenglon(5,1,renglon);
      permutaVerticesRenglon(5,0,renglon);
      //printf("giraDerecha %d\n",renglon );
   
      int numero=-1;
      int contador=2;
      if(renglon==0){
        numero=2*9;
        contador=6;
      }
      else if(renglon==2)
        numero=3*9;
      while(numero!=-1 and contador--){
      int auxiliar=colores[numero+0];
      colores[numero+0]=colores[numero+3];
      int auxiliar2=colores[numero+1];
      colores[numero+1]=auxiliar;

      auxiliar=colores[numero+2];
      colores[numero+2]=auxiliar2;
      auxiliar2=colores[numero+5];
      colores[numero+5]=auxiliar;

      auxiliar=colores[numero+8];
      colores[numero+8]=auxiliar2;
      auxiliar2=colores[numero+7];
      colores[numero+7]=auxiliar;

      auxiliar=colores[numero+6];
      colores[numero+6]=auxiliar2;
      auxiliar2=colores[numero+3];
      colores[numero+3]=auxiliar;
      }
    
}

void giraIzquierda(int renglon){
 
     giraDerecha(renglon);
     giraDerecha(renglon);
     giraDerecha(renglon);
}
void giraArriba(int columna){
//printf("girando columna=%d\n",columna );
      
      permutaVerticesColumna(3,0,columna);
      permutaVerticesColumna(1,3,columna);
      permutaVerticesColumna(2,1,columna);
 
      int numero=-1;
      int contador=6 ;
      if(columna==0){
        numero=5*9;
        contador=2;
      }
      else if(columna==2)
        numero=4*9;
      while(numero!=-1 and contador--){
      int auxiliar=colores[numero+0];
      colores[numero+0]=colores[numero+3];
      int auxiliar2=colores[numero+1];
      colores[numero+1]=auxiliar;

      auxiliar=colores[numero+2];
      colores[numero+2]=auxiliar2;
      auxiliar2=colores[numero+5];
      colores[numero+5]=auxiliar;

      auxiliar=colores[numero+8];
      colores[numero+8]=auxiliar2;
      auxiliar2=colores[numero+7];
      colores[numero+7]=auxiliar;

      auxiliar=colores[numero+6];
      colores[numero+6]=auxiliar2;
      auxiliar2=colores[numero+3];
      colores[numero+3]=auxiliar;
      }

}
void giraAbajo(int columna){
  giraArriba(columna);
    giraArriba(columna);
      giraArriba(columna);
}
void arriba(){

      permutaVertices(3,0);
      permutaVertices(1,3);
      permutaVertices(2,1);

      int numero=3*9;
      int numeros=5;
      int repeat=0;
      while(repeat<8){
        numero=numeros*9;
        repeat++;
        if(repeat==2)
          numeros--;
      int auxiliar=colores[numero+0];
      colores[numero+0]=colores[numero+3];
      int auxiliar2=colores[numero+1];
      colores[numero+1]=auxiliar;

      auxiliar=colores[numero+2];
      colores[numero+2]=auxiliar2;
      auxiliar2=colores[numero+5];
      colores[numero+5]=auxiliar;

      auxiliar=colores[numero+8];
      colores[numero+8]=auxiliar2;
      auxiliar2=colores[numero+7];
      colores[numero+7]=auxiliar;

      auxiliar=colores[numero+6];
      colores[numero+6]=auxiliar2;
      auxiliar2=colores[numero+3];
      colores[numero+3]=auxiliar;
      }
}
void abajo(){
  arriba();
    arriba();
      arriba();
}
void derecha(){

      permutaVertices(1,4);
      permutaVertices(5,1);
      permutaVertices(5,0);

      int numero=3*9;
      int numeros=3;
      int repeat=0;
      while(repeat<8){
        numero=numeros*9;
        repeat++;
        if(repeat==2)
            numeros--;
      int auxiliar=colores[numero+0];
      colores[numero+0]=colores[numero+3];
      int auxiliar2=colores[numero+1];
      colores[numero+1]=auxiliar;

      auxiliar=colores[numero+2];
      colores[numero+2]=auxiliar2;
      auxiliar2=colores[numero+5];
      colores[numero+5]=auxiliar;

      auxiliar=colores[numero+8];
      colores[numero+8]=auxiliar2;
      auxiliar2=colores[numero+7];
      colores[numero+7]=auxiliar;

      auxiliar=colores[numero+6];
      colores[numero+6]=auxiliar2;
      auxiliar2=colores[numero+3];
      colores[numero+3]=auxiliar;
      }
}
void izquierda(){
  derecha();
    derecha();
      derecha();
}
//=================================================================
//Funciones OpenGL
//=================================================================

void dibujaVertice(int vertice){

  glLineWidth(1.0);
  glBegin(GL_QUADS);

    glColor3fv(color[colores[vertice]]);

    glVertex3iv(vertices[vertice][0]);
    glVertex3iv(vertices[vertice][1]);
    glVertex3iv(vertices[vertice][3]);
    glVertex3iv(vertices[vertice][2]);

  glEnd();
  glLineWidth(4.0);
  glBegin(GL_LINE_STRIP);

    glColor3fv(color[7]);
    glVertex3iv(vertices[vertice][0]);
    glVertex3iv(vertices[vertice][1]);
    glVertex3iv(vertices[vertice][3]);
    glVertex3iv(vertices[vertice][2]);
    glVertex3iv(vertices[vertice][0]);
  glEnd();
}
void cuboRubik()
{
  glColor3f(1.0,1.0,1.0);
  time(&horaActual);
  double segundos=difftime(horaActual,horaInicio);
  string cadena="Puntaje : "+to_string(segundos);
  string parametroCadena;
  string accionPosible;
  string numeroColores=convierteColores();
  if(mapaCaminos[numeroColores]!=0){
    accionPosible = mapaAccion[numeroColores];
    int parametroNumero=mapaParametro[numeroColores];

    if(accionPosible == "giraizquierda" || accionPosible == "giraderecha"){
      parametroCadena=parametroNumero==0?"Techo":(parametroNumero==1?"Centro":"Piso");
    }else  if(accionPosible == "giraarriba" || accionPosible == "giraabajo"){
      parametroCadena=parametroNumero==0?"Izquierda":(parametroNumero==1?"Centro":"Derecha");
    }else{
      parametroCadena="";
    }
     cadena=cadena+" pista: "+accionPosible+" parametro: "+parametroCadena;
  }

   
  glRasterPos2i( -14, 6);
  for (int i = 0; i < cadena.size(); ++i)
  {
    /* code */
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, cadena[i]);
  }
  
 for(int i=0;i<54;i=i+1){ 
  dibujaVertice(i); 
 }
 
}


//=================================================================
//=================================================================
//Funciones para operar en el cubo
//=================================================================

void specialKeys( int key, int x, int y )
{
    string accionHacer="";
    if (key == GLUT_KEY_RIGHT){
      accionHacer="derecha";
      printf("derecha  \n" );
    }
    else if (key == GLUT_KEY_LEFT){
      accionHacer="izquierda";
      printf("izquierda  \n" );
    }
    else if (key == GLUT_KEY_UP){
      accionHacer="arriba";
      printf("arriba  \n" );
    }else if (key == GLUT_KEY_DOWN){
      accionHacer="abajo";
      printf("abajo  \n" );
    }

    relizarAccion(accionHacer,0);
    glutPostRedisplay();
}

void teclado(unsigned char key,int x, int y){
  if (key == 'd')
  rotate_x-=10;
  else if (key == 'a')
  rotate_x+=10;
  else if (key == 's')
  rotate_y+=10;
  else if (key == 'w')
  rotate_y-=10;
  glutPostRedisplay();
}
void display()
{

  //scanf("%d ",&numeroInicio);

    glClearColor( 0, 0, 0, 1 );
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    int w = glutGet( GLUT_WINDOW_WIDTH );
    int h = glutGet( GLUT_WINDOW_HEIGHT );
    gluPerspective( 60, w / h, 0.1, 100 );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt
        (
        10, 4, 4,
        0, 0, 0,
        0, 1, 0
        );


    glRotatef( rotate_x, 0.0, 0.0, 1.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    //glRotatef(rotate_z,1.0,0.0,0.0);
  //  glTranslatef(translate_x, translate_y, 0.0 );

    cuboRubik();
    glPointSize(7.0);
    glBegin(GL_POINTS);

    glVertex3f(3.0,-3.0,-3.0);
    glVertex3f(3.0,3.0,-3.0);
    glVertex3f(3.0,-3.0,3.0);
    glVertex3f(3.0,3.0,3.0);
    glEnd();
    glutSwapBuffers();
}
void motion(int x,int y){

}
int cuadrante(int a,int b){
  float desplasamientoX=(float)(X11-X22)/3;
  float desplasamientoY=(float)(Y12-Y11)/3;
  if(a<=X11&&b<=Y12){
      for(int i=0;i<3;i++)
          for(int j=0;j<3;j++){

            if(a>=X22+desplasamientoX*j && a<=X22+desplasamientoX*(j+1)&&b>=Y11+desplasamientoY*i && b<=Y11+desplasamientoY*(i+1) )
            {
              cuadranteX=j;
              cuadranteY=i;
              //printf("cuadrante %d,%d\n",i,j );
               return i*j;
            }
          }
  }else{
    return -1;
  }
  return -1;
}
void mouseClickHandler(int button, int state, int x, int y)
{
  int ancho=GLUT_WINDOW_WIDTH;
  int alto=GLUT_WINDOW_HEIGHT;
  if(anteriorH!=alto || anteriorW!=ancho){
    anteriorH=GLUT_WINDOW_WIDTH;
    anteriorW=GLUT_WINDOW_HEIGHT;
        GLdouble X, Y, Z; // target 2d coords (z is 'unused')
        GLdouble coords[] = { 3.0, -3.0, -3.0 }; // current 3d coords

        GLdouble model_view[16];

        GLdouble projection[16];

        GLint viewport[4];
        glGetDoublev(GL_MODELVIEW_MATRIX, model_view);
        glGetDoublev(GL_PROJECTION_MATRIX, projection);
        glGetIntegerv(GL_VIEWPORT, viewport);

        gluProject( coords[0], coords[1], coords[2],  model_view, projection, viewport,&X, &Y, &Z);
        X11=X;
        Y11=Y;
        glGetDoublev(GL_MODELVIEW_MATRIX, model_view);
        glGetDoublev(GL_PROJECTION_MATRIX, projection);
        glGetIntegerv(GL_VIEWPORT, viewport);
        gluProject( 3-0,-3.0,3.0,  model_view, projection, viewport,  &X, &Y, &Z);
        X21=X;
        Y21=Y;
        glGetDoublev(GL_MODELVIEW_MATRIX, model_view);
        glGetDoublev(GL_PROJECTION_MATRIX, projection);
        glGetIntegerv(GL_VIEWPORT, viewport);
        gluProject( 3-0,3.0,-3.0,  model_view, projection, viewport,  &X, &Y, &Z);
        X12=X;
        Y12=Y+100;
        glGetDoublev(GL_MODELVIEW_MATRIX, model_view);
        glGetDoublev(GL_PROJECTION_MATRIX, projection);
        glGetIntegerv(GL_VIEWPORT, viewport);
        gluProject( 3-0,3.0,3.0,  model_view, projection, viewport,  &X, &Y, &Z);
        X22=X;
        Y22=Y;;
        //printf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\n", X11,X12,X21,X22, Y11,Y12,Y21,Y22);

  }
  int anteriorA=cuadranteX,anteriorB=cuadranteY;
  cuadrante(x,y);
  if(state==1){
    if(anteriorA!=cuadranteX || anteriorB!=cuadranteY){
      string accionHacer="";
      int opcionHacer=-1;
        if(anteriorA<cuadranteX && anteriorB== cuadranteY){
         printf("derecha renglon: %d \n",cuadranteY );
         accionHacer="giraderecha";
         opcionHacer=cuadranteY;
       }else if(anteriorA>cuadranteX && anteriorB== cuadranteY){
          printf("izquierda renglon: %d \n",cuadranteY );
         accionHacer="giraizquierda";
         opcionHacer=cuadranteY;
       }else if(anteriorB>cuadranteY && anteriorA== cuadranteX){
          printf("Arriba columna: %d\n",cuadranteX);
           accionHacer="giraarriba";
           opcionHacer=cuadranteX;
       }else if(anteriorB<cuadranteY && anteriorA== cuadranteX){
          printf("Abajo  columna: %d\n",cuadranteX);
           accionHacer="giraabajo";
           opcionHacer=cuadranteX;
       
       }
      if(opcionHacer!=-1)
       relizarAccion(accionHacer,opcionHacer);
    }

    glutPostRedisplay();
  }


}

//=================================================================
//=================================================================
//Funciones para personalizar la corrida
//=================================================================
void dificultad(int dif){
  for (int i = 0; i < dif; ++i)
  {
    int opcion=rand()%3;
    int orientacion=(rand()*i+3)%2;
    int orientacion2=(rand()*i+323+i)%2;
    if(orientacion2==0){
      if(orientacion==1){
          giraArriba(opcion);
      }else{
          giraAbajo(opcion);
      }
    }else if(orientacion2==1){
       if(orientacion==1){
          giraDerecha(opcion);
      }else{
          giraIzquierda(opcion);
      }
    }
  }
}
void init(int dif){
  inicializarMapa();
  dificultad(dif);
  time(&horaInicio);
 
}
//=================================================================
//=================================================================
int main( int argc, char **argv )
{
    int dif=1;
    printf("¿Qué dificultad deseas tener?: \n");
    scanf("%d",&dif);
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE );
    glutInitWindowSize( 640, 480 );
    glutCreateWindow( "GLUT" );
    glutDisplayFunc( display );
    glutSpecialFunc( specialKeys );
    glutKeyboardFunc(teclado);
    glutMouseFunc(mouseClickHandler);
    glutMotionFunc(motion);
    glEnable( GL_DEPTH_TEST );
     
    init(dif);
    glutMainLoop();
    return 0;
}