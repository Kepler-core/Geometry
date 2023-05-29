#pragma once
#include "layer.h"
#include "mapProperty.h"

#include <map>
#include <deque>
#include <vector>

/*地图操作*/


class GeoMap 
{
public:
    struct LayerOrder   //图层选择
    {
        LayerOrder(int nLID, int nOrder): LID(nLID), order(nOrder) {}
        int LID;  //图层编号
        int order;  //“选择”标识
    };

public:
    GeoMap() {}
    GeoMap(const GeoMap& rhs);
    ~GeoMap();

    GeoMap* copy();   //深拷贝
    void Draw() const;  //绘制图层
    bool isEmpty() const { return layers.empty(); }    //判断图层是否为空
    int getNumLayers() const { return layers.size(); }   //获取图层数
    GeoLayer* getLayerByOrder(int order) const;   //获取显示的图层
    GeoLayer* getLayerById(int idx) const { return layers[idx]; }   //通过下标获取图层
    GeoLayer* getLayerByLID(int nLID) const;   //通过图层编号获取图层
    GeoLayer* getLayerByName(const QString& name) const;   //通过图层名称获取图层
    GeoLayer* getLastLayer() const;   //获取最新图层
    //获取图层id好
    int getLayerLIDByOrder(int order) const
    {
        return layerOrders[order];
    }
    int getLayerIndexByOrder(int order) const;
    int getLayerIndexByName(const QString& name) const;
    int getLayerIndexByLID(int lid) const;

    int addLayer(GeoLayer* layerIn);   //添加图层，返回图层编号
    bool removeLayerByLID(int nLID);   //移除图层
    void changeLayerOrder(int nLID, int insertLID);  //插入图层

    //遍历图层
    std::vector<GeoLayer*>::iterator begin() { return layers.begin(); }
    std::vector<GeoLayer*>::iterator end() { return layers.end(); }

    QString getName() const { return properties.name; }    //获取图层名
    GeoExtent getExtent() const { return properties.extent; }  //获取边界范围

    void setName(const QString& nameIn) { properties.name = nameIn; }  //重命名
    void updateExtent();

    //空间查询
    void queryFeature(double x, double y, double halfEdge,GeoFeatureLayer*& layerOut,GeoFeature*& featureOut);
    void queryFeatures(const GeoExtent& extent,std::map<GeoFeatureLayer*, std::vector<GeoFeature*>>& featuresOut);

    //要素选择
    void getAllSelectedFeatures(std::map<GeoFeatureLayer*, std::vector<GeoFeature*>>& selectedFeatures);  //选择所有
    void emplaceSelectedFeature(int nLID, GeoFeature* sf);
    void emplaceSelectedFeatures(int nLID, const std::vector<GeoFeature*>& sfs);
    void emplaceSelectedFeatures(GeoFeatureLayer* layer, const std::vector<GeoFeature*>& sfs);
    void setSelectedFeatures(const std::map<GeoFeatureLayer*, std::vector<GeoFeature*>>& sfs);
    void clearSelectedFeatures();  //清除所选内容
    void offsetSelectedFeatures(double xOffset, double yOffset);   //移动所选内容

private:
    int currentLID = 0;
    std::vector<GeoLayer*> layers; 
    GeoMapProperty properties;
    std::deque<int> layerOrders;
};