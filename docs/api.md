# api

---

## 1.SystemTimeSupport.h

### 概述

该文件提供芯片系统层平台的实现基于RT-Thread滴答计数器的time/clock函数。

## 2.GenericThreadStackManagerImpl_RTThread.h

### 概述

该文件提供了在RT-Thread平台上使用的ThreadStackManager功能的通用实现。

### 类

- `GenericThreadStackManagerImpl_RTThread<ImplClass>`：模板类，实现了ThreadStackManager的抽象接口。

### 方法

- `_StartThreadTask()`：启动线程任务的方法。
- `_LockThreadStack()`：锁定线程堆栈的方法。
- `_TryLockThreadStack()`：尝试锁定线程堆栈的方法。
- `_UnlockThreadStack()`：解锁线程堆栈的方法。
- `DoInit()`：初始化方法。
- `SignalThreadActivityPending()`：信号线程活动待处理的方法。

### 成员

- `mThreadStackLock`：线程堆栈锁。
- `mThreadStackNotify`：线程堆栈通知事件。
- `mThreadTask`：线程任务。

## 3.GenericThreadStackManagerImpl_RTThread.cpp

### 概述

该文件包含了`GenericThreadStackManagerImpl_RTThread`模板的非内联方法定义。

### 方法

- `DoInit()`：初始化方法的实现。
- `_StartThreadTask()`：启动线程任务的方法的实现。
- `_LockThreadStack()`：锁定线程堆栈的方法的实现。
- `_TryLockThreadStack()`：尝试锁定线程堆栈的方法的实现。
- `_UnlockThreadStack()`：解锁线程堆栈的方法的实现。
- `SignalThreadActivityPending()`：信号线程活动待处理的方法的实现。
- `ThreadTaskMain()`：线程任务的主函数。

## 4.CHIPPlatformConfig.h

### 概述

该文件包含了适用于RT-Thread平台的CHIP的平台特定配置覆盖。

### 安全配置覆盖

- `PENDING_EVENT_FLAG`：待处理事件标志。
- `PENDING_EVENT_ISR_FLAG`：从ISR触发的待处理事件标志。
- `CHIP_CONFIG_RTTHREAD_USE_STATIC_TASK`：使用静态任务的配置。
- `CHIP_CONFIG_RTTHREAD_USE_STATIC_MUTEX`：使用静态互斥锁的配置。
- `CHIP_CONFIG_RTTHREAD_USE_STATIC_EVENT`：使用静态事件的配置。
