/********************************************************
 *                                                      *
 *                                                      *
 *      user_sm.h			          	*
 *                                                      *
 *							*
 *		FI-UNAM					*
 *		17-2-2019                               *
 *                                                      *
 ********************************************************/



// State Machine 
void user_sm(float intensity, float *light_values, float *observations, int size, float laser_value, int  dest, int obs , movement *movements  ,int *next_state ,float Mag_Advance ,float max_twist)
{

 int state = *next_state;
 int i;

 printf("intensity %f\n",intensity);
 printf("quantized destination %d\n",dest);
 printf("quantized obs %d\n",obs);

 for(int i = 0; i < 8; i++)
        printf("light_values[%d] %f\n",i,light_values[i]);
 for (int i = 0; i < size ; i++ ) 
         printf("laser observations[%d] %f\n",i,observations[i]);


 switch ( obs ) {

        case 0:{



int flg_result = light_follower(intensity,light_values,movements,Mag_Advance,max_twist);
                if(flg_result == 1) stop();
	break;
	}
        case 1:{
	if(observations[4]==0.05f)
	  *movements=generate_output(FORWARD,Mag_Advance,max_twist);
	else
	  *movements=generate_output(LEFT,Mag_Advance,max_twist/10);
	break;	
	}
 	case 2:{
	*movements=generate_output(LEFT,Mag_Advance,max_twist);
	break;		
	}
        case 3:{
	*movements=generate_output(LEFT,Mag_Advance,max_twist);        
	break;       
	}

	default:{
                
		if(observations[4]==0.05&&obs==1)
		{
		printf("hacia adelante");
		  *movements=generate_output(FORWARD,Mag_Advance,max_twist);
		}
		else
		  *movements=generate_output(LEFT,Mag_Advance,max_twist/10);
		break;
}
                
 }

 printf("Next State: %d\n", *next_state);


}



                 
