static void ps2_mouse_event ( DeviceState * dev , QemuConsole * src , InputEvent * evt ) {
 static const int bmap [ INPUT_BUTTON__MAX ] = {
 [ INPUT_BUTTON_LEFT ] = PS2_MOUSE_BUTTON_LEFT , [ INPUT_BUTTON_MIDDLE ] = PS2_MOUSE_BUTTON_MIDDLE , [ INPUT_BUTTON_RIGHT ] = PS2_MOUSE_BUTTON_RIGHT , [ INPUT_BUTTON_SIDE ] = PS2_MOUSE_BUTTON_SIDE , [ INPUT_BUTTON_EXTRA ] = PS2_MOUSE_BUTTON_EXTRA , }
 ;
 PS2MouseState * s = ( PS2MouseState * ) dev ;
 InputMoveEvent * move ;
 InputBtnEvent * btn ;
 if ( ! ( s -> mouse_status & MOUSE_STATUS_ENABLED ) ) return ;
 switch ( evt -> type ) {
 case INPUT_EVENT_KIND_REL : move = evt -> u . rel . data ;
 if ( move -> axis == INPUT_AXIS_X ) {
 s -> mouse_dx += move -> value ;
 }
 else if ( move -> axis == INPUT_AXIS_Y ) {
 s -> mouse_dy -= move -> value ;
 }
 break ;
 case INPUT_EVENT_KIND_BTN : btn = evt -> u . btn . data ;
 if ( btn -> down ) {
 s -> mouse_buttons |= bmap [ btn -> button ] ;
 if ( btn -> button == INPUT_BUTTON_WHEEL_UP ) {
 s -> mouse_dz -- ;
 }
 else if ( btn -> button == INPUT_BUTTON_WHEEL_DOWN ) {
 s -> mouse_dz ++ ;
 }
 }
 else {
 s -> mouse_buttons &= ~ bmap [ btn -> button ] ;
 }
 break ;
 default : break ;
 }
 }