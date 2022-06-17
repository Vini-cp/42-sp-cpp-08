// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <deque>
#include <list>
#include <iostream>
#include <stack>

template < typename T, typename C = std::deque< T > >
class MutantStack : public std::stack< T, C >
{
public:
    MutantStack() : std::stack< T, C >() {};    
    MutantStack( MutantStack const &prMutantStack ) : std::stack< T, C >( prMutantStack ) {};
    virtual ~MutantStack() {};

    MutantStack& operator=( MutantStack const &prMutantStack )
    {
        if ( this == &prMutantStack ) return *this;

        this->c = prMutantStack.c;
        return *this;
    };

    typedef typename std::stack< T >::container_type::iterator iterator;

    iterator begin(void)
    {
        return this->c.begin();
    };

    iterator end(void)
    {
        return this->c.end();
    };
};

#endif
