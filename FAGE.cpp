// =====================================================
// FAGE - ForgeHold Advanced Gaming Engine
// Stage 1: Window aur Game Loop
// =====================================================

// GLAD ko GLFW se PEHLE include karna zaroori hai
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

// Jab window ka size badle, to OpenGL ko naya size bata do
void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// Keyboard check karne wala function
void processInput(GLFWwindow* window)
{
    // Agar ESC dabaya jaye to window band karne ka ishara do
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

int main()
{
    // 1) GLFW ko shuru karo
    if (!glfwInit())
    {
        std::cout << "FAGE Error: GLFW shuru nahi ho saka" << std::endl;
        return -1;
    }

    // 2) OpenGL ka version batao (3.3 Core)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // 3) Window banao
    GLFWwindow* window = glfwCreateWindow(1280, 720, "FAGE - ForgeHold Advanced Gaming Engine", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "FAGE Error: Window nahi ban saki" << std::endl;
        glfwTerminate();
        return -1;
    }

    // 4) Is window ko OpenGL ke liye "active" karo
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    // 5) GLAD se OpenGL ke functions load karo
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "FAGE Error: GLAD load nahi ho saka" << std::endl;
        return -1;
    }

    std::cout << "FAGE shuru ho gaya!" << std::endl;
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

    // 6) GAME LOOP - jab tak window band na ho, chalta rahega
    while (!glfwWindowShouldClose(window))
    {
        // Input lo
        processInput(window);

        // Screen ko ek rang se saaf karo (gehra neela)
        glClearColor(0.08f, 0.10f, 0.20f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Tayyar frame ko screen par dikhao
        glfwSwapBuffers(window);

        // Keyboard/mouse ke events check karo
        glfwPollEvents();
    }

    // 7) Safai karke band karo
    glfwTerminate();
    return 0;
}