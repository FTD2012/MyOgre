


#######################################################################
# Core dependencies
#######################################################################


# Find FreeType
find_package(Freetype)
macro_log_feature(FREETYPE_FOUND "freetype" "Portable font engine" "http://www.freetype.org" FALSE "" "")
