# C Embedded Labs
This repository contains C embedded code for various tasks, primarily focused on STM32 microcontrollers.

# Task 1: Toggle All LEDs

**Description:** Toggles all LEDs connected to the microcontroller pin.

```c
while (1) {
    // Toggle all LEDs
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_8);
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_9);
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
    HAL_Delay(1000); // Delay for 1 second
}
```

## Task 2: Blink LEDs Alternately

**Description:** Blinks four LEDs alternately with a variable blinking period. The blinking period can be adjusted using the debugger.

```c
int delay = 1000;

while (1) {
    // Toggle RED and GREEN LEDs
    HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
    HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
    HAL_Delay(delay); // Delay based on the variable 'delay'
    HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
    HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);

    // Toggle YELLOW and BLUE LEDs
    HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
    HAL_GPIO_TogglePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin);
    HAL_Delay(delay); // Delay based on the variable 'delay'
    HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
    HAL_GPIO_TogglePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin);
}
```

## Task 3: Sequential LED Blinking

**Description:** Toggles the state of four LEDs in sequence - red, yellow, green, and blue - with a specified delay between each toggle. The LEDs blink continuously in the specified sequence until the program is terminated.

```c
int delay = 1000;

while (1) {
    HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin); 
    HAL_Delay(delay); 
    HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);

    HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin); 
    HAL_Delay(delay); 
    HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);

    HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin); 
    HAL_Delay(delay); 
    HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);

    HAL_GPIO_TogglePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin); 
    HAL_Delay(delay);
    HAL_GPIO_TogglePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin);
}
```

Feel free to expand or modify this README to include more details or instructions as needed.

## Task 2: Blink LEDs Alternately
Description: Blinks four LEDs alternately with a variable blinking period. The blinking period can be adjusted using the debugger.

## Task 3: Sequential LED Blinking
Description: Toggles the state of four LEDs in sequence (red, yellow, green, blue) with a specified delay between each toggle.

## Task 4: Button Press Detection
Description: Detects button presses and performs different actions based on the number of presses. The LED blinks a specific number of times if a certain condition is met.

## Task 5: Binary Representation of Button Presses
Description: Displays the number of button presses in binary on three LEDs. Each LED represents a binary digit.

## Task 6: LED Toggle on Button Press
Description: Toggles an LED if the push button is shortly pressed. If the button is held for 5 seconds, the LED starts blinking.

## Task 7: Push Button Counter
Description: Counts the number of presses of two push buttons using EXTI interrupts. If the second button is pressed twice, an LED blinks a number of times equal to the count of the first button presses.
