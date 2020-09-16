cmake_minimum_required(VERSION 3.16)

project(Engine VERSION 1.0.0)

add_subdirectory(engine)

include(cmake/Settings.cmake)
include(cmake/Variables.cmake)
include(cmake/BuildOptions.cmake)

function(add_external_libraries)
    foreach(LIBRARY ${LIBRARIES_LIST})
        message(${Green} "Adding ${LIBRARY} library" ${ColourReset})
        add_subdirectory(${CMAKE_SOURCE_DIR}/${EXTERNAL_FOLDER}/${LIBRARY})
    endforeach()
endfunction()

function(add_packages)
    foreach(PACKAGE ${PACKAGES_LIST})
        message(${Green} "Adding ${PACKAGE} package" ${ColourReset})
        add_subdirectory(${CMAKE_SOURCE_DIR}/${PACKAGES_FOLDER}/${PACKAGE})
    endforeach()
endfunction()

add_external_libraries()
add_packages()
