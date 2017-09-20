#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hr, m, total_min, fee, day_int;
    float day_float;

    printf("Enter HH:MM ");
    scanf("%d:%d",&hr, &m);
    printf("hr: %d\n",hr);
    printf("min: %d\n",m);

    total_min = hr*60 + m;

    if (total_min <= 15)
        fee = 0;
    else if (total_min > 15 && total_min<= 180){
        if (m == 0)
            fee = hr*10;
        else
            fee = (hr + 1)*10;
    }
    else if (total_min > 180 && total_min <= 360){
        if (m == 0)
            fee = hr*15;
        else
            fee = (hr + 1)*15;
    }
    else if (total_min > 360 && total_min <= 720){
        if (m == 0)
            fee = hr*20;
        else
            fee = (hr + 1)*20;
    }
    else if (total_min > 720 && total_min <= 1440)
        fee = 300;
    else{
        // จำนวนวันแบบมีทศนิยม
        day_float = total_min/(24*60*1.0); //multiply 1.0 to make result float

        // จำนวนวันแบบหารปัดลง
        day_int = hr/24;

        day_float -= day_int; // day_float = เศษของวัน
        fee = 300*day_int;
        if (day_float > 0.0)
            fee += 300;

    }
    printf("The fee is %d bahts",fee);
    return 0;
}
