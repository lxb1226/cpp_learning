FIND_PATH(HELLO_INCLUDE_DIR hello.h /tmp/t2/usr/include/hello)
FIND_LIBRARY(HELLO_LIBRARY hello /tmp/t2/usr/lib)
IF (HELLO_INCLUDE_DIR AND HELLO_LIBRARY)
    SET(HELLO_FOUND TRUE)
    MESSAGE("HELLO_INCLUDE_DIR: " ${HELLO_INCLUDE_DIR})
    MESSAGE("HELLO_LIBRARY: " ${HELLO_LIBRARY})
ENDIF (HELLO_INCLUDE_DIR AND HELLO_LIBRARY)
IF (HELLO_FOUND)
    IF (NOT HELLO_FIND_QUIETLY)
        MESSAGE(STATUS "Found Hello: ${HELLO_LIBRARY}")
    ENDIF (NOT HELLO_FIND_QUIETLY)
ELSE (HELLO_FOUND)
    IF (HELLO_FIND_REQUIRED)
        MESSAGE(FATAL_ERROR "Could not find hello library")
    ENDIF (HELLO_FIND_REQUIRED)
ENDIF (HELLO_FOUND)