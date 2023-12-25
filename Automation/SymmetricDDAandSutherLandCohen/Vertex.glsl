attribute highp vec4 posAttr;
attribute lowp vec4 colAttr;
varying lowp vec4 col;
uniform highp mat4 matrix;
uniform highp mat4 scaleMatrix;
uniform highp mat4 rotateMatrix;
uniform highp mat4 translateMatrix;
void main()
{
col = colAttr;
gl_Position = matrix * ( (scaleMatrix * posAttr) * rotateMatrix );
}


