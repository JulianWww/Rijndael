#include <iostream>
#include <rijndael/fields/4byteVector.hpp>

int main(int, char**){
    Rijndael::FourByteVector a = Rijndael::FourByteVector({
        Rijndael::ByteField((unsigned char) 0x00), 
        Rijndael::ByteField((unsigned char) 0x00), 
        Rijndael::ByteField((unsigned char) 0x00), 
        Rijndael::ByteField((unsigned char) 0x00)
    });

    Rijndael::FourByteVector b = Rijndael::FourByteVector({
        Rijndael::ByteField((unsigned char) 0x00), 
        Rijndael::ByteField((unsigned char) 0x00), 
        Rijndael::ByteField((unsigned char) 0x00), 
        Rijndael::ByteField((unsigned char) 0x00)
    });

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    Rijndael::FourByteVector c = a + b;
    std::cout << c << std::endl;

    return 0;
}
