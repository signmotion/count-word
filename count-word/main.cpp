#pragma once

#include "TextFile.h"
#include <iostream>
#include <boost/algorithm/string.hpp>


int
main( int argc, char** argv ) {

    using namespace cw;

    setlocale( LC_ALL, "Russian" );
    setlocale( LC_NUMERIC, "C" );


    const std::string file =
        (argc > 1) ? argv[ 1 ] : "";
    if ( file.empty() ) {
        std::cout << "Укажите имя файла." << std::endl;
        return -1;
    }


    TextFile tf( file );
    const auto countWord =
        tf.countWord( " ,.;:[]{}<>\\?\"*/~!@#$%^&*()_+-=" );
    std::cout << countWord << std::endl;


    return 0;
}
