/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License. */

#include "screen.h"

#include "ssd1306.h"

void screen_print(char* str, LINE_NUM line)
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(2, line);
    ssd1306_WriteString(str, Font_11x18, White);
    ssd1306_UpdateScreen();
    // ssd1306_DrawRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, SSD1306_COLOR color);
    ssd1306_DrawRectangle(1,1,10,10,White);
    ssd1306_UpdateScreen();

}

void screen_printn(const char* str, unsigned int str_length, LINE_NUM line)
{
    ssd1306_Fill(Black);
    ssd1306_SetCursor(2, line);

    for (unsigned int i = 0; i < str_length; ++i)
    {
        if (ssd1306_WriteChar(str[i], Font_11x18, White) != str[i])
        {
            return;
        }
    }

    ssd1306_UpdateScreen();
}