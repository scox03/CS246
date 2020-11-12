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
		public
		MyCalendar();
		MyCalendar(ulong);
		MyCalendar(const MyCalendar&);
		MyCalendar& operator=(const MyCalendar&);
		bool Book(ulong,ulong);
	};
}

#endif
