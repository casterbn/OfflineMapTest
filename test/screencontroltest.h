
/****************************************************************************
** @projectName   OfflineMapTest
** QT Version     5.11.1
** This file is part of the OfflineMapTest project.
** @file          screencontrol.h
** @brief         屏幕控制测试类
** @details       主要功能测试屏幕控制screencontrol类
** @author        wangpengcheng
** @QQ            673018396
** @email         wangpengcheng2018@gmail.com
** @address       https://github.com/wangpengcheng/OfflineMapTest
** @date          2018-11-09 周五  17:11:23
** @example
**
** QApplication app(argc, argv);//使用QApplication
** QDesktopWidget *desktop=QApplication::desktop();//获取当前硬件控件
** ScreenControlTest  he_he(desktop);//创建测试类
** he_he.SetWindowTest();    //测试窗口
**
*****************************************************************************/
#ifndef SCREENCONTROLTEST_H
#define SCREENCONTROLTEST_H
#include "src/screencontrol.h"
#ifndef  TOOL_H
#include "src/tool.h"
#endif

class ScreenControlTest
{
public:
    ScreenControlTest();
    ScreenControlTest(QDesktopWidget *desktop);
    void SetWindowTest();//测试窗口设置
    void initTest();
private:
    ScreenControl m_screencontrol;
     Tool tool;
};

#endif // SCREENCONTROLTEST_H
