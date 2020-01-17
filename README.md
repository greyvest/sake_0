# sake 0


An OpenGL graphics engine developed by me, Austin Anderson, for learning purposes. I have now switched this project over to developing on a forked version of https://github.com/TheCherno/OpenGL due to numorous cross-platform development hiccups. That repository can be found on my profile. 

Project Goals:

1. Cross platform development and compilation
2. Custom and usable file serialization and project structure
3. Usable GUI for game development
4. Reasonably performant

Dependencies:

[OpenGL 3](https://www.opengl.org/) and [GLEW](http://glew.sourceforge.net/) for Graphical Rendering

[GLM](https://glm.g-truc.net/0.9.9/index.html) Math Library

[Dear_ImGui](https://github.com/ocornut/imgui) for GUI implementation

[Assimp](http://www.assimp.org/) for asset importing

[CMake](https://cmake.org/) for compilation

Resources Used:

[OpenGL Udemy Course](https://www.udemy.com/graphics-with-modern-opengl/)



# usage instructions

Note: Currently only compiling on Mac OSX

1. Clone project
2. Install dependencies (I suggest using brew on mac or choco on windows)
3. '''cmake .''' inside of project directory
4. '''make''' inside of project directory
5. run '''./sake''' to start engine
