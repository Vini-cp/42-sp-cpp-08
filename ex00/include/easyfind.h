// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#ifndef EASYFIND_H
#define EASYFIND_H

# include <iostream>
# include <algorithm>

class NotFound : public std::exception
{
public:
    virtual const char* what() const throw()
    {
        return ("Not found!");
    }
};


template< typename T >
typename T::iterator easyfind( T& prContainer, int pToFind )
{
    typename T::iterator it;

    it = std::find( prContainer.begin(), prContainer.end(), pToFind );
    
    if ( it == prContainer.end() ) throw NotFound();

    return it;
};

#endif
