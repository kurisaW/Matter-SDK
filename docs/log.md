## List of files removed

```bash
+ Using Matter v1.0.0 SDK.

Limitation:
+ All symbolic links of Matter and his dependances has been removed.

/* 2023.8.29 */
+ List of files removed from the original Matter directory:
+ in adaptation-layer/third_party/ directory:
  - adaptation-layer/third_party/ameba/
  - adaptation-layer/third_party/android_deps/
  - adaptation-layer/third_party/boringssl/
  - adaptation-layer/third_party/bouffalolab/
  - adaptation-layer/third_party/cirque/
  - adaptation-layer/third_party/editline/
  - adaptation-layer/third_party/infineon/
  - adaptation-layer/third_party/inipp/
  - adaptation-layer/third_party/jlink/
  - adaptation-layer/third_party/jsoncpp/
  - adaptation-layer/third_party/mbed-mcu-boot/
  - adaptation-layer/third_party/mbed-os-cypress-capsense-button/
  - adaptation-layer/third_party/mbed-os-posix-socket/
  - adaptation-layer/third_party/mbed-os/
  - adaptation-layer/third_party/mt793x_sdk/
  - adaptation-layer/third_party/mynewt-core/
  - adaptation-layer/third_party/nanopb/
  - adaptation-layer/third_party/nxp/
  - adaptation-layer/third_party/openthread/
  - adaptation-layer/third_party/ot-br-posix/
  - adaptation-layer/third_party/pigweed/
  - adaptation-layer/third_party/pybind11/
  - adaptation-layer/third_party/qpg_sdk/
  - adaptation-layer/third_party/silabs/
  - adaptation-layer/third_party/simw-top-mini/
  - adaptation-layer/third_party/telink_sdk/
  - adaptation-layer/third_party/ti_simplelink_sdk/
  - adaptation-layer/third_party/tizen/
  - adaptation-layer/third_party/zap/

+ in adaptation-layer/src/ directory:
  - adaptation-layer/src/android
  - adaptation-layer/src/darwin

+ In adaptation-layer directory, the following directories/files has been removed:
  - adaptation-layer/.devcontainer/
  - adaptation-layer/.githooks/
  - adaptation-layer/.github/
  - adaptation-layer/.vscode/
  - adaptation-layer/build/
  - adaptation-layer/build_overrides/
  - adaptation-layer/config/
  - adaptation-layer/integrations/
  - adaptation-layer/scripts/
  - adaptation-layer/.clang-format
  - adaptation-layer/.clang-tidy
  - adaptation-layer/.default-version.min
  - adaptation-layer/.dirs-locals.el
  - adaptation-layer/.editorconfig
  - adaptation-layer/.flake8
  - adaptation-layer/.gitattributes
  - adaptation-layer/.gitignore
  - adaptation-layer/.gitmodules
  - adaptation-layer/.gn
  - adaptation-layer/.prettierrc.json
  - adaptation-layer/.pullapprove.yml
  - adaptation-layer/.restyled.yaml
  - adaptation-layer/.shellcheck_tree
  - adaptation-layer/.spellcheck.yml
  - adaptation-layer/.gn_build.sh
  - adaptation-layer/.lgtm.yml
```

## List of files added

```bash
+ RT-Thread connect to Matter v1.0.0 SDK.

+ List of files added to the original Matter directory:

/* 2023.8.29 */
+ in adaptation-layer/third_party/ directory:
  - adaptation-layer/third_party/rtthread/BUILD.gn
  - adaptation-layer/third_party/rtthread/rtthread.gni

/* 2023.8.29 */
+ in adaptation-layer/src/platform/ directory:
  - adaptation-layer/src/platform/RTThread/CHIPPlatformConfig.h
  - adaptation-layer/src/platform/RTThread/GenericThreadStackManagerImpl_RTThread.cpp
  - adaptation-layer/src/platform/RTThread/GenericThreadStackManagerImpl_RTThread.h
  - adaptation-layer/src/platform/RTThread/SystemTimeSupport.cpp
  - adaptation-layer/src/platform/RTThread/SystemTimeSupport.h

/* 2023.9.2 */
+ in adaptation-layer/src/include/platform/internal/ directory:
  - adaptation-layer/src/include/platform/internal/GenericPlatformManagerImpl_RTThread.h
  - adaptation-layer/src/include/platform/internal/GenericPlatformManagerImpl_RTThread.ipp

/* 2023.9.4 */
+ in adaptation-layer/src/system/ directory:
  - adaptation-layer/src/system/SystemLayerImplRTThread.h
  - adaptation-layer/src/system/SystemLayerImplRTThread.cpp

/* 2023.9.22 */
+ in adaptation-layer/src/lwip/ directory:
  - adaptation-layer/src/lwip/rtthread/sys_arch.c
  - adaptation-layer/src/lwip/rtthread/sys_arch.h
```

## List of files modified

```bash
+ RT-Thread connect to Matter v1.0.0 SDK.

+ List of files modified to the original Matter directory:

/* 2023.9.4 */
  - adaptation-layer/src/system/SystemLayer.h

/* 2023.9.17 */
  - adaptation-layer/src/platform/BUILD.gn
  - adaptation-layer/src/platform/device.gni

/* 2023.9.20 */
  - adaptation-layer/src/system/SystemConfig.h
  - adaptation-layer/src/system/SystemMutex.cpp
  - adaptation-layer/src/system/SystemMutex.h
  - adaptation-layer/src/system/system.gni
  - adaptation-layer/src/system/BUILD.gn
  - adaptation-layer/src/system/tests/TestSystemTimer.cpp

/* 2023.9.22 */
  - adaptation-layer/src/lwip/rtthread/BUILD.gn
  - adaptation-layer/src/lwip/rtthread/lwip.gni

/* 2023.9.23 */
+ in adaptation-layer/src/lwip/ directory:
  - adaptation-layer/src/lwip/rtthread/sys_arch.c
  - adaptation-layer/src/lwip/rtthread/sys_arch.h
  - adaptation-layer/src/lwip/rtthread/BUILD.gn
```

## Tips

	+ To recover all deleted files, please follow these steps:
	  - download the Git for Windows software.
	  - save this file (st_readme.txt) in a location other than the /adaptation-layer directory.
	  - delete the /adaptation-layer directory.
	  - do the following command in the adaptation-layer/Third_Party directory, with a git for Windows shell terminal:
	  
	    git clone -b v1.0.0 https://github.com/project-chip/connectedhomeip.git --recurse-submodule
		
	  - you now have the complete Matter SDK v1.0.0.