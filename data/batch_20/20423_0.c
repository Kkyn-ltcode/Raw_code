TEST_F ( ScoredHistoryMatchTest , Scoring ) {
 base : : Time now = base : : Time : : NowFromSystemTime ( ) ;
 history : : URLRow row_a ( MakeURLRow ( "http://fedcba" , "abcd bcd" , 3 , 30 , 1 ) ) ;
 RowWordStarts word_starts_a ;
 PopulateWordStarts ( row_a , & word_starts_a ) ;
 WordStarts one_word_no_offset ( 1 , 0u ) ;
 VisitInfoVector visits_a = CreateVisitInfoVector ( 3 , 30 , now ) ;
 visits_a [ 0 ] . second = ui : : PAGE_TRANSITION_TYPED ;
 ScoredHistoryMatch scored_a ( row_a , visits_a , ASCIIToUTF16 ( "abc" ) , Make1Term ( "abc" ) , one_word_no_offset , word_starts_a , false , nullptr , now ) ;
 history : : URLRow row_b ( MakeURLRow ( "http://abcdef" , "abcd bcd" , 10 , 30 , 1 ) ) ;
 RowWordStarts word_starts_b ;
 PopulateWordStarts ( row_b , & word_starts_b ) ;
 VisitInfoVector visits_b = CreateVisitInfoVector ( 10 , 30 , now ) ;
 visits_b [ 0 ] . second = ui : : PAGE_TRANSITION_TYPED ;
 ScoredHistoryMatch scored_b ( row_b , visits_b , ASCIIToUTF16 ( "abc" ) , Make1Term ( "abc" ) , one_word_no_offset , word_starts_b , false , nullptr , now ) ;
 EXPECT_GT ( scored_b . raw_score , scored_a . raw_score ) ;
 history : : URLRow row_c ( MakeURLRow ( "http://abcdef" , "abcd bcd" , 3 , 10 , 1 ) ) ;
 RowWordStarts word_starts_c ;
 PopulateWordStarts ( row_c , & word_starts_c ) ;
 VisitInfoVector visits_c = CreateVisitInfoVector ( 3 , 10 , now ) ;
 visits_c [ 0 ] . second = ui : : PAGE_TRANSITION_TYPED ;
 ScoredHistoryMatch scored_c ( row_c , visits_c , ASCIIToUTF16 ( "abc" ) , Make1Term ( "abc" ) , one_word_no_offset , word_starts_c , false , nullptr , now ) ;
 EXPECT_GT ( scored_c . raw_score , scored_a . raw_score ) ;
 history : : URLRow row_d ( MakeURLRow ( "http://abcdef" , "abcd bcd" , 3 , 30 , 3 ) ) ;
 RowWordStarts word_starts_d ;
 PopulateWordStarts ( row_d , & word_starts_d ) ;
 VisitInfoVector visits_d = CreateVisitInfoVector ( 3 , 30 , now ) ;
 visits_d [ 0 ] . second = ui : : PAGE_TRANSITION_TYPED ;
 visits_d [ 1 ] . second = ui : : PAGE_TRANSITION_TYPED ;
 visits_d [ 2 ] . second = ui : : PAGE_TRANSITION_TYPED ;
 ScoredHistoryMatch scored_d ( row_d , visits_d , ASCIIToUTF16 ( "abc" ) , Make1Term ( "abc" ) , one_word_no_offset , word_starts_d , false , nullptr , now ) ;
 EXPECT_GT ( scored_d . raw_score , scored_a . raw_score ) ;
 history : : URLRow row_e ( MakeURLRow ( "http://csi.csi.csi/csi_csi" , "CSI Guide to CSI Las Vegas, CSI New York, CSI Provo" , 3 , 30 , 3 ) ) ;
 RowWordStarts word_starts_e ;
 PopulateWordStarts ( row_e , & word_starts_e ) ;
 const VisitInfoVector visits_e = visits_d ;
 ScoredHistoryMatch scored_e ( row_e , visits_e , ASCIIToUTF16 ( "csi" ) , Make1Term ( "csi" ) , one_word_no_offset , word_starts_e , false , nullptr , now ) ;
 EXPECT_LT ( scored_e . raw_score , 1400 ) ;
 ScoredHistoryMatch scored_f ( row_a , visits_a , ASCIIToUTF16 ( "cd" ) , Make1Term ( "cd" ) , one_word_no_offset , word_starts_a , false , nullptr , now ) ;
 EXPECT_EQ ( scored_f . raw_score , 0 ) ;
 }