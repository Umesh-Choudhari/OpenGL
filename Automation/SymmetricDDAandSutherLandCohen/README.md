# Visualizer Project (OpenGL Automation)
 
## Overview

This graphical application, implemented in C++ using the Qt framework and OpenGL for rendering, functions as a visualization tool to illustrate the workings of Computer-Aided Geometric Design (CAGD) algorithms. The project incorporates the separation and automation of shader programs, allowing dynamic modifications to shader program files at runtime. As a result, alterations to the shader program files are promptly reflected in the OpenGL window. Detailed explanations of the modified shader program can be found at the end of this document.

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
 
**Shader Program**
 
1. Separated `vertexShader` and `fragmentShader` programs in different files.
 
- `Vertex.glsl` and `Fragment.glsl` with necessary changes.
 
2. Defined `readShader()` function to read shader programs from '.glsl' files.
 
3. Defined `shaderWatcher()` function to read updated data from `.glsl` files when we make any changes to it. and It releases the current OpenGL shader program, removes all shaders from it, and creates a new `QOpenGLShaderProgram` object.
It adds the `vertex` and `fragment` shaders to the `new program` from the corresponding source codes.
It `links` the shader program.
 
4. Added `connector` in `OpenGLWindow constructor`.When any of these files `(vertexShader.glsl or fragmentShader.glsl)` is modified, the fileChanged signal of the `QFileSystemWatcher` triggers the `shaderWatcher` function of the OpenGLWindow class. The connect function establishes this connection.
