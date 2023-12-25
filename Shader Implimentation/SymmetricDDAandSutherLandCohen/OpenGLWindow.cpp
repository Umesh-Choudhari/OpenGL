#include "stdafx.h"
#include "OpenGLWindow.h"
#include "SutherlandandCohenAlgo.h"
#include "Line.h"

#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QOpenGLShaderProgram>
#include <QMatrix4x4>
#include <QPainter>


OpenGLWindow::OpenGLWindow(const QColor& background, QMainWindow* parent) :
    mBackground(background)
{
    setParent(parent);
    setMinimumSize(250, 250);

    const QStringList list = { "E:\\Ramesh__Workspace\\Qt\\SymmetricDDAandSutherLandCohen2\\SymmetricDDAandSutherLandCohen1\\SymmetricDDAandSutherLandCohen\\Vertex.glsl" ,"E:\\Ramesh__Workspace\\Qt\\SymmetricDDAandSutherLandCohen2\\SymmetricDDAandSutherLandCohen1\\SymmetricDDAandSutherLandCohen\\Fragment.glsl"};
    mVertexShaderWatcher = new QFileSystemWatcher(list,this);
    connect(mVertexShaderWatcher, &QFileSystemWatcher::fileChanged, this, &OpenGLWindow::shaderWatcher);

}

OpenGLWindow::~OpenGLWindow()
{
    reset();
}

void OpenGLWindow::reset()
{
    // And now release all OpenGL resources.
    makeCurrent();
    delete mProgram;
    mProgram = nullptr;
    delete mVshader;
    mVshader = nullptr;
    delete mFshader;
    mFshader = nullptr;
    mVbo.destroy();
    doneCurrent();
    QObject::disconnect(mContextWatchConnection);
}


void OpenGLWindow::setVectorOfLines(QVector<GLfloat>& vectorOfLines)
{
    verticesOfOrignalLine = vectorOfLines;
}

void OpenGLWindow::setColorOfLines(QVector<GLfloat>& colorOfLines)
{
    colorOfOrignalLine = colorOfLines;
}


void OpenGLWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    mProgram->bind();

    QMatrix4x4 matrix;
    QMatrix4x4 scaleMatrix;
    QMatrix4x4 rotateMatrix;
    QMatrix4x4 translateMatrix;

    rotateMatrix.rotate(mRotateFactor, 0, 0, 1);
    scaleMatrix.scale(mScaleFactorX, mScaleFactorY, 1.0f);
    translateMatrix.translate(mScaleFactorX, mScaleFactorY, 1.0f);

    matrix.ortho(-30.0f, 30.0f, -30.0f, 30.0f, 0.1f, 100.0f);
    matrix.translate(0, 0, -2);

    mProgram->setUniformValue("scaleMatrix", scaleMatrix);

    mProgram->setUniformValue("rotateMatrix", rotateMatrix);

    mProgram->setUniformValue("translateMatrix", translateMatrix);

    mProgram->setUniformValue("matrix", matrix);

    mProgram->setUniformValue("r", r);
    mProgram->setUniformValue("g", b);
    mProgram->setUniformValue("b", g);

    GLfloat* verticesData = verticesOfOrignalLine.data();
    GLfloat* colorsData = colorOfOrignalLine.data();

    if (mFlag == 1) {
        glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, verticesData);
        glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colorsData);

        glEnableVertexAttribArray(m_posAttr);
        glEnableVertexAttribArray(m_colAttr);

        glDrawArrays(GL_LINES, 0, verticesOfOrignalLine.size() / 3);
    }
    else {
        glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, verticesData);
        glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colorsData);

        glEnableVertexAttribArray(m_posAttr);
        glEnableVertexAttribArray(m_colAttr);

        glDrawArrays(GL_LINES, 0, verticesOfOrignalLine.size() / 2);
    }

    mProgram->release();
}


void OpenGLWindow::updateData(const QVector<GLfloat>& vertices, const QVector<GLfloat>& colors,int  flag)
{
    verticesOfOrignalLine = vertices;
    colorOfOrignalLine = colors;
    mFlag = flag;
    update();  // Schedule a repaint
}

QString OpenGLWindow::readShader(QString filepath)
{
    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly))
        return "";
    QTextStream stream(&file);
    QString line = stream.readLine();

    while (!stream.atEnd())
    {
        line.append(stream.readLine());
    }
    return line;
}

void OpenGLWindow::shaderWatcher()
{
    QString fragmentShaderSource = readShader("Fragment.glsl");
    QString vertexShaderSource = readShader("Vertex.glsl");

    mProgram->release();
    mProgram->removeAllShaders();

    mProgram = new QOpenGLShaderProgram(this);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    mProgram->link();
}

void OpenGLWindow::setSharingFactor(float& rotateFactor , float& scaleFactorX , float& scaleFactorY)
{
    mRotateFactor = rotateFactor;
    mScaleFactorX = scaleFactorX;
    mScaleFactorY = scaleFactorY;
    update();
}
void OpenGLWindow::setTranslateFactor(float& translateFactorX, float& translateFactorY)
{
    mTranslateFactorX = translateFactorX;
    mTranslateFactorY = translateFactorY;
    update();
}

void OpenGLWindow::setColorFactor(float& r1, float& g1, float& b1)
{
    r = r1;
    b = g1;
    g = b1;
    update();
}

void OpenGLWindow::initializeGL()
{
    QString fragmentShaderSource = readShader("Fragment.glsl");
    QString vertexShaderSource = readShader("Vertex.glsl");

    initializeOpenGLFunctions();

    mProgram = new QOpenGLShaderProgram(this);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);

    mProgram->link();

    m_posAttr = mProgram->attributeLocation("posAttr");

    m_colAttr = mProgram->attributeLocation("colAttr");

    m_matrixUniform = mProgram->uniformLocation("matrix");

    m_scaleMatrix = mProgram->uniformLocation("scaleMatrix");

    if (m_posAttr == -1 || m_colAttr == -1 || m_scaleMatrix == -1 || m_matrixUniform == -1)
    {
        qDebug() << "Shader attribute or uniform location error.";
        // Handle the error appropriately, e.g., return or throw an exception
    }
}

