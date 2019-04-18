#ifndef __LogManager_H_
#define __LogManager_H_

#include "OgrePrerequisites.h"
#include "OgreLog.h"
#include "OgreSingleton.h"
#include "OgreHeaderPrefix.h"

namespace Ogre {
    /** \addtogroup Core
    *  @{
    */
    /** \addtogroup General
    *  @{
    */
    class _OgreExport LogManager : public Singleton<LogManager>, public LogAlloc
    {
    protected:
        typedef std::map<String, Log*> LogList;
        /// A list of all the logs the manager can access
        LogList mLogs;
        /// The default log to which output is done
        Log* mDefaultLog;

    public:
        LogManager();
        ~LogManager();

        /** Creates a new log with the given name.
            @param name 
                The name to give the log e.g. 'Ogre.log'
            @param defaultLog
                If true, this is the default log output will be
                sent to if the generic logging methods on this class are
                used. The first log created is always the default log unless
                this parameter is set.
            @param debuggerOutput
                If true, output to this log will also be
                routed to the debugger's output window.
            @param suppressFileOutput
                If true, this is a logical rather than a physical
                log and no file output will be written. If you do this you should
                register a LogListener so log output is not lost.
        */
        Log* createLog(const String& name, bool defaultLog = false, bool debuggerOutput = true, bool suppressFileOutput = false);

        void logMessage(const String& message, LogMessageLevel lml = LML_NORMAL, bool maskDebug = false);

        static LogManager& getSingleton();
        static LogManager* getSingletonPtr();
    };
    /** @} */
    /** @} */
}

#include "OgreHeaderSuffix.h"

#endif // #ifndef __LogManager_H_