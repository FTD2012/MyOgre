#include "OgreStableHeaders.h"

#include <iostream>

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32 || OGRE_PLATFORM == OGRE_PLATFORM_WINRT
#   include <windows.h>
#   if _WIN32_WINNT >= _WIN32_WINNT_VISTA
#       include <werapi.h>
#   endif
#endif

namespace {
    const char* RED = "\x1b[31;1m";
    const char* YELLOW = "\x1b[33;1m";
    const char* RESET = "\x1b[0m";
}

namespace Ogre {
    //-----------------------------------------------------------------------
    Log::Log(const String& name, bool debuggerOutput, bool suppressFile)
    : mLogLevel(LL_NORMAL)
    , mDebugOut(debuggerOutput)
    , mSuppressFile(suppressFile)
    , mTimeStamp(true)
    , mLogName(name)
    , mTermHasColours(false)
    {
        if (!mSuppressFile)
        {
            mLog.open(name.c_str());
#if (OGRE_PLATFORM == OGRE_PLATFORM_WIN32 || OGRE_PLATFORM == OGRE_PLATFORM_WINRT) && _WIN32_WINNT >= _WIN32_WINNT_VISTA
            // Register log file to be collected by Windows Error Reporting
            const int utf16Length = ::MultiByteToWideChar(CP_ACP, 0, name.c_str(), (int)name.size(), NULL, 0);
            if(utf16Length > 0)
            {
                std::wstring wname;
                wname.resize(utf16Length);
                if (0 != ::MultiByteToWideChar(CP_ACP, 0, name.c_str(), (int)name.size(), &wname[0], (int)wname.size()))
                    WerRegisterFile(wname.c_str(), WerRegFileTypeOther, WER_FILE_ANONYMOUS_DATA);
            }
#endif
        }

#if OGRE_PLATFORM != OGRE_PLATFORM_WINRT
        if(mDebugOut)
        {
            char* val = getenv("TERM");
            mTermHasColours = val && String(val).find("xterm") != String::npos;
        }
#endif
    }

    //-----------------------------------------------------------------------
    Log::~Log()
    {
        OGRE_LOCK_AUTO_MUTEX;
        if (!mSuppressFile)
            mLog.close();
    }

    //-----------------------------------------------------------------------
    void Log::logMessage(const String& message, LogMessageLevel lml, bool maskDebug)
    {
        OGRE_LOCK_AUTO_MUTEX;
        if ((mLogLevel + lml) >= OGRE_LOG_THRESHOLD)
        {
            bool skipThisMessage = false;
            for (mtLogListener::iterator i = mListerens.begin(); i != mListerens.end(); ++i)
                (*i)->messageLogged(message, lml, maskDebug, mLogName, skipThisMessage);
            
            if (!skipThisMessage)
            {
                if (mDebugOut && !maskDebug)
                {
#    if (OGRE_PLATFORM == OGRE_PLATFORM_WIN32 || OGRE_PLATFORM == OGRE_PLATFORM_WINRT) && OGRE_DEBUG_MODE
                    OutputDebugStringA("Ogre: ");
                    OutputDebugStringA(message.c_str());
                    OutputDebugStringA("\n");
#    endif
                    std::ostream& os = int(lml) >= int(LML_WARING) ? std::cerr : std::cout;

                    if (mTermHasColours)
                    {
                        if (lml == LML_WARING)
                            os << YELLOW;
                        if (lml == LML_CRITICAL)
                            os << RED;
                    }

                    os << message;

                    if (mTermHasColours)
                    {
                        os << RESET;
                    }

                    os << std::endl;
                }

                // Write time into log
                if (!mSuppressFile)
                {
                    if (mTimeStamp)
                    {
                        struct tm* pTime;
                        time_t ctTime;
                        time(&ctTime);
                        pTime = localtime(&ctTime);
                        mLog << std::setw(2) << std::setfill('0') << pTime->tm_hour
                            << ":" << std::setw(2) << std::setfill('0') << pTime->tm_min
                            << ":" << std::setw(2) << std::setfill('0') << pTime->tm_sec
                            << ": ";
                    }
                    mLog << message << std::endl;

                    // Flush stcmdream to ensure it is wirtten (in case of crash, we need log to be up to date)
                    mLog.flush();
                }
            }
        }
    }

}