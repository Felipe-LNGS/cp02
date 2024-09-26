#pragma once

#include <iostream>
#include <string>
#include <cmath>
class Fixed{

    private :
        int _value;
        static const int    _fractionalBits;

    public :
        Fixed();
        Fixed(Fixed const &value);
        Fixed(int const &value);
        Fixed(float const &value);
        ~Fixed();
        Fixed & operator=(Fixed const &value);

        // opérateur de comparaison
        bool operator>(Fixed const &value) const;
        bool operator<(Fixed const &value) const;
        bool operator>=(Fixed const &value)const;
        bool operator<=(Fixed const &value)const;
        bool operator==(Fixed const &value)const;
        bool operator!=(Fixed const &value)const;

        //opérateurs de arithmétiques 
        Fixed operator+(Fixed const &value) const;
        Fixed operator-(Fixed const &value)const;
        Fixed operator*(Fixed const &value)const;
        Fixed operator/(Fixed const &value)const;

        //opérateurs d’incrémentation et de décrémentation 
        Fixed	operator++(int); //post incr
        Fixed	&operator++(); //pre incr
	    Fixed	operator--(int); //post decr
		Fixed	&operator--(); //pre decr
		
        //MIN/MAX
        static Fixed		&min(Fixed &nb1, Fixed &nb2);
		static Fixed const	&min(Fixed const &nb1, Fixed const &nb2);
		static Fixed		&max(Fixed &nb1, Fixed &nb2);
		static Fixed const	&max(Fixed const &nb1, Fixed const &nb2);

        float toFloat( void ) const;
        int toInt(void) const ;
        int getRawBits( void ) const;
        void setRawBits( int const raw );

};
        std::ostream & operator<<(std::ostream &os,const Fixed & fixed);

// expresion arritmetique

// + 1 1 prefixe , notation fonctionel
// +(1, 1)
// 1.+(1)


// 1 + 1 anotation infixe 

// 1 1 + anotation postfixe

// surcharge operateur

// class MyClass

// MyClass & operator=(MyClass const & rhs); assignation donc nouvelle instant qui prend la valeur assignéé
// MyClass  operator+(MyClass const & rhs)const ; aditionne suelement l'instance avec le parametre
// operator permet d'effectuer une surcharge d'operateur avec des signe assigné


// forme canonique

// un constructeur par default

// un autre par copie MyClass(Myclass const &src) nouvelle instance de cree
// alors que la c'est simplement un maj de l'instance MyClass & operator=(MyClass const & src);

// destrtucteur
