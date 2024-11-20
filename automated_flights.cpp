#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<math.h>
#include<windows.h>

//AIR FRANCE FLIGHT 331
//TYPE: AIRBUS: A350
//START OF WEATHER FUNCTIONS

//START OF FILING FUNCTIONS
int i;
double way[8]; //global declaration

// haversien distance formulae
double *distance(double lt[8],double lo[8])
{
double a,b,c,d,po1,po2;
double lat,lon,r1,r2;
double pi=22/7;
int R=6371;
double ltt=43.61,lot=-77.97;
lot=lot * (pi/180);
ltt=ltt * (pi/180);
for(i=0;i<7;i++)
{
 r1=0;r2=0;lat=0;lon=0;
//*convert to radians*//
r1=lt[i]*(pi/180);
r2=lo[i]*(pi/180);

//*find difference of both longitude and latitude*//
lat=ltt-r1;
lon=lot-r2;

//*sin square*//
po1=pow(sin(lat/2),2);
po2=pow(sin(lon/2),2);

//*haversien formulae*//
a=po1+cos(ltt)*cos(r1)*po2;
c=2*atan2(sqrt(a),sqrt(1-a));
way[i]=R*c;
}
way[6]=way[6]+399;


return way;
}
//END OF FILING FUNCTIONS

//START OF WEATHER FUNCTIONS
struct weather 
{
   char col; //color
   char opt[4]; //ans for alt path or e.descent
   float temph; //for tti formula
  float dew;//for tti formula
  float	templ;//for tti formula
  float tti;//for tti formula
   char ans2;
	
};
//RANDOM FUNCTIONS

//random for midflight altitude
int printRandoms(int lower, int upper, int count)
 
{ 
    int i,num;
    for (i = 0; i < count; i++)
	 { 

        num = (rand() % (upper - lower + 1)) + lower;  
		} 
		return num; 
} 

 int mid_flightp()
{

    int lower = 30000, upper = 37000, count = 1; 
 
    srand(time(0)); 
 
	printRandoms(lower, upper, count); 
 
}

 int mid_flightn()
{

    int lower = 20000, upper = 28000, count = 1; 
 
    srand(time(0)); 
 
	printRandoms(lower, upper, count); 
 
}
//end of midflight function

//Random function for co-ordinates in midflight
float printRandoms1(int lower, int upper, int count)
{ 
    int i;
	float num;
    for (i = 0; i < count; i++)
	 { 

        num = (rand() % (upper - lower + 1)) + lower;  
		} 
		return num; 
} 
//START LATITUDE
float coord1()
{
	 float lower = 51.329, upper=54.300 , count =1; 
 
    srand(time(0)); 
 
	printRandoms1(lower, upper, count);
}
float coord2()
{
	 int lower = 56.354, upper = 60.785, count =1; 
 
    srand(time(0)); 
 
	printRandoms1(lower, upper, count);
}
float coord3()
{
	 int lower = 50.329, upper =54.543, count =1; 
 
    srand(time(0)); 
 
	printRandoms1(lower, upper, count);
}
//END LATITUDE
//----------------------------------------------------------
//START LONGITUDE
float cord1()
{
	 int lower = -23.14, upper =-21.43, count =1; 
 
    srand(time(0)); 
 
	printRandoms1(lower, upper, count);
}
float cord2()
{
	 int lower = -28.329, upper =-24.543, count =1; 
 
    srand(time(0)); 
 
	printRandoms1(lower, upper, count);
}
float cord3()
{
	 int lower = -23.329, upper =-21.543, count =1; 
 
    srand(time(0)); 
 
	printRandoms1(lower, upper, count);
}
//END LONGITUDE
//End of coordinates random function


//Midflight temperature random function
int tempmid()
{
	 int lower = -100, upper = -40, count =1; 
 
    srand(time(0)); 
 
	printRandoms(lower, upper, count); 
 

}
//end of midflight temp random function
 
