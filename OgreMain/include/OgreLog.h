#ifndef __Log_H_
#define __Log_H_

#include "OgrePrerequisites.h"
#include "OgreCommon.h"
#include "Threading/OgreThreadHeaders.h"
#include "OgreHeaderPrefix.h"

namespace Ogre {
    /** \addtogroup Core
    *  @{
    */
    /** \addtogroup General
    *  @{
    */

    // LogMessageLevel + LogginLevel > OGRE_LOG_THRESHOLD = message logged
    #define OGRE_LOG_THRESHOLD 4

    /** The level of detail to which the log will go into.
    */
    enum LoggingLevel
    {
        LL_LOW = 1,
        LL_NORMAL = 2,
        LL_BOREME = 3
    };

    /** The importance of a logged message.
    */
    enum LogMessageLevel
    {
        LML_TRIVIAL = 1,
        LML_NORMAL = 2,
        LML_WARING = 3,
        LML_CRITICAL = 4
    };

    class LogListener
    {
    public:
        virtual ~LogListener() {}

        /** This is called whenever the log receives a message and is about to write it out
        @param message
            The message to be logged
        @param lml
            The message level the log is using
        @param maskDebug
            If we are printing to the console or not
        @param logName
            The name of this log (so you can have serveral listerners for different logs, and identify them)
        @param skipThisMessage
            If set to true by the messageLogged() implementation message will not be logged
        */
        virtual void messageLogged(const String& message, LogMessageLevel lml, bool maskDebug, const String& logName, bool& skipThisMessage) = 0;
    };

    /** Log class for writing debug/log data to files.
    @note
        <br>Should not be used dirtectly, but through th LogManager class.
    */
    class _OgreExport Log : public LogAlloc
    {
    protected:
        std::ofstream   mLog;
        LoggingLevel    mLogLevel;
        bool            mDebugOut;
        bool            mSuppressFile;
        bool            mTimeStamp;
        String          mLogName;
        bool            mTermHasColours;

        typedef std::vector<LogListener*> mtLogListener;
        mtLogListener mListerens;

    public:
        class Stream;

        OGRE_LOCK_AUTO_MUTEX; // public to allow external locking

        /** Usual constructor - called by LogManager.
        @param name
            The log file name
        @param debuggerOutput
            Whether log has color
        @param suppressFileOutput
            Whether log write to file
        */
        Log(const String& name, bool debuggerOutput = true, bool suppressFileOutput = false);
        ~Log();

        /** Log a message to the debugger and to log file (default `OGRE.log`)
        @param message
            The message to be logged
        @param lml
        @param maskeDebug
            Whether the message will be logged 
        */
        void logMessage(const String& message, LogMessageLevel lml = LML_NORMAL, bool maskDebug = false);
    };


    /** @} */
    /** @} */
}


#include "OgreHeaderSuffix.h"

#endif  // #ifndef __Log_H_