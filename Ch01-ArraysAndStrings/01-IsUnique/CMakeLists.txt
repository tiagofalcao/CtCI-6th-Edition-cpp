file(GLOB SOURCES "*.cc")
get_filename_component(TEST ${CMAKE_CURRENT_SOURCE_DIR}/test.cc ABSOLUTE)
list(REMOVE_ITEM SOURCES "${TEST}")

FOREACH(src ${SOURCES})
    STRING(REGEX REPLACE ".cc\$" "" bin "${src}")
    message(STATUS "${bin}")
    STRING(REGEX REPLACE "\^${CMAKE_SOURCE_DIR}/" "" bin "${bin}")
    message(STATUS "${bin}")
    STRING(REGEX REPLACE "/" "_" bin "${bin}")
    message(STATUS "${bin}")

    add_executable(${bin} ${src} "${TEST}")
    target_link_libraries(${bin} ${GTEST_BOTH_LIBRARIES} pthread)

    add_test(${bin} ${bin})
ENDFOREACH(src)
