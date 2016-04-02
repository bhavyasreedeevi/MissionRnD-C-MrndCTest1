/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int checkdate(int day, int month, int year)
{
	if (day == 0 || month == 0 || year == 0)
		return(-1);
	else if (month>12 || day>31)
		return(-1);
	else if (month == 2)
	{
		if (year % 4 == 0)
		{
			if (day>29)
				return(-1);
		}
		else
		{
			if (day>28)
				return(-1);
		}

	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day>30)
			return(-1);
	}
}
int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head==NULL)
		return -1;
	int d1=0, d2=0, m1=0, m2=0, y1=0, y2=0,flag1=0,flag2=0;
	struct node *curr1,*curr2;
	for (curr1 = date1head, curr2 = date2head; curr1 != NULL&&curr2!=NULL;)
	{
			d1 = curr1->data * 10 + curr1->next->data;
			d2 = curr2->data * 10 + curr2->next->data;
			curr1 = curr1->next->next;
			curr2 = curr2->next->next;
			m1 = curr1->data * 10 + curr1->next->data;
			m2 = curr2->data * 10 + curr2->next->data;
			curr1 = curr1->next->next;
			curr2 = curr2->next->next;
			y1 = curr1->data * 1000 + curr1->next->data * 100 + curr1->next->next->data * 100 + curr1->next->next->next->data * 100;
			m2 = curr2->data * 1000 + curr2->next->data * 100 + curr1->next->next->data * 100 + curr1->next->next->next->data * 100;
			flag1 = checkdate(d1, m1, y1);
			flag2 = checkdate(d2, m2, y2);
			if (flag1 != -1 && flag2 != -1)
			{
				if (y1 == y2 && m1 == m2 && d1!=d2)
				{
					return(d2 - d1 - 1);
				}
				if (y2 - y1 == 1 && m1 - m2 == 11 && d1 - d2 == 30)
				{
					return 1;
				}
				else
				{

				}
			}
	}
}