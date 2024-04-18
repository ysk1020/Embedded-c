/*TASK NUMBER 2:
    Toggle all LEDs connected to the microcontroller pin.
*/

/*
    STM32 Generated Code
*/

while (1) {
    // Toggle all LEDs
    HAL_GPIO_TogglePiN(GPIOB, GPIO_PIN_8);
    HAL_GPIO_TogglePiN(GPIOB, GPIO_PIN_9);
    HAL_GPIO_TogglePiN(GPIOA, GPIO_PIN_6);
    HAL_GPIO_TogglePiN(GPIOA, GPIO_PIN_5);
    HAL_Delay(1000); // Delay for 1 second
}

/*
    Rest of Generated Code
*/


----------------------------------------------------------------
/*TASK NUMBER 2:
    Blink 4 LEDs alternately with a variable blinking period.
    Use the debugger to change the period to different values.
*/
//delacred global variables delay
int delay = 1000;

/*
STM32 Generated Code 
*/

while (1) {
    // Toggle RED and GREEN LEDs
    HAL_GPIO_TogglePiN(LED_RED_GPIO_Port, LED_RED_Pin);
    HAL_GPIO_TogglePiN(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
    HAL_Delay(delay); // Delay based on the variable 'delay'
    HAL_GPIO_TogglePiN(LED_RED_GPIO_Port, LED_RED_Pin);
    HAL_GPIO_TogglePiN(LED_GREEN_GPIO_Port, LED_GREEN_Pin);

    // Toggle YELLOW and BLUE LEDs
    HAL_GPIO_TogglePiN(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
    HAL_GPIO_TogglePiN(LED_BLUE_GPIO_Port, LED_BLUE_Pin);
    HAL_Delay(delay); // Delay based on the variable 'delay'
    HAL_GPIO_TogglePiN(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
    HAL_GPIO_TogglePiN(LED_BLUE_GPIO_Port, LED_BLUE_Pin);
}

/*
Rest of Generated Code
*/

----------------------------------------------------------------
/*TASK NUMBER 3:
Write a C program to toggle the state of four LEDs in a sequence - 
red, yellow, green, and blue - with a specified delay between each toggle. 
The LEDs should blink continuously in the specified sequence until the program 
is terminated.
*/

//delacred global variables delay
int delay = 1000;

/*
STM32 Generated Code 
*/

while (1){ 
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

/*
Rest of Generated Code
*/

