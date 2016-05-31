#include <GL/glut.h>

typedef struct {
  int wire;
  GLfloat rot_deg_x;
  GLfloat rot_deg_y;
  GLfloat rot_deg_z;
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


static void basic_draw_sphere(GLdouble radius, GLint slices, GLint stacks,
			      GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha,
			      GLfloat trnsl_x, GLfloat trnsl_y, GLfloat trnsl_z,
			      GLfloat rot_deg_x, GLfloat rot_deg_y, GLfloat rot_deg_z) {
  GLfloat rot_x = 0., rot_y = 0., rot_z = 0.;
  /* glPushMatrix pushes the current matrix stack down by one, duplicating the current matrix.
     That is, after a glPushMatrix call, the matrix on top of the stack is identical to the one below it. */
  glPushMatrix();
  /* glRotate produces a rotation of angle degrees around the vector (x, y, z).
     The current matrix is multiplied by a rotation matrix with the product replacing the current matrix */
  rot_x = 1., rot_y = 0., rot_z = 0.;
  glRotatef(rot_deg_x, rot_x, rot_y, rot_z);
  rot_x = 0., rot_y = 1., rot_z = 0.;
  glRotatef(rot_deg_y, rot_x, rot_y, rot_z);
  rot_x = 0., rot_y = 0., rot_z = 1.;
  glRotatef(rot_deg_z, rot_x, rot_y, rot_z);
  /* glTranslate produces a translation by (x, y, z).
     The current matrix is multiplied by this translation matrix, with the product replacing the current matrix */
  glTranslatef(trnsl_x, trnsl_y, trnsl_z);
  /* The GL stores both a current single-valued color index and a current four-valued RGBA color. */
  glColor4f(red, green, blue, alpha);
  /* Renders a sphere centered at the modeling coordinates origin of the specified radius. The sphere is subdivided around the Z axis into slices and along the Z axis into stacks. */
  if (perspective.wire)
    glutWireSphere(radius, slices, stacks);
  else
    glutSolidSphere(radius, slices, stacks);

  /* glPopMatrix pops the current matrix stack, replacing the current matrix with the one below it on the stack. */
  glPopMatrix();
}

static void display() {
  GLclampf glclmp_red = 0., glclmp_green = 0., glclmp_blue = 0., glclmp_alpha = 0.;
  GLfloat trnsl_x = 0., trnsl_y = 0., trnsl_z = 0.;
  GLfloat  rot_deg_x = perspective.rot_deg_x, rot_deg_y = perspective.rot_deg_y, rot_deg_z = perspective.rot_deg_z;
  GLfloat glf_red = 0., glf_green = 0., glf_blue = 0., glf_alpha = .01;
  GLdouble radius = 0.;
  GLint slices = 20, stacks = 20;
  GLfloat distance = 1.6 / 1.41421356;

  /* Applies subsequent matrix operations to the modelview matrix stack. */
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  /* gluLookAt creates a viewing matrix derived from an eye point, a reference
     point indicating the center of the scene, and an up vector. */
  gluLookAt(perspective.eyeX, perspective.eyeY, perspective.eyeZ, perspective.centerX, perspective.centerY, perspective.centerZ, perspective.upX, perspective.upY, perspective.upZ);

  /* Specify the red, green, blue, and alpha values used when the color buffers are cleared. The initial values are all 0. */
  glclmp_red = 0., glclmp_green = 0., glclmp_blue = 0., glclmp_alpha = 1.;
  /* glClearColor specifies the red, green, blue, and alpha values used by glClear to clear the color buffers.
     Values specified by glClearColor are clamped to the range [0, 1]. */
  glClearColor(glclmp_red, glclmp_green, glclmp_blue, glclmp_alpha);
  /* glClear sets the bitplane area of the window to values previously selected by
     glClearColor, glClearIndex, glClearDepth, glClearStencil, and glClearAccum. */
  /* glClear(GL_COLOR_BUFFER_BIT); */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  radius = 1.;

  /* yellow */
  glf_red = 1., glf_green = 1., glf_blue = 0.;
  trnsl_x = 0., trnsl_y = 0., trnsl_z = 0.;
  basic_draw_sphere(radius, slices, stacks,
		    glf_red, glf_green, glf_blue, glf_alpha,
		    trnsl_x, trnsl_y, trnsl_z,
		    rot_deg_x, rot_deg_y, rot_deg_z);

  radius = .4;

  /* white */
  glf_red = 1., glf_green = 1., glf_blue = 1.;
  trnsl_x = 0., trnsl_y = -distance, trnsl_z = distance;
  basic_draw_sphere(radius, slices, stacks,
		    glf_red, glf_green, glf_blue, glf_alpha,
		    trnsl_x, trnsl_y, trnsl_z,
		    rot_deg_x, rot_deg_y, rot_deg_z);

  /* red */
  glf_red = 1., glf_green = 0., glf_blue = 0.;
  trnsl_x = 0., trnsl_y = distance, trnsl_z = -distance;
  basic_draw_sphere(radius, slices, stacks,
		    glf_red, glf_green, glf_blue, glf_alpha,
		    trnsl_x, trnsl_y, trnsl_z,
		    rot_deg_x, rot_deg_y, rot_deg_z);

  /* blue */
  glf_red = 0., glf_green = 0., glf_blue = 1.;
  trnsl_x = 0., trnsl_y = -distance, trnsl_z = -distance;
  basic_draw_sphere(radius, slices, stacks,
		    glf_red, glf_green, glf_blue, glf_alpha,
		    trnsl_x, trnsl_y, trnsl_z,
		    rot_deg_x, rot_deg_y, rot_deg_z);

  /* cyan */
  glf_red = 0., glf_green = 1., glf_blue = 1.;
  trnsl_x = 0., trnsl_y = distance, trnsl_z = distance;
  basic_draw_sphere(radius, slices, stacks,
		    glf_red, glf_green, glf_blue, glf_alpha,
		    trnsl_x, trnsl_y, trnsl_z,
		    rot_deg_x, rot_deg_y, rot_deg_z);

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
  const GLfloat STEP_DEG = 2;
  switch (key) {
  case '+':
    perspective.eyeY -= EYE_STEP;
    break;
  case '-':
    perspective.eyeY += EYE_STEP;
    break;
  case 'w':
    perspective.wire = 1 - perspective.wire;
    break;
  case 'x':
    perspective.rot_deg_x = (int)(perspective.rot_deg_x + STEP_DEG) % 360;
    break;
  case 'X':
    perspective.rot_deg_x = (int)(perspective.rot_deg_x - STEP_DEG) % 360;
    break;
  case 'y':
    perspective.rot_deg_y = (int)(perspective.rot_deg_y + STEP_DEG) % 360;
    break;
  case 'Y':
    perspective.rot_deg_y = (int)(perspective.rot_deg_y - STEP_DEG) % 360;
    break;
  case 'z':
    perspective.rot_deg_z = (int)(perspective.rot_deg_z + STEP_DEG) % 360;
    break;
  case 'Z':
    perspective.rot_deg_z = (int)(perspective.rot_deg_z - STEP_DEG) % 360;
    break;
  case 'r':
    perspective.rot_deg_x = 4.;
    perspective.rot_deg_y = 0.;
    perspective.rot_deg_z = 0.;
    perspective.eyeX = 0.;
    perspective.eyeY = 5.5;
    perspective.eyeZ = 0.;
    perspective.centerX = 0.;
    perspective.centerY = 0.;
    perspective.centerZ = 0.;
    perspective.upX = 0.;
    perspective.upY = 0.;
    perspective.upZ = 1.;
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
  glutInitWindowSize(1280, 720);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("EA979a - Yugo Kuno, ra033324 - task06");

  /* glEnable(GL_BLEND); */
  /* glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); */
  glClearDepth(1.);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);

  perspective.wire = 1;
  perspective.rot_deg_x = 4.;
  perspective.rot_deg_y = 0.;
  perspective.rot_deg_z = 0.;
  perspective.eyeX = 0.;
  perspective.eyeY = 5.5;
  perspective.eyeZ = 0.;
  perspective.centerX = 0.;
  perspective.centerY = 0.;
  perspective.centerZ = 0.;
  perspective.upX = 0.;
  perspective.upY = 0.;
  perspective.upZ = 1.;

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);

  glutMainLoop();

  return 0;
}
