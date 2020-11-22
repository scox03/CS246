#ifndef MYCALENDAR_H
#define MYCALENDAR_H

#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"
#include "Map.h"
#include "Vector.h"
using ulong = unsigned long;

namespace ds
{
	class Calendar
	{
		public:
		virtual bool Book(ulong,ulong) = 0;
	};

	class MyCalendar : public Calendar
	{
		private:
		ds::sn::Map<ulong,ulong> calendar;

		public:
		MyCalendar()
		{
			for(ulong i = 1;i <= 365;i += 1)
			{
				calendar.Put(i,0);
			}
		}
			
		MyCalendar(ulong year)
		{
			ulong n = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))?(366):(365);

			for(ulong i = 1;i <= n;i += 1)
			{
				calendar.Put(i,0);
			}
		}

		MyCalendar(const MyCalendar& obj)
		{
			calendar = obj.calendar;
		}

		MyCalendar& operator=(const MyCalendar& rhs)
		{
			if(this != &rhs)
			{
				calendar = rhs.calendar;
			}
			return *this;
		}

		~MyCalendar() {}

		bool Book(ulong start,ulong end)
		{
			ulong n = 365;

			if(calendar.Contains(366))
			{
				n = 366;
			}
			
			if(start >= n && end >= n && start >= end)
			{
				return false;
			} 

			for(ulong i = start + 1;i <= end;i += 1)
			{
				if(calendar[i] + 1 > 2)
				{
					return false;
				}
			}

			for(ulong i = start + 1;i < end;i += 1)
			{
				calendar[i] += 1;
			}
		}
	};
}

#endif
