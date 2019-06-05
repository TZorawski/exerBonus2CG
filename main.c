#include <stdio.h>
#include <GL/freeglut.h>

float alpha=0, beta=0, delta=1;


int init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);     //define a cor de fundo
    glEnable(GL_DEPTH_TEST);           //remo��o de superf�cie oculta

    glMatrixMode(GL_PROJECTION);          //define que a matriz � a de proje��o
    glLoadIdentity();                     //carrega a matriz de identidade
    glOrtho(-5,5,-5,5,-5,5);          //define uma proje��o ortogr�fica
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa o buffer

    glMatrixMode(GL_MODELVIEW);      //define que a matriz � a de modelo
    glLoadIdentity();                //carrega matriz identidade

    glColor3f(1, 0, 0);                 //define cor objeto
    glRotatef(beta, 0, 1, 0);
    glRotatef(alpha, 1, 0, 0);
    glScalef(delta, delta, delta);
    glutWireTeapot(3);                  //desenha bule wired e centrado na origem(tamanho)

    glFlush();                       //desenha os comandos n�o executados
}

// Fun��o que trata teclas especiais do teclado
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
    glutInitWindowPosition(200,0);                  //seta a posi��o inicial da janela
    glutInitWindowSize(400,400);                    //configura a largura e altura da janela de exibi��o
    glutCreateWindow("3D");                 //cria a janela de exibi��o

    init();                                         //executa fun��o de inicializa��o
    glutSpecialFunc(keyPressed_special);
    glutDisplayFunc(display);
    glutMainLoop();                                  //mostre tudo e espere
    return 0;
}

