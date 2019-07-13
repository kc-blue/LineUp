/**
  ******************************************************************************
  * @file    LCD12864.c
  * @author  newlab edu
  ch12864c driver
  ******************************************************************************
**/

#include "stdio.h"
#include "stm32f10x_gpio.h"
#include "LCD12864.h"
//#incldue "debug_printf.h"
#include "debug_printf.h"

const unsigned char newLandEduLogo[]=	
{//New land edu logo,128*64
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0xF0,0xF8,0xFC,0xFE,
0xFE,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x60,0xE0,0xE0,0x78,0x78,0xE0,0xE0,0x60,0x60,0xE0,0xE0,0x60,0x60,0x60,
0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE0,0xE0,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xC0,0xC0,
0xC0,0xC0,0xE0,0xE0,0xC0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0xF0,0xF0,
0xF0,0xE0,0xC0,0xE0,0x20,0xE0,0xF0,0xF0,0xC0,0xC0,0xC0,0xC0,0x00,0x00,0x00,0x00,
0x60,0x60,0x60,0xE0,0xE0,0xE0,0xE0,0x70,0x70,0x70,0x60,0xE0,0xE0,0x60,0x60,0x60,
0x00,0xC0,0xE0,0xE0,0xF0,0xF8,0xFC,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xF8,0xF8,0xE0,0xE0,0x80,0x80,
0x00,0x00,0xFA,0xFA,0xFB,0xFF,0xFE,0xFF,0xFB,0x9A,0x9A,0xFF,0xFF,0x02,0xFE,0xFE,
0xFE,0x02,0x00,0x00,0x00,0x03,0x03,0x03,0x03,0x83,0xE3,0xFB,0xFF,0xFF,0xFF,0x83,
0x83,0x03,0x03,0x03,0x03,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xBF,0xFF,0xE0,0xE6,0xE6,
0xE6,0x06,0xFF,0xFF,0x06,0xE6,0xE6,0x06,0x00,0x00,0x00,0x00,0xBA,0x9A,0x9F,0xDF,
0xFF,0xFF,0xBB,0xBB,0x03,0x1F,0x7F,0xF8,0xF0,0xFF,0x0F,0x00,0x00,0x00,0x00,0x00,
0x00,0xFB,0xFB,0xFB,0x6B,0x6B,0x6B,0x6B,0x6B,0x6B,0x6B,0x6B,0xFB,0xFB,0x02,0x00,
0x00,0x00,0x01,0x03,0x87,0x8F,0xCF,0xEF,0x33,0xBB,0xCC,0xEE,0x31,0xBB,0xC7,0xEF,
0x1F,0xBF,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0x3F,0xBF,0x9F,0x0F,0x07,0x03,0x01,0x00,
0x00,0x00,0x0F,0x07,0x03,0x0F,0x0F,0x0F,0x01,0x03,0x07,0x07,0x03,0x00,0x0F,0x0F,
0x0F,0x00,0x00,0x00,0x00,0x0C,0x0E,0x06,0x07,0x03,0x03,0x01,0x00,0x00,0x03,0x03,
0x07,0x06,0x06,0x0E,0x0C,0x00,0x00,0x00,0x0F,0x0F,0x0F,0x01,0x01,0x01,0x07,0x0F,
0x0F,0x0C,0x0F,0x0F,0x0C,0x0F,0x0F,0x00,0x00,0x00,0x00,0x00,0x01,0x0D,0x0D,0x0F,
0x0F,0x07,0x00,0x0C,0x0E,0x06,0x03,0x03,0x03,0x07,0x06,0x0E,0x00,0x00,0x00,0x00,
0x00,0x0F,0x0F,0x0F,0x03,0x03,0x03,0x03,0x03,0x03,0x0B,0x0F,0x0F,0x0F,0x00,0x00,
0x00,0x0C,0x0E,0x37,0x3B,0xDB,0xEC,0xEE,0x33,0xFB,0xCC,0xEE,0x33,0xBB,0xCC,0xEE,
0x33,0xBB,0xCC,0xEF,0x33,0xBB,0xCC,0xEE,0x33,0xBB,0xCC,0xEE,0x26,0x3A,0x18,0x00,
0x00,0x00,0xFE,0xFE,0x3E,0x78,0xF0,0xC0,0xFE,0xFE,0xFE,0xE0,0xF8,0xB8,0x98,0xD8,
0xF8,0x78,0xB8,0x28,0xF8,0xF0,0x80,0xE0,0xF8,0xF8,0xE0,0xC0,0xF8,0x38,0xFE,0xFE,
0xFE,0xE0,0xF8,0x38,0x38,0x18,0x18,0x38,0xF8,0xE0,0xE0,0xF0,0xF8,0x38,0x18,0x38,
0xF8,0xE0,0xE0,0xF0,0xF8,0x38,0x18,0x18,0x38,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0xFE,0xFE,0x66,0x66,0x66,0x66,0x66,0x06,0x00,0xE0,0xF8,0x38,0x18,
0x18,0x38,0x00,0xFE,0xFE,0x00,0xF8,0xF8,0x00,0x00,0x00,0xF8,0xF8,0xF8,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x03,0x0B,0x0C,0x2E,0x33,0xBB,0xCC,0xEE,
0x33,0xBB,0xCC,0xEE,0x33,0x3B,0x0C,0x0E,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x0F,0x0F,0x00,0x00,0x01,0x03,0x0F,0x0F,0x0F,0x01,0x07,0x07,0x0F,0x0C,
0x0E,0x06,0x07,0x00,0x00,0x03,0x0F,0x07,0x01,0x03,0x0F,0x0F,0x03,0x00,0x0F,0x0F,
0x0F,0x01,0x07,0x07,0x0E,0x0E,0x0E,0x06,0x0F,0x0F,0x0F,0x0F,0x0F,0x00,0x00,0x00,
0x0F,0x0F,0x03,0x03,0x0F,0x0E,0x0E,0x0E,0x0F,0x07,0x03,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x0F,0x0F,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x00,0x03,0x07,0x0E,0x0E,
0x0E,0x0E,0x07,0x03,0x00,0x00,0x03,0x0F,0x0E,0x0E,0x0E,0x0F,0x07,0x03,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,
0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};


