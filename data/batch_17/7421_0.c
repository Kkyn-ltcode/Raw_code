enum block_op find_operand ( const char * start ) {
 char first = * start ;
 char next = * ( start + 1 ) ;
 if ( first == '=' && next == '=' ) return EQ_OP ;
 if ( first == '!' && next == '=' ) return NE_OP ;
 if ( first == '>' && next == '=' ) return GE_OP ;
 if ( first == '>' ) return GT_OP ;
 if ( first == '<' && next == '=' ) return LE_OP ;
 if ( first == '<' ) return LT_OP ;
 return ILLEG_OP ;
 }