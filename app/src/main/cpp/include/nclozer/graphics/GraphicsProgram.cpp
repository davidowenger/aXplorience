#include "GraphicsCommon.h"

namespace NSNATIVE
{

GraphicsParam::GraphicsParam(nint vID, nuint vDataCount) :
    mID(vID), mNVec(vDataCount)
{
}

GraphicsParam::~GraphicsParam()
{
}
void GraphicsParam::is(nfloat v0)
{
    mNVec.is(v0);
    use();
}

void GraphicsParam::is(nfloat v0, nfloat v1)
{
    mNVec.is(v0, v1);
    use();
}

void GraphicsParam::is(nfloat v0, nfloat v1, nfloat v2)
{
    mNVec.is(v0, v1, v2);
    use();
}

void GraphicsParam::is(nfloat v0, nfloat v1, nfloat v2, nfloat v3)
{
    mNVec.is(v0, v1, v2, v3);
    use();
}

void GraphicsParam::is1(nfloat* vaData)
{
    mNVec.is1(vaData);
    use();
}

void GraphicsParam::is2(nfloat* vaData)
{
    mNVec.is2(vaData);
    use();
}

void GraphicsParam::is3(nfloat* vaData)
{
    mNVec.is3(vaData);
    use();
}

void GraphicsParam::is4(nfloat* vaData)
{
    mNVec.is4(vaData);
    use();
}

void GraphicsParam::is1(NVec<nfloat> vNVec)
{
    mNVec.is1(vNVec);
    use();
}

void GraphicsParam::is2(NVec<nfloat> vNVec)
{
    mNVec.is2(vNVec);
    use();
}

void GraphicsParam::is3(NVec<nfloat> vNVec)
{
    mNVec.is3(vNVec);
    use();
}

void GraphicsParam::is4(NVec<nfloat> vNVec)
{
    mNVec.is4(vNVec);
    use();
}

GraphicsParamBuf::GraphicsParamBuf(nint vID, GraphicsBuffer* vGraphicsBuffer, nuint vParamSize, nuint vParamOffset) :
    GraphicsParam(vID, 1), mParamSize(vParamSize), mParamOffset(vParamOffset), mGraphicsBuffer(vGraphicsBuffer)
{
    // TODO: enable multiple buffers
    glEnableVertexAttribArray(mID);
    glVertexAttribPointer(mID, mParamSize, GL_FLOAT, GL_FALSE, mGraphicsBuffer->mRowSize*sizeof(GLfloat), (GLvoid*)(mParamOffset*sizeof(GLfloat)));
}

GraphicsParamBuf::~GraphicsParamBuf()
{
}

void GraphicsParamBuf::is(GraphicsParam* vGraphicsParam)
{
}

void GraphicsParamBuf::use()
{
}

GraphicsParamTex::GraphicsParamTex(nint vID, GraphicsTexture* vGraphicsTexture)
    : GraphicsParam(vID, 1), mGraphicsTexture(vGraphicsTexture)
{
    mTextureID = mGraphicsTexture->mID;
    mTextureTarget = mGraphicsTexture->mTarget;
    mNVec.is((nfloat)mGraphicsTexture->mTextureUnit);
    use();
    glUniform1i(mID, (nint)mNVec.d[0]);
}

GraphicsParamTex::~GraphicsParamTex()
{
}

void GraphicsParamTex::is(GraphicsParam* vGraphicsParam)
{
    mGraphicsTexture = ((GraphicsParamTex*)vGraphicsParam)->mGraphicsTexture;
    mTextureID = mGraphicsTexture->mID;
    mTextureTarget = mGraphicsTexture->mTarget;
    mNVec.is1(vGraphicsParam->mNVec);
    glActiveTexture(GraphicsTexture::kTextureUnitBase + mNVec.d[0]);
    glBindTexture(mTextureTarget, mTextureID);
    glUniform1i(mID, (nint)mNVec.d[0]);
}

void GraphicsParamTex::use()
{
    glActiveTexture(GraphicsTexture::kTextureUnitBase + mNVec.d[0]);
    glBindTexture(mTextureTarget, mTextureID);
    glUniform1i(mID, (nint)mNVec.d[0]);
}

GraphicsParamVec1::GraphicsParamVec1(nint vID, NArray<nfloat> vValueArray) :
    GraphicsParam(vID, vValueArray.mcData)
{
    is1(vValueArray.maData);
}

GraphicsParamVec1::~GraphicsParamVec1()
{
}

void GraphicsParamVec1::is(GraphicsParam* vGraphicsParam)
{
    mNVec.is1(vGraphicsParam->mNVec);
    glUniform1fv(mID, 1, mNVec.d);
}

void GraphicsParamVec1::use()
{
    glUniform1fv(mID, 1, mNVec.d);
}

GraphicsParamVec2::GraphicsParamVec2(nint vID, NArray<nfloat> vValueArray) :
    GraphicsParam(vID, vValueArray.mcData)
{
    is2(vValueArray.maData);
}

GraphicsParamVec2::~GraphicsParamVec2()
{
}

void GraphicsParamVec2::is(GraphicsParam* vGraphicsParam)
{
    mNVec.is2(vGraphicsParam->mNVec);
    glUniform2fv(mID, 1, mNVec.d);
}

void GraphicsParamVec2::use()
{
    glUniform2fv(mID, 1, mNVec.d);
}

GraphicsParamVec3::GraphicsParamVec3(nint vID, NArray<nfloat> vValueArray) :
    GraphicsParam(vID, vValueArray.mcData)
{
    is3(vValueArray.maData);
}

GraphicsParamVec3::~GraphicsParamVec3()
{
}

void GraphicsParamVec3::is(GraphicsParam* vGraphicsParam)
{
    mNVec.is3(vGraphicsParam->mNVec);
    glUniform3fv(mID, 1, mNVec.d);
}

void GraphicsParamVec3::use()
{
    glUniform3fv(mID, 1, mNVec.d);
}

GraphicsParamVec4::GraphicsParamVec4(nint vID, NArray<nfloat> vValueArray) :
    GraphicsParam(vID, vValueArray.mcData)
{
    is4(vValueArray.maData);
}

GraphicsParamVec4::~GraphicsParamVec4()
{
}

void GraphicsParamVec4::is(GraphicsParam* vGraphicsParam)
{
    mNVec.is4(vGraphicsParam->mNVec);
    glUniform4fv(mID, 1, mNVec.d);
}

void GraphicsParamVec4::use()
{
    glUniform4fv(mID, 1, mNVec.d);
}

GraphicsProgram::GraphicsProgram(NWrapper* vNWrapper, NArray<String> vaShader, nuint vIndiceCount, nuint vFirstIndice) :
    mID(0), mParamOffset(0), mIndiceCount(vIndiceCount), mFirstIndice(vFirstIndice), mNWrapper(vNWrapper), mGraphicsBuffer(nullptr), maShader(vaShader)
{
    mID = mNWrapper->mGraphicsWrapper->mGraphicsHandler->loadProgramAsset(vaShader.maData[0], vaShader.maData[1]);
    use();

    if (!mID) {
        SLOGE("Graphics program could not be created: " + vaShader.maData[0] + '/' + vaShader.maData[1]);
    }
}

GraphicsProgram::~GraphicsProgram()
{
}

GraphicsParam* GraphicsProgram::createParam(const String& vName, GraphicsBuffer* vGraphicsBuffer, nuint vParamSize)
{
    nint vID = glGetAttribLocation(mID, vName.c_str());
    GraphicsParam* vGraphicsParam = new GraphicsParamBuf(vID, vGraphicsBuffer, vParamSize, mParamOffset);
    mGraphicsBuffer = vGraphicsBuffer;
    mParamOffset += vParamSize;

    if (vID == -1) {
        SLOGE("Graphics program param not found: " + vName);
    }
    return vGraphicsParam;
}

GraphicsParam* GraphicsProgram::createParam(const String& vName, NArray<nfloat> vValueArray)
{
    nint vID = glGetUniformLocation(mID, vName.c_str());
    GraphicsParam* vGraphicsParam = nullptr;

    switch (vValueArray.mcData) {
    case 1:
        vGraphicsParam = new GraphicsParamVec1(vID, vValueArray);
        break;
    case 2:
        vGraphicsParam = new GraphicsParamVec2(vID, vValueArray);
        break;
    case 3:
        vGraphicsParam = new GraphicsParamVec3(vID, vValueArray);
        break;
    case 4:
        vGraphicsParam = new GraphicsParamVec4(vID, vValueArray);
        break;
    }
    if (!vGraphicsParam) {
        SLOGE("Graphics program param could not be created : " + vName);
    }
    if (vID == -1) {
        SLOGE("Graphics program param not found: " + vName);
    }
    return vGraphicsParam;
}

GraphicsParam* GraphicsProgram::createParam(const String& vName, GraphicsTexture* vGraphicsTexture)
{
    nint vID = glGetUniformLocation(mID, vName.c_str());
    GraphicsParam* vGraphicsParam = new GraphicsParamTex(vID, vGraphicsTexture);

    if (vID == -1) {
        SLOGE("Graphics program param not found: " + vName);
    }
    return vGraphicsParam;
}

void GraphicsProgram::draw()
{
    glDrawElements(GL_TRIANGLES, mIndiceCount, GL_UNSIGNED_SHORT, (GLvoid*)(mFirstIndice*sizeof(GLushort)));
}

void GraphicsProgram::use()
{
    glUseProgram(mID);
}

} // End namespace
