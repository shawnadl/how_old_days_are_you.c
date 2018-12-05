/***********************************************/
 *Practice-3 2018-12-5 by shawnadl
 *This function calculates how old days are you.
 *Example, your birth day is 5/5/2000 and current
 time is 2018/5/12 then:
  -calculate_year function calculates: how many days
 were there from 2001 to 2017.
  -calculate_month function calculates: how many days
  were there from June to Dec in 2000 and how many
  days were there from Jan to Nov in 2018.
  -calculate_day function calculates: how many days
  have you lived in May 2000 and in Dec 2018.
  -Total days = sumary of all functions above.
 *This program is including leap year
/***********************************************/
typedef struct{
	int year;
	int month;
	int day;
}time;

int leap[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
int non_leap[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

/*This function is to check leap year, please visit:
https://www.wikihow.com/Calculate-Leap-Years for more detail*/
int check_leap_year(int year){
	if(year % 4 != 0)
		return 0;//return 0 as non-leap year
	else{
		if(year % 100 != 0)
			return 1;
		else if(year % 400 != 0)
			return 0;
	}
	return 1;//return 1 as leap year
}

int calculate_year(time current, time birth){
	int i;
	int total_y = 0;
	for(i = birth.year+1; i < current.year; i++){
		if(check_leap_year(i))
			total_y += 366;
		else
			total_y += 365;
	}//end for
	return total_y;
}

int calculate_month(time current, time birth){
	int i,j;
	int total_m = 0;
	for(i = birth.month+1; i <= 12; i++){
		if(check_leap_year(birth.year))
			total_m += leap[i];
		else
			total_m += non_leap[i];
	}//end birth month
	for(j = 1; j < current.month; j++){
		if(check_leap_year(current.year))
			total_m += leap[j];
		else
			total_m += non_leap[j];
	}//end current month
	return total_m;
}

int calculate_day(time current, time birth){
	int total_d;
	if(check_leap_year(birth.year))
		total_d = leap[birth.month] - birth.day;
	else
		total_d = non_leap[birth.month] - birth.day;
	return total_d + current.day;
}

int calculate_total(time current, time birth){
	int total_day = calculate_year(current, birth) + calculate_month(current, birth) +
					calculate_day(current, birth);
	return total_day;
}
