#![no_std]
#![no_main]

use arduino_leonardo::prelude::*;
use arduino_leonardo::pwm;
use panic_halt as _;

/// CW speed as WPM
const WORDS_PER_MINUTE: u8 = 21;

#[arduino_leonardo::entry]
fn main() -> ! {

    // Handle pin mappings for this board
    let dp = arduino_leonardo::Peripherals::take().unwrap();
    let mut pins = arduino_leonardo::Pins::new(dp.PORTB, dp.PORTC, dp.PORTD, dp.PORTE, dp.PORTF);

    // Get and configure GPIO pins
    let mut dah_input = pins.d2;
    let mut dit_input = pins.d3;
    let mut sound_output = pins.d4.into_output(&mut pins.ddr);


}