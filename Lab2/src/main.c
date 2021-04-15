/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "string.h"
#include "math.h"
#include <inttypes.h>

typedef struct {
	int32_t s;
	int32_t e;
	int32_t m;
} MyFloat;


void print_result(int32_t m, int32_t e){
	int32_t count = 0;
	int32_t num = m;
	if (m < 0){
		m = m * -1;
		trace_printf("%c", '-');
	}
	do
	    {
	        count++;
	        num /= 10;
	    } while(num != 0);

	char snum[count];
	itoa(m, snum, 10);
//	trace_printf("%d", sizeof(snum)/sizeof(snum[0]));
	if (e >= 0){
		trace_printf("%d", m);
		int32_t i;
		for (i = 0; i < e; i++){
			trace_printf("%d", 0);
		}
		trace_printf("\n");

	}else if(e < 0 && e * -1 < count){
		int32_t i;
		if (snum[0] == '-'){
				e = e + 1;
		}
		for (i = 0; i < count - e * -1; i++){
			trace_printf("%c", snum[i]);
		}
		trace_printf("%c", ',');
		for (i = count - e * -1; i <= count; i++){
			trace_printf("%c", snum[i]);
		}
		trace_printf("\n");


	}else{
		int32_t i;
		trace_printf("%d", 0);
		trace_printf("%c", ',');
		for (i = 0; i <= e * -1 - floor(log10(abs(m))) - 2; i++){
			trace_printf("%d", 0);
		}
		trace_printf("%d\n", m);

	}
}




void minus(MyFloat *mf1, MyFloat *mf2){
	int32_t m_new, e_new, s_new;
	int32_t dif;

	if (mf1->s == 1 && mf2->s == 0){
			mf2->s = 1;
			plus(mf2, mf1);
			mf2->s = 0;

	}
	else if (mf2->s == 1){
		mf2->s = 0;
		plus(mf1, mf2);
		mf2->s = 1;


	}
	else{

		if (mf1->e > mf2->e){
			dif = mf1->e - mf2->e;
			m_new = (mf2->m * pow(10, dif) - mf1->m) * -1;
			e_new = mf1->e;

		}
		else{
			dif = mf2->e - mf1->e;
			m_new = mf1->m * pow(10, dif) - mf2->m;
			e_new = mf2->e;

		}

		trace_printf ("%d * 10^", m_new);
		trace_printf ("%d = ", e_new * -1);
		print_result(m_new, e_new * -1);
	}
}


void plus(MyFloat *mf1, MyFloat *mf2){
	int32_t m_new, e_new, s_new;
	int32_t dif;

	if (mf1->s == 1 && mf2->s == 0){
		mf1->s = 0;
		minus(mf2, mf1);
		mf1->s = 1;

	}
	else if (mf1->s == 0 && mf2->s == 1){
		mf2->s = 0;
		minus(mf1, mf2);
		mf2->s = 1;

	}
	else{

		if (mf1->s == 1 && mf1->s == 1){
			s_new = 1;
		}
		else{
			s_new = 0;
		}

		if (mf1->e > mf2->e){
			dif = mf1->e - mf2->e;
			m_new = mf2->m * pow(10, dif) + mf1->m;
			e_new = mf1->e;

		}
		else{
			dif = mf2->e - mf1->e;
			m_new = mf1->m * pow(10, dif) + mf2->m;
			e_new = mf2->e;

		}

	//	m_new = mf1->m + mf2->m * pow(10, (mf2->e - mf1->e));
	//	MyFloat mf_new;
	//	mf_new.s = 0;
	//	mf_new.e = e_new;
	//	mf_new.m = m_new;

		trace_printf ("%d * 10^", m_new);
		trace_printf ("%d = ", e_new*-1);
		if (s_new == 0){
			print_result(m_new, e_new * -1);

		}
		else {
			print_result(m_new * -1, e_new * -1);

		}
	}

}



void multi(MyFloat *mf1, MyFloat *mf2){

	int32_t m_new, e_new, s_new;
	m_new = mf2->m * mf1->m;
//	trace_printf("%" PRIu32 "\n",mf2->m);
//	trace_printf ("\n%d\n", m_new);

	e_new = mf2->e + mf1->e;
	if ((mf1->s == 1 && mf2->s == 0) || (mf1->s == 0 && mf2->s == 1))
	{
		trace_printf ("Multiplication: %d * 10^", m_new * -1);
		trace_printf ("%d = ", e_new * -1);
		print_result(m_new * -1, e_new * -1);

	}else {
		trace_printf ("Multiplication: %d * 10^", m_new);
		trace_printf ("%d = ", e_new * -1);
		print_result(m_new, e_new * -1);

	}
}


void dev(MyFloat *mf1, MyFloat *mf2){
	mf1->m = mf1->m * 100000;
	mf1->e = mf1->e + 5;
	int32_t m_new, e_new, s_new;
	m_new = mf1->m / mf2->m;
	e_new = mf1->e - mf2->e;

	trace_printf ("Division: ");
	print_result(m_new, e_new * -1);


}


void removeChar(char *str, char garbage) {

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}

void removeLeft(char *str, char garbage) {

    char *src, *dst;
    int32_t write = 0;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;

        if (write){
                	dst++;
                }
        if (*dst == garbage) {
        	write = 1;
        }

    }
    *dst = '\0';
}

void SystemClock_Config(void);

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  HAL_Init();
  SystemClock_Config();

  MyFloat mf1;
  char* test1 = malloc(sizeof(int32_t)+1);
  strcpy(test1, "4.002");
  trace_printf ("Float_1 = %s\n", test1);
  char* buf = malloc(strlen(test1));
  strcpy(buf, test1);
  if (test1[0] == '-'){
	  mf1.s = 1;
	  removeChar(test1, '-');
	  removeChar(buf, '-');

  }
  else{
	  mf1.s = 0;

  }


  removeChar(test1, '.');
  mf1.m = atoi(test1);
  removeLeft(buf, '.');
  mf1.e = strlen(buf);


  MyFloat mf2;
  char* test2 = malloc(sizeof(int32_t)+1);
  strcpy(test2, "0.03");
  trace_printf ("Float_2 = %s\n", test2);

  char* buf2 = malloc(strlen(test2));
  strcpy(buf2, test2);
  if (test2[0] == '-'){
  	  mf2.s = 1;
  	  removeChar(test2, '-');
  	  removeChar(buf2, '-');

    }
    else{
  	  mf2.s = 0;

    }
  removeChar(test2, '.');
  mf2.m = atoi(test2);
  removeLeft(buf2, '.');
  mf2.e = strlen(buf2);


  trace_printf("Addition: ");
  plus(&mf1, &mf2);
  trace_printf("Subtraction: ");
  minus(&mf1, &mf2);
  multi(&mf1, &mf2);
  dev(&mf1, &mf2);



}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
