#include <rijndael/fields/byteField.hpp>
#include <rijndael/utils.hpp>
#include <bitset>

#define MX 0x1B

Rijndael::ByteField::ByteField(const unsigned char& _value) : value(_value) {}
Rijndael::ByteField::ByteField() : ByteField((unsigned char) 0x00) {}
Rijndael::ByteField::ByteField(const ByteField& value) : ByteField(value.value) {}
Rijndael::ByteField::ByteField(const ByteField* value) : ByteField(*value) {}

Rijndael::ByteField Rijndael::ByteField::operator+(const ByteField& a) const {
    return ByteField(this->value ^ a.value);
}
void Rijndael::ByteField::operator+=(const ByteField& a) {
    this->value = this->value ^ a.value;
}
Rijndael::ByteField Rijndael::ByteField::operator-(const ByteField& a) const {
    return this->operator+(a);
}
void Rijndael::ByteField::operator-=(const ByteField& a) {
    this->operator+=(a);
}

void Rijndael::ByteField::xtimes() {
    bool shouldXor = (bool)(this->value & 0x80);
    this->value = this->value << 1;
    if (shouldXor) {
        this->value = this->value ^ MX;
    }
}
bool Rijndael::ByteField::getBit(const short& idx) const {
    return (this->value >> idx) & 1;
}
void Rijndael::ByteField::operator*=(const ByteField& other) {
    ByteField iter = ByteField(this);
    this->value = 0x00;
    for (short idx = 0; idx < 8; idx++) {
        if (other.getBit(idx)) {
            this->operator+=(iter);
        }
        iter.xtimes();
    }
}

Rijndael::ByteField Rijndael::ByteField::operator*(const ByteField& other) {
    ByteField res = ByteField(*this);
    res *= other;
    return res;
}

const unsigned char& Rijndael::ByteField::getValue() const {
    return this->value;
}
void Rijndael::ByteField::setValue(const unsigned char& other) {
    this->value = other;
}
void Rijndael::ByteField::setValue(const ByteField& other) {
    this->setValue(other.getValue());
}

std::ostream& operator<<(std::ostream& out, const Rijndael::ByteField& field) {
    out << std::hex << (int)(field.getValue());
    return out;
}