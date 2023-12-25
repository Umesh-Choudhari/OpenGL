#pragma once
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>

class QOpenGLTexture;
class QOpenGLShader;
class QOpenGLShaderProgram;
class QOpenGLPaintDevice;


    class OpenGLWindow :public QOpenGLWidget, protected QOpenGLFunctions
    {
        Q_OBJECT
    public:
        OpenGLWindow(const QColor& background, QMainWindow* parent);
        ~OpenGLWindow();

        void setVectorOfLines(QVector<GLfloat>& vectorOfLines);
        void setColorOfLines(QVector<GLfloat>& colorOfLines);
        void updateData(const QVector<GLfloat>& vertices, const QVector<GLfloat>& colors, int flag=0);
        void setSharingFactor(float& rotateFactor , float& scaleFactorX, float& scaleFactorY);
        void setColorFactor(float& r, float& g, float& b);
        void setTranslateFactor(float& translateFactorX, float& translateFactorY);

    protected:
        void paintGL() override;
        void initializeGL() override;

    private:
        void reset();
        QString readShader(QString path);
        

    private slots:
        void shaderWatcher();

    private:
        bool mAnimating = false;
        int mFlag;
        QOpenGLContext* mContext = nullptr;
        QOpenGLPaintDevice* mDevice = nullptr;

        QOpenGLShader* mVshader = nullptr;
        QOpenGLShader* mFshader = nullptr;
        QOpenGLShaderProgram* mProgram = nullptr;

        QList<QVector3D> mVertices;
        QList<QVector3D> mNormals;
        QOpenGLBuffer mVbo;
        int mVertexAttr;
        int mNormalAttr;
        int mMatrixUniform;
        QColor mBackground;
        QMetaObject::Connection mContextWatchConnection;


        QVector<GLfloat> verticesOfOrignalLine;
        QVector<GLfloat> colorOfOrignalLine;

        GLint m_posAttr = 0;
        GLint m_colAttr = 0;
        GLint m_posAttr1 = 0;
        GLint m_colAttr1 = 0;
        GLint m_matrixUniform = 0;
        GLint m_translationMatrix = 0;
        GLfloat m_tX = 0;
        GLfloat m_tY = 0;
        GLfloat m_tZ = 0;
        GLfloat r=1;
        GLfloat b=1;
        GLfloat g=1;
        GLfloat m_scaleMatrix = 0;
        GLfloat m_rotateMatrix = 0;
        GLfloat m_translateMatrix = 0;
        GLfloat mRotateFactor = 0;
        GLfloat mScaleFactorX = 0;
        GLfloat mScaleFactorY = 0;
        GLfloat mTranslateFactorX = 0;
        GLfloat mTranslateFactorY = 0;

        GLint rotationAngle;
        QPoint lastPos;

        QFileSystemWatcher* mVertexShaderWatcher;
    };



