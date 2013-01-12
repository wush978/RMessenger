#include "../../jid.h"
using namespace gloox;

#include <stdio.h>
#include <locale.h>
#include <string>
#include <cstdio> // [s]print[f]

int main( int /*argc*/, char** /*argv*/ )
{
  int fail = 0;
  std::string name;
  JID j;

  // -------
  name = "bare JID ctor";
  j = JID( "abc@server.dom" );
  if( j.bare() != "abc@server.dom" || j.username() != "abc" || j.server() != "server.dom" )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }

  // -------
  name = "full JID ctor";
  j = JID( "abc@server.dom/res" );
  if( j.full() != "abc@server.dom/res" || j.username() != "abc" || j.server() != "server.dom"
      || j.resource() != "res" )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }

  // -------
  name = "server + resource ctor";
  j = JID( "server.dom/res" );
  if( j.full() != "server.dom/res" || j.server() != "server.dom" || j.resource() != "res" )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }

  // -------
  name = "server ctor";
  j = JID( "server.dom" );
  if( j.full() != "server.dom" || j.server() != "server.dom" )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }

  // -------
  name = "prepped node";
  j = JID( "ABC@server.dom" );
  if( j.bare() != "abc@server.dom" )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }

  // -------
  name = "prepped dom";
  j = JID( "abc@SeRvEr.dom" );
  if( j.bare() != "abc@server.dom" )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }

  // -------
  name = "resource getter";
  j = JID( "abc@server.dom/rEsOurCe" );
  if( j.resource() != "rEsOurCe" )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }

  // -------
  name = "node getter";
  j = JID( "aBc@server.dom/rEsOurCe" );
  if( j.username() != "abc" )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }

  // -------
  name = "server getter";
  j = JID( "abc@serVer.dom/rEsOurCe" );
  if( j.server() != "server.dom" )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }

  // -------
  name = "bare JID getter";
  j = JID( "abc@serVer.dom/rEsOurCe" );
  JID t1( "abc@serVer.dom/rEsOurCe");
  if( j.bareJID() != t1.bareJID() )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }

  // -------
  name = "clear jid";
  j = JID( "abc@serVer.dom/rEsOurCe" );
  j.setJID( "" );
  if( j || !j.username().empty()
        || !j.server().empty()
        || !j.serverRaw().empty()
        || !j.resource().empty()
        || !j.bare().empty()
        || !j.full().empty() )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }

  // -------
  name = "operator bool() 1";
  JID jid1( "abc@serVer.dom/rEsOurCe" );
  if( !jid1 )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }

  // -------
  name = "operator bool() 2";
  JID jid2( "" );
  if( jid2 )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }

  // -------
  name = "JID\20Escaping";
  const std::string e = JID::escapeNode( "1 2\"3&4'5/6:7<8>9@10\\" );
  if( e != "1\\202\\223\\264\\275\\2f6\\3a7\\3c8\\3e9\\4010\\5c" )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }

  // -------
  name = "JID\20Unescaping";
  const std::string f = JID::unescapeNode( "1\\202\\223\\264\\275\\2f6\\3a7\\3c8\\3e9\\4010\\5c" );
  if( f != "1 2\"3&4'5/6:7<8>9@10\\" )
  {
    ++fail;
    printf( "test '%s' failed\n", name.c_str() );
  }










  if( fail == 0 )
  {
    printf( "JID: OK\n" );
    return 0;
  }
  else
  {
    printf( "JID: %d test(s) failed\n", fail );
    return 1;
  }

}
