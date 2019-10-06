#ifndef _DELAY_H_P_P_
#define _DELAY_H_P_P_

#ifndef F_CPU
#error "Must be included after avr/io.h or similar"
#else

enum inst_t : uint8_t
{
    k_push = 0,
    k_in,
    k_sbiw,
    k_cli,
    k_out,
    k_mov,
    k_ldi,
    k_call,
    k_std,
    k_ldd,
    k_breq,
    k_brne,
    k_adiw,
    k_pop,
    k_ret
};
//https://www.microchip.com/webdoc/avrassembler/
constexpr uint8_t inst[] = {
    [k_push]   = 1,
    [k_in]     = 1,  
    [k_sbiw]   = 2,  
    [k_cli]    = 1,  
    [k_out]    = 1,  
    [k_mov]    = 1,  
    [k_ldi]    = 1,
    [k_call]   = 3,
    [k_std]    = 2,
    [k_ldd]    = 2,
    [k_breq]   = 1,
    [k_brne]   = 2,
    [k_adiw]   = 2,
    [k_pop]    = 2,
    [k_ret]    = 4
};


void wait_ms(unsigned long long const& t)
{
    constexpr int loop_cycles = inst[k_ldd]*8 +
                                inst[k_ldi]*2 +
                                inst[k_call]*2 +
                                inst[k_std]*8 +
                                inst[k_brne];
    volatile unsigned long long delay = t * F_CPU / 1000 / loop_cycles;
loop:
    if(--delay)
        goto loop;
}

#endif /* F_CPU */
#endif /* _DELAY_H_P_P_ */ 