static hb_unicode_general_category_t hb_icu_unicode_general_category ( hb_unicode_funcs_t * ufuncs HB_UNUSED , hb_codepoint_t unicode , void * user_data HB_UNUSED ) {
 switch ( u_getIntPropertyValue ( unicode , UCHAR_GENERAL_CATEGORY ) ) {
 case U_UNASSIGNED : return HB_UNICODE_GENERAL_CATEGORY_UNASSIGNED ;
 case U_UPPERCASE_LETTER : return HB_UNICODE_GENERAL_CATEGORY_UPPERCASE_LETTER ;
 case U_LOWERCASE_LETTER : return HB_UNICODE_GENERAL_CATEGORY_LOWERCASE_LETTER ;
 case U_TITLECASE_LETTER : return HB_UNICODE_GENERAL_CATEGORY_TITLECASE_LETTER ;
 case U_MODIFIER_LETTER : return HB_UNICODE_GENERAL_CATEGORY_MODIFIER_LETTER ;
 case U_OTHER_LETTER : return HB_UNICODE_GENERAL_CATEGORY_OTHER_LETTER ;
 case U_NON_SPACING_MARK : return HB_UNICODE_GENERAL_CATEGORY_NON_SPACING_MARK ;
 case U_ENCLOSING_MARK : return HB_UNICODE_GENERAL_CATEGORY_ENCLOSING_MARK ;
 case U_COMBINING_SPACING_MARK : return HB_UNICODE_GENERAL_CATEGORY_SPACING_MARK ;
 case U_DECIMAL_DIGIT_NUMBER : return HB_UNICODE_GENERAL_CATEGORY_DECIMAL_NUMBER ;
 case U_LETTER_NUMBER : return HB_UNICODE_GENERAL_CATEGORY_LETTER_NUMBER ;
 case U_OTHER_NUMBER : return HB_UNICODE_GENERAL_CATEGORY_OTHER_NUMBER ;
 case U_SPACE_SEPARATOR : return HB_UNICODE_GENERAL_CATEGORY_SPACE_SEPARATOR ;
 case U_LINE_SEPARATOR : return HB_UNICODE_GENERAL_CATEGORY_LINE_SEPARATOR ;
 case U_PARAGRAPH_SEPARATOR : return HB_UNICODE_GENERAL_CATEGORY_PARAGRAPH_SEPARATOR ;
 case U_CONTROL_CHAR : return HB_UNICODE_GENERAL_CATEGORY_CONTROL ;
 case U_FORMAT_CHAR : return HB_UNICODE_GENERAL_CATEGORY_FORMAT ;
 case U_PRIVATE_USE_CHAR : return HB_UNICODE_GENERAL_CATEGORY_PRIVATE_USE ;
 case U_SURROGATE : return HB_UNICODE_GENERAL_CATEGORY_SURROGATE ;
 case U_DASH_PUNCTUATION : return HB_UNICODE_GENERAL_CATEGORY_DASH_PUNCTUATION ;
 case U_START_PUNCTUATION : return HB_UNICODE_GENERAL_CATEGORY_OPEN_PUNCTUATION ;
 case U_END_PUNCTUATION : return HB_UNICODE_GENERAL_CATEGORY_CLOSE_PUNCTUATION ;
 case U_CONNECTOR_PUNCTUATION : return HB_UNICODE_GENERAL_CATEGORY_CONNECT_PUNCTUATION ;
 case U_OTHER_PUNCTUATION : return HB_UNICODE_GENERAL_CATEGORY_OTHER_PUNCTUATION ;
 case U_MATH_SYMBOL : return HB_UNICODE_GENERAL_CATEGORY_MATH_SYMBOL ;
 case U_CURRENCY_SYMBOL : return HB_UNICODE_GENERAL_CATEGORY_CURRENCY_SYMBOL ;
 case U_MODIFIER_SYMBOL : return HB_UNICODE_GENERAL_CATEGORY_MODIFIER_SYMBOL ;
 case U_OTHER_SYMBOL : return HB_UNICODE_GENERAL_CATEGORY_OTHER_SYMBOL ;
 case U_INITIAL_PUNCTUATION : return HB_UNICODE_GENERAL_CATEGORY_INITIAL_PUNCTUATION ;
 case U_FINAL_PUNCTUATION : return HB_UNICODE_GENERAL_CATEGORY_FINAL_PUNCTUATION ;
 }
 return HB_UNICODE_GENERAL_CATEGORY_UNASSIGNED ;
 }