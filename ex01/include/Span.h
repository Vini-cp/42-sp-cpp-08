// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <vector>

class Span
{
public:
    Span();
    Span( unsigned int n );
    Span( std::vector< int >::iterator pBegin, std::vector< int >::iterator pEnd );
    Span( const Span& prSpan );
    ~Span();

    Span& operator=( const Span& prSpan );

    void addNumber( int pNumber );

    int shortestSpan( void ) const;
    int longestSpan( void ) const;

    std::vector< int > getVector( void ) const;
    unsigned int getFullSize( void ) const;

    class SpanFull : public std::exception
    {
    public:
        virtual const char* what( void ) const throw();
    };

    class SpanHasFewMembers : public std::exception
    {
    public:
        virtual const char* what( void ) const throw();
    };

private:
    std::vector< int > mVector;

    unsigned int mFullSize;
};

#endif
