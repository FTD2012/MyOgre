
# default build output paths
if (NOT OGRE_ARCHIVE_OUTPUT)
    if (APPLE AND NOT OGRE_BUILD_PLATFORM_ANDROID)
        set(OGRE_ARCHIVE_OUTPUT ${PROJECT_BINARY_DIR}/lib/${PLATFORM_NAME})
    else ()
        set(OGRE_ARCHIVE_OUTPUT ${PROJECT_BINARY_DIR}/lib)
    endif ()
endif ()

if (NOT OGRE_LIBRARY_OUTPUT)
    if (APPLE AND NOT OGRE_BUILD_PLATFORM_ANDROID)
        set(OGRE_LIBRARY_OUTPUT ${PROJECT_BINARY_DIR}/lib/${PLATFORM_NAME})
    else ()
        set(OGRE_LIBRARY_OUTPUT ${PROJECT_BINARY_DIR}/lib)
    endif ()
endif ()

if (NOT OGRE_RUNTIME_OUPUT)
    set(OGRE_RUNTIME_OUPUT ${PROJECT_BINARY_DIR}/lib)
endif ()


# create vcproj.user file for Visual Studio to set debug working directory
function(ogre_create_vcproj_userfile TARGETNAME)
### TODO: ljm >>> implemation
endfunction(ogre_create_vcproj_userfile)

# install targets according to current build type
function(ogre_install_target TARGETNAME SUFFIX EXPORT)
	# Skip all install targets in SDK
	if (OGRE_SDK_BUILD)
		return()
	endif()

	if(EXPORT)
	    install(TARGETS ${TARGETNAME} EXPORT OgreTargetsRelease
		    CONFIGURATIONS Release None ""
		    BUNDLE DESTINATION "bin${OGRE_RELEASE_PATH}"
		    RUNTIME DESTINATION "bin${OGRE_RELEASE_PATH}"
		    LIBRARY DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_LIB_RELEASE_PATH}${SUFFIX}"
		    ARCHIVE DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_LIB_RELEASE_PATH}${SUFFIX}"
		    FRAMEWORK DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_RELEASE_PATH}/Release")
	    install(TARGETS ${TARGETNAME} EXPORT OgreTargetsRelWithDebInfo
		    CONFIGURATIONS RelWithDebInfo
		    BUNDLE DESTINATION "bin${OGRE_RELWDBG_PATH}"
		    RUNTIME DESTINATION "bin${OGRE_RELWDBG_PATH}"
		    LIBRARY DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_LIB_RELWDBG_PATH}${SUFFIX}"
		    ARCHIVE DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_LIB_RELWDBG_PATH}${SUFFIX}"
		    FRAMEWORK DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_RELWDBG_PATH}/RelWithDebInfo")
	    install(TARGETS ${TARGETNAME} EXPORT OgreTargetsMinSizeRel
		    CONFIGURATIONS MinSizeRel
		    BUNDLE DESTINATION "bin${OGRE_MINSIZE_PATH}"
		    RUNTIME DESTINATION "bin${OGRE_MINSIZE_PATH}"
		    LIBRARY DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_LIB_MINSIZE_PATH}${SUFFIX}"
		    ARCHIVE DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_LIB_MINSIZE_PATH}${SUFFIX}"
		    FRAMEWORK DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_MINSIZE_PATH}/MinSizeRel")
	    install(TARGETS ${TARGETNAME} EXPORT OgreTargetsDebug
		    CONFIGURATIONS Debug
		    BUNDLE DESTINATION "bin${OGRE_DEBUG_PATH}"
		    RUNTIME DESTINATION "bin${OGRE_DEBUG_PATH}"
		    LIBRARY DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_LIB_DEBUG_PATH}${SUFFIX}"
		    ARCHIVE DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_LIB_DEBUG_PATH}${SUFFIX}"
		    FRAMEWORK DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_DEBUG_PATH}/Debug")
	else()
	    install(TARGETS ${TARGETNAME}
	    	CONFIGURATIONS Release None ""
	    	BUNDLE DESTINATION "bin${OGRE_RELEASE_PATH}" 
	    	RUNTIME DESTINATION "bin${OGRE_RELEASE_PATH}"
	    	LIBRARY DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_LIB_RELEASE_PATH}${SUFFIX}"
	    	ARCHIVE DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_LIB_RELEASE_PATH}${SUFFIX}"
	    	FRAMEWORK DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_RELEASE_PATH}/Release")
	    install(TARGETS ${TARGETNAME}
	    	CONFIGURATIONS RelWithDebInfo
	    	BUNDLE DESTINATION "bin${OGRE_RELWDBG_PATH}"
	    	RUNTIME DESTINATION "bin${OGRE_RELWDBG_PATH}"
	    	LIBRARY DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_LIB_RELWDBG_PATH}${SUFFIX}"
	    	ARCHIVE DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_LIB_RELWDBG_PATH}${SUFFIX}"
	    	FRAMEWORK DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_RELWDBG_PATH}/RelWithDebInfo")
	    install(TARGETS ${TARGETNAME}
	    	CONFIGURATIONS MinSizeRel
	    	BUNDLE DESTINATION "bin${OGRE_MINSIZE_PATH}"
	    	RUNTIME DESTINATION "bin${OGRE_MINSIZE_PATH}"
	    	LIBRARY DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_LIB_MINSIZE_PATH}${SUFFIX}"
	    	ARCHIVE DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_LIB_MINSIZE_PATH}${SUFFIX}"
	    	FRAMEWORK DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_MINSIZE_PATH}/MinSizeRel")
	    install(TARGETS ${TARGETNAME}
	    	CONFIGURATIONS Debug
	    	BUNDLE DESTINATION "bin${OGRE_DEBUG_PATH}"
	    	RUNTIME DESTINATION "bin${OGRE_DEBUG_PATH}"
	    	LIBRARY DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_LIB_DEBUG_PATH}${SUFFIX}"
	    	ARCHIVE DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_LIB_DEBUG_PATH}${SUFFIX}"
	    	FRAMEWORK DESTINATION "${OGRE_LIB_DIRECTORY}${OGRE_DEBUG_PATH}/Debug")
	endif()
