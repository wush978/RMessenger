#include "../../prep.h"
using namespace gloox;

#include <stdio.h>
#include <locale.h>
#include <string>
#include <cstdio> // [s]print[f]

int main( int /*argc*/, char** /*argv*/ )
{
  int fail = 0;
  std::string name;
  std::string result;

  // -------
  name = "nodeprep oversized";
  const std::string t( 1200, 'x' );
  if( prep::nodeprep( t, result ) || !result.empty() )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }
  result = "";

  // -------
  name = "resourceprep oversized";
  if( prep::resourceprep( t, result ) || !result.empty() )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }
  result = "";

  // -------
  name = "nameprep oversized";
  if( prep::nameprep( t, result ) || !result.empty() )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }
  result = "";

  // -------
  name = "idna oversized";
  if( prep::idna( t, result ) || !result.empty() )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }
  result = "";

  // -------
  name = "nodeprep unchanged";
  const std::string t1( 10, 'x' );
  if( !( prep::nodeprep( t1, result ) && result == t1 ) )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }
  result = "";

  // -------
  name = "resourceprep unchanged";
  if( !( prep::resourceprep( t1, result ) && result == t1 ) )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }
  result = "";

  // -------
  name = "nameprep unchanged";
  if( !( prep::nameprep( t1, result ) && result == t1 ) )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }
  result = "";

  // -------
  name = "idna unchanged";
  if( !( prep::idna( t1, result ) && result == t1 ) )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }
  result = "";

  // -------
  name = "nodeprep simple casefolding";
  const std::string t2( "aBcDeFgH" );
  const std::string t3( "abcdefgh" );
  if( !( prep::nodeprep( t2, result ) && result == t3 ) )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }
  result = "";

  // -------
  name = "resourceprep simple casefolding (none)";
  if( !( prep::resourceprep( t2, result ) && result == t2 ) )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }
  result = "";

  // -------
  name = "nameprep simple casefolding";
  if( !( prep::nameprep( t2, result ) && result == t3 ) )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }
  result = "";

  // -------
  name = "idna example";
  if( !( prep::idna( "www.dömäin.de", result ) && result == "www.xn--dmin-moa0i.de" ) )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }
  result = "";












  if( fail == 0 )
  {
    printf( "Prep: OK\n" );
    return 0;
  }
  else
  {
    printf( "Prep: %d test(s) failed\n", fail );
    return 1;
  }

}
