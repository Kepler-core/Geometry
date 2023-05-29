#include "Geometry.h"

#include <algorithm>


GeoPoint::GeoPoint() :x(0.0f), y(0.0f) {}

GeoPoint::GeoPoint(double xx, double yy) : x(xx), y(yy) {}

GeoGeometry* GeoPoint::copy()   //复制
{
    return (new GeoPoint(this->x, this->y));
}

GeometryType GeoPoint::getGeometryType() const  //几何类型
{
    return kPoint;
}

const char* GeoPoint::getGeometryName() const   //类型名
{
    return "POINT";
}

int GeoPoint::getNumPoints() const  //数量
{
    return 1;
}

GeoExtent GeoPoint::getExtent() const  //边界
{
    return { x, x, y, y };
}

bool GeoPoint::isEmpty() const  //判空
{
    return false;
}

void GeoPoint::swapXY()  //交换
{
    std::swap(x, y);
}

void GeoPoint::offset(double xOffset, double yOffset)   //平移
{
    x += xOffset;
    y += yOffset;
}