#include <iostream>
#include "Window.h"



int main()
{


    

    Window win(1000, 800);

    float vert[] =
    { 1.0f,1.0f,.0f,
      1.0f,-1.0f,.0f,
      -1.0f,-1.0f,.0f,
      -1.0f,1.0f,.0f,
    };
    int indexes[] =
    {
        0,1,2,
        2,3,0
    };


    unsigned int VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);
    

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexes), indexes, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
    glEnableVertexAttribArray(0);
   

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);




    win.create_shader("Vertex.glsl", "Fragment.glsl");
    win.main_loop(VAO);
    
}


