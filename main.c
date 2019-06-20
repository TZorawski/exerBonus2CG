#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>

float alpha=0, beta=0, delta=1;


int init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);     //define a cor de fundo
    glEnable(GL_DEPTH_TEST);           //remoção de superfície oculta
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
    //glRotatef(beta, 0, 1, 0);
    //glRotatef(alpha, 1, 0, 0);
    //glScalef(delta, delta, delta);
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
    glRotatef(beta, 0, 1, 0);
    glRotatef(alpha, 1, 0, 0);
    glScalef(delta, delta, delta);
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
    //glRotatef(beta, 0, 1, 0);
    //glRotatef(alpha, 1, 0, 0);
    //glScalef(delta, delta, delta);
    glutWireTeapot(1.5);                  //desenha bule wired e centrado na origem(tamanho)

    glFlush();                       //desenha os comandos não executados
}

// Função que trata teclas especiais do teclado
void keyPressed_special(int key, int x, int y){
    if(key == GLUT_KEY_PAGE_UP){//faz zoom-in
        delta = delta * 1.1f;
    }
    if(key == GLUT_KEY_PAGE_DOWN){//faz zoom-out
        delta = delta * 0.809f;
    }
    if(key == GLUT_KEY_RIGHT){//gira sobre o eixo-y
        beta = beta - 1;
    }
    if(key == GLUT_KEY_LEFT){//gira sobre o eixo-y
        beta = beta + 1;
    }
    if(key == GLUT_KEY_UP){ //gira sobre o eixo-x
        alpha = alpha - 1;
    }
    if(key == GLUT_KEY_DOWN){ //gira sobre o eixo-x
         alpha = alpha + 1;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);                           //inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);    //configura o modo de display
    glutInitWindowPosition(200,0);                  //seta a posição inicial da janela
    glutInitWindowSize(800,800);                    //configura a largura e altura da janela de exibição
    glutCreateWindow("Exercicio Bonus 2");                 //cria a janela de exibição

    init();                                         //executa função de inicialização
    glutSpecialFunc(keyPressed_special);
    glutDisplayFunc(display);
    glutMainLoop();                                  //mostre tudo e espere
    return 0;
}

