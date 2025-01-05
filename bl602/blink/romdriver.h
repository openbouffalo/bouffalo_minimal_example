#ifndef _BL702_ROMDRIVER_H_
#define _BL702_ROMDRIVER_H_

#include <stdint.h>

#define ROMAPI_INDEX_SECT_SIZE (0x800)
#define ROMAPI_INDEX_MAX       (ROMAPI_INDEX_SECT_SIZE / 4 - 1)

typedef enum {
    ROM_API_INDEX_VERSION = 0,
    ROM_API_INDEX_RSVD_0 ,
    ROM_API_INDEX_RSVD_1,
    ROM_API_INDEX_RSVD_LAST,


    ROM_API_INDEX_AON_Power_On_MBG,
    ROM_API_INDEX_AON_Power_Off_MBG,
    ROM_API_INDEX_AON_Power_On_XTAL,
    ROM_API_INDEX_AON_Set_Xtal_CapCode,
    ROM_API_INDEX_AON_Get_Xtal_CapCode,
    ROM_API_INDEX_AON_Power_Off_XTAL,
    ROM_API_INDEX_AON_Power_On_BG,
    ROM_API_INDEX_AON_Power_Off_BG,
    ROM_API_INDEX_AON_Power_On_LDO11_SOC,
    ROM_API_INDEX_AON_Power_Off_LDO11_SOC,
    ROM_API_INDEX_AON_Power_On_LDO15_RF,
    ROM_API_INDEX_AON_Power_Off_LDO15_RF,
    ROM_API_INDEX_AON_Power_On_SFReg,
    ROM_API_INDEX_AON_Power_Off_SFReg,
    ROM_API_INDEX_AON_LowPower_Enter_PDS0,
    ROM_API_INDEX_AON_LowPower_Exit_PDS0,

    ROM_API_INDEX_ASM_Delay_Us,

    ROM_API_INDEX_BL602_Delay_US,
    ROM_API_INDEX_BL602_Delay_MS,
    ROM_API_INDEX_BL602_MemCpy,
    ROM_API_INDEX_BL602_MemCpy4,
    ROM_API_INDEX_BL602_MemCpy_Fast,
    ROM_API_INDEX_BL602_MemSet,
    ROM_API_INDEX_BL602_MemSet4,
    ROM_API_INDEX_BL602_MemCmp,

    ROM_API_INDEX_EF_Ctrl_Sw_AHB_Clk_0,
    ROM_API_INDEX_EF_Ctrl_Program_Efuse_0,
    ROM_API_INDEX_EF_Ctrl_Load_Efuse_R0,
    ROM_API_INDEX_EF_Ctrl_Busy,
    ROM_API_INDEX_EF_Ctrl_AutoLoad_Done,
    ROM_API_INDEX_EF_Ctrl_Get_Trim_Parity,
    ROM_API_INDEX_EF_Ctrl_Read_RC32M_Trim,
    ROM_API_INDEX_EF_Ctrl_Read_RC32K_Trim,
    ROM_API_INDEX_EF_Ctrl_Clear,

    ROM_API_INDEX_GLB_Get_Root_CLK_Sel,
    ROM_API_INDEX_GLB_Set_System_CLK_Div,
    ROM_API_INDEX_GLB_Get_BCLK_Div,
    ROM_API_INDEX_GLB_Get_HCLK_Div,

    ROM_API_INDEX_Update_SystemCoreClockWith_XTAL,

    ROM_API_INDEX_GLB_Set_System_CLK,

    ROM_API_INDEX_System_Core_Clock_Update_From_RC32M,

    ROM_API_INDEX_GLB_Set_SF_CLK,
    ROM_API_INDEX_GLB_Set_PKA_CLK_Sel,
    ROM_API_INDEX_GLB_SW_System_Reset,
    ROM_API_INDEX_GLB_SW_CPU_Reset,
    ROM_API_INDEX_GLB_SW_POR_Reset,
    ROM_API_INDEX_GLB_Select_Internal_Flash,
    ROM_API_INDEX_GLB_Select_External_Flash,
    ROM_API_INDEX_GLB_Deswap_Flash_Pin,
    ROM_API_INDEX_GLB_Swap_Flash_Pin,
    ROM_API_INDEX_GLB_GPIO_Init,
    ROM_API_INDEX_GLB_GPIO_OUTPUT_Enable,
    ROM_API_INDEX_GLB_GPIO_OUTPUT_Disable,
    ROM_API_INDEX_GLB_GPIO_Set_HZ,
    ROM_API_INDEX_GLB_GPIO_Get_Fun,

    ROM_API_INDEX_HBN_Mode_Enter,
    ROM_API_INDEX_HBN_Power_Down_Flash,
    ROM_API_INDEX_HBN_Enable,
    ROM_API_INDEX_HBN_Reset,
    ROM_API_INDEX_HBN_Set_Ldo11_Aon_Vout,
    ROM_API_INDEX_HBN_Set_Ldo11_Rt_Vout,
    ROM_API_INDEX_HBN_Set_Ldo11_Soc_Vout,
    ROM_API_INDEX_HBN_32K_Sel,
    ROM_API_INDEX_HBN_Set_ROOT_CLK_Sel,
    ROM_API_INDEX_HBN_Power_On_Xtal_32K,
    ROM_API_INDEX_HBN_Power_Off_Xtal_32K,
    ROM_API_INDEX_HBN_Power_On_RC32K,
    ROM_API_INDEX_HBN_Power_Off_RC32K,
    ROM_API_INDEX_HBN_Trim_RC32K,
    ROM_API_INDEX_HBN_Hw_Pu_Pd_Cfg,
    ROM_API_INDEX_HBN_Pin_WakeUp_Mask,
    ROM_API_INDEX_HBN_GPIO7_Dbg_Pull_Cfg,
    ROM_API_INDEX_HBN_Set_Embedded_Flash_Pullup,

    ROM_API_INDEX_L1C_Set_Wrap,
    ROM_API_INDEX_L1C_Set_Way_Disable,
    ROM_API_INDEX_L1C_IROM_2T_Access_Set,

    ROM_API_INDEX_PDS_Reset,
    ROM_API_INDEX_PDS_Enable,
    ROM_API_INDEX_PDS_Force_Config,
    ROM_API_INDEX_PDS_RAM_Config,
    ROM_API_INDEX_PDS_Default_Level_Config,
    ROM_API_INDEX_PDS_Trim_RC32M,
    ROM_API_INDEX_PDS_Select_RC32M_As_PLL_Ref,
    ROM_API_INDEX_PDS_Select_XTAL_As_PLL_Ref,
    ROM_API_INDEX_PDS_Power_On_PLL,
    ROM_API_INDEX_PDS_Enable_PLL_All_Clks,
    ROM_API_INDEX_PDS_Disable_PLL_All_Clks,
    ROM_API_INDEX_PDS_Enable_PLL_Clk,
    ROM_API_INDEX_PDS_Disable_PLL_Clk,
    ROM_API_INDEX_PDS_Power_Off_PLL,

    ROM_API_INDEX_SEC_Eng_Turn_On_Sec_Ring,
    ROM_API_INDEX_SEC_Eng_Turn_Off_Sec_Ring,

    ROM_API_INDEX_SFlash_Init,
    ROM_API_INDEX_SFlash_SetSPIMode,
    ROM_API_INDEX_SFlash_Read_Reg,
    ROM_API_INDEX_SFlash_Write_Reg,
    ROM_API_INDEX_SFlash_Busy,
    ROM_API_INDEX_SFlash_Write_Enable,
    ROM_API_INDEX_SFlash_Qspi_Enable,
    ROM_API_INDEX_SFlash_Volatile_Reg_Write_Enable,
    ROM_API_INDEX_SFlash_Chip_Erase,
    ROM_API_INDEX_SFlash_Sector_Erase,
    ROM_API_INDEX_SFlash_Blk32_Erase,
    ROM_API_INDEX_SFlash_Blk64_Erase,
    ROM_API_INDEX_SFlash_Erase,
    ROM_API_INDEX_SFlash_Program,
    ROM_API_INDEX_SFlash_GetUniqueId,
    ROM_API_INDEX_SFlash_GetJedecId,
    ROM_API_INDEX_SFlash_GetDeviceId,
    ROM_API_INDEX_SFlash_Powerdown,
    ROM_API_INDEX_SFlash_Releae_Powerdown,
    ROM_API_INDEX_SFlash_SetBurstWrap,
    ROM_API_INDEX_SFlash_DisableBurstWrap,
    ROM_API_INDEX_SFlash_Software_Reset,
    ROM_API_INDEX_SFlash_Reset_Continue_Read,
    ROM_API_INDEX_SFlash_Set_IDbus_Cfg,
    ROM_API_INDEX_SFlash_IDbus_Read_Enable,
    ROM_API_INDEX_SFlash_Cache_Enable_Set,
    ROM_API_INDEX_SFlash_Cache_Flush,
    ROM_API_INDEX_SFlash_Cache_Read_Enable,
    ROM_API_INDEX_SFlash_Cache_Hit_Count_Get,
    ROM_API_INDEX_SFlash_Cache_Miss_Count_Get,
    ROM_API_INDEX_SFlash_Cache_Read_Disable,
    ROM_API_INDEX_SFlash_Read,
    ROM_API_INDEX_SFlash_Read_Reg_With_Cmd,
    ROM_API_INDEX_SFlash_Write_Reg_With_Cmd,
    ROM_API_INDEX_SFlash_Restore_From_Powerdown,

    ROM_API_INDEX_SF_Cfg_Init_Ext_Flash_Gpio,
    ROM_API_INDEX_SF_Cfg_Init_Internal_Flash_Gpio,
    ROM_API_INDEX_SF_Cfg_Deinit_Ext_Flash_Gpio,
    ROM_API_INDEX_SF_Cfg_Restore_GPIO17_Fun,
    ROM_API_INDEX_SF_Cfg_Get_Flash_Cfg_Need_Lock,
    ROM_API_INDEX_SF_Cfg_Init_Flash_Gpio,
    ROM_API_INDEX_SF_Cfg_Flash_Identify,
    ROM_API_INDEX_SF_Ctrl_Enable,
    ROM_API_INDEX_SF_Ctrl_Select_Pad,
    ROM_API_INDEX_SF_Ctrl_Set_Owner,
    ROM_API_INDEX_SF_Ctrl_Disable,
    ROM_API_INDEX_SF_Ctrl_AES_Enable_BE,
    ROM_API_INDEX_SF_Ctrl_AES_Enable_LE,
    ROM_API_INDEX_SF_Ctrl_AES_Set_Region,
    ROM_API_INDEX_SF_Ctrl_AES_Set_Key,
    ROM_API_INDEX_SF_Ctrl_AES_Set_Key_BE,
    ROM_API_INDEX_SF_Ctrl_AES_Set_IV,
    ROM_API_INDEX_SF_Ctrl_AES_Set_IV_BE,
    ROM_API_INDEX_SF_Ctrl_AES_Enable,
    ROM_API_INDEX_SF_Ctrl_AES_Disable,
    ROM_API_INDEX_SF_Ctrl_Set_Flash_Image_Offset,
    ROM_API_INDEX_SF_Ctrl_Get_Flash_Image_Offset,
    ROM_API_INDEX_SF_Ctrl_Select_Clock,
    ROM_API_INDEX_SF_Ctrl_SendCmd,
    ROM_API_INDEX_SF_Ctrl_Icache_Set,
    ROM_API_INDEX_SF_Ctrl_Icache2_Set,
    ROM_API_INDEX_SF_Ctrl_GetBusyState,
    ROM_API_INDEX_SF_Ctrl_Is_AES_Enable,
    ROM_API_INDEX_SF_Ctrl_Get_Clock_Delay,
    ROM_API_INDEX_SF_Ctrl_Set_Clock_Delay,

    ROM_API_INDEX_XIP_SFlash_State_Save,
    ROM_API_INDEX_XIP_SFlash_State_Restore,
    ROM_API_INDEX_XIP_SFlash_Erase_Need_Lock,
    ROM_API_INDEX_XIP_SFlash_Write_Need_Lock,
    ROM_API_INDEX_XIP_SFlash_Read_Need_Lock,
    ROM_API_INDEX_XIP_SFlash_GetJedecId_Need_Lock,
    ROM_API_INDEX_XIP_SFlash_GetDeviceId_Need_Lock,
    ROM_API_INDEX_XIP_SFlash_GetUniqueId_Need_Lock,
    ROM_API_INDEX_XIP_SFlash_Read_Via_Cache_Need_Lock,
    ROM_API_INDEX_XIP_SFlash_Read_With_Lock,
    ROM_API_INDEX_XIP_SFlash_Write_With_Lock,
    ROM_API_INDEX_XIP_SFlash_Erase_With_Lock,
    ROM_API_INDEX_XIP_SFlash_Opt_Enter,
    ROM_API_INDEX_XIP_SFlash_Opt_Exit,

    ROM_API_INDEX_BFLB_Soft_CRC32,

    ROM_API_INDEX_FUNC_EMPTY_START,

    ROM_API_INDEX_FUNC_EMPTY_END = ROMAPI_INDEX_MAX

} ROM_API_INDEX_e;

