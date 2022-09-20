#include <stdlib.h>
#include <GL/glut.h>

struct s_coordenada {
    float x;
    float y;
};

struct s_robotVertices {
    s_coordenada cabeca[4];
    s_coordenada corpo[4];
    s_coordenada bracoEsq[4];
    s_coordenada bracoDir[4];
    s_coordenada pernaEsq[4];
    s_coordenada pernaDir[4];
} robot = {
    {{-1.0, 1.0}, {1.0, 1.0}, {1.0, -1.0}, {-1.0, -1.0}},       // Os pontos dos vertices da cabeça do robot.
    {{-1.5, -1.5}, {1.5, -1.5}, {1.5, -7.5}, {-1.5, -7.5}},     // Os pontos dos vertices do corpo do robot.
    {{-3.0, -1.5}, {-2.0, -1.5}, {-2.0, -5.5}, {-3.0, -5.5}},   // Os pontos dos vertices do braço esquerdo do robot.
    {{3.0, -1.5}, {2.0, -1.5}, {2.0, -5.5}, {3.0, -5.5}},       // Os pontos dos vertices do braço direito do robot.
    {{-1.5, -8.0}, {-0.5, -8.0}, {-0.5, -12.0}, {-1.5, -12.0}}, // Os pontods dos vertices da perna esquerda do robot.
    {{1.5, -8.0}, {0.5, -8.0}, {0.5, -12.0}, {1.5, -12.0}},     // Os pontos dos vertices da perna direita do robot.
};

struct s_rgbValores {
    float r;
    float g;
    float b;
};

struct s_coresRobot {
    s_rgbValores cabeca;
    s_rgbValores corpo;
    s_rgbValores bracos;
    s_rgbValores pernas;
} cores = {
    {0.9, 0.8, 0.7},    // Cor de pele clara.
    {0, 0, 1},          // Cor azul. 
    {1, 0, 0},          // Cor vermelha.
    {1, 1, 0}           // Cor amarela.
};

