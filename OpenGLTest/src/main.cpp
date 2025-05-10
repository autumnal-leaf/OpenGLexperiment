#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>
#include "gl/glut.h"
#include <cmath>

const float PI = 3.14159265358979323846f;

// 初始化函数
int init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 设置背景色为黑色
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // 设置坐标系范围
    return 1;
}

// 绘制五角星函数
void drawStar() {
    float outerRadius = 0.8f; // 外接圆半径
    float innerRadius = outerRadius * sin(PI / 10) / sin(3 * PI / 10); // 内接圆半径
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 0.0f); // 中心点为黄色
    glVertex2f(0.0f, 0.0f); // 中心点
    
    for (int i = 0; i <= 10; ++i) {
        float angle = PI / 2 + 2 * PI * i / 10; // 计算角度
        float radius = (i % 2 == 0) ? outerRadius : innerRadius; // 交替使用内外半径
        
        // 交替使用红色和黄色
        if (i % 2 == 0) {
            glColor3f(1.0f, 0.0f, 0.0f); // 红色
        } else {
            glColor3f(1.0f, 1.0f, 0.0f); // 黄色
        }
        
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }
    
    glEnd();
}

// 显示回调函数
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // 清除颜色缓冲区
    
    drawStar(); // 绘制五角星
    
    glFlush(); // 刷新缓冲区
}
int main(int argc, char** argv) {
    glutInit(&argc, argv); // 初始化GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // 设置显示模式
    glutInitWindowSize(500, 500); // 设置窗口大小
    glutInitWindowPosition(100, 100); // 设置窗口位置
    glutCreateWindow("OpenGL 五角星");
    glutDisplayFunc(display); // 注册显示回调函数
    
    glutMainLoop(); // 进入主循环
  
    return 0;
}