#define ASCILL_TO_CODE_INDEX	32
// 8 x 16 font
// 1 pixel space at left and bottom
// index = ASCII - 32
// !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
unsigned char char_code_8x16[][16] =
{
/*--  文字:  space --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  !  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x33,0x00,0x00,0x00,0x00},

/*--  文字:  "  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x10,0x0C,0x02,0x10,0x0C,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  #  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x40,0xC0,0x78,0x40,0xC0,0x78,0x00,0x00,0x04,0x3F,0x04,0x04,0x3F,0x04,0x00},

/*--  文字:  $  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x70,0x88,0x88,0xFC,0x08,0x30,0x00,0x00,0x18,0x20,0x20,0xFF,0x21,0x1E,0x00},

/*--  文字:  %  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0xF0,0x08,0xF0,0x80,0x60,0x18,0x00,0x00,0x00,0x31,0x0C,0x03,0x1E,0x21,0x1E,0x00},

/*--  文字:  &  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0xF0,0x08,0x88,0x70,0x00,0x00,0x00,0x1E,0x21,0x23,0x2C,0x19,0x27,0x21,0x10},

/*--  文字:  '  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x12,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  (  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x00,0xE0,0x18,0x04,0x02,0x00,0x00,0x00,0x00,0x07,0x18,0x20,0x40,0x00},

/*--  文字:  )  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x02,0x04,0x18,0xE0,0x00,0x00,0x00,0x00,0x40,0x20,0x18,0x07,0x00,0x00,0x00},

/*--  文字:  *  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x40,0x40,0x80,0xF0,0x80,0x40,0x40,0x00,0x02,0x02,0x01,0x0F,0x01,0x02,0x02,0x00},

/*--  文字:  +  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x0F,0x01,0x01,0x01},

/*--  文字:  ,  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0x70,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  -  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x00},

/*--  文字:  .  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  /  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x00,0x00,0xC0,0x38,0x04,0x00,0x00,0x60,0x18,0x07,0x00,0x00,0x00,0x00},

/*--  文字:  0  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0xE0,0x10,0x08,0x08,0x10,0xE0,0x00,0x00,0x0F,0x10,0x20,0x20,0x10,0x0F,0x00},

/*--  文字:  1  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x10,0x10,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00},

/*--  文字:  2  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x70,0x08,0x08,0x08,0x08,0xF0,0x00,0x00,0x30,0x28,0x24,0x22,0x21,0x30,0x00},

/*--  文字:  3  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x30,0x08,0x08,0x08,0x88,0x70,0x00,0x00,0x18,0x20,0x21,0x21,0x22,0x1C,0x00},

/*--  文字:  4  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x80,0x40,0x30,0xF8,0x00,0x00,0x00,0x06,0x05,0x24,0x24,0x3F,0x24,0x24},

/*--  文字:  5  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0xF8,0x88,0x88,0x88,0x08,0x08,0x00,0x00,0x19,0x20,0x20,0x20,0x11,0x0E,0x00},

/*--  文字:  6  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0xE0,0x10,0x88,0x88,0x90,0x00,0x00,0x00,0x0F,0x11,0x20,0x20,0x20,0x1F,0x00},

/*--  文字:  7  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x18,0x08,0x08,0x88,0x68,0x18,0x00,0x00,0x00,0x00,0x3E,0x01,0x00,0x00,0x00},

/*--  文字:  8  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x70,0x88,0x08,0x08,0x88,0x70,0x00,0x00,0x1C,0x22,0x21,0x21,0x22,0x1C,0x00},

/*--  文字:  9  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0xF0,0x08,0x08,0x08,0x10,0xE0,0x00,0x00,0x01,0x12,0x22,0x22,0x11,0x0F,0x00},

/*--  文字:  :  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x00,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00},

/*--  文字:  ;  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0x00},

/*--  文字:  <  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x80,0x40,0x20,0x10,0x08,0x00,0x00,0x01,0x02,0x04,0x08,0x10,0x20,0x00},

/*--  文字:  =  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x02,0x02,0x02,0x02,0x02,0x02,0x00},

/*--  文字:  >  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x08,0x10,0x20,0x40,0x80,0x00,0x00,0x00,0x20,0x10,0x08,0x04,0x02,0x01,0x00},

/*--  文字:  ?  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x70,0x48,0x08,0x08,0x88,0x70,0x00,0x00,0x00,0x00,0x30,0x37,0x00,0x00,0x00},

/*--  文字:  @  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0xC0,0x30,0xC8,0x28,0xE8,0x10,0xE0,0x00,0x07,0x18,0x27,0x28,0x2F,0x28,0x17,0x00},

/*--  文字:  A  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0xC0,0x38,0xE0,0x00,0x00,0x00,0x20,0x3C,0x23,0x02,0x02,0x27,0x38,0x20},

/*--  文字:  B  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x08,0xF8,0x88,0x88,0x88,0x70,0x00,0x00,0x20,0x3F,0x20,0x20,0x20,0x11,0x0E,0x00},

/*--  文字:  C  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0xC0,0x30,0x08,0x08,0x08,0x08,0x38,0x00,0x07,0x18,0x20,0x20,0x20,0x10,0x08,0x00},

/*--  文字:  D  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x08,0xF8,0x08,0x08,0x08,0x10,0xE0,0x00,0x20,0x3F,0x20,0x20,0x20,0x10,0x0F,0x00},

/*--  文字:  E  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x08,0xF8,0x88,0x88,0xE8,0x08,0x10,0x00,0x20,0x3F,0x20,0x20,0x23,0x20,0x18,0x00},

/*--  文字:  F  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x08,0xF8,0x88,0x88,0xE8,0x08,0x10,0x00,0x20,0x3F,0x20,0x00,0x03,0x00,0x00,0x00},

/*--  文字:  G  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0xC0,0x30,0x08,0x08,0x08,0x38,0x00,0x00,0x07,0x18,0x20,0x20,0x22,0x1E,0x02,0x00},

/*--  文字:  H  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x08,0xF8,0x08,0x00,0x00,0x08,0xF8,0x08,0x20,0x3F,0x21,0x01,0x01,0x21,0x3F,0x20},

/*--  文字:  I  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x08,0x08,0xF8,0x08,0x08,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00},

/*--  文字:  J  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x08,0x08,0xF8,0x08,0x08,0x00,0xC0,0x80,0x80,0x80,0x7F,0x00,0x00,0x00},

/*--  文字:  K  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x08,0xF8,0x88,0xC0,0x28,0x18,0x08,0x00,0x20,0x3F,0x20,0x01,0x26,0x38,0x20,0x00},

/*--  文字:  L  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x08,0xF8,0x08,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x20,0x20,0x20,0x20,0x30,0x00},

/*--  文字:  M  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x08,0xF8,0xF8,0x00,0xF8,0xF8,0x08,0x00,0x20,0x3F,0x01,0x3E,0x01,0x3F,0x20,0x00},

/*--  文字:  N  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x08,0xF8,0x30,0xC0,0x00,0x08,0xF8,0x08,0x20,0x3F,0x20,0x00,0x07,0x18,0x3F,0x00},

/*--  文字:  O  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0xE0,0x10,0x08,0x08,0x08,0x10,0xE0,0x00,0x0F,0x10,0x20,0x20,0x20,0x10,0x0F,0x00},

/*--  文字:  P  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x08,0xF8,0x08,0x08,0x08,0x08,0xF0,0x00,0x20,0x3F,0x21,0x01,0x01,0x01,0x00,0x00},

/*--  文字:  Q  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0xE0,0x10,0x08,0x08,0x08,0x10,0xE0,0x00,0x0F,0x10,0x28,0x28,0x30,0x50,0x4F,0x00},

/*--  文字:  R  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x08,0xF8,0x88,0x88,0x88,0x88,0x70,0x00,0x20,0x3F,0x20,0x00,0x03,0x0C,0x30,0x20},

/*--  文字:  S  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x70,0x88,0x08,0x08,0x08,0x38,0x00,0x00,0x38,0x20,0x21,0x21,0x22,0x1C,0x00},

/*--  文字:  T  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x18,0x08,0x08,0xF8,0x08,0x08,0x18,0x00,0x00,0x00,0x20,0x3F,0x20,0x00,0x00,0x00},

/*--  文字:  U  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x08,0xF8,0x08,0x00,0x00,0x08,0xF8,0x08,0x00,0x1F,0x20,0x20,0x20,0x20,0x1F,0x00},

/*--  文字:  V  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x08,0x78,0x88,0x00,0x00,0xC8,0x38,0x08,0x00,0x00,0x07,0x38,0x0E,0x01,0x00,0x00},

/*--  文字:  W  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x08,0xF8,0x00,0xF8,0x00,0xF8,0x08,0x00,0x00,0x03,0x3E,0x01,0x3E,0x03,0x00,0x00},

/*--  文字:  X  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x08,0x18,0x68,0x80,0x80,0x68,0x18,0x08,0x20,0x30,0x2C,0x03,0x03,0x2C,0x30,0x20},

/*--  文字:  Y  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x08,0x38,0xC8,0x00,0xC8,0x38,0x08,0x00,0x00,0x00,0x20,0x3F,0x20,0x00,0x00,0x00},

/*--  文字:  Z  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x10,0x08,0x08,0x08,0xC8,0x38,0x08,0x00,0x20,0x38,0x26,0x21,0x20,0x20,0x18,0x00},

/*--  文字:  [  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x00,0xFE,0x02,0x02,0x02,0x00,0x00,0x00,0x00,0x7F,0x40,0x40,0x40,0x00},

/*--  文字:  \  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x04,0x38,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x06,0x38,0xC0,0x00},

/*--  文字:  ]  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x02,0x02,0x02,0xFE,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x7F,0x00,0x00,0x00},

/*--  文字:  ^  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x04,0x02,0x02,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  _  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},

/*--  文字:  `  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x02,0x02,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  a  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x19,0x24,0x24,0x12,0x3F,0x20,0x00},

/*--  文字:  b  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x10,0xF0,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x3F,0x11,0x20,0x20,0x11,0x0E,0x00},

/*--  文字:  c  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x00,0x80,0x80,0x80,0x00,0x00,0x00,0x0E,0x11,0x20,0x20,0x20,0x11,0x00},

/*--  文字:  d  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x80,0x80,0x80,0x90,0xF0,0x00,0x00,0x1F,0x20,0x20,0x20,0x10,0x3F,0x20},

/*--  文字:  e  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x1F,0x24,0x24,0x24,0x24,0x17,0x00},

/*--  文字:  f  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x80,0x80,0xE0,0x90,0x90,0x20,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00},

/*--  文字:  g  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x6B,0x94,0x94,0x94,0x93,0x60,0x00},

/*--  文字:  h  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x10,0xF0,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x3F,0x21,0x00,0x00,0x20,0x3F,0x20},

/*--  文字:  i  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x80,0x98,0x98,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00},

/*--  文字:  j  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x00,0x80,0x98,0x98,0x00,0x00,0x00,0xC0,0x80,0x80,0x80,0x7F,0x00,0x00},

/*--  文字:  k  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x10,0xF0,0x00,0x00,0x80,0x80,0x80,0x00,0x20,0x3F,0x24,0x06,0x29,0x30,0x20,0x00},

/*--  文字:  l  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x10,0x10,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00},

/*--  文字:  m  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x20,0x3F,0x20,0x00,0x3F,0x20,0x00,0x3F},

/*--  文字:  n  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x3F,0x21,0x00,0x00,0x20,0x3F,0x20},

/*--  文字:  o  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x1F,0x20,0x20,0x20,0x20,0x1F,0x00},

/*--  文字:  p  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0x80,0xFF,0x91,0x20,0x20,0x11,0x0E,0x00},

/*--  文字:  q  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x00,0x80,0x80,0x00,0x80,0x00,0x00,0x0E,0x11,0x20,0x20,0x91,0xFF,0x80},

/*--  文字:  r  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x80,0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x20,0x20,0x3F,0x21,0x20,0x00,0x01,0x00},

/*--  文字:  s  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x33,0x24,0x24,0x24,0x24,0x19,0x00},

/*--  文字:  t  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x80,0x80,0xE0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x1F,0x20,0x20,0x10,0x00},

/*--  文字:  u  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x80,0x80,0x00,0x00,0x00,0x80,0x80,0x00,0x00,0x1F,0x20,0x20,0x20,0x10,0x3F,0x20},

/*--  文字:  v  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x80,0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x00,0x03,0x0C,0x30,0x0C,0x03,0x00,0x00},

/*--  文字:  w  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x01,0x0E,0x30,0x0C,0x07,0x38,0x06,0x01},

/*--  文字:  x  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x80,0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x20,0x31,0x0E,0x2E,0x31,0x20,0x00},

/*--  文字:  y  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x80,0x80,0x80,0x00,0x00,0x80,0x80,0x80,0x00,0x81,0x86,0x78,0x18,0x06,0x01,0x00},

/*--  文字:  z  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x21,0x30,0x2C,0x22,0x21,0x30,0x00},

/*--  文字:  {  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x00,0x00,0x00,0xFC,0x02,0x02,0x00,0x00,0x00,0x00,0x01,0x3E,0x40,0x40},

/*--  文字:  |  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00},

/*--  文字:  }  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x02,0x02,0xFC,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x3E,0x01,0x00,0x00,0x00,0x00},

/*--  文字:  ~  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
{0x00,0x02,0x01,0x02,0x02,0x04,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
};


/* lcd gpio init */
void lcd_gpio_init(void)
{
	GPIO_InitTypeDef GPIO_Init_Inf;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE, ENABLE);
	
	GPIO_Init_Inf.GPIO_Pin = LCD_RS | LCD_RW | LCD_CS1 | LCD_CS2 | LCD_RST | LCD_BL;
	GPIO_Init_Inf.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init_Inf.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_Init_Inf);

	GPIO_Init_Inf.GPIO_Pin = LCD_E;
	GPIO_Init_Inf.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init_Inf.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_Init_Inf);
	
	GPIO_Init_Inf.GPIO_Pin = LCD_DATA0 | LCD_DATA1 | LCD_DATA2 | LCD_DATA3 | 
	LCD_DATA4 | LCD_DATA5 | LCD_DATA6 | LCD_DATA7;
	GPIO_Init_Inf.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init_Inf.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_Init_Inf);
}

