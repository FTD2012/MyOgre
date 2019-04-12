#include "OgreStableHeaders.h"

namespace Ogre {
    const String& StringUtil::BLANK = BLANKSTRING;

    //-----------------------------------------------------------------------
    void StringUtil::trim(String& str, bool left, bool right)
    {
        static const String delims = " \t\r\n";
        if (right)
            str.erase(str.find_last_not_of(delims)+1); // trim right
        if (left)
            str.erase(0, str.find_first_not_of(delims)); // trim left
    }

    //-----------------------------------------------------------------------
    StringVector StringUtil::split(const String& str, const String& delims, unsigned int maxSplits, bool preserveDelims)
    {
        StringVector ret;
        ret.reserve(maxSplits ? maxSplits+1 : 10); // Pre-allocate some space for performance

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
                // Copy the rest of the string
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

    //-----------------------------------------------------------------------
    void StringUtil::toLowerCase(String& str)
    {
        std::transform(str.begin(), str.end(), str.begin(), tolower);
    }

    //-----------------------------------------------------------------------
    void StringUtil::toUpperCase(String& str)
    {
        std::transform(str.begin(), str.end(), str.begin(), toupper);
    }

    //-----------------------------------------------------------------------
    void StringUtil::toTitleCase(String& str)
    {
        String::iterator it = str.begin();
        (*it) = toupper(*it);
        for (; it != str.end() - 1; ++it)
        {
            if (*it == ' ')
            {
                *(it+1) = toupper(*(it+1));
            }
        }
    }

    //-----------------------------------------------------------------------
    bool StringUtil::startWith(const String& str, const String& pattern, bool lowerCase)
    {
        if (str.empty())
            return false;

        if (lowerCase)
            return strnicmp(str.c_str(), pattern.c_str(), pattern.size()) == 0;

        return strncmp(str.c_str(), pattern.c_str(), pattern.size()) == 0;
    }

    //-----------------------------------------------------------------------
    bool StringUtil::endWith(const String& str, const String& pattern, bool lowerCase)
    {
        if (str.empty())
            return false;
        
        size_t offset = str.size() - pattern.size();

        if (lowerCase)
            return strnicmp(str.c_str() + offset, pattern.c_str(), pattern.size()) == 0;

        return strncmp(str.c_str() + offset, pattern.c_str(), pattern.size()) == 0;
    }

    //-----------------------------------------------------------------------
    String StringUtil::standardisePath(const String& str)
    {
        String path = str;
        std::replace(path.begin(), path.end(), '\\', '/');
        if (path[path.length() - 1] != '/')
            path += '/';

        return path;
    }

    //-----------------------------------------------------------------------
    void StringUtil::splitFileName(const String& qualifiedName, String& outBasename, String& outPath)
    {
        String path = qualifiedName;
        std::replace(path.begin(), path.end(), '\\', '/');
        size_t i = path.find_last_of('/');

        if (i == String::npos)
        {
            outBasename = qualifiedName;
            outPath.clear();
        }
        else
        {
            outBasename = path.substr(i+1, path.size() - i - 1);
            outPath = path.substr(0, i+1);
        }
    }


    //-----------------------------------------------------------------------
    void StringUtil::splitBaseFileName(const String& fullName, String& outBasename, String& outExtention)
    {
        size_t i = fullName.find_last_of('.');
        if (i == String::npos)
        {
            outBasename = fullName;
            outExtention.clear();
        }
        else
        {
            outBasename = fullName.substr(i+1);
            outExtention = fullName.substr(0, i);
        }
    }

    //-----------------------------------------------------------------------
    String StringUtil::replaceAll(const String& source, const String& replaceWhat, const String& replaceWithWhat)
    {
        String result = source;
        String::size_type pos = 0;
        while(1)
        {
            pos = result.find_first_of(replaceWhat);
            if (pos == String::npos) break;
            result.replace(pos, replaceWithWhat.size(), replaceWithWhat);
            pos += replaceWithWhat.size();
        }
        return result;
    }


    //-----------------------------------------------------------------------

    

}