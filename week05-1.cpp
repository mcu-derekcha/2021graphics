#include <GL/glut.h>///(0)�ϥ�GLUT�~��
#include <stdio.h>
float vx[2000],vy[2000];///�ǳƤ@�ﳻ�I
int N=0;///��N�ӳ��I
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�M��
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<N;i++){
        glVertex2f(vx[i],vy[i]);
    }
    glEnd();
    glutSwapBuffers();///�洫�⭿��buffers
}
void mouse(int buttin,int state,int x,int y)
{

}
void motion(int x,int y)
{
    printf("%d %d\n",x,y);///�⳻�I�O�_��...���@�U�n�e
    vx[N]=(x-150)/150.0;///�ܹ��o�˪��g�k�A�O���_��
    vy[N]=-(y-150)/150.0;
    N++;
    display();
}  ///��@�b�A�b���@�b�Ay�[�t��
int main(int argc, char ** argv)///�H�e�Oint main()
{
    glutInit(&argc, argv);///(1)GLUT��l�]�w
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///(2)��ܼҦ�
    glutCreateWindow("08160360_���۷�");///�}��

    glutDisplayFunc(display);///(4)���@�U�n��ܪ��禡
    glutMouseFunc(mouse);///�ƹ����U�h�u�_��
    glutMotionFunc(motion);///mouse motion �b��(�즲)/�A�e
    glutMainLoop();///(5)�D�n�j��
}
