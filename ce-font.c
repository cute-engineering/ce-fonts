#include "ce-font.h"

#include "_source_code_pro.inc"
#include "_source_code_pro_retina.inc"

ce_font CE_SOURCE_CODE_PRO = {
    .width = 8,
    .height = 16,
    .buf =
        {
            .len = ce_fonts_source_code_pro_len,
            .ptr = ce_fonts_source_code_pro_bin,
        },
};

ce_font CE_SOURCE_CODE_PRO_RETINA = {
    .width = 16,
    .height = 32,
    .buf =
        {
            .len = ce_fonts_source_code_pro_retina_len,
            .ptr = ce_fonts_source_code_pro_retina_bin,
        },
};
