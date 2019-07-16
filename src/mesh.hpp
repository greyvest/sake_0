#ifndef mesh_hpp
#define mesh_hpp

#include <stdio.h>
#include <iostream>
#include <GL/glew.h>

class Mesh
{
public:
    //Constructor/Destructor
    Mesh();
    ~Mesh();

    //Create mesh function
    void CreateMesh(GLfloat *vertices, unsigned int *indices, unsigned int numOfVertices, unsigned int numOfIndices);

    //Render Clear functions
    void RenderMesh();
    void ClearMesh();
    
    /* #region Operator overloads */
    friend std::ostream& operator<<(std::ostream& os, const Mesh& dt)
    {
        os << dt.VAO << dt.VBO << dt.IBO << dt.indexCount;
        return os;
    }

    friend std::istream & operator >> (std::istream &in, Mesh& c){
        in >> c.VAO >> c.VBO >> c.IBO >> c.indexCount;
        return in;
    }
    /* #endregion */

private:
    GLuint VAO, VBO, IBO;
    GLsizei indexCount;
};

#endif /* mesh_hpp */