void set_lcd_data_gpio_to_output(void)
{
	GPIO_InitTypeDef GPIO_Init_Inf;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE, ENABLE);

	GPIO_Init_Inf.GPIO_Pin = LCD_DATA0 | LCD_DATA1 | LCD_DATA2 | LCD_DATA3 | 
	LCD_DATA4 | LCD_DATA5 | LCD_DATA6 | LCD_DATA7;
	GPIO_Init_Inf.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init_Inf.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_Init_Inf);
}

void set_lcd_data_gpio_to_input(void)
{
	GPIO_InitTypeDef GPIO_Init_Inf;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE, ENABLE);

	GPIO_Init_Inf.GPIO_Pin = LCD_DATA0 | LCD_DATA1 | LCD_DATA2 | LCD_DATA3 | 
	LCD_DATA4 | LCD_DATA5 | LCD_DATA6 | LCD_DATA7;
	GPIO_Init_Inf.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init_Inf.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_Init_Inf);
}

unsigned char is_lcd_busy(unsigned char controller_cs)
{
	uint16_t status;

	if(controller_cs != CONCTROLLER_CS1 && controller_cs != CONCTROLLER_CS2) {
		printf("controller_cs(%d)error...\r\n", controller_cs);
		return 0xff;
	}
	
	GPIO_ResetBits(GPIOD, LCD_RW);
	set_lcd_data_gpio_to_input();
	
	GPIO_ResetBits(GPIOD, LCD_RS);
	if(controller_cs == CONCTROLLER_CS1)
		GPIO_SetBits(GPIOD, LCD_CS1);
	else
		GPIO_SetBits(GPIOD, LCD_CS2);

	GPIO_SetBits(GPIOD, LCD_RW);

	delay_us(1);
	
	GPIO_SetBits(GPIOE, LCD_E);

	delay_us(1);
   
	GPIO_ResetBits(GPIOE, LCD_E);
	status = GPIO_ReadInputData(GPIOE);

	delay_us(1);
	GPIO_ResetBits(GPIOD, LCD_RW);
	if(controller_cs == CONCTROLLER_CS1)
		GPIO_ResetBits(GPIOD, LCD_CS1);
	else
		GPIO_ResetBits(GPIOD, LCD_CS2);

	//printf("status:%x\r\n", status);
	if((status >> 8) & 0x80)
		return  1;
	else
		return 0;
}


