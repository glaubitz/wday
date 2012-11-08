/* 
* Weekday 1.0.3
* WdGetDay.cpp
* May, 10 2001
* by A.Glaubitz
*/

#include "stdafx.h"
#include "Weekday.h"

char * wdgetday (int year,int month,int day) {

	char * wd[]= {
	"Friday",
	"Saturday",
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday" };

	int x = 0;
	int yr,mte,dye=0;
	int dy = 1;
	int mt = 1;
	int syear = 4;
	
	// Processing
	
	for (yr=0 ; yr < year+1;yr=yr+1) {

		if (yr == year)
			mte = month;
   
		if (yr < year)
			mte = 12;
   
		while (mt < mte+1) {

			if (mt==1||mt==3||mt==5||mt==7||mt==8||mt==10||mt==12)
				dye = 31;
			
			if (mt==4||mt==6||mt==9||mt==11)
				dye = 30;

			if (syear < 4 && mt==2)
				dye = 28;
      
			if (syear==4 && mt==2)
				dye = 29;

			if (yr == year && mt == month)
				dye = day;

			while (dy<dye+1) {
				
				dy=dy+1;
				x=x+1;
				
				if (x == 8)
					x = 1;
			}
			
			if (dy == dye+1)
				dy=1;

			mt=mt+1;
		}
   
		syear=syear+1;

		if(syear == 5)
			syear=1;  
		
		if (mt == 13)

			mt=1;
	}

	// Output

	return wd[x-1];
}
