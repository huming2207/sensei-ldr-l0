#pragma once

#define __LOADER_RAMFUNC __attribute__(( long_call, section(".data") ))

__LOADER_RAMFUNC void loader_init();
