#version 330 core
//#define Julia
#define Mandelbrot

out vec4 FragColor;
in vec3 pos;
uniform float r;
uniform float q;

uniform float x;
uniform float y;
uniform float z;

uniform float i;
uniform float j;

vec3 isInSet(vec2 pos);

void main()
{
	
		FragColor = vec4(isInSet(vec2(pos.y/(z)*q+x,pos.x/(z)+y)),1);
	
	
}

vec2 res(vec2 z,vec2 c){
return vec2(pow(z.x,2) - pow(z.y,2) + c.x,2*z.x*z.y+ c.y);
}


vec3 isInSet(vec2 pos)
{	
#ifdef Julia
	vec2 c = vec2(.34+i,.34+j);
#endif
#ifdef Mandelbrot
	vec2 c = pos;
#endif
	vec2 zn = res(pos,c);
	
	int s = 200;
	for(int j = 0;j<int(r);j=j+1)
	{
		 s = 64;
		 zn = res(zn,c);
		 if(pow(zn.x,2)+pow(zn.y,2)>4)
			return vec3(float(j)/s/2,float(j)/s/5,1-float(j)/s);
			//return vec3(1-float(j)/s,1-float(j)/s,1-float(j)/s);
 
	}
	return vec3(0,0,0);


	
}