/* send lcd cmd*/
void lcd_write_cmd(unsigned char cmd, unsigned char controller_cs)
{
	uint16_t data;

	if(controller_cs != CONCTROLLER_CS1 && controller_cs != CONCTROLLER_CS2) {
		printf("controller_cs(%d)error...\r\n", controller_cs);
		return;
	}

	//while(is_lcd_busy(controller_cs));
	
	GPIO_SetBits(GPIOD, LCD_RW);
	set_lcd_data_gpio_to_output();
	
    GPIO_ResetBits(GPIOD, LCD_RS);
	if(controller_cs == CONCTROLLER_CS1)
		GPIO_SetBits(GPIOD, LCD_CS1);
	else
		GPIO_SetBits(GPIOD, LCD_CS2);
	GPIO_ResetBits(GPIOD, LCD_RW);

	data = GPIO_ReadInputData(GPIOE);
	data &= 0x00ff;
	data |= (cmd << 8);
	GPIO_Write(GPIOE, data);
	
	GPIO_SetBits(GPIOE, LCD_E);

	delay_us(1);
   
	GPIO_ResetBits(GPIOE, LCD_E);

	delay_us(1);
	GPIO_SetBits(GPIOD, LCD_RW);
	if(controller_cs == CONCTROLLER_CS1)
		GPIO_ResetBits(GPIOD, LCD_CS1);
	else if(controller_cs == CONCTROLLER_CS2)
		GPIO_ResetBits(GPIOD, LCD_CS2);
}

