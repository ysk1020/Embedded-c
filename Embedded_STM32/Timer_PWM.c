/*TASK 1    
Write code for toggle 3 LEDs. Toggle one LED with 1Hz frequency inside of the while(1)
loop and two other LEDs with 10 Hz and 20Hz using two different Timer’s (TIM14 and
TIM16) interrupts.
*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim == &htim3) {
        // Handle interrupt from htim3
        HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
    } else if (htim == &htim4) {
        // Handle interrupt from htim4
        HAL_GPIO_TogglePin(GREEN_GPIO_Port, GREEN_Pin);
    }
}

/* USER CODE BEGIN 2 */
HAL_TIM_Base_Start_IT(&htim3);

HAL_TIM_Base_Start_IT(&htim4);

  /* USER CODE END 2 */


  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)
  {
	  HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
	  HAL_Delay(500);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */

----------------------------------------------------------------

/*TASK 2
3.5. Write code for the check User button. If the button is pressed one-time LED is ON for
about 10 sek and then OFF. If the button is pressed like “double click” LED must blink 5
seconds and after must be OFF. For time counting – please use Timer interrupt. You
should use HAL_TIM_Base_Start_IT function.
*/

typedef enum {
    IDLE,
    PRESSED_ONCE,
    PRESSED_TWICE
} ButtonState;

ButtonState buttonState = IDLE;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	static int blink = 0;

	if(htim == &htim10 && buttonState == PRESSED_ONCE)
	{
		HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, GPIO_PIN_RESET);
		HAL_TIM_Base_Stop_IT(&htim10);
		buttonState = IDLE;
	}
	if(htim == &htim12 && buttonState == PRESSED_TWICE)
	{
		HAL_GPIO_TogglePin(RED_GPIO_Port, RED_Pin);
		blink++;
		if(blink>=15)
		{
			HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, GPIO_PIN_RESET);
			HAL_TIM_Base_Stop_IT(&htim12);
			blink=0;
			buttonState = IDLE;
		}
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    uint32_t currTime =  HAL_GetTick();

    if(GPIO_Pin == USER_BTN_Pin)
    {
        if(currTime - lastTime > 50)  
        {
            if(buttonState == IDLE)
            {
                buttonState = PRESSED_ONCE;
                HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, GPIO_PIN_SET);
                HAL_TIM_Base_Start_IT(&htim10);
            }
            else if(buttonState == PRESSED_ONCE)
            {
                buttonState = PRESSED_TWICE;
                HAL_TIM_Base_Stop_IT(&htim10);
                HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, GPIO_PIN_SET);
                HAL_TIM_Base_Start_IT(&htim12);  
            }
            lastTime = currTime;
        }
    }
}
----------------------------------------------------------------
/*TASK 3
3.6. Write code for changing two LED brightness using PWM (frequency 1 kHz and duty change
every 20 mS, up from 20% to 100% and down).
*/
/* USER CODE BEGIN 2 */

  HAL_TIM_PWM_Start(&htim12, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  
	  for (int duty_c = 51; duty_c <= 255; duty_c++) 
	  {
		  __HAL_TIM_SET_COMPARE(&htim12, TIM_CHANNEL_1, duty_c);
		  __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, duty_c);
		  HAL_Delay(20); 
	  }

	  
	  for (int duty_c = 255; duty_c >= 51; duty_c--) 
	  {
		  __HAL_TIM_SET_COMPARE(&htim12, TIM_CHANNEL_1, duty_c);
		  __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, duty_c);
		  HAL_Delay(20); 
	  }
