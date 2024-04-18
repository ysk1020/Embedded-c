/*TASK NUMBER 1:
Write the code to start blinking the LED after X(as an example 5 times) presses a push
button. Continue counting the number of presses and turn LED off when the number
reaches X+Y time (as an example 5+5=10). Store the number of presses into a separate
global variable. 
*/

/*
STM32 Generated Code 
*/
while (1) {
    if (HAL_GPIO_ReadPin(BTN_EX_GPIO_Port, BTN_EX_Pin) == GPIO_PIN_SET) {
        HAL_Delay(300);
        
        if (HAL_GPIO_ReadPin(BTN_EX_GPIO_Port, BTN_EX_Pin) == GPIO_PIN_SET) {
            buttonPressCount++;
            
            if (buttonPressCount >= 5 && buttonPressCount <= 10) {
                // Your logic for handling button presses between 5 and 10
            }
            
            if (buttonPressCount >= 10) {
                HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
                HAL_Delay(500);
                
                // Check for additional button press
                if (HAL_GPIO_ReadPin(BTN_EX_GPIO_Port, BTN_EX_Pin) == GPIO_PIN_SET) {
                    buttonPressCount++;
                    HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
                }
            }
        }
    }
}

/*
Rest of Generated Code
*/
----------------------------------------------------------------
/*TASK NUMBER 2:
Write the code for detecting how many times (until 7) the push-button was pressed and
indicate this number of presses in binary on 3 LED’s, like:
If 1 press – 001
If 2 presses – 010
An etc.
*/

/*
STM32 Generated Code 
*/
while(){
    if (HAL_GPIO_ReadPin(BTN_EX_GPIO_Port, BTN_EX_Pin) == GPIO_PIN_SET) {
        HAL_Delay(300);

        if (HAL_GPIO_ReadPin(BTN_EX_GPIO_Port, BTN_EX_Pin) == GPIO_PIN_SET) {
            buttonPressCount++;

            if (buttonPressCount <= 7) {
                switch (buttonPressCount) {
                    case 1:
                        HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
                        break;
                    case 2:
                        HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
                        HAL_GPIO_TogglePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin);
                        break;
                    case 3:
                        HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
                        HAL_GPIO_TogglePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin);
                        HAL_GPIO_TogglePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin);
                        break;
                    case 4:
                        // Toggle other LEDs based on your requirements
                        break;
                    // Add cases for other button press counts
                    default:
                        break;
                }
            } else {
                buttonPressCount = 8;
                HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
                HAL_GPIO_TogglePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin);
                HAL_GPIO_TogglePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin);
            }
        }
    }
}
/*
Rest of Generated Code
*/
----------------------------------------------------------------
/*TASK NUMBER 3 :
Write the code for toggling the LED if the push button was shortly pressed. If the button is
pressed and held for 5 seconds, the LED should start blinking
*/

/*
STM32 Generated Code 
*/while (1) {
    if (HAL_GPIO_ReadPin(BTN_EX_GPIO_Port, BTN_EX_Pin) == GPIO_PIN_RESET) 
    {
        HAL_Delay(100);
        buttonPressCount++;

        if (HAL_GPIO_ReadPin(BTN_EX_GPIO_Port, BTN_EX_Pin) == GPIO_PIN_SET) 
        {
            while (buttonPressCount < 8 && HAL_GPIO_ReadPin(BTN_EX_GPIO_Port, BTN_EX_Pin) == GPIO_PIN_RESET) 
            {
                HAL_Delay(100);
                buttonPressCount++;
            }

            if (buttonPressCount < 50) 
            {
                HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
                HAL_GPIO_TogglePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin);
                HAL_GPIO_TogglePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin);
                buttonPressCount = 0;
            } 
            else 
            {
                while (HAL_GPIO_ReadPin(BTN_EX_GPIO_Port, BTN_EX_Pin) == GPIO_PIN_SET) 
                {
                    HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
                    HAL_GPIO_TogglePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin);
                    HAL_GPIO_TogglePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin);
                    HAL_Delay(500);
                    buttonPressCount = 0;
                }
            }
        }
    }
}


/*
Rest of Generated Code
*/