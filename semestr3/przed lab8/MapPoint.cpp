#include<iostream>
#include<cmath>
#include "MapPoint.h"
using namespace std;
MapPoint::MapPoint(const double lat, const double lon)
{
	_lat=lat;
	_lon=lon;
}
void MapPoint::print() const
{
	cout<<"Point ("<<abs(_lat);
	if (_lat>=0)
	{
		cout<<"N, ";
	}
	else
	{
		cout<<"S, ";
	}
	cout<<abs(_lon);
	if (_lon>0)
	{
		cout<<"E)";
	}
	else
	{
		cout<<"W)";
	}
	cout<<endl;
}
void MapPoint::move(double a, double b)
{
	_lat+=a;
	_lon+=b;
}
MapPoint MapPoint::inTheMiddle(const MapPoint& point1, const MapPoint& point2) {
  const double lat = (point1._lat + point2._lat) / 2;
  const double lon = (point1._lon + point2._lon) / 2;

  return MapPoint(lat, lon);
}
 MapPoint& MapPoint::furtherFrom(MapPoint& p1, MapPoint& p2) const
{
	double l1= sqrt(pow(this->_lat+p1._lat,2)+pow(this->_lon+p1._lon,2));
	double l2= sqrt(pow(this->_lat+p2._lat,2)+pow(this->_lon+p2._lon,2));
	if (l1>l2)
		return p1;
	return p2;
}