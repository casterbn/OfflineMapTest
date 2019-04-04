﻿#ifndef MAINSHOWDIALOG_H
#define MAINSHOWDIALOG_H
/****************************************************************************
** @projectName   OfflineMapTest
** QT Version    5.11.3
** This file is part of the OfflineMapTest project.
** @file          mainshowdialog.h
** @brief         this file is MainShowDialog class head file
** @details       MainShowDialog 利用QstackWidgets 实现两个页面之间的相互切换，暂时提添加的地图显示页和，视频显示页面
** @author        wangpengcheng
** @QQ            673018396
** @email         wangpengcheng2018@gmail.com
** @address       https://github.com/wangpengcheng/OfflineMapTest
** @date          2019-04-04 周四  20:46:10
** @example
**
** 示例代码
**
*****************************************************************************/
#include <QDialog>
#include <QStackedWidget>
#include <QQuickWidget>
#include <QQuickView>
#include <QVBoxLayout>
class VideoShowWidget;
namespace Ui {
class MainShowDialog;
}

class MainShowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainShowDialog(QWidget *parent = nullptr);
    ~MainShowDialog();
    void Init();//初始化函数

private:
    Ui::MainShowDialog *ui;
    //私有成员类
    QStackedWidget *stacked_widget_=nullptr;//中间间隔类
    QWidget *map_page_=nullptr;//qml地图
    VideoShowWidget *video_page_=nullptr;//自定义视频展示widget
    QVBoxLayout* vbox_layout_=nullptr;//水平布局

};

#endif // MAINSHOWDIALOG_H