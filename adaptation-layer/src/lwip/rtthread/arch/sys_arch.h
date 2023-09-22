/*
 *    Copyright (c) 2020 Project CHIP Authors
 *    Copyright (c) 2018-2019 Google LLC.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/*
 *    Description:
 *      LwIP sys_arch definitions for use with RT-Thread.
 *
 */

#ifndef CHIP_LWIP_RTTHREAD_ARCH_SYS_ARCH_H
#define CHIP_LWIP_RTTHREAD_ARCH_SYS_ARCH_H

#include "arch/cc.h"
#include <rtthread.h>

#define SYS_MBOX_NULL RT_NULL
#define SYS_SEM_NULL  RT_NULL

typedef rt_uint32_t sys_prot_t;

#define SYS_MBOX_SIZE 10
#define SYS_LWIP_TIMER_NAME "timer"
#define SYS_LWIP_MBOX_NAME "mbox"
#define SYS_LWIP_SEM_NAME "sem"
#define SYS_LWIP_MUTEX_NAME "mu"

typedef rt_sem_t sys_sem_t;
typedef rt_mutex_t sys_mutex_t;
typedef rt_mailbox_t  sys_mbox_t;
typedef rt_thread_t sys_thread_t;

#endif /* CHIP_LWIP_RTTHREAD_ARCH_SYS_ARCH_H */
