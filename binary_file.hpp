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

#ifndef ACK_BINARY_FILE_HPP
#define ACK_BINARY_FILE_HPP

#include <fstream>
#include <vector>

namespace ack {


class BinaryFile
{
    using DEFAULT_N_PRINT_COLUMNS   = std::integral_constant<int, 15>;
    using DEFAULT_N_PRINT_LINES     = std::integral_constant<int, -1>;

public:
    using byte_t = char;
    using byte_array_t = std::vector<byte_t>;

    static int N_PRINT_LINES;
    static int N_PRINT_COLUMNS;

    BinaryFile() noexcept;
    BinaryFile(const std::string &file);

    ~BinaryFile() noexcept;

    void load_file(const std::string &file);
    void reset() noexcept;

    void write_file_binary_form(const std::string &file) const;
    void write_file_text_form(const std::string &file) const;

    std::string name() const noexcept;
    std::size_t size() const noexcept;

    std::string to_string() const noexcept;
    byte_array_t to_byte_array() const noexcept;

private:
    std::string file_;
    std::size_t fileSize_;
    byte_array_t byteArray_;

private:
    void writeByteArray(std::ifstream &stream);

};


} // ack

#endif // ACK_BINARY_FILE_HPP
