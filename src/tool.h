﻿#ifndef TOOL_H
#define TOOL_H
/****************************************************************************
** @projectName   OfflineMapTest
** QT Version     5.11.1
** This file is part of the OfflineMapTest project.
** @file          tool.h
** @brief         Tool class
** @details       Tool 类实现各种工具功能
** @author        wangpengcheng
** @QQ            673018396
** @email         wangpengcheng2018@gmail.com
** @address       https://github.com/wangpengcheng/OfflineMapTest
** @date          2018-10-30 周二  18:21:11
** @example
**
** 详见test/tool_test.h文件中的ToolTest类使用方法
**
*****************************************************************************/
#ifndef QT_QTPOSITIONING_MODULE_H
#include <QtPositioning>
#endif

#ifndef  QLOCATION_H
#include <QLocation>
#endif

#ifndef QGEOCOORDINATE_H
#include <QGeoCoordinate>
#endif

#ifndef QMATH_H
#include <QtMath>
#endif
#ifndef QDEBUG_H
#include <QDebug>
#endif
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <math.h>
#define DELETE_OBJECT(obj) {if(obj!=nullptr){delete obj;obj=nullptr;qDebug()<<obj<<" deleted";} }

#define DELETE_QOBJECT(obj) {if(obj->parent()==nullptr){ delete obj;obj=nullptr;qDebug()<<obj<<" deleted";}}

class Tool: public QObject
{
    Q_OBJECT
    public:
        explicit Tool(QObject *parent = nullptr);
       // ~Tool();
        Q_INVOKABLE static double TransfromLatToDouble(double x,double y);//将经度转换为数值
        Q_INVOKABLE static double TransfromLonToDouble(double x,double y);//将维度转换为数值
        Q_INVOKABLE static QGeoCoordinate WPS84ToGCJ02(double lat, double lon);//转换坐标系到星火坐标系
        Q_INVOKABLE static QGeoCoordinate WPS84ToGCJ02FromCoord(QGeoCoordinate temp);//转换坐标系到星火坐标系
        Q_INVOKABLE static double GetDistance(QGeoCoordinate point1,QGeoCoordinate point2);//计算两点之间距离
        //测试信息工具类
        Q_INVOKABLE static void TestNoteTool(const QString TestName,
                                      const int i);//选择模式1-start，2-end
        static QString CreatFile(QString director_name,//文件夹名字
                         QString file_name,//文件名称
                         QString file_type//文件后缀
                         );//创建文件工具类
        //Json 请求同步函数，通过线程阻塞实现，json的同步请求。
        static QJsonObject NetWorkGet(QString url,//传输的地址
                                      QJsonObject send_data//请求的数据
                                      );
        static void RunWindowsCommand(QString command);

};

#endif // TOOL_H
