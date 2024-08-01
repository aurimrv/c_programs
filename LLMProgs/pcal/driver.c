
#include <stdio.h>


void driver(int tc_number, int argc, char *argv[])
{
int i;

    switch (tc_number)
    {
        case 0:
            dispatch(argc,argv);
            break;
        case 1:
            byebye("%d %d %d %d %d %d %d\n", atoi(argv[3]), atoi(argv[4]), atoi(argv[5]),
                   atoi(argv[6]), atoi(argv[7]), atoi(argv[8]), atoi(argv[9]));
            break;
        case 2:
            byebye(NULL, atoi(argv[3]), atoi(argv[4]), atoi(argv[5]),
                   atoi(argv[6]), atoi(argv[7]), atoi(argv[8]), atoi(argv[9]));
            break;
        case 3:
        {
            int d, m, y;
            getmmddyy(&m, &d, &y);
            printf("%d %d %d\n", d, m, y);
            break;
        }
        case 4:
        {
            int d = atoi(argv[3]), m =  atoi(argv[4]),   y = atoi(argv[5]);
            getmmddyy(&m, &d, &y);
            printf("%d %d %d\n", d, m, y);
            break;
        }
        case 5:
        {
            int d = atoi(argv[3]), m =  atoi(argv[4]),   y = atoi(argv[5]);
            getmmddyy(&m, &d, NULL);
            printf("%d %d %d\n", d, m, y);
            break;
        }
        case 6:
        {
            int d = atoi(argv[3]), m =  atoi(argv[4]),   y = atoi(argv[5]);
            getmmddyy(&m, NULL, &y);
            printf("%d %d %d\n", d, m, y);
            getmmddyy(NULL, &d, &y);
            printf("%d %d %d\n", d, m, y);
            break;
        }
        case 7:
        {
            int y = atoi(argv[3]);
            printf("%d\n", isleapyear(y));
            break;
        }
        case 8:
        {
            int d = atoi(argv[3]), m =  atoi(argv[4]),   y = atoi(argv[5]);
            d = dayofweek(m, d, y);
            printf("%d\n", d);
            break;
        }
        case 9:
        {
            int week[] = {1,2,3,4,5,6,7}, weeknum =  atoi(argv[3]),   startdays = atoi(argv[4]),
                daysinweek = atoi(argv[5]), numdays = atoi(argv[6]);
            genweek(week,weeknum,startdays, daysinweek,numdays);
            break;
        }
    }
}
