/*
SAKE ENGINE

Developed by Austin Anderson 2019

This is an OpenGL engine developed for learning purposes.
 */

/* #region includes */
//--Standard Library Header Files--
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
//--Third Pawrty Header Files--
//GLEW
#define GLEW_STATIC
#include<GL/glew.h>
//GLFW
#include <GLFW/glfw3.h>
//GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//IMGUI
#include "Imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
//ASSIMP
//#include <assimp/Importer.hpp>
//--Project Header Files--
#include "commonValues.h"
#include "window.hpp"
#include "mesh.hpp"
#include "camera.hpp"
#include "shader.hpp"
#include "texture.hpp"
#include "material.hpp"
#include "directionalLight.hpp"
#include "pointLight.hpp"
#include "object.hpp"
/* #endregion */

/* #region constants */
//Radian conversion Const
const float toRadians = 3.14159265f / 180.0f;

/* #endregion */

/* #region Global Variables */
//Main window object
Window mainWindow;
//Master list of meshes
std::vector<Mesh*> meshList;
std::vector<Shader> shaderList;
//Camera Object
Camera camera;
//List of textueres:
Texture brickTexture;
Texture dirtTexture;
Texture plainTexture;

Material shinyMaterial;
Material dullMaterial;

DirectionalLight mainLight;

PointLight pointLights[MAX_POINT_LIGHTS];

GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;

GLfloat movementVelocity = 0.01f;

glm::vec3 controllerVec; 

//Shader location constants
static const char * vShader = "src/Shaders/shader.vert";

static const char * fShader = "src/Shaders/shader.frag";

/* #endregion */

/* #region Calc Normals */
//TODO: Maybe extract this into seperate file?
void calcAverageNormals(unsigned int * indices, unsigned int indiceCount, GLfloat * vertices, unsigned int verticeCount,
                        unsigned int vLength, unsigned int normalOffset)
{
    for (size_t i = 0; i < indiceCount; i += 3)
    {
        unsigned int in0 = indices[i] * vLength;
        unsigned int in1 = indices[i + 1] * vLength;
        unsigned int in2 = indices[i + 2] * vLength;
        glm::vec3 v1(vertices[in1] - vertices[in0], vertices[in1 + 1] - vertices[in0 + 1], vertices[in1 + 2] - vertices[in0 + 2]);
        glm::vec3 v2(vertices[in2] - vertices[in0], vertices[in2 + 1] - vertices[in0 + 1], vertices[in2 + 2] - vertices[in0 + 2]);
        glm::vec3 normal = glm::cross(v1, v2);
        normal = glm::normalize(normal);
        
        in0 += normalOffset; in1 += normalOffset; in2 += normalOffset;
        vertices[in0] += normal.x; vertices[in0 + 1] += normal.y; vertices[in0 + 2] += normal.z;
        vertices[in1] += normal.x; vertices[in1 + 1] += normal.y; vertices[in1 + 2] += normal.z;
        vertices[in2] += normal.x; vertices[in2 + 1] += normal.y; vertices[in2 + 2] += normal.z;
    }
    
    for (size_t i = 0; i < verticeCount / vLength; i++)
    {
        unsigned int nOffset = i * vLength + normalOffset;
        glm::vec3 vec(vertices[nOffset], vertices[nOffset + 1], vertices[nOffset + 2]);
        vec = glm::normalize(vec);
        vertices[nOffset] = vec.x; vertices[nOffset + 1] = vec.y; vertices[nOffset + 2] = vec.z;
    }
}
/* #endregion */

/* #region Create Objects */
void CreateObjects()
{
    unsigned int indices[] = {
        0, 3, 1,
        1, 3, 2,
        2, 3, 0,
        0, 1, 2
    };
    
    GLfloat vertices[] = {
        //    x      y      z            u      v            nx      ny    nz
        -1.0f, -1.0f, -0.6f,        0.0f, 0.0f,        0.0f, 0.0f, 0.0f,
        0.0f, -1.0f, 1.0f,        0.5f, 0.0f,        0.0f, 0.0f, 0.0f,
        1.0f, -1.0f, -0.6f,        1.0f, 0.0f,        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,        0.5f, 1.0f,        0.0f, 0.0f, 0.0f
    };
    
    unsigned int floorIndices[] = {
        0, 2, 1,
        1, 2, 3
    };
    
    GLfloat floorVertices[] = {
        -10.0f, 0.0f, -10.0f,    0.0f, 0.0f,        0.0f, -1.0f, 0.0f,
        10.0f, 0.0f, -10.0f,    10.0f, 0.0f,    0.0f, -1.0f, 0.0f,
        -10.0f, 0.0f, 10.0f,    0.0f, 10.0f,    0.0f, -1.0f, 0.0f,
        10.0f, 0.0f, 10.0f,        10.0f, 10.0f,    0.0f, -1.0f, 0.0f
    };
    
    calcAverageNormals(indices, 12, vertices, 32, 8, 5);
    
    Mesh *obj1 = new Mesh();
    obj1->CreateMesh(vertices, indices, 32, 12);
    meshList.push_back(obj1);
    
    Mesh *obj2 = new Mesh();
    obj2->CreateMesh(vertices, indices, 32, 12);
    meshList.push_back(obj2);
    
    Mesh *obj3 = new Mesh();
    obj3->CreateMesh(floorVertices, floorIndices, 32, 6);
    meshList.push_back(obj3);

    Mesh *obj4 = new Mesh();
    obj4->CreateMesh(vertices, indices, 32, 12);
    meshList.push_back(obj4);
}
/* #endregion */

