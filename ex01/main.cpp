// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#include "include/Span.h"

#include <cstdlib>

int main( void )
{
    {
        std::cout << "=============================================" << std::endl;

        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        std::cout << "=============================================" << std::endl << std::endl;
    }
    {
        std::cout << "=================== Empty ===================" << std::endl;
        
        Span sp;
        try
        {
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "=============================================" << std::endl << std::endl;
    }
    {
        std::cout << "==================== One ====================" << std::endl;
        
        Span sp( 1 );
        try
        {
            sp.addNumber( 5 );
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "=============================================" << std::endl << std::endl;
    }
    {
        std::cout << "==================== Two ====================" << std::endl;
        
        Span sp( 2 );
        try
        {
            sp.addNumber( 5 );
            sp.addNumber( 42 );
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "=============================================" << std::endl << std::endl;
    }
    {
        std::cout << "================== OverFlow =================" << std::endl;
        
        Span sp( 3 );
        try
        {
            sp.addNumber( 0 );
            sp.addNumber( 1 );
            sp.addNumber( 2 );
            sp.addNumber( 3 );
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "=============================================" << std::endl << std::endl;
    }
    {
        std::cout << "================== Negative =================" << std::endl;

        Span sp( 5 );
        srand( time( NULL ) );
        try
        {
            sp.addNumber( -1 );
            sp.addNumber( -64 );
            sp.addNumber( -172 );
            sp.addNumber( -9 );
            sp.addNumber( -555 );

            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch( std::exception& e )
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "=============================================" << std::endl << std::endl;
    }
    {
        std::cout << "================== Rand(10) =================" << std::endl;

        Span sp( 10 );
        srand( time( NULL ) );
        try
        {
            for ( int i = 1; i <= 10; i++ )
                sp.addNumber( rand() % 1000000 );

            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch( std::exception& e )
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "=============================================" << std::endl << std::endl;
    }
    {
        std::cout << "================ Rand(10.000) ===============" << std::endl;

        Span sp( 10000 );
        srand( time( NULL ) );
        try
        {
            for ( int i = 1; i <= 10000; i++ )
                sp.addNumber( rand() % 1000000 );

            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch( std::exception& e )
        {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "=============================================" << std::endl << std::endl;

    return 0;
}
