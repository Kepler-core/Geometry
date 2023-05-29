#pragma once
#include "layer.h"
#include "mapProperty.h"

#include <map>
#include <deque>
#include <vector>

/*��ͼ����*/


class GeoMap 
{
public:
    struct LayerOrder   //ͼ��ѡ��
    {
        LayerOrder(int nLID, int nOrder): LID(nLID), order(nOrder) {}
        int LID;  //ͼ����
        int order;  //��ѡ�񡱱�ʶ
    };

public:
    GeoMap() {}
    GeoMap(const GeoMap& rhs);
    ~GeoMap();

    GeoMap* copy();   //���
    void Draw() const;  //����ͼ��
    bool isEmpty() const { return layers.empty(); }    //�ж�ͼ���Ƿ�Ϊ��
    int getNumLayers() const { return layers.size(); }   //��ȡͼ����
    GeoLayer* getLayerByOrder(int order) const;   //��ȡ��ʾ��ͼ��
    GeoLayer* getLayerById(int idx) const { return layers[idx]; }   //ͨ���±��ȡͼ��
    GeoLayer* getLayerByLID(int nLID) const;   //ͨ��ͼ���Ż�ȡͼ��
    GeoLayer* getLayerByName(const QString& name) const;   //ͨ��ͼ�����ƻ�ȡͼ��
    GeoLayer* getLastLayer() const;   //��ȡ����ͼ��
    //��ȡͼ��id��
    int getLayerLIDByOrder(int order) const
    {
        return layerOrders[order];
    }
    int getLayerIndexByOrder(int order) const;
    int getLayerIndexByName(const QString& name) const;
    int getLayerIndexByLID(int lid) const;

    int addLayer(GeoLayer* layerIn);   //���ͼ�㣬����ͼ����
    bool removeLayerByLID(int nLID);   //�Ƴ�ͼ��
    void changeLayerOrder(int nLID, int insertLID);  //����ͼ��

    //����ͼ��
    std::vector<GeoLayer*>::iterator begin() { return layers.begin(); }
    std::vector<GeoLayer*>::iterator end() { return layers.end(); }

    QString getName() const { return properties.name; }    //��ȡͼ����
    GeoExtent getExtent() const { return properties.extent; }  //��ȡ�߽緶Χ

    void setName(const QString& nameIn) { properties.name = nameIn; }  //������
    void updateExtent();

    //�ռ��ѯ
    void queryFeature(double x, double y, double halfEdge,GeoFeatureLayer*& layerOut,GeoFeature*& featureOut);
    void queryFeatures(const GeoExtent& extent,std::map<GeoFeatureLayer*, std::vector<GeoFeature*>>& featuresOut);

    //Ҫ��ѡ��
    void getAllSelectedFeatures(std::map<GeoFeatureLayer*, std::vector<GeoFeature*>>& selectedFeatures);  //ѡ������
    void emplaceSelectedFeature(int nLID, GeoFeature* sf);
    void emplaceSelectedFeatures(int nLID, const std::vector<GeoFeature*>& sfs);
    void emplaceSelectedFeatures(GeoFeatureLayer* layer, const std::vector<GeoFeature*>& sfs);
    void setSelectedFeatures(const std::map<GeoFeatureLayer*, std::vector<GeoFeature*>>& sfs);
    void clearSelectedFeatures();  //�����ѡ����
    void offsetSelectedFeatures(double xOffset, double yOffset);   //�ƶ���ѡ����

private:
    int currentLID = 0;
    std::vector<GeoLayer*> layers; 
    GeoMapProperty properties;
    std::deque<int> layerOrders;
};