#include <GL/glut.h>///�ϥ�glut�~��
float angle=0;
void hand()
{
    glPushMatrix();
        glScalef(0.5,0.1,0.1);///�ӲӪ�����
        glutSolidCube(1);///���
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///�Ƥ��x�}�B�����u
        glTranslatef(-0.25,0,0);///3.�⥿�T�a�����u�A���b�ӤW
        glRotatef(angle,0,0,1);///2.���
        glTranslatef(-0.25,0,0);///1.�N���त�ߡA��b������
        hand();///�W���u
        glPushMatrix();
            glTranslatef(-0.25,0,0);///3.�⥿�T�a����y�A���b�y���`�W
            glRotatef(angle,0,0,1);///2.���
            glTranslatef(-0.25,0,0);///1.�N���त�ߡA��b������
            hand();///�U���u
        glPopMatrix();
    glPopMatrix();///�٭�x�}
    glPushMatrix();///�Ƥ��x�}�B�k���u
        glTranslatef(+0.25,0,0);///3.�⥿�T�a�����u�A���b�ӤW
        glRotatef(-angle,0,0,1);///2.���
        glTranslatef(+0.25,0,0);///1.�N���त�ߡA��b������
        hand();///�W���u
        glPushMatrix();
            glTranslatef(+0.25,0,0);///3.�⥿�T�a����y�A���b�y���`�W
            glRotatef(-angle,0,0,1);///2.���
            glTranslatef(+0.25,0,0);///1.�N���त�ߡA��b������
            hand();///�U���u
        glPopMatrix();
    glPopMatrix();///�٭�x�}
    glutSwapBuffers();///�洫�⭿��buffers
    angle++;
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);///GLUT��l�]�w
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("08160360");

    glutIdleFunc(display);///idle�ܶ����ɭԡA�N���e
    glutDisplayFunc(display);
    glutMainLoop();///�D�n�j��
}
