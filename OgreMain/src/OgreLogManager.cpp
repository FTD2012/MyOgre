#include "OgreStableHeaders.h"

namespace Ogre
{
    //-----------------------------------------------------------------------
    template<> LogManager* Singleton<LogManager>::mSingleton = nullptr;
    LogManager* LogManager::getSingletonPtr()
    {
        return mSingleton;
    }
    LogManager& LogManager::getSingleton()
    {
        assert(mSingleton);
        return *mSingleton;
    }
    //-----------------------------------------------------------------------
    LogManager::LogManager()
    {
        mDefaultLog = nullptr;
    }

    //-----------------------------------------------------------------------
    LogManager::~LogManager()
    {
        OGRE_LOCK_AUTO_MUTEX;
        for (LogList::iterator i = mLogs.begin(); i != mLogs.end(); ++i)
        {
            OGRE_DELETE i->second;
        }
    }

    //-----------------------------------------------------------------------
    Log* LogManager::createLog(const String& name, bool defaultLog, bool debuggerOutput, bool suppressFileOutput)
    {
        OGRE_LOCK_AUTO_MUTEX;

        Log* newLog = OGRE_NEW Log(name, debuggerOutput, suppressFileOutput);

        if( !mDefaultLog || defaultLog )
        {
            mDefaultLog = newLog;
        }

        mLogs.insert( LogList::value_type( name, newLog ) );

        return newLog;
    }

    //-----------------------------------------------------------------------
    void LogManager::logMessage(const String& message, LogMessageLevel lml, bool maskDebug)
    {
        OGRE_LOCK_AUTO_MUTEX;
        if (mDefaultLog)
            mDefaultLog->logMessage(message, lml, maskDebug);
    }
}