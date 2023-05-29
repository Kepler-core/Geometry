#pragma once
#include <QString>

#include "geo_base.hpp"

/*դ��ͼ������  �ɼ�+����+���+���ݷ�Χ*/

class GeoRasterLayerProperty 
{
public:
    GeoRasterLayerProperty() {}
    ~GeoRasterLayerProperty() {}

    bool visible = true;  //�ɼ�/���ɼ�
    int id = 0;  //ͼ����
    QString name;  //ͼ����
    GeoExtent extent;  //ͼ�����ݷ�Χ
};

