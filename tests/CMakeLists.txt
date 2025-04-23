#Google Test のセットアップ
include(FetchContent)
    FetchContent_Declare(googletest GIT_REPOSITORY https :  // github.com/google/googletest.git
                         GIT_TAG release - 1.12.1) FetchContent_MakeAvailable(googletest)

#テストファイルを検索
        file(GLOB_RECURSE TEST_FILES
             "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
             "${CMAKE_CURRENT_SOURCE_DIR}/*.cxx"
             "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")

#テスト実行ファイルを作成
            add_executable(${PROJECT_NAME} _tests ${TEST_FILES})

#インクルードパスを設定
                target_include_directories(${PROJECT_NAME} _tests PRIVATE ${
                    CMAKE_CURRENT_SOURCE_DIR})

#依存関係をリンク
                    target_link_libraries(${PROJECT_NAME} _tests PRIVATE ${
                        PROJECT_NAME} gtest gtest_main)

#テストを CTest に追加
                        include(GoogleTest) gtest_discover_tests(${PROJECT_NAME} _tests)