/* send lcd data to show */
void lcd_write_data(unsigned char wdata, unsigned char controller_cs)
{
	uint16_t data;

	if(controller_cs != CONCTROLLER_CS1 && controller_cs != CONCTROLLER_CS2) {
		printf("controller_cs(%d)error...\r\n", controller_cs);
		return;
	}

	//while(is_lcd_busy(controller_cs));
	
	GPIO_SetBits(GPIOD, LCD_RW);
	set_lcd_data_gpio_to_output();
	
	GPIO_SetBits(GPIOD, LCD_RS);
	if(controller_cs == CONCTROLLER_CS1)
		GPIO_SetBits(GPIOD, LCD_CS1);
	else
		GPIO_SetBits(GPIOD, LCD_CS2);

	GPIO_ResetBits(GPIOD, LCD_RW);

	data = GPIO_ReadInputData(GPIOE);
	data &= 0x00ff;
	data |= (wdata << 8);
	GPIO_Write(GPIOE, data);
	
	GPIO_SetBits(GPIOE, LCD_E);

	delay_us(1);
   
	GPIO_ResetBits(GPIOE, LCD_E);

	delay_us(1);
	GPIO_SetBits(GPIOD, LCD_RW);
	if(controller_cs == CONCTROLLER_CS1)
		GPIO_ResetBits(GPIOD, LCD_CS1);
	else
		GPIO_ResetBits(GPIOD, LCD_CS2);
}


