#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <gameobject.hpp>
#include <window.hpp>
#include <Camera.hpp>

#include <iostream>

int screenHeight = 800;
int screenWidth = 600;

float deltaTime = 1;
float lastFrame = glfwGetTime();
float currentFrame;

float xoffset;
float yoffset;

float camDamp = 0.2;

float pitch, yaw;
float lastX = static_cast<float>(screenWidth / 2), lastY = static_cast<float>( screenHeight/ 2);

bool fullscr = false;

void processInput(GLFWwindow* window, Camera& cam);
void viewportSizeChanged(GLFWwindow* window, int width, int height);
void mouseUpdate(GLFWwindow* window, double xpos, double ypos);

int main (int argc, char *argv[]) {

    // Create window
    Window myWin = Window(600, 620, "Awesome sauce");
    myWin.makeWindowContextCurrent();
    
    std::cout << "Loading glad...\n";
    // Load glad function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    else
    {
        std::cout << "Glad initialized succesfully\n";
    }
    // Set callbacks
    glfwSetFramebufferSizeCallback(myWin.getWindow(), viewportSizeChanged);
    glfwSetCursorPosCallback(myWin.getWindow(), mouseUpdate);  

    glEnable(GL_DEPTH_TEST);

    // Create camera
    Camera playerCamera = Camera(screenHeight, screenWidth, 90.0f, 0.1f, 100.0f);
    playerCamera.transform.position = glm::vec3(0, 0, 10);
    playerCamera.transform.localFront = glm::vec3(0,0,-1);
    playerCamera.cameraMode = FirstPerson;
    playerCamera.dampening = camDamp;

    Shader myShader = Shader("../src/Shaders/vertex.glsl", "../src/Shaders/fragment.glsl");
    
    // End of boilerplate
    GameObject myObject = GameObject();
    myObject.BufferMeshData("../assets/models/GuitarBag/guitarPack.fbx");

    glm::mat4 projection;
    glm::mat4 view;

    projection = glm::perspective(glm::radians(playerCamera.fov), (float)screenHeight / (float)screenWidth, playerCamera.getMin(), playerCamera.getMax());
    myShader.use();
    myShader.setMat4("projection", projection); 
    
    glfwSetInputMode(myWin.getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);  

    while (!myWin.getWindowCloseState())
    {

        currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glClearColor(0.3f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
        myObject.transform.rotationEuler += glm::vec3(0, 10 * deltaTime, 0);

        const float radius = 10.0f;

        playerCamera.transform.rotationEuler = glm::vec3(yaw,pitch, 0);

        view = playerCamera.calculateView();

        myObject.Draw(view);

        processInput(myWin.getWindow(), playerCamera);

        glfwSwapBuffers(myWin.getWindow());
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}


void processInput(GLFWwindow* window, Camera& cam)
{
    float CamSpeed = cam.camSpeed * deltaTime;

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
    {
        GLFWmonitor* monitor = glfwGetWindowMonitor(window);
        if (monitor == NULL && !fullscr)
        {
            std::cout << "Fullscr\n";
            monitor = glfwGetPrimaryMonitor();
            const GLFWvidmode* mode = glfwGetVideoMode(monitor);
            glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
            fullscr = true;
        }
        else if (!fullscr){
            std::cout << "Windowed\n";
            glfwSetWindowMonitor(window, NULL, 200, 200, 600, 600, 0);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_RELEASE)
        fullscr = false;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cam.transform.position += cam.transform.localFront * CamSpeed;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cam.transform.position -= glm::normalize(glm::cross(cam.transform.localFront, glm::vec3(0,1,0))) * CamSpeed;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cam.transform.position -= cam.transform.localFront * CamSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cam.transform.position += glm::normalize(glm::cross(cam.transform.localFront, glm::vec3(0,1,0))) * CamSpeed;
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        cam.transform.position += glm::vec3(0, 1, 0) * CamSpeed;
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        cam.transform.position -= glm::vec3(0, 1, 0) * CamSpeed;

}

void viewportSizeChanged(GLFWwindow* window, int width, int height)
{
    screenWidth = width;
    screenHeight = height;
    lastX = static_cast<float>(screenWidth / 2);
    lastY = static_cast<float>(screenHeight/ 2);

    glViewport(0, 0, width, height);
}

void mouseUpdate(GLFWwindow* window, double xpos, double ypos)
{
    xoffset = xpos - lastX;
    yoffset = lastY - ypos; 
    lastX = xpos;
    lastY = ypos;
    
    const float sensitivity = 0.2;// * deltaTime;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0)
        pitch = 89.0;
    else if (pitch < -89.0)
        pitch = -89.0;
}
