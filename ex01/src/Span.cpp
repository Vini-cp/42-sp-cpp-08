// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#include "../include/Span.h"

#include <algorithm>

//------------------------------------------------------------------------------

Span::Span( void ) : mFullSize( 0 )
{
}

//------------------------------------------------------------------------------
Span::Span( unsigned int n ) : mFullSize( n )
{
}

//------------------------------------------------------------------------------

Span::Span( std::vector< int >::iterator pBegin, std::vector< int >::iterator pEnd ) :
    mVector( pBegin, pEnd ),
    mFullSize( pEnd - pBegin )
{
}

//------------------------------------------------------------------------------

Span::Span( const Span& prSpan )
{
    *this = prSpan;
}

//------------------------------------------------------------------------------

Span::~Span( void )
{
}

//------------------------------------------------------------------------------

Span& Span::operator=( const Span& prSpan )
{
    if ( this == &prSpan ) return *this;

    mVector = prSpan.getVector();
    mFullSize = prSpan.getFullSize();

    return *this;
}

//------------------------------------------------------------------------------

std::vector< int > Span::getVector( void ) const
{
    return mVector;
}

//------------------------------------------------------------------------------

unsigned int Span::getFullSize( void ) const
{
    return mFullSize;
}

//------------------------------------------------------------------------------

void Span::addNumber( int pNumber )
{
    if ( mVector.size() == mFullSize )
        throw Span::SpanFull();

    mVector.push_back( pNumber );
}

//------------------------------------------------------------------------------

int Span::shortestSpan( void ) const
{
    if ( mVector.size() < 2 )
        throw Span::SpanHasFewMembers();

    std::vector< int > lSortedVector = mVector;
    std::sort( lSortedVector.begin(), lSortedVector.end() );

    std::vector< int >::iterator it;

    int lShortestSpan = *( lSortedVector.end() - 1 ) - *lSortedVector.begin();

    for ( it = lSortedVector.begin() + 1; it != lSortedVector.end(); it++ )
    {
        if ( ( *it - *( it - 1 ) ) < lShortestSpan )
        {
            lShortestSpan = *it - *( it - 1 );
        }
    }

    return lShortestSpan;
}

//------------------------------------------------------------------------------

int Span::longestSpan( void ) const
{
    if ( mVector.size() < 2 )
        throw Span::SpanHasFewMembers();

    std::vector< int >::const_iterator lMaxValue = std::max_element( mVector.begin(), mVector.end() );
    std::vector< int >::const_iterator lMinValue = std::min_element( mVector.begin(), mVector.end() );

    return ( *lMaxValue - *lMinValue );
}

//------------------------------------------------------------------------------

const char* Span::SpanFull::what( void ) const throw()
{
    return "Span already full";
}

//------------------------------------------------------------------------------

const char* Span::SpanHasFewMembers::what( void ) const throw()
{
    return "Span has few members";
}

//------------------------------------------------------------------------------
