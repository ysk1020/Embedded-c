/*TASK NUMBER 1:
    Build a circuit with two push buttons and EXTI. Count the first push-button presses and
    store it in X variable. If you press two times second push button - blink a LED X many times.
*/
uint8_t counter = 0;
uint8_t flag = 0;

while(1){
	if(flag == 1 && counter>0)
	{
		HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_SET);
		HAL_Delay(300);
        counter--;
	}
	flag = 0;
    counter = 0;
}

void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == YELLOW_BTN_Pin)
	{
		counter++;
	}
	else if (GPIO_Pin == BLACK_BTN_Pin && counter > 0)
	{
		flag=1;
	}
}

----------------------------------------------------------------
/*TASK NUMBER 3:
    Use EXTI to Write the code for toggling the LED if the push button was shortly pressed. If
    the button is pressed and held for 5 seconds, the LED should start blinking.
*/
uint32_t counterBTN = 0;
int blinkingFlag = 0;
int flag_led = 0;	

while (1)
  {
	  if (HAL_GPIO_ReadPin(USER_Btn_GPIO_Port, USER_Btn_Pin) == GPIO_PIN_SET && (HAL_GetTick() - counterBTN >= 5000))
	  {
		  blinkingFlag = 1;
	  }
	  if (HAL_GPIO_ReadPin(USER_Btn_GPIO_Port, USER_Btn_Pin) == GPIO_PIN_RESET && blinkingFlag)
	  {
		  blinkingFlag = 0;
		  counterBTN = 0;
	  }
	  if (blinkingFlag)
	  {
		  HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
		  HAL_Delay(200);
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == USER_Btn_Pin)
    {
        if (HAL_GPIO_ReadPin(USER_Btn_GPIO_Port, USER_Btn_Pin) == GPIO_PIN_SET)
        {
            counterBTN = HAL_GetTick();
            flag_led =1;
        }
        else
        {
        	if(!blinkingFlag)
        	{
        		HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
        	}
            blinkingFlag = 0;
            counterBTN = 0;
        }
    }
}

