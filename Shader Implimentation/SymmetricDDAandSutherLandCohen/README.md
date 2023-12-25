# Visualizer Project (OpenGL Shader Implimentation)
 
## Overview

This graphical application, implemented in C++ using the Qt framework and OpenGL for rendering, functions as a visualization tool to illustrate the workings of Computer-Aided Geometric Design (CAGD) algorithms. 

### Algorithms and Equations
 
1. **Sutherland Line Clipping Algorithm**
- The Sutherland-Hodgman line clipping algorithm efficiently determines and outputs the visible portion of a line segment within a specified rectangular window in computer graphics.
 
2. **Bezier Curve**
- A Bézier curve is a smooth curve defined by control points, commonly used in computer graphics and design. Its shape is influenced by the positions of these points, and it comes in various degrees, with quadratic and cubic being most common.
 
3. **Hermite Curve**
- A Hermite curve is a type of spline curve defined by two points and their associated tangent vectors. It is commonly used in computer graphics and computer-aided design to create smooth and predictable curves. The curve interpolates the given points and follows the specified tangent vectors at those points, providing control over both position and direction along the curve.
 
4. **BSpline Curve**
- A B-spline curve is a smooth and flexible mathematical curve defined by control points and basis functions, widely used in computer graphics and design for its local control and versatility in approximating complex shapes.
 
### File Structure
 
**Libraries**
 
1. `SutherlandAndCohenAlgo.lib` - Includes `utherlandAndCohenAlgo.h` and `utherlandAndCohenAlgo.cpp`
 
2. `Bezier.lib` - Includes `Bezier.h` and `Bezier.cpp`
 
3. `Hermite.lib` - Includes `Hermite.h` and `Bezier.cpp`
 
4. `BSpline.lib` - Includes `BSpline.h` and `BSpline.cpp`
 
5. `Geometry.lib`
 
Includes various geometry classes as follows
 
- `Point3D.h` and `Point3D.cpp`
 
- `Line.h` and `Line.cpp`
 
- `Rectanglee.h` and `Rectanglee.cpp`
 
**Visualizer App**
 
1. Includes `Visualizer.h` and `Visualizer.cpp`
- GUI components are implemented in these files.
 
2. Includes `OpenGLWindow.h` and `OpenGLWindow.cpp`
- Responsible for handling OpenGL rendering.
 
3. And `main.cpp`
- Entry point for the application, initializes and runs the graphical line clipping tool.
 

**Sharing Implementaion**
1. Added  button `Sharing` in GUI.
 
2. Defined two connector `setSharingFactor`  in `Visualizer.cpp`, passes `rotation, translation and scaling factor` to `OpenGLWindow.cpp`.
 
3. Defined `setSharingFactor` function that takes scale factor value and update scale `mScaleFactor`.
 
4. Created  `QMatrix4x4 scaleMatrix;` to scale drawing. 

5. Created  `QMatrix4x4 translateMatrix;` to translate drawing. 

6. Created  `QMatrix4x4 rotateMatrix;` to rotate drawing. 
 
7. And updated `vertexShader.glsl`.