/* set display position
  page: page num(0~7), column:column pixel num(0~127)*/
void lcd_set_dsp_position(unsigned char page, unsigned char column)
{
	unsigned char controller_cs;
    if( column >= LCD_COLUMN_PIXEL_SUM/2 )
		controller_cs = CONCTROLLER_CS2;
    else
		controller_cs = CONCTROLLER_CS1;
    
    lcd_write_cmd(0xC0, controller_cs);
    lcd_write_cmd(0x40 + (column & 0x3F), controller_cs);                 //列地址
    lcd_write_cmd(0xB8 + (page & 0x07), controller_cs);                    //行
}

/* clean lcd */
void lcd_clr(void)
{
    unsigned char i, x=0;
    
    for(x=0; x<8; x++)
    {
        lcd_set_dsp_position(x, 0);                       //选中左屏
        for(i=0; i<64; i++)
        {
            lcd_write_data(0, CONCTROLLER_CS1);
        }
        
        lcd_set_dsp_position(x, 64);                      //选中右屏
        for(i=0; i<64; i++)
        {
            lcd_write_data(0, CONCTROLLER_CS2);
        }
    }
}

/*
row num(0~3)
*/
void lcd_clr_row(unsigned char row)
{
    unsigned char i;
    
    lcd_set_dsp_position(row*(CHAR_ROW_PIXEL/LCD_PAGE_ROW_NUM), 0);                       //选中左屏
    for(i = 0; i < LCD_COLUMN_PIXEL_SUM/2; i++){
        lcd_write_data(0, CONCTROLLER_CS1);
    }
	lcd_set_dsp_position(row*(CHAR_ROW_PIXEL/LCD_PAGE_ROW_NUM) + 1, 0);
	for(i = 0; i < LCD_COLUMN_PIXEL_SUM/2; i++){
        lcd_write_data(0, CONCTROLLER_CS1);
    }
    
    lcd_set_dsp_position(row*(CHAR_ROW_PIXEL/LCD_PAGE_ROW_NUM), 64);                      //选中右屏
    for(i = 0; i < LCD_COLUMN_PIXEL_SUM/2; i++){
         lcd_write_data(0, CONCTROLLER_CS2);
    }
	lcd_set_dsp_position(row*(CHAR_ROW_PIXEL/LCD_PAGE_ROW_NUM) + 1, 64);
	for(i = 0; i < LCD_COLUMN_PIXEL_SUM/2; i++){
         lcd_write_data(0, CONCTROLLER_CS2);
    }
}


