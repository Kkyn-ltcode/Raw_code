static void timerblock_write ( void * opaque , hwaddr addr , uint64_t value , unsigned size ) {
 TimerBlock * tb = ( TimerBlock * ) opaque ;
 int64_t old ;
 switch ( addr ) {
 case 0 : tb -> load = value ;
 case 4 : if ( ( tb -> control & 1 ) && tb -> count ) {
 qemu_del_timer ( tb -> timer ) ;
 }
 tb -> count = value ;
 if ( tb -> control & 1 ) {
 timerblock_reload ( tb , 1 ) ;
 }
 break ;
 case 8 : old = tb -> control ;
 tb -> control = value ;
 if ( ( ( old & 1 ) == 0 ) && ( value & 1 ) ) {
 if ( tb -> count == 0 && ( tb -> control & 2 ) ) {
 tb -> count = tb -> load ;
 }
 timerblock_reload ( tb , 1 ) ;
 }
 break ;
 case 12 : tb -> status &= ~ value ;
 timerblock_update_irq ( tb ) ;
 break ;
 }
 }