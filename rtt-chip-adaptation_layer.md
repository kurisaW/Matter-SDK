## 说明

为了实现RT-Thread Matter的适配，可以遵循与Zephyr Matter适配相同的概要步骤，创建和修改与各种接口的平台特定实现相对应的文件。这里概述了需要采取的高级步骤,文件路径相对于`connectedhomeip/src/...`:

### 1.PlatformManager实现

`include/platform/RTThread/PlatformManagerImpl.h`   

`RTThread/PlatformManagerImpl.cpp`   

* 实现RT-Thread的具体`PlatformManager`接口
* 初始化CHIP堆栈和芯片任务的核心事件循环
* 使用适当的泛型实现,例如:`GenericPlatformManagerImpl_FreeRTOS<>`

### 2.ConfigurationManager实现

`include/platform/RTThread/ConfigurationManagerImpl.h`   

`RTThread/ConfigurationManagerImpl.cpp`   

* 实现RT-Thread的具体`ConfigurationManager`接口
* 管理持久配置数据的存储和检索
* 使用适当的泛型实现,例如:`GenericConfigurationManagerImpl<>`
* 将低级读写持久值的任务委托给新的RT-Thread特定类,例如`RTThreadConfig`

### 3.ThreadStackManager实现

`include/platform/RTThread/ThreadStackManagerImpl.h`   

`RTThread/ThreadStackManagerImpl.cpp`   

* 实现RT-Thread的具体`ThreadStackManager`接口
* 支持线程栈初始化和核心事件循环处理
* 使用适当的泛型实现,例如:`GenericThreadStackManagerImpl_OpenThread/FreeRTOS<>`

### 4.BLEManager实现

`include/platform/RTThread/BLEManagerImpl.h`   

`RTThread/BLEManagerImpl.cpp`   

* 实现RT-Thread的具体`BLEManager`接口
* 将CHIP的BLE接口抽象映射到平台的本机BLE服务
* 实现CHIP兼容的BLE广告

### 5.Logging 适配

`platform/RTThread/Logging.cpp`   

* 将CHIP调试日志记录适配到RT-Thread的日志记录机制

### 6.RTThreadConfig 实现

`platform/RT-Thread/RTThreadConfig.cpp`   

* 实现低级读/写持久配置值
* 设计类API与`GenericConfigurationManagerImpl<>`类协同工作

### 7.CHIPDevicePlatformEvent 实现

`platform/RTThread/CHIPDevicePlatformEvent.h`   

* 定义CHIP设备层的平台特定事件类型和数据

