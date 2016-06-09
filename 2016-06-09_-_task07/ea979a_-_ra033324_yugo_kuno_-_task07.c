/* by yugo kuno, ra033324 */
/* copyleft material: free to reuse, but acknowledgement required! */
/* ea979a, task07 */
/* 2016-06-08 */

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

typedef struct {
  GLdouble eyeR;
  GLdouble deg_theta;
  GLdouble deg_psi;
  GLdouble eyeX;
  GLdouble eyeY;
  GLdouble eyeZ;
  GLdouble centerX;
  GLdouble centerY;
  GLdouble centerZ;
  GLdouble upX;
  GLdouble upY;
  GLdouble upZ;
} Perspective;

Perspective perspective;


static void update_eye() {
  double rad_theta = perspective.deg_theta * 2. * M_PI / 360.;
  double rad_psi = perspective.deg_psi * 2. * M_PI / 360.;
  perspective.eyeX = perspective.eyeR * sin(rad_theta) * cos(rad_psi);
  perspective.eyeY = perspective.eyeR * sin(rad_theta) * sin(rad_psi);
  perspective.eyeZ = perspective.eyeR * cos(rad_theta);

  perspective.upX = - cos(rad_theta) * cos(rad_psi);
  perspective.upY = - cos(rad_theta) * sin(rad_psi);
  perspective.upZ = sin(rad_theta);
}


static void reset() {
    perspective.eyeR = 5.;
    perspective.deg_theta = 30.;
    perspective.deg_psi = 150.;
    perspective.centerX = 0.;
    perspective.centerY = 0.;
    perspective.centerZ = 0.;
    update_eye();
}


static void tetrahedron(GLfloat trnsl_x, GLfloat trnsl_y, GLfloat trnsl_z,
			GLfloat deg_x, GLfloat deg_y, GLfloat deg_z) {
  GLfloat rot_x = 0., rot_y = 0., rot_z = 0.;
  GLfloat glf_red = 0., glf_green = 0., glf_blue = 0., glf_alpha = .01;
  /* glPushMatrix pushes the current matrix stack down by one, duplicating the current matrix.
     That is, after a glPushMatrix call, the matrix on top of the stack is identical to the one below it. */
  glPushMatrix();
  /* glRotate produces a rotation of angle degrees around the vector (x, y, z).
     The current matrix is multiplied by a rotation matrix with the product replacing the current matrix */
  rot_x = 1., rot_y = 0., rot_z = 0.;
  glRotatef(deg_x, rot_x, rot_y, rot_z);
  rot_x = 0., rot_y = 1., rot_z = 0.;
  glRotatef(deg_y, rot_x, rot_y, rot_z);
  rot_x = 0., rot_y = 0., rot_z = 1.;
  glRotatef(deg_z, rot_x, rot_y, rot_z);
  /* glTranslate produces a translation by (x, y, z).
     The current matrix is multiplied by this translation matrix, with the product replacing the current matrix */
  glTranslatef(trnsl_x, trnsl_y, trnsl_z);

  glBegin(GL_TRIANGLES);

  glf_red = 1.; glf_green = 1.; glf_blue = 0.; glf_alpha = 1.;
  glColor4f(glf_red, glf_green, glf_blue, glf_alpha);
  glVertex3d(-1.000, -0.500,  0.000);
  glVertex3d( 1.000, -0.500,  0.000);
  glVertex3d( 0.000,  1.232,  0.000);

  glf_red = 0.; glf_green = 1.; glf_blue = 0.; glf_alpha = 1.;
  glColor4f(glf_red, glf_green, glf_blue, glf_alpha);
  glVertex3d(-1.000, -0.500,  0.000);
  glVertex3d( 1.000, -0.500,  0.000);
  glVertex3d( 0.000,  0.000,  1.658);

  glf_red = 0.; glf_green = 0.; glf_blue = 1.; glf_alpha = 1.;
  glColor4f(glf_red, glf_green, glf_blue, glf_alpha);
  glVertex3d( 1.000, -0.500,  0.000);
  glVertex3d( 0.000,  1.232,  0.000);
  glVertex3d( 0.000,  0.000,  1.658);

  glf_red = 1.; glf_green = 0.; glf_blue = 0.; glf_alpha = 1.;
  glColor4f(glf_red, glf_green, glf_blue, glf_alpha);
  glVertex3d(-1.000, -0.500,  0.000);
  glVertex3d( 0.000,  1.232,  0.000);
  glVertex3d( 0.000,  0.000,  1.658);

  glEnd();

  /* glPopMatrix pops the current matrix stack, replacing the current matrix with the one below it on the stack. */
  glPopMatrix();
}


