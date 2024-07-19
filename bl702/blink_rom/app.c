#include "romdriver.h"
#define GLB_BASE         ((uint32_t)0x40000000)
#define GLB_GPIO_OUTPUT_OFFSET    0x188
BL_Err_Type GLB_GPIO_Write(GLB_GPIO_Type gpioPin, uint32_t val)
{
    uint32_t *pOut = (uint32_t *)(GLB_BASE + GLB_GPIO_OUTPUT_OFFSET + ((gpioPin >> 5) << 2));
    uint32_t pos = gpioPin % 32;
    uint32_t tmpOut;

    tmpOut = *pOut;
    if (val > 0) {
        tmpOut |= (1 << pos);
    } else {
        tmpOut &= (~(1 << pos));
    }
    *pOut = tmpOut;

    return SUCCESS;
}

int main() {
	GLB_GPIO_Cfg_Type gpioCfg = {
        .gpioPin = GLB_GPIO_PIN_31,
        .gpioFun = 11,
        .gpioMode = 1,
        .pullType = 2,
        .drive = 0,
        .smtCtrl = 1
    };

    RomDriver_GLB_GPIO_Init(&gpioCfg);
    RomDriver_GLB_GPIO_OUTPUT_Enable(gpioCfg.gpioPin);
    while (1) {
		GLB_GPIO_Write(31, 1);
		RomDriver_BL702_Delay_MS(1000);
		GLB_GPIO_Write(31, 0);
		RomDriver_BL702_Delay_MS(1000);
    }
}