void lcd_init (void)
{
	lcd_gpio_init();

    //打开背光
	GPIO_ResetBits(GPIOD, LCD_BL);

	//reset
	GPIO_ResetBits(GPIOD, LCD_RST);
  delay_ms(100);
  GPIO_SetBits(GPIOD, LCD_RST);
  delay_ms(100);
    
	GPIO_ResetBits(GPIOE, LCD_E);
	delay_us(1);
	
  lcd_write_cmd(0xC0, CONCTROLLER_CS1);                            //设置显示起始行
  lcd_write_cmd(0x3F, CONCTROLLER_CS1);                            //显示打开
	lcd_write_cmd(0xC0, CONCTROLLER_CS2);							 //设置显示起始行
	lcd_write_cmd(0x3F, CONCTROLLER_CS2);							 //显示打开

	lcd_clr();											 //清屏
}


/* display a image(128*64) */
void lcd_disp_full_img(const unsigned char *img)			   //显示图片
{
	unsigned char i=0,j=0;
	for(i=0;i<8;i++)
	{
		lcd_set_dsp_position(i, 0);													
		for(j=0;j<128;j++)
		{
			if( j == 64 )
			{
					lcd_set_dsp_position(i, j);                   //选中右屏
			}
			if(j < 64)
				lcd_write_data(*img, CONCTROLLER_CS1);
			else
				lcd_write_data(*img, CONCTROLLER_CS2);
			img++;
		}
	}
}


