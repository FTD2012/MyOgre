#include "OgreStableHeaders.h"

namespace Ogre {
    const String& StringUtil::BLANK = BLANKSTRING;

    void StringUtil::trim(String& str, bool left, bool right)
    {
        static const String delims = " \t\r\n";
        if (right) 
            str.erase(str.find_last_not_of(delims)+1); // trim right
        if (left)
            str.erase(0, str.find_first_not_of(delims)); // trim left
    }

    StringVector StringUtil::split(const String& str, const String& delims, unsigned int maxSplits, bool preserveDelims)
    {
        StringVector ret;
        ret.reserve(maxSplits ? maxSplits+1 : 10); // Pre-allocate some space for performanc

        size_t start = 0, pos;
        unsigned int numSplits = 0;

        do {
            pos = str.find_first_of(delims, start);
            if (pos == start) 
            {
                // Do nothing
                start = pos + 1;
            }
            else if (pos == String::npos || (maxSplits && numSplits == maxSplits))
            {
                // Copy the rest fo the string
                ret.push_back(str.substr(start));
            }
            else
            {
                // Copy to the delimiter
                ret.push_back(str.substr(start, pos - start));

                if (preserveDelims)
                {
                    size_t delimStart = pos, delimPos;
                    delimPos = str.find_first_not_of(delims, delimStart);
                    if (delimPos == String::npos)
                    {
                        // Copy the rest of the string
                        ret.push_back(str.substr(delimStart));
                    }
                    else
                    {
                        ret.push_back(str.substr(delimStart, delimPos - delimStart));
                    }
                }

                start = pos + 1;
            }
            // parse up to next real data
            start = str.find_first_not_of(delims, start);
            ++numSplits;

        } while (pos != String::npos);

        return ret;
    }

    

}