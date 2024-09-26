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
