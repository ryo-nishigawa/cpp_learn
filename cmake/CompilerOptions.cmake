# コンパイラフラグの設定
if(MSVC)
    # Visual Studio のフラグ
    add_compile_options(
        /W4
        /WX
        /wd4251
        /permissive-
        /Zc:__cplusplus
        /MP
    )
else()
    # GCC/Clang のフラグ
    add_compile_options(
        -Wall
        -Wextra
        -Wpedantic
        -Werror
        -Wconversion
        -Wshadow
        -Wnon-virtual-dtor
    )
    
    # Clang 専用フラグ
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        add_compile_options(
            -Wmost
            -Weverything
            -Wno-c++98-compat
            -Wno-c++98-compat-pedantic
        )
    endif()
endif()