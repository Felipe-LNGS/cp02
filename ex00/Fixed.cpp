#include "Fixed.hpp"

const int    fractionalBits = 8;

Fixed::Fixed(): _value(0){
    std::cout << "Default constructor called" <<std::endl;
}

Fixed::Fixed(Fixed const &value){
    std::cout << "Copy constructor called" <<std::endl;
*this = value;
}

Fixed::~Fixed(){
    std::cout << "Default constructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &value){
    std::cout << "Copy assignment operator called" <<std::endl;
    this->_value = value.getRawBits();
    return *this;
}
int Fixed::getRawBits()const{
    std::cout << "getRawBits member function called" <<std::endl;
   
    return this->_value;
} 

void Fixed::setRawBits(int const raw){
this->_value = raw;
}