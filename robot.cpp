#include <stdlib.h>
#include <GL/glut.h>

struct s_coordenada {
    float x;
    float y;
};

struct s_robotVertex {
    s_coordenada head[4];
    s_coordenada body[4];
    s_coordenada leftArm[4];
    s_coordenada rightArm[4];
    s_coordenada leftLeg[4];
    s_coordenada rightLeg[4];
} robot = {
    {{-1.0, 1.0}, {1.0, 1.0}, {1.0, -1.0}, {-1.0, -1.0}},
    {{-1.5, -1.5}, {1.5, -1.5}, {1.5, -7.5}, {-1.5, -7.5}},
    {{-3.0, -1.5}, {-2.0, -1.5}, {-2.0, -5.5}, {-3.0, -5.5}},
    {{3.0, -1.5}, {2.0, -1.5}, {2.0, -5.5}, {3.0, -5.5}},
    {{-1.5, -8.0}, {-0.5, -8.0}, {-0.5, -12.0}, {-1.5, -12.0}},
    {{1.5, -8.0}, {0.5, -8.0}, {0.5, -12.0}, {1.5, -12.0}},
};

struct s_rgbValues {
    float r;
    float g;
    float b;
};

struct s_coresRobot {
    s_rgbValues head;
    s_rgbValues body;
    s_rgbValues arms;
    s_rgbValues legs;
} cores = {
    {0.9, 0.8, 0.7},
    {0, 0, 1},
    {1, 0, 0},
    {1, 1, 0}
};

void init();
void draw();
void mouseEvent(int, int, int, int);
void keyEvent(unsigned char, int, int);

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Robot");
    init();

    glutDisplayFunc(draw);
    glutMouseFunc(mouseEvent);
    glutKeyboardFunc(keyEvent);

    glutMainLoop();

    return 0;
}

void init() {

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-20.0, 20.0, -20.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

void draw() {

    glClear(GL_COLOR_BUFFER_BIT);

    // Cabeça
    glPushMatrix();

    glColor3f(cores.head.r, cores.head.g, cores.head.b);

    glBegin(GL_QUADS);
        glVertex2f(robot.head[0].x, robot.head[0].y);
        glVertex2f(robot.head[1].x, robot.head[1].y);
        glVertex2f(robot.head[2].x, robot.head[2].y);
        glVertex2f(robot.head[3].x, robot.head[3].y);
    glEnd();

    glPopMatrix();

    // Corpo
    glPushMatrix();

    glColor3f(cores.body.r, cores.body.g, cores.body.b);

    glBegin(GL_QUADS);
        glVertex2f(robot.body[0].x, robot.body[0].y);
        glVertex2f(robot.body[1].x, robot.body[1].y);
        glVertex2f(robot.body[2].x, robot.body[2].y);
        glVertex2f(robot.body[3].x, robot.body[3].y);
    glEnd();

    glPopMatrix();

    // Braço Esquerdo
    glPushMatrix();

    glColor3f(cores.arms.r, cores.arms.g, cores.arms.b);

    glBegin(GL_QUADS);
        glVertex2f(robot.leftArm[0].x, robot.leftArm[0].y);
        glVertex2f(robot.leftArm[1].x, robot.leftArm[1].y);
        glVertex2f(robot.leftArm[2].x, robot.leftArm[2].y);
        glVertex2f(robot.leftArm[3].x, robot.leftArm[3].y);
    glEnd();

    glPopMatrix();

    // Braço Direito
    glPushMatrix();

    glColor3f(cores.arms.r, cores.arms.g, cores.arms.b);

    glBegin(GL_QUADS);
        glVertex2f(robot.rightArm[0].x, robot.rightArm[0].y);
        glVertex2f(robot.rightArm[1].x, robot.rightArm[1].y);
        glVertex2f(robot.rightArm[2].x, robot.rightArm[2].y);
        glVertex2f(robot.rightArm[3].x, robot.rightArm[3].y);
    glEnd();

    glPopMatrix();

    // Perna Esquerda
    glPushMatrix();

    glColor3f(cores.legs.r, cores.legs.g, cores.legs.b);

    glBegin(GL_QUADS);
        glVertex2f(robot.leftLeg[0].x, robot.leftLeg[0].y);
        glVertex2f(robot.leftLeg[1].x, robot.leftLeg[1].y);
        glVertex2f(robot.leftLeg[2].x, robot.leftLeg[2].y);
        glVertex2f(robot.leftLeg[3].x, robot.leftLeg[3].y);
    glEnd();

    glPopMatrix();

    // Perna Direita
    glPushMatrix();

    glColor3f(cores.legs.r, cores.legs.g, cores.legs.b);

    glBegin(GL_QUADS);
        glVertex2f(robot.rightLeg[0].x, robot.rightLeg[0].y);
        glVertex2f(robot.rightLeg[1].x, robot.rightLeg[1].y);
        glVertex2f(robot.rightLeg[2].x, robot.rightLeg[2].y);
        glVertex2f(robot.rightLeg[3].x, robot.rightLeg[3].y);
    glEnd();

    glPopMatrix();

    glFlush();
}

void mouseEvent(int button, int state, int x, int y) {

    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            cores.arms.r = r;
            cores.arms.g = g;
            cores.arms.b = b;

            float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            float g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            float b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

            cores.legs.r = r;
            cores.legs.g = g;
            cores.legs.b = b;
        }
    } else if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {
            cores.head.r = r;
            cores.head.g = g;
            cores.head.b = b;

            float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            float g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            float b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

            cores.body.r = r;
            cores.body.g = g;
            cores.body.b = b;
        }
    }

    glutPostRedisplay();
}

void keyEvent(unsigned char key, int x, int y) {

    switch (key) {
        case 'm':
            for (int i = 0; i < 4; i++) {
                robot.head[i].x++;
                robot.body[i].x++;
                robot.leftArm[i].x++;
                robot.rightArm[i].x++;
                robot.leftLeg[i].x++;
                robot.rightLeg[i].x++;
            }
            break;
        case 'M':
            for (int i = 0; i < 4; i++) {
                robot.head[i].x--;
                robot.body[i].x--;
                robot.leftArm[i].x--;
                robot.rightArm[i].x--;
                robot.leftLeg[i].x--;
                robot.rightLeg[i].x--;
            }
            break;
        case 'i':
            robot.rightArm[0].y++;
            robot.rightArm[1].y++;
            robot.rightArm[2].y++;
            robot.rightArm[3].y++;
            break;
        case 'I':
            robot.rightArm[0].y--;
            robot.rightArm[1].y--;
            robot.rightArm[2].y--;
            robot.rightArm[3].y--;
            break;
        case 'p':
            robot.leftArm[0].y++;
            robot.leftArm[1].y++;
            robot.leftArm[2].y++;
            robot.leftArm[3].y++;
            break;
        case 'P':
            robot.leftArm[0].y--;
            robot.leftArm[1].y--;
            robot.leftArm[2].y--;
            robot.leftArm[3].y--;
            break;
        default:
            break;
    }

    glutPostRedisplay();
}