/*
  * @brief  show_logo()
  * @param  none
  * @note1  void show_logo(void)        
  * @Date:   2018.9.30
  * @updatge:2018.9.30
  * @author:zhao
  * @return:void
   * @note2   lcd拓展考题  显示 考生在此函数下实现显示附件 logo
                          
*/
void show_logo(void)
{
	

  lcd_disp_full_img(newLandEduLogo);
	delay_ms(1000);
 
}
/*
  * @brief  lcd_write
  * @param  1. row 显示行数  0~3
            2. column 显示列号 0~15
            3. data   需要显示的数据
            4. len    数据长度
                   
  * @Date:   2018.9.30
  * @updatge:2018.9.30
  * @author:zhao
  * @return:0   OK
            -1  error
*/
/*row num(0~3), column num(0~15), lcd can display 4*16 chars*/
int lcd_write(unsigned char row, unsigned char column, char* data, unsigned char len)
{
	unsigned char controller_cs;
	unsigned char page_addr_cmd;
	unsigned char column_addr_cmd;
	unsigned char i,j,page_index,column_index;
	unsigned char code_idx1,code_idx2;

	if((row > LCD_ROW_NUM -1 ) || (column > LCD_COLUMN_NUM - 1) || (data == NULL)){
		return -1;
	}

	if((len + column) > LCD_COLUMN_NUM){
		len = LCD_COLUMN_NUM - column;
	}

	for(page_index = 0; page_index < (CHAR_ROW_PIXEL/LCD_PAGE_ROW_NUM); page_index++){
		for(column_index = column, i = 0; column_index < (column + len); column_index++, i++){
			
			if(column_index >= (LCD_COLUMN_NUM / 2)){
				controller_cs = CONCTROLLER_CS2;
			}else{
				controller_cs = CONCTROLLER_CS1;
			}
			//printf("controller_cs:%d\r\n", controller_cs);
			
			//set row address to 0
		    lcd_write_cmd(0xC0, controller_cs);
			//set page address
			page_addr_cmd = 0xB8 | row*(CHAR_ROW_PIXEL/LCD_PAGE_ROW_NUM) + page_index;
		    lcd_write_cmd(page_addr_cmd, controller_cs);
			//set column address
			column_addr_cmd = 0x40 | ((column_index * CHAR_COLUMN_PIXEL) & 0x3f);
			lcd_write_cmd(column_addr_cmd, controller_cs);

			//send data to lcd
			if(data[i] & 0x80){
				//chinese
				printf("not support display chinese\r\n");
			}else{
				//ASCII
				//printf("row:%d, column:%d index:%d data:%c\r\n", row, column, data[i]-32, data[i]);
				for(j = 0; j < CHAR_COLUMN_PIXEL; j++){
					code_idx1 = data[i]-ASCILL_TO_CODE_INDEX;
					code_idx2 = j+LCD_PAGE_ROW_NUM*page_index;
					lcd_write_data(char_code_8x16[code_idx1][code_idx2], controller_cs);
				}
			}
		}
	}
	return 0;
}



/* 关闭背光 */
void lcd_close(void)
{
  GPIO_SetBits(GPIOD, LCD_BL);
  lcd_clr();
}

/* 打开背光 */
void lcd_open(void)
{
   GPIO_ResetBits(GPIOD, LCD_BL);
}

void lcd_people_num(char number)
{	
	char *p=&number;
	char num,tennum,hundrednum=0;
	//*p=*p+'0';
	lcd_write(0,0,"Number:",7);
	num=number/1%10;
	p=&num;
	*p=*p+'0';
	lcd_write(0,10,p,1);
	if(number>=10)
	{
		tennum=number/10%10;
		p=&tennum;
		*p=*p+'0';
		lcd_write(0,9,p,1);
	}
	
	if(number>=100)
	{
		hundrednum=number/100%10;
		p=&hundrednum;
		*p=*p+'0';
		lcd_write(0,8,p,1);
	}
   
}

/*
  * @brief  lcd_id
  * @param  none
  * @note1   void lcd_id(void)        
  * @Date:   2018.9.30
  * @updatge:2018.9.30
  * @author:zhao
  * @return:void
  * @note2   lcd显示考题  第一行显示  "ID card "
                        第二行显示“当前刷卡号” 对应 系统变量为 read_buff[8]    
                              lcd显示格式为英文字符串, 卡号需将 read_buff[8]经过格式转换在导入 。
                        
*/
void lcd_id(void)
{	
	
	/*以下部分又选手补充*/
    //Line2:  "ID card"          
	//Line3:  07A85026D6226885	低频卡刷卡成功ID卡号
	
	  
	//空白部分起始========>>
	

	
		//char num
	char mystr[16] = "";

 // char *p=mystr1;

	lcd_write(1,0,"ID_card:",7);
	
	ByteToHexStr(mystr,read_buff,8);

	lcd_write(2,0,mystr,16);
	
		
	//空白部分结束========<<


    
}



//	p_add=0,
//	p_delete=1,
//	p_hold=2,
extern p_state p_state1;
extern volatile char number_show;
void lcd_task(void)
{
	uint8_t state;

	state=p_state1;
	p_state1=p_hold;
	switch(state)
	{
		case p_add:lcd_clr();lcd_people_num(number_show);lcd_id();break;
		case p_delete:lcd_clr();lcd_people_num(number_show);break;
		default: break;	
	}
}



