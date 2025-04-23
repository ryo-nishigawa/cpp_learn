#メインアプリケーションの実行ファイルを作成
add_executable(cpp_learn_app main.cpp)

#ライブラリをリンク
    target_link_libraries(cpp_learn_app PRIVATE ${PROJECT_NAME})

#インストール設定
        install(TARGETS cpp_learn_app RUNTIME DESTINATION bin)