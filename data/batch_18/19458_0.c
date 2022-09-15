const char * GetInputMessageTypeName ( const IPC : : Message & message ) {
 switch ( message . type ( ) ) {
 # include "content/common/input_messages.h" default : NOTREACHED ( ) << "Invalid message type: " << message . type ( ) ;
 break ;
 }
 ;
 return "NonInputMsgType" ;
 }