//random function for TTI variables
//random for dewpoint
int dew()
{
	int lower = 0, upper = 15, count =1; 
 
    srand(time(0)); 
 

	printRandoms(lower, upper, count); 
  
}
//end of dew
//random function for temph
int temph()
{
	int lower =70 , upper = 100, count =1; 
 
    srand(time(0)); 
 

	printRandoms(lower, upper, count); 
 

}
//random function for templ
int templ()
{
int lower =0 , upper = 50, count =1; 
 
    srand(time(0)); 
 

	printRandoms(lower, upper, count); 
 
}
//END OF TTI VARIABLES

//FORMULA OF TTI
//formula for TTI 
int formula()
{
    struct weather w;
    w.temph=temph();
    w.templ=templ();
    w.dew=dew();
  
  w.tti=w.temph+w.dew-(2*w.templ);
  
  
  return w.tti;
  
}
//END OF WEATHER FUNCTIONS

//EMERGENCY LANDINGS FUNCTION
int airport_d()
{

    int lower = 50, upper =760 , count = 1; 
 
    srand(time(0)); 
 
	printRandoms(lower, upper, count); 
 
}
// END OFEMERGENCY LANDINGS FUNCTION


//START OF NAVI FUNCTIONS
int alt()
{
	int d=2.9,t=2,v=120,ft=0;
	printf("Flight has taken off\n\n");
	for (int i=0;i<6;i++)
	{
		printf("    Time  :  %d min\n",t);    //time interval until it reaches midflight
		printf("-----------------------\n");
		printf(" Distance :  %d km\n",d);
		printf(" Altitude :  %d ft\n",ft);
		printf(" Velocity :  %d km/h\n",v);
		printf("-----------------------\n");
		d=d+1;
		t=t+2;
		ft=ft+5600;
		v=v+120;
		sleep(2);
	}
}

int endem()
{
	int d=160,t=4,v=150,ft=30000,t1=30;
	printf("\nPREPARE FOR EMERGENCY LANDING\n\n");
	sleep(1);
	for (int i=0;i<6;i++)
	{  
        //t1=t1-6;
		printf("    Time  :  %d min\n",t1);    //time interval until it reaches midlanding
		printf("-----------------------\n");
		printf(" Distance :  %d km\n",d);
		printf(" Altitude :  %d ft\n",ft);
		printf(" Velocity :  %d km/h\n",v);
		printf("-----------------------\n");
		Beep(450,300);
		d=d-32;
		t1=t1-6;
		ft=ft-6000;
		v=v+60;

		sleep(2);
	}
}

int end()
{
	int d=160,t=4,v=150,ft=30000,t1=30;
	printf("Pilot: Air France-331 entering Left downwind Runway L24\nATC:");
	sleep(1);
	char ATC[30];
	gets(ATC);
	for (int i=0;i<3;i++)
	{
		printf("    Time  :  %d min\n",t1);    //time interval until it reaches midlanding
		printf("-----------------------\n");
		printf(" Distance :  %d km\n",d);
		printf(" Altitude :  %d ft\n",ft);
		printf(" Velocity :  %d km/h\n",v);
		printf("-----------------------\n");
		if(d==80)
		{
			break;
		}
		d=d-40;
		t1=t1-t;
		t=t-2;
		ft=ft-3000;
		v=v+25;
		sleep(2);
	}
	for (int i=0;i<5;i++)
	{  
        //t1=t1-6;
		printf("    Time  :  %d min\n",t1);    //time interval until it reaches midlanding
		printf("-----------------------\n");
		printf(" Distance :  %d km\n",d);
		printf(" Altitude :  %d ft\n",ft);
		printf(" Velocity :  %d km/h\n",v);
		printf("-----------------------\n");
		d=d-20;
		t1=t1-6;
		ft=ft-6000;
		v=v+25;

		sleep(2);
	}
}
//END OF NAVI FUNCTIONS
//END OF FUNCTIONS



//INT MAIN




