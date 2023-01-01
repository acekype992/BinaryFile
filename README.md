# BinaryFile Class
```cpp
namespace ack {
    class BinaryFile;
}
```
<br/>

## Informations :

#### Typedef :
```cpp
using byte_t = char;
using byte_array_t = std::vector<byte_t>;
```

#### Constructors :
```cpp
BinaryFile() noexcept;
BinaryFile(const std::string &file);
```
#### Member variables :
```cpp
static int N_PRINT_COLUMNS; // Number of column to write in the string
static int N_PRINT_LINES; // Number of lines to write in the string
```
#### Member Functions :
```cpp
void load_file(const std::string &file); // loads a file into a byte array
void reset() noexcept; // reset this BinaryFile object

void write_file_binary_form(const std::string &file) const; // writes the byte array to a file in binary format
void write_file_text_form(const std::string &file) const; // writes the byte array to a file in string format

std::string name() const noexcept; // returns the name of the loaded file
std::size_t size() const noexcept; // returns the size of the loaded file

std::string to_string() const noexcept; // converts the byte array to a string and returns it
byte_array_t to_byte_array() const noexcept; // returns an array of bytes
```
#### Exceptions :
An exception <a href="https://en.cppreference.com/w/cpp/error/runtime_error"><i>std::runtime_error</i></a> is thrown when the file cannot be opened for some reason :
```cpp
BinaryFile(const std::string &file);
void load_file(const std::string &file);
```
An exception <a href="https://en.cppreference.com/w/cpp/error/runtime_error"><i>std::runtime_error</i></a> is thrown when it is impossible to write to a file for some reason :
```cpp
void write_file_binary_form(const std::string &file) const;
void write_file_text_form(const std::string &file) const;
```
<br/>

## Example
###### main.cpp
```cpp
#include "binary_file.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    ack::BinaryFile f {"image.png"};
    std::cout << "File : " << f.name() << std::endl;
    std::cout << "Size file : " << f.size() << std::endl;
    std::cout << "Content :\n" << f.to_string() << std::endl;

    return 0;
}
```
###### OUTPUT
```
File : image.png
Size file : 5453
Content :
89 50 4e 47 0d 0a 1a 0a 00 00 00 0d 49 48 44 
52 00 00 00 e1 00 00 00 e1 08 03 00 00 00 09 
6d 22 48 00 00 00 f0 50 4c 54 45 f3 64 09 ff 
ff ff f2 f2 f2 f3 62 00 f3 5f 00 f3 5d 00 f3 
...
```
<br/>

## License :
<a href=https://github.com/acekype992/BinaryFile/blob/bef56c5c38211235e6be0a06606719e7b7a54127/LICENSE>MIT License - Copyright (c) 2022 acekype992</a>
