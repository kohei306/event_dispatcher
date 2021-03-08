add_library(${PROJECT_NAME} INTERFACE)

set(include_dest "${INSTALL_INCLUDEDIR}/include")

set(cmake_dest   "${INSTALL_LIBDIR}/lib/${PROJECT_NAME}/cmake")

# Set includes paths
file(GLOB_RECURSE  public_header ${CMAKE_CURRENT_SOURCE_DIR}/../include/${PROJECT_NAME}/*h)
set(header ${public_header})    

# Link include directories
target_include_directories(${PROJECT_NAME}
 INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
 INTERFACE $<INSTALL_INTERFACE:${include_dest}>
)



## Mark executables and/or libraries for installation
# libraries and executables
install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}-targets
        LIBRARY DESTINATION ${LNSTALL_LIBDIR}
        ARCHIVE DESTINATION ${LNSTALL_LIBDIR}
        RUNTIME DESTINATION ${LNSTALL_BINDIR})
# headers
install(FILES ${header} DESTINATION "${include_dest}")
