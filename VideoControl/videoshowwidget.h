﻿#ifndef VIDEOSHOWWIDGET_H
#define VIDEOSHOWWIDGET_H

#include <QWidget>
#include <QMenu>
#include <QTimer>
//#include "myvideowidget.h"
class MyVideoWidget;
namespace Ui {
class VideoShowWidget;
}

class VideoShowWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VideoShowWidget(QWidget *parent = nullptr);
    ~VideoShowWidget();
    //保护函数，设置键盘监听
protected:
    bool eventFilter(QObject *watched, QEvent *event);
    //公共槽函数
public slots:
    void initForm();
    void initMenu();

public slots:
    void play_video_all();
    void snapshot_video_one();
    void snapshot_video_all();

    void show_video_all();
    void show_video_4();
    void show_video_6();
    void show_video_8();
    void show_video_9();
    void show_video_16();

    void hide_video_all();
    void change_video(int index, int v_row,int col);
    void change_video_4(int index);
    void change_video_6(int index);
    void change_video_8(int index);
    void change_video_9(int index);
    void change_video_12(int index);
private:
    Ui::VideoShowWidget *ui;

    bool videoMax;
    int videoCount;
    QString videoType;
    QMenu *videoMenu=nullptr;//右键选项
    QList<MyVideoWidget *>widgets;//播放窗口队列
};

#endif // VIDEOSHOWWIDGET_H