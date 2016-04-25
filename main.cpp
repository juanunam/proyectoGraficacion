#include <GL/glut.h>

float vertices[8][3] =
{
    {-1.0,-1.0,1.0},
    {-1.0,1.0,1.0},
    {1.0,1.0,1.0},
    {1.0,-1.0,1.0},
    {-1.0,-1.0,-1.0},
    {-1.0,1.0,-1.0},
    {1.0,1.0,-1.0},
    {1.0,-1.0,-1.0},
};

GLfloat color[8][3] =
{
    {0.0,1.0,0.0},
    {1.0,0.0,0.0},
    {1.0,1.0,0.0},
    {1.0,1.0,1.0},
    {0.0,0.0,1.0},
    {1.0,0.0,1.0},
    {1.0,1.0,1.0},
    {0.0,1.0,1.0},
};
int cara=0;
void quad(int a,int b,int c,int d)
{
    glBegin(GL_QUADS);
    glColor3fv(color[cara]);
    cara++;
    glVertex3fv(vertices[a]);

    glVertex3fv(vertices[b]);

    glVertex3fv(vertices[c]);

    glVertex3fv(vertices[d]);
    glEnd();
}

void colorcube()
{
    quad(0,3,2,1);
    quad(2,3,7,6);
    quad(0,4,7,3);
    quad(1,2,6,5);
    quad(4,5,6,7);
    quad(0,1,5,4);
    cara=0;
}

double rotate_y = 0;
double rotate_x = 0;

void specialKeys( int key, int x, int y )
{
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 5;
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;
    else if (key == GLUT_KEY_UP)
        rotate_x += 5;
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;

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
        3, 3, 3,
        0, 0, 0,
        0, 0, 1
        );

    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );

    glTranslatef(translate_x, translate_y, 0.0 );

    colorcube();

    glutSwapBuffers();
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
    glEnable( GL_DEPTH_TEST );
    glutMainLoop();
    return 0;
}
