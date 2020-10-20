
// Pins
#define LONG_INPUT_PIN 2
#define SHORT_INPUT_PIN 3
#define OUTPUT_PIN 4

// Output voltage
#define OUTPUT_VOLTAGE HIGH

// Words per minute
#define WORDS_PER_MINUTE 17

// Calculate the number of dits per second
const int dits_per_second = (WORDS_PER_MINUTE * 50) / 60;
const int ms_per_dit = 1000 / dits_per_second;
const int ms_per_dah = ms_per_dit * 3;
const int ms_per_pause = ms_per_dit ;

// Possible states
enum possible_states { IDLE, DIT, DAH, PAUSE };

// Tracker for the next state
unsigned long state_change_timestamp_ms = 0;
bool next_state = false;

// Current state
possible_states current_state = possible_states::IDLE;

void setup() {
    // Configure all pins
    pinMode(LONG_INPUT_PIN, INPUT);
    pinMode(SHORT_INPUT_PIN, INPUT);
    pinMode(OUTPUT_PIN, OUTPUT);

    // Reset outputs
    digitalWrite(OUTPUT_PIN, LOW);
}

void loop() {
    // Dits take priority over dahs
    if (digitalRead(SHORT_INPUT_PIN)) {
        // If this button was just pressed
        if (current_state != possible_states::DIT &&
            current_state != possible_states::PAUSE) {
            current_state = possible_states::DIT;
            state_change_timestamp_ms = millis() + ms_per_dit;
        }

        // If a pause has run out
        if (current_state == possible_states::PAUSE &&
            state_change_timestamp_ms <= millis()) {
            current_state = possible_states::DIT;
            state_change_timestamp_ms = millis() + ms_per_dit;
        }

    } else if (digitalRead(LONG_INPUT_PIN)) {
        // If this button was just pressed
        if (current_state != possible_states::DAH &&
            current_state != possible_states::PAUSE) {
            current_state = possible_states::DAH;
            state_change_timestamp_ms = millis() + ms_per_dah;
        }

        // If a pause has run out
        if (current_state == possible_states::PAUSE &&
            state_change_timestamp_ms <= millis()) {
            current_state = possible_states::DAH;
            state_change_timestamp_ms = millis() + ms_per_dah;
        }

    } else {        
        state_change_timestamp_ms = 0;
        current_state = possible_states::IDLE;
    }

    // Check if an action needs to be performed
    if (state_change_timestamp_ms <= millis()) {
        if (current_state == possible_states::DIT ||
            current_state == possible_states::DAH) {

            // Wait
            current_state = possible_states::PAUSE;
            state_change_timestamp_ms = millis() + ms_per_pause;
        }
    }

    // Handle each state
    if(current_state == possible_states::IDLE || current_state == possible_states::PAUSE){
        digitalWrite(OUTPUT_PIN, LOW);
    }else if (current_state == possible_states::DIT|| current_state == possible_states::DAH){
        digitalWrite(OUTPUT_PIN, OUTPUT_VOLTAGE);
    }
}
