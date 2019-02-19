#ifndef __GraphicsProgram_H__
#define __GraphicsProgram_H__

namespace NSNATIVE
{

class GraphicsParam
{
public:
    GraphicsParam(nint vID, nuint vDataCount);
    virtual ~GraphicsParam();

    void is(nfloat v0);
    void is(nfloat v0, nfloat v1);
    void is(nfloat v0, nfloat v1, nfloat v2);
    void is(nfloat v0, nfloat v1, nfloat v2, nfloat v3);
    void is1(nfloat* vaData);
    void is2(nfloat* vaData);
    void is3(nfloat* vaData);
    void is4(nfloat* vaData);
    void is1(NVec<nfloat> vNVec);
    void is2(NVec<nfloat> vNVec);
    void is3(NVec<nfloat> vNVec);
    void is4(NVec<nfloat> vNVec);

    virtual void is(GraphicsParam* vGraphicsParam) = 0;
    virtual void use() = 0;

    nint mID;
    NVec<nfloat> mNVec;
};

class GraphicsParamBuf : public GraphicsParam
{
public:
    GraphicsParamBuf(nint vID, GraphicsBuffer* vGraphicsBuffer, nuint vParamSize, nuint vDataOffset);
    virtual ~GraphicsParamBuf();

    virtual void is(GraphicsParam* vGraphicsParam);
    virtual void use();

    nuint mParamSize;
    nuint mParamOffset;
    GraphicsBuffer* mGraphicsBuffer;
};

class GraphicsParamTex : public GraphicsParam
{
public:
    GraphicsParamTex(nint vID, GraphicsTexture* vGraphicsTexture);
    virtual ~GraphicsParamTex();

    virtual void is(GraphicsParam* vGraphicsParam);
    virtual void use();

    nuint mTextureID;
    nuint mTextureTarget;
    GraphicsTexture* mGraphicsTexture;
};

class GraphicsParamVec1 : public GraphicsParam
{
public:
    GraphicsParamVec1(nint vID, NArray<nfloat> vValueArray);
    virtual ~GraphicsParamVec1();

    virtual void is(GraphicsParam* vGraphicsParam);
    virtual void use();
};

class GraphicsParamVec2 : public GraphicsParam
{
public:
    GraphicsParamVec2(nint vID, NArray<nfloat> vValueArray);
    virtual ~GraphicsParamVec2();

    virtual void is(GraphicsParam* vGraphicsParam);
    virtual void use();
};

class GraphicsParamVec3 : public GraphicsParam
{
public:
    GraphicsParamVec3(nint vID, NArray<nfloat> vValueArray);
    virtual ~GraphicsParamVec3();

    virtual void is(GraphicsParam* vGraphicsParam);
    virtual void use();
};

class GraphicsParamVec4 : public GraphicsParam
{
public:
    GraphicsParamVec4(nint vID, NArray<nfloat> vValueArray);
    virtual ~GraphicsParamVec4();

    virtual void is(GraphicsParam* vGraphicsParam);
    virtual void use();
};

class GraphicsProgram
{
public:
    GraphicsProgram(NWrapper* vNWrapper, NArray<String> vaShader, nuint vIndiceCount, nuint vFirstIndice);
   ~GraphicsProgram();

    GraphicsParam* createParam(const String&, GraphicsBuffer* vGraphicsBuffer, nuint vParamSize);
    GraphicsParam* createParam(const String&, NArray<nfloat> vValueArray);
    GraphicsParam* createParam(const String&, GraphicsTexture* vGraphicsTexture);
    void draw();
    void use();

    nuint mID;
    nuint mParamOffset;
    nuint mIndiceCount;
    nuint mFirstIndice;
    NWrapper* mNWrapper;
    GraphicsBuffer* mGraphicsBuffer;
    NArray<String> maShader;
};

} // End namespace

#endif
