#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
int FlatShaded = 0; int Wireframed = 0; //flatshading�� Wireframe�� ��۸��ϱ� ���� �ο� ����

int ViewX = 100; // ���콺 �����ӿ� ���� ������ �ٲٱ� ���� ���� 
int ViewY = 100;
void InitLight() {
	GLfloat mat_diffuse[] = { 0.5, 0.4, 0.3, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
	GLfloat mat_shininess[] = { 15.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat light_ambient[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat light_position[] = { -3, 6, 3.0, 0.0 };
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void MyMouseMove(GLint X, GLint Y) {
	// ���콺 ������ X,Y�� ���� ������ ViewX, ViewY�� �Ҵ�
	ViewX = X;
	ViewY = Y;
	glutPostRedisplay();
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'q': case 'Q': case '\033':
		exit(0);
		break;
	case 's':
		if (FlatShaded) {
			FlatShaded = 0;
			glShadeModel(GL_SMOOTH);
		}
		else {
			FlatShaded = 1;
			glShadeModel(GL_FLAT);
		}
		glutPostRedisplay();
		break;

	case 'w':

		if (Wireframed) {
			Wireframed = 0;
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
		else {
			Wireframed = 1;
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
		glutPostRedisplay();
		break;
	}
	// ���⿡ ���̾� ������ ��۸��� ���� �ڵ带 ������ �� 
	// ���� ���� ���� Wireframed�� ����� �� 

}

void DrawTable() {
	glTranslatef(0.0, -0.1, 0.0);
	glBegin(GL_QUADS);

	glVertex3f(-0.25, 0.0125, -0.25);
	glVertex3f(0.25, 0.0125, -0.25);
	glVertex3f(0.25, 0.0125, 0.25);
	glVertex3f(-0.25, 0.0125, 0.25);

	glVertex3f(-0.25, -0.0125, -0.25);
	glVertex3f(0.25, -0.0125, -0.25);
	glVertex3f(0.25, -0.0125, 0.25);
	glVertex3f(-0.25, -0.0125, 0.25);

	glVertex3f(-0.25, -0.0125, 0.25);
	glVertex3f(0.25, -0.0125, 0.25);
	glVertex3f(0.25, 0.0125, 0.25);
	glVertex3f(-0.25, 0.0125, 0.25);

	glVertex3f(-0.25, -0.0125, -0.25);
	glVertex3f(0.25, -0.0125, -0.25);
	glVertex3f(0.25, 0.0125, -0.25);
	glVertex3f(-0.25, 0.0125, -0.25);

	glVertex3f(-0.25, -0.0125, -0.25);
	glVertex3f(-0.25, -0.0125, 0.25);
	glVertex3f(-0.25, 0.0125, 0.25);
	glVertex3f(-0.25, 0.0125, -0.25);

	glVertex3f(0.25, -0.0125, -0.25);
	glVertex3f(0.25, -0.0125, 0.25);
	glVertex3f(0.25, 0.0125, 0.25);
	glVertex3f(0.25, 0.0125, -0.25);
	glEnd();

	glTranslatef(0.0, 0.1, 0.0);

	auto Leg = [](float x, float y, float z) {
		glTranslatef(x, y, z);
		glBegin(GL_QUADS);

		glVertex3f(-0.0125, 0.15, -0.0125);
		glVertex3f(0.0125, 0.15, -0.0125);
		glVertex3f(0.0125, 0.15, 0.0125);
		glVertex3f(-0.0125, 0.15, 0.0125);

		glVertex3f(-0.0125, -0.15, -0.0125);
		glVertex3f(0.0125, -0.15, -0.0125);
		glVertex3f(0.0125, -0.15, 0.0125);
		glVertex3f(-0.0125, -0.15, 0.0125);

		glVertex3f(-0.0125, -0.15, 0.0125);
		glVertex3f(0.0125, -0.15, 0.0125);
		glVertex3f(0.0125, 0.15, 0.0125);
		glVertex3f(-0.0125, 0.15, 0.0125);

		glVertex3f(-0.0125, -0.15, -0.0125);
		glVertex3f(0.0125, -0.15, -0.0125);
		glVertex3f(0.0125, 0.15, -0.0125);
		glVertex3f(-0.0125, 0.15, -0.0125);

		glVertex3f(-0.0125, -0.15, -0.0125);
		glVertex3f(-0.0125, -0.15, 0.0125);
		glVertex3f(-0.0125, 0.15, 0.0125);
		glVertex3f(-0.0125, 0.15, -0.0125);

		glVertex3f(0.0125, -0.15, -0.0125);
		glVertex3f(0.0125, -0.15, 0.0125);
		glVertex3f(0.0125, 0.15, 0.0125);
		glVertex3f(0.0125, 0.15, -0.0125);
		glEnd();

		glTranslatef(-x, -y, -z);
	};

	Leg(-0.225, -0.3, -0.225);
	Leg(0.225, -0.3, -0.225);
	Leg(-0.225, -0.3, 0.225);
	Leg(0.225, -0.3, 0.225);
}




void DrawO() {

	float sX = -0.2;
	float sY = 0.1; 
	float sZ = -0.2;
	glTranslatef(sX, sY, sZ);
	glutSolidSphere(0.1, 20, 20);
	glTranslatef(-sX, -sY, -sZ);


	float tX = 0.2;
	float tY = 0.1; 
	float tZ = 0.2;
	glTranslatef(tX, tY, tZ);
	glutSolidTorus(0.05, 0.1, 20, 20); 
	glTranslatef(-tX, -tY, -tZ);

	float cX = 0.0;
	float cY = 0.15; 
	float cZ = 0.0;
	glTranslatef(cX, cY, cZ);
	glutSolidCube(0.2);
	glTranslatef(-cX, -cY, -cZ);
}


void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	float cameraX = (ViewX - 200) / 200.0;
	float cameraY = (200 - ViewY) / 200.0;
	gluLookAt(cameraX, cameraY, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	// ���콺�� �����ӿ� ���� ������ ��ȭ��Ű����
	// MyMouseMove �Լ����� �ԷµǴ� ��ȭ���� �����Ͽ�
	// glLookAt ��ɾ� �Ķ���͸� �����غ� �� (���� ����)
	// �Ʒ��� �ʿ��� ��ü ����� ����� ������ �� 

	DrawTable();
	DrawO();

	glFlush();
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Table and Objects");

	glClearColor(0.4, 0.4, 0.4, 0.0);
	InitLight();
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutMotionFunc(MyMouseMove);
	glutReshapeFunc(MyReshape);
	glutMainLoop();
}
