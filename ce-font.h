#pragma once

#include <ce-base.h>

typedef struct
{
    ce_usize width;
    ce_usize height;
    ce_buf buf;
} ce_font;

extern ce_font CE_SOURCE_CODE_PRO;
extern ce_font CE_SOURCE_CODE_PRO_RETINA;

static inline ce_u8 ce_font_sample(ce_font font, char c, ce_usize x, ce_usize y)
{
    if (c < 32 || c > 126)
        return 0;
    c -= 32;
    ce_u8 const *pixels = font.buf.ptr;
    return pixels[(c * font.width * font.height) + (y * font.width + x)];
}
