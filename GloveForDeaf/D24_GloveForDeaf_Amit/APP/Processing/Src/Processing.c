/*
 * Processing.c
 *
 * Created: 10/4/2022 6:13:16 PM
 *  Author: ALKODS
 */ 

#include "../Inc/Processing.h "


uint8      CheckSign (void)
{
	uint8 FlexSign=10;
	
	if(
	Flex0_u8CheckBending() &&
   !Flex1_u8CheckBending() &&
	Flex2_u8CheckBending() &&
	Flex3_u8CheckBending() &&
	Flex4_u8CheckBending() 		)
	
	{
		FlexSign= YOU_SIGN;
	}
	
	else if(
	Flex0_u8CheckBending() &&
	Flex1_u8CheckBending() &&
	Flex2_u8CheckBending() &&
	Flex3_u8CheckBending() &&
	Flex4_u8CheckBending() 		)
	
	{
		FlexSign= IM_WATCHING_SIGN;
	}
	
	else if(
   !Flex0_u8CheckBending() &&
   !Flex1_u8CheckBending() &&
   !Flex2_u8CheckBending() &&
	Flex3_u8CheckBending() &&
   !Flex4_u8CheckBending() 		)
   
	{
		FlexSign= REALLY_LOVE_U_SIGN;
	}
	
	else if(
   !Flex0_u8CheckBending() &&
   !Flex1_u8CheckBending() &&
    Flex2_u8CheckBending() &&
	Flex3_u8CheckBending() &&
   !Flex4_u8CheckBending() 		)
   
	{
		FlexSign= LOVE_U_SIGN ;
	}
	
	else if(
	Flex0_u8CheckBending() &&
   !Flex1_u8CheckBending() &&
	Flex2_u8CheckBending() &&
	Flex3_u8CheckBending() &&
   !Flex4_u8CheckBending() 		)
   
	{
		FlexSign= THATS_RAHEEB_SIGN;
	}
	
	else if(
	!Flex0_u8CheckBending() &&
	!Flex1_u8CheckBending() &&
	!Flex2_u8CheckBending() &&
	!Flex3_u8CheckBending() &&
	!Flex4_u8CheckBending() 	)
	
	{
		FlexSign= WISH_U_HAPPY_LIFE_SIGN;
	}
	
	else if(
   !Flex0_u8CheckBending() &&
	Flex1_u8CheckBending() &&
	Flex2_u8CheckBending() &&
	Flex3_u8CheckBending() &&
	Flex4_u8CheckBending() 		)
	
	{
		
		FlexSign= GOOD_JOB_SIGN;
	}

	return FlexSign;
}


void    TranslateSign (uint8 Sign)
{
	switch (Sign) {
		
		case YOU_SIGN:
		
		YOU();
		break;
		
		case IM_WATCHING_SIGN:
		
		IM_WATCHING();
		break;
		
		case REALLY_LOVE_U_SIGN:
		
		REALLY_LOVE_U();
		break;
		
		case LOVE_U_SIGN:
		
		LOVE_U();
		break;
		
		case THATS_RAHEEB_SIGN:
		
		THATS_RAHEEB();
		break;
		
		case WISH_U_HAPPY_LIFE_SIGN:

		I_WISH_U_HAPPY_LIFE();
		break;
		
		case GOOD_JOB_SIGN:
		
		GOOD_JOB();
		break;
		
		default:
		br
	}
}