static int get_pid_priority ( pid_t pid ) {
 struct sched_param par ;
 sched_getparam ( pid , & par ) ;
 return par . sched_priority ;
 }