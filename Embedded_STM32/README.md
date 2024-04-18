# C Embedded Labs
This repository contains C embedded code for various tasks, primarily focused on STM32 microcontrollers.
# Lab 1: Toggle LEDs:
## Task 1: Toggle All LEDs

**Description:** Toggles all LEDs connected to the microcontroller pin.

## Task 2: Blink LEDs Alternately

**Description:** Blinks four LEDs alternately with a variable blinking period. The blinking period can be adjusted using the debugger.

## Task 3: Sequential LED Blinking

**Description:** Toggles the state of four LEDs in sequence - red, yellow, green, and blue - with a specified delay between each toggle. The LEDs blink continuously in the specified sequence until the program is terminated.

# Lab 2: Push buttons:
This repository contains C embedded code for various tasks involving push button presses and LED toggling on STM32 microcontrollers.

## Task 1: Blink LED After Button Presses

**Description:** Starts blinking the LED after a certain number of button presses. Continues counting the number of presses and turns off the LED when the count reaches a specific value.

## Task 2: Indicate Button Presses on LEDs

**Description:** Detects the number of times (up to 7) a push button was pressed and indicates this number of presses in binary on 3 LEDs.

## Task 3: Toggle LED Based on Button Press Duration

**Description:** Toggles the LED if the push button was shortly pressed. If the button is pressed and held for 5 seconds, the LED starts blinking.

# Lab 3: EXTI and GPIO:
This repository contains C embedded code for various tasks involving push button presses and LED toggling on STM32 microcontrollers with interrupts.

## Task 1: Count Button Presses and Blink LED

**Description:** Build a circuit with two push buttons and EXTI. Count the first push-button presses and store it in variable X. If you press the second push button twice, blink an LED X many times.

## Task 3: Toggle LED Based on Button Press Duration

**Description:** Use EXTI to toggle the LED if the push button was shortly pressed. If the button is pressed and held for 5 seconds, the LED should start blinking.

# Lab 4: Timer and PWM:
This repository contains C embedded code for various tasks involving LED toggling, button checking, and PWM control on STM32 microcontrollers.

## Task 1: Toggle LEDs with Different Frequencies

**Description:** Write code to toggle three LEDs. Toggle one LED with a frequency of 1Hz inside the while loop and toggle the other two LEDs with frequencies of 10Hz and 20Hz using two different Timer interrupts (TIM14 and TIM16).

## Task 2: Check User Button

**Description:** Write code to check the user button. If the button is pressed once, the LED is ON for about 10 seconds and then OFF. If the button is pressed twice, the LED blinks for 5 seconds and then turns OFF.

## Task 3: Change LED Brightness using PWM

**Description:** Write code to change the brightness of two LEDs using PWM. The frequency is set to 1 kHz, and the duty cycle changes every 20 milliseconds from 20% to 100% and then back down.
