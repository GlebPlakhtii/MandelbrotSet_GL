#version 330 core
uniform float i;
layout (location = 0) in vec3 aPos;
out vec3 pos;


void main()
{

   gl_Position = vec4(aPos.y,aPos.x,aPos.z, 1.0);
   pos = aPos;
   
}