endfunction(ogre_install_target)

# setup common target settings
function(ogre_config_common TARGETNAME)
    set_target_properties(${TARGETNAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${OGRE_ARCHIVE_OUTPUT}
        LIBRARY_OUTPUT_DIRECTORY ${OGRE_LIBRARY_OUTPUT}
        RUNTIME_OUTPUT_DIRECTORY ${OGRE_RUNTIME_OUPUT}
    )
    if(APPLE_IOS)
        set_target_properties(${TARGETNAME} PROPERTIES XCODE_ATTRIBUTE_GCC_THUMB_SUPPORT "NO")
        set_target_properties(${TARGETNAME} PROPERTIES XCODE_ATTRIBUTE_GCC_UNROLL_LOOPS "YES")
        set_target_properties(${TARGETNAME} PROPERTIES XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "iPhone Developer")
        set_target_properties(${TARGETNAME} PROPERTIES XCODE_ATTRIBUTE_GCC_PRECOMPILE_PREFIX_HEADER "YES")
        set_target_properties(${TARGETNAME} PROPERTIES XCODE_ATTRIBUTE_DEBUG_INFORMATION_FORMAT "dwarf$<$<NOT:$<CONFIG:Debug>>:-with-dsym>")
    endif(APPLE_IOS)

    if(NOT OGRE_STATIC AND (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
        set_target_properties(${TARGETNAME} PROPERTIES XCODE_ATTRIBUTE_ONLY_ACTIVE_ARCH "NO")
    endif()
    
    ogre_create_vcproj_userfile(${TARGETNAME})
endfunction(ogre_config_common)




# setup library build
function(ogre_config_lib LIBNAME EXPORT)
    ogre_config_common(${LIBNAME})
    if (OGRE_STATIC)
        # add static prefix, if compiling static version
        set_target_properties(${LIBNAME} PROPERTIES OUTPUT_NAME ${LIBNAME}Static)
    else (OGRE_STATIC)
        if (MINGW)
            # remove lib prefix from DLL outputs
            set_target_properties(${LIBNAME} PROPERTIES PREFIX "")
        endif ()
    endif ()
    ogre_install_target(${LIBNAME} "" ${EXPORT})

    if (OGRE_INSTALL_PDB)
        # install debug pdb files
        if (OGRE_STATIC)
	        install(FILES ${PROJECT_BINARY_DIR}/lib${OGRE_LIB_DEBUG_PATH}/${LIBNAME}Static_d.pdb
	            DESTINATION ${OGRE_LIB_DIRECTORY}${OGRE_LIB_DEBUG_PATH}
		        CONFIGURATIONS Debug
	        )
	        install(FILES ${PROJECT_BINARY_DIR}/lib${OGRE_LIB_RELWDBG_PATH}/${LIBNAME}Static.pdb
	            DESTINATION ${OGRE_LIB_DIRECTORY}${OGRE_LIB_RELWDBG_PATH}
		        CONFIGURATIONS RelWithDebInfo
	        )
	    else ()
            ogre_produces_pdb(PRODUCES_PDB ${LIBNAME})
            if (PRODUCES_PDB)
	            install(FILES $<TARGET_PDB_FILE:${LIBNAME}>
	                DESTINATION bin${OGRE_DEBUG_PATH}
		            CONFIGURATIONS Debug
	            )
	            install(FILES $<TARGET_PDB_FILE:${LIBNAME}>
	                DESTINATION bin${OGRE_RELWDBG_PATH}
		            CONFIGURATIONS RelWithDebInfo
	            )
            endif ()
	    endif ()
    endif ()
endfunction (ogre_config_lib)

function(ogre_config_component LIBNAME)
    ogre_config_lib(${LIBNAME} TRUE)
    if (OGRE_PROJECT_FOLDERS)
        set_property(TARGET ${LIBNAME} PROPERTY FOLDER Components)
    endif ()
endfunction (ogre_config_component LIBNAME)

function (ogre_config_framework LIBNAME)
    if (OGRE_BUILD_LIBS_AS_FRAMEWORKS)
        set_target_properties(${LIBNAME} PROPERTIES FRAMEWORK TRUE)

        # Set the INSTALL_PATH so that frameworks can be installed in the application package
        set_target_properties(${LIBNAME}
            PROPERTIES BUILD_WITH_INSTALL_RPATH 1
            INSTALL_NAME_DIR "@executable_path/../Frameworks"
        )
        set_target_properties(${LIBNAME} PROPERTIES PUBLIC_HEADER "${HEADER_FILES};${PLATFORM_HEADERS};" )
        set_target_properties(${LIBNAME} PROPERTIES RESOURCE "${RESOURCE_FILES}")
        set_source_files_properties("${RESOURCE_FILES}" PROPERTIES MACOSX_PACKAGE_LOCATION Resources)

        set_target_properties(${LIBNAME} PROPERTIES OUTPUT_NAME ${LIBNAME})
    endif()
endfunction (ogre_config_framework)