int rotBracoEsq = 0;
int rotBracoDir = 0;

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

    glColor3f(cores.cabeca.r, cores.cabeca.g, cores.cabeca.b);

    glBegin(GL_QUADS);
        glVertex2f(robot.cabeca[0].x, robot.cabeca[0].y);
        glVertex2f(robot.cabeca[1].x, robot.cabeca[1].y);
        glVertex2f(robot.cabeca[2].x, robot.cabeca[2].y);
        glVertex2f(robot.cabeca[3].x, robot.cabeca[3].y);
    glEnd();

    glPopMatrix();

    // Corpo
    glPushMatrix();

    glColor3f(cores.corpo.r, cores.corpo.g, cores.corpo.b);

    glBegin(GL_QUADS);
        glVertex2f(robot.corpo[0].x, robot.corpo[0].y);
        glVertex2f(robot.corpo[1].x, robot.corpo[1].y);
        glVertex2f(robot.corpo[2].x, robot.corpo[2].y);
        glVertex2f(robot.corpo[3].x, robot.corpo[3].y);
    glEnd();

    glPopMatrix();

    // Braço Esquerdo
    glPushMatrix();

    glColor3f(cores.bracos.r, cores.bracos.g, cores.bracos.b);

    float pontoMedioEsqX = (robot.bracoEsq[0].x + robot.bracoEsq[1].x) / 2;
    float pontoMedioEsqY = (robot.bracoEsq[0].y + robot.bracoEsq[1].y) / 2;

    glTranslatef(pontoMedioEsqX, pontoMedioEsqY, 0);
    glRotatef(rotBracoEsq, 0.0, 0.0, 1.0);
    glTranslatef(-pontoMedioEsqX, -pontoMedioEsqY, 0);

    glBegin(GL_QUADS);
        glVertex2f(robot.bracoEsq[0].x, robot.bracoEsq[0].y);
        glVertex2f(robot.bracoEsq[1].x, robot.bracoEsq[1].y);
        glVertex2f(robot.bracoEsq[2].x, robot.bracoEsq[2].y);
        glVertex2f(robot.bracoEsq[3].x, robot.bracoEsq[3].y);
    glEnd();

    glPopMatrix();

    // Braço Direito
    glPushMatrix();

    glColor3f(cores.bracos.r, cores.bracos.g, cores.bracos.b);

    float pontoMedioDirX = (robot.bracoDir[0].x + robot.bracoDir[1].x) / 2;
    float pontoMedioDirY = (robot.bracoDir[0].y + robot.bracoDir[1].y) / 2;

    glTranslatef(pontoMedioDirX, pontoMedioDirY, 0);
    glRotatef(rotBracoDir, 0.0, 0.0, 1.0);
    glTranslatef(-pontoMedioDirX, -pontoMedioDirY, 0);

    glBegin(GL_QUADS);
        glVertex2f(robot.bracoDir[0].x, robot.bracoDir[0].y);
        glVertex2f(robot.bracoDir[1].x, robot.bracoDir[1].y);
        glVertex2f(robot.bracoDir[2].x, robot.bracoDir[2].y);
        glVertex2f(robot.bracoDir[3].x, robot.bracoDir[3].y);
    glEnd();

    glPopMatrix();

    // Perna Esquerda
    glPushMatrix();

    glColor3f(cores.pernas.r, cores.pernas.g, cores.pernas.b);

    glBegin(GL_QUADS);
        glVertex2f(robot.pernaEsq[0].x, robot.pernaEsq[0].y);
        glVertex2f(robot.pernaEsq[1].x, robot.pernaEsq[1].y);
        glVertex2f(robot.pernaEsq[2].x, robot.pernaEsq[2].y);
        glVertex2f(robot.pernaEsq[3].x, robot.pernaEsq[3].y);
    glEnd();

    glPopMatrix();

    // Perna Direita
    glPushMatrix();

    glColor3f(cores.pernas.r, cores.pernas.g, cores.pernas.b);

    glBegin(GL_QUADS);
        glVertex2f(robot.pernaDir[0].x, robot.pernaDir[0].y);
        glVertex2f(robot.pernaDir[1].x, robot.pernaDir[1].y);
        glVertex2f(robot.pernaDir[2].x, robot.pernaDir[2].y);
        glVertex2f(robot.pernaDir[3].x, robot.pernaDir[3].y);
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
            cores.bracos.r = r;
            cores.bracos.g = g;
            cores.bracos.b = b;

            float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            float g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            float b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

            cores.pernas.r = r;
            cores.pernas.g = g;
            cores.pernas.b = b;
        }
    } else if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {
            cores.cabeca.r = r;
            cores.cabeca.g = g;
            cores.cabeca.b = b;

            float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            float g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            float b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

            cores.corpo.r = r;
            cores.corpo.g = g;
            cores.corpo.b = b;
        }
    }

    glutPostRedisplay();
}

void keyEvent(unsigned char key, int x, int y) {

    switch (key) {
        case 'm':
            if (robot.bracoDir[0].x != 18) {
                for (int i = 0; i < 4; i++) {
                    robot.cabeca[i].x++;
                    robot.corpo[i].x++;
                    robot.bracoEsq[i].x++;
                    robot.bracoDir[i].x++;
                    robot.pernaEsq[i].x++;
                    robot.pernaDir[i].x++;
                }
            }
            break;
        case 'M':
            if (robot.bracoEsq[0].x != -18) {
                for (int i = 0; i < 4; i++) {
                    robot.cabeca[i].x--;
                    robot.corpo[i].x--;
                    robot.bracoEsq[i].x--;
                    robot.bracoDir[i].x--;
                    robot.pernaEsq[i].x--;
                    robot.pernaDir[i].x--;
                }
            }
            break;
        case 'i':
            if (rotBracoDir < 180) {
                rotBracoDir+=5;
            }
            break;
        case 'I':
            if (rotBracoDir > 0) {
                rotBracoDir-=5;
            }
            break;
        case 'p':
            if (rotBracoEsq > -180) {
                rotBracoEsq-=5;
            }
            break;
        case 'P':
            if (rotBracoEsq < 0) {
                rotBracoEsq+=5;
            }
            break;
        default:
            break;
    }

    glutPostRedisplay();
}