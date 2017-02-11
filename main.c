#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    
    unsigned int max = atoi(argv[1]);
   
    unsigned int div_count,j, reel_div_count, divisor;
    int count = 0;

    //time var
    double timeStart, timeEnd, Texec, i;
    struct timeval tp;

    //start time
    gettimeofday(&tp, NULL);
    timeStart = (double) (tp.tv_sec) + (double) (tp.tv_usec) / 1e6;
    
    //there's no number that has 8 divisor under 24

    if (max < 24){

	count = 0;	    
    }
    
    //iterate between min to max
    //optimize loop by going 100 to 1 instead of the inverse
    else {

	  //start iteration at 24 because no other number under 24 has 8 divisors
	  for(i=24 ; i <= max; i++){
		    
    
       	 //check if current number has height divisors. Actually, check for 6
	 //because a number will always has 1 and itself as divisor.
	 //I used the math rule to find more quickly how many divisors a number has.
	 //Ex: number/ 2^n /3^n /5^n ...  (n2+1)*(n3+1)*(n5+1)=number of divisors
        	 div_count = 0;
        	 divisor = 2;
		 j = i;
		 reel_div_count = 1;


       		 while(divisor <= i && j !=1)
        	{
			//find the first prime number divisor of "i"
			//then divide "j" by divisor until its no longer divisible
			//take count each time "j" is divided by divisor
           		 while (j % divisor == 0){
				j = j / divisor; 
                		div_count ++; 
            		}
		 	if (div_count == 0 ){
				divisor ++;
			}

			//take the count and add 1 and multiply it to reel_div_count
			//to find the reel number of divisors
			else { 
				div_count ++;
			    	reel_div_count = reel_div_count * div_count;
				div_count = 0;

				//End loop more quickly if a number has more than
				//8 divisors
			       	if (reel_div_count > 8){
					divisor = i+1;
				}
				else{
					divisor ++;
				}
			}
        	}
       
        	if(reel_div_count == 8)
        	{
            		count ++;
        	}
	  }
    }

    //end timer
    gettimeofday(&tp, NULL);
    timeEnd = (double) (tp.tv_sec) + (double) (tp.tv_usec) / 1e6;
    Texec = timeEnd - timeStart;
    printf("\nExecution time : %f seconds", Texec);
    
    printf("\nCount : %d\n", count);
    
   
    return 0;    
}
