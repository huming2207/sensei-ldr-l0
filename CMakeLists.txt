cmake_minimum_required(VERSION 3.13)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/stm32_gcc.cmake)

project(sensei-ldr-l0 C ASM)

stm32_fetch_cmsis(L0)
stm32_fetch_hal(L0)


find_package(CMSIS COMPONENTS STM32L071KB REQUIRED)
find_package(HAL COMPONENTS STM32L0 REQUIRED)

set(CMAKE_C_STANDARD 99)
#if (CMAKE_BUILD_TYPE EQUAL "Release")
#    set(CMAKE_C_FLAGS "-g0 -Os -fno-common -fno-builtin -mthumb -mthumb-interwork \
#                            -ffunction-sections -fdata-sections -fno-rtti \
#                            -flto -fmessage-length=0 -specs=nosys.specs -specs=nano.specs
#                            -std=gnu99")
#else()
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Og -fno-common -fno-builtin -mthumb -mthumb-interwork \
#                            -ffunction-sections -fdata-sections \
#                            -flto -fmessage-length=0 -specs=nosys.specs -specs=nano.specs
#                            -std=gnu99")
#endif()



add_executable(cyberxray-l0x1-ldr main.c)
target_link_libraries(cyberxray-l0x1-ldr
        HAL::STM32::L0::LL_RCC
        HAL::STM32::L0::LL_GPIO
        HAL::STM32::L0::LL_UTILS
        CMSIS::STM32::L071KB
        STM32::NoSys
)