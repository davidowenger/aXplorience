#ifndef __NWrapper_H__
#define __NWrapper_H__

namespace NSNATIVE
{

class NWrapper
{
public:
    DBWrapper* mDBWrapper;
    GraphicsWrapper* mGraphicsWrapper;
    NKrossWrapper* mNKrossWrapper;
    OpWrapper* mOpWrapper;

    String mFileDir;
    String mAssetDir;
    AAssetManager* mAAssetManager;
};

} // END namespace

#endif
