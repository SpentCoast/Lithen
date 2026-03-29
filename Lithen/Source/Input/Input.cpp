#include "Input.h"

#include "Lithen/Application.h"

#include <GLFW/glfw3.h>

namespace Lithen {

    bool Input::IsKeyDown(KeyCode keyCode)
    {
        GLFWwindow* windowHandle = Application::Get().GetWindowHandle();
        int state = glfwGetKey(windowHandle, (int)keyCode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool Input::IsMouseButtonDown(MouseButton button)
    {
        GLFWwindow* windowHandle = Application::Get().GetWindowHandle();
        int state = glfwGetMouseButton(windowHandle, (int)button);
        return state == GLFW_PRESS;
    }

    glm::vec2 Input::GetMousePosition()
    {
        GLFWwindow* windowHandle = Application::Get().GetWindowHandle();

        double x, y;
        glfwGetCursorPos(windowHandle, &x, &y);

        return { (float)x, (float)y };
    }

    void Input::SetCursorMode(CursorMode mode)
    {
        GLFWwindow* windowHandle = Application::Get().GetWindowHandle();
        glfwSetInputMode(windowHandle, GLFW_CURSOR, GLFW_CURSOR_NORMAL + (int)mode);
    }

}
