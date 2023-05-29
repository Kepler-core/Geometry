#pragma once
#include <QString>

#include "geo_base.hpp"

/*栅格图层属性  可见+名称+编号+数据范围*/

class GeoRasterLayerProperty 
{
public:
    GeoRasterLayerProperty() {}
    ~GeoRasterLayerProperty() {}

    bool visible = true;  //可见/不可见
    int id = 0;  //图层编号
    QString name;  //图层名
    GeoExtent extent;  //图层数据范围
};