static void pill6side(GLfloat trnsl_x, GLfloat trnsl_y, GLfloat trnsl_z,
		       GLfloat deg_x, GLfloat deg_y, GLfloat deg_z) {
  GLfloat rot_x = 0., rot_y = 0., rot_z = 0.;
  GLfloat glf_red = 0., glf_green = 0., glf_blue = 0., glf_alpha = .01;
  /* glPushMatrix pushes the current matrix stack down by one, duplicating the current matrix.
     That is, after a glPushMatrix call, the matrix on top of the stack is identical to the one below it. */
  glPushMatrix();
  /* glRotate produces a rotation of angle degrees around the vector (x, y, z).
     The current matrix is multiplied by a rotation matrix with the product replacing the current matrix */
  rot_x = 1., rot_y = 0., rot_z = 0.;
  glRotatef(deg_x, rot_x, rot_y, rot_z);
  rot_x = 0., rot_y = 1., rot_z = 0.;
  glRotatef(deg_y, rot_x, rot_y, rot_z);
  rot_x = 0., rot_y = 0., rot_z = 1.;
  glRotatef(deg_z, rot_x, rot_y, rot_z);
  /* glTranslate produces a translation by (x, y, z).
     The current matrix is multiplied by this translation matrix, with the product replacing the current matrix */
  glTranslatef(trnsl_x, trnsl_y, trnsl_z);

  glBegin(GL_TRIANGLES);

  glf_red = 1.; glf_green = 1.; glf_blue = 0.; glf_alpha = 1.;
  glColor4f(glf_red, glf_green, glf_blue, glf_alpha);
  glVertex3d( 0.000,  0.000,  0.500);
  glVertex3d( 0.000,  1.000,  0.000);
  glVertex3d( 0.866,  0.500,  0.000);
  glEnd();

  /* glPopMatrix pops the current matrix stack, replacing the current matrix with the one below it on the stack. */
  glPopMatrix();
}


static void pill6(GLfloat trnsl_x, GLfloat trnsl_y, GLfloat trnsl_z,
		  GLfloat deg_x, GLfloat deg_y, GLfloat deg_z) {
  GLfloat rot_x = 0., rot_y = 0., rot_z = 0.;
  int i = 0, j = 0;
  /* glPushMatrix pushes the current matrix stack down by one, duplicating the current matrix.
     That is, after a glPushMatrix call, the matrix on top of the stack is identical to the one below it. */
  glPushMatrix();
  /* glRotate produces a rotation of angle degrees around the vector (x, y, z).
     The current matrix is multiplied by a rotation matrix with the product replacing the current matrix */
  rot_x = 1., rot_y = 0., rot_z = 0.;
  glRotatef(deg_x, rot_x, rot_y, rot_z);
  rot_x = 0., rot_y = 1., rot_z = 0.;
  glRotatef(deg_y, rot_x, rot_y, rot_z);
  rot_x = 0., rot_y = 0., rot_z = 1.;
  glRotatef(deg_z, rot_x, rot_y, rot_z);
  /* glTranslate produces a translation by (x, y, z).
     The current matrix is multiplied by this translation matrix, with the product replacing the current matrix */
  glTranslatef(trnsl_x, trnsl_y, trnsl_z);

  for (j = 0; j < 2; ++j) {
    for (i = 0; i < 6; ++i) {
      trnsl_x = 0., trnsl_y = 0., trnsl_z = 0.;
      deg_y = j * 180., deg_x = 0., deg_z = i * 60.;
      pill6side(trnsl_x, trnsl_y, trnsl_z, deg_x, deg_y, deg_z);
    }
  }

  /* glPopMatrix pops the current matrix stack, replacing the current matrix with the one below it on the stack. */
  glPopMatrix();
}


