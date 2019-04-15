macro(MACRO_LOG_FEATURE _var _package _description _url ) # _required _minvers _comments)

    set(_required "${ARGV4}")
    set(_minvers "${ARGV5}")
    set(_comments "${ARGV6}")

    if (${_var})
        set(_LOGFILENAME ${PROJECT_BINARY_DIR}/EnabledFeatures.txt)
    else (${_var})
        if (${_required} MATCHES "[Tt][Rr][Uu][Ee]")
            set(_LOGFILENAME ${PROJECT_BINARY_DIR}/MissingRequirements.txt)
        else (${_required} MATCHES "[Tt][Rr][Uu][Ee]")
            set(_LOGFILENAME ${PROJECT_BINARY_DIR}/DisabledFeatures.txt)
        endif (${_required} MATCHES "[Tt][Rr][Uu][Ee]")
    endif (${_var})

    set(_logtext "+ ${_package}")

    if (NOT ${_var})
        if (${_minvers} MATCHES ".*")
            set(_logtext "${_logtext}, ${_minvers}")
        endif (${_minvers} MATCHES ".*")
        set(_logtext "${_logtext}: ${_description} <${_url}>")
        if (${_comments} MATCHES ".*")
            set(_logtext "${_logtext}\n${_comments}")
        endif (${_comments} MATCHES ".*")
        # set(_logtext "${_logtext}\n") #double-space missing features?
    endif (NOT ${_var})
    
    file(APPEND "${_LOGFILENAME}" "${_logtext}\n")
    message("${_logtext}")
endmacro(MACRO_LOG_FEATURE)