/* #region Create Shaders */
void CreateShaders()
{
    Shader *shader1 = new Shader();
    shader1->CreateFromFiles(vShader, fShader);
    shaderList.push_back(*shader1);
}
/* #endregion */

/* #region SetControllerLoc */
void SetControllerLoc(bool* keys, GLfloat deltaTime){
    //GLfloat velocity = moveSpeed * deltaTime;
    
    if (keys[GLFW_KEY_W])
    {
        controllerVec.y += 1.0 * movementVelocity;
    }
    
    if (keys[GLFW_KEY_S])
    {
        controllerVec.y -= 1.0 * movementVelocity;
    }
    
    if (keys[GLFW_KEY_A])
    {
        controllerVec.z -= 1.0 * movementVelocity;
    }
    
    if (keys[GLFW_KEY_D])
    {
        controllerVec.z += 1.0 * movementVelocity;
    }
}
/* #endregion */

/* #region Render Model Function */
void renderAModel(glm::mat4 * model, GLuint uniformModel, glm::vec3 * pos, Texture * renderTex, Material * renderMat, GLuint uniformSpecularIntensity, GLuint uniformShininess, int i){
    model = new glm::mat4(1.0f);
    *model = glm::translate(*model, *pos);
    glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(*model));
    renderTex->UseTexture();
    renderMat->UseMaterial(uniformSpecularIntensity, uniformShininess);
    meshList[i]->RenderMesh();
}
/* #endregion */
int main(){
    //Set main window size and initialise
    mainWindow = Window(900, 600); // 1280, 1024 or 1024, 768
    mainWindow.Initialise();

   
    /* #region Load Textures and materials */
    
    brickTexture = Texture("src/textures/brick.png");
    brickTexture.LoadTextureA();
    dirtTexture = Texture("src/textures/dirt.png");
    dirtTexture.LoadTextureA();
    plainTexture = Texture("src/textures/plain.png");
    plainTexture.LoadTextureA();
    
    shinyMaterial = Material(4.0f, 256);
    dullMaterial = Material(0.3f, 4);
    /* #endregion */


    std::vector<Object> objectList;

    objectList.push_back(Object(new glm::vec3(8.0f, 2.0f,1.0f),&brickTexture,&dullMaterial));
    objectList.push_back(Object(new glm::vec3(4.0f, 4.0f,1.0f),&brickTexture,&dullMaterial));
    objectList.push_back(Object(new glm::vec3(1.0f, 0.0f,3.0f),&dirtTexture,&dullMaterial));
    objectList.push_back(Object(new glm::vec3(0.0f, -4.0f,1.0f),&plainTexture,&dullMaterial));


    //GLSL version for IMGUI;
    const char* glsl_version = "#version 150"; 

    /* #region IMGUI setup code*/
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); 
    (void)io;
    ImGui_ImplGlfw_InitForOpenGL(mainWindow.getMainWindow(), true);
    ImGui::StyleColorsDark();
    ImGui_ImplOpenGL3_Init(glsl_version);
    bool show_demo_window = true;
    bool show_another_window = false;
    
    io.MouseDrawCursor = true;
    io.MousePos = ImVec2(0,0);
    /* #endregion */

    //Create control vec
    controllerVec = glm::vec3(8,0,0);
    //Create objects and shaders
    CreateObjects();
    CreateShaders();
    
    //Camera Setup
    camera = Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 0.0f, 0.0f, 5.0f, 0.5f);
    
    GLfloat mlightAI = 0.6f;
    GLfloat mlightDI = 0.0f;

    /* #region Light setup */
    mainLight = DirectionalLight(1.0f, 1.0f, 1.0f,
                                 mlightAI, mlightDI,
                                 0.0f, 0.0f, -1.0f);

    GLfloat red; GLfloat green; GLfloat blue;
    GLfloat aIntensity; GLfloat dIntensity;
    GLfloat xPos; GLfloat yPos; GLfloat zPos;
    GLfloat con; GLfloat lin; GLfloat exp;
    

    unsigned int pointLightCount = 0;
    pointLights[0] = PointLight(1.0f, 0.0f, 1.0f,
                                0.0f, 1.0f,
                                0.0f, 1.0f, 0.0f,
                                0.3f, 0.2f, 0.1f);
    pointLightCount++;
    pointLights[1] = PointLight(0.0f, 1.0f, 0.0f,
                                0.0f, 1.0f,
                                -4.0f, 2.0f, 0.0f,
                                0.3f, 0.1f, 0.1f);
    pointLightCount++;
    
    /* #endregion */
    
    /* #region Setup projection  matrix */
    GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0, uniformEyePosition = 0,
    uniformSpecularIntensity = 0, uniformShininess = 0;
    glm::mat4 projection = glm::perspective(45.0f, (GLfloat)mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 100.0f);
    /* #endregion */
    while(!mainWindow.getShouldClose()){
        /* #region Time Controls */
        GLfloat now = glfwGetTime();
        deltaTime = now - lastTime;
        lastTime = now;
        /* #endregion */

        // Get + Handle User Input
        glfwPollEvents();

        /* #region Mouse Tracking */
        char * barrier = "";
        if(io.MousePos.x < 0){
            io.MousePos = ImVec2(0,io.MousePos.y);
            barrier = "left";
        }
        if(io.MousePos.x > 900){
            io.MousePos.x = 900;
            barrier = "right";
        }
        if(io.MousePos.y < 0){
            io.MousePos.y = 0;
            barrier = "top";
        }
        if(io.MousePos.y > 600){
            io.MousePos.y = 600;
            barrier = "bottom";
        }
        /* #endregion Mouse Trackin */
        
        /* #region IMGUI */
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        
        {
            if(ImGui::BeginMainMenuBar()){
                if (ImGui::MenuItem("Open..", "Ctrl+O")) {
                    /* Do stuff */ 
                }
                if (ImGui::MenuItem("Save", "Ctrl+S"))   {
                    /* Do stuff */ 
                }
                if (ImGui::MenuItem("Close", "Ctrl+W"))  { /*Do stuff */}
                if (ImGui::BeginMenu("More Options")){
                    ImGui::MenuItem("Xthing");
                    ImGui::MenuItem("Ything");
                    ImGui::EndMenu();
                }
                if (ImGui::MenuItem("Exit", "Ctrl+S"))   {
                    break;
                }
                ImGui::EndMainMenuBar();
            }
        }
        
        {
            ImGuiWindowFlags window_flags = 0;
            //window_flags |= ImGuiWindowFlags_NoTitleBar;
            window_flags |= ImGuiWindowFlags_NoScrollbar;
            //window_flags |= ImGuiWindowFlags_NoMove;
            //window_flags |= ImGuiWindowFlags_NoResize;
            //window_flags |= ImGuiWindowFlags_NoCollapse;
            //window_flags |= ImGuiWindowFlags_NoNav;
            //window_flags |= ImGuiWindowFlags_NoBackground;
            

            ImGui::Begin("Mouse Tracking", NULL, window_flags);                         
            ImGui::Text("Mouse Pos: X %.6f Y: %.6f\n", io.MousePos.x, io.MousePos.y);

            ImGui::Text("Camera Pos: X %.6f Y: %.6f Z: %.6f Yaw: %.6f Pitch: %.6f\n", camera.getCameraPosition().x, camera.getCameraPosition().y, camera.getCameraPosition().z, camera.getYaw(), camera.getPitch());

            ImGui::Text("Broker barrier on %s \n", barrier);

            ImGui::End();
        } 

        /* #endregion */
        
        /* #region Camera Controls */
        camera.keyControl(mainWindow.getsKeys(), deltaTime);
        if(camera.getCameraState())
            camera.mouseControl(mainWindow.getXChange(), mainWindow.getYChange());
        /* #endregion */

        //Current function for moving object on screen
        //SetControllerLoc(mainWindow.getsKeys(), deltaTime);
        
        // Clear the window
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        /* #region Calculating Lighting */
        shaderList[0].UseShader();
        uniformModel = shaderList[0].GetModelLocation();
        uniformProjection = shaderList[0].GetProjectionLocation();
        uniformView = shaderList[0].GetViewLocation();
        uniformEyePosition = shaderList[0].GetEyePositionLocation();
        uniformSpecularIntensity = shaderList[0].GetSpecularIntensityLocation();
        uniformShininess = shaderList[0].GetShininessLocation();
        
        shaderList[0].SetDirectionalLight(&mainLight);
        //Commented because I can't understand why this won't work
        //shaderList[0].SetPointLights(pointLights, pointLightCount);
        
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
        glUniform3f(uniformEyePosition, camera.getCameraPosition().x, camera.getCameraPosition().y, camera.getCameraPosition().z);
        /* #endregion */

        //Create new Mat for Model
        glm::mat4 model(1.0f);

        /* #region Model Rendering */
        for(int i = 0; i < objectList.size(); i++){
            renderAModel(&model, uniformModel, objectList[i].pos, objectList[i].texture, objectList[i].material, uniformSpecularIntensity, uniformShininess, i);
        }
        /* #endregion */

        //Fianl rendering calls        
        glUseProgram(0);
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        //swap in buffers
        mainWindow.swapBuffers();
        
    }
    //Clean up GUI
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    
    return 0;
}