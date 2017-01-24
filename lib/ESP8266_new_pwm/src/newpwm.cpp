#include <osapi.h>
#include <esp8266_peri.h>

#include "newpwm.h"

int32_t PWMPERIOD = 2500;

static uint8_t nPins = 0;
static uint32_t io_info[PWM_MAX_CHANNELS][3];

int pwmAddChannel(uint8_t pin) {
    if (nPins == PWM_MAX_CHANNELS) {
        return -1;
    }

    io_info[nPins][0] = 0x60000800 + esp8266_gpioToFn[pin];
    io_info[nPins][1] = GPFFS_GPIO(pin);
    io_info[nPins][2] = pin;
    nPins += 1;

    return nPins - 1;
}

void pwmInit(uint32_t period) {
    PWMPERIOD = period;

    uint32_t pwm_duty_init[PWM_MAX_CHANNELS];
    memset(pwm_duty_init, 0, PWM_MAX_CHANNELS * sizeof(uint32_t));

    pwm_init(period, pwm_duty_init, nPins, io_info);
    pwmStart();
}
