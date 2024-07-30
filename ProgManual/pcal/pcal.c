/*pcal.c                                    Sun Feb 26 23:08:25 EST 1989*/



/*
 *Contents: One page per month calendar program.
 *
 *Author  : Troy Saville(evh@vax1.acs.udel.edu)
 *
 *Compiling: cc -o pcal pcal.c
 *
 *byebye     - make a clean exit from the program
 *getmmddyy  - get month,day,year of todays date(from the system)
 *isleapyear - determine if year is a leap year
 *jan1       - get day of week for 1st day of a year
 *dayofweek  - get day of week for any day of any year
 *genweek    - driver to print out one week of a month
 *genmonth   - driver to print out a complete month
 *main       - the pcal program
 *
 */






/*generate a calender, 1 month per page*/


#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


/*width of calendar, not including margin*/
#define NUMWIDTH 71
/*#of spaces to indent calendar*/
#define NUMINDENT 4

#define INDENT() printf("%-*.*s",NUMINDENT,NUMINDENT,spaces)

/*check for split sqaure on calendar*/
#define THESPLIT (weeknum == 5) && (endday < numdays) && (week[i]+7 <= numdays)


static char *spaces = "                                                   ";
static char *dashes = "-------------------------------------------------------------------------------";

static int daysinmonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

char *monthnames[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November",
                      "December"};

char *daynames[] = {"Sun" ,"Mon" ,"Tue" ,"Wed" ,"Thu" ,"Fri" ,"Sat" };


/*day of week that first day starts on*/
#define DAYSTART 0

/*first month to print out*/
#define MONSTART 0


/*exit the program cleanly - display error message*/
void byebye(fmt,a1,a2,a3,a4,a5,a6,a7)
   char *fmt;
   int a1,a2,a3,a4,a5,a6,a7;
   {
   if (fmt != NULL)
      {
      char tmp[80];
      sprintf(tmp,fmt,a1,a2,a3,a4,a5,a6,a7);
      printf(tmp);
      }
  
   printf("\n");
   printf("Usage: pcal [-l] [-m startmonth]\n");
   printf("            [-n nummonths] [-u] [-y startyear]\n");
   printf("       startmonth:day of month to start on(1=jan...12=dec)\n");
   printf("       startyear :year to start on(1989=1989, 89=0089)\n");
   printf("                  default startday=1, startmonth=1,\n");
   printf("                  startyear=current year\n");
   printf("       nummonths :#of months to print out(default is 12)\n");
   printf("       -l        :suppress printing of ^L's after each month\n");
   printf("                  default is to print them\n");
   printf("       -u        :print this synopsis\n");

   exit(0);
   }



/*get month,day,year of today date, year=89(mean actual year is 1989*/
void getmmddyy(month,day,year)
   int *month, *day, *year;
   {
   long clockval,time();
   struct tm *dateinfo,*localtime();

   clockval = time((long *) 0);

   dateinfo = localtime(&clockval);
   if (month)
     *month = dateinfo->tm_mon+1;
   if (day)
      *day = dateinfo->tm_mday;
   if (year)
      *year = dateinfo->tm_year;
   }




/******************************************************************************
 *isleapyear                                     Tue Oct 25, 1988 -> 21:42:56
 *
 *returns 1 if 'year' is a leap year else returns 0.
 *1988 should be passed as 1988 and not 88.
 */
int isleapyear(year)
   int year;
   {
   return((!(year % 4)) && (year % 100) ? 1 : 0);
   }


/*Return day of the week for Jan 1 of the specified year.*/
/*0=sunday....6=saturday*/
/*I ripped this out of someone elses program*/
/*author unknown*/
int jan1(year)
   int year;
   {
   int day;

   day = year + 4 + ((year + 3) / 4);     /* Julian Calendar      */
   if (year > 1800)                       /* If it's recent, do   */
      {
      day -= ((year - 1701) / 100);       /* Clavian correction   */
      day += ((year - 1601) / 400);       /* Gregorian correction */
      }
    if (year > 1752)                      /* Adjust for Gregorian */
      day += 3;                           /* calendar             */

   return (day % 7);
   }




/*return day of the week for the date passed in*/
/*month = 0-11, day is 1 based, year is assumed to be 4 digits*/
/*RETURN:0= sunday.....6=saturday*/
int dayofweek(month,day,year)
   int month,day,year;
   {
   int i;
   int dow = (-1);

   dow += day + jan1(year);

   for(i=0;i < month;i++)
      dow += daysinmonth[i] + ((i == 1) * isleapyear(year));

   return(dow % 7);
   }


/************************************************************************
 *genweek                                    Mon Feb 27 00:46:16 EST 1989
 * - generate calander for 1 week
 */
