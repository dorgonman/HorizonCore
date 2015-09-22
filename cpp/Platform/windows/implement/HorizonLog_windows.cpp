#include "precompile/precompiled.h"
#include "HorizonLog.h"
#include <Windows.h> 
#include <tchar.h> 

namespace horizon{
    void logMessageImplementInternal(const std::string& msg){
        WCHAR wszBuf[HORIZON_LOG_MAX_LEN] = { 0 };
        MultiByteToWideChar(CP_UTF8, 0, msg.c_str(), -1, wszBuf, sizeof(wszBuf));
        OutputDebugStringW(wszBuf);
    }

    void LogBasicBackend::logMessageImplement(const std::string& msg){


        logMessageImplementInternal(msg);


    }

    void LogBasicFormatedBackend::logMessageImplement(const std::string& msg){
        logMessageImplementInternal(msg);
    }

 


}//namespace horizon