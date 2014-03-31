#include "TextFile.h"
#include <assert.h>
#include <fstream>
#include <boost/algorithm/string.hpp>


namespace cw {


TextFile::TextFile(
    const std::string& file
) :
    mFile( file )
{
    assert( !mFile.empty()
        && "Имя файла должно быть указано." );
}




TextFile::~TextFile() {
}




std::map< TextFile::word_t, size_t >
TextFile::countWord( const std::string& separator ) const {

    using namespace boost;

    // @todo Кешировать результат.

    // читаем файл
    std::ifstream  in( mFile.c_str() );
    // @todo Заменить assert'ы на throw Exception.
    assert( in.is_open()
        && "Файл не найден." );
    
    std::map< word_t, size_t >  r;
    std::string line;
    while ( getline( in, line ) ) {

        std::vector< std::string >  allInLine;
        split( allInLine, line, is_any_of( separator ), token_compress_on );
        for (auto itr = allInLine.cbegin(); itr != allInLine.cend(); ++itr) {
            const word_t&  word = *itr;
            if ( !word.empty() ) {
                const auto ftr = r.find( word );
                if (ftr == r.cend()) {
                    r[ word ] = 1;
                } else {
                    ++ftr->second;
                }
            }
        }

    } // while ...

    in.close();

    return r;
}


} // cw








namespace std {

std::ostream& operator<<(
    std::ostream& out,
    const std::map< cw::TextFile::word_t, size_t >& r
) {
    for (auto itr = r.cbegin(); itr != r.cend(); ++itr) {
        std::cout << itr->second << "\t" << itr->first << std::endl;
    }

    return out;
}

} // std