void genweek(week,weeknum,startday,daysinweek,numdays)
   int week[];     /*#of each day of week to be generated*/
   int weeknum;    /*week # for current month*/
   int startday;   /*starting day 
   int daysinweek; /*last day to be generated*/
   int numdays;    /*#days in month*/
   {
   int i;
   int row;
   int endday;

   if (weeknum > 5)
      return;

   endday = startday + daysinweek - 1;


   for(row=0;row < 5;row++)
      {
      INDENT();
      printf("|");

      for(i=0;i< 7;i++)
         {
         /*see if day of the week contains a day for this month*/
         if (week[i])
	 {
            switch(row)
               {
               case 0:
                  printf("%2d|    %s",week[i],
                         (THESPLIT) ? "_/" : "  ");
                  break;

               case 1:
                  printf("---  %s  ",(THESPLIT) ? "_/" : "  ");
                  break;

               case 2:
                  printf("   %s    ",(THESPLIT) ? "_/" : "  ");
                  break;

               case 3:
                  printf(" %s",(THESPLIT) ? "_/   ---" : "        ");
                  break;

               case 4:
                  if (THESPLIT)
                     printf("/     |%2d",week[i]+7);
                  else
                     printf("         ");
                  break;
               }
         }
         else /*this day of the week is in last month or next month*/
            printf("%-9.9s",spaces);
         printf("|");
         }

      printf("\n");
      }

   INDENT();
   printf("%-*.*s\n", NUMWIDTH, NUMWIDTH,dashes);
   }



/************************************************************************
 *genmonth                                   Sun Feb 26 23:21:30 EST 1989
 * - generate calander for 1 month
 */
void genmonth(month,year)
   int month;
   int year;
   {
   int i,j,k;
   int startday; /*day of week 1st day starts on*/
   int numdays;  /*#days in month*/
   int dow;      /*dat of week*/
   int weeknum = 1; /*# of the current week to print*/
   int week[7];

   i = (80 - strlen(monthnames[month])) / 2;

   printf("%-*.*s%-s\n\n",i,i,spaces,monthnames[month]);

   numdays = daysinmonth[month] + ((month==1) * isleapyear(year));

   startday = dayofweek(month,1,year);

   INDENT();
   printf("|   SUN   |   MON   |   TUE   |   WED   |   THU   |   FRI   |   SAT   |\n");
   INDENT();
   printf("%-*.*s\n", NUMWIDTH, NUMWIDTH,dashes);

   /*figure out first row*/
   /*first row of calander*/
   for(i=0,j=0;i < 7;i++)
      if (i >= startday)
         week[i] = ++j;
      else
         week[i] = 0;

   /*generate row for one week of calendar*/
   i = 7 - startday;
   genweek(week,weeknum,1,i,numdays);

   /*rest of calendar*/
   for(k=0; i < numdays;i += k,k=0)
      {
      for(j=0;j < 7;j++)
         if ((i+k) < numdays)
            week[j] = ++k + i;
         else
            week[j] = 0;
      if (k)
         genweek(week,++weeknum,i+1,k,numdays);
      }
   }



/**************************************************************************
 *main 
 * - main program
 *
 */
dispatch(argc,argv)
   int argc;
   char *argv[];
   {
   int i,j;
   int curmonth = 1;   /*current month of year*/
   int curyear;        /*current year*/
   int numday;         /*#of the day of the week*/
   int nummonths = 12; /*#of months to print out*/
   int controll = 0;   /*suppress printing of control L's 0=no, 1=yes*/


   /*set defaults*/
   getmmddyy(0,0,&curyear);
   curyear += 1900;

   /*parse command line args*/
   for(i=1;i<argc;i++)
      {
      if (argv[i][0] == '-')
      {
         switch(argv[i][1])
            {
            case 'm': /*day # of the week to start calander on*/
               if (++i == argc)
                  byebye("-m requires integer arguement");
               else if ( (sscanf(argv[i],"%d", &curmonth) != 1) ||
                         (curmonth < 1) || (curmonth > 12) )
                  byebye("Bad arg '%s' for -m flag\n", argv[i]);
               break;

            case 'n': /*#of months to print*/
               if (++i == argc)
                  byebye("-n requires integer arguement");
               else if ( (sscanf(argv[i],"%d", &nummonths) != 1) ||
                         (nummonths < 1) )
                  byebye("Bad arg '%s' for -n flag\n", argv[i]);
               break;

            case 'y': /*day # of the week to start calander on*/
               if (++i == argc)
                  byebye("-y requires integer arguement");
               else if (sscanf(argv[i],"%d", &curyear) != 1)
                  byebye("Bad arg '%s' for -y flag\n", argv[i]);
               break;

            case 'l': /*suppress ^L's*/
               controll = 1;
               break;

            case 'u': /*usage*/
               byebye(0);
               break;

            default: 
               byebye("Bad command line arguement: %s",argv[i]);
               break;
            }
      }
      else
         byebye("Bad command line arguement: %s",argv[i]);
      }

   curmonth--;


   /*loop through months*/
   for(;nummonths > 0;nummonths--, curmonth++)
      {
      if (curmonth == 12)
         {
         curmonth = 0;
         curyear++;
         }

      printf("\n\n\n%-*.*s%-4d\n\n",38,38,spaces,curyear);

      genmonth(curmonth,curyear);

      if (!controll)
         printf("       \014\n"); /*form feed to next page*/
      }


   }

/** A test method */
void main(int argc, char *argv[]) {
	
    if ( argc > 1 && strcmp("-", argv[1]) == 0 )
    {

        driver(atoi(argv[2]), argc, argv);
    }
    else
    {
        driver(0, argc, argv);
    }

}


