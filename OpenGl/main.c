#pragma comment (lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <math.h> // sin, cos �Լ� ���

#define PI 3.14159265

void draw_circle() {
    float cx = 0.0f; // �߽� x
    float cy = 0.0f; // �߽� y
    float r = 0.8f;  // ������
    int num_segments = 100; // �ﰢ�� ���� (�� �������� �ε巯�� ��)

    glBegin(GL_TRIANGLES); // �ﰢ�� �׸��� ����
    for (int i = 0; i < num_segments; i++) {
        float theta1 = 2.0f * PI * i / num_segments;
        float theta2 = 2.0f * PI * (i + 1) / num_segments;

        // �ﰢ�� �ϳ��� �� ��
        glColor3f(1.0f, 0.5f, 0.0f); // ��Ȳ�� �迭
        glVertex2f(cx, cy); // �߽���
        glVertex2f(cx + r * cosf(theta1), cy + r * sinf(theta1));
        glVertex2f(cx + r * cosf(theta2), cy + r * sinf(theta2));
    }
    glEnd();
}

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(500, 500, "GLFW:����", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        draw_circle(); // ���� �׸��� �Լ� ȣ��

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
