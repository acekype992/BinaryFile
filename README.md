# BinaryFile
```cpp
class BinaryFile;
```

### Informations :


###### Typedef :
```cpp
using byte_t = char;
using byte_array_t = std::vector<byte_t>;
```


###### Constructors :
```cpp
BinaryFile() noexcept;
BinaryFile(const std::string &file);
```


###### Member Functions :
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
<br/>

### License :
<a href=https://github.com/acekype992/BinaryFile/blob/bef56c5c38211235e6be0a06606719e7b7a54127/LICENSE>MIT License - Copyright (c) 2022 acekype992</a>
