#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>
#include "gl/glut.h"
#include <cmath>

const float PI = 3.14159265358979323846f;

// ��ʼ������
int init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // ���ñ���ɫΪ��ɫ
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // ��������ϵ��Χ
    return 1;
}

// ��������Ǻ���
void drawStar() {
    float outerRadius = 0.8f; // ���Բ�뾶
    float innerRadius = outerRadius * sin(PI / 10) / sin(3 * PI / 10); // �ڽ�Բ�뾶
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 0.0f); // ���ĵ�Ϊ��ɫ
    glVertex2f(0.0f, 0.0f); // ���ĵ�
    
    for (int i = 0; i <= 10; ++i) {
        float angle = PI / 2 + 2 * PI * i / 10; // ����Ƕ�
        float radius = (i % 2 == 0) ? outerRadius : innerRadius; // ����ʹ������뾶
        
        // ����ʹ�ú�ɫ�ͻ�ɫ
        if (i % 2 == 0) {
            glColor3f(1.0f, 0.0f, 0.0f); // ��ɫ
        } else {
            glColor3f(1.0f, 1.0f, 0.0f); // ��ɫ
        }
        
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }
    
    glEnd();
}

// ��ʾ�ص�����
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // �����ɫ������
    
    drawStar(); // ���������
    
    glFlush(); // ˢ�»�����
}
int main(int argc, char** argv) {
    glutInit(&argc, argv); // ��ʼ��GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // ������ʾģʽ
    glutInitWindowSize(500, 500); // ���ô��ڴ�С
    glutInitWindowPosition(100, 100); // ���ô���λ��
    glutCreateWindow("OpenGL �����");
    glutDisplayFunc(display); // ע����ʾ�ص�����
    
    glutMainLoop(); // ������ѭ��
  
    return 0;
}