static void star5point(GLfloat trnsl_x, GLfloat trnsl_y, GLfloat trnsl_z,
		       GLfloat deg_x, GLfloat deg_y, GLfloat deg_z) {
  GLfloat rot_x = 0., rot_y = 0., rot_z = 0.;
  GLfloat glf_red = 0., glf_green = 0., glf_blue = 0., glf_alpha = .01;
  /* glPushMatrix pushes the current matrix stack down by one, duplicating the current matrix.
     That is, after a glPushMatrix call, the matrix on top of the stack is identical to the one below it. */
  glPushMatrix();
  /* glRotate produces a rotation of angle degrees around the vector (x, y, z).
     The current matrix is multiplied by a rotation matrix with the product replacing the current matrix */
  rot_x = 1., rot_y = 0., rot_z = 0.;
  glRotatef(deg_x, rot_x, rot_y, rot_z);
  rot_x = 0., rot_y = 1., rot_z = 0.;
  glRotatef(deg_y, rot_x, rot_y, rot_z);
  rot_x = 0., rot_y = 0., rot_z = 1.;
  glRotatef(deg_z, rot_x, rot_y, rot_z);
  /* glTranslate produces a translation by (x, y, z).
     The current matrix is multiplied by this translation matrix, with the product replacing the current matrix */
  glTranslatef(trnsl_x, trnsl_y, trnsl_z);

  glBegin(GL_TRIANGLES);

  glf_red = 0.; glf_green = 1.; glf_blue = 1.; glf_alpha = 1.;
  glColor4f(glf_red, glf_green, glf_blue, glf_alpha);
  glVertex3d( 0.000,  0.000,  0.200);
  glVertex3d( 0.000,  1.500,  0.000);
  glVertex3d( 0.300,  0.000,  0.000);

  glf_red = 0.; glf_green = 0.; glf_blue = 1.; glf_alpha = 1.;
  glColor4f(glf_red, glf_green, glf_blue, glf_alpha);
  glVertex3d( 0.000,  0.000,  0.200);
  glVertex3d( 0.000,  1.500,  0.000);
  glVertex3d(-0.300,  0.000,  0.000);

  glEnd();

  /* glPopMatrix pops the current matrix stack, replacing the current matrix with the one below it on the stack. */
  glPopMatrix();
}


static void star5(GLfloat trnsl_x, GLfloat trnsl_y, GLfloat trnsl_z,
		  GLfloat deg_x, GLfloat deg_y, GLfloat deg_z) {
  GLfloat rot_x = 0., rot_y = 0., rot_z = 0.;
  int i = 0, j = 0;
  /* glPushMatrix pushes the current matrix stack down by one, duplicating the current matrix.
     That is, after a glPushMatrix call, the matrix on top of the stack is identical to the one below it. */
  glPushMatrix();
  /* glRotate produces a rotation of angle degrees around the vector (x, y, z).
     The current matrix is multiplied by a rotation matrix with the product replacing the current matrix */
  rot_x = 1., rot_y = 0., rot_z = 0.;
  glRotatef(deg_x, rot_x, rot_y, rot_z);
  rot_x = 0., rot_y = 1., rot_z = 0.;
  glRotatef(deg_y, rot_x, rot_y, rot_z);
  rot_x = 0., rot_y = 0., rot_z = 1.;
  glRotatef(deg_z, rot_x, rot_y, rot_z);
  /* glTranslate produces a translation by (x, y, z).
     The current matrix is multiplied by this translation matrix, with the product replacing the current matrix */
  glTranslatef(trnsl_x, trnsl_y, trnsl_z);

  for (j = 0; j < 2; ++j) {
    for (i = 0; i < 5; ++i) {
      trnsl_x = 0., trnsl_y = 0., trnsl_z = 0.;
      deg_y = j * 180., deg_x = 0., deg_z = i * 72.;
      star5point(trnsl_x, trnsl_y, trnsl_z, deg_x, deg_y, deg_z);
    }
  }

  /* glPopMatrix pops the current matrix stack, replacing the current matrix with the one below it on the stack. */
  glPopMatrix();
}