int main()
{//FILING AND POINTERS AND ARRAYS
   double lt[8],lo[8],*dis;
   FILE *ptr;
   ptr= fopen ("WAYPOINTS.txt","r");
if ( ptr == NULL )
{
printf( "File could not be opened\n" );

}
// extracting longitude and latitude//
for(i=0;i<7;i++)
{
 fscanf(ptr,"%lf%lf",&lt[i],&lo[i]);
}
fclose(ptr);
// pointer//
dis = distance(lt,lo);
//END OF FILING 
//---------------------------------------------------------------------------------------------
//TAKE OFF DEPARTURE
	char ATC[30];
	printf("Pilot: Pearson tower, Air France Flight 331, Runaway L24,"
	"ready to take off"
	"\nATC:");
	gets(ATC);
	printf("\ncleared for takeoff runaway L24, Air France 331");
	sleep(1);
	
	alt();//Take off
	
	//WAYPOINT DELMA
	printf("\n----------------------------------------------------------------------");
	printf("\nAir France-331 has approached waypoint Delma ");
	printf("\ndistance traveled=%lf",*(dis+0));
    printf("\ndistance left=%lf",6000-*(dis+0));
	printf("\n----------------------------------------------------------------------");
	sleep(3);
	
	//WAYPOINT RUDOLF
	printf("\n----------------------------------------------------------------------");
	printf("\nAir France-331 has approached waypoint Rudolf ");
	printf("\ndistance traveled=%lf",*(dis+1));
    printf("\ndistance left=%lf",6000-*(dis+1));
	printf("\n----------------------------------------------------------------------");
      sleep(2);
      
      
	//MIDFLIGHT WEATHER
		//Thunderstorms
	printf("\nAir France-331 has reached level mid flight");
	sleep(3);
	//WAYPOINT PARAMOUNT
	printf("\n----------------------------------------------------------------------");
	printf("\nAir France-331 has approached waypoint paramount ");
	printf("\ndistance traveled=%lf",*(dis+2));
    printf("\ndistance left=%lf",6000-*(dis+2));
	printf("\n----------------------------------------------------------------------");
	sleep(2);	
	printf("\nwe will begin assessing the weather conditions "
	"for a possible thunderstorms \n");
	printf("current altitude:%d",mid_flightp());
	sleep(1);
	
	struct weather w;
	int TTI=formula();
	printf("\n----------------------------------------------------------------");
	printf("\n The TTP index is: %d \n",TTI);
	printf("\n----------------------------------------------------------------");
	sleep(2);
	//conditions for TTI
	if(TTI<44)
  {
  	printf("\n Convection not likely");
  	printf("\n-----------------------------------------------------------------------------------");
  }
  else if(TTI>=44&&TTI<=50)
  {
  	printf("\n Likely thunderstorms");
  	printf("\n------------------------------------------------------------------------------------");
  }
  else if(TTI>=51&&TTI<=52)
  {
  	printf("\nIsolated severe");
  	printf("\n------------------------------------------------------------------------------------");
  }
  else if(TTI>56||TTI>=53&&TTI<56)
  {
  	//REQUEST FOR ATC PERMISIION (mandatory)
  	printf("\nScattered severe storms or "
	  "widely scattered storms");
	  printf("\n----------------------------------------------------------------------------------------");
  	printf("\n \n  Air France-331 Request ATC for a "
	  "mandatory emergency descent (ED) "
	  "or request for a alternative path(AP)");
		scanf("%s",w.opt);
		char ed[3]={"ED"};
		char ap[3]={"AP"};
		
		if(strcmp(w.opt,ed)==0)
		{
			//use random function to show 
			//decrease in altitude
			printf("\n------------------------------------------------------------------------------------\n");
			printf("\nAn emergency descent will be performed.");
			printf("\n------------------------------------------------------------------------------------\n");
			printf("\n Previous altitude:%d",mid_flightp());
			printf("\n New altitude:%d",mid_flightn());
			printf("\n-------------------------------------------------------------------------------------\n");
		}
		else if(strcmp(w.opt,ap)==0)
		{
			float lat=50.329,log=-20.14;
			//show change in coordinates
			printf("\n--------------------------------------------------------------------------------\n");
			printf("\norignal co-ordinates: Latitude=%f   Longitude=%f",lat,log);
			sleep(2);
			printf("\nnew co-ordinates: Latitude=%f   Longitude=%f",coord1(),cord1());
			sleep(2);
			printf("\nnew co-ordinates: Latitude=%f   Longitude=%f",coord2(),cord2());
			sleep(2);
			printf("\nnew co-ordinates: Latitude=%f   Longitude=%f",coord3(),cord3());
		    printf("\n---------------------------------------------------------------------------------\n");
	  
  }
  else
  {
  	printf("\n invalid input");
  	
  }
  
  //WAYPOINT CALLOC
	printf("\n----------------------------------------------------------------------");
	printf("\nAir France-331 has approached waypoint Calloc ");
	printf("\ndistance traveled=%lf",*(dis+3));
    printf("\ndistance left=%lf",6000-*(dis+3));
	printf("\n----------------------------------------------------------------------");
	sleep(2);
  
  //COLD TEMPERATURE
  printf("\n The temperature will be analysed now for peto tubes "
  "that are the speed sensors");
  printf("\n-----------------------------------------------------------------------------------------");
  printf("\n current altitude: %d",mid_flightp());
  printf("\n-----------------------------------------------------------------------------------------");
  
  int petotemp=tempmid();
  char speed[30]={"52@#$%^&*(!@#!@##"};
     if(petotemp<-48)
     {
     	printf("\n\nAnalysis: Temperature is such that peto tubes have been frozen");
     	sleep(2);
     	printf("\nThe Autopilot is recieving garbage values \nspeed=%s",speed);
     	printf("\nERROR---"
		 "\n\nThe Auto-pilot cannot work with garbage values."
		 "the manual control of the plane is handed to the pilots\n");
		 sleep(2);
		printf("\nAir France-331 Request for change in altitude to reach 'Y' for Yes 'N' for No ");  
		scanf(" %c",&w.ans2);
		if(w.ans2=='Y')
		{
		//WAYPOINT TOPAZ	
    		printf("\n----------------------------------------------------------------------");
	   	 	printf("\nAir France-331 has approached waypoint Topaz ");
			printf("\ndistance traveled=%lf",*(dis+4));
    		printf("\ndistance left=%lf",6000-*(dis+4));
			printf("\n----------------------------------------------------------------------");
			sleep(2);
		
			printf("previous altitude= %d",mid_flightp());
			printf("\n new altitude= %d. Maintain flight level",mid_flightn());
			printf("\n\n-------------------------------------------------------------------------");
			sleep(2);
		}
		else
		{
			
		//WAYPOINT AZURE	
    		printf("\n----------------------------------------------------------------------");
	   	 	printf("\nAir France-331 has approached waypoint Azure ");
			printf("\ndistance traveled=%lf",*(dis+4));
    		printf("\ndistance left=%lf",6000-*(dis+4));
			printf("\n----------------------------------------------------------------------");
			sleep(2);
		printf("\nPlane will continue to fly at the same altitude manually until the heating system unfreez"
		"the peto tube sensors");
		
		}
	 }
}
//END OF MID WEATHER FLIGHT
  //EMERGENCY
  int a,c,d;
  srand(time(0));
	a=rand() % 5;
	c=rand () % 4; 
	d=rand () % 6;


	printf("------------------------------------------------------------------------\n");
	switch(a)
	{
		case 0:
			{
				
		//WAYPOINT PRIME	
    		printf("\n----------------------------------------------------------------------");
	   	 	printf("\nAir France-331 has approached waypoint Prime ");
			printf("\ndistance traveled=%lf",*(dis+4));
    		printf("\ndistance left=%lf",6000-*(dis+4));
			printf("\n----------------------------------------------------------------------");
			sleep(2);
			
				printf ("\nWe will have a normal landing\n");
				end();
				sleep(1);
					printf("Air France Flight-331 has touched down");
				break;
		}
		case 1:
	       {
	       	
		//WAYPOINT PRIME	
    		printf("\n----------------------------------------------------------------------");
	   	 	printf("\nAir France-331 has approached waypoint Prime ");
			printf("\ndistance traveled=%lf",*(dis+5));
    		printf("\ndistance left=%lf",6000-*(dis+5));
			printf("\n----------------------------------------------------------------------");
			sleep(2);
			
			        for(int i=0;i<3;i++)
				{
				printf("\nWARNING\n");
				Beep (450, 300);
				sleep(1);
				}
	       	    break;
	       	    printf ("\n!MAYDAY MAYDAY There is an engine birdsrtike!\n");
	       	   
		}	
		case 2:
			{
				
		//WAYPOINT PRIME
    		printf("\n----------------------------------------------------------------------");
	   	 	printf("\nAir France-331 has approached waypoint Prime ");
			printf("\ndistance traveled=%lf",*(dis+5));
    		printf("\ndistance left=%lf",6000-*(dis+5));
			printf("\n----------------------------------------------------------------------");
			sleep(2);
			
				        for(int i=0;i<3;i++)
			{
			printf("\nWARNING\n");
			Beep (450, 300);
			sleep(1);
			}
				printf ("\n!MAYDAY MAYDAY The plane has ran out of fuel!\n");
		
				break;
		}
		case 3:
			{
		//WAYPOINT PRIME	
    		printf("\n----------------------------------------------------------------------");
	   	 	printf("\nAir France-331 has approached waypoint Prime ");
			printf("\ndistance traveled=%lf",*(dis+5));
    		printf("\ndistance left=%lf",6000-*(dis+5));
			printf("\n----------------------------------------------------------------------");
			sleep(2);
			
				        for(int i=0;i<3;i++)
			{
			printf("\nWARNING\n");
			Beep (450, 300);
			sleep(1);
			}
				printf ("\n!MAYDAY MAYDAY There is an engine flameout in the plane!\n");
		
				break;
		}
		case 4:
			{
		//WAYPOINT PRIME	
    		printf("\n----------------------------------------------------------------------");
	   	 	printf("\nAir France-331 has approached waypoint Prime ");
			printf("\ndistance traveled=%lf",*(dis+5));
    		printf("\ndistance left=%lf",6000-*(dis+5));
			printf("\n----------------------------------------------------------------------");
			sleep(2);
			
				        for(int i=0;i<3;i++)
			{
			printf("\nWARNING\n");
			Beep (450, 300);
			sleep(1);
			}
				printf ("\n!MAYDAY MAYDAY The plane is acting as a glider!\n");
		
				break;
		}
	    case 5:
			{
		//WAYPOINT PRIME	
    		printf("\n----------------------------------------------------------------------");
	   	 	printf("\nAir France-331 has approached waypoint Prime ");
			printf("\ndistance traveled=%lf",*(dis+5));
    		printf("\ndistance left=%lf",6000-*(dis+5));
			printf("\n----------------------------------------------------------------------");
			sleep(2);
			
			        for(int i=0;i<3;i++)
			{
			printf("WARNING\n");
			Beep (450, 300);
			sleep(1);
			}
				printf ("\n!MAYDAY MAYDAY The plane is having an engine failure!\n");
			
				break;
		}
		case 6:
			{
		//WAYPOINT PRIME	
    		printf("\n----------------------------------------------------------------------");
	   	 	printf("\nAir France-331 has approached waypoint Prime ");
			printf("\ndistance traveled=%lf",*(dis+5));
    		printf("\ndistance left=%lf",6000-*(dis+5));
			printf("\n----------------------------------------------------------------------");
			sleep(2);
			
			    for(int i=0;i<3;i++)
			{
			printf("WARNING\n");
			Beep (450, 300);
			sleep(1);
			}
				printf ("\nThe plane is stalling\n");  //either high altitude or low altitude
			

				break;                                      //QUERY
		}
	}
	printf("------------------------------------------------------------------------\n");
	
	if(a == 1 || a==2 || a==3 || a==4 || a==5 || a==6 )
	{
		int z=airport_d(); 
		if (z<=720)  // plane is near from the area where it departed
		 {
		 	
		//WAYPOINT OUTFR	
    		printf("\n----------------------------------------------------------------------");
	   	 	printf("\nAir France-331 has approached waypoint Outfr ");
			printf("\ndistance traveled=%lf",*(dis+6));
    		printf("\ndistance left=%lf",6000-*(dis+6));
			printf("\n----------------------------------------------------------------------");
			sleep(2);
			
		 	printf ("\nThe plane will go around and make emergency landing at nearest airport");
		 	sleep(1);
		 	endem();
		 	sleep(1);
		 	printf("Air France Flight-331 has touched down");
		}
		 else if(c==1 && d==3) //C ==1 SIGNIFYS motorway and D==3 less populated
		 {
		 	
		//WAYPOINT OUTFR	
    		printf("\n----------------------------------------------------------------------");
	   	 	printf("\nAir France-331 has approached waypoint Outfr ");
			printf("\ndistance traveled=%lf",*(dis+6));
    		printf("\ndistance left=%lf",6000-*(dis+6));
			printf("\n----------------------------------------------------------------------");
			sleep(2);
			
            printf ("motorway / highway less populated\n");		 
		    printf ("Air France 331 will perform a emergency landing on nearest motorway highway");
		    sleep(1);
		    endem();
		    sleep(1);
		    printf("Air France Flight-331 has touched down");
		 } 
		  else if(c==2 && d==1) //c==2 field and d==1 field is very vast
		  {	
		//WAYPOINT OUTFR	
    		printf("\n----------------------------------------------------------------------");
	   	 	printf("\nAir France-331 has approached waypoint Outffr ");
			printf("\ndistance traveled=%lf",*(dis+6));
    		printf("\ndistance left=%lf",6000-*(dis+6));
			printf("\n----------------------------------------------------------------------");
			sleep(2);
			
		  	printf ("field is very vast\n");
		  	printf ("\nAir France 331 will perform a emergency landing on a field");
		  	sleep(1);
		  	endem();
		  	printf("Air France Flight-331 has touched down");
		  	sleep(1);
		   }
		   else if(c==3 && d==4) //c==3 water bodies and d==4 dense and densly populated
		  {
		  	
		//WAYPOINT OUTFR	
    		printf("\n----------------------------------------------------------------------");
	   	 	printf("\nAir France-331 has approached waypoint Outfr ");
			printf("\ndistance traveled=%lf",*(dis+6));
    		printf("\ndistance left=%lf",6000-*(dis+6));
			printf("\n----------------------------------------------------------------------");
			sleep(2);
			
		  	printf("water body is densly populated\n");
		  	printf ("\nAir France 331 will perform a emergency landing on water bodies");
		  	sleep(1);
		  	endem();
		  	sleep(1);
		  	printf("Air France Flight-331 has touched down");
		   }
		   else if(c==4) // c==4 populated
		  {
		  	if(d==2)
		  	{
		//WAYPOINT OUTFR	
    		printf("\n----------------------------------------------------------------------");
	   	 	printf("\nAir France-331 has approached waypoint Outfr ");
			printf("\ndistance traveled=%lf",*(dis+6));
    		printf("\ndistance left=%lf",6000-*(dis+6));
			printf("\n----------------------------------------------------------------------");
			sleep(2);
		  		printf ("Air France 331 is ditching in river\n");
		  		sleep(1);
		  		endem();
		  		sleep(1);
		  		printf("Air France Flight-331 has touched down");
			  }
			  else  {
		//WAYPOINT OUTFR	
    		printf("\n----------------------------------------------------------------------");
	   	 	printf("\nAir France-331 has approached waypoint Outfr ");
			printf("\ndistance traveled=%lf",*(dis+6));
    		printf("\ndistance left=%lf",6000-*(dis+6));
			printf("\n----------------------------------------------------------------------");
			sleep(2);
			  	printf("Air France 331 is ditching in ocean\n");
			sleep(1);
			endem();	
			sleep(1);
			printf("Air France Flight-331 has touched down");
			  }
		   }
	}	
	//END OF EMERGENCY
  
  

}
