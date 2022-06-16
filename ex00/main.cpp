// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#include <list>
#include <deque>
#include <vector>

#include "include/easyfind.h"

int main( void )
{
    {
        std::cout << "==================== vector ====================" << std::endl;
        
        std::vector< int > v( 10, 42 );

        try
        {
            std::vector< int >::iterator it = easyfind( v, 42 );
            std::cout << "Found: " << *it << std::endl;
        }
        catch( const std::exception& e )
        {
            std::cerr << e.what() << std::endl;
        }

        try
        {
            std::vector< int >::iterator it = easyfind( v, 100 );
            std::cout << "Found: " << *it << std::endl;
        }
        catch( const std::exception& e )
        {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "================================================" << std::endl << std::endl;
    }
    {
        std::cout << "===================== deque ====================" << std::endl;
        
        std::deque< int > d( 10, 42 );

        try
        {
            std::deque< int >::iterator it = easyfind( d, 42 );
            std::cout << "Found: " << *it << std::endl;
        }
        catch( const std::exception& e )
        {
            std::cerr << e.what() << std::endl;
        }

        try
        {
            std::deque< int >::iterator it = easyfind( d, 100 );
            std::cout << "Found: " << *it << std::endl;
        }
        catch( const std::exception& e )
        {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "================================================" << std::endl << std::endl;
    }
    {
        std::cout << "===================== list =====================" << std::endl;
        
        std::list< int > li( 10, 42 );

        try
        {
            std::list< int >::iterator it = easyfind( li, 42 );
            std::cout << "Found: " << *it << std::endl;
        }
        catch( const std::exception& e )
        {
            std::cerr << e.what() << std::endl;
        }

        try
        {
            std::list< int >::iterator it = easyfind( li, 100 );
            std::cout << "Found: " << *it << std::endl;
        }
        catch( const std::exception& e )
        {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "================================================" << std::endl << std::endl;
    }
    return 0;
}
