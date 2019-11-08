int main()
{

    unsigned int index_7LED[8] = {Digit_1, Digit_2, Digit_3, Digit_4, Digit_5, Digit_6, Digit_7, Digit_8};
    unsigned int index_7LED_NUM[17] = {Number_0, Number_1, Number_2, Number_3, Number_4, Number_5, Number_6, Number_7,
            Number_8, Number_9, Number_A, Number_b, Number_C, Number_d, Number_E, Number_F, Number_Dot, };


    OS_PowerOnDriverInitial();


    DRV_Printf("====================================\r\n", 0);
    DRV_Printf("   ADP-WT58F2C9 7-SEG demo program   \r\n", 0);
    DRV_Printf("====================================\r\n", 0);


    DRV_Printf("7-SEG testing ...\r\n", 0);

    // Setting for 7LED select
    GPIO_PTA_DIR = 0x0000;
    GPIO_PTA_CFG = 0x0000;
    GPIO_PTA_GPIO = Digit_1;
    // Setting for 7LED number
    GPIO_PTB_DIR = 0x0000;  //for GPIO
    GPIO_PTB_CFG = 0xFFFF;  //for push pull
    GPIO_PTB_PADIN = 0x00;  //for Output
    
    GPIO_PTC_FS = 0x0000;
    GPIO_PTC_PADINSEL = 0x0000;
    GPIO_PTC_DIR = 0xFFFF;
    GPIO_PTC_CFG = 0x0000;

    GPIO_PTD_DIR = 0x0000;
    GPIO_PTD_CFG = 0x0000;
    GPIO_PTD_GPIO = 0x0;


    unsigned int input;
    int LED[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
    int num[3] = {-1,-1,-1};

    int state = 0;
    int step = 0;
    int pre = -1;
    int i;

    while( 1 ){


        input = (GPIO_PTC_PADIN >> 2) & 0x7f;
        
        GPIO_PTB_GPIO = ((~input)<<8) + input;

        if( pre != input ){
            state = step = 0;
            num[0] = num[1] = num[2] = -1;
            int tmp = input;
            int k = 0;
            while( tmp > 0 ){
                num[k++] = tmp%10;
                tmp /= 10;
            }
        }

        if( state == 0 ){
            if( step == 8 ){
                state++;
                step = 0;
            }
            for( i = 0 ; i < 8 ; i++ ){
                LED[i] = -1;
            }
            
            LED[7-step] = num[0];
            
            step++;
        }
        if( state == 1 ){
            if( step == 7 ){
                state++;
                step = 0;
            }
            for( i = 0 ; i < 8 ; i++ ){
                LED[i] = -1;
            }

            LED[0] = num[0];
            LED[7-step] = num[1];

            step++;
        }
        if( state == 2 ){
            if( step == 6 ){
                state++;
                step = 0;
            }
            for( i = 0 ; i < 8 ; i++ ){
                LED[i] = -1;
            }

            LED[0] = num[0];
            LED[1] = num[1];
            LED[7-step] = num[2];


            step++;
        }
        if( state == 3 ){
            if( step == 6 ){
                state++;
                step = 0;
            }
            for( i = 0 ; i < 8 ; i++ ){
                LED[i] = -1;
            }

            LED[step] = num[0];
            LED[step+1] = num[1];
            LED[step+2] = num[2];

            step++;
        }
        if( state == 4 ){
            for( i = 0 ; i < 8 ; i++ ){
                LED[i] = -1;
            }
            LED[5] = num[0];
            LED[6] = num[1];
            LED[7] = num[2];
        }

        pre = input;

        int show = 100;
        while( show-- ){
            for( i = 0 ; i < 8 ; i++ ){
                if( LED[i] != -1 ){
                    GPIO_PTA_GPIO = index_7LED[i];
                    GPIO_PTD_GPIO = index_7LED_NUM[LED[i]];
                    delay1(1000);
                }
            }
            if( state == 0 )
                delay1(2000);
            if( state == 1 )
                delay1(1000);
        }


    }


    DRV_Printf("====================================\r\n", 0);


    return 0;
}
