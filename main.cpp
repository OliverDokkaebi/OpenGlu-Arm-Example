#include <GL/glut.h>
 #include <GL/freeglut.h>
 #include <iostream>
 #include <cmath>
 
 //Definindo parâmetros inicias das partes
 float ombro_x = 0.0f;
 float ombro_y = 0.0f;
 float ombro_z = 0.0f;
 float cotovelo = 0.0f;
 float pulso_x = 0.0f;
 float pulso_y = 0.0f;
 float pulso_z = 0.0f;
 float dedo2 = 0.0f;  
 float dedo3 = 0.0f;  
 float dedo4 = 0.0f;  
 float dedo5 = 0.0f;  
 
 //Cores padrôes
 GLfloat cores[][4] = {
     {0.8f, 0.5f, 0.2f, 1.0f},  
     {0.7f, 0.4f, 0.2f, 1.0f},  
     {0.6f, 0.3f, 0.1f, 1.0f},  
     {0.9f, 0.9f, 0.9f, 1.0f}   
 };
 
 // Iluminação do ambiente
 void configuraIluminacao() {
     GLfloat luzAmbiente[4] = {0.2f, 0.2f, 0.2f, 1.0f};
     GLfloat luzDifusa[4] = {0.7f, 0.7f, 0.7f, 1.0f};
     GLfloat luzEspecular[4] = {1.0f, 1.0f, 1.0f, 1.0f};
     GLfloat posicaoLuz[4] = {0.0f, 10.0f, 10.0f, 1.0f};
 
     glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
     glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
     glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
     glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);
 
     glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
     glEnable(GL_COLOR_MATERIAL);
     glEnable(GL_NORMALIZE);
     
     
     GLfloat materialAmbiente[4] = {0.2f, 0.2f, 0.2f, 1.0f};
     GLfloat materialDifuso[4] = {0.8f, 0.8f, 0.8f, 1.0f};
     GLfloat materialEspecular[4] = {0.5f, 0.5f, 0.5f, 1.0f};
     GLfloat materialBrilho = 32.0f;
     
     glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbiente);
     glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDifuso);
     glMaterialfv(GL_FRONT, GL_SPECULAR, materialEspecular);
     glMaterialf(GL_FRONT, GL_SHININESS, materialBrilho);
 }
 
 //Desenha a junta do ombro
 void desenhaJunta(GLfloat raio) {
     glutSolidSphere(raio, 20, 20);
 }
 
 //Desenha o segmento do braço
 void desenhaSegmento(GLfloat comprimento, GLfloat raio) {
     GLUquadricObj *quadric = gluNewQuadric();
     gluQuadricDrawStyle(quadric, GLU_FILL);
     gluQuadricNormals(quadric, GLU_SMOOTH);
     
     glPushMatrix();
         glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
         gluCylinder(quadric, raio, raio, comprimento, 20, 20);
     glPopMatrix();
     
     gluDeleteQuadric(quadric);
 }
 
 //Desenha os dedos utilizados no código
 void desenhaDedo(float angulo, float comprimento_1 = 0.6f, float comprimento_2 = 0.4f, 
                 float raio_1 = 0.08f, float raio_2 = 0.07f) {
     glPushMatrix();
         
         glRotatef(angulo, 0.0f, 0.0f, 1.0f);
         
         
         glColor4fv(cores[2]);
         desenhaSegmento(comprimento_1, raio_1);
         
         
         glPushMatrix();
             glTranslatef(comprimento_1, 0.0f, 0.0f);
             
             glRotatef(angulo/1.5f, 0.0f, 0.0f, 1.0f);
             
             
             desenhaSegmento(comprimento_2, raio_2);
             
             
             glPushMatrix();
                 glTranslatef(comprimento_2, 0.0f, 0.0f);
                 glColor4fv(cores[3]);
                 glScalef(0.2f, 0.12f, 0.05f);
                 glutSolidCube(1.0f);
             glPopMatrix();
         glPopMatrix();
     glPopMatrix();
 }
 
 //Desenha a mão presente no código
 void desenhaMao() {
     glPushMatrix();
         
         glColor4fv(cores[1]);
         glScalef(0.5f, 0.2f, 0.8f);
         glutSolidCube(1.0f);
         
         
         glScalef(2.0f, 5.0f, 1.25f);
         
         
         
         glTranslatef(0.25f, 0.0f, 0.0f);
         
         
         glPushMatrix();
             glTranslatef(0.0f, 0.0f, 0.3f);  
             
             glRotatef(5.0f, 0.0f, 1.0f, 0.0f); 
             desenhaDedo(dedo2, 0.65f, 0.45f, 0.08f, 0.07f);
         glPopMatrix();
         
         
         glPushMatrix();
             glTranslatef(0.0f, 0.0f, 0.1f);  
             desenhaDedo(dedo3, 0.7f, 0.5f, 0.08f, 0.07f);
         glPopMatrix();
         
         
         glPushMatrix();
             glTranslatef(0.0f, 0.0f, -0.1f);  
             
             glRotatef(-3.0f, 0.0f, 1.0f, 0.0f);
             desenhaDedo(dedo4, 0.65f, 0.45f, 0.08f, 0.07f);
         glPopMatrix();
         
         
         glPushMatrix();
             glTranslatef(0.0f, 0.0f, -0.3f);  
             
             glRotatef(-6.0f, 0.0f, 1.0f, 0.0f);
             desenhaDedo(dedo5, 0.5f, 0.35f, 0.07f, 0.06f);
         glPopMatrix();
     glPopMatrix();
 }
 
 //Desenha o antebraço presente no código
 void desenhaAntebraco() {
     glPushMatrix();
         glColor4fv(cores[1]);
         desenhaSegmento(2.0f, 0.2f);
         
         
         glPushMatrix();
             glTranslatef(2.0f, 0.0f, 0.0f);
             
             
             glRotatef(pulso_x, 1.0f, 0.0f, 0.0f);
             glRotatef(pulso_y, 0.0f, 1.0f, 0.0f);
             glRotatef(pulso_z, 0.0f, 0.0f, 1.0f);
             
             
             glColor4fv(cores[0]);
             desenhaJunta(0.25f);
             
             
             desenhaMao();
         glPopMatrix();
     glPopMatrix();
 }
 
 //Desenha o braço superior presente no código
 void desenhaBracoSuperior() {
     glPushMatrix();
         glColor4fv(cores[1]);
         desenhaSegmento(2.5f, 0.3f);
         
         
         glPushMatrix();
             glTranslatef(2.5f, 0.0f, 0.0f);
             
             
             glRotatef(cotovelo, 0.0f, 0.0f, 1.0f);
             
             
             glColor4fv(cores[0]);
             desenhaJunta(0.3f);
             
             
             desenhaAntebraco();
         glPopMatrix();
     glPopMatrix();
 }
 
 //Desenha o braço
 void desenhaBraco() {
     glPushMatrix();
         
         glRotatef(ombro_x, 1.0f, 0.0f, 0.0f);
         glRotatef(ombro_y, 0.0f, 1.0f, 0.0f);
         glRotatef(ombro_z, 0.0f, 0.0f, 1.0f);
         
         
         glColor4fv(cores[0]);
         desenhaJunta(0.4f);
         
         
         desenhaBracoSuperior();
     glPopMatrix();
 }
 
 //Define a tela para vizualicação do úsuario 
 void display() {
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     
     
     glLoadIdentity();
     gluLookAt(0.0, 1.0, 10.0,  
               0.0, 0.0, 0.0,   
               0.0, 1.0, 0.0);  
               
     
     desenhaBraco();
     
     
     glDisable(GL_LIGHTING);
     glColor3f(1.0f, 1.0f, 1.0f);
     
     glMatrixMode(GL_PROJECTION);
     glPushMatrix();
         glLoadIdentity();
         gluOrtho2D(0, 800, 0, 600);
         
         glMatrixMode(GL_MODELVIEW);
         glPushMatrix();
             glLoadIdentity();
             glRasterPos2i(10, 580);
             std::string instrucoes = "Controles:";
             for (char c : instrucoes) {
                 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
             }
             
             glRasterPos2i(10, 560);
             std::string instrucoes1 = "Ombro: Q/A (X), W/S (Y), E/D (Z)";
             for (char c : instrucoes1) {
                 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
             }
             
             glRasterPos2i(10, 540);
             std::string instrucoes2 = "Cotovelo: R/F";
             for (char c : instrucoes2) {
                 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
             }
             
             glRasterPos2i(10, 520);
             std::string instrucoes3 = "Pulso: T/G (X), Y/H (Y), U/J (Z)";
             for (char c : instrucoes3) {
                 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
             }
             
             glRasterPos2i(10, 500);
             std::string instrucoes4 = "Dedos: 3/4 (indicador), 5/6 (medio), 7/8 (anelar), 9/0 (minimo)";
             for (char c : instrucoes4) {
                 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
             }
             
             glRasterPos2i(10, 480);
             std::string instrucoes5 = "Todos os dedos: C (fechar), V (abrir)";
             for (char c : instrucoes5) {
                 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
             }
         glPopMatrix();
         
         glMatrixMode(GL_PROJECTION);
     glPopMatrix();
     
     glMatrixMode(GL_MODELVIEW);
     glEnable(GL_LIGHTING);
     
     glutSwapBuffers();
 }
 
 //Projeção da visão do úsuairo em relação ao braço
 void reshape(int width, int height) {
     glViewport(0, 0, width, height);
     
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);
     
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
 }
 
 //Entrada do úsuairo 
 void keyboard(unsigned char key, int x, int y) {
     float velocidade = 5.0f;
     
     switch(key) {
         
         case 'q': ombro_x += velocidade; break;
         case 'a': ombro_x -= velocidade; break;
         case 'w': ombro_y += velocidade; break;
         case 's': ombro_y -= velocidade; break;
         case 'e': ombro_z += velocidade; break;
         case 'd': ombro_z -= velocidade; break;
         
         
         case 'r': cotovelo += velocidade; if (cotovelo > 135.0f) cotovelo = 135.0f; break;
         case 'f': cotovelo -= velocidade; if (cotovelo < 0.0f) cotovelo = 0.0f; break;
         
         
         case 't': pulso_x += velocidade; break;
         case 'g': pulso_x -= velocidade; break;
         case 'y': pulso_y += velocidade; break;
         case 'h': pulso_y -= velocidade; break;
         case 'u': pulso_z += velocidade; break;
         case 'j': pulso_z -= velocidade; break;
         
         
         
         case '3': dedo2 += velocidade; if (dedo2 > 90.0f) dedo2 = 90.0f; break;
         case '4': dedo2 -= velocidade; if (dedo2 < 0.0f) dedo2 = 0.0f; break;
         case '5': dedo3 += velocidade; if (dedo3 > 90.0f) dedo3 = 90.0f; break;
         case '6': dedo3 -= velocidade; if (dedo3 < 0.0f) dedo3 = 0.0f; break;
         case '7': dedo4 += velocidade; if (dedo4 > 90.0f) dedo4 = 90.0f; break;
         case '8': dedo4 -= velocidade; if (dedo4 < 0.0f) dedo4 = 0.0f; break;
         case '9': dedo5 += velocidade; if (dedo5 > 90.0f) dedo5 = 90.0f; break;
         case '0': dedo5 -= velocidade; if (dedo5 < 0.0f) dedo5 = 0.0f; break;
         
         
         case 'c':
             dedo2 = dedo3 = dedo4 = dedo5 = 90.0f;
             break;
             
         
         case 'v':
             dedo2 = dedo3 = dedo4 = dedo5 = 0.0f;
             break;
         
         
         case 27: 
             exit(0);
             break;
     }
     
     glutPostRedisplay();
 }
 
 //Função principal
 int main(int argc, char** argv) {
     
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
     glutInitWindowSize(800, 600);
     glutInitWindowPosition(100, 100);
     glutCreateWindow("Proejto Braco Robo");
     
     
     glClearColor(0.0f, 0.0f, 0.1f, 1.0f);
     glEnable(GL_DEPTH_TEST);
     
     
     configuraIluminacao();
     
     
     glutDisplayFunc(display);
     glutReshapeFunc(reshape);
     glutKeyboardFunc(keyboard);
     
     
     glutMainLoop();
     
     return 0;
 }