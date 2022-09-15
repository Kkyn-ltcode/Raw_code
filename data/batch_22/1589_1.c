int arm_cpu_caps ( void ) {
 int flags ;
 int mask ;
 if ( ! arm_cpu_env_flags ( & flags ) ) {
 return flags ;
 }
 mask = arm_cpu_env_mask ( ) ;
 # if HAVE_EDSP flags |= HAS_EDSP ;
 # endif # if HAVE_MEDIA flags |= HAS_MEDIA ;
 # endif # if HAVE_NEON flags |= HAS_NEON ;
 # endif return flags & mask ;
 }