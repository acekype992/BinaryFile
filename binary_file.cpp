// MIT License
//
// Copyright (c) 2022 acekype992
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#include "binary_file.hpp"
#include <sstream>

using namespace std::literals;

namespace ack {


inline int BinaryFile::N_PRINT_COLUMNS  = DEFAULT_N_PRINT_COLUMNS::value;
inline int BinaryFile::N_PRINT_LINES    = DEFAULT_N_PRINT_LINES::value;


BinaryFile::BinaryFile() noexcept
    : file_ {std::string {}}
    , fileSize_ {0}
    , byteArray_ {byte_array_t {}}
{}


BinaryFile::BinaryFile(const std::string &file)
    : file_ {std::string {}}
    , fileSize_ {0}
    , byteArray_ {byte_array_t {}}
{
    std::ifstream f {file, std::ios::binary | std::ios::ate};
    if(!f.good())
        throw std::runtime_error("Unable to open the file. : "s + file);

    file_ = file;
    fileSize_ = f.tellg();
    byteArray_.reserve(fileSize_);

    f.seekg(0, std::ios::beg);
    writeByteArray(f);

    f.close();
}


BinaryFile::~BinaryFile() noexcept
{}


void BinaryFile::load_file(const std::string &file)
{
    reset();

    std::ifstream f {file, std::ios::binary | std::ios::ate};
    if(!f.good())
        throw std::runtime_error("Unable to open the file. : "s + file);

    file_ = file;
    fileSize_ = f.tellg();
    byteArray_.reserve(fileSize_);

    f.seekg(0, std::ios::beg);
    writeByteArray(f);

    f.close();
}


void BinaryFile::reset() noexcept
{
    file_.clear();
    fileSize_ = 0;
    byteArray_.clear();
    byteArray_.shrink_to_fit();
}


void BinaryFile::write_file_binary_form(const std::string &file) const
{
    std::ofstream f {file, std::ios::binary | std::ios::trunc};
    if(!f.good())
        throw std::runtime_error("Unable to open stream for writing : "s + file);

    for(std::size_t i {0}; i < byteArray_.size(); ++i)
    {
        const byte_t b = byteArray_[i];
        f.put(b);
    }

    f.close();
}


void BinaryFile::write_file_text_form(const std::string &file) const
{
    std::ofstream f {file, std::ios::trunc};
    if(!f.good())
        throw std::runtime_error("Unable to open the file for writing : "s + file);

    f << to_string();

    f.close();
}


std::string BinaryFile::name() const noexcept
{
    return file_;
}


std::size_t BinaryFile::size() const noexcept
{
    return fileSize_;
}


std::string BinaryFile::to_string() const noexcept
{
    //[IF]
    N_PRINT_COLUMNS < 0 ?
    N_PRINT_COLUMNS = DEFAULT_N_PRINT_COLUMNS::value : N_PRINT_COLUMNS = N_PRINT_COLUMNS;
    //[IF]

    std::ostringstream stream;
    std::size_t line{0};
    std::size_t line_break {0};
    const std::size_t byteArraySize {byteArray_.size()};

    for(std::size_t i {0}; i < byteArraySize; ++i)
    {
        if(line == BinaryFile::N_PRINT_LINES && BinaryFile::N_PRINT_LINES >= 0)
            break;

        const byte_t b {byteArray_[i]};
        const int byteINT = static_cast<int>(b) & 0xFF;

        std::ostringstream hexstream;
        hexstream << std::hex << byteINT;

        if(hexstream.str().size() == 1)
            stream << "0";

        stream << hexstream.str() << " ";

        ++line_break;
        if(line_break == BinaryFile::N_PRINT_COLUMNS) {
            stream << '\n';
            line_break = 0;
            ++line;
        }
    }

    const std::string byteArrayString {stream.str()};
    return byteArrayString;
}


BinaryFile::byte_array_t BinaryFile::to_byte_array() const noexcept
{
    return byteArray_;
}


void BinaryFile::writeByteArray(std::ifstream &stream)
{
    byte_t b;
    while(stream.get(b))
        byteArray_.push_back(b);

    if(!stream.eof())
        throw std::runtime_error("Error when initializing the byte array");
}


} // ack