static void display() {
  GLclampf glclmp_red = 0., glclmp_green = 0., glclmp_blue = 0., glclmp_alpha = 0.;
  GLfloat trnsl_x = 0., trnsl_y = 0., trnsl_z = 0.;
  GLfloat deg_x = 0., deg_y = 0., deg_z = 0.;

  /* Applies subsequent matrix operations to the modelview matrix stack. */
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  /* gluLookAt creates a viewing matrix derived from an eye point, a reference
     point indicating the center of the scene, and an up vector. */
  update_eye();
  gluLookAt(perspective.eyeX, perspective.eyeY, perspective.eyeZ,
	    perspective.centerX, perspective.centerY, perspective.centerZ,
	    perspective.upX, perspective.upY, perspective.upZ);

  /* Specify the red, green, blue, and alpha values used when the color buffers are cleared. The initial values are all 0. */
  glclmp_red = 0., glclmp_green = 0., glclmp_blue = 0., glclmp_alpha = 1.;
  /* glClearColor specifies the red, green, blue, and alpha values used by glClear to clear the color buffers.
     Values specified by glClearColor are clamped to the range [0, 1]. */
  glClearColor(glclmp_red, glclmp_green, glclmp_blue, glclmp_alpha);
  /* glClear sets the bitplane area of the window to values previously selected by
     glClearColor, glClearIndex, glClearDepth, glClearStencil, and glClearAccum. */
  /* glClear(GL_COLOR_BUFFER_BIT); */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  trnsl_x = .5, trnsl_y = .5, trnsl_z = -2.;
  deg_x = 0., deg_y = 0., deg_z = 0.;
  tetrahedron(trnsl_x, trnsl_y, trnsl_z, deg_x, deg_y, deg_z);

  trnsl_x = -.5, trnsl_y = -.5, trnsl_z = 2.;
  deg_x = 0., deg_y = 0., deg_z = 0.;
  pill6(trnsl_x, trnsl_y, trnsl_z, deg_x, deg_y, deg_z);

  trnsl_x = 0., trnsl_y = 0., trnsl_z = 0.;
  deg_x = 0., deg_y = 0., deg_z = 0.;
  star5(trnsl_x, trnsl_y, trnsl_z, deg_x, deg_y, deg_z);

  /* Performs a buffer swap on the layer in use for the current window.
     Specifically, glutSwapBuffers promotes the contents of the back buffer of the layer in use of the current window to become the contents of the front buffer. */
  glutSwapBuffers();
}


static void reshape(int width, int height) {
  GLint x = 0., y = 0.;
  GLdouble fovy = 0., aspect = 0., zNear = 0., zFar = 0.;

  /* Specify the lower left corner of the viewport rectangle, in pixels. The initial value is (0,0). */
  x = 0., y = 0.;
  /* glViewport specifies the affine transformation of x and y from normalized device coordinates to window coordinates. */
  glViewport(x, y, width, height);

  /* Applies subsequent matrix operations to the projection matrix stack. */
  glMatrixMode(GL_PROJECTION);
  /* glLoadIdentity replaces the current matrix with the identity matrix. */
  glLoadIdentity();
  /* Specifies the field of view angle, in degrees, in the y direction. */
  fovy = 60.;
  /* Specifies the aspect ratio that determines the field of view in the x direction.
     The aspect ratio is the ratio of x (width) to y (height). */
  aspect = (GLdouble)width / (GLdouble)height;
  /* Specifies the distance from the viewer to the near clipping plane (always positive). */
  zNear = 1.;
  /* Specifies the distance from the viewer to the far clipping plane (always positive). */
  zFar = 20.;
  /* gluPerspective specifies a viewing frustum into the world coordinate system.
     In general, the aspect ratio in gluPerspective should match the aspect ratio of the associated viewport. */
  gluPerspective(fovy, aspect, zNear, zFar);
}


static void keyboard(unsigned char key, int x, int y) {
  const GLdouble EYE_STEP = .1;
  const GLfloat STEP_DEG = 2.;
  switch (key) {
  case '+':
    perspective.eyeR -= EYE_STEP;
    break;
  case '-':
    perspective.eyeR += EYE_STEP;
    break;
  case 't':
    perspective.deg_theta = (int)(perspective.deg_theta + STEP_DEG) % 360;
    break;
  case 'T':
    perspective.deg_theta = (int)(perspective.deg_theta - STEP_DEG + 360) % 360;
    break;
  case 'p':
    perspective.deg_psi = (int)(perspective.deg_psi + STEP_DEG) % 360;
    break;
  case 'P':
    perspective.deg_psi = (int)(perspective.deg_psi - STEP_DEG + 360) % 360;
    break;
  case 'r':
    reset();
    break;
  default:
    return;
  }
  /* Mark the normal plane of current window as needing to be redisplayed.
     The next iteration through glutMainLoop, the window's display callback will be called to redisplay the window's normal plane. */
  glutPostRedisplay();
}


int main(int argn, char** argv) {
  glutInit(&argn, argv);
  /* glutInitDisplayMode(GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH | GLUT_STENCIL); */
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL);
  /* glutInitWindowSize(1280, 720); */
  glutInitWindowSize(640, 360);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("EA979a - Yugo Kuno, ra033324 - task07");

  /* glEnable(GL_BLEND); */
  /* glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); */
  glClearDepth(1.);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);

  reset();

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);

  glutMainLoop();

  return 0;
}
