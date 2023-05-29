#pragma once
#include "geo_base.hpp"

/*地图属性  名称+边界*/

#include <QString>


class GeoMapProperty 
{
public:
    GeoMapProperty() = default;
    ~GeoMapProperty() = default;

public:
    QString name = "untitled";
    GeoExtent extent;
};