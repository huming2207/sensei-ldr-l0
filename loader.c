#include <stm32l071xx.h>
#include "loader.h"

// Flash write ops key
#define FLASH_PEKEY1           (0x89ABCDEF)
#define FLASH_PEKEY2           (0x02030405)
#define FLASH_PRGKEY1          (0x8C9DAEBF)
#define FLASH_PRGKEY2          (0x13141516)

// Write bytes
#define MOD8(addr)  (*((uint8_t  *) (addr)))
#define MOD16(addr) (*((uint16_t *) (addr)))
#define MOD32(addr) (*((uint32_t *) (addr)))

#define FW_BUF_A_BASE           (0x20001000) // 6KB
#define FW_BUF_B_BASE           (0x20002500) // 6KB
#define FW_BUF_LEN              0x1800 // 6KB; from 0x20001000-0x200027ff; 0x20002800-0x20003fff

// Pointers
#define BUF_CTR                 (0x20004000) // RW
#define BUF_LEFT                (0x20004004) // RW
#define WRITE_ENABLE            (0x20004008) // RW

void loader_init()
{
    // Unlock PECR register
    FLASH->PEKEYR = FLASH_PEKEY1;
    FLASH->PEKEYR = FLASH_PEKEY2;

    // Unlock programming
    FLASH->PRGKEYR = FLASH_PRGKEY1;
    FLASH->PRGKEYR = FLASH_PRGKEY2;

    //

    return 0;
}