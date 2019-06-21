#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>

float alpha=0, beta=0, delta=1, spin=0;

void timer_func(int n){
	//if(spin < 360){
    spin = spin + 1;                    // Atualiza rotação do objeto
	//} else {
	//    spin = 0;
	//}
	glutPostRedisplay();                // carrega tela
    //glutTimerFunc(tempo, timer_func, n);
	glutTimerFunc(10, timer_func, 0);   // chama callback
}

int init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);       //define a cor de fundo
    glEnable(GL_DEPTH_TEST);                //remoção de superfície oculta
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa o buffer

    // VIEW INF. ESQ.
    glViewport(0,0,400,400);                // define viewport canto infer. esq.
    glMatrixMode(GL_PROJECTION);            //define que a matriz é a de projeção
    glLoadIdentity();                       //carrega matriz identidade
    glOrtho(-3, 3, -3, 3, 1, 50);           // define projeção ortogonal

    glMatrixMode(GL_MODELVIEW);      //define que a matriz é a de projeção
    glLoadIdentity();                //carrega matriz identidade
    gluLookAt(0, 0, 30,
              0, 0, 0,
              0, 1, 0); // define posição camera (posicao camera, para onde camera olha, vetor view up: orientacao - camera de pé)

    glColor3f(1, 0, 1);                 //define cor objeto
    glutWireTeapot(1.5);                  //desenha bule wired e centrado na origem(tamanho)
    // ==========================

    // VIEW SUP. ESQ.
    glViewport(0,400,400,400); // define viewport canto sup. esq.
    glMatrixMode(GL_PROJECTION);      //define que a matriz é a de projeção
    glLoadIdentity();                //carrega matriz identidade
    glOrtho(-3, 3, -3, 3, 1, 50); // define projeção ortogonal

    glMatrixMode(GL_MODELVIEW);      //define que a matriz é a de projeção
    glLoadIdentity();                //carrega matriz identidade
    gluLookAt(0, 30, 0,
              0, 0, 0,
              0, 0, -1); // define posição camera (posicao camera, para onde camera olha, vetor view up: orientacao - camera de pé)

    glColor3f(1, 0, 0);                 //define cor objeto
    glutWireTeapot(1.5);                  //desenha bule wired e centrado na origem(tamanho)
    // ==========================

    // VIEW INF. DIR.
    glViewport(400,0,400,400); // define viewport canto infer. dir.
    glMatrixMode(GL_PROJECTION);      //define que a matriz é a de projeção
    glLoadIdentity();                //carrega matriz identidade
    gluPerspective(70, 1, 1, 50);

    glMatrixMode(GL_MODELVIEW);      //define que a matriz é a de projeção
    glLoadIdentity();                //carrega matriz identidade
    gluLookAt(0, 0, 5,
              0, 0, 0,
              0, 1, 0); // define posição camera (posicao camera, para onde camera olha, vetor view up: orientacao - camera de pé)

    glColor3f(1, 1, 0);                 //define cor objeto
    glRotated(45, 1, 0, 0);
    glRotated(spin, 0, 0, 1);

    glutWireTeapot(1.5);                  //desenha bule wired e centrado na origem(tamanho)
    // ==========================

    // VIEW SUP. DIR.
    glViewport(400,400,400,400); // define viewport canto sup. dir.
    glMatrixMode(GL_PROJECTION);      //define que a matriz é a de projeção
    glLoadIdentity();                //carrega matriz identidade
    glOrtho(-3, 3, -3, 3, 1, 50); // define projeção ortogonal

    glMatrixMode(GL_MODELVIEW);      //define que a matriz é a de projeção
    glLoadIdentity();                //carrega matriz identidade
    gluLookAt(30, 0, 0,
              0, 0, 0,
              0, 1, 0); // define posição camera (posicao camera, para onde camera olha, vetor view up: orientacao - camera de pé)

    glColor3f(1, 0, 0);                 //define cor objeto
    glutWireTeapot(1.5);                  //desenha bule wired e centrado na origem(tamanho)

    glFlush();                       //desenha os comandos não executados
}

int main(int argc, char** argv){
    glutInit(&argc,argv);                           //inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);    //configura o modo de display
    glutInitWindowPosition(200,0);                  //seta a posição inicial da janela
    glutInitWindowSize(800,800);                    //configura a largura e altura da janela de exibição
    glutCreateWindow("Exercicio Bonus 2");                 //cria a janela de exibição

    init();                                         //executa função de inicialização
    glutDisplayFunc(display);
    timer_func(0);
    glutMainLoop();                                 //mostre tudo e espere

    return 0;
}

