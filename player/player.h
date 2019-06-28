﻿/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
QT_BEGIN_NAMESPACE
class QAbstractItemView;
class QLabel;
class QMediaPlayer;
class QModelIndex;
class QPushButton;
class QSlider;
class QStatusBar;
class QVideoProbe;
class VideoWidget;
class QAudioProbe;
class VideoWidget;
#include <QGeoCoordinate>
#include <QVideoWidget>
#include "VideoControl/recordselectdialog.h"
QT_END_NAMESPACE

class PlaylistModel;
class HistogramWidget;

class Player : public QWidget
{
    Q_OBJECT

public:
    //基本构造函数
    Player(QWidget* parent=nullptr);
    ~Player();

    bool isPlayerAvailable() const;

    void addToPlaylist(const QList<QUrl> &urls);
    void setCustomAudioRole(const QString &role);
    //获取显示
    inline QVideoWidget* videoWidget(){return m_videoWidget;}
    inline QMediaPlayer* GetPlyer(){return m_player;}

signals:
    void fullScreenChanged(bool fullScreen);
    void SendQGeoCoordinate(QGeoCoordinate);

private slots:
    void open();
    void durationChanged(qint64 duration);//最后信号更改
    void positionChanged(qint64 progress);//
    void metaDataChanged();

    void previousClicked();

    void seek(int seconds);
    void jump(const QModelIndex &index);
    void playlistPositionChanged(int);

    void statusChanged(QMediaPlayer::MediaStatus status);
    void stateChanged(QMediaPlayer::State state);
    void bufferingProgress(int progress);
    void videoAvailableChanged(bool available);

    void displayErrorMessage();

    void showColorDialog();
    void InitQGeoCoordinates(int record_id);//从数据库获取坐标信息
    void SendCoordinatesToBus(int index); //抛出信号的函数
    void GetMainShowMessage(MainSendMessage new_message);//接收查询结果信息
    //void UpdatePlayInfo();
private:
    void clearHistogram();
    void setTrackInfo(const QString &info);
    void setStatusInfo(const QString &info);
    void handleCursor(QMediaPlayer::MediaStatus status);
    void updateDurationInfo(qint64 currentInfo);
    QMediaPlayer *m_player = nullptr;//播放器
    QMediaPlaylist *m_playlist = nullptr;//播放列表
    QVideoWidget *m_videoWidget = nullptr;//显示列表
    QLabel *m_coverLabel = nullptr;//转换列表
    QSlider *m_slider = nullptr; //进度条
    QLabel *m_labelDuration = nullptr;//
    QPushButton *m_fullScreenButton = nullptr;//全屏按钮
    QPushButton *m_colorButton = nullptr;//色彩按钮
    QDialog *m_colorDialog = nullptr;//色彩选框
    QLabel *m_statusLabel = nullptr;//状态标签
    QStatusBar *m_statusBar = nullptr;//状态条

    QLabel *m_labelHistogram = nullptr;//频率条
    HistogramWidget *m_videoHistogram = nullptr;//视频
    HistogramWidget *m_audioHistogram = nullptr;//音频
    QVideoProbe *m_videoProbe = nullptr;//视频属性
    QAudioProbe *m_audioProbe = nullptr;//音频属性

    PlaylistModel *m_playlistModel = nullptr;
    QAbstractItemView *m_playlistView = nullptr;
    QString m_trackInfo;
    QString m_statusInfo;
    qint64 m_duration;
    QList<QGeoCoordinate> bus_coordinates_list_;//公交的历史坐标点信息
    RecordSelectDialog* sql_choose_dialog_;//sql选择框


};

#endif // PLAYER_H
