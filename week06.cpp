#include <GL/glut.h>///使用glut外掛
float angle=0;
void hand()
{
    glPushMatrix();
        glScalef(0.5,0.1,0.1);///細細長長的
        glutSolidCube(1);///方塊
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備分矩陣、左手臂
        glTranslatef(-0.25,0,0);///3.把正確地的手臂，掛在肩上
        glRotatef(angle,0,0,1);///2.轉動
        glTranslatef(-0.25,0,0);///1.將旋轉中心，放在正中心
        hand();///上手臂
        glPushMatrix();
            glTranslatef(-0.25,0,0);///3.把正確地的手肘，掛在肘關節上
            glRotatef(angle,0,0,1);///2.轉動
            glTranslatef(-0.25,0,0);///1.將旋轉中心，放在正中心
            hand();///下手臂
        glPopMatrix();
    glPopMatrix();///還原矩陣
    glPushMatrix();///備分矩陣、右手臂
        glTranslatef(+0.25,0,0);///3.把正確地的手臂，掛在肩上
        glRotatef(-angle,0,0,1);///2.轉動
        glTranslatef(+0.25,0,0);///1.將旋轉中心，放在正中心
        hand();///上手臂
        glPushMatrix();
            glTranslatef(+0.25,0,0);///3.把正確地的手肘，掛在肘關節上
            glRotatef(-angle,0,0,1);///2.轉動
            glTranslatef(+0.25,0,0);///1.將旋轉中心，放在正中心
            hand();///下手臂
        glPopMatrix();
    glPopMatrix();///還原矩陣
    glutSwapBuffers();///交換兩倍的buffers
    angle++;
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);///GLUT初始設定
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("08160360");

    glutIdleFunc(display);///idle很閒的時候，就重畫
    glutDisplayFunc(display);
    glutMainLoop();///主要迴圈
}
