void _main(void) {
    if (oldint5) {
        //--------------------------------------
        // if TSR is already running, stop it
        // by restoring the old interrupt vector
        //--------------------------------------
        SetIntVec(AUTO_INT_5, oldint5);
        oldint5 = NULL;
    }
    else {    
        resettime = 1;
        oldint5 = GetIntVec(AUTO_INT_5);
        SetIntVec(AUTO_INT_5, myint5handler);
    }
}