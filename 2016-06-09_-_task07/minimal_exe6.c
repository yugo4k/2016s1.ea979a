#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

typedef struct {
  GLdouble eyeX;
  GLdouble eyeY;
  GLdouble eyeZ;
  GLdouble centerX;
  GLdouble centerY;
  GLdouble centerZ;
  GLdouble upX;
  GLdouble upY;
  GLdouble upZ;

  int perc_fovy;
  int perc_aspect;

  int w;
  int h;
} Perspective;

static Perspective perspective;

static void reset() {
    perspective.eyeX = 0.;
    perspective.eyeY = 0.;
    perspective.eyeZ = 4.;
    perspective.centerX = 0.;
    perspective.centerY = 0.;
    perspective.centerZ = 0.;
    perspective.upX = 0.;
    perspective.upY = 1.;
    perspective.upZ = 0.;

    perspective.perc_fovy = 100;
    perspective.perc_aspect = 100;
}

static int camera = 0;

void init(void) {
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}


void display(void) {
   glClear (GL_COLOR_BUFFER_BIT);

   glPushMatrix();
   glRotatef ((GLfloat) camera, 1.0, 0.0, 0.0);
   glColor3f(1.0f,1.0f,0.0f);
   glutWireSphere(1.0, 22, 20);
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) camera, 1.0, 0.0, 0.0);
   glColor3f(1.0f,0.0f,0.0f);
   glTranslated(0.0,-1.2,-1);
   glutWireSphere(0.4, 22, 20);
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) camera, 1.0, 0.0, 0.0);
   glColor3f(1.0f,1.0f,1.0f);
   glTranslated(0.0,1.2,1);
   glutWireSphere(0.4, 22, 20);
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) camera, 1.0, 0.0, 0.0);
   glColor3f(0.0f,1.0f,1.0f);
   glTranslated(0.0,-1,1.2);
   glutWireSphere(0.4, 22, 20);
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) camera, 1.0, 0.0, 0.0);
   glColor3f(0.0f,0.0f,1.0f);
   glTranslated(0.0,1,-1.2);
   glutWireSphere(0.4, 22, 20);
   glPopMatrix(); 



   glutSwapBuffers();
}


void reshape(int w, int h) {
  GLdouble fovy = 60., aspect = (GLfloat) w / (GLfloat) h, zNear = 1., zFar = 20.;
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(fovy * perspective.perc_fovy / 100.,
		 aspect * perspective.perc_aspect / 100.,
		 zNear,
		 zFar);
  /* gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0); */
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(perspective.eyeX, perspective.eyeY, perspective.eyeZ,
	    perspective.centerX, perspective.centerY, perspective.centerZ,
	    perspective.upX, perspective.upY, perspective.upZ);
  perspective.w = w;
  perspective.h = h;
}


void keyboard (unsigned char key, int x, int y) {
  switch (key) {
  case 'c':
    camera = (camera + 10) % 360;
    break;
  case 'C':
    camera = (camera - 10) % 360;
    break;
  case 'v':
    perspective.perc_fovy += 2;
    break;
  case 'V':
    perspective.perc_fovy -= 2;
    break;
  case 'a':
    perspective.perc_aspect += 2;
    break;
  case 'A':
    perspective.perc_aspect -= 2;
    break;
  case 'x':
    perspective.eyeX += .5;
    perspective.centerX += .5;
    break;
  case 'X':
    perspective.eyeX -= .5;
    perspective.centerX -= .5;
    break;
  case 'y':
    perspective.eyeY += .5;
    perspective.centerY += .5;
    break;
  case 'Y':
    perspective.eyeY -= .5;
    perspective.centerY -= .5;
    break;
  case 'z':
    perspective.eyeZ += .5;
    perspective.centerZ += .5;
    break;
  case 'Z':
    perspective.eyeZ -= .5;
    perspective.centerZ -= .5;
    break;
  default:
    return;
  }
  reshape(perspective.w, perspective.h);
  glutPostRedisplay();
}


int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);

   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);

   init();
   reset();

   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);

   glutMainLoop();
   
   return 0;
}
