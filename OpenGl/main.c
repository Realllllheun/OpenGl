#pragma comment (lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <math.h> // sin, cos 함수 사용

#define PI 3.14159265

void draw_circle() {
    float cx = 0.0f; // 중심 x
    float cy = 0.0f; // 중심 y
    float r = 0.8f;  // 반지름
    int num_segments = 100; // 삼각형 개수 (더 많을수록 부드러운 원)

    glBegin(GL_TRIANGLES); // 삼각형 그리기 시작
    for (int i = 0; i < num_segments; i++) {
        float theta1 = 2.0f * PI * i / num_segments;
        float theta2 = 2.0f * PI * (i + 1) / num_segments;

        // 삼각형 하나당 세 점
        glColor3f(1.0f, 0.5f, 0.0f); // 주황색 계열
        glVertex2f(cx, cy); // 중심점
        glVertex2f(cx + r * cosf(theta1), cy + r * sinf(theta1));
        glVertex2f(cx + r * cosf(theta2), cy + r * sinf(theta2));
    }
    glEnd();
}

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(500, 500, "GLFW:원형", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        draw_circle(); // 원형 그리기 함수 호출

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
