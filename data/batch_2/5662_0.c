static void dumpmissingglyph ( SplineFont * sf , struct glyphinfo * gi , int fixedwidth ) {
 struct glyphhead gh ;
 BasePoint bp [ 10 ] ;
 uint8 instrs [ 50 ] ;
 int stemcvt , stem ;
 char * stempt ;
 stem = 0 ;
 if ( sf -> private != NULL && ( stempt = PSDictHasEntry ( sf -> private , "StdVW" ) ) != NULL ) stem = strtod ( stempt , NULL ) ;
 else if ( sf -> private != NULL && ( stempt = PSDictHasEntry ( sf -> private , "StdHW" ) ) != NULL ) stem = strtod ( stempt , NULL ) ;
 if ( stem <= 0 ) stem = ( sf -> ascent + sf -> descent ) / 30 ;
 gi -> pointcounts [ gi -> next_glyph ] = 8 ;
 gi -> loca [ gi -> next_glyph ++ ] = ftell ( gi -> glyphs ) ;
 gi -> maxp -> maxContours = 2 ;
 gh . numContours = 2 ;
 gh . ymin = 0 ;
 gh . ymax = 2 * ( sf -> ascent + sf -> descent ) / 3 ;
 gh . xmax = 5 * stem + ( sf -> ascent + sf -> descent ) / 10 ;
 gh . xmin = stem ;
 gh . xmax += stem ;
 if ( gh . ymax > sf -> ascent ) gh . ymax = sf -> ascent ;
 dumpghstruct ( gi , & gh ) ;
 bp [ 0 ] . x = stem ;
 bp [ 0 ] . y = 0 ;
 bp [ 1 ] . x = stem ;
 bp [ 1 ] . y = gh . ymax ;
 bp [ 2 ] . x = gh . xmax ;
 bp [ 2 ] . y = gh . ymax ;
 bp [ 3 ] . x = gh . xmax ;
 bp [ 3 ] . y = 0 ;
 bp [ 4 ] . x = 2 * stem ;
 bp [ 4 ] . y = stem ;
 bp [ 5 ] . x = gh . xmax - stem ;
 bp [ 5 ] . y = stem ;
 bp [ 6 ] . x = gh . xmax - stem ;
 bp [ 6 ] . y = gh . ymax - stem ;
 bp [ 7 ] . x = 2 * stem ;
 bp [ 7 ] . y = gh . ymax - stem ;
 if ( ! gi -> ttc_composite_font ) {
 stemcvt = TTF_getcvtval ( gi -> sf , stem ) ;
 instrs [ 0 ] = 0xb1 ;
 instrs [ 1 ] = 1 ;
 instrs [ 2 ] = 0 ;
 instrs [ 3 ] = 0x2f ;
 instrs [ 4 ] = 0x3c ;
 instrs [ 5 ] = 0xb2 ;
 instrs [ 6 ] = 7 ;
 instrs [ 7 ] = 4 ;
 instrs [ 8 ] = stemcvt ;
 instrs [ 9 ] = 0xe0 + 0x0d ;
 instrs [ 10 ] = 0x32 ;
 instrs [ 11 ] = 0xb1 ;
 instrs [ 12 ] = 6 ;
 instrs [ 13 ] = 5 ;
 instrs [ 14 ] = 0xc0 + 0x1c ;
 instrs [ 15 ] = 0x3c ;
 instrs [ 16 ] = 0xb2 ;
 instrs [ 17 ] = 3 ;
 instrs [ 18 ] = 2 ;
 instrs [ 19 ] = stemcvt ;
 instrs [ 20 ] = 0xe0 + 0x0d ;
 instrs [ 21 ] = 0x32 ;
 instrs [ 22 ] = 0x00 ;
 instrs [ 23 ] = 0xb1 ;
 instrs [ 24 ] = 3 ;
 instrs [ 25 ] = 0 ;
 instrs [ 26 ] = 0x2f ;
 instrs [ 27 ] = 0x3c ;
 instrs [ 28 ] = 0xb2 ;
 instrs [ 29 ] = 5 ;
 instrs [ 30 ] = 4 ;
 instrs [ 31 ] = stemcvt ;
 instrs [ 32 ] = 0xe0 + 0x0d ;
 instrs [ 33 ] = 0x32 ;
 instrs [ 34 ] = 0xb2 ;
 instrs [ 35 ] = 7 ;
 instrs [ 36 ] = 6 ;
 instrs [ 37 ] = TTF_getcvtval ( gi -> sf , bp [ 6 ] . y ) ;
 instrs [ 38 ] = 0xe0 + 0x1c ;
 instrs [ 39 ] = 0x3c ;
 instrs [ 40 ] = 0xb2 ;
 instrs [ 41 ] = 1 ;
 instrs [ 42 ] = 2 ;
 instrs [ 43 ] = stemcvt ;
 instrs [ 44 ] = 0xe0 + 0x0d ;
 instrs [ 45 ] = 0x32 ;
 }
 putshort ( gi -> glyphs , 4 - 1 ) ;
 putshort ( gi -> glyphs , 8 - 1 ) ;
 if ( ! gi -> ttc_composite_font ) dumpinstrs ( gi , instrs , 46 ) ;
 else dumpinstrs ( gi , NULL , 0 ) ;
 dumppointarrays ( gi , bp , NULL , 8 ) ;
 if ( fixedwidth <= 0 ) putshort ( gi -> hmtx , gh . xmax + 2 * stem ) ;
 else putshort ( gi -> hmtx , fixedwidth ) ;
 putshort ( gi -> hmtx , stem ) ;
 if ( sf -> hasvmetrics ) {
 putshort ( gi -> vmtx , sf -> ascent + sf -> descent ) ;
 putshort ( gi -> vmtx , gh . ymax ) ;
 }
 }