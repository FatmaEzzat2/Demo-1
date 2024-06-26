#include "StopWatch.h"


#include<stdio.h>
 StopWatchTime_t current_time={
    .second = DEFAULT,
    .minute = DEFAULT,
    .hour   = DEFAULT
};

void STOPWATCH_Reset(void){
    current_time.second = DEFAULT;
    current_time.minute = DEFAULT;
    current_time.hour = DEFAULT;
}

void STOPWATCH_Update(void){

    
    static uint32_t Loc_u32CommanCounter = 0;
    Loc_u32CommanCounter += TICK_TIME;


    if (Loc_u32CommanCounter % TIME_ONE_SECOND == DEFAULT){
        current_time.second++;

        if ( current_time.second == NUM_OF_SCONDS){

            /*1- Reset Second Counter*/
             current_time.second =DEFAULT;

            /*2- Increament Minute Counter*/
            current_time.minute++;

            if(current_time.minute == NUM_OF_MINUTES){
                /*1- Reset Minute Counter*/
                 current_time.minute =DEFAULT;
                /*2- Increament Hour Counter*/
                current_time.hour++;

                if(current_time.hour == NUM_OF_HOURS){
                       /*1- Reset Hour Counter*/
                        current_time.hour =DEFAULT;
                }

            }
        }
         printf("H = %i\tM= %i\tS = %i",current_time.hour,current_time.minute,current_time.second);
    }
}
StopWatch_Error STOPWATCH_GetTime(StopWatchTime_t *time)
{
    StopWatch_Error ReturnError = StopWatch_enumOk;
    if(!time){
        ReturnError = StopWatch_NullPointer;
    }else{
        time->second =current_time.second;
        time->minute =current_time.minute;
        time->hour =current_time.hour;

    }
    return ReturnError;
}