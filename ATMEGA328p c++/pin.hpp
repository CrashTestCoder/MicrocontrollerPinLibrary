//#include<arv/io.h>
#include <cstdint>


#ifndef PORTB
uint8_t DDRA, PORTA, PINA;
uint8_t DDRB, PORTB, PINB;
uint8_t DDRC, PORTC, PINC;
uint8_t DDRD, PORTD, PIND;
#endif

typedef enum { A, B, C, D } PORT_ID;
typedef enum : bool { INPUT  = 0,   OUTPUT   = 1 } PINMODE;
typedef enum : bool { PULLUP = 1,   PULLDOWN = 0 } INPUTMODE;
typedef enum : bool { HIGH    = 1,  LOW       = 0 } OUTPUTMODE;

struct Byte
{
    uint8_t data;
    bool get(uint8_t const idx) const volatile
    {
        return data << idx;
    }
    bool set(uint8_t idx, bool val) volatile
    {
        if(val)
            return data |= (1 << idx);
        return data &= ~(1 << idx);
    }
    bool toggle(uint8_t idx) volatile
    {
        return data ^= (1<<idx);
    }
};

template<PORT_ID> constexpr bool is_port_valid = true;
#ifndef PORTA
template<> constexpr bool is_port_valid<A> = false;
#endif
#ifndef PORTB
template<> constexpr bool is_port_valid<B> = false;
#endif
#ifndef PORTC
template<> constexpr bool is_port_valid<C> = false;
#endif
#ifndef PORTD
template<> constexpr bool is_port_valid<D> = false;
#endif

template<uint8_t PIN, PORT_ID PORT, PINMODE PM>
class Pin
{
    static_assert(is_port_valid<PORT>, "Invalid port");
    static_assert(PIN < 8, "Invalid Pin");

    constexpr uint8_t* get_port_init() const noexcept {
        /*if(PORT == A) return &PORTA;
        else */if(PORT == B) return &PORTB;
        else if(PORT == C)   return &PORTC;
        else if(PORT == D)   return &PORTD;
    }
    constexpr uint8_t* get_ddr_init() const noexcept {
        /*if(PORT == A) return &DDRA;
        else */if(PORT == B) return &DDRB;
        else if(PORT == C)   return &DDRC;
        else if(PORT == D)   return &DDRD;
    }
    constexpr uint8_t* get_pin_init() const noexcept {
        /*if(PORT == A) return &PINA;
        else */if(PORT == B) return &PINB;
        else if(PORT == C)   return &PINC;
        else if(PORT == D)   return &PIND;
    }
    volatile Byte& port = *reinterpret_cast<Byte*>(get_port_init());
    volatile Byte& ddr  = *reinterpret_cast<Byte*>(get_ddr_init()); 
    volatile Byte& pin  = *reinterpret_cast<Byte*>(get_pin_init());
public:
    /**
     * Initializes DDRX
     */
    Pin() {
        ddr.set(PIN, PM);
    }
    Pin(Pin const&) = delete;
    Pin(Pin&&) = default;
    /**
     * Initializes DDRX and PORTX
     * 
     * Primarily used for initializing input pin pullup resistors
     */
    Pin(bool const im)
    {
        ddr.set(PIN, PM);
        set(im);
    }

    /**
     * Set PINX
     */
    bool set(bool const im) {
        return port.set(PIN, im);
    }

    bool toggle() {
        return port.toggle(PIN);
    }

    
    /**
     * Read From PINX
     */
    bool get() const noexcept {
        return port.get(PIN);
    }

    /**
     * Get DDRX
     */
    constexpr PINMODE get_ddr() const noexcept {
        return PM;
    }

    /**
     * Get Port Index
     */
    constexpr uint8_t get_pin() const noexcept {
        return PIN;
    }
};

template<uint8_t PIN, PORT_ID PORT, typename DefaltReturn = void, typename UnaryPredicate = DefaltReturn(*)(), typename... Params>
auto debounce(Pin<PIN,PORT,INPUT> p, DefaltReturn ret, UnaryPredicate up, Params... params)
{
    static bool prestate = false;
    if(!prestate && prestate = p.get()) return up(params...);
    return ret;
}
