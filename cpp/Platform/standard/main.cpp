#include "precompile/precompiled.h"
#include "HorizonLog.h"
#include "HorizonCore.h"
int main()
{
    horizon::HorizonCore::GetInstance()->init();
    //horizon::HorizonCore::GetInstance()->setLogEnable(false);
    HORIZON_INFO << "TEST" << "\n" << "test2";
    //horizon::log::HORIZON_DEBUG_F << "test";
     
    // startGUIViewFSM();
    return 0;
}