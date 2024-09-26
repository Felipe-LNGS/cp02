#include "Fixed.hpp"

const int    Fixed::_fractionalBits = 8;

/*********************CONSTRUCTOR_DEFAULT***********************/
Fixed::Fixed(): _value(0){
	std::cout << "Default constructor called" <<std::endl;
}

Fixed::~Fixed(){
	std::cout << "Default constructor called" << std::endl;
}

/*********************CONSTRUCTOR_VALUE***********************/
Fixed::Fixed (Fixed const &value){
	std::cout << "Copy constructor called" << std::endl;
*this = value;
}
Fixed::Fixed(int const &value){
	std::cout << "Int constructor called" <<std::endl;
this->_value = value  * (1 << _fractionalBits); 
}

Fixed::Fixed(float const &value){
	std::cout << "Float constructor called" <<std::endl;
this->_value = value * (1 << _fractionalBits);
}

//déplace le bit 1 de 8 positions vers la gauche. ce qui fais 2^8 = 256 
//plus on augmentera le nombre de bits moins on aura d'erreur de precision
//ex : float 42.42 * 256 = 10859.52    on stock 10859. 0.52/256 = 0.002 ce qui equivaut a la perte de precision 

/******************OPERATOR************************/
Fixed &Fixed::operator=(Fixed const &value){
	std::cout << "Copy assignment operator called" <<std::endl;
	this->_value = value.getRawBits();
	return *this;
}
std::ostream &operator<<(std::ostream &os, const Fixed  & fixed){
	os << fixed.toFloat();
	return os;
}
//permet d'afficher le resultat de fixed dans os(os = std::cout) ce qui equivaut a faire 
//std::out << 'ma variable de class'(fixed.toFloat)
//en faisant le return os cela me permet de chaine plusieur valeur du genre
//std::cout << fixed1 << fixed2 << fixed3

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
	std::cout << "getRawBits member function called" <<std::endl;
	return this->_value;
} 

void Fixed::setRawBits(int const raw){
this->_value = raw;
}

