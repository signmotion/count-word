#pragma once

#include <array>
#include <regex>
#include <map>
#include <string>


namespace cw {


/**
* Работает с текстовым файлом.
*/
class TextFile {
public:
    // # Делаем public, чтобы не плодить геттеры.
    const std::string mFile;


    typedef std::string  word_t;


public:
    TextFile( const std::string& file );


    virtual ~TextFile();


    /**
    * @return Слова и их количество в тексте.
    *
    * @param separator Односимвольные разделители слов.
    */
    std::map< word_t, size_t >  countWord( const std::string& separator ) const;

};


} // cw








namespace std {

std::ostream& operator<<(
    std::ostream&,
    const std::map< cw::TextFile::word_t, size_t >&
);

} // std
