#pragma once
#include<iostream>
class MapPoint
{
public:
	MapPoint(const double lat, const double lon);
	void print() const;
	void move(double a, double b);
	 static MapPoint inTheMiddle(const MapPoint& p1, const MapPoint& p2);
	 MapPoint& furtherFrom(MapPoint& p1, MapPoint& p2) const;
private:
	double _lat;
	double _lon;

};