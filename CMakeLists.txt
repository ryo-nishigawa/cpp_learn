# ヘッダーファイルを検索
file(GLOB_RECURSE HEADER_FILES 
     "${CMAKE_CURRENT_SOURCE_DIR}/../include/*.hpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/../include/*.h")

# ソースファイルを検索
file(GLOB_RECURSE SOURCE_FILES 
     "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/*.cxx"
     "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")

# ライブラリを作成
add_library(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

# インクルードパスを設定
target_include_directories(${PROJECT_NAME} 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# インストール設定
install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}Targets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../include/
        DESTINATION include
        FILES_MATCHING PATTERN "*.h*")