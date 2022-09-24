#ifndef UpDate_H
#define upDate_H
#include <string>
using namespace std;

class upDate
{
	public:
		upDate();
		upDate(int, int, int);
		upDate(int);
		~upDate();
		void setDate(int, int, int);
		int getMonth();
		int getDay();
		int getYear();
		string getMonthName();
		friend ostream& operator<<(ostream&, const upDate&);
		upDate(const upDate&);
		upDate operator=(upDate);
		upDate operator+=(int);
		upDate operator-=(int);
		upDate operator+(int);
		friend upDate operator+(int, const upDate&);
		friend int operator-(const upDate&, const upDate&);
		upDate operator-(int);
		friend upDate operator++(upDate&, int);
		friend upDate operator++(upDate&);
		friend upDate operator--(upDate&, int);
		friend upDate operator--(upDate&);
		int julian();
		friend bool operator==(upDate&, upDate&);
		friend bool operator<(upDate&, upDate&);

		friend bool operator>(upDate&, upDate&);
		static int GetDateCount();

	private:
		int* ptr;
		static int dateCount;
		
};
#endif

