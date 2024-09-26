#include "Fixed.hpp"

const int    Fixed::_fractionalBits = 8;

/*********************CONSTRUCTOR_DEFAULT***********************/
Fixed::Fixed(): _value(0){
}

Fixed::~Fixed(){
}

/*********************CONSTRUCTOR_VALUE***********************/
Fixed::Fixed (Fixed const &value){
*this = value;
}
Fixed::Fixed(int const &value){
this->_value = value  * (1 << _fractionalBits); 
}

Fixed::Fixed(float const &value){
this->_value = value * (1 << _fractionalBits);
}

Fixed &Fixed::operator=(Fixed const &value){
	this->_value = value.getRawBits();
	return *this;
}
std::ostream &operator<<(std::ostream &os, const Fixed  & fixed)
{
	os << fixed.toFloat();
	return os;
}

/******************COMPARAISON************************/

bool Fixed::operator>(Fixed const &value) const
{
    if (this->_value > value._value) {
        return true;
    } else {
        return false;
    }
}

bool Fixed::operator<(Fixed const &value) const
{
    if (this->_value < value._value) {
        return true;
    } else {
        return false;
    }
}

bool Fixed::operator>=(Fixed const &value)const
{
    if (this->_value >= value._value) {
        return true;
    } else {
        return false;
    }
}

bool Fixed::operator<=(Fixed const &value)const
{
    if (this->_value <= value._value) {
        return true;
    } else {
        return false;
    }
}

bool Fixed::operator==(Fixed const &value)const
{
    if (this->_value == value._value) {
        return true;
    } else {
        return false;
    }
}

bool Fixed::operator!=(Fixed const &value)const
{
    if (this->_value != value._value) {
        return true;
    } else {
        return false;
    }
}
/************************ARITHMETIQUE*************************** */
Fixed Fixed::operator+(Fixed const &value) const
{
Fixed result;

result = this->toFloat() + value.toFloat();

return result;
}

Fixed Fixed::operator-(Fixed const &value)const
{
Fixed result;

result = this->toFloat() - value.toFloat();

return result;
}

Fixed Fixed::operator*(Fixed const &value)const
{
Fixed result;

result = this->toFloat() * value.toFloat();

return result;
}

Fixed Fixed::operator/(Fixed const &value)const
{
Fixed result;

result = this->toFloat() / value.toFloat();

return result;
}
/****************************INCR/POST******************************* */

Fixed	Fixed::operator++(int) //pre incrementation i++
{
Fixed result = *this;
	++*this;
	return (result);
}

Fixed	&Fixed::operator++() //post incrementation ++i
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator--(int) //post decrementation --i
{
	Fixed result = *this;
	++*this;
	return (result);
}

Fixed	&Fixed::operator--()//pre decrementation i--
{
	this->_value--;
	return (*this);
}
/**********************MIN/MAX***************************/
Fixed	&Fixed::min(Fixed &nb1, Fixed &nb2)
{
	if (nb1.getRawBits() < nb2.getRawBits())
		return (nb1);
	return (nb2);
}

Fixed const	&Fixed::min(Fixed const &nb1, Fixed const &nb2)
{
	if (nb1.getRawBits() < nb2.getRawBits())
		return (nb1);
	return (nb2);
}

Fixed	&Fixed::max(Fixed &nb1, Fixed &nb2)
{
	if (nb1.getRawBits() > nb2.getRawBits())
		return (nb1);
	return (nb2);
}

Fixed const	&Fixed::max(Fixed const &nb1, Fixed const &nb2)
{
	if (nb1.getRawBits() > nb2.getRawBits())
		return (nb1);
	return (nb2);
}
/**********************FUNCTION********************/
float Fixed::toFloat()const{
	return static_cast<float>(this->_value) /(1 << _fractionalBits);
}
int Fixed::toInt()const{
return static_cast<int>(roundf(this->_value)) /(1 << _fractionalBits);
}
//ici on divise par 2^8 pour soit obtenir la valeur avec float 42.418(qui a perdu les 0.002 de precision)
// ou soit en int qu'on arrondi a la valeur la plus proche des decimal 

int Fixed::getRawBits()const{
	return this->_value;
} 

void Fixed::setRawBits(int const raw){
this->_value = raw;
}

