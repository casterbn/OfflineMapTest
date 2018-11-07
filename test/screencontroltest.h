#ifndef SCREENCONTROLTEST_H
#define SCREENCONTROLTEST_H

//include ScreenControl

/*
 *屏幕控制测试类
 * 主要功能测试屏幕控制screencontrol类
 * 王鹏程 2018-11-5 18:26
 * QQ: 673018396
 * 完整项目地址：
 * https://github.com/wangpengcheng/OfflineMapTest
 *
 *  使用方法：
 *  QApplication app(argc, argv);//使用QApplication
 *  QDesktopWidget *desktop=QApplication::desktop();//获取当前硬件控件
 *  ScreenControlTest  he_he(desktop);//创建测试类
 *   he_he.SetWindowTest();    //测试窗口
 *
 */

#include "screencontrol.h"

class ScreenControlTest
{
public:
    ScreenControlTest();
    ScreenControlTest(QDesktopWidget *desktop);
    void SetWindowTest();//测试窗口设置
private:
    ScreenControl m_screencontrol;
};

#endif // SCREENCONTROLTEST_H
