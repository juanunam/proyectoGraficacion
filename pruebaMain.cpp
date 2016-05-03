#include <GL/glut.h>
#include<cmath>
#include<stdio.h>
#define PI 3.141592
int vertices[54][4][3]=
{
// Cara 1
 { //vertice 1
  {-3,-3,-3},  {-3,-3,-1},  {-3,-1,-3},  {-3,-1,-1}
 },
 { //vertice 2
  {-3,-1,-3},  {-3,-1,-1},  {-3,1,-3},  {-3,1,-1}
 },
 { //vertice 3
  {-3,1,-3},  {-3,1,-1},  {-3,3,-3},  {-3,3,-1}
 },
 { //vertice 4
  {-3,-3,-1},  {-3,-3,1},  {-3,-1,-1},  {-3,-1,1}
 },
 { //vertice 5
  {-3,-1,-1},  {-3,-1,1},  {-3,1,-1},  {-3,1,1}
 },
 { //vertice 6
  {-3,1,-1},  {-3,1,1},  {-3,3,-1},  {-3,3,1}
 },
 { //vertice 7
  {-3,-3,1},  {-3,-3,3},  {-3,-1,1},  {-3,-1,3}
 },
 { //vertice 8
  {-3,-1,1},  {-3,-1,3},  {-3,1,1},  {-3,1,3}
 },
 { //vertice 9
  {-3,1,1},  {-3,1,3},  {-3,3,1},  {-3,3,3}
 },
// Cara 2
 { //vertice 10
  {3,-3,-3},  {3,-3,-1},  {3,-1,-3},  {3,-1,-1}
 },
 { //vertice 11
  {3,-1,-3},  {3,-1,-1},  {3,1,-3},  {3,1,-1}
 },
 { //vertice 12
  {3,1,-3},  {3,1,-1},  {3,3,-3},  {3,3,-1}
 },
 { //vertice 13
  {3,-3,-1},  {3,-3,1},  {3,-1,-1},  {3,-1,1}
 },
 { //vertice 14
  {3,-1,-1},  {3,-1,1},  {3,1,-1},  {3,1,1}
 },
 { //vertice 15
  {3,1,-1},  {3,1,1},  {3,3,-1},  {3,3,1}
 },
 { //vertice 16
  {3,-3,1},  {3,-3,3},  {3,-1,1},  {3,-1,3}
 },
 { //vertice 17
  {3,-1,1},  {3,-1,3},  {3,1,1},  {3,1,3}
 },
 { //vertice 18
  {3,1,1},  {3,1,3},  {3,3,1},  {3,3,3}
 },
// Cara 3
 { //vertice 19
  {-3,-3,-3},  {-3,-3,-1},  {-1,-3,-3},  {-1,-3,-1}
 },
 { //vertice 20
  {-1,-3,-3},  {-1,-3,-1},  {1,-3,-3},  {1,-3,-1}
 },
 { //vertice 21
  {1,-3,-3},  {1,-3,-1},  {3,-3,-3},  {3,-3,-1}
 },
 { //vertice 22
  {-3,-3,-1},  {-3,-3,1},  {-1,-3,-1},  {-1,-3,1}
 },
 { //vertice 23
  {-1,-3,-1},  {-1,-3,1},  {1,-3,-1},  {1,-3,1}
 },
 { //vertice 24
  {1,-3,-1},  {1,-3,1},  {3,-3,-1},  {3,-3,1}
 },
 { //vertice 25
  {-3,-3,1},  {-3,-3,3},  {-1,-3,1},  {-1,-3,3}
 },
 { //vertice 26
  {-1,-3,1},  {-1,-3,3},  {1,-3,1},  {1,-3,3}
 },
 { //vertice 27
  {1,-3,1},  {1,-3,3},  {3,-3,1},  {3,-3,3}
 },
// Cara 4
 { //vertice 28
  {-3,3,-3},  {-3,3,-1},  {-1,3,-3},  {-1,3,-1}
 },
 { //vertice 29
  {-1,3,-3},  {-1,3,-1},  {1,3,-3},  {1,3,-1}
 },
 { //vertice 30
  {1,3,-3},  {1,3,-1},  {3,3,-3},  {3,3,-1}
 },
 { //vertice 31
  {-3,3,-1},  {-3,3,1},  {-1,3,-1},  {-1,3,1}
 },
 { //vertice 32
  {-1,3,-1},  {-1,3,1},  {1,3,-1},  {1,3,1}
 },
 { //vertice 33
  {1,3,-1},  {1,3,1},  {3,3,-1},  {3,3,1}
 },
 { //vertice 34
  {-3,3,1},  {-3,3,3},  {-1,3,1},  {-1,3,3}
 },
 { //vertice 35
  {-1,3,1},  {-1,3,3},  {1,3,1},  {1,3,3}
 },
 { //vertice 36
  {1,3,1},  {1,3,3},  {3,3,1},  {3,3,3}
 },
// Cara 5
 { //vertice 37
  {-3,-3,-3},  {-3,-1,-3},  {-1,-3,-3},  {-1,-1,-3}
  },
 { //vertice 38
  {-1,-3,-3},  {-1,-1,-3},  {1,-3,-3},  {1,-1,-3}
  },
 { //vertice 39
  {1,-3,-3},  {1,-1,-3},  {3,-3,-3},  {3,-1,-3}
  },
 { //vertice 40
  {-3,-1,-3},  {-3,1,-3},  {-1,-1,-3},  {-1,1,-3}
  },
 { //vertice 41
  {-1,-1,-3},  {-1,1,-3},  {1,-1,-3},  {1,1,-3}
  },
 { //vertice 42
  {1,-1,-3},  {1,1,-3},  {3,-1,-3},  {3,1,-3}
  },
 { //vertice 43
  {-3,1,-3},  {-3,3,-3},  {-1,1,-3},  {-1,3,-3}
  },
 { //vertice 44
  {-1,1,-3},  {-1,3,-3},  {1,1,-3},  {1,3,-3}
  },
 { //vertice 45
  {1,1,-3},  {1,3,-3},  {3,1,-3},  {3,3,-3}
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
{
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
1,
1,
1,
1,
1,
1,
1,
2,
2,
2,
2,
2,
2,
2,
2,
2,
3,
3,
3,
3,
3,
3,
3,
3,
3,
4,
4,
4,
4,
4,
4,
4,
4,
4,
5,
5,
5,
5,
5,
5,
5,
5,
5
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
    {0.0,0.0,0.0},//negro
};
void permutaVertices(int a,int b){
  a=a*9;
  b=b*9;
  for(int i=0;i<9;i++){
    int aux=colores[a+i];
    colores[a+i]=colores[b+i];
    colores[b+i]=aux;
  }
}
void arriba(){

      permutaVertices(3,0);
      permutaVertices(1,3);
      permutaVertices(2,1);


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

}
void izquierda(){
  derecha();
    derecha();
      derecha();
}

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
  glRasterPos2i( 0, 0);
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');
  for (int i = 0; i < 54; i++) {
    dibujaVertice(i);
  }
}

double rotate_z = 0;
double rotate_y = 0;
double rotate_x = 0;

void specialKeys( int key, int x, int y )
{

     if (key == GLUT_KEY_RIGHT)
        derecha();
    else if (key == GLUT_KEY_LEFT)
      izquierda();
    else if (key == GLUT_KEY_UP)
        arriba();
    else if (key == GLUT_KEY_DOWN)
        abajo();


    glutPostRedisplay();
}

double translate_x=0;
double translate_y=0;
void teclado(unsigned char key,int x, int y){
  if (key == 'd')
  translate_x-=1;
  else if (key == 'a')
  translate_x+=1;
  else if (key == 's')
  translate_y+=1;
  else if (key == 'w')
  translate_y-=1;
  glutPostRedisplay();
}
void display()
{
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
    glRotatef(rotate_z,1.0,0.0,0.0);
  //  glTranslatef(translate_x, translate_y, 0.0 );

    cuboRubik();

    glutSwapBuffers();
}
int anteriorW=0;
int anteriorH=0;
int cuadranteX,cuadranteY;
double X11,X12,X21,X22,Y11,Y12,Y21,Y22;
void motion(int x,int y){

}
int cuadrante(int a,int b){
  float desplasamientoX=(float)(X11-X22)/3;
    float desplasamientoY=(float)(Y12-Y11)/3;
    printf("%lf,%lf\n", X11,Y12);
  if(a<=X11&&b<=Y12){
      for(int i=0;i<3;i++)
          for(int j=0;j<3;j++){

            if(a>=X22+desplasamientoX*j && a<=X22+desplasamientoX*(j+1)&&b>=Y11+desplasamientoY*i && b<=Y11+desplasamientoY*(i+1) )
            {
              cuadranteX=j;
              cuadranteY=i;
              printf("cuadrante %d,%d\n",i,j );
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
        printf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\n", X11,X12,X21,X22, Y11,Y12,Y21,Y22);

  }
    int anteriorA=cuadranteX,anteriorB=cuadranteY;

    printf("%dcuadrante:%d %d,%d\n",state,cuadrante(x,y),x,y );
    if(state==1){
      if(anteriorA!=cuadranteX || anteriorB!=cuadranteY){
        if(anteriorA<cuadranteX && anteriorB== cuadranteY)
         printf("derecha!!\n" );
         else if(anteriorA>cuadranteX && anteriorB== cuadranteY)
          printf("izquierda!!\n" );
        else if(anteriorB>cuadranteY && anteriorA== cuadranteX)
         printf("Arriba!!\n");
         else if(anteriorB<cuadranteY && anteriorA== cuadranteX)
          printf("Abajp!!\n" );
      }
    }


}
int main( int argc, char **argv )
{
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
    glutMainLoop();
    return 0;
}
