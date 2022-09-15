static void full_to_model_count ( unsigned int * model_count , unsigned int * full_count ) {
 int n ;
 model_count [ ZERO_TOKEN ] = full_count [ ZERO_TOKEN ] ;
 model_count [ ONE_TOKEN ] = full_count [ ONE_TOKEN ] ;
 model_count [ TWO_TOKEN ] = full_count [ TWO_TOKEN ] ;
 for ( n = THREE_TOKEN ;
 n < EOB_TOKEN ;
 ++ n ) model_count [ TWO_TOKEN ] += full_count [ n ] ;
 model_count [ EOB_MODEL_TOKEN ] = full_count [ EOB_TOKEN ] ;
 }