#define ROM_APITABLE            ((uint32_t *)0x21010800)

typedef struct
{
    uint8_t gpioPin;
    uint8_t gpioFun;
    uint8_t gpioMode;
    uint8_t pullType;
    uint8_t drive;
    uint8_t smtCtrl;
} GLB_GPIO_Cfg_Type;

typedef enum
{
    GLB_GPIO_PIN_0 = 0,
    GLB_GPIO_PIN_1,
    GLB_GPIO_PIN_2,
    GLB_GPIO_PIN_3,
    GLB_GPIO_PIN_4,
    GLB_GPIO_PIN_5,
    GLB_GPIO_PIN_6,
    GLB_GPIO_PIN_7,
    GLB_GPIO_PIN_8,
    GLB_GPIO_PIN_9,
    GLB_GPIO_PIN_10,
    GLB_GPIO_PIN_11,
    GLB_GPIO_PIN_12,
    GLB_GPIO_PIN_13,
    GLB_GPIO_PIN_14,
    GLB_GPIO_PIN_15,
    GLB_GPIO_PIN_16,
    GLB_GPIO_PIN_17,
    GLB_GPIO_PIN_18,
    GLB_GPIO_PIN_19,
    GLB_GPIO_PIN_20,
    GLB_GPIO_PIN_21,
    GLB_GPIO_PIN_22,
    GLB_GPIO_PIN_MAX,
}GLB_GPIO_Type;

typedef enum {
    SUCCESS = 0,
    ERROR = 1,
    TIMEOUT = 2,
    INVALID = 3, /* invalid arguments */
    NORESC = 4   /* no resource or resource temperary unavailable */
} BL_Err_Type;

#define RomDriver_BL602_Delay_MS \
    ((void (*)(uint32_t cnt))ROM_APITABLE[ROM_API_INDEX_BL602_Delay_MS])
#define RomDriver_GLB_GPIO_Init \
    ((BL_Err_Type(*)(GLB_GPIO_Cfg_Type * cfg)) ROM_APITABLE[ROM_API_INDEX_GLB_GPIO_Init])
#define RomDriver_GLB_GPIO_OUTPUT_Enable \
    ((BL_Err_Type(*)(GLB_GPIO_Type gpioPin))ROM_APITABLE[ROM_API_INDEX_GLB_GPIO_OUTPUT_Enable])
#define RomDriver_GLB_GPIO_OUTPUT_Disable \
    ((BL_Err_Type(*)(GLB_GPIO_Type gpioPin))ROM_APITABLE[ROM_API_INDEX_GLB_GPIO_OUTPUT_Disable])

#endif