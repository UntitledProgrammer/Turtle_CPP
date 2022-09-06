# C++ Graphics Turtle.  
>**Introduction**  
>The c++ graphics turtle is a small, personal project that mimics the use of Python's graphics turtle in the c++ programming language. The graphics turtle provides a straightforward framework to encourage newcomers to learn and experience low-level graphics programming.

>**Concepts & Usage**  
> You can think of the rendering window as a 2D graph and canvas that outlines the area where the turtle can draw. The rendering window uses a traditional format that places the point of origin (0,0) in the top left corner.  
>
>`Turtle::Forward(unsigned int steps)`  
>Moves the turtle along its localised vertical axis according to the number of steps (pixels) specified.  
>
>`Turtle::Backward(unsigned int steps)`  
> Moves the turtle along its localised vertical axis according to the number of steps (pixels) specified. Unlike the forward method, this method multiplies the localised vertical axis by a negative one.  
>
>`Turtle::SetRotation(float eulerAngle)`   
>Sets the turtle's rotation. The angle specified should always be kept to Euler angles, although the turtle works with radians "behind the scenes". (The turtle handles the conversion).  
>
>`Turtle::Rotate(float eulerAngle)`  
Rotate is a cumulative method that adds the specified Euler angle to the turtle's current rotation.  

>**Dependencies**  
>The graphics turtle is written entirely in header (.h) and source (.cpp) files, utilising 'SDL' for graphics rendering and 'GLM' for Vector and Matrix arithmetic.
>
>*Library Resources*  
><a href="https://github.com/libsdl-org/SDL"> SDL Repository.</a>  
><a href="https://github.com/g-truc/glm">GLM Repository.</a>
