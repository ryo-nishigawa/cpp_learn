cmake_minimum_required(VERSION 3.14...3.25)

# プロジェクト情報
project(cpp_learn VERSION 0.1.0
                   DESCRIPTION "C++学習用サンプルプロジェクト"
                   LANGUAGES CXX)

# C++17 を指定
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# プロジェクトがメインプロジェクトの場合の設定
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    # テストを有効化
    include(CTest)
    
    # IDE でのフォルダ表示を改善
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

# サブディレクトリを追加
add_subdirectory(src)

# テストを有効にする
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

# アプリケーションを追加
option(BUILD_APPS "アプリケーションをビルドする" ON)
if(BUILD_APPS)
    add_subdirectory(apps)
endif()

# Git hooks設定
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    # Git hooksへのパスを設定
    set(GIT_HOOKS_DIR "${PROJECT_SOURCE_DIR}/.githooks")
    
    # pre-commitフックを設定
    execute_process(
        COMMAND ${GIT_EXECUTABLE} config core.hooksPath ${GIT_HOOKS_DIR}
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    )
    
    message(STATUS "Git hooks enabled: ${GIT_HOOKS_DIR}")
endif()