/*******************************************************************************
  linux平台下输入子系统架构分析:
  知识点1: inputReader线程如何读取Rawdata?什么时候唤醒这个线程?
  知识点2: inputdispatcher线程与inputReader线程到底是什么关系?是如何通信的?
  知识点3: 获取到焦点fcous(屏幕的坐标)怎么传递给viewroot?
  知识点4: inputReader线程一直读取evdev.c数据?会不会读空?
*******************************************************************************/
