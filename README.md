# MandelbrotSet_GL
Mandelbrot set and Julia set visualisation with OpenGL   
# Reqirements libs:
- [GLFW](https://www.glfw.org/download.html)
- [glad](https://glad.dav1d.de/)
# Management:
- To chose which fractal you want to see   
you should comment one of `#define` in ***fragment.glsl***:   
`#define Julia`  
`#define Mandelbrot`
- To move use : **`w` `a` `s` `d`**
- To zoom in : **`z`**
- To zoom out : **`c`**
- To increase iterations : **`r`**
- To decrease iterations : **`e`**
- To change constant **c = a + b*i*** for Julia set:   
  - to increase/decreace a : **`f` `g`**
  - to increase/decreace b : **`c` `v`**
  

# Screenshots:
![Mandelbrot Set](https://github.com/GlebPlakhtii/MandelbrotSet_GL/blob/master/Images/Mandelbrot%2018.02.2022%2020_29_17.png)
![Mandelbrot Set](https://github.com/GlebPlakhtii/MandelbrotSet_GL/blob/master/Images/Mandelbrot%2018.02.2022%2020_30_12.png)
![Julia Set](https://github.com/GlebPlakhtii/MandelbrotSet_GL/blob/master/Images/Mandelbrot%2018.02.2022